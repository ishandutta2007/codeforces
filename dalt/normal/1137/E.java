import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Iterator;
import java.util.HashMap;
import java.io.IOException;
import java.util.TreeSet;
import java.io.UncheckedIOException;
import java.util.Map;
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
            ETrainCarSelection solver = new ETrainCarSelection();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class ETrainCarSelection {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();

            LongConvexHullTrick cht = new LongConvexHullTrick();
            int l = 1;
            int r = n;
            Map<LongConvexHullTrick.Line, Integer> map = new HashMap<>(m + 1);
            map.put(cht.insert(0, 0), 1);
            long bSum = 0;
            long sSum = 0;
            for (int i = 0; i < m; i++) {
                int t = in.readInt();
                if (t == 1) {
                    int k = in.readInt();
                    cht.clear();
                    map.put(cht.insert(0, 0), l - k);
                    bSum = sSum = 0;
                    l -= k;
                } else if (t == 2) {
                    int k = in.readInt();
                    //size * sSum + b + bSum = 0
                    // b = -bSum - size * sSum
                    int size = r - l + 1;
                    map.put(cht.insert(-size, -(-bSum - size * sSum)), r + 1);
                    r += k;
                } else {
                    bSum += in.readInt();
                    sSum += in.readInt();
                }

                LongConvexHullTrick.Line line = cht.queryLine(sSum);
                long ans = -line.y(sSum) + bSum;
                out.append(map.get(line) - l + 1).append(' ').append(ans).println();
            }
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

        public FastOutput append(long c) {
            cache.append(c);
            return this;
        }

        public FastOutput println() {
            cache.append('\n');
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
                    setSortedByA.remove(floor);
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
}