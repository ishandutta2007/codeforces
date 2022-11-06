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
            TaskG solver = new TaskG();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskG {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int a = in.readInt();
            Problem[] ps = new Problem[n];
            for (int i = 0; i < n; i++) {
                ps[i] = new Problem();
                ps[i].d = in.readInt();
                ps[i].p = a - in.readInt();
            }
            long ans = dac(ps, 0, n - 1);
            out.println(ans);
        }

        public long dac(Problem[] ps, int l, int r) {
            if (l == r) {
                return Math.max(0, ps[l].p);
            }
            int m = (l + r) >>> 1;
            long ans = Math.max(dac(ps, l, m), dac(ps, m + 1, r));

            long cost = pow2(ps[m].d - ps[m + 1].d);
            long lBest = 0;
            long rBest = 0;
            long lSum = 0;
            long rSum = 0;
            int i = m;
            int j = m + 1;
            while (i >= l || j <= r) {
                if (i >= l && (j > r || pow2(ps[i].d - ps[i + 1].d)
                        <= pow2(ps[j].d - ps[j - 1].d))) {
                    lSum += ps[i].p;
                    cost = Math.max(cost, pow2(ps[i].d - ps[i + 1].d));
                    lBest = Math.max(lBest, lSum);
                    i--;
                } else {
                    rSum += ps[j].p;
                    cost = Math.max(cost, pow2(ps[j].d - ps[j - 1].d));
                    rBest = Math.max(rBest, rSum);
                    j++;
                }
                ans = Math.max(ans, lBest + rBest - cost);
            }
            return ans;
        }

        long pow2(long x) {
            return x * x;
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

    static class Problem {
        int d;
        int p;

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