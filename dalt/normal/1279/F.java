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
            FNewYearAndHandleChange solver = new FNewYearAndHandleChange();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FNewYearAndHandleChange {
        int n;
        int k;
        int l;
        int[] s;
        IntegerPreSum ps;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            n = in.readInt();
            k = in.readInt();
            l = in.readInt();

            s = new int[n];
            for (int i = 0; i < n; i++) {
                if (Character.isUpperCase(in.readChar())) {
                    s[i] = 1;
                } else {
                    s[i] = 0;
                }
            }

            int lower = solve();
            for (int i = 0; i < n; i++) {
                s[i] = 1 - s[i];
            }
            int upper = solve();
            out.println(Math.min(lower, upper));
        }

        public int solve() {
            ps = new IntegerPreSum(s);

            DoubleBinarySearch dbs = new DoubleBinarySearch(1e-8, 1e-8) {

                public boolean check(double mid) {
                    Recorder recorder = dp(mid);
                    return recorder.time <= k;
                }
            };

            double cost = dbs.binarySearch(0, l);
            double ans = dp(cost).ans - k * cost;
            return DigitUtils.roundToInt(ans);
        }

        public Recorder dp(double cost) {
            double[] dp = new double[n];
            int[] time = new int[n];
            for (int i = 0; i < n; i++) {
                if (i < l) {
                    if (ps.prefix(i) <= cost) {
                        dp[i] = ps.prefix(i);
                    } else {
                        dp[i] = cost;
                        time[i] = 1;
                    }
                } else {
                    if (dp[i - 1] + s[i] < dp[i - l] + cost) {
                        dp[i] = dp[i - 1] + s[i];
                        time[i] = time[i - 1];
                    } else {
                        dp[i] = dp[i - l] + cost;
                        time[i] = time[i - l] + 1;
                    }
                }
            }
            Recorder recorder = new Recorder();
            recorder.ans = dp[n - 1];
            recorder.time = time[n - 1];
            return recorder;
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int roundToInt(double x) {
            return (int) round(x);
        }

        public static long round(double x) {
            if (x >= 0) {
                return (long) (x + 0.5);
            } else {
                return (long) (x - 0.5);
            }
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

        public FastOutput println(int c) {
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

    static class IntegerPreSum {
        private int[] pre;

        public IntegerPreSum(int n) {
            pre = new int[n];
        }

        public void populate(int[] a) {
            int n = a.length;
            pre[0] = a[0];
            for (int i = 1; i < n; i++) {
                pre[i] = pre[i - 1] + a[i];
            }
        }

        public IntegerPreSum(int[] a) {
            this(a.length);
            populate(a);
        }

        public int prefix(int i) {
            if (i < 0) {
                return 0;
            }
            return pre[i];
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

        public char readChar() {
            skipBlank();
            char c = (char) next;
            next = read();
            return c;
        }

    }

    static class Recorder {
        int time;
        double ans;

    }

    static abstract class DoubleBinarySearch {
        private final double relativeErrorTolerance;
        private final double absoluteErrorTolerance;

        public DoubleBinarySearch(double relativeErrorTolerance, double absoluteErrorTolerance) {
            this.relativeErrorTolerance = relativeErrorTolerance;
            this.absoluteErrorTolerance = absoluteErrorTolerance;
        }

        public abstract boolean check(double mid);

        public double binarySearch(double l, double r) {
            if (l > r) {
                throw new IllegalArgumentException();
            }
            while (r - l > absoluteErrorTolerance) {
                if ((r < 0 && (r - l) < -r * relativeErrorTolerance) || (l > 0 && (r - l) < l * relativeErrorTolerance)) {
                    break;
                }

                double mid = (l + r) / 2;
                if (check(mid)) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            return (l + r) / 2;
        }

    }
}