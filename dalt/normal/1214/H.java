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
            TaskH solver = new TaskH();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskH {
        boolean valid = true;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int k = in.readInt();
            Node[] nodes = new Node[n + 1];
            for (int i = 1; i <= n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
            }
            for (int i = 1; i < n; i++) {
                Node a = nodes[in.readInt()];
                Node b = nodes[in.readInt()];
                a.next.add(b);
                b.next.add(a);
            }
            findDiameter(nodes[1], null, 0);
            List<Node> trace = new ArrayList<>(n);
            dfsForTrace(nodes[1].a, null, 0, nodes[1].diameter, trace);

            int half = trace.size() / 2;
            Node a = trace.get(half - 1);
            Node b = trace.get(half);
            a.next.remove(b);
            b.next.remove(a);
            paint(a, b, 0, k, -1);
            paint(b, a, 1, k, 1);
            verify(a, b, 0, k);
            verify(b, a, 0, k);
            if (!valid) {
                out.println("No");
                return;
            }
            out.println("Yes");
            for (int i = 1; i <= n; i++) {
                out.append(nodes[i].color + 1).append(' ');
            }
        }

        public void verify(Node root, Node p, int depth, int k) {
            root.depth = depth;
            root.depthest = root;
            for (Node node : root.next) {
                if (node == p) {
                    continue;
                }
                verify(node, root, depth + 1, k);
                if (root.depthest != root && node.depthest.depth + root.depthest.depth - depth * 2 + 1 >= k && k > 2) {
                    valid = false;
                }
                if (node.depthest.depth > root.depthest.depth) {
                    root.depthest = node.depthest;
                }
            }
        }

        public void paint(Node root, Node p, int color, int k, int step) {
            root.color = DigitUtils.mod(color, k);
            for (Node node : root.next) {
                if (node == p) {
                    continue;
                }
                paint(node, root, color + step, k, step);
            }
        }

        public boolean dfsForTrace(Node root, Node p, int depth, int diameter, List<Node> trace) {
            trace.add(root);
            if (depth == diameter) {
                return true;
            }
            for (Node node : root.next) {
                if (node == p) {
                    continue;
                }
                if (dfsForTrace(node, root, depth + 1, diameter, trace)) {
                    return true;
                }
            }
            trace.remove(trace.size() - 1);
            return false;
        }

        public void findDiameter(Node root, Node p, int depth) {
            root.depth = depth;
            root.depthest = root;
            for (Node node : root.next) {
                if (node == p) {
                    continue;
                }
                findDiameter(node, root, depth + 1);
                if (root.diameter < node.diameter) {
                    root.diameter = node.diameter;
                    root.a = node.a;
                }
                if (root.depthest.depth + node.depthest.depth - root.depth * 2 > root.diameter) {
                    root.diameter = root.depthest.depth + node.depthest.depth - 2 * root.depth;
                    root.a = root.depthest;
                }
                if (root.depthest.depth < node.depthest.depth) {
                    root.depthest = node.depthest;
                }
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

        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }

        public FastOutput append(int c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(String c) {
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

    static class Node {
        List<Node> next = new ArrayList<>();
        int color;
        Node depthest;
        int depth;
        int diameter;
        Node a;
        int id;

        public String toString() {
            return "" + id;
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int mod(int x, int mod) {
            x %= mod;
            if (x < 0) {
                x += mod;
            }
            return x;
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