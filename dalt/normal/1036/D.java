import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.IOException;
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
            DVasyaAndArrays solver = new DVasyaAndArrays();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DVasyaAndArrays {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.readInt();
            }
            int m = in.readInt();
            long[] b = new long[m];
            for (int j = 0; j < m; j++) {
                b[j] = in.readInt();
            }

            int ans = solve(a, 0, 0, b, 0, 0);
            if (ans >= 1e8) {
                out.println(-1);
                return;
            }
            out.println(ans);
        }

        public int solve(long[] a, int i, long pa, long[] b, int j, long pb) {
            if (i == a.length && j == b.length) {
                if (pa != 0 || pb != 0) {
                    return (int) 1e8;
                }
                return 0;
            }
            if (pa <= pb && i < a.length) {
                pa += a[i++];
            } else if (j < b.length) {
                pb += b[j++];
            } else {
                return (int) 1e8;
            }
            int ans = 0;
            if (pa == pb) {
                ans++;
                pa = pb = 0;
            }
            ans += solve(a, i, pa, b, j, pb);
            return ans;
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