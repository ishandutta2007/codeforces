import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
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
            DCandiesForChildren solver = new DCandiesForChildren();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DCandiesForChildren {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            long n = in.readLong();
            long l = in.readLong();
            long r = in.readLong();
            long k = in.readLong();
            long dist = DigitUtils.mod(r - l, n) + 1;

            long max = -1;
            int threshold = 1000000;

            LinearIntegerRange range = new LinearIntegerRange();
            if (n < threshold) {
                for (int i = 0; i <= n; i++) {
                    range.reset(0, k);
                    range.between(-(i + n), k - dist, 0, Math.min(i, dist));
                    range.between(i + n, i - (k - dist), 0, n - dist);
                    if (range.valid()) {
                        max = Math.max(max, i);
                    }
                }
            } else {
                if (dist <= k && k <= dist * 2) {
                    max = Math.max(max, k - dist + n - dist);
                }
                for (int i = 1; i * n <= k; i++) {
                    long remain = k - i * n - dist;
                    if (remain < 0) {
                        continue;
                    }
                    range.reset(0, n);

                    range.lessThanOrEqual(i, remain);
                    range.greaterThanOrEqual(i + 1, remain);
                    range.greaterThanOrEqual(-i, remain, 0);
                    range.lessThanOrEqual(-i, remain, dist);
                    range.greaterThanOrEqual(i + 1, -remain, 0);
                    range.lessThanOrEqual(i + 1, -remain, n - dist);


                    if (range.valid()) {
                        max = Math.max(range.getR(), max);
                    }
                }
            }

            //take one last time
            k++;
            if (n < threshold) {
                for (int i = 1; i <= n; i++) {
                    range.reset(0, k);
                    range.between(-(i + n), k - dist, 1, Math.min(i, dist));
                    range.between(i + n, i - (k - dist), 0, n - dist);
                    if (range.valid()) {
                        max = Math.max(max, i);
                    }
                }
            } else {
                if (dist + 1 <= k && k <= dist * 2) {
                    max = Math.max(max, k - dist + n - dist);
                }
                for (int i = 1; i * n <= k; i++) {
                    long remain = k - i * n - dist;
                    if (remain < 0) {
                        continue;
                    }
                    range.reset(0, n);

                    range.lessThanOrEqual(i, remain);
                    range.greaterThanOrEqual(i + 1, remain);
                    range.greaterThanOrEqual(-i, remain, 1);
                    range.lessThanOrEqual(-i, remain, dist);
                    range.greaterThanOrEqual(i + 1, -remain, 0);
                    range.lessThanOrEqual(i + 1, -remain, n - dist);

                    if (range.valid()) {
                        max = Math.max(range.getR(), max);
                    }
                }
            }

            out.println(max);
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

    static class LinearIntegerRange {
        private long l;
        private long r;

        public LinearIntegerRange(long l, long r) {
            this.l = l;
            this.r = r;
        }

        public LinearIntegerRange() {
            this(Long.MIN_VALUE, Long.MAX_VALUE);
        }

        public boolean valid() {
            return r >= l;
        }

        public long getR() {
            return r;
        }

        public void reset(long l, long r) {
            this.l = l;
            this.r = r;
        }

        public void greaterThanOrEqual(long k, long y) {
            if (k < 0) {
                lessThanOrEqual(-k, -y);
                return;
            }
            l = Math.max(l, DigitUtils.ceilDiv(y, k));
        }

        public void greaterThanOrEqual(long k, long b, long y) {
            greaterThanOrEqual(k, y - b);
        }

        public void lessThanOrEqual(long k, long y) {
            if (k < 0) {
                greaterThanOrEqual(-k, -y);
                return;
            }
            r = Math.min(r, DigitUtils.floorDiv(y, k));
        }

        public void between(long k, long b, long l, long r) {
            greaterThanOrEqual(k, b, l);
            lessThanOrEqual(k, b, r);
        }

        public void lessThanOrEqual(long k, long b, long y) {
            lessThanOrEqual(k, y - b);
        }

        public String toString() {
            return "[" + l + "," + r + "]";
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

        public static long mod(long x, long mod) {
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

    }
}