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
            GInverseOfRowsAndColumns solver = new GInverseOfRowsAndColumns();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class GInverseOfRowsAndColumns {
        int n;
        int m;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            n = in.readInt();
            m = in.readInt();

            int[][] mat = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    mat[i][j] = in.readInt();
                }
            }

            int[] colMask = new int[m];
            int[] rowMask = new int[n];

            for (int k = 0; k <= 1; k++) {
                rowMask[0] = k;

                //all one
                Arrays.fill(colMask, 0);
                Arrays.fill(rowMask, 1, n, 0);
                for (int i = 0; i < m; i++) {
                    colMask[i] = 1 ^ mat[0][i] ^ rowMask[0];
                }
                if (flip(mat, rowMask, colMask, 1)) {
                    yes(out, rowMask, colMask);
                    return;
                }

                for (int i = 0; i < m; i++) {
                    Arrays.fill(colMask, 0);
                    Arrays.fill(rowMask, 1, n, 0);
                    for (int j = 0; j < m; j++) {
                        if (j > i) {
                            colMask[j] = 1 ^ mat[0][j] ^ rowMask[0];
                        } else {
                            colMask[j] = mat[0][j] ^ rowMask[0];
                        }
                    }
                    if (flip(mat, rowMask, colMask, 1)) {
                        yes(out, rowMask, colMask);
                        return;
                    }
                }
            }

            out.println("NO");
        }

        public void yes(FastOutput out, int[] rowMask, int[] colMask) {
            out.println("YES");
            for (int x : rowMask) {
                out.append(x);
            }
            out.println();
            for (int x : colMask) {
                out.append(x);
            }
            out.println();
        }

        public boolean check(int last, int rowMask, int[] colMask, int[] row) {
            for (int i = 0; i < m; i++) {
                if (last > (row[i] ^ rowMask ^ colMask[i])) {
                    return false;
                }
                last = (row[i] ^ rowMask ^ colMask[i]);
            }
            return true;
        }

        public boolean flip(int[][] mat, int[] rowMask, int[] colMask, int i) {
            if (i == mat.length) {
                return true;
            }

            int lastElement = mat[i - 1][m - 1] ^ rowMask[i - 1] ^ colMask[m - 1];

            rowMask[i] = lastElement ^ mat[i][0];
            if (!check(lastElement, rowMask[i], colMask, mat[i])) {
                rowMask[i] ^= 1;
                if (!check(lastElement, rowMask[i], colMask, mat[i])) {
                    return false;
                }
            }

            return flip(mat, rowMask, colMask, i + 1);
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

        public FastOutput append(int c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(String c) {
            cache.append(c).append('\n');
            return this;
        }

        public FastOutput println() {
            cache.append('\n');
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