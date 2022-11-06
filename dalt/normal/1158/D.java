

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.util.*;

public class CF1158D {
    public static void main(String[] args) throws Exception {
        boolean local = System.getProperty("ONLINE_JUDGE") == null;
        boolean async = false;

        Charset charset = Charset.forName("ascii");

        FastIO io = local ? new FastIO(new FileInputStream("D:\\DATABASE\\TESTCASE\\Code.in"), System.out, charset) : new FastIO(System.in, System.out, charset);
        Task task = new Task(io, new Debug(local));

        if (async) {
            Thread t = new Thread(null, task, "dalt", 1 << 27);
            t.setPriority(Thread.MAX_PRIORITY);
            t.start();
            t.join();
        } else {
            task.run();
        }

        if (local) {
            io.cache.append("\n\n--memory -- \n" + ((Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()) >> 20) + "M");
        }

        io.flush();
    }

    public static class Task implements Runnable {
        final FastIO io;
        final Debug debug;
        int inf = (int) 1e8;
        int mod = (int) 1e9 + 7;

        public int mod(int val) {
            val %= mod;
            if (val < 0) {
                val += mod;
            }
            return val;
        }

        public int mod(long val) {
            val %= mod;
            if (val < 0) {
                val += mod;
            }
            return (int) val;
        }

        int bitAt(int x, int i) {
            return (x >> i) & 1;
        }

        int bitAt(long x, int i) {
            return (int) ((x >> i) & 1);
        }

        public Task(FastIO io, Debug debug) {
            this.io = io;
            this.debug = debug;
        }

        @Override
        public void run() {
            solve();
        }

        public void solve() {
            int n = io.readInt();
            int[][] points = new int[n][4];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 2; j++) {
                    points[i][j] = io.readInt();
                }
                points[i][3] = i + 1;
            }

            int[] last = points[0];
            for (int[] pt : points) {
                if (pt[0] == last[0]) {
                    if (pt[1] < last[1]) {
                        last = pt;
                    }
                } else if (pt[0] > last[0]) {
                    last = pt;
                }
            }

            last[2] = 1;
            io.cache.append(last[3]).append(' ');
            for (int i = 0; i < n - 2; i++) {
                char c = io.readChar();
                Comparator<int[]> cmp;
                int[] finalLast = last;
                int[] choose = null;
                if (c == 'L') {
                    cmp = (a, b) -> {
                        return -Long.signum(Geometry.cross(a[0] - finalLast[0], a[1] - finalLast[1], b[0] - finalLast[0], b[1] - finalLast[1]));
                    };
                } else {
                    cmp = (a, b) -> {
                        return Long.signum(Geometry.cross(a[0] - finalLast[0], a[1] - finalLast[1], b[0] - finalLast[0], b[1] - finalLast[1]));
                    };
                }
                for (int[] pt : points) {
                    if (pt[2] == 1) {
                        continue;
                    }
                    if (choose == null || cmp.compare(pt, choose) < 0) {
                        choose = pt;
                    }
                }
                last = choose;
                last[2] = 1;
                io.cache.append(last[3]).append(' ');
            }

            for (int[] pt : points) {
                if (pt[2] == 1) {
                    continue;
                }
                io.cache.append(pt[3]).append(' ');
            }
        }
    }

    public static class Geometry {
        public static class Point2 {
            final double x, y;

            public Point2(double x, double y) {
                this.x = x;
                this.y = y;
            }

            public Point2 add(Point2 other) {
                return new Point2(x + other.x, y + other.y);
            }

            public Point2 sub(Point2 other) {
                return new Point2(x - other.x, y - other.y);
            }

            @Override
            public String toString() {
                return String.format("(%f,%f)", x, y);
            }
        }

        public static class Line2 {
            final Point2 begin, end;

            public Line2(Point2 begin, Point2 end) {
                this.begin = begin;
                this.end = end;
            }

            public Point2 getVector() {
                return end.sub(begin);
            }

            public Point2 getPointAt(double alpha) {
                return new Point2((1 - alpha) * begin.x + alpha * end.x, (1 - alpha) * begin.y + alpha * end.y);
            }

            @Override
            public String toString() {
                return String.format("%s->%s", begin.toString(), end.toString());
            }
        }

        public static int compare(double a, double b, double prec) {
            return Math.abs(a - b) < prec ? 0 : a < b ? -1 : 1;
        }

        /**
         * point2s
         */
        public static List<Point2> grahamScan(List<Point2> point2s, final double prec) {
            final Point2[] points = point2s.toArray(new Point2[0]);
            int n = points.length;

            Memory.swap(points, 0, Memory.min(points, 0, n, new Comparator<Point2>() {
                @Override
                public int compare(Point2 o1, Point2 o2) {
                    return o1.y != o2.y ? Double.compare(o1.y, o2.y) : Double.compare(o1.x, o2.x);
                }
            }));

            Comparator<Point2> cmp = new Comparator<Point2>() {
                @Override
                public int compare(Point2 o1, Point2 o2) {
                    return Geometry.compare(0, cross(o1.sub(points[0]), o2.sub(points[0])), prec);
                }
            };
            Arrays.sort(points, 1, n, cmp);

            int shrinkSize = 2;
            for (int i = 2; i < n; i++) {
                if (cmp.compare(points[i], points[shrinkSize - 1]) == 0) {
                    if (distance2(points[i].sub(points[0])) > distance2(points[shrinkSize - 1].sub(points[0]))) {
                        points[shrinkSize - 1] = points[i];
                    }
                } else {
                    points[shrinkSize++] = points[i];
                }
            }

            n = shrinkSize;
            Deque<Point2> stack = new ArrayDeque(n);
            stack.addLast(points[0]);
            for (int i = 1; i < n; i++) {
                while (stack.size() >= 2) {
                    Point2 last = stack.removeLast();
                    Point2 second = stack.peekLast();
                    if (cross(points[i].sub(second), last.sub(second)) < -prec) {
                        stack.addLast(last);
                        break;
                    }
                }
                stack.addLast(points[i]);
            }

            return new ArrayList(stack);
        }

        /**
         * Get (x1, y1)(x2, y2)
         */
        public static long cross(int x1, int y1, int x2, int y2) {
            return (long) x1 * y2 - (long) y1 * x2;
        }

        /**
         * Get (x1, y1)(x2, y2)
         */
        public static double cross(double x1, double y1, double x2, double y2) {
            return x1 * y2 - y1 * x2;
        }

        /**
         * Get (x1, y1)(x2, y2)
         */
        public static double cross(Point2 a, Point2 b) {
            return a.x * b.y - a.y * b.x;
        }

        /**
         * psection
         */
        public static boolean onSection(Point2 p, Line2 section, double precision) {
            return Math.abs(cross(p.sub(section.begin), section.getVector())) < precision
                    && p.x >= Math.min(section.begin.x, section.end.x) - precision && p.x <= Math.max(section.begin.x, section.end.x) + precision;
        }

        /**
         * p
         */
        public static double distance2(Point2 p) {
            return p.x * p.x + p.y * p.y;
        }

        /**
         * p
         */
        public static double distance(Point2 p) {
            return Math.sqrt(distance2(p));
        }

        /**
         * s1s2null
         */
        public static Point2 lineIntersection(Line2 s1, Line2 s2, double prec) {
            double m11 = s1.end.x - s1.begin.x;
            double m01 = s2.end.x - s2.begin.x;
            double m10 = s1.begin.y - s1.end.y;
            double m00 = s2.begin.y - s2.end.y;

            double div = m00 * m11 - m01 * m10;
            if (Math.abs(div) < prec) {
                return null;
            }

            double v0 = (s2.begin.x - s1.begin.x) / div;
            double v1 = (s2.begin.y - s1.begin.y) / div;

            double alpha = m00 * v0 + m01 * v1;

            return s1.getPointAt(alpha);
        }

        /**
         * s1s2null
         */
        public static Point2 sectionIntersection(Line2 s1, Line2 s2, double prec) {
            double m11 = s1.end.x - s1.begin.x;
            double m01 = s2.end.x - s2.begin.x;
            double m10 = s1.begin.y - s1.end.y;
            double m00 = s2.begin.y - s2.end.y;

            double div = m00 * m11 - m01 * m10;
            if (Math.abs(div) < prec) {
                return null;
            }

            double v0 = (s2.begin.x - s1.begin.x) / div;
            double v1 = (s2.begin.y - s1.begin.y) / div;

            double alpha = m00 * v0 + m01 * v1;
            double beta = m10 * v0 + m11 * v1;

            if (-prec <= alpha && alpha <= 1 + prec && -prec <= beta && beta <= 1 + prec) {
                return s1.getPointAt(alpha);
            }
            return null;
        }
    }

    public static class Memory {
        public static <T> void swap(T[] data, int i, int j) {
            T tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

        public static void swap(char[] data, int i, int j) {
            char tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

        public static void swap(int[] data, int i, int j) {
            int tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

        public static void swap(long[] data, int i, int j) {
            long tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

        public static <T> int min(T[] data, int from, int to, Comparator<T> cmp) {
            int m = from;
            for (int i = from + 1; i < to; i++) {
                if (cmp.compare(data[m], data[i]) > 0) {
                    m = i;
                }
            }
            return m;
        }

        public static <T> void move(T[] data, int from, int to, int step) {
            int len = to - from;
            step = len - (step % len + len) % len;
            Object[] buf = new Object[len];
            for (int i = 0; i < len; i++) {
                buf[i] = data[(i + step) % len + from];
            }
            System.arraycopy(buf, 0, data, from, len);
        }

        public static <T> void reverse(T[] data, int f, int t) {
            int l = f, r = t - 1;
            while (l < r) {
                swap(data, l, r);
                l++;
                r--;
            }
        }

        public static void reverse(int[] data, int f, int t) {
            int l = f, r = t - 1;
            while (l < r) {
                swap(data, l, r);
                l++;
                r--;
            }
        }

        public static void copy(Object[] src, Object[] dst, int srcf, int dstf, int len) {
            if (len < 8) {
                for (int i = 0; i < len; i++) {
                    dst[dstf + i] = src[srcf + i];
                }
            } else {
                System.arraycopy(src, srcf, dst, dstf, len);
            }
        }

        public static void fill(int[][] x, int val) {
            for (int[] v : x) {
                Arrays.fill(v, val);
            }
        }

        public static void fill(int[][][] x, int val) {
            for (int[][] v : x) {
                fill(v, val);
            }
        }
    }


    public static class FastIO {
        public final StringBuilder cache = new StringBuilder();
        private final InputStream is;
        private final OutputStream os;
        private final Charset charset;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 8);
        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;

        public FastIO(InputStream is, OutputStream os, Charset charset) {
            this.is = is;
            this.os = os;
            this.charset = charset;
        }

        public FastIO(InputStream is, OutputStream os) {
            this(is, os, Charset.forName("ascii"));
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

        public long readLong() {
            int sign = 1;

            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+' ? 1 : -1;
                next = read();
            }

            long val = 0;
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

        public double readDouble() {
            boolean sign = true;
            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+';
                next = read();
            }

            long val = 0;
            while (next >= '0' && next <= '9') {
                val = val * 10 + next - '0';
                next = read();
            }
            if (next != '.') {
                return sign ? val : -val;
            }
            next = read();
            long radix = 1;
            long point = 0;
            while (next >= '0' && next <= '9') {
                point = point * 10 + next - '0';
                radix = radix * 10;
                next = read();
            }
            double result = val + (double) point / radix;
            return sign ? result : -result;
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

        public int readLine(char[] data, int offset) {
            int originalOffset = offset;
            while (next != -1 && next != '\n') {
                data[offset++] = (char) next;
                next = read();
            }
            return offset - originalOffset;
        }

        public int readString(char[] data, int offset) {
            skipBlank();

            int originalOffset = offset;
            while (next > 32) {
                data[offset++] = (char) next;
                next = read();
            }

            return offset - originalOffset;
        }

        public int readString(byte[] data, int offset) {
            skipBlank();

            int originalOffset = offset;
            while (next > 32) {
                data[offset++] = (byte) next;
                next = read();
            }

            return offset - originalOffset;
        }

        public char readChar() {
            skipBlank();
            char c = (char) next;
            next = read();
            return c;
        }

        public void flush() {
            try {
                os.write(cache.toString().getBytes(charset));
                os.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        public boolean hasMore() {
            skipBlank();
            return next != -1;
        }
    }

    public static class Debug {
        private boolean allowDebug;

        public Debug(boolean allowDebug) {
            this.allowDebug = allowDebug;
        }

        public void assertTrue(boolean flag) {
            if (!allowDebug) {
                return;
            }
            if (!flag) {
                fail();
            }
        }

        public void fail() {
            throw new RuntimeException();
        }

        public void assertFalse(boolean flag) {
            if (!allowDebug) {
                return;
            }
            if (flag) {
                fail();
            }
        }

        private void outputName(String name) {
            System.out.print(name + " = ");
        }

        public void debug(String name, int x) {
            if (!allowDebug) {
                return;
            }

            outputName(name);
            System.out.println("" + x);
        }

        public void debug(String name, long x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println("" + x);
        }

        public void debug(String name, double x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println("" + x);
        }

        public void debug(String name, int[] x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.toString(x));
        }

        public void debug(String name, long[] x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.toString(x));
        }

        public void debug(String name, double[] x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.toString(x));
        }

        public void debug(String name, Object x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println("" + x);
        }

        public void debug(String name, Object... x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.deepToString(x));
        }
    }
}