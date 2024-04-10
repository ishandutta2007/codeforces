import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.AbstractQueue;
import java.io.IOException;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.util.stream.Stream;
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
            TaskF solver = new TaskF();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskF {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            int k = in.readInt();
            Node[] nodes = new Node[n + 1];
            for (int i = 1; i <= n; i++) {
                nodes[i] = new Node();
            }
            Edge[] edges = new Edge[m];
            for (int i = 0; i < m; i++) {
                edges[i] = new Edge();
                edges[i].a = nodes[in.readInt()];
                edges[i].b = nodes[in.readInt()];
                edges[i].w = in.readInt();
            }

            Arrays.sort(edges, (a, b) -> a.w - b.w);
            if (edges.length > k) {
                edges = Arrays.copyOf(edges, k);
            }
            PriorityQueue pq = find(edges).pq;
            while (pq.size() > k) {
                pq.remove();
            }

            out.println(pq.peek());
        }

        PQ find(Edge[] edges) {
            PQ pq = new PQ();
            for (Edge e : edges) {
                e.a.next.add(e);
                e.b.next.add(e);
            }
            Node[] nodes = Arrays.stream(edges).flatMap(x -> Stream.of(x.a, x.b)).toArray(x -> new Node[x]);
            for (Node node : nodes) {
                List<Node> trace = new ArrayList<>();
                trace(node, trace);
                if (trace.isEmpty()) {
                    continue;
                }
                maintain(trace, pq);
            }
            return pq;
        }

        private void maintain(List<Node> trace, PQ pq) {
            Node[] nodes = trace.toArray(new Node[0]);
            int n = nodes.length;
            for (int i = 0; i < n; i++) {
                nodes[i].id = i;
            }
            long[][] dist = new long[n][n];
            SequenceUtils.deepFill(dist, (long) 1e18);
            for (Node node : nodes) {
                for (Edge e : node.next) {
                    dist[e.a.id][e.b.id] = dist[e.b.id][e.a.id] = e.w;
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        dist[j][k] = Math.min(dist[j][k], dist[j][i] + dist[i][k]);
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    pq.add(dist[i][j]);
                }
            }
        }

        public void trace(Node root, List<Node> trace) {
            if (root.visited) {
                return;
            }
            root.visited = true;
            trace.add(root);
            for (Edge e : root.next) {
                Node node = e.a == root ? e.b : e.a;
                trace(node, trace);
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

        public FastOutput println(Object c) {
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
        int id;
        boolean visited;
        List<Edge> next = new ArrayList<>();

    }

    static class PQ {
        PriorityQueue<Long> pq = new PriorityQueue<>(400, (a, b) -> -a.compareTo(b));

        public void add(long x) {
            if (pq.size() < 400) {
                pq.add(x);
                return;
            }
            if (pq.peek() > x) {
                pq.remove();
                pq.add(x);
            }
        }

    }

    static class Edge {
        Node a;
        Node b;
        int w;

    }

    static class SequenceUtils {
        public static void deepFill(Object array, long val) {
            if (!array.getClass().isArray()) {
                throw new IllegalArgumentException();
            }
            if (array instanceof long[]) {
                long[] longArray = (long[]) array;
                Arrays.fill(longArray, val);
            } else {
                Object[] objArray = (Object[]) array;
                for (Object obj : objArray) {
                    deepFill(obj, val);
                }
            }
        }

    }
}