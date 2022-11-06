import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.Deque;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.Collection;
import java.io.IOException;
import java.lang.reflect.Field;
import java.nio.charset.StandardCharsets;
import java.io.UncheckedIOException;
import java.util.stream.Stream;
import java.io.Closeable;
import java.util.Comparator;
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
            FPointsMovement solver = new FPointsMovement();
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                solver.solve(i, in, out);
            out.close();
        }
    }

    static class FPointsMovement {
        Debug debug = new Debug(false);
        Point[] pts;
        int ptIter = 0;
        long inf = (long) 1e15;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int m = in.ri();
            pts = new Point[n + 2];
            Line[] lines = new Line[m];
            for (int i = 0; i < n; i++) {
                pts[i] = new Point();
                pts[i].l = in.ri();
            }
            pts[n] = new Point();
            pts[n].l = -inf;
            pts[n + 1] = new Point();
            pts[n + 1].l = inf;

            for (int i = 0; i < m; i++) {
                lines[i] = new Line();
                lines[i].l = in.ri();
                lines[i].r = in.ri();
            }
            n += 2;
            Arrays.sort(pts, Comparator.comparingLong(x -> x.l));
            Arrays.sort(lines, Comparator.<Line>comparingLong(x -> x.l).thenComparingLong(x -> -x.r));
            Deque<Line> filterList = new ArrayDeque<>();
            for (Line line : lines) {
                while (!filterList.isEmpty() && filterList.peekLast().r >= line.r) {
                    Line removed = filterList.removeLast();
                    debug.debug("removed", removed);
                    continue;
                }
                filterList.addLast(line);
            }

            ptIter = 0;
            lines = filterList.stream().filter(line -> {
                while (ptIter < pts.length && pts[ptIter].l < line.l) {
                    ptIter++;
                }
                return ptIter == pts.length || pts[ptIter].l > line.r;
            }).toArray(i -> new Line[i]);
            m = lines.length;

            debug.debug("lines", lines);
            debug.debug("pts", pts);
            int lIter = 0;
            for (int i = 0; i < n - 1; i++) {
                Point cur = pts[i];
                Point next = pts[i + 1];
                int begin = lIter;
                while (lIter < m && lines[lIter].l < next.l) {
                    lIter++;
                }
                cur.follow = Arrays.copyOfRange(lines, begin, lIter);
            }

            long[][] ans = dac(0, n - 1);
            long best = inf;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    best = Math.min(best, ans[i][j]);
                }
            }
            out.println(best);
        }

        public long take(Line[] lines, Point lp, Point rp, int ltake, int rtake) {
            if (lines.length == 0) {
                return 0;
            }
            long best = Math.min((rp.l - lines[0].r) * rtake, (lines[lines.length - 1].l - lp.l) * ltake);
            for (int i = 0; i + 1 < lines.length; i++) {
                best = Math.min(best, (lines[i].l - lp.l) * ltake + (rp.l - lines[i + 1].r) * rtake);
            }
            return best;
        }

        public long[][] merge(long[][] a, long[][] b, Point lp, Point rp) {
            long[][] ans = new long[2][2];
            Line[] lines = lp.follow;
            SequenceUtils.deepFill(ans, inf);

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < 2; k++) {
                        for (int t = 0; t < 2; t++) {
                            long cost = a[i][j] + b[k][t] + take(lines, lp, rp, j + 1, k + 1);
                            ans[i][t] = Math.min(ans[i][t], cost);
                        }
                    }
                }
            }

            return ans;
        }

        public long[][] dac(int l, int r) {
            if (l == r) {
                long[][] ans = new long[2][2];
                ans[0][0] = ans[1][1] = inf;
                return ans;
            }
            int m = (l + r) / 2;
            long[][] L = dac(l, m);
            long[][] R = dac(m + 1, r);
            long[][] ans = merge(L, R, pts[m], pts[m + 1]);
            debug.debug("l", l);
            debug.debug("r", r);
            debug.debug("ans", ans);
            return ans;
        }

    }

    static class SequenceUtils {
        public static void deepFill(Object array, long val) {
            if (array == null) {
                return;
            }
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

    static class Point {
        long l;
        Line[] follow;

        public String toString() {
            return "Point{" +
                    "l=" + l +
                    '}';
        }

    }

    static class Line extends Point {
        long r;

        public String toString() {
            return "Line{" +
                    "r=" + r +
                    ", l=" + l +
                    '}';
        }

    }

    static class Debug {
        private boolean offline;
        private PrintStream out = System.err;
        static int[] empty = new int[0];

        public Debug(boolean enable) {
            offline = enable && System.getSecurityManager() == null;
        }

        public Debug debug(String name, int x) {
            if (offline) {
                debug(name, "" + x);
            }
            return this;
        }

        public Debug debug(String name, String x) {
            if (offline) {
                out.printf("%s=%s", name, x);
                out.println();
            }
            return this;
        }

        public Debug debug(String name, Object x) {
            return debug(name, x, empty);
        }

        public Debug debug(String name, Object x, int... indexes) {
            if (offline) {
                if (x == null || !x.getClass().isArray()) {
                    out.append(name);
                    for (int i : indexes) {
                        out.printf("[%d]", i);
                    }
                    out.append("=").append("" + x);
                    out.println();
                } else {
                    indexes = Arrays.copyOf(indexes, indexes.length + 1);
                    if (x instanceof byte[]) {
                        byte[] arr = (byte[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof short[]) {
                        short[] arr = (short[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof boolean[]) {
                        boolean[] arr = (boolean[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof char[]) {
                        char[] arr = (char[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof int[]) {
                        int[] arr = (int[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof float[]) {
                        float[] arr = (float[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof double[]) {
                        double[] arr = (double[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof long[]) {
                        long[] arr = (long[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else {
                        Object[] arr = (Object[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    }
                }
            }
            return this;
        }

    }

    static class FastInput {
        private final InputStream is;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 13);
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

        public String next() {
            return readString();
        }

        public int ri() {
            return readInt();
        }

        public int readInt() {
            boolean rev = false;

            skipBlank();
            if (next == '+' || next == '-') {
                rev = next == '-';
                next = read();
            }

            int val = 0;
            while (next >= '0' && next <= '9') {
                val = val * 10 - next + '0';
                next = read();
            }

            return rev ? val : -val;
        }

        public String readString(StringBuilder builder) {
            skipBlank();

            while (next > 32) {
                builder.append((char) next);
                next = read();
            }

            return builder.toString();
        }

        public String readString() {
            defaultStringBuf.setLength(0);
            return readString(defaultStringBuf);
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private static final int THRESHOLD = 32 << 10;
        private OutputStream writer;
        private StringBuilder cache = new StringBuilder(THRESHOLD * 2);
        private static Field stringBuilderValueField;
        private char[] charBuf = new char[THRESHOLD * 2];
        private byte[] byteBuf = new byte[THRESHOLD * 2];

        static {
            try {
                stringBuilderValueField = StringBuilder.class.getSuperclass().getDeclaredField("value");
                stringBuilderValueField.setAccessible(true);
            } catch (Exception e) {
                stringBuilderValueField = null;
            }
            stringBuilderValueField = null;
        }

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

        public FastOutput(OutputStream writer) {
            this.writer = writer;
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

        public FastOutput println(long c) {
            return append(c).println();
        }

        public FastOutput println() {
            return append('\n');
        }

        public FastOutput flush() {
            try {
                if (stringBuilderValueField != null) {
                    try {
                        byte[] value = (byte[]) stringBuilderValueField.get(cache);
                        writer.write(value, 0, cache.length());
                    } catch (Exception e) {
                        stringBuilderValueField = null;
                    }
                }
                if (stringBuilderValueField == null) {
                    int n = cache.length();
                    if (n > byteBuf.length) {
                        //slow
                        writer.write(cache.toString().getBytes(StandardCharsets.UTF_8));
//                writer.append(cache);
                    } else {
                        cache.getChars(0, n, charBuf, 0);
                        for (int i = 0; i < n; i++) {
                            byteBuf[i] = (byte) charBuf[i];
                        }
                        writer.write(byteBuf, 0, n);
                    }
                }
                writer.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
            return this;
        }

        public void close() {
            flush();
            try {
                writer.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

        public String toString() {
            return cache.toString();
        }

    }
}