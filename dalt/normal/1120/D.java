import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Collection;
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
        List<Node> dpSolutions = new ArrayList<>(1000000);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            Node[] nodes = new Node[n + 1];
            for (int i = 1; i <= n; i++) {
                nodes[i] = new Node();
                nodes[i].price = in.readInt();
                nodes[i].id = i;
            }

            for (int i = 1; i < n; i++) {
                Node a = nodes[in.readInt()];
                Node b = nodes[in.readInt()];
                a.next.add(b);
                b.next.add(a);
            }

            dfsForDp(nodes[1], null);
            out.println(nodes[1].dp);
            dpSolutions.add(nodes[1].max);
            for (Node node : dpSolutions) {
                node.find().selected = true;
                for (Node c : node.candidate) {
                    c.find().selected = true;
                }
            }

            List<Integer> ans = new ArrayList<>(n);
            for (int i = 1; i <= n; i++) {
                if (nodes[i].find().selected) {
                    ans.add(i);
                }
            }

            out.println(ans.size());
            for (Integer node : ans) {
                out.append(node).append(' ');
            }
        }

        public void dfsForDp(Node root, Node father) {
            root.next.remove(father);
            if (root.next.isEmpty()) {
                root.dp = root.price;
                root.max = root;
                return;
            }
            Node max = null;
            int cnt = 0;
            for (Node node : root.next) {
                dfsForDp(node, root);
                root.dp += node.dp;
                if (max == null) {
                    max = node.max;
                    cnt = 1;
                } else if (node.max.price == max.price) {
                    Node.merge(node.max, max);
                    dpSolutions.add(node.max);
                    node.max.candidate = CollectionUtils.mergeHeuristically(max.candidate, node.max.candidate);
                    max.candidate = new ArrayList<>();
                    cnt++;
                } else if (node.max.price > max.price) {
                    dpSolutions.add(max);
                    max = node.max;
                    cnt = 1;
                } else {
                    dpSolutions.add(node.max);
                }
            }

            if (root.price == max.price) {
                max.candidate.add(root);
            }
            if (root.price < max.price) {
                if (cnt == 1) {
                    max.candidate.clear();
                } else {
                    dpSolutions.add(max);
                }

                root.dp -= max.price;
                root.dp += root.price;
                max = root;
            }
            root.max = max;
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

        public FastOutput append(Object c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(int c) {
            cache.append(c).append('\n');
            return this;
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
    static class Node {
        List<Node> next = new ArrayList<>();
        long dp;
        long price;
        Node p = this;
        int rank;
        int id;
        boolean selected;
        Node max;
        List<Node> candidate = new ArrayList<>();

        Node find() {
            return p == p.p ? p : (p = p.find());
        }

        static void merge(Node a, Node b) {
            a = a.find();
            b = b.find();
            if (a == b) {
                return;
            }
            if (a.rank == b.rank) {
                a.rank++;
            }
            if (a.rank > b.rank) {
                b.p = a;
            } else {
                a.p = b;
            }
        }

        public String toString() {
            return "" + id;
        }

    }
}