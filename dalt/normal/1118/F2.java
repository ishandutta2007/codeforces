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
            TaskF2 solver = new TaskF2();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskF2 {
        MultiWayIntStack edges;
        int[][] dp;
        int[] color;
        int[] parent;
        boolean[] visited;
        Modular mod = new Modular(998244353);
        boolean valid = true;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int k = in.readInt();
            edges = new MultiWayIntStack(n + 1, n * 2);
            dp = new int[n + 1][2];
            color = new int[n + 1];
            visited = new boolean[n + 1];
            parent = new int[n + 1];

            for (int i = 1; i <= n; i++) {
                color[i] = in.readInt();
            }

            for (int i = 1; i <= n; i++) {
                int a = in.readInt();
                int b = in.readInt();
                edges.addLast(a, b);
                edges.addLast(b, a);
            }
            LcaOnTree lcaOnTree = new LcaOnTree(edges, 1);
            int[] lca = new int[k + 1];
            dfsForParent(1, 0);
            for (int i = 1; i <= n; i++) {
                if (color[i] == 0) {
                    continue;
                }
                if (lca[color[i]] == 0) {
                    lca[color[i]] = i;
                } else {
                    lca[color[i]] = lcaOnTree.lca(lca[color[i]], i);
                }
            }
            for (int i = 1; i <= n; i++) {
                if (color[i] == 0) {
                    continue;
                }
                if (i != lca[color[i]]) {
                    paint(parent[i], lca[color[i]], color[i]);
                }
            }


            if (!valid) {
                out.println(0);
                return;
            }

            int ans = 1;
            for (int i = 1; i <= n; i++) {
                if (visited[i] || color[i] != 0) {
                    continue;
                }
                dfs(i, 0);
                ans = mod.mul(ans, dp[i][1]);
            }

            out.println(ans);
        }

        public void dfsForParent(int root, int p) {
            parent[root] = p;
            for (IntIterator iterator = edges.iterator(root); iterator.hasNext(); ) {
                int node = iterator.next();
                if (node == p) {
                    continue;
                }
                dfsForParent(node, root);
            }
        }

        public void paint(int root, int ancestor, int c) {
            if (color[root] != 0) {
                if (color[root] == c) {
                    return;
                }
                valid = false;
                return;
            }
            color[root] = c;
            if (root != ancestor) {
                paint(parent[root], ancestor, c);
            }
        }

        public void dfs(int root, int p) {
            if (visited[root]) {
                return;
            }
            visited[root] = true;
            if (color[root] != 0) {
                dp[root][0] = 0;
                dp[root][1] = 1;
                return;
            }
            dp[root][0] = 1;
            dp[root][1] = 0;
            for (IntIterator iterator = edges.iterator(root); iterator.hasNext(); ) {
                int node = iterator.next();
                if (node == p) {
                    continue;
                }
                dfs(node, root);
                int total = mod.plus(dp[node][0], dp[node][1]);
                dp[root][1] = mod.plus(mod.mul(dp[root][1], total), mod.mul(dp[root][0], dp[node][1]));
                dp[root][0] = mod.mul(dp[root][0], total);
            }
        }

    }

    static class MultiWayIntStack {
        private int[] values;
        private int[] next;
        private int[] heads;
        private int alloc;
        private int stackNum;

        public IntIterator iterator(final int queue) {
            return new IntIterator() {
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

        public int stackNumber() {
            return stackNum;
        }

        public MultiWayIntStack(int qNum, int totalCapacity) {
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
                for (IntIterator iterator = iterator(i); iterator.hasNext(); ) {
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

    static class Modular {
        int m;

        public Modular(int m) {
            this.m = m;
        }

        public Modular(long m) {
            this.m = (int) m;
            if (this.m != m) {
                throw new IllegalArgumentException();
            }
        }

        public Modular(double m) {
            this.m = (int) m;
            if (this.m != m) {
                throw new IllegalArgumentException();
            }
        }

        public int valueOf(int x) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            return x;
        }

        public int valueOf(long x) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            return (int) x;
        }

        public int mul(int x, int y) {
            return valueOf((long) x * y);
        }

        public int plus(int x, int y) {
            return valueOf(x + y);
        }

        public String toString() {
            return "mod " + m;
        }

    }

    static class LcaOnTree {
        int[] parent;
        int[] preOrder;
        int[] I;
        int[] head;
        int[] A;
        int time;

        void dfs1(MultiWayIntStack tree, int u, int p) {
            parent[u] = p;
            I[u] = preOrder[u] = time++;
            for (IntIterator iterator = tree.iterator(u); iterator.hasNext(); ) {
                int v = iterator.next();
                if (v == p) continue;
                dfs1(tree, v, u);
                if (Integer.lowestOneBit(I[u]) < Integer.lowestOneBit(I[v])) {
                    I[u] = I[v];
                }
            }
            head[I[u]] = u;
        }

        void dfs2(MultiWayIntStack tree, int u, int p, int up) {
            A[u] = up | Integer.lowestOneBit(I[u]);
            for (IntIterator iterator = tree.iterator(u); iterator.hasNext(); ) {
                int v = iterator.next();
                if (v == p) continue;
                dfs2(tree, v, u, A[u]);
            }
        }

        public LcaOnTree(MultiWayIntStack tree, int root) {
            int n = tree.stackNumber();
            preOrder = new int[n];
            I = new int[n];
            head = new int[n];
            A = new int[n];
            parent = new int[n];

            dfs1(tree, root, -1);
            dfs2(tree, root, -1, 0);
        }

        private int enterIntoStrip(int x, int hz) {
            if (Integer.lowestOneBit(I[x]) == hz)
                return x;
            int hw = Integer.highestOneBit(A[x] & (hz - 1));
            return parent[head[I[x] & -hw | hw]];
        }

        public int lca(int x, int y) {
            int hb = I[x] == I[y] ? Integer.lowestOneBit(I[x]) : Integer.highestOneBit(I[x] ^ I[y]);
            int hz = Integer.lowestOneBit(A[x] & A[y] & -hb);
            int ex = enterIntoStrip(x, hz);
            int ey = enterIntoStrip(y, hz);
            return preOrder[ex] < preOrder[ey] ? ex : ey;
        }

    }

    static interface IntIterator {
        boolean hasNext();

        int next();

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