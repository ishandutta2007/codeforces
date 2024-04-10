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
            G2PlaylistForPolycarpHardVersion solver = new G2PlaylistForPolycarpHardVersion();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class G2PlaylistForPolycarpHardVersion {
        Modular mod = new Modular(1e9 + 7);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            int[][] musics = new int[n][2];
            int[] cnts = new int[4];
            for (int i = 0; i < n; i++) {
                musics[i][0] = in.readInt();
                musics[i][1] = in.readInt();
                cnts[musics[i][1]]++;
            }

            int c1 = cnts[1];
            int c2 = cnts[2];
            int c3 = cnts[3];

            int[][][][] comp = new int[c1 + 1][c2 + 1][c3 + 1][4];
            for (int i = 0; i <= c1; i++) {
                for (int j = 0; j <= c2; j++) {
                    for (int k = 0; k <= c3; k++) {
                        for (int t = 0; t < 4; t++) {
                            if (i == 0 && j == 0 && k == 0) {
                                comp[i][j][k][t] = 1;
                                continue;
                            }
                            if (i > 0 && t != 1) {
                                comp[i][j][k][t] = mod.plus(comp[i][j][k][t], mod.mul(comp[i - 1][j][k][1], i));
                            }
                            if (j > 0 && t != 2) {
                                comp[i][j][k][t] = mod.plus(comp[i][j][k][t], mod.mul(comp[i][j - 1][k][2], j));
                            }
                            if (k > 0 && t != 3) {
                                comp[i][j][k][t] = mod.plus(comp[i][j][k][t], mod.mul(comp[i][j][k - 1][3], k));
                            }
                        }
                    }
                }
            }

            int[][][][] last = new int[c1 + 1][c2 + 1][c3 + 1][m + 1];
            int[][][][] next = new int[c1 + 1][c2 + 1][c3 + 1][m + 1];

            last[0][0][0][0] = 1;
            int t1 = 0;
            int t2 = 0;
            int t3 = 0;
            for (int[] music : musics) {
                int m1 = music[1];
                int m0 = music[0];
                if (m1 == 1) {
                    t1++;
                } else if (m1 == 2) {
                    t2++;
                } else {
                    t3++;
                }
                for (int i = 0; i <= t1; i++) {
                    for (int j = 0; j <= t2; j++) {
                        for (int k = 0; k <= t3; k++) {
                            for (int t = 0; t <= m; t++) {
                                next[i][j][k][t] = last[i][j][k][t];
                                if (t < m0) {
                                    continue;
                                }
                                if (m1 == 1 && i > 0) {
                                    next[i][j][k][t] = mod.plus(next[i][j][k][t], last[i - 1][j][k][t - m0]);
                                } else if (m1 == 2 && j > 0) {
                                    next[i][j][k][t] = mod.plus(next[i][j][k][t], last[i][j - 1][k][t - m0]);
                                } else if (m1 == 3 && k > 0) {
                                    next[i][j][k][t] = mod.plus(next[i][j][k][t], last[i][j][k - 1][t - m0]);
                                }
                            }
                        }
                    }
                }

                int[][][][] tmp = last;
                last = next;
                next = tmp;
            }

            int ans = 0;
            for (int i = 0; i <= c1; i++) {
                for (int j = 0; j <= c2; j++) {
                    for (int k = 0; k <= c3; k++) {
                        ans = mod.plus(ans, mod.mul(last[i][j][k][m], comp[i][j][k][0]));
                    }
                }
            }

            out.println(ans);
        }

    }

    static class Modular {
        int m;

        public Modular(int m) {
            this.m = m;
        }

        public Modular(long m) {
            this.m = (int) m;
            if (this.m != m) {
                throw new IllegalArgumentException();
            }
        }

        public Modular(double m) {
            this.m = (int) m;
            if (this.m != m) {
                throw new IllegalArgumentException();
            }
        }

        public int valueOf(int x) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            return x;
        }

        public int valueOf(long x) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            return (int) x;
        }

        public int mul(int x, int y) {
            return valueOf((long) x * y);
        }

        public int plus(int x, int y) {
            return valueOf(x + y);
        }

        public String toString() {
            return "mod " + m;
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