import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.Random;
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
            TaskE solver = new TaskE();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskE {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int a = in.readInt();
            int b = in.readInt();
            int c = in.readInt();
            int[] as = new int[a];
            int[] bs = new int[b];
            int[] cs = new int[c];
            for (int i = 0; i < a; i++) {
                as[i] = in.readInt();
            }
            for (int i = 0; i < b; i++) {
                bs[i] = in.readInt();
            }
            for (int i = 0; i < c; i++) {
                cs[i] = in.readInt();
            }


            Randomized.randomizedArray(as, 0, a);
            Randomized.randomizedArray(bs, 0, b);
            Randomized.randomizedArray(cs, 0, c);
            Arrays.sort(as);
            Arrays.sort(bs);
            Arrays.sort(cs);

            int n = a + b + c;
            int[] ab = new int[n + 1];

            int la = 0;
            int lb = 0;
            int cost = a;

            for (int i = 1; i <= n; i++) {
                while (la < a && as[la] < i) {
                    la++;
                    cost--;
                }
                while (lb < b && bs[lb] < i) {
                    lb++;
                    cost++;
                }
                ab[i] = cost;
            }

            int[] bc = new int[n + 1];
            int rb = b - 1;
            int rc = c - 1;
            cost = c;

            for (int i = n; i >= 1; i--) {
                while (rb >= 0 && bs[rb] > i) {
                    rb--;
                    cost++;
                }
                while (rc >= 0 && cs[rc] > i) {
                    rc--;
                    cost--;
                }
                bc[i] = cost;
            }

            int[] sufMinBC = new int[n + 1];
            sufMinBC[n] = bc[n];
            for (int i = n - 1; i >= 1; i--) {
                sufMinBC[i] = Math.min(sufMinBC[i + 1], bc[i]);
            }

            int ans = n;
            ans = Math.min(ans, b + c);
            for (int i = 1; i <= n; i++) {
                if (i > 1) {
                    ans = Math.min(ans, ab[i] + sufMinBC[i - 1]);
                } else {
                    ans = Math.min(ans, ab[1] + b);
                    ans = Math.min(ans, ab[1] + sufMinBC[1]);
                }
            }

            out.println(ans);
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

    static class Randomized {
        static Random random = new Random();

        public static void randomizedArray(int[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                int tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static int nextInt(int l, int r) {
            return random.nextInt(r - l + 1) + l;
        }

    }
}