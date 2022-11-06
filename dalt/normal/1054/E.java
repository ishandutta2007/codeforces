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
            EChipsPuzzle solver = new EChipsPuzzle();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class EChipsPuzzle {
        List<int[]> seq = new ArrayList<>(400000);

        public void add(int... pts) {
            seq.add(pts);
        }

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();


            String[][] now = new String[n][m];
            String[][] target = new String[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    now[i][j] = in.readString();
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    target[i][j] = in.readString();
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < now[i][i].length(); j++) {
                    add(i, i, i, 1 - i);
                }
                now[i][1 - i] = now[i][i] + now[i][1 - i];
                now[i][i] = "";
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    if (i == j) {
                        continue;
                    }
                    for (int k = now[i][j].length() - 1; k >= 0; k--) {
                        int c = now[i][j].charAt(k) - '0';
                        add(i, j, c, c);
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i < 2 && j < 2) {
                        continue;
                    }
                    for (int k = now[i][j].length() - 1; k >= 0; k--) {
                        int c = now[i][j].charAt(k) - '0';
                        if (i < 2) {
                            add(i, j, i, 1 - i);
                            add(i, 1 - i, c, c);
                        } else if (j < 2) {
                            add(i, j, 1 - j, j);
                            add(1 - j, j, c, c);
                        } else {
                            add(i, j, c, j);
                            add(c, j, c, c);
                        }
                    }
                }
            }

            for (int i = n - 1; i >= 0; i--) {
                for (int j = 0; j < m; j++) {
                    if (i < 2 && j < 2) {
                        continue;
                    }
                    for (int k = target[i][j].length() - 1; k >= 0; k--) {
                        int c = target[i][j].charAt(k) - '0';
                        if (i < 2) {
                            add(c, c, i, 1 - i);
                            add(i, 1 - i, i, j);
                        } else if (j < 2) {
                            add(c, c, 1 - j, j);
                            add(1 - j, j, i, j);
                        } else {
                            add(c, c, c, j);
                            add(c, j, i, j);
                        }
                    }
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int k = target[i][i].length() - 1; k >= 0; k--) {
                    int c = target[i][i].charAt(k) - '0';
                    add(c, c, i, 1 - i);
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    if (i == j) {
                        continue;
                    }
                    for (int k = target[i][j].length() - 1; k >= 0; k--) {
                        int c = target[i][j].charAt(k) - '0';
                        ;
                        add(c, c, i, j);
                    }
                }
            }

            for (int i = 0; i < 2; i++) {
                for (int k = target[i][i].length() - 1; k >= 0; k--) {
                    add(i, 1 - i, i, i);
                }
            }

            out.println(seq.size());
            for (int[] task : seq) {
                for (int x : task) {
                    out.append(x + 1).append(' ');
                }
                out.println();
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

    static class FastOutput implements AutoCloseable, Closeable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

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