import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.function.DoubleUnaryOperator;
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
            FWriteTheContest solver = new FWriteTheContest();
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                solver.solve(i, in, out);
            out.close();
        }
    }

    static class FWriteTheContest {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            double c = in.readDouble();
            double t = in.readDouble();
            double s = 1;

            double[] bests = new double[n + 1];
            for (int i = 0; i <= n; i++) {
                if (i * 10 >= t) {
                    continue;
                }
                double punish = 10 * i;
                DoubleUnaryOperator func = x -> (s + c * x) * (t - x - punish);
                DoubleTernarySearch dts = new DoubleTernarySearch(func, 1e-12, 1e-6);
                double best = func.applyAsDouble(dts.find(0, t));
                bests[i] = best;
            }
            int[][] problems = new int[n][2];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 2; j++) {
                    problems[i][j] = in.readInt();
                }
            }

            double[] pow = new double[n + 1];
            pow[0] = 1;
            for (int i = 1; i <= n; i++) {
                pow[i] = pow[i - 1] * 0.9D;
            }
            Arrays.sort(problems, (a, b) -> -(a[0] - b[0]));
            int limit = 10 * n;
            double[][] dp = new double[n + 1][limit + 1];
            SequenceUtils.deepFill(dp, 1e18);
            dp[0][0] = 0;
            for (int i = 0; i < n; i++) {
                int a = problems[i][0];
                int p = problems[i][1];
                for (int j = n; j >= 0; j--) {
                    for (int k = 0; k <= limit; k++) {
                        if (j >= 1 && k >= p) {
                            dp[j][k] = Math.min(dp[j][k], dp[j - 1][k - p] + a / pow[j]);
                        }
                    }
                }
            }

            for (int i = limit; i >= 0; i--) {
                for (int j = 0; j <= n; j++) {
                    if (dp[j][i] <= bests[j]) {
                        out.println(i);
                        return;
                    }
                }
            }
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

    }

    static class DoubleTernarySearch {
        private DoubleUnaryOperator operator;
        private double relative;
        private double absolute;

        public DoubleTernarySearch(DoubleUnaryOperator operator, double relative, double absolute) {
            this.operator = operator;
            this.relative = relative;
            this.absolute = absolute;
        }

        public double find(double l, double r) {
            while (r - l > absolute) {
                if (r < 0 && (r - l) / -r <= relative ||
                        l > 0 && (r - l) / l <= relative) {
                    break;
                }
                double dist = (r - l) / 3;
                double ml = l + dist;
                double mr = r - dist;
                if (operator.applyAsDouble(ml) < operator.applyAsDouble(mr)) {
                    l = ml;
                } else {
                    r = mr;
                }
            }
            return (l + r) / 2;
        }

    }

    static class SequenceUtils {
        public static void deepFill(Object array, double val) {
            if (!array.getClass().isArray()) {
                throw new IllegalArgumentException();
            }
            if (array instanceof double[]) {
                double[] doubleArray = (double[]) array;
                Arrays.fill(doubleArray, val);
            } else {
                Object[] objArray = (Object[]) array;
                for (Object obj : objArray) {
                    deepFill(obj, val);
                }
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
}