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
            FDivideTheStudents solver = new FDivideTheStudents();
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                solver.solve(i, in, out);
            out.close();
        }
    }

    static class FDivideTheStudents {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int[] c1 = new int[4];
            int[] c2 = new int[4];
            for (int i = 1; i < 4; i++) {
                c1[i] = in.readInt();
            }
            for (int i = 1; i < 4; i++) {
                c2[i] = in.readInt();
            }
            int[] f = new int[8];
            for (int i = 1; i < 8; i++) {
                f[i] = in.readInt();
            }

            for (int i = 0; i <= f[2]; i++) {
                for (int j = 0; j <= f[3]; j++) {
                    for (int k = 0; k <= f[5]; k++) {
                        int c11 = c1[1] - i - j;
                        int c21 = c2[1] - f[2] - f[3] + i + j;
                        int c12 = c1[2] - i - k;
                        int c22 = c2[2] - f[2] - f[5] + i + k;
                        int c13 = c1[3] - j - k;
                        int c23 = c2[3] - f[3] - f[5] + j + k;
                        if (c11 < 0 || c12 < 0 || c13 < 0 || c21 < 0 || c22 < 0 || c23 < 0) {
                            continue;
                        }
                        int a1 = Math.min(Math.min(c11, c12), c13);
                        int a2 = Math.min(Math.min(c21, c22), c23);
                        if (a1 + a2 < f[1] || c11 + c21 - f[1] - f[4] < 0
                                || c12 + c22 - f[1] - f[6] < 0
                                || c13 + c23 - f[1] - f[7] < 0) {
                            continue;
                        }
                        int g1 = Math.min(a1, f[1]);
                        out.append(g1).append(' ');
                        out.append(i).append(' ');
                        out.append(j).append(' ');
                        out.append(Math.min(f[4], c11 - g1)).append(' ');
                        out.append(k).append(' ');
                        out.append(Math.min(f[6], c12 - g1)).append(' ');
                        out.append(Math.min(f[7], c13 - g1)).append(' ');
                        out.println();
                        return;
                    }
                }
            }

            out.println(-1);
        }

    }

    static class FastInput {
        private final InputStream is;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 13);
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
            return append(c).println();
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