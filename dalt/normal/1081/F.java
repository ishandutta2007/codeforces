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
            FTrickyInteractor solver = new FTrickyInteractor();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FTrickyInteractor {
        FastInput in;
        FastOutput out;
        int n;
        int t;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            this.in = in;
            this.out = out;

            n = in.readInt();
            t = in.readInt();

            int[] ans = new int[n + 1];
            if (n == 1) {
                ans[1] = t;
                output(ans);
                return;
            }

            if (n % 2 == 0) {
                ans[1] = queryPrefix(1, t);
            } else {
                ans[1] = t - querySuffix(2, t);
            }

            int preSum = ans[1];
            for (int i = 2; i <= n; i++) {
                ans[i] = queryPrefix(i, t) - preSum;
                preSum += ans[i];
            }

            output(ans);
        }

        public void output(int[] ans) {
            out.append("! ");
            for (int i = 1; i <= n; i++) {
                out.append(ans[i]);
            }
            out.flush();
        }

        public int querySuffix(int s, int t) {
            int p = s;
            boolean sufOdd = (n - s + 1) % 2 == 1;
            boolean prevOdd = !sufOdd;
            if (prevOdd != (p % 2 == 1)) {
                p++;
            }
            boolean lFlip = false;
            boolean rFlip = false;
            int ans = t;
            while (!(!lFlip && rFlip)) {
                int val = query(s, p);
                if ((Math.abs(ans - val) % 2 == 1) == prevOdd) {
                    lFlip = !lFlip;
                } else {
                    rFlip = !rFlip;
                }
                ans = val;
            }
            int ret = (n - s + 1 + t - ans) / 2;
            while (lFlip || rFlip) {
                int val = query(s, p);
                if ((Math.abs(ans - val) % 2 == 1) == prevOdd) {
                    lFlip = !lFlip;
                } else {
                    rFlip = !rFlip;
                }
                ans = val;
            }
            return ret;
        }

        public int queryPrefix(int p, int t) {
            int s = p;
            boolean prevOdd = p % 2 == 1;
            boolean sufOdd = !prevOdd;
            if (sufOdd != ((n - s + 1) % 2 == 1)) {
                s--;
            }
            boolean lFlip = false;
            boolean rFlip = false;
            int ans = t;
            while (!(lFlip && !rFlip)) {
                int val = query(s, p);
                if ((Math.abs(ans - val) % 2 == 1) == prevOdd) {
                    lFlip = !lFlip;
                } else {
                    rFlip = !rFlip;
                }
                ans = val;
            }
            int ret = (p + t - ans) / 2;
            while (lFlip || rFlip) {
                int val = query(s, p);
                if ((Math.abs(ans - val) % 2 == 1) == prevOdd) {
                    lFlip = !lFlip;
                } else {
                    rFlip = !rFlip;
                }
                ans = val;
            }
            return ret;
        }

        public int query(int l, int r) {
            out.append("? ").append(l).append(' ').append(r).println();
            out.flush();
            return in.readInt();
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

        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }

        public FastOutput append(int c) {
            cache.append(c);
            return this;
        }

        public FastOutput append(String c) {
            cache.append(c);
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