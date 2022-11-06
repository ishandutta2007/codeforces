import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Iterator;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 29);
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
            ETwoEditorials solver = new ETwoEditorials();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class ETwoEditorials {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int m = in.ri();
            int k = in.ri();
            Interval[] intervals = new Interval[m];
            for (int i = 0; i < m; i++) {
                intervals[i] = new Interval();
                intervals[i].l = in.ri() - 1;
                intervals[i].r = in.ri() - 1;
            }

            FastPQ[] pq = new FastPQ[4];
            for (int i = 0; i < 4; i++) {
                pq[i] = new FastPQ();
            }
            long ans = 0;
            for (int a = k - 1; a < n; a++) {
                for (int i = 0; i < 4; i++) {
                    pq[i].clear();
                }
                long maintain = 0;
                for (Interval x : intervals) {
                    x.next = x.l - 1;
                    pq[3].add(x);
                    maintain += x.cover = cover(a - k + 1, a, x.l, x.r);
                }
                optimize(pq, k, a);
                ans = Math.max(ans, maintain);
                for (int b = a + 1; b < n; b++) {
                    maintain += pq[0].size() - pq[2].size();
                    ans = Math.max(ans, maintain);
                    optimize(pq, k, b);
                }
            }

            out.println(ans);
        }

        public void optimize(FastPQ[] pq, int k, int i) {
            while (!pq[3].isEmpty(i) && pq[3].peek(i).next <= i) {
                Interval head = pq[3].remove(i);
                head.next = Math.min(head.r, head.l + k - 1);
                pq[0].add(head);
            }
            //0
            while (!pq[0].isEmpty(i) && pq[0].peek(i).next <= i) {
                Interval head = pq[0].remove(i);
                head.next = Math.max(head.r, head.l + k - 1);
                pq[1].add(head);
            }
            //1
            while (!pq[1].isEmpty(i) && pq[1].peek(i).next <= i) {
                Interval head = pq[1].remove(i);
                head.next = cover(head.l, head.r, i - k + 1, i) - head.cover + i;
                pq[2].add(head);
            }
            while (!pq[2].isEmpty(i) && pq[2].peek(i).next <= i) {
                Interval head = pq[2].remove(i);
            }
        }

        public int cover(int ll, int rr, int l, int r) {
            return Math.max(0, Math.min(rr, r) - Math.max(ll, l) + 1);
        }

    }

    static class FastPQ {
        static int max = 2010;
        MultiWayStack<Interval> stack = new MultiWayStack<>(max, max);
        int cur = 0;
        int size = 0;

        public void clear() {
            stack.clear();
            cur = 0;
            size = 0;
        }

        public void add(Interval interval) {
            int q = interval.next;
            q = Math.max(q, cur);
            q = Math.min(q, max - 1);
            stack.addLast(q, interval);
            size++;
        }

        public int size() {
            return size;
        }

        public boolean isEmpty(int i) {
            return !reindex(i);
        }

        private boolean reindex(int i) {
            while (stack.isEmpty(cur) && cur + 1 <= i) {
                cur++;
            }
            return !stack.isEmpty(cur);
        }

        public Interval peek(int i) {
            assert size > 0;
            reindex(i);
            return stack.peekLast(cur);
        }

        public Interval remove(int i) {
            assert size > 0;
            size--;
            reindex(i);
            return stack.removeLast(cur);
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private static final int THRESHOLD = 1 << 13;
        private final Writer os;
        private StringBuilder cache = new StringBuilder(THRESHOLD * 2);

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

        private void afterWrite() {
            if (cache.length() < THRESHOLD) {
                return;
            }
            flush();
        }

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput append(char c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(long c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(String c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(long c) {
            return append(c).println();
        }

        public FastOutput println() {
            return append(System.lineSeparator());
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

        public int ri() {
            return readInt();
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

    static class MultiWayStack<T> {
        private Object[] values;
        private int[] next;
        private int[] heads;
        private int alloc;
        private int stackNum;

        public RevokeIterator<T> iterator(final int queue) {
            return new RevokeIterator<T>() {
                int ele = heads[queue];
                int pre = 0;


                public boolean hasNext() {
                    return ele != 0;
                }


                public T next() {
                    T ans = (T) values[ele];
                    pre = ele;
                    ele = next[ele];
                    return ans;
                }


                public void revoke() {
                    ele = pre;
                    pre = 0;
                }
            };
        }

        private void doubleCapacity() {
            int newSize = Math.max(next.length + 10, next.length * 2);
            next = Arrays.copyOf(next, newSize);
            values = Arrays.copyOf(values, newSize);
        }

        public void alloc() {
            alloc++;
            if (alloc >= next.length) {
                doubleCapacity();
            }
            next[alloc] = 0;
        }

        public void clear() {
            alloc = 0;
            Arrays.fill(heads, 0, stackNum, 0);
        }

        public boolean isEmpty(int qId) {
            return heads[qId] == 0;
        }

        public MultiWayStack(int qNum, int totalCapacity) {
            values = new Object[totalCapacity + 1];
            next = new int[totalCapacity + 1];
            heads = new int[qNum];
            stackNum = qNum;
        }

        public void addLast(int qId, T x) {
            alloc();
            values[alloc] = x;
            next[alloc] = heads[qId];
            heads[qId] = alloc;
        }

        public T peekLast(int qId) {
            return (T) values[heads[qId]];
        }

        public T removeLast(int qId) {
            T ans = (T) values[heads[qId]];
            heads[qId] = next[heads[qId]];
            return ans;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < stackNum; i++) {
                builder.append(i).append(": ");
                for (Iterator iterator = iterator(i); iterator.hasNext(); ) {
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

    static interface RevokeIterator<E> extends Iterator<E> {
    }

    static class Interval {
        int l;
        int r;
        int next;
        int cover;

    }
}