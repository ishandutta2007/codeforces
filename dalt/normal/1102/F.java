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
            FElongatedMatrix solver = new FElongatedMatrix();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FElongatedMatrix {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            int[][] mat = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    mat[i][j] = in.readInt();
                }
            }

            int[][] minDist = new int[n][n];
            SequenceUtils.deepFill(minDist, (int) 1e9);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < m; k++) {
                        minDist[i][j] = Math.min(minDist[i][j], Math.abs(mat[i][k] - mat[j][k]));
                    }
                }
            }
            int[][] minDistBetweenHeadAndTail = new int[n][n];
            SequenceUtils.deepFill(minDistBetweenHeadAndTail, (int) 1e9);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 1; k < m; k++) {
                        minDistBetweenHeadAndTail[i][j] = Math.min(minDistBetweenHeadAndTail[i][j], Math.abs(mat[i][k] - mat[j][k - 1]));
                    }
                }
            }

            Log2 log2 = new Log2();
            BitOperator bo = new BitOperator();
            int[][][] dp = new int[1 << n][n][n];
            for (int i = 1; i < (1 << n); i++) {
                if (i == Integer.lowestOneBit(i)) {
                    dp[i][log2.floorLog(i)][log2.floorLog(i)] = (int) 1e9;
                    continue;
                }
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        if (bo.bitAt(i, j) == 0) {
                            continue;
                        }
                        for (int t = 0; t < n; t++) {
                            dp[i][j][k] = Math.max(dp[i][j][k],
                                    Math.min(dp[bo.setBit(i, j, false)][t][k],
                                            minDist[j][t]));
                        }
                    }
                }
            }

            int ans = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    ans = Math.max(ans, Math.min(dp[(1 << n) - 1][i][j], minDistBetweenHeadAndTail[j][i]));
                }
            }
            out.println(ans);
        }

    }

    static class SequenceUtils {
        public static void deepFill(Object array, int val) {
            if (!array.getClass().isArray()) {
                throw new IllegalArgumentException();
            }
            if (array instanceof int[]) {
                int[] intArray = (int[]) array;
                Arrays.fill(intArray, val);
            } else {
                Object[] objArray = (Object[]) array;
                for (Object obj : objArray) {
                    deepFill(obj, val);
                }
            }
        }

    }

    static class Log2 {
        public int floorLog(int x) {
            return 31 - Integer.numberOfLeadingZeros(x);
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

    static class BitOperator {
        public int bitAt(int x, int i) {
            return (x >> i) & 1;
        }

        public int setBit(int x, int i, boolean v) {
            if (v) {
                x |= 1 << i;
            } else {
                x &= ~(1 << i);
            }
            return x;
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