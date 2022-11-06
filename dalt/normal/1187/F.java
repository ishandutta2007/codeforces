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
            TaskF solver = new TaskF();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskF {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int[] ls = new int[n + 1];
            int[] rs = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                ls[i] = in.readInt();
            }
            for (int i = 1; i <= n; i++) {
                rs[i] = in.readInt();
            }
            Modular mod = new Modular(1e9 + 7);
            Power pow = new Power(mod);

            int[] range = new int[n + 1];
            for (int i = 0; i <= n; i++) {
                range[i] = rs[i] - ls[i] + 1;
            }
            int[] invRange = new int[n + 1];
            for (int i = 0; i <= n; i++) {
                invRange[i] = pow.inverse(range[i]);
            }

            int[] probF = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                int p = mod.mul(invRange[i - 1], invRange[i]);
                int intersect = intersect(ls[i - 1], rs[i - 1], ls[i], rs[i]);
                p = mod.mul(p, intersect);
                probF[i] = mod.subtract(1, p);
            }
            PreSum ps = new PreSum(probF);

            int part1 = 0;
            for (int i = 2; i <= n; i++) {
                int local1 = mod.valueOf(ps.intervalSum(1, i - 2));
                local1 = mod.mul(local1, probF[i]);

                int intersect = intersect(ls[i - 2], rs[i - 2], ls[i - 1], rs[i - 1],
                        ls[i], rs[i]);
                int probBoth = intersect;
                probBoth = mod.mul(probBoth, invRange[i - 2]);
                probBoth = mod.mul(probBoth, invRange[i - 1]);
                probBoth = mod.mul(probBoth, invRange[i]);
                int local2 = 1;
                local2 = mod.subtract(local2, mod.subtract(1, probF[i - 1]));
                local2 = mod.subtract(local2, mod.subtract(1, probF[i]));
                local2 = mod.plus(local2, probBoth);

                int local = mod.plus(local1, local2);
                part1 = mod.plus(part1, local);
            }
            part1 = mod.mul(part1, 2);

            int part2 = 0;
            for (int i = 1; i <= n; i++) {
                part2 = mod.plus(part2, probF[i]);
            }

            int exp = mod.plus(part1, part2);
            out.println(exp);
        }

        public int intersect(int l1, int r1, int l2, int r2) {
            int l = Math.max(l1, l2);
            int r = Math.min(r1, r2);
            return Math.max(r - l + 1, 0);
        }

        public int intersect(int l1, int r1, int l2, int r2, int l3, int r3) {
            int l = Math.max(l1, Math.max(l2, l3));
            int r = Math.min(r1, Math.min(r2, r3));
            return Math.max(r - l + 1, 0);
        }

    }

    static class PreSum {
        private long[] pre;

        public PreSum(long[] a) {
            int n = a.length;
            pre = new long[n];
            pre[0] = a[0];
            for (int i = 1; i < n; i++) {
                pre[i] = pre[i - 1] + a[i];
            }
        }

        public PreSum(int[] a) {
            int n = a.length;
            pre = new long[n];
            pre[0] = a[0];
            for (int i = 1; i < n; i++) {
                pre[i] = pre[i - 1] + a[i];
            }
        }

        public long intervalSum(int l, int r) {
            if (l > r) {
                return 0;
            }
            if (l == 0) {
                return pre[r];
            }
            return pre[r] - pre[l - 1];
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

    static class Power {
        final Modular modular;

        public Power(Modular modular) {
            this.modular = modular;
        }

        public int pow(int x, long n) {
            if (n == 0) {
                return modular.valueOf(1);
            }
            long r = pow(x, n >> 1);
            r = modular.valueOf(r * r);
            if ((n & 1) == 1) {
                r = modular.valueOf(r * x);
            }
            return (int) r;
        }

        public int inverse(int x) {
            return pow(x, modular.m - 2);
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

        public int subtract(int x, int y) {
            return valueOf(x - y);
        }

        public String toString() {
            return "mod " + m;
        }

    }
}