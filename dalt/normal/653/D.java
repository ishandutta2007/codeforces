import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.math.BigDecimal;
import java.util.List;
import java.util.stream.Stream;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.function.DoublePredicate;
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
            DDeliveryBears solver = new DDeliveryBears();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DDeliveryBears {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int m = in.ri();
            int x = in.ri();
            int[][] edges = new int[m][3];
            for (int i = 0; i < m; i++) {
                edges[i][0] = in.ri() - 1;
                edges[i][1] = in.ri() - 1;
                edges[i][2] = in.ri();
            }
            LongISAP isap = new LongISAP();
            DoublePredicate pred = mid -> {
                List<LongFlowEdge>[] g = Graph.createGraph(n);
                for (int[] e : edges) {
                    LongFlow.addFlowEdge(g, e[0], e[1], (long) (e[2] / mid));
                }
                long flow = isap.apply(g, 0, n - 1, x);
                return flow < x;
            };
            double ans = BinarySearch.firstTrue(pred, 1e-12, 1e12, 1e-12, 1e-12);
            out.println(ans * x);
        }

    }

    static interface IntegerStack {
        void addLast(int x);

        boolean isEmpty();

        void clear();

    }

    static class LongFlowEdge<T extends LongFlowEdge<T>> extends DirectedEdge {
        public long flow;
        public boolean real;
        public T rev;

        public LongFlowEdge(int to, long flow, boolean real) {
            super(to);
            this.flow = flow;
            this.real = real;
        }

        public String toString() {
            return rev.to + "-[" + flow + "/" + (flow + rev.flow) + "]->" + to;
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

    static class LongISAP implements LongMaximumFlow {
        private List<LongFlowEdge>[] net;
        private int s;
        private int t;
        private int[] dists;
        private int[] cnts;
        private int n;
        private boolean exit;
        private IntegerDeque deque;

        public LongISAP() {
        }

        public void ensure(int vertexNum) {
            if (dists != null && dists.length >= vertexNum) {
                return;
            }
            dists = new int[vertexNum];
            cnts = new int[vertexNum + 2];
            deque = new IntegerDequeImpl(n);
        }

        private long send(int root, long flow) {
            if (root == t) {
                return flow;
            }
            long snapshot = flow;
            for (LongFlowEdge e : net[root]) {
                long remain;
                if (dists[e.to] + 1 != dists[root] || (remain = e.rev.flow) == 0) {
                    continue;
                }
                long sent = send(e.to, Math.min(flow, remain));
                flow -= sent;
                LongFlow.send(e, sent);
                if (flow == 0 || exit) {
                    break;
                }
            }
            if (flow == snapshot) {
                cnts[dists[root]]--;
                dists[root]++;
                cnts[dists[root]]++;
                if (cnts[dists[root] - 1] == 0) {
                    exit = true;
                }
            }
            return snapshot - flow;
        }

        public long apply(List<LongFlowEdge>[] g, int s, int t, long send) {
            ensure(g.length);
            this.net = g;
            this.s = s;
            this.t = t;
            this.exit = false;
            n = g.length;
            LongFlow.bfsForFlow(g, t, dists, n + 1, deque);
            Arrays.fill(cnts, 0, n + 2, 0);
            for (int d : dists) {
                cnts[d]++;
            }
            long flow = 0;
            while (flow < send && !exit && dists[s] < n) {
                flow += send(s, send - flow);
            }
            return flow;
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static boolean equal(long a, long b) {
            return a == b;
        }

    }

    static interface LongMaximumFlow {
    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private static final int THRESHOLD = 32 << 10;
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

        public FastOutput append(double c) {
            cache.append(new BigDecimal(c).toPlainString());
            afterWrite();
            return this;
        }

        public FastOutput append(String c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(double c) {
            return append(c).println();
        }

        public FastOutput println() {
            return append(System.lineSeparator());
        }

        public FastOutput flush() {
            try {
//            boolean success = false;
//            if (stringBuilderValueField != null) {
//                try {
//                    char[] value = (char[]) stringBuilderValueField.get(cache);
//                    os.write(value, 0, cache.length());
//                    success = true;
//                } catch (Exception e) {
//                }
//            }
//            if (!success) {
                os.append(cache);
//            }
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

    static class LongFlow {
        public static <T extends LongFlowEdge> void send(T edge, long flow) {
            edge.flow += flow;
            edge.rev.flow -= flow;
        }

        public static LongFlowEdge addFlowEdge(List[] g, int s, int t, long cap) {
            LongFlowEdge real = new LongFlowEdge(t, 0, true);
            LongFlowEdge virtual = new LongFlowEdge(s, cap, false);
            real.rev = virtual;
            virtual.rev = real;
            g[s].add(real);
            g[t].add(virtual);
            return real;
        }

        public static <T extends LongFlowEdge> void bfsForFlow(List<T>[] g, int s, int[] dist, int inf, IntegerDeque deque) {
            Arrays.fill(dist, 0, g.length, inf);
            dist[s] = 0;
            deque.clear();
            deque.addLast(s);
            while (!deque.isEmpty()) {
                int head = deque.removeFirst();
                for (T e : g[head]) {
                    if (!DigitUtils.equal(e.flow, 0) && dist[e.to] == inf) {
                        dist[e.to] = dist[head] + 1;
                        deque.addLast(e.to);
                    }
                }
            }
        }

    }

    static class DirectedEdge {
        public int to;

        public DirectedEdge(int to) {
            this.to = to;
        }

        public String toString() {
            return "->" + to;
        }

    }

    static class IntegerDequeImpl implements IntegerDeque {
        private int[] data;
        private int bpos;
        private int epos;
        private static final int[] EMPTY = new int[0];
        private int n;

        public IntegerDequeImpl(int cap) {
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
            bpos = 0;
            epos = 0;
            n = cap;
        }

        private void expandSpace(int len) {
            while (n < len) {
                n = Math.max(n + 10, n * 2);
            }
            int[] newData = new int[n];
            if (bpos <= epos) {
                if (bpos < epos) {
                    System.arraycopy(data, bpos, newData, 0, epos - bpos);
                }
            } else {
                System.arraycopy(data, bpos, newData, 0, data.length - bpos);
                System.arraycopy(data, 0, newData, data.length - bpos, epos);
            }
            epos = size();
            bpos = 0;
            data = newData;
        }

        public IntegerIterator iterator() {
            return new IntegerIterator() {
                int index = bpos;


                public boolean hasNext() {
                    return index != epos;
                }


                public int next() {
                    int ans = data[index];
                    index = IntegerDequeImpl.this.next(index);
                    return ans;
                }
            };
        }

        public int removeFirst() {
            int ans = data[bpos];
            bpos = next(bpos);
            return ans;
        }

        public void addLast(int x) {
            ensureMore();
            data[epos] = x;
            epos = next(epos);
        }

        public void clear() {
            bpos = epos = 0;
        }

        private int next(int x) {
            return x + 1 >= n ? 0 : x + 1;
        }

        private void ensureMore() {
            if (next(epos) == bpos) {
                expandSpace(n + 1);
            }
        }

        public int size() {
            int ans = epos - bpos;
            if (ans < 0) {
                ans += data.length;
            }
            return ans;
        }

        public boolean isEmpty() {
            return bpos == epos;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (IntegerIterator iterator = iterator(); iterator.hasNext(); ) {
                builder.append(iterator.next()).append(' ');
            }
            return builder.toString();
        }

    }

    static interface IntegerDeque extends IntegerStack {
        int removeFirst();

    }

    static interface IntegerIterator {
        boolean hasNext();

        int next();

    }

    static class Graph {
        public static List[] createGraph(int n) {
            return IntStream.range(0, n).mapToObj(i -> new ArrayList<>()).toArray(i -> new List[i]);
        }

    }

    static class BinarySearch {
        private BinarySearch() {
        }

        public static double firstTrue(DoublePredicate predicate, double l, double r, double absError, double relativeError) {
            if (l > r) {
                throw new IllegalArgumentException();
            }
            while (r - l > absError) {
                if ((r < 0 && (r - l) < -r * relativeError) || (l > 0 && (r - l) < l * relativeError)) {
                    break;
                }
                double mid = (l + r) / 2;
                if (predicate.test(mid)) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            return (l + r) / 2;
        }

    }
}