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
            EBreakingGood solver = new EBreakingGood();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class EBreakingGood {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            Node[] nodes = new Node[n];
            Edge[] edges = new Edge[m];
            for (int i = 0; i < n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
            }
            for (int i = 0; i < m; i++) {
                edges[i] = new Edge();
                edges[i].a = nodes[in.readInt() - 1];
                edges[i].b = nodes[in.readInt() - 1];
                edges[i].z = in.readInt();
                edges[i].a.next.add(edges[i]);
                edges[i].b.next.add(edges[i]);
            }
            int s = 0;
            int t = n - 1;
            for (int i = 0; i < n; i++) {
                nodes[i].dist = (int) 1e8;
                nodes[i].cost = (int) 1e8;
            }
            Deque<Node> deque = new ArrayDeque<>(n);
            nodes[s].dist = 0;
            nodes[s].cost = 0;
            deque.addLast(nodes[s]);
            while (!deque.isEmpty()) {
                Node head = deque.removeFirst();
                for (Edge e : head.next) {
                    Node node = e.other(head);
                    if (node.dist > head.dist + 1) {
                        node.dist = head.dist + 1;
                        node.cost = (int) 1e8;
                        node.prev = e;
                        deque.addLast(node);
                    }
                    int fee = e.z == 1 ? -1 : 1;
                    if (node.dist == head.dist + 1 &&
                            node.cost > head.cost + fee) {
                        node.cost = head.cost + fee;
                        node.prev = e;
                    }
                }
            }

            for (Node node = nodes[t]; node.prev != null; node = node.prev.other(node)) {
                node.prev.path = true;
            }

            List<Edge> edgeList = new ArrayList<>(m);
            for (int i = 0; i < m; i++) {
                if (edges[i].path) {
                    if (edges[i].z == 0) {
                        edgeList.add(edges[i]);
                    }
                } else {
                    if (edges[i].z == 1) {
                        edgeList.add(edges[i]);
                    }
                }
            }

            out.println(edgeList.size());
            for (Edge e : edgeList) {
                out.append(e.a.id + 1).append(' ')
                        .append(e.b.id + 1).append(' ').append(1 - e.z).println();
            }
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

        public FastOutput println(int c) {
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
        int z;
        Node a;
        Node b;
        boolean path;

        Node other(Node x) {
            return x == a ? b : a;
        }

    }

    static class Node {
        int id;
        int dist;
        int cost;
        Edge prev;
        List<Edge> next = new ArrayList<>();

    }
}