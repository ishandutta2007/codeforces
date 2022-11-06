import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
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
            EColoredCubes solver = new EColoredCubes();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class EColoredCubes {
        Cube[][] mat;
        int n;
        List<int[]> operations = new ArrayList<>(100000);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            n = in.readInt();
            int m = in.readInt();
            mat = new Cube[n][n];
            int[][] init = new int[m][2];

            if (n == 1) {
                out.println(0);
                return;
            }

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < 2; j++) {
                    init[i][j] = in.readInt() - 1;
                }
            }
            for (int i = 0; i < m; i++) {
                Cube cube = new Cube();
                cube.tx = in.readInt() - 1;
                cube.ty = in.readInt() - 1;
                mat[init[i][0]][init[i][1]] = cube;
            }

            int half = n / 2;
            while (true) {
                int leftist = m;
                for (int i = 0; i < m; i++) {
                    if (mat[half][i] == null) {
                        leftist = i;
                        break;
                    }
                }
                if (leftist == m) {
                    break;
                }
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (mat[i][j] == null) {
                            continue;
                        }
                        if (i != half && j < leftist && mat[i][j + 1] == null) {
                            moveTo(i, j, i, j + 1);
                        } else if (i < half && mat[i + 1][j] == null) {
                            moveTo(i, j, i + 1, j);
                        } else if (i > half && mat[i - 1][j] == null) {
                            moveTo(i, j, i - 1, j);
                        } else if (i == half && j > 0 && mat[i][j - 1] == null) {
                            moveTo(i, j, i, j - 1);
                        }
                    }
                }
            }

            //insert sort
            for (int i = 0; i < m; i++) {
                int j = i;
                moveTo(half, j, half - 1, j);
                while (j - 1 >= 0 && mat[half][j - 1].ty > mat[half - 1][j].ty) {
                    moveTo(half - 1, j, half - 1, j - 1);
                    moveTo(half, j - 1, half, j);
                    j--;
                }
                moveTo(half - 1, j, half, j);
            }

            //to position
            for (int i = 0; i < m; i++) {
                int j = half;
                if (mat[j][i] == null) {
                    continue;
                }
                while (mat[j][i].tx < j) {
                    moveTo(j, i, j - 1, i);
                    j--;
                }
                while (mat[j][i].tx > j) {
                    moveTo(j, i, j + 1, i);
                    j++;
                }
            }

            for (int i = 0; i < n; i++) {
                //handle row
                Cube[] row = mat[i];
                while (true) {
                    boolean handled = false;
                    for (int j = 0; j < n; j++) {
                        if (row[j] == null) {
                            continue;
                        }
                        if (row[j].ty < j && row[j - 1] == null) {
                            handled = true;
                            moveTo(i, j, i, j - 1);
                        } else if (row[j].ty > j && row[j + 1] == null) {
                            handled = true;
                            moveTo(i, j, i, j + 1);
                        }
                    }
                    if (!handled) {
                        break;
                    }
                }
            }

            out.println(operations.size());
            for (int[] op : operations) {
                for (int i = 0; i < 4; i++) {
                    out.append(op[i] + 1).append(' ');
                }
                out.println();
            }
        }

        public void moveTo(int i, int j, int ni, int nj) {
            mat[ni][nj] = mat[i][j];
            mat[i][j] = null;
            operations.add(SequenceUtils.wrapArray(i, j,
                    ni, nj));
        }

    }

    static class Cube {
        int tx;
        int ty;

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

        public FastOutput append(int c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(int c) {
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
        public static int[] wrapArray(int... x) {
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