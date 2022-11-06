import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
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
            ENewYearAndCastleConstruction solver = new ENewYearAndCastleConstruction();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class ENewYearAndCastleConstruction {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            Point[] pts = new Point[n];
            for (int i = 0; i < n; i++) {
                pts[i] = new Point();
                pts[i].x = in.readInt();
                pts[i].y = in.readInt();
            }

            long ans = 0;
            Point[] sorted = new Point[n];
            for (int i = 0; i < n; i++) {
                sorted[i] = new Point();
            }
            for (int i = 0; i < n; i++) {
                Point center = pts[i];
                for (int j = 0; j < n; j++) {
                    sorted[j].x = pts[j].x - center.x;
                    sorted[j].y = pts[j].y - center.y;
                }
                SequenceUtils.swap(sorted, i, n - 1);
                ans += count(sorted, n - 1);
            }

            out.println(ans);
        }

        public long cross(long x1, long y1, long x2, long y2) {
            return x1 * y2 - x2 * y1;
        }

        public long cross(Point a, Point b) {
            return cross(a.x, a.y, b.x, b.y);
        }

        public long pick(long n, int i) {
            return i == 0 ? 1 : pick(n - 1, i - 1) * n / i;
        }

        public long count(Point[] pts, int n) {
            Arrays.sort(pts, 0, n, (a, b) -> {
                if (a.y >= 0 && b.y < 0) {
                    return -1;
                }
                if (a.y < 0 && b.y >= 0) {
                    return 1;
                }
                return cross(a, b) >= 0 ? -1 : 1;
            });

            long ans = 0;
            int cnt = 0;
            for (int i = 0, j = 0; i < n; i++) {
                if (cnt > 0) {
                    cnt--;
                }
                if (cnt == 0) {
                    j = i;
                }
                while (cross(pts[i], pts[(j + 1) % n]) > 0) {
                    j++;
                    cnt++;
                }
                ans += pick(cnt, 3);
            }


            return pick(n, 4) - ans;
        }

    }

    static class Point {
        long x;
        long y;

        public String toString() {
            return String.format("(%d, %d)", x, y);
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

    static class SequenceUtils {
        public static <T> void swap(T[] data, int i, int j) {
            T tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

    }
}