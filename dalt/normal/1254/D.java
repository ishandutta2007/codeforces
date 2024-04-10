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
 * Built using CHelper plug-in Actual solution is at the top
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
            TaskD solver = new TaskD();
            solver.solve(1, in, out);
            out.close();
        }
    }
    static class TaskD {
        NumberTheory.Modular mod = new NumberTheory.Modular(998244353);
        NumberTheory.Power pow = new NumberTheory.Power(mod);
        int dfn = 1;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int q = in.readInt();
            Node[] nodes = new Node[n + 1];
            for (int i = 1; i <= n; i++) {
                nodes[i] = new Node();
            }
            for (int i = 1; i < n; i++) {
                Node a = nodes[in.readInt()];
                Node b = nodes[in.readInt()];
                a.next.add(b);
                b.next.add(a);
            }

            dfs1(nodes[1], null);
            dfs2(nodes[1], null);
            Segment seg = new Segment(1, n);
            int invN = pow.inverse(n);
            for (int i = 0; i < q; i++) {
                int t = in.readInt();
                if (t == 1) {
                    int v = in.readInt();
                    int d = in.readInt();
                    nodes[v].count = mod.plus(nodes[v].count, d);
                    if (nodes[v].heavy != null) {
                        int prob = mod.mul(n - nodes[v].heavy.size, invN);
                        int plus = mod.mul(prob, d);
                        seg.update(nodes[v].heavy.l, nodes[v].heavy.r, 1, n, plus);
                    }
                    int prob = mod.mul(nodes[v].size, invN);
                    int plus = mod.mul(prob, d);
                    seg.update(1, nodes[v].l - 1, 1, n, plus);
                    seg.update(nodes[v].r + 1, n, 1, n, plus);
                } else {
                    int v = in.readInt();
                    int exp = nodes[v].count;
                    exp = mod.plus(exp, seg.query(nodes[v].l, nodes[v].l, 1, n));

                    Node sub = nodes[v].lightFather;
                    while (sub != null) {
                        Node p = sub.parent;
                        int prob = mod.mul(n - sub.size, invN);
                        int plus = mod.mul(prob, p.count);
                        exp = mod.plus(exp, plus);
                        sub = p.lightFather;
                    }

                    out.println(exp);
                }
            }
        }

        public void dfs2(Node root, Node light) {
            root.lightFather = light;
            for (Node node : root.next) {
                if (node == root.heavy) {
                    dfs2(node, light);
                } else {
                    dfs2(node, node);
                }
            }
        }

        public void dfs1(Node root, Node p) {
            root.parent = p;
            root.next.remove(p);
            root.size = 1;
            root.l = dfn++;
            for (Node node : root.next) {
                dfs1(node, root);
                root.size += node.size;
                if (root.heavy == null || root.heavy.size < node.size) {
                    root.heavy = node;
                }
            }
            root.r = dfn - 1;
        }

    }
    static class Segment implements Cloneable {
        private static final NumberTheory.Modular MOD = new NumberTheory.Modular(998244353);
        private Segment left;
        private Segment right;
        private int sum;
        private int mod;
        private int size;

        private void mod(int x) {
            sum = MOD.plus(sum, MOD.mul(x, size));
            mod = MOD.plus(mod, x);
        }

        public void pushUp() {
            size = left.size + right.size;
            sum = left.sum + right.sum;
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
                size = 1;
            }
        }

        private boolean covered(int ll, int rr, int l, int r) {
            return ll <= l && rr >= r;
        }

        private boolean noIntersection(int ll, int rr, int l, int r) {
            return ll > r || rr < l;
        }

        public void update(int ll, int rr, int l, int r, int x) {
            if (noIntersection(ll, rr, l, r)) {
                return;
            }
            if (covered(ll, rr, l, r)) {
                mod(x);
                return;
            }
            pushDown();
            int m = (l + r) >> 1;
            left.update(ll, rr, l, m, x);
            right.update(ll, rr, m + 1, r, x);
            pushUp();
        }

        public int query(int ll, int rr, int l, int r) {
            if (noIntersection(ll, rr, l, r)) {
                return 0;
            }
            if (covered(ll, rr, l, r)) {
                return sum;
            }
            pushDown();
            int m = (l + r) >> 1;
            return MOD.plus(left.query(ll, rr, l, m), right.query(ll, rr, m + 1, r));
        }

    }
    static class Node {
        List<Node> next = new ArrayList<>();
        Node heavy;
        int size;
        Node lightFather;
        Node parent;
        int l;
        int r;
        int count;

    }
    static class NumberTheory {
        public static class Modular {
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

        public static class Power {
            final NumberTheory.Modular modular;

            public Power(NumberTheory.Modular modular) {
                this.modular = modular;
            }

            public int pow(int x, long n) {
                if (n == 0) {
                    return modular.valueOf(1);
                }
                long r = pow(x, n >> 1);
                r = modular.valueOf(r * r);
                if ((n & 1) == 1) {
                    r = modular.valueOf(r * x);
                }
                return (int) r;
            }

            public int inverse(int x) {
                return pow(x, modular.m - 2);
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
}