import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
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
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 28);
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
            FUpAndDownTheTree solver = new FUpAndDownTheTree();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FUpAndDownTheTree {
        int[][] dp;
        MultiWayIntegerStack edges;
        int[] depths;
        int[] nearestDepths;
        int[] degrees;
        boolean[] isLeaves;
        int k;
        int inf = (int) 1e8;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            k = in.readInt();
            dp = new int[2][n];
            edges = new MultiWayIntegerStack(n, 2 * n);
            depths = new int[n];
            nearestDepths = new int[n];
            degrees = new int[n];
            isLeaves = new boolean[n];

            for (int i = 1; i < n; i++) {
                int p = in.readInt() - 1;
                edges.addLast(i, p);
                edges.addLast(p, i);
                degrees[i]++;
                degrees[p]++;
            }
            for (int i = 1; i < n; i++) {
                if (degrees[i] == 1) {
                    isLeaves[i] = true;
                }
            }

            dfsForDepth(0, -1, 0);
            dfsForDp(0, -1);

            int ans = dp[0][0];
            out.println(ans);
        }

        public void dfsForDepth(int root, int p, int depth) {
            depths[root] = depth;
            nearestDepths[root] = inf;
            if (isLeaves[root]) {
                nearestDepths[root] = depth;
            }
            for (IntegerIterator iterator = edges.iterator(root); iterator.hasNext(); ) {
                int node = iterator.next();
                if (node == p) {
                    continue;
                }
                dfsForDepth(node, root, depth + 1);
                nearestDepths[root] = Math.min(nearestDepths[root], nearestDepths[node]);
            }
        }

        public void dfsForDp(int root, int p) {
            int maxDiff = 0;
            if (isLeaves[root]) {
                dp[1][root] = 1;
            }
            for (IntegerIterator iterator = edges.iterator(root); iterator.hasNext(); ) {
                int node = iterator.next();
                if (node == p) {
                    continue;
                }
                dfsForDp(node, root);
                maxDiff = Math.max(dp[0][node] - dp[1][node], maxDiff);
                dp[1][root] += dp[1][node];
            }
            dp[0][root] = dp[1][root] + maxDiff;
            if (nearestDepths[root] - (depths[root] - 1) > k) {
                dp[1][root] = 0;
            }
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

    static interface IntegerIterator {
        boolean hasNext();

        int next();

    }

    static class MultiWayIntegerStack {
        private int[] values;
        private int[] next;
        private int[] heads;
        private int alloc;
        private int stackNum;

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
            values = Arrays.copyOf(values, newSize);
        }

        public void alloc() {
            alloc++;
            if (alloc >= next.length) {
                doubleCapacity();
            }
            next[alloc] = 0;
        }

        public MultiWayIntegerStack(int qNum, int totalCapacity) {
            values = new int[totalCapacity + 1];
            next = new int[totalCapacity + 1];
            heads = new int[qNum];
            stackNum = qNum;
        }

        public void addLast(int qId, int x) {
            alloc();
            values[alloc] = x;
            next[alloc] = heads[qId];
            heads[qId] = alloc;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < stackNum; i++) {
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