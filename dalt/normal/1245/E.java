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
 * Built using CHelper plug-in Actual solution is at the top
 * 
 * @author daltao
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "daltao", 1 << 27);
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
            TaskE solver = new TaskE();
            solver.solve(1, in, out);
            out.close();
        }
    }
    static class TaskE {
        int[][] boards = new int[10][10];
        double[][][] exp = new double[10][10][2];

        public void solve(int testNumber, FastInput in, FastOutput out) {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    boards[i][j] = in.readInt();
                }
            }

            SequenceUtils.deepFill(exp, -1D);
            exp[0][0][0] = 0;
            double ans = exp(9, 0, 0);
            out.printf("%.10f", ans);
        }

        public double exp(int i, int j, int t) {
            if (exp[i][j][t] < 0) {
                exp[i][j][t] = 0;
                if (t == 1 && boards[i][j] == 0) {
                    return exp[i][j][t] = 1e50;
                }

                if (t == 0) {
                    double wayExp = 0;
                    double stayProb = 0;
                    for (int k = 1; k <= 6; k++) {
                        int dir = i % 2 == 1 ? 1 : -1;
                        int nj = j + dir * k;
                        int ni = i;
                        if (nj < 0 || nj >= 10) {
                            if (i == 0) {
                                stayProb += 1.0D / 6;
                                continue;
                            } else {
                                ni--;
                                if (nj < 0) {
                                    nj = -nj - 1;
                                } else {
                                    nj = 9 - (nj - 10);
                                }
                            }
                        }
                        wayExp += (Math.min(exp(ni, nj, 0), exp(ni, nj, 1)) + 1) / 6;
                    }

                    exp[i][j][t] = (wayExp + stayProb) / (1 - stayProb);
                } else {
                    exp[i][j][t] = exp(i - boards[i][j], j, 0);
                }
            }

            return exp[i][j][t];
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

        public FastOutput printf(String format, Object... args) {
            cache.append(String.format(format, args));
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