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
            ATesla solver = new ATesla();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class ATesla {
        int n;
        int[][] mat;
        int k;
        List<int[]> ans = new ArrayList<>();

        public void solve(int testNumber, FastInput in, FastOutput out) {
            n = in.readInt();
            k = in.readInt();
            mat = new int[5][1 + n];
            for (int i = 1; i <= 4; i++) {
                for (int j = 1; j <= n; j++) {
                    mat[i][j] = in.readInt();
                }
            }

            while (k > 0) {
                tryMatch();
                if (!tryLoop()) {
                    if (k > 0) {
                        out.println(-1);
                        return;
                    }
                }
            }

            out.println(ans.size());
            for (int[] x : ans) {
                out.append(x[0]).append(' ')
                        .append(x[1]).append(' ')
                        .append(x[2]).println();
            }
        }

        public int[] next(int[] xy) {
            int[] ans = xy.clone();
            if (ans[0] == 3) {
                ans[1]--;
                if (ans[1] <= 0) {
                    ans[1]++;
                    ans[0]--;
                }
            } else {
                ans[1]++;
                if (ans[1] > n) {
                    ans[1]--;
                    ans[0]++;
                }
            }
            return ans;
        }

        public void move(int x1, int y1, int x2, int y2) {
            ans.add(new int[]{mat[x1][y1], x2, y2});
            mat[x2][y2] = mat[x1][y1];
            mat[x1][y1] = 0;
        }

        public boolean tryLoop() {
            int x = -1;
            int y = -1;
            for (int i = 2; i <= 3; i++) {
                for (int j = 1; j <= n; j++) {
                    if (mat[i][j] == 0) {
                        x = i;
                        y = j;
                        break;
                    }
                }
            }
            if (x == -1) {
                return false;
            }
            int[] now = new int[]{x, y};
            while (true) {
                int[] next = next(now);
                if (next[0] == x && next[1] == y) {
                    break;
                }
                if (mat[next[0]][next[1]] != 0) {
                    move(next[0], next[1], now[0], now[1]);
                }
                now = next;
            }

            return true;
        }

        public void tryMatch() {
            for (int i = 1; i <= n; i++) {
                if (mat[1][i] == mat[2][i] && mat[2][i] != 0) {
                    move(2, i, 1, i);
                    k--;
                }
                if (mat[3][i] == mat[4][i] && mat[4][i] != 0) {
                    move(3, i, 4, i);
                    k--;
                }
            }
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
}