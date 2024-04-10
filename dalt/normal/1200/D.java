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
            DWhiteLines solver = new DWhiteLines();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DWhiteLines {
        int n;
        int[][] tags;

        public void add(int l, int r, int t, int b) {
            l = Math.max(l, 1);
            r = Math.min(r, n);
            t = Math.max(t, 1);
            b = Math.min(b, n);
            if (l > r || t > b) {
                return;
            }
            tags[t][l] += 1;
            if (b < n) {
                tags[b + 1][l] -= 1;
            }
            if (r < n) {
                tags[t][r + 1] -= 1;
            }
            if (b < n && r < n) {
                tags[b + 1][r + 1] += 1;
            }
        }

        public void solve(int testNumber, FastInput in, FastOutput out) {
            n = in.readInt();
            int k = in.readInt();
            tags = new int[n + 1][n + 1];
            int[][] mat = new int[n + 1][n + 1];
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    mat[i][j] = in.readChar() == 'B' ? 1 : 0;
                }
            }
            for (int i = 1; i <= n; i++) {
                int l = n + 1;
                int r = 0;
                for (int j = 1; j <= n; j++) {
                    if (mat[i][j] == 1) {
                        l = Math.min(l, j);
                        r = Math.max(r, j);
                    }
                }
                if (l > r) {
                    tags[1][1] += 1;
                    continue;
                }
                add(r - k + 1, l, i - k + 1, i);
            }

            for (int i = 1; i <= n; i++) {
                int l = n + 1;
                int r = 0;
                for (int j = 1; j <= n; j++) {
                    if (mat[j][i] == 1) {
                        l = Math.min(l, j);
                        r = Math.max(r, j);
                    }
                }
                if (l > r) {
                    tags[1][1] += 1;
                    continue;
                }
                add(i - k + 1, i, r - k + 1, l);
            }

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    tags[i][j] += tags[i - 1][j] +
                            tags[i][j - 1] -
                            tags[i - 1][j - 1];
                }
            }

            int ans = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    ans = Math.max(tags[i][j], ans);
                }
            }

            out.println(ans);
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

        public char readChar() {
            skipBlank();
            char c = (char) next;
            next = read();
            return c;
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
}