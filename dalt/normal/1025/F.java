import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.io.UncheckedIOException;
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
            FDisjointTriangles solver = new FDisjointTriangles();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FDisjointTriangles {
        int n;
        Point[] relativePoints;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            n = in.readInt();
            Point[] points = new Point[n];
            relativePoints = new Point[n];
            for (int i = 0; i < n; i++) {
                points[i] = new Point(in.readInt(), in.readInt());
                relativePoints[i] = new Point();
            }

            long ans = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    relativePoints[j].x = points[j].x - points[i].x;
                    relativePoints[j].y = points[j].y - points[i].y;
                    relativePoints[j].atan2 = GeometryUtils.theta(relativePoints[j].y, relativePoints[j].x);
                }
                SequenceUtils.swap(relativePoints, i, n - 1);
                ans += count(points[i]);
            }

            System.err.println(ans);
            out.println(ans / 4);
        }

        public long cross(Point a, Point b) {
            return cross(a.x, a.y, b.x, b.y);
        }

        public long cross(long x1, long y1, long x2, long y2) {
            return x1 * y2 - x2 * y1;
        }

        public long pick(int n, int m) {
            if (n < m) {
                return 0;
            }
            return m == 0 ? 1 : (n * pick(n - 1, m - 1) / m);
        }

        public long count(Point center) {
            Arrays.sort(relativePoints, 0, n - 1, (a, b) -> Double.compare(a.atan2, b.atan2));

            long total = 0;
            int iter = 1;
            for (int i = 0; i < n - 1; i++) {
                while (!(cross(relativePoints[i], relativePoints[DigitUtils.mod(iter - 1, n - 1)]) >= 0 &&
                        cross(relativePoints[i], relativePoints[iter]) <= 0)) {
                    iter = DigitUtils.mod(iter + 1, n - 1);
                }
                int leftCnt = DigitUtils.mod(iter - 1 - i, n - 1);
                int rightCnt = n - 1 - 1 - leftCnt;
                long contrib = pick(leftCnt, 2) * pick(rightCnt, 2) * 2;
                total += contrib;

//            System.err.printf("(%d,%d)=>(%d,%d) = %d\n", center.x, center.y,
//                    relativePoints[i].x + center.x, relativePoints[i].y + center.y,
//                    contrib);
            }
            return total;
        }

    }

    static class Point {
        int x;
        int y;
        double atan2;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public Point() {
        }

    }

    static class GeometryUtils {
        public static double theta(double y, double x) {
            double theta = Math.atan2(y, x);
            if (theta < 0) {
                theta += Math.PI * 2;
            }
            return theta;
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

    static class SequenceUtils {
        public static <T> void swap(T[] data, int i, int j) {
            T tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int mod(int x, int mod) {
            x %= mod;
            if (x < 0) {
                x += mod;
            }
            return x;
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
}