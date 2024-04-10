import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.util.Deque;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
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
        Deque<Node> deque = new ArrayDeque<>(200000);
        int dfn = 1;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int k = in.readInt();
            int[] p = new int[n];
            int[] q = new int[n];
            for (int i = 0; i < n; i++) {
                p[i] = in.readInt() - 1;
            }
            for (int i = 0; i < n; i++) {
                q[i] = in.readInt() - 1;
            }
            Node[] nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new Node();
            }
            for (int i = 1; i < n; i++) {
                nodes[q[i]].next.add(nodes[q[i - 1]]);
                nodes[p[i]].next.add(nodes[p[i - 1]]);
            }

            int distinct = 0;
            for (Node node : nodes) {
                tarjan(node);
                if (node == node.set) {
                    distinct++;
                }
            }

            if (distinct < k) {
                out.println("NO");
                return;
            }

            List<Node> trace = new ArrayList<>(n);
            for (Node node : nodes) {
                topologicalSort(node, trace);
            }
            for (int i = 0; i < trace.size(); i++) {
                trace.get(i).val = Math.min(i, 25);
            }
            out.println("YES");
            for (Node node : nodes) {
                out.append((char) (node.set.val + 'a'));
            }
        }

        public void topologicalSort(Node root, List<Node> trace) {
            if (root.visited) {
                return;
            }
            root.visited = true;
            for (Node node : root.next) {
                topologicalSort(node, trace);
            }
            if (root.set == root) {
                trace.add(root);
            }
        }

        public void tarjan(Node root) {
            if (root.dfn != 0) {
                return;
            }
            root.dfn = root.low = dfn++;
            root.instk = true;
            deque.addLast(root);

            for (Node node : root.next) {
                tarjan(node);
                if (node.instk && node.low < root.low) {
                    root.low = node.low;
                }
            }

            if (root.low == root.dfn) {
                while (true) {
                    Node tail = deque.removeLast();
                    tail.set = root;
                    tail.instk = false;
                    if (tail == root) {
                        break;
                    }
                }
            }
        }

    }

    static class Node {
        List<Node> next = new ArrayList<>(2);
        Node set;
        int dfn;
        int low;
        boolean instk;
        int val;
        boolean visited;

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