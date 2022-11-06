import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Iterator;
import java.io.IOException;
import java.util.TreeSet;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
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
            GSumOfPrefixSums solver = new GSumOfPrefixSums();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class GSumOfPrefixSums {
        long ans = 0;
        LongConvexHullTrick cht = new LongConvexHullTrick();

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            Node[] nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
            }
            for (int i = 1; i < n; i++) {
                Node a = nodes[in.readInt() - 1];
                Node b = nodes[in.readInt() - 1];
                a.next.add(b);
                b.next.add(a);
            }
            for (int i = 0; i < n; i++) {
                nodes[i].w = in.readInt();
            }

            dac(nodes[0], n * 2);
            out.println(ans);
        }

        private void prepareForAdd(Node root) {
            root.a = root.w;
            root.b = root.w;
            root.c = 1;
        }

        private void prepareForTest(Node root) {
            root.a = 0;
            root.b = 0;
            root.c = 0;
        }

        private void dac(Node root, int psize) {
            ans = Math.max(ans, root.w);
            dfsForSize(root, null);
            if (root.size == 1) {
                return;
            }
            int n = root.size;
            if (n * 2 > psize) {
                throw new RuntimeException();
            }
            root = dfsForCentroid(root, null, n);
            cht.clear();
            prepareForAdd(root);
            cht.insert(root.b, root.a);
            for (Node node : root.next) {
                prepareForTest(root);
                dfsForTest(node, root);
                prepareForAdd(root);
                dfsForAdd(node, root);
            }
            cht.clear();
            prepareForAdd(root);
            cht.insert(root.b, root.a);
            SequenceUtils.reverse(root.next);
            for (Node node : root.next) {
                prepareForTest(root);
                dfsForTest(node, root);
                prepareForAdd(root);
                dfsForAdd(node, root);
            }

            for (Node node : root.next) {
                node.next.remove(root);
                dac(node, n);
            }
        }

        private void dfsForTest(Node root, Node p) {
            root.a = p.a + p.b + root.w;
            root.b = p.b + root.w;
            root.c = p.c + 1;
            int size = 0;
            for (Node node : root.next) {
                if (node == p) {
                    continue;
                }
                dfsForTest(node, root);
                size++;
            }
            if (size == 0) {
                ans = Math.max(ans, root.a);
                LongConvexHullTrick.Line line = cht.queryLine(root.c);
                if (line != null) {
                    ans = Math.max(ans, line.y(root.c) + root.a);
                }
            }
        }

        private void dfsForAdd(Node root, Node p) {
            root.a = p.a + root.w * (1 + p.c);
            root.b = p.b + root.w;
            root.c = p.c + 1;
            int size = 0;
            for (Node node : root.next) {
                if (node == p) {
                    continue;
                }
                dfsForAdd(node, root);
                size++;
            }
            if (size == 0) {
                cht.insert(root.b, root.a);
                ans = Math.max(ans, root.a);
            }
        }

        private Node dfsForCentroid(Node root, Node p, int total) {
            int size = 0;
            for (Node node : root.next) {
                if (node == p) {
                    size = Math.max(size, total - root.size);
                } else {
                    size = Math.max(size, node.size);
                }
            }
            if (size <= total / 2) {
                return root;
            }
            for (Node node : root.next) {
                if (node == p) {
                    continue;
                }
                Node ans = dfsForCentroid(node, root, total);
                if (ans != null) {
                    return ans;
                }
            }
            return null;
        }

        private void dfsForSize(Node root, Node p) {
            root.size = 1;
            for (Node node : root.next) {
                if (node == p) {
                    continue;
                }
                dfsForSize(node, root);
                root.size += node.size;
            }
        }

    }

    static class Node {
        List<Node> next = new ArrayList<>();
        long w;
        int size;
        long a;
        long b;
        long c;
        int id;

        public String toString() {
            return "" + (id + 1);
        }

    }

    static class SequenceUtils {
        public static <T> void swap(List<T> data, int i, int j) {
            T tmp = data.get(i);
            data.set(i, data.get(j));
            data.set(j, tmp);
        }

        public static <T> void reverse(List<T> data, int l, int r) {
            while (l < r) {
                swap(data, l, r);
                l++;
                r--;
            }
        }

        public static <T> void reverse(List<T> data) {
            reverse(data, 0, data.size() - 1);
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

    static class LongConvexHullTrick implements Iterable<LongConvexHullTrick.Line> {
        static final long INF = (long) 2e18;
        TreeSet<LongConvexHullTrick.Line> setSortedByA = new TreeSet<>(LongConvexHullTrick.Line.sortByA);
        TreeSet<LongConvexHullTrick.Line> setSortedByL = new TreeSet<>(LongConvexHullTrick.Line.sortByL);
        private LongConvexHullTrick.Line qBody = new LongConvexHullTrick.Line(0, 0);

        private long rightBoundOfXPrefX(LongConvexHullTrick.Line x, LongConvexHullTrick.Line y) {
            //x.a * r + x.b >= y.a * r + y.b
            //x.a * (r + 1) + x.b < y.a * (r + 1) + y.b
            //r * (y.a - x.a) <= x.b - y.b
            //r <= (x.b - y.b) / (y.a - x.a)
            return (x.b - y.b) / (y.a - x.a);
        }

        private long rightBoundOfXPrefY(LongConvexHullTrick.Line x, LongConvexHullTrick.Line y) {
            return DigitUtils.floorDiv(x.b - y.b - 1, y.a - x.a);
        }

        private void removeLine(LongConvexHullTrick.Line line) {
            setSortedByA.remove(line);
            setSortedByL.remove(line);
        }

        private void addLine(LongConvexHullTrick.Line line) {
            setSortedByA.add(line);
            setSortedByL.add(line);
        }

        public LongConvexHullTrick.Line queryLine(long x) {
            qBody.l = x;
            return setSortedByL.floor(qBody);
        }

        public LongConvexHullTrick.Line insert(long a, long b) {
            LongConvexHullTrick.Line line = new LongConvexHullTrick.Line(a, b);

            while (true) {
                LongConvexHullTrick.Line floor = setSortedByA.floor(line);
                if (floor == null) {
                    line.l = -INF;
                    break;
                }
                if (floor.a == line.a) {
                    if (floor.b >= line.b) {
                        return line;
                    } else {
                        removeLine(floor);
                        continue;
                    }
                }

                long r = rightBoundOfXPrefX(floor, line);
                if (r > floor.r + 1) {
                    return line;
                }
                if (r < floor.l) {
                    removeLine(floor);
                    continue;
                }
                floor.r = r;
                line.l = r + 1;
                break;
            }

            while (true) {
                LongConvexHullTrick.Line ceil = setSortedByA.ceiling(line);
                if (ceil == null) {
                    line.r = INF;
                    break;
                }
                long r = rightBoundOfXPrefY(line, ceil);
                if (r < ceil.l - 1) {
                    return line;
                }
                removeLine(ceil);
                if (r >= ceil.r) {
                    continue;
                }
                ceil.l = r + 1;
                line.r = r;
                addLine(ceil);
                break;
            }

            if (!line.isEmpty()) {
                addLine(line);
            }
            return line;
        }

        public void clear() {
            setSortedByL.clear();
            setSortedByA.clear();
        }

        public Iterator<LongConvexHullTrick.Line> iterator() {
            return setSortedByA.iterator();
        }

        public static class Line {
            long a;
            long b;
            long l;
            long r;
            static Comparator<LongConvexHullTrick.Line> sortByA = (x, y) -> Long.compare(x.a, y.a);
            static Comparator<LongConvexHullTrick.Line> sortByL = (x, y) -> Long.compare(x.l, y.l);

            public Line(long a, long b) {
                this.a = a;
                this.b = b;
            }

            public long y(long x) {
                return a * x + b;
            }

            public boolean isEmpty() {
                return r < l;
            }

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

        public FastOutput println(long c) {
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

    static class DigitUtils {
        private DigitUtils() {
        }

        public static long floorDiv(long a, long b) {
            return a < 0 ? -ceilDiv(-a, b) : a / b;
        }

        public static long ceilDiv(long a, long b) {
            if (a < 0) {
                return -floorDiv(-a, b);
            }
            long c = a / b;
            if (c * b < a) {
                return c + 1;
            }
            return c;
        }

    }
}