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
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 29);
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
            ECapitalism solver = new ECapitalism();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class ECapitalism {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int m = in.ri();
            XorDeltaDSU dsu = new XorDeltaDSU(n);
            dsu.init();
            DifferenceConstraintSystem dcs = new DifferenceConstraintSystem(n);
            for (int i = 0; i < m; i++) {
                int a = in.ri() - 1;
                int b = in.ri() - 1;
                int c = in.ri();
                if (dsu.find(a) == dsu.find(b) && dsu.delta(a, b) == 0) {
                    out.println("NO");
                    return;
                }
                dsu.merge(a, b, 1);
                if (c == 1) {
                    dcs.differenceEqualTo(a, b, -1);
                } else {
                    dcs.differenceLessThanOrEqualTo(a, b, 1);
                    dcs.differenceLessThanOrEqualTo(b, a, 1);
                }
            }
            int pairA = -1;
            long dist = -(int) 1e9;
            for (int i = 0; i < n; i++) {
                if (dcs.runSpfaSince(i)) {
                    long max = 0;
                    for (int j = 0; j < n; j++) {
                        max = Math.max(dcs.possibleSolutionOf(j), max);
                    }
                    if (max > dist) {
                        dist = max;
                        pairA = i;
                    }
                } else {
                    out.println("NO");
                    return;
                }
            }

            out.println("YES");
            out.println(dist);
            dcs.runSpfaSince(pairA);
            for (int i = 0; i < n; i++) {
                out.append(dcs.possibleSolutionOf(i)).append(' ');
            }
        }

    }

    static class DifferenceConstraintSystem {
        DifferenceConstraintSystem.Node[] nodes;
        Deque<DifferenceConstraintSystem.Node> deque;
        int n;
        boolean hasSolution;
        public static final long INF = (long) 2e18;

        public DifferenceConstraintSystem(int n) {
            this.n = n;
            deque = new ArrayDeque<>(n);
            nodes = new DifferenceConstraintSystem.Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new DifferenceConstraintSystem.Node();
                nodes[i].id = i;
            }
        }

        public void differenceLessThanOrEqualTo(int i, int j, long d) {
            nodes[j].edges.add(new DifferenceConstraintSystem.Edge(nodes[j], nodes[i], d));
        }

        public void differenceGreaterThanOrEqualTo(int i, int j, long d) {
            differenceLessThanOrEqualTo(j, i, -d);
        }

        public void differenceEqualTo(int i, int j, long d) {
            differenceGreaterThanOrEqualTo(i, j, d);
            differenceLessThanOrEqualTo(i, j, d);
        }

        private boolean spfa() {
            while (!deque.isEmpty()) {
                DifferenceConstraintSystem.Node head = deque.removeFirst();
                head.inque = false;
                if (head.times >= n) {
                    return false;
                }
                for (DifferenceConstraintSystem.Edge edge : head.edges) {
                    DifferenceConstraintSystem.Node node = edge.next;
                    if (node.dist <= edge.len + head.dist) {
                        continue;
                    }
                    node.dist = edge.len + head.dist;
                    if (node.inque) {
                        continue;
                    }
                    node.times++;
                    node.inque = true;
                    deque.addLast(node);
                }
            }
            return true;
        }

        public long possibleSolutionOf(int i) {
            return nodes[i].dist;
        }

        private void prepare(long initDist) {
            deque.clear();
            for (int i = 0; i < n; i++) {
                nodes[i].dist = initDist;
                nodes[i].times = 0;
                nodes[i].inque = false;
                nodes[i].instk = false;
            }
        }

        public boolean runSpfaSince(int j) {
            prepare(INF);
            deque.clear();
            deque.addLast(nodes[j]);
            nodes[j].dist = 0;
            nodes[j].inque = true;
            hasSolution = spfa();
            return hasSolution;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < n; i++) {
                for (DifferenceConstraintSystem.Edge edge : nodes[i].edges) {
                    builder.append(edge).append('\n');
                }
            }
            builder.append("-------------\n");
            if (!hasSolution) {
                builder.append("impossible");
            } else {
                for (int i = 0; i < n; i++) {
                    builder.append("a").append(i).append("=").append(nodes[i].dist).append('\n');
                }
            }
            return builder.toString();
        }

        private static class Node {
            List<DifferenceConstraintSystem.Edge> edges = new ArrayList();
            long dist;
            boolean inque;
            boolean instk;
            int times;
            int id;

            public String toString() {
                return "a" + id;
            }

        }

        private static class Edge {
            final DifferenceConstraintSystem.Node src;
            final DifferenceConstraintSystem.Node next;
            final long len;

            private Edge(DifferenceConstraintSystem.Node src, DifferenceConstraintSystem.Node next, long len) {
                this.src = src;
                this.next = next;
                this.len = len;
            }

            public String toString() {
                return String.format("%s - %s <= %d", next.toString(), src.toString(), len);
            }

        }

    }

    static class XorDeltaDSU {
        int[] p;
        int[] rank;
        int[] delta;

        public XorDeltaDSU(int n) {
            p = new int[n];
            rank = new int[n];
            delta = new int[n];
            init();
        }

        public void init() {
            init(p.length);
        }

        public void init(int n) {
            for (int i = 0; i < n; i++) {
                p[i] = i;
                rank[i] = 0;
                delta[i] = 0;
            }
        }

        public int find(int a) {
            if (p[a] == p[p[a]]) {
                return p[a];
            }
            find(p[a]);
            delta[a] ^= delta[p[a]];
            return p[a] = p[p[a]];
        }

        public int delta(int a, int b) {
            find(a);
            find(b);
            return delta[a] ^ delta[b];
        }

        public void merge(int a, int b, int d) {
            find(a);
            find(b);
            d = d ^ delta[a] ^ delta[b];
            a = find(a);
            b = find(b);
            if (a == b) {
                return;
            }
            if (rank[a] == rank[b]) {
                rank[a]++;
            }
            if (rank[a] > rank[b]) {
                p[b] = a;
                delta[b] = d;
            } else {
                p[a] = b;
                delta[a] = d;
            }
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private static final int THRESHOLD = 1 << 13;
        private final Writer os;
        private StringBuilder cache = new StringBuilder(THRESHOLD * 2);

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

        private void afterWrite() {
            if (cache.length() < THRESHOLD) {
                return;
            }
            flush();
        }

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput append(char c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(long c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(String c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(String c) {
            return append(c).println();
        }

        public FastOutput println(long c) {
            return append(c).println();
        }

        public FastOutput println() {
            return append(System.lineSeparator());
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

        public int ri() {
            return readInt();
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