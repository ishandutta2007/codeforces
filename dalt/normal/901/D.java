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
            DWeightingATree solver = new DWeightingATree();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DWeightingATree {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            Node[] nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
                nodes[i].w = in.readInt();
            }
            DSU dsu = new DSU(n);
            Edge[] edges = new Edge[m];
            for (int i = 0; i < m; i++) {
                edges[i] = new Edge();
                edges[i].a = nodes[in.readInt() - 1];
                edges[i].b = nodes[in.readInt() - 1];
                if (dsu.find(edges[i].a.id) != dsu.find(edges[i].b.id)) {
                    edges[i].tree = true;
                    dsu.merge(edges[i].a.id, edges[i].b.id);
                    edges[i].a.next.add(edges[i]);
                    edges[i].b.next.add(edges[i]);
                }
            }

            dfs(nodes[0], null, 0);
            long diff = 0;
            for (Node node : nodes) {
                if (node.sign) {
                    diff += node.w;
                } else {
                    diff -= node.w;
                }
            }

            if (diff % 2 != 0) {
                out.println("NO");
                return;
            }

            for (Edge e : edges) {
                if (e.tree) {
                    continue;
                }
                if (e.a.sign != e.b.sign) {
                    continue;
                }
                if (e.a.sign) {
                    e.val = diff / 2;
                } else {
                    e.val = -diff / 2;
                }
                e.a.w -= e.val;
                e.b.w -= e.val;
                diff = 0;
                break;
            }

            if (diff != 0) {
                out.println("NO");
                return;
            }

            dfs(nodes[0], null, 0);
            out.println("YES");
            for (Edge e : edges) {
                out.println(e.val);
            }
        }

        public long dfs(Node root, Edge p, int d) {
            root.sign = d % 2 == 0;
            long w = root.w;
            for (Edge e : root.next) {
                Node node = e.other(root);
                if (e == p) {
                    continue;
                }
                long need = dfs(node, e, d + 1);
                e.val = need;
                w -= need;
            }
            return w;
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

        public FastOutput println(String c) {
            cache.append(c);
            println();
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

    static class Edge {
        Node a;
        Node b;
        long val;
        boolean tree;

        Node other(Node x) {
            return a == x ? b : a;
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

    static class Node {
        int id;
        List<Edge> next = new ArrayList<>();
        long w;
        boolean sign;

    }
}