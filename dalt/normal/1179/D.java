import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Iterator;
import java.io.IOException;
import java.util.TreeSet;
import java.io.UncheckedIOException;
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
            TaskD solver = new TaskD();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskD {
        MultiWayIntDeque edges;
        long[] dp0;
        long[] dp1;
        int n;
        int[] size;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            n = in.readInt();
            dp0 = new long[n + 1];
            dp1 = new long[n + 1];
            size = new int[n + 1];
            edges = new MultiWayIntDeque(n + 1, 2 * n);
            for (int i = 1; i < n; i++) {
                int a = in.readInt();
                int b = in.readInt();
                edges.addFirst(a, b);
                edges.addFirst(b, a);
            }
            dfs(1, 0);
            long ans = 0;
            for (int i = 1; i <= n; i++) {
                ans = Math.max(ans, dp0[i]);
                ans = Math.max(ans, dp1[i]);
            }
            long origin = (long) n * (n - 1) / 2;
            out.println(ans + origin);
        }

        public void dfs(int root, int p) {
            size[root] = 1;
            for (IntIterator iterator = edges.iterator(root); iterator.hasNext(); ) {
                int node = iterator.next();
                if (node == p) {
                    continue;
                }
                dfs(node, root);
                size[root] += size[node];
            }
            ConvexHullTrick cht = new ConvexHullTrick();
            for (IntIterator iterator = edges.iterator(root); iterator.hasNext(); ) {
                int node = iterator.next();
                if (node == p) {
                    continue;
                }
                dp0[root] = Math.max(dp0[root], dp0[node] + (long) (size[root] - size[node]) * size[node]);
                if (!cht.isEmpty()) {
                    dp1[root] = Math.max(dp1[root], dp0[node] + (long) (n - size[node]) * size[node] + DigitUtils.round(cht.query(size[node])));
                }
                cht.insert(-size[node], dp0[node] + (long) (n - size[node]) * size[node]);
            }
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static long round(double x) {
            if (x >= 0) {
                return (long) (x + 0.5);
            } else {
                return (long) (x - 0.5);
            }
        }

    }

    static class ConvexHullTrick implements Iterable<ConvexHullTrick.Line> {
        static final double INF = 1e50;
        private TreeSet<ConvexHullTrick.Line> setOrderByA = new TreeSet(ConvexHullTrick.Line.orderByA);
        private TreeSet<ConvexHullTrick.Line> setOrderByLx = new TreeSet(ConvexHullTrick.Line.orderByLx);
        private ConvexHullTrick.Line queryLine = new ConvexHullTrick.Line(0, 0);

        public boolean isEmpty() {
            return setOrderByA.isEmpty();
        }

        public double query(double x) {
            queryLine.lx = x;
            ConvexHullTrick.Line line = setOrderByLx.floor(queryLine);
            return line.y(x);
        }

        public ConvexHullTrick.Line insert(double a, double b) {
            ConvexHullTrick.Line newLine = new ConvexHullTrick.Line(a, b);
            boolean add = true;
            while (add) {
                ConvexHullTrick.Line prev = setOrderByA.floor(newLine);
                if (prev == null) {
                    newLine.lx = -INF;
                    break;
                }
                if (prev.a == newLine.a) {
                    if (prev.b >= newLine.b) {
                        add = false;
                        break;
                    } else {
                        setOrderByA.remove(prev);
                        setOrderByLx.remove(prev);
                    }
                } else {
                    double lx = ConvexHullTrick.Line.intersectAt(prev, newLine);
                    if (lx <= prev.lx) {
                        setOrderByA.remove(prev);
                        setOrderByLx.remove(prev);
                    } else if (lx > prev.rx) {
                        add = false;
                        break;
                    } else {
                        prev.rx = lx;
                        newLine.lx = lx;
                        break;
                    }
                }
            }

            while (add) {
                ConvexHullTrick.Line next = setOrderByA.ceiling(newLine);
                if (next == null) {
                    newLine.rx = INF;
                    break;
                }
                double rx = ConvexHullTrick.Line.intersectAt(newLine, next);
                if (rx >= next.rx) {
                    setOrderByA.remove(next);
                    setOrderByLx.remove(next);
                } else if (rx < next.lx || (newLine.lx >= rx)) {
                    ConvexHullTrick.Line lastLine = setOrderByA.floor(newLine);
                    if (lastLine != null) {
                        lastLine.rx = next.lx;
                    }
                    add = false;
                    break;
                } else {
                    next.lx = rx;
                    newLine.rx = rx;
                    break;
                }
            }

            if (add) {
                setOrderByA.add(newLine);
                setOrderByLx.add(newLine);
            }

            return newLine;
        }

        public Iterator<ConvexHullTrick.Line> iterator() {
            return setOrderByA.iterator();
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (ConvexHullTrick.Line line : this) {
                builder.append(line).append('\n');
            }
            return builder.toString();
        }

        public static class Line {
            double a;
            double b;
            double lx;
            double rx;
            static Comparator<ConvexHullTrick.Line> orderByA = new Comparator<ConvexHullTrick.Line>() {

                public int compare(ConvexHullTrick.Line o1, ConvexHullTrick.Line o2) {
                    return Double.compare(o1.a, o2.a);
                }
            };
            static Comparator<ConvexHullTrick.Line> orderByLx = new Comparator<ConvexHullTrick.Line>() {

                public int compare(ConvexHullTrick.Line o1, ConvexHullTrick.Line o2) {
                    return Double.compare(o1.lx, o2.lx);
                }
            };

            public Line(double a, double b) {
                this.a = a;
                this.b = b;
            }

            public double y(double x) {
                return a * x + b;
            }

            public static double intersectAt(ConvexHullTrick.Line a, ConvexHullTrick.Line b) {
                return (b.b - a.b) / (a.a - b.a);
            }

            public int hashCode() {
                return (int) (Double.doubleToLongBits(a) * 31 + Double.doubleToLongBits(b));
            }

            public boolean equals(Object obj) {
                ConvexHullTrick.Line line = (ConvexHullTrick.Line) obj;
                return a == line.a && b == line.b;
            }

            public String toString() {
                return a + "x+" + b;
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

    static interface IntIterator {
        boolean hasNext();

        int next();

    }

    static class MultiWayIntDeque {
        private int[] values;
        private int[] next;
        private int[] prev;
        private int[] heads;
        private int[] tails;
        private int alloc;
        private int queueNum;

        public IntIterator iterator(final int queue) {
            return new IntIterator() {
                int ele = heads[queue];


                public boolean hasNext() {
                    return ele != 0;
                }


                public int next() {
                    int ans = values[ele];
                    ele = next[ele];
                    return ans;
                }
            };
        }

        private void doubleCapacity() {
            int newSize = Math.max(next.length + 10, next.length * 2);
            next = Arrays.copyOf(next, newSize);
            prev = Arrays.copyOf(prev, newSize);
            values = Arrays.copyOf(values, newSize);
        }

        public void alloc() {
            alloc++;
            if (alloc >= next.length) {
                doubleCapacity();
            }
            next[alloc] = 0;
        }

        public MultiWayIntDeque(int qNum, int totalCapacity) {
            values = new int[totalCapacity + 1];
            next = new int[totalCapacity + 1];
            prev = new int[totalCapacity + 1];
            heads = new int[qNum];
            tails = new int[qNum];
            queueNum = qNum;
        }

        public void addFirst(int qId, int x) {
            alloc();
            values[alloc] = x;

            if (heads[qId] == 0) {
                heads[qId] = tails[qId] = alloc;
                return;
            }
            next[alloc] = heads[qId];
            prev[heads[qId]] = alloc;
            heads[qId] = alloc;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < queueNum; i++) {
                builder.append(i).append(": ");
                for (IntIterator iterator = iterator(i); iterator.hasNext(); ) {
                    builder.append(iterator.next()).append(",");
                }
                if (builder.charAt(builder.length() - 1) == ',') {
                    builder.setLength(builder.length() - 1);
                }
                builder.append('\n');
            }
            return builder.toString();
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
}