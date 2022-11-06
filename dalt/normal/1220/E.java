import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Collection;
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
            TaskE solver = new TaskE();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskE {
        int dfn = 1;
        Deque<Node> stack = new ArrayDeque<>();

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            Node[] nodes = new Node[n + 1];
            for (int i = 1; i <= n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
                nodes[i].w = in.readInt();
            }

            for (int i = 0; i < m; i++) {
                Node a = nodes[in.readInt()];
                Node b = nodes[in.readInt()];
                a.next.add(b);
                b.next.add(a);
            }

            for (int i = 1; i <= n; i++) {
                tarjan(nodes[i], null);
            }

            Node root = nodes[in.readInt()].set;
            dfs(root);
            out.println(root.dp[0]);
        }

        void dfs(Node root) {
            root.visited = true;
            for (Node node : root.next) {
                node = node.set;
                if (node.visited) {
                    continue;
                }
                dfs(node);
                root.dp[0] = Math.max(node.dp[0] - node.dp[1], root.dp[0]);
                root.dp[1] += node.dp[1];
                root.meet = root.meet || node.meet;
            }
            root.dp[0] += root.dp[1] + root.w;
            root.meet = root.meet || root.size > 1;
            if (root.meet) {
                root.dp[1] += root.w;
            }
        }

        void tarjan(Node root, Node father) {
            if (root.dfn != 0) {
                return;
            }
            root.low = root.dfn = dfn++;
            root.instk = true;
            stack.addLast(root);
            for (Node node : root.next) {
                if (node == father) {
                    continue;
                }
                tarjan(node, root);
                if (node.instk) {
                    root.low = Math.min(root.low, node.low);
                }
            }
            if (root.low == root.dfn) {
                while (true) {
                    Node last = stack.removeLast();
                    last.set = root;
                    last.instk = false;
                    if (last == root) {
                        break;
                    }
                    root.w += last.w;
                    root.size++;
                    root.next = CollectionUtils.mergeHeuristically(root.next, last.next);
                }
            }
        }

    }

    static class Node {
        List<Node> next = new ArrayList<>();
        Node set;
        int dfn = 0;
        int low;
        boolean instk = false;
        long w;
        long[] dp = new long[2];
        boolean meet;
        boolean visited;
        int size = 1;
        int id;

        public String toString() {
            return "" + id;
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

    static class CollectionUtils {
        public static <E, T extends Collection<E>> T mergeHeuristically(T a, T b) {
            if (a.size() >= b.size()) {
                a.addAll(b);
                return a;
            } else {
                b.addAll(a);
                return b;
            }
        }

    }
}