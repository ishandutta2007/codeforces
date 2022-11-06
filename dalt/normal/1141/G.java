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
            TaskG solver = new TaskG();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskG {
        MultiWayStack<Edge> edges;
        int[] cnt;
        int[] size;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int k = in.readInt();
            edges = new MultiWayStack<>(n + 1, n * 2);
            Edge[] es = new Edge[n];
            cnt = new int[n + 1];
            size = new int[n + 1];
            for (int i = 1; i < n; i++) {
                Edge e = new Edge();
                es[i] = e;
                e.a = in.readInt();
                e.b = in.readInt();
                edges.addFirst(e.a, e);
                edges.addFirst(e.b, e);
                size[e.a]++;
                size[e.b]++;
            }
            IntBinarySearch bs = new IntBinarySearch() {

                public boolean check(int mid) {
                    dfs(1, null, mid);
                    return cnt[1] <= k;
                }
            };
            int ans = bs.binarySearch(1, n);
            bs.check(ans);
            out.println(ans);
            paint(1, null, ans);
            for (int i = 1; i < n; i++) {
                out.append(es[i].color + 1);
                out.append(' ');
            }
        }

        public void paint(int root, Edge p, int c) {
            int color = 0;
            if (p != null) {
                color = p.color + 1;
            }
            for (Edge e : edges.queue(root)) {
                if (e == p) {
                    continue;
                }
                int node = e.other(root);
                e.color = color % c;
                color++;
                paint(node, e, c);
            }
        }

        public void dfs(int root, Edge p, int c) {
            cnt[root] = 0;
            if (size[root] > c) {
                cnt[root]++;
            }
            for (Edge e : edges.queue(root)) {
                if (e == p) {
                    continue;
                }
                int node = e.other(root);
                dfs(node, e, c);
                cnt[root] += cnt[node];
            }
        }

    }

    static class MultiWayStack<T> {
        private Object[] values;
        private int[] next;
        private int[] heads;
        private int alloc;
        private int queueNum;

        public RevokeIterator iterator(final int queue) {
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

        public Iterable<T> queue(int qId) {
            return new Iterable<T>() {

                public Iterator<T> iterator() {
                    return MultiWayStack.this.iterator(qId);
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

        public MultiWayStack(int qNum, int totalCapacity) {
            values = (T[]) new Object[totalCapacity + 1];
            next = new int[totalCapacity + 1];
            heads = new int[qNum];
            queueNum = qNum;
        }

        public void addFirst(int qId, T x) {
            alloc();
            values[alloc] = x;
            next[alloc] = heads[qId];
            heads[qId] = alloc;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < queueNum; i++) {
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

    static abstract class IntBinarySearch {
        public abstract boolean check(int mid);

        public int binarySearch(int l, int r) {
            if (l > r) {
                throw new IllegalArgumentException();
            }
            while (l < r) {
                int mid = (l + r) >>> 1;
                if (check(mid)) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return l;
        }

    }

    static interface RevokeIterator<E> extends Iterator<E> {
    }

    static class Edge {
        int a;
        int b;
        int color;

        int other(int x) {
            return a ^ b ^ x;
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

        public FastOutput println(int c) {
            cache.append(c).append('\n');
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
}