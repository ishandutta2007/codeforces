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
            EGraphCutting solver = new EGraphCutting();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class EGraphCutting {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            Node[] nodes = new Node[n + 1];
            for (int i = 1; i <= n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
            }
            for (int i = 0; i < m; i++) {
                Edge e = new Edge();
                e.a = nodes[in.readInt()];
                e.b = nodes[in.readInt()];
                e.a.next.add(e);
                e.b.next.add(e);
                e.a.xor ^= 1;
                e.toA = 1;
            }
            for (int i = 1; i <= n; i++) {
                if (nodes[i].visited) {
                    continue;
                }
                dfs(nodes[i], null);
            }

            List<int[]> solutions = new ArrayList<>(m / 2);
            for (int i = 1; i <= n; i++) {
                Node node = nodes[i];
                Edge remain = null;
                for (Edge e : node.next) {
                    if (e.toWhich() != node) {
                        continue;
                    }
                    if (remain == null) {
                        remain = e;
                    } else {
                        solutions.add(SequenceUtils.wrapArray(
                                remain.other(node).id, node.id, e.other(node).id));
                        remain = null;
                    }
                }
                if (remain != null) {
                    out.println("No solution");
                    return;
                }
            }
            for (int[] s : solutions) {
                for (int x : s) {
                    out.append(x).append(' ');
                }
                out.println();
            }
        }

        static void dfs(Node root, Edge p) {
            root.visited = true;
            for (Edge e : root.next) {
                Node node = e.other(root);
                if (node.visited) {
                    continue;
                }
                dfs(node, e);
                root.xor ^= node.xor;
            }
            if (p != null) {
                p.toA ^= root.xor;
            }
        }

    }

    static class Node {
        int id;
        int xor;
        boolean visited;
        List<Edge> next = new ArrayList<>();

    }

    static class Edge {
        Node a;
        Node b;
        int toA;

        Node other(Node x) {
            return a == x ? b : a;
        }

        Node toWhich() {
            return toA == 1 ? a : b;
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

        public FastOutput append(int c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(String c) {
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

    static class SequenceUtils {
        public static int[] wrapArray(int... x) {
            return x;
        }

    }
}