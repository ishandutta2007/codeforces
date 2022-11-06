import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Collection;
import java.io.IOException;
import java.util.Deque;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 27);
        thread.start();
        thread.join();
    }

    static class TaskAdapter implements Runnable {
        @Override
        public void run() {
            InputStream inputStream = System.in;
            OutputStream outputStream = System.out;
            FastInput in = new FastInput(inputStream);
            FastOutput out = new FastOutput(outputStream);
            EMessengerSimulator solver = new EMessengerSimulator();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class EMessengerSimulator {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            int[] a = new int[m];
            for (int i = 0; i < m; i++) {
                a[i] = in.readInt() - 1;
            }

            MultiWayIntegerDeque deque = new MultiWayIntegerDeque(n, m);
            for (int i = 0; i < m; i++) {
                deque.addLast(a[i], i);
            }

            List<Query> queries = new ArrayList<>();
            int[] first = new int[n];
            int[] last = new int[n];

            for (int i = 0; i < n; i++) {
                if (deque.isEmpty(i)) {
                    first[i] = i;
                } else {
                    first[i] = 0;
                    IntegerIterator iterator = deque.iterator(i);
                    int pre = iterator.next();
                    while (iterator.hasNext()) {
                        int next = iterator.next();
                        queries.add(new Query(pre + 1, next - 1, i));
                        pre = next;
                    }
                    if (pre + 1 <= m - 1) {
                        queries.add(new Query(pre + 1, m - 1, i));
                    }
                }
            }

            IntegerBIT appearBIT = new IntegerBIT(n);
            boolean[] visited = new boolean[n];
            for (int i = 0; i < m; i++) {
                if (visited[a[i]]) {
                    continue;
                }
                visited[a[i]] = true;
                appearBIT.update(a[i] + 1, 1);
                last[a[i]] = Math.max(last[a[i]], a[i] + appearBIT.query(n) - appearBIT.query(a[i] + 1));
            }

            for (int i = 0; i < n; i++) {
                if (visited[i]) {
                    continue;
                }
                visited[i] = true;
                last[i] = Math.max(last[i], i + appearBIT.query(n) - appearBIT.query(i + 1));
            }

            int[] registries = new int[n];
            Arrays.fill(registries, -1);
            IntegerBIT countBit = new IntegerBIT(m);
            queries.sort((x, y) -> x.r - y.r);
            Deque<Query> queue = new ArrayDeque<>(queries);

            for (int i = 0; i < m; i++) {
                if (registries[a[i]] != -1) {
                    countBit.update(1 + registries[a[i]], -1);
                }
                registries[a[i]] = i;
                countBit.update(1 + registries[a[i]], 1);
                while (!queue.isEmpty() && queue.peekFirst().r == i) {
                    Query q = queue.removeFirst();
                    int ans = countBit.query(q.r + 1) - countBit.query(q.l);
                    last[q.person] = Math.max(last[q.person], ans);
                }
            }

            for (int i = 0; i < n; i++) {
                out.append(first[i] + 1).append(' ').append(last[i] + 1).println();
            }
        }

    }

    static class FastInput {
        private final InputStream is;
        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;

        public FastInput(InputStream is) {
            this.is = is;
        }

        private int read() {
            while (bufLen == bufOffset) {
                bufOffset = 0;
                try {
                    bufLen = is.read(buf);
                } catch (IOException e) {
                    bufLen = -1;
                }
                if (bufLen == -1) {
                    return -1;
                }
            }
            return buf[bufOffset++];
        }

        public void skipBlank() {
            while (next >= 0 && next <= 32) {
                next = read();
            }
        }

        public int readInt() {
            int sign = 1;

            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+' ? 1 : -1;
                next = read();
            }

            int val = 0;
            if (sign == 1) {
                while (next >= '0' && next <= '9') {
                    val = val * 10 + next - '0';
                    next = read();
                }
            } else {
                while (next >= '0' && next <= '9') {
                    val = val * 10 - next + '0';
                    next = read();
                }
            }

            return val;
        }

    }

    static class FastOutput implements AutoCloseable, Closeable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }

        public FastOutput append(int c) {
            cache.append(c);
            return this;
        }

        public FastOutput println() {
            cache.append('\n');
            return this;
        }

        public FastOutput flush() {
            try {
                os.append(cache);
                os.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
            return this;
        }

        public void close() {
            flush();
            try {
                os.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

        public String toString() {
            return cache.toString();
        }

    }

    static class IntegerBIT {
        private int[] data;
        private int n;

        public IntegerBIT(int n) {
            this.n = n;
            data = new int[n + 1];
        }

        public int query(int i) {
            int sum = 0;
            for (; i > 0; i -= i & -i) {
                sum += data[i];
            }
            return sum;
        }

        public void update(int i, int mod) {
            if (i <= 0) {
                return;
            }
            for (; i <= n; i += i & -i) {
                data[i] += mod;
            }
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 1; i <= n; i++) {
                builder.append(query(i) - query(i - 1)).append(' ');
            }
            return builder.toString();
        }

    }

    static interface IntegerIterator {
        boolean hasNext();

        int next();

    }

    static class Query {
        int l;
        int r;
        int person;

        public Query(int l, int r, int person) {
            this.l = l;
            this.r = r;
            this.person = person;
        }

    }

    static class MultiWayIntegerDeque {
        private int[] values;
        private int[] next;
        private int[] prev;
        private int[] heads;
        private int[] tails;
        private int alloc;
        private int queueNum;

        public IntegerIterator iterator(final int queue) {
            return new IntegerIterator() {
                int ele = heads[queue];


                public boolean hasNext() {
                    return ele != 0;
                }


                public int next() {
                    int ans = values[ele];
                    ele = next[ele];
                    return ans;
                }
            };
        }

        private void doubleCapacity() {
            int newSize = Math.max(next.length + 10, next.length * 2);
            next = Arrays.copyOf(next, newSize);
            prev = Arrays.copyOf(prev, newSize);
            values = Arrays.copyOf(values, newSize);
        }

        public void alloc() {
            alloc++;
            if (alloc >= next.length) {
                doubleCapacity();
            }
            next[alloc] = 0;
        }

        public boolean isEmpty(int qId) {
            return heads[qId] == 0;
        }

        public MultiWayIntegerDeque(int qNum, int totalCapacity) {
            values = new int[totalCapacity + 1];
            next = new int[totalCapacity + 1];
            prev = new int[totalCapacity + 1];
            heads = new int[qNum];
            tails = new int[qNum];
            queueNum = qNum;
        }

        public void addLast(int qId, int x) {
            alloc();
            values[alloc] = x;

            if (heads[qId] == 0) {
                heads[qId] = tails[qId] = alloc;
                return;
            }
            next[tails[qId]] = alloc;
            prev[alloc] = tails[qId];
            tails[qId] = alloc;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < queueNum; i++) {
                builder.append(i).append(": ");
                for (IntegerIterator iterator = iterator(i); iterator.hasNext(); ) {
                    builder.append(iterator.next()).append(",");
                }
                if (builder.charAt(builder.length() - 1) == ',') {
                    builder.setLength(builder.length() - 1);
                }
                builder.append('\n');
            }
            return builder.toString();
        }

    }
}