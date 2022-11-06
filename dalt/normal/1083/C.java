import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.function.IntBinaryOperator;
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
            CMaxMex solver = new CMaxMex();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class CMaxMex {
        int[] depth;
        MultiWayIntegerStack edges;

        public void dfsForDepth(int root, int p, int d) {
            depth[root] = d;
            for (IntegerIterator iterator = edges.iterator(root); iterator.hasNext(); ) {
                int node = iterator.next();
                if (node == p) {
                    continue;
                }
                dfsForDepth(node, root, d + 1);
            }
        }

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int[] nodeToPerm = new int[n];
            int[] permToNode = new int[n];
            for (int i = 0; i < n; i++) {
                nodeToPerm[i] = in.readInt();
                permToNode[nodeToPerm[i]] = i;
            }

            edges = new MultiWayIntegerStack(n, n + n);
            depth = new int[n];
            for (int i = 1; i < n; i++) {
                int p = in.readInt() - 1;
                edges.addLast(i, p);
                edges.addLast(p, i);
            }
            LcaOnTree lca = new LcaOnTree(edges, 0);
            dfsForDepth(0, -1, 0);
            Segment.lca = lca;
            Segment.distFunc = (a, b) -> depth[a] + depth[b] - depth[lca.lca(a, b)] * 2;

            int l = 0;
            int r = n - 1;
            Segment seg = new Segment(l, r, permToNode);

            int q = in.readInt();
            for (int i = 0; i < q; i++) {
                if (in.readInt() == 1) {
                    int a = in.readInt() - 1;
                    int b = in.readInt() - 1;
                    SequenceUtils.swap(nodeToPerm, a, b);
                    permToNode[nodeToPerm[a]] = a;
                    permToNode[nodeToPerm[b]] = b;
                    seg.update(nodeToPerm[a], nodeToPerm[a], l, r, a);
                    seg.update(nodeToPerm[b], nodeToPerm[b], l, r, b);
                } else {
                    out.println(seg.query(l, r));
                }
            }
        }

    }

    static class SequenceUtils {
        public static void swap(int[] data, int i, int j) {
            int tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

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

        public int stackNumber() {
            return stackNum;
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

    static class LcaOnTree {
        int[] parent;
        int[] preOrder;
        int[] i;
        int[] head;
        int[] a;
        int time;

        void dfs1(MultiWayIntegerStack tree, int u, int p) {
            parent[u] = p;
            i[u] = preOrder[u] = time++;
            for (IntegerIterator iterator = tree.iterator(u); iterator.hasNext(); ) {
                int v = iterator.next();
                if (v == p) continue;
                dfs1(tree, v, u);
                if (Integer.lowestOneBit(i[u]) < Integer.lowestOneBit(i[v])) {
                    i[u] = i[v];
                }
            }
            head[i[u]] = u;
        }

        void dfs2(MultiWayIntegerStack tree, int u, int p, int up) {
            a[u] = up | Integer.lowestOneBit(i[u]);
            for (IntegerIterator iterator = tree.iterator(u); iterator.hasNext(); ) {
                int v = iterator.next();
                if (v == p) continue;
                dfs2(tree, v, u, a[u]);
            }
        }

        public LcaOnTree(MultiWayIntegerStack tree, int root) {
            int n = tree.stackNumber();
            preOrder = new int[n];
            i = new int[n];
            head = new int[n];
            a = new int[n];
            parent = new int[n];

            dfs1(tree, root, -1);
            dfs2(tree, root, -1, 0);
        }

        private int enterIntoStrip(int x, int hz) {
            if (Integer.lowestOneBit(i[x]) == hz)
                return x;
            int hw = 1 << CachedLog2.floorLog(a[x] & (hz - 1));
            return parent[head[i[x] & -hw | hw]];
        }

        public int lca(int x, int y) {
            int hb = i[x] == i[y] ? Integer.lowestOneBit(i[x]) : (1 << CachedLog2.floorLog(i[x] ^ i[y]));
            int hz = Integer.lowestOneBit(a[x] & a[y] & -hb);
            int ex = enterIntoStrip(x, hz);
            int ey = enterIntoStrip(y, hz);
            return preOrder[ex] < preOrder[ey] ? ex : ey;
        }

    }

    static class Segment implements Cloneable {
        private Segment left;
        private Segment right;
        static LcaOnTree lca;
        static IntBinaryOperator distFunc;
        TreePath path = new TreePath();
        boolean isPath;

        public void pushUp() {
            path.mergeAsLongestPath(left.path, right.path, distFunc);
            if (!left.isPath || !right.isPath) {
                isPath = false;
            } else {
                isPath = path.include(left.path.getA(), lca) &&
                        path.include(left.path.getB(), lca) &&
                        path.include(right.path.getA(), lca) &&
                        path.include(right.path.getB(), lca);
            }
        }

        public void pushDown() {
        }

        public Segment(int l, int r, int[] nodes) {
            if (l < r) {
                int m = (l + r) >> 1;
                left = new Segment(l, m, nodes);
                right = new Segment(m + 1, r, nodes);
                pushUp();
            } else {
                path.initAsSingleVertex(nodes[l]);
                isPath = true;
            }
        }

        private boolean covered(int ll, int rr, int l, int r) {
            return ll <= l && rr >= r;
        }

        private boolean noIntersection(int ll, int rr, int l, int r) {
            return ll > r || rr < l;
        }

        public void update(int ll, int rr, int l, int r, int node) {
            if (noIntersection(ll, rr, l, r)) {
                return;
            }
            if (covered(ll, rr, l, r)) {
                path.initAsSingleVertex(node);
                return;
            }
            pushDown();
            int m = (l + r) >> 1;
            left.update(ll, rr, l, m, node);
            right.update(ll, rr, m + 1, r, node);
            pushUp();
        }

        public int query(int l, int r) {
            TreePath pair = null;
            TreePath tmp = new TreePath();

            Segment trace = this;
            while (l < r) {
                int m = (l + r) >>> 1;
                trace.pushDown();
                if (trace.left.isPath) {
                    if (pair == null) {
                        pair = new TreePath();
                        pair.copyOf(trace.left.path);
                        l = m + 1;
                        trace = trace.right;
                        continue;
                    }
                    tmp.mergeAsLongestPath(pair, trace.left.path, distFunc);
                    if (tmp.include(pair.getA(), lca) && tmp.include(pair.getB(), lca) &&
                            tmp.include(trace.left.path.getA(), lca) && tmp.include(trace.left.path.getB(), lca)) {
                        l = m + 1;
                        trace = trace.right;
                        pair.copyOf(tmp);
                        continue;
                    }
                }
                trace = trace.left;
                r = m;
            }

            if (trace.isPath) {
                if (pair == null) {
                    return l + 1;
                }
                tmp.mergeAsLongestPath(pair, trace.path, distFunc);
                if (tmp.include(pair.getA(), lca) && tmp.include(pair.getB(), lca) &&
                        tmp.include(trace.path.getA(), lca) && tmp.include(trace.path.getB(), lca)) {
                    return l + 1;
                }
            }

            return l;
        }

    }

    static class CachedLog2 {
        private static final int BITS = 16;
        private static final int LIMIT = 1 << BITS;
        private static final byte[] CACHE = new byte[LIMIT];

        static {
            int b = 0;
            for (int i = 0; i < LIMIT; i++) {
                while ((1 << (b + 1)) <= i) {
                    b++;
                }
                CACHE[i] = (byte) b;
            }
        }

        public static int floorLog(int x) {
            return x < LIMIT ? CACHE[x] : (BITS + CACHE[x >>> BITS]);
        }

    }

    static class TreePath {
        private int[] vertex = new int[2];
        private int dist;

        public int getA() {
            return vertex[0];
        }

        public int getB() {
            return vertex[1];
        }

        public void initAsSingleVertex(int x) {
            vertex[0] = vertex[1] = x;
            dist = 0;
        }

        public void copyOf(TreePath x) {
            vertex[0] = x.vertex[0];
            vertex[1] = x.vertex[1];
            dist = x.dist;
        }

        public boolean include(int v, LcaOnTree lca) {
            int lca1 = lca.lca(vertex[0], vertex[1]);
            int lca2 = lca.lca(vertex[0], v);
            int lca3 = lca.lca(vertex[1], v);
            return lca1 == v || ((lca2 == v) != (lca3 == v));
        }

        public void mergeAsLongestPath(TreePath a, TreePath b, IntBinaryOperator distFunc) {
            copyOf(a);
            mergeAsLongestPath(b, distFunc);
        }

        public void mergeAsLongestPath(TreePath x, IntBinaryOperator distFunc) {
            int a = vertex[0];
            int b = vertex[1];
            int dist = this.dist;

            if (x.dist > dist) {
                a = x.vertex[0];
                b = x.vertex[1];
                dist = x.dist;
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    int d = distFunc.applyAsInt(vertex[i], x.vertex[j]);
                    if (d > dist) {
                        a = vertex[i];
                        b = x.vertex[j];
                        dist = d;
                    }
                }
            }

            this.vertex[0] = a;
            this.vertex[1] = b;
            this.dist = dist;
        }

        public String toString() {
            return String.format("%d...%d(%d)", vertex[0], vertex[1], dist);
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
}