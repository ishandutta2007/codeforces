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
            CMaximumSubrectangle solver = new CMaximumSubrectangle();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class CMaximumSubrectangle {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            long[] a = new long[n];
            long[] b = new long[m];
            for (int i = 0; i < n; i++) {
                a[i] = in.readInt();
            }
            for (int i = 0; i < m; i++) {
                b[i] = in.readInt();
            }
            long x = in.readInt();
            LongPreSum pa = new LongPreSum(a);
            LongPreSum pb = new LongPreSum(b);
            long[] minA = new long[n + 1];
            long[] minB = new long[m + 1];
            Arrays.fill(minA, (long) 1e10);
            Arrays.fill(minB, (long) 1e10);
            minA[0] = minB[0] = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    int len = j - i + 1;
                    minA[len] = Math.min(minA[len], pa.intervalSum(i, j));
                }
            }
            for (int i = 0; i < m; i++) {
                for (int j = i; j < m; j++) {
                    int len = j - i + 1;
                    minB[len] = Math.min(minB[len], pb.intervalSum(i, j));
                }
            }

            //System.err.println(Arrays.toString(minA));
            //System.err.println(Arrays.toString(minB));
            long area = 0;
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= m; j++) {
                    if (DigitUtils.isMultiplicationOverflow(minA[i], minB[j], x)) {
                        continue;
                    }
                    area = Math.max(area, i * j);
                }
            }
            out.println(area);
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

        public static boolean isMultiplicationOverflow(long a, long b, long limit) {
            if (limit < 0) {
                limit = -limit;
            }
            if (a < 0) {
                a = -a;
            }
            if (b < 0) {
                b = -b;
            }
            if (a == 0 || b == 0) {
                return false;
            }
            //a * b > limit => a > limit / b
            return a > limit / b;
        }

    }

    static class LongPreSum {
        private long[] pre;
        private int n;

        public LongPreSum(int n) {
            pre = new long[n];
        }

        public void populate(long[] a) {
            n = a.length;
            pre[0] = a[0];
            for (int i = 1; i < n; i++) {
                pre[i] = pre[i - 1] + a[i];
            }
        }

        public LongPreSum(long[] a) {
            this(a.length);
            populate(a);
        }

        public long intervalSum(int l, int r) {
            return prefix(r) - prefix(l - 1);
        }

        public long prefix(int i) {
            if (i < 0) {
                return 0;
            }
            return pre[Math.min(i, n - 1)];
        }

    }
}