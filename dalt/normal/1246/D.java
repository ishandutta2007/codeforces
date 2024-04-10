import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.util.TreeSet;
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
            TaskD solver = new TaskD();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskD {
        List<Node> seq = new ArrayList<>(100000);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            Node[] nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
            }
            for (int i = 1; i < n; i++) {
                Node p = nodes[in.readInt()];
                p.next.add(nodes[i]);
            }
            dfs(nodes[0], 0);
            merge(nodes[0]);

            for (Node node = nodes[0]; node != null; node = node.queue.isEmpty() ? null : node.queue.first()) {
                out.append(node.id).append(' ');
            }
            out.println();
            ArrayUtils.reverse(seq, 0, seq.size());
            out.println(seq.size());
            for (Node node : seq) {
                out.append(node.id).append(' ');
            }
        }

        public void merge(Node root) {
            if (root.visited) {
                return;
            }
            root.visited = true;
            if (root.queue.isEmpty()) {
                return;
            }
            Node min = root.queue.pollFirst();
            merge(min);
            while (!root.queue.isEmpty()) {
                Node deepest = root.queue.pollFirst();
                min.depthest++;
                deepest.queue.add(min);
                seq.add(min);
                merge(deepest);
                min = deepest;
            }
            root.queue.add(min);
            root.depthest = min.depthest;
        }

        public void dfs(Node root, int depth) {
            root.depth = depth;
            root.depthest = depth;
            for (Node node : root.next) {
                dfs(node, depth + 1);
                root.depthest = Math.max(node.depthest, root.depthest);
                root.queue.add(node);
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

        public FastOutput println(int c) {
            cache.append(c).append('\n');
            return this;
        }

        public FastOutput println() {
            cache.append('\n');
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

    static class ArrayUtils {
        public static <T> void swap(List<T> data, int i, int j) {
            T tmp = data.get(i);
            data.set(i, data.get(j));
            data.set(j, tmp);
        }

        public static <T> void reverse(List<T> data, int f, int t) {
            int l = f, r = t - 1;
            while (l < r) {
                swap(data, l, r);
                l++;
                r--;
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

    static class Node {
        int id;
        int depth;
        int depthest;
        boolean visited;
        TreeSet<Node> queue = new TreeSet<>((a, b) -> a.depthest == b.depthest ? a.id - b.id : -(a.depthest - b.depthest));
        List<Node> next = new ArrayList<>();

        public String toString() {
            return "" + id;
        }

    }
}