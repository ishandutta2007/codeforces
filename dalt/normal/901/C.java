import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.OutputStreamWriter;
import java.util.function.IntFunction;
import java.io.OutputStream;
import java.util.Iterator;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
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
            CBipartiteSegments solver = new CBipartiteSegments();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class CBipartiteSegments {
        int[] parents;
        List<UndirectedEdge>[] g;
        int color;
        int[] colors;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();

            parents = new int[n];
            colors = new int[n];
            Arrays.fill(colors, -1);
            g = Graph.createUndirectedGraph(n);
            Edge[] edges = new Edge[m];
            DSU dsu = new DSU(n);
            for (int i = 0; i < m; i++) {
                edges[i] = new Edge();
                edges[i].a = in.readInt() - 1;
                edges[i].b = in.readInt() - 1;
                if (dsu.find(edges[i].a) != dsu.find(edges[i].b)) {
                    edges[i].tree = true;
                    dsu.merge(edges[i].a, edges[i].b);
                    Graph.addUndirectedEdge(g, edges[i].a, edges[i].b);
                }
            }
            for (int i = 1; i < n; i++) {
                if (dsu.find(i) != dsu.find(i - 1)) {
                    dsu.merge(i, i - 1);
                    Graph.addUndirectedEdge(g, i, i - 1);
                }
            }

            dfs(0, -1);
            LcaOnTree lca = new LcaOnTree(g, 0);
            for (Edge e : edges) {
                if (e.tree) {
                    continue;
                }
                int a = e.a;
                int b = e.b;
                int c = lca.lca(a, b);
                paint(a, c, color);
                paint(b, c, color);
                color++;
            }

            int[] right = new int[n];
            int[] limit = new int[color];
            for (int c : colors) {
                if (c == -1) {
                    continue;
                }
                limit[c]++;
            }
            Machine machine = new Machine(color, limit);
            for (int i = 0, r = -1, l = 0; i < n; i++) {
                while (l < i) {
                    machine.remove(colors[l]);
                    l++;
                }
                while (r + 1 < n && machine.total == 0) {
                    machine.add(colors[r + 1]);
                    r++;
                }
                if (machine.total == 0) {
                    right[i] = r;
                } else {
                    right[i] = r - 1;
                }
            }

            //System.err.println(Arrays.toString(right));

            int q = in.readInt();
            Query[] queries = new Query[q];
            for (int i = 0; i < q; i++) {
                queries[i] = new Query();
                queries[i].l = in.readInt() - 1;
                queries[i].r = in.readInt() - 1;
            }

            Query[] sorted = queries.clone();
            Arrays.sort(sorted, (a, b) -> -Integer.compare(a.l, b.l));
            Segment seg = new Segment(0, n);
            SimplifiedDeque<Query> dq = new Range2DequeAdapter<>(i -> sorted[i], 0, sorted.length - 1);
            for (int i = n - 1; i >= 0; i--) {
                seg.update(i, right[i], 0, n, 1);
                while (!dq.isEmpty() && dq.peekFirst().l == i) {
                    Query head = dq.removeFirst();
                    head.ans = seg.query(head.l, head.r, 0, n);
                }
            }

            for (Query query : queries) {
                out.println(query.ans);
            }
        }

        public void paint(int root, int end, int c) {
            colors[root] = c;
            if (root == end) {
                return;
            }
            paint(parents[root], end, c);
        }

        public void dfs(int root, int p) {
            parents[root] = p;
            for (UndirectedEdge e : g[root]) {
                if (e.to == p) {
                    continue;
                }
                dfs(e.to, root);
            }
        }

    }

    static class Edge {
        int a;
        int b;
        boolean tree;

    }

    static interface SimplifiedDeque<T> extends SimplifiedStack<T> {
        T peekFirst();

        T removeFirst();

    }

    static class DirectedEdge {
        public int to;

        public DirectedEdge(int to) {
            this.to = to;
        }

        public String toString() {
            return "->" + to;
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

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

        public FastOutput println(long c) {
            cache.append(c);
            println();
            return this;
        }

        public FastOutput println() {
            cache.append(System.lineSeparator());
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

    static class Graph {
        public static void addUndirectedEdge(List<UndirectedEdge>[] g, int s, int t) {
            UndirectedEdge toT = new UndirectedEdge(t);
            UndirectedEdge toS = new UndirectedEdge(s);
            toT.rev = toS;
            toS.rev = toT;
            g[s].add(toT);
            g[t].add(toS);
        }

        public static List<UndirectedEdge>[] createUndirectedGraph(int n) {
            List<UndirectedEdge>[] ans = new List[n];
            for (int i = 0; i < n; i++) {
                ans[i] = new ArrayList<>();
            }
            return ans;
        }

    }

    static class Machine {
        int total;
        int[] cnts;
        int[] limit;

        public Machine(int m, int[] limit) {
            cnts = new int[m];
            this.limit = limit;
        }

        public void add(int x) {
            if (x < 0) {
                return;
            }
            cnts[x]++;
            if (cnts[x] == limit[x]) {
                total++;
            }
        }

        public void remove(int x) {
            if (x < 0) {
                return;
            }
            cnts[x]--;
            if (cnts[x] + 1 == limit[x]) {
                total--;
            }
        }

    }

    static class UndirectedEdge extends DirectedEdge {
        public UndirectedEdge rev;

        public UndirectedEdge(int to) {
            super(to);
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

    static class Query {
        int l;
        int r;
        long ans;

    }

    static interface SimplifiedStack<T> extends Iterable<T> {
        boolean isEmpty();

    }

    static class LcaOnTree {
        int[] parent;
        int[] preOrder;
        int[] i;
        int[] head;
        int[] a;
        int time;

        void dfs1(List<UndirectedEdge>[] tree, int u, int p) {
            parent[u] = p;
            i[u] = preOrder[u] = time++;
            for (UndirectedEdge e : tree[u]) {
                int v = e.to;
                if (v == p) continue;
                dfs1(tree, v, u);
                if (Integer.lowestOneBit(i[u]) < Integer.lowestOneBit(i[v])) {
                    i[u] = i[v];
                }
            }
            head[i[u]] = u;
        }

        void dfs2(List<UndirectedEdge>[] tree, int u, int p, int up) {
            a[u] = up | Integer.lowestOneBit(i[u]);
            for (UndirectedEdge e : tree[u]) {
                int v = e.to;
                if (v == p) continue;
                dfs2(tree, v, u, a[u]);
            }
        }

        public LcaOnTree(List<UndirectedEdge>[] tree, int root) {
            int n = tree.length;
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

    static class DSU {
        int[] p;
        int[] rank;

        public DSU(int n) {
            p = new int[n];
            rank = new int[n];
            reset();
        }

        public void reset() {
            for (int i = 0; i < p.length; i++) {
                p[i] = i;
                rank[i] = 0;
            }
        }

        public int find(int a) {
            return p[a] == p[p[a]] ? p[a] : (p[a] = find(p[a]));
        }

        public void merge(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) {
                return;
            }
            if (rank[a] == rank[b]) {
                rank[a]++;
            }
            if (rank[a] > rank[b]) {
                p[b] = a;
            } else {
                p[a] = b;
            }
        }

    }

    static class Segment implements Cloneable {
        private Segment left;
        private Segment right;
        private long sum;
        private int size;
        private long dirty;

        public void modify(long x) {
            sum += x * size;
            dirty += x;
        }

        public void pushUp() {
            size = left.size + right.size;
            sum = left.sum + right.sum;
        }

        public void pushDown() {
            if (dirty != 0) {
                left.modify(dirty);
                right.modify(dirty);
                dirty = 0;
            }
        }

        public Segment(int l, int r) {
            if (l < r) {
                int m = (l + r) >> 1;
                left = new Segment(l, m);
                right = new Segment(m + 1, r);
                pushUp();
            } else {
                size = 1;
            }
        }

        private boolean covered(int ll, int rr, int l, int r) {
            return ll <= l && rr >= r;
        }

        private boolean noIntersection(int ll, int rr, int l, int r) {
            return ll > r || rr < l;
        }

        public void update(int ll, int rr, int l, int r, long x) {
            if (noIntersection(ll, rr, l, r)) {
                return;
            }
            if (covered(ll, rr, l, r)) {
                modify(x);
                return;
            }
            pushDown();
            int m = (l + r) >> 1;
            left.update(ll, rr, l, m, x);
            right.update(ll, rr, m + 1, r, x);
            pushUp();
        }

        public long query(int ll, int rr, int l, int r) {
            if (noIntersection(ll, rr, l, r)) {
                return 0;
            }
            if (covered(ll, rr, l, r)) {
                return sum;
            }
            pushDown();
            int m = (l + r) >> 1;
            return left.query(ll, rr, l, m) +
                    right.query(ll, rr, m + 1, r);
        }

        private Segment deepClone() {
            Segment seg = clone();
            if (seg.left != null) {
                seg.left = seg.left.deepClone();
            }
            if (seg.right != null) {
                seg.right = seg.right.deepClone();
            }
            return seg;
        }

        protected Segment clone() {
            try {
                return (Segment) super.clone();
            } catch (CloneNotSupportedException e) {
                throw new RuntimeException(e);
            }
        }

        private void toString(StringBuilder builder) {
            if (left == null && right == null) {
                builder.append("val").append(",");
                return;
            }
            pushDown();
            left.toString(builder);
            right.toString(builder);
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            deepClone().toString(builder);
            if (builder.length() > 0) {
                builder.setLength(builder.length() - 1);
            }
            return builder.toString();
        }

    }

    static class Range2DequeAdapter<T> implements SimplifiedDeque<T> {
        IntFunction<T> data;
        int l;
        int r;

        public Range2DequeAdapter(IntFunction<T> data, int l, int r) {
            this.data = data;
            this.l = l;
            this.r = r;
        }

        public boolean isEmpty() {
            return l > r;
        }

        public T peekFirst() {
            return data.apply(l);
        }

        public T removeFirst() {
            return data.apply(l++);
        }

        public Iterator<T> iterator() {
            return new Iterator<T>() {
                int iter = l;


                public boolean hasNext() {
                    return iter <= r;
                }


                public T next() {
                    return data.apply(iter++);
                }
            };
        }

    }

    static class FastInput {
        private final InputStream is;
        private byte[] buf = new byte[1 << 20];
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