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
            TaskC solver = new TaskC();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskC {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            long[] src = new long[]{in.readInt(), in.readInt()};
            long[] dst = new long[]{in.readInt(), in.readInt()};
            int n = in.readInt();
            int[][] dxy = new int[n][2];
            for (int i = 0; i < n; i++) {
                switch (in.readChar()) {
                    case 'U':
                        dxy[i][1] = 1;
                        break;
                    case 'D':
                        dxy[i][1] = -1;
                        break;
                    case 'L':
                        dxy[i][0] = -1;
                        break;
                    case 'R':
                        dxy[i][0] = 1;
                        break;
                }
            }

            long l = 0;
            long r = (long) 1e18;
            while (l < r) {
                long mid = (l + r) >>> 1;
                if (check(src, dst, dxy, mid)) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (check(src, dst, dxy, l)) {
                out.println(l);
            } else {
                out.println(-1);
            }
        }

        public boolean check(long[] src, long[] dst, int[][] dxy, long time) {
            int n = dxy.length;
            long[] sum = new long[2];
            for (int i = 0; i < n; i++) {
                sum[0] += dxy[i][0];
                sum[1] += dxy[i][1];
            }
            long[] trace = src.clone();
            trace[0] += sum[0] * (time / n);
            trace[1] += sum[1] * (time / n);
            for (int i = 0; i < time % n; i++) {
                trace[0] += dxy[i][0];
                trace[1] += dxy[i][1];
            }
            return dist(trace, dst) <= time;
        }

        public long dist(long[] a, long[] b) {
            return Math.abs(a[0] - b[0]) + Math.abs(a[1] - b[1]);
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

        public char readChar() {
            skipBlank();
            char c = (char) next;
            next = read();
            return c;
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

        public FastOutput println(long c) {
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