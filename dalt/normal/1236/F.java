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
 * 
 * @author daltao
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "daltao", 1 << 27);
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
        NumberTheory.Modular mod = new NumberTheory.Modular(1e9 + 7);
        NumberTheory.Power pow = new NumberTheory.Power(mod);
        int ONE_TWO = pow.inverse(2);
        int ONE_FOUR = pow.inverse(4);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            Node[] nodes = new Node[n + 1];
            for (int i = 1; i <= n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
            }

            Edge[] edges = new Edge[m];
            for (int i = 0; i < m; i++) {
                Edge edge = new Edge(nodes[in.readInt()], nodes[in.readInt()]);
                edge.a.next.add(edge);
                edge.b.next.add(edge);
                edges[i] = edge;
            }

            if (n == 1) {
                out.println(ONE_FOUR);
                return;
            }

            List<Circle> circles = new ArrayList<>(m);
            List<Node> stack = new ArrayList<>(n);
            dfsForCircle(nodes[1], null, circles, stack);

            int exp = 0;
            int loopContri = 0;
            int edgeContri = 0;
            int nodeContri = 0;
            for (Circle c : circles) {
                loopContri = mod.plus(loopContri, c.prob);
            }
            edgeContri = mod.mul(m, pow.pow(ONE_TWO, 2));
            nodeContri = mod.mul(n, pow.pow(ONE_TWO, 1));
            exp = mod.plus(loopContri, mod.subtract(nodeContri, edgeContri));

            int exp2 = 0;
            int loop2Contri = 0;
            int node2Contri = 0;
            int edge2Contri = 0;
            int loopNodeContri = 0;
            int loopEdgeContri = 0;
            int nodeEdgeContri = 0;

            int allCircleProbSum = 0;
            for (Circle c : circles) {
                allCircleProbSum = mod.plus(allCircleProbSum, pow.pow(ONE_TWO, c.nodes.size()));
            }

            for (Circle c : circles) {
                int local = 0;
                local = mod.plus(local, c.prob);
                local = mod.plus(local, mod.mul(c.prob, mod.subtract(allCircleProbSum, c.prob)));
                for (Node node : c.nodes) {
                    local = mod.plus(local, mod.mul(c.prob, mod.subtract(node.probSum, c.prob)));
                }
                loop2Contri = mod.plus(loop2Contri, local);
            }

            node2Contri = mod.plus(node2Contri, mod.mul(n, ONE_TWO));
            node2Contri = mod.plus(node2Contri, mod.mul(mod.mul(n, n - 1), ONE_FOUR));

            for (Edge e : edges) {
                int local = ONE_FOUR;
                int related = e.a.next.size() + e.b.next.size() - 2;
                int unrelated = m - related - 1;
                local = mod.plus(local, mod.mul(related, pow.pow(ONE_TWO, 3)));
                local = mod.plus(local, mod.mul(unrelated, pow.pow(ONE_TWO, 4)));
                edge2Contri = mod.plus(edge2Contri, local);
            }

            for (Circle c : circles) {
                int related = c.nodes.size();
                int unrelated = n - related;
                int local1 = mod.mul(related, pow.pow(ONE_TWO, c.nodes.size()));
                int local2 = mod.mul(unrelated, pow.pow(ONE_TWO, c.nodes.size() + 1));
                int local = mod.plus(local1, local2);
                loopNodeContri = mod.plus(loopNodeContri, local);
            }
            loopNodeContri = mod.mul(loopNodeContri, 2);

            for (Circle c : circles) {
                int relatedEdge = 0;
                for (Node node : c.nodes) {
                    relatedEdge += node.next.size() - 2;
                }
                int unrelatedEdge = m - c.nodes.size() - relatedEdge;
                int local1 = mod.mul(c.nodes.size(), c.prob);
                int local2 = mod.mul(relatedEdge, mod.mul(c.prob, ONE_TWO));
                int local3 = mod.mul(unrelatedEdge, mod.mul(c.prob, ONE_FOUR));
                int local = local1;
                local = mod.plus(local, local2);
                local = mod.plus(local, local3);
                loopEdgeContri = mod.plus(loopEdgeContri, local);
            }
            loopEdgeContri = mod.mul(loopEdgeContri, 2);

            nodeEdgeContri = mod.mul(2, ONE_FOUR);
            nodeEdgeContri = mod.plus(nodeEdgeContri, mod.mul(n - 2, pow.pow(ONE_TWO, 3)));
            nodeEdgeContri = mod.mul(nodeEdgeContri, m);
            nodeEdgeContri = mod.mul(nodeEdgeContri, 2);

            exp2 = mod.plus(exp2, loop2Contri);
            exp2 = mod.plus(exp2, node2Contri);
            exp2 = mod.plus(exp2, edge2Contri);
            exp2 = mod.plus(exp2, loopNodeContri);
            exp2 = mod.subtract(exp2, loopEdgeContri);
            exp2 = mod.subtract(exp2, nodeEdgeContri);

            int ans = mod.mul(exp, exp);
            ans = mod.subtract(exp2, ans);

            out.println(ans);
        }

        public void dfsForCircle(Node root, Edge from, List<Circle> circles, List<Node> stack) {
            if (root.visited) {
                if (!root.instack) {
                    return;
                }
                int len = from.other(root).depth - root.depth + 1;
                Circle c = new Circle(len);
                c.prob = pow.pow(ONE_TWO, len);
                circles.add(c);

                for (int i = stack.size() - 1; i >= 0; i--) {
                    Node node = stack.get(i);
                    c.nodes.add(node);
                    node.probSum = mod.plus(node.probSum, c.prob);
                    if (node == root) {
                        break;
                    }
                }
                return;
            }
            root.instack = true;
            stack.add(root);
            root.depth = stack.size();
            root.visited = true;
            for (Edge e : root.next) {
                if (e == from) {
                    continue;
                }
                Node node = e.other(root);
                dfsForCircle(node, e, circles, stack);
            }
            stack.remove(stack.size() - 1);
            root.instack = false;
        }

    }
    static class Node {
        List<Edge> next = new ArrayList<>(2);
        int probSum;
        int id;
        int depth;
        boolean visited = false;
        boolean instack;

        public String toString() {
            return "" + id;
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
                    throw new RuntimeException(e);
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
    static class Edge {
        Node a;
        Node b;

        public Edge(Node a, Node b) {
            this.a = a;
            this.b = b;
        }

        Node other(Node x) {
            return a == x ? b : a;
        }

    }
    static class FastOutput implements AutoCloseable, Closeable {
        private StringBuilder cache = new StringBuilder(1 << 20);
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

    }
    static class Circle {
        int prob;
        List<Node> nodes;

        public Circle(int cap) {
            nodes = new ArrayList<>(cap);
        }

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

            public int subtract(int x, int y) {
                return valueOf(x - y);
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
                    return 1;
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
}