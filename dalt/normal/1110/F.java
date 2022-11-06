import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
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
            TaskF solver = new TaskF();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskF {
        int n;
        Segment seg;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            n = in.readInt();
            int q = in.readInt();
            Node[] nodes = new Node[n + 1];
            for (int i = 1; i <= n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
            }
            for (int i = 2; i <= n; i++) {
                Node p = nodes[in.readInt()];
                Edge edge = new Edge();
                edge.a = p;
                edge.b = nodes[i];
                edge.w = in.readInt();
                edge.a.next.add(edge);
                edge.b.next.add(edge);
            }

            List<Query> qs = new ArrayList<>(q);
            for (int i = 0; i < q; i++) {
                Node node = nodes[in.readInt()];
                Query query = new Query();
                query.l = in.readInt();
                query.r = in.readInt();
                node.queries.add(query);
                qs.add(query);
            }
            seg = new Segment(1, n);
            dfs(nodes[1], null, 0);
            dfsForQuery(nodes[1], null);

            for (Query query : qs) {
                out.println(query.ans);
            }
        }

        public void dfs(Node root, Edge p, long dist) {
            root.l = root.r = root.id;
            root.next.remove(p);
            if (root.next.isEmpty()) {
                seg.update(root.id, root.id, 1, n, dist);
                return;
            }
            for (Edge e : root.next) {
                Node node = e.other(root);
                dfs(node, e, dist + e.w);
                root.l = Math.min(root.l, node.l);
                root.r = Math.max(root.r, node.r);
            }
            seg.update(root.id, root.id, 1, n, (long) 1e18);
        }

        public void dfsForQuery(Node root, Edge p) {
            if (p != null) {
                seg.update(1, n, 1, n, p.w);
                seg.update(root.l, root.r, 1, n, p.w * -2);
            }

            for (Edge e : root.next) {
                Node node = e.other(root);
                dfsForQuery(node, e);
            }

            for (Query q : root.queries) {
                q.ans = seg.query(q.l, q.r, 1, n);
            }

            if (p != null) {
                seg.update(root.l, root.r, 1, n, p.w * 2);
                seg.update(1, n, 1, n, -p.w);
            }
        }

    }

    static class Node {
        List<Edge> next = new ArrayList<>();
        List<Query> queries = new ArrayList<>();
        int l;
        int r;
        int id;

    }

    static class Query {
        int l;
        int r;
        long ans;

    }

    static class Segment implements Cloneable {
        private Segment left;
        private Segment right;
        private long min;
        private long mod;

        public void mod(long m) {
            min += m;
            mod += m;
        }

        public void pushUp() {
            min = Math.min(left.min, right.min);
        }

        public void pushDown() {
            if (mod != 0) {
                left.mod(mod);
                right.mod(mod);
                mod = 0;
            }
        }

        public Segment(int l, int r) {
            if (l < r) {
                int m = (l + r) >> 1;
                left = new Segment(l, m);
                right = new Segment(m + 1, r);
                pushUp();
            } else {

            }
        }

        private boolean covered(int ll, int rr, int l, int r) {
            return ll <= l && rr >= r;
        }

        private boolean noIntersection(int ll, int rr, int l, int r) {
            return ll > r || rr < l;
        }

        public void update(int ll, int rr, int l, int r, long mod) {
            if (noIntersection(ll, rr, l, r)) {
                return;
            }
            if (covered(ll, rr, l, r)) {
                mod(mod);
                return;
            }
            pushDown();
            int m = (l + r) >> 1;
            left.update(ll, rr, l, m, mod);
            right.update(ll, rr, m + 1, r, mod);
            pushUp();
        }

        public long query(int ll, int rr, int l, int r) {
            if (noIntersection(ll, rr, l, r)) {
                return (long) 1e18;
            }
            if (covered(ll, rr, l, r)) {
                return min;
            }
            pushDown();
            int m = (l + r) >> 1;
            return Math.min(left.query(ll, rr, l, m),
                    right.query(ll, rr, m + 1, r));
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

        public FastOutput println(long c) {
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

    static class Edge {
        Node a;
        Node b;
        int w;

        Node other(Node x) {
            return x == a ? b : a;
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