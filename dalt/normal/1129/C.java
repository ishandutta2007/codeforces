import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
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
        int[][] forbiden = new int[][]{{0, 0, 1, 1},
                {0, 1, 0, 1}, {1, 1, 1, 0}, {1, 1, 1, 1}};

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int m = in.readInt();
            Hash h11 = new Hash(m + 4, 11);
            Hash h31 = new Hash(m + 4, 31);

            h11.populate(forbiden[0], 4);
            h31.populate(forbiden[0], 4);
            long f1 = DigitUtils.asLong(h11.partialVerbose(0, 3), h31.partialVerbose(0, 3));
            h11.populate(forbiden[1], 4);
            h31.populate(forbiden[1], 4);
            long f2 = DigitUtils.asLong(h11.partialVerbose(0, 3), h31.partialVerbose(0, 3));
            h11.populate(forbiden[2], 4);
            h31.populate(forbiden[2], 4);
            long f3 = DigitUtils.asLong(h11.partialVerbose(0, 3), h31.partialVerbose(0, 3));
            h11.populate(forbiden[3], 4);
            h31.populate(forbiden[3], 4);
            long f4 = DigitUtils.asLong(h11.partialVerbose(0, 3), h31.partialVerbose(0, 3));

            NumberTheory.Modular mod = new NumberTheory.Modular(1e9 + 7);
            LongHashSet set = new LongHashSet(m * (m - 1) / 2 + m);
            int[] str = new int[m];
            int[] dp = new int[m + 1];
            int ans = 0;
            for (int i = 0; i < m; i++) {
                str[i] = in.readInt();
                h11.populate(str, i + 1);
                h31.populate(str, i + 1);
                Arrays.fill(dp, 0);
                for (int j = 0; j <= i; j++) {
                    long sig = DigitUtils.asLong(h11.partialVerbose(j, i),
                            h31.partialVerbose(j, i));
                    if (set.contain(sig)) {
                        continue;
                    }
                    set.add(sig);
                    dp[j] = 1;
                }
                for (int j = 0; j <= i; j++) {
                    if (j + 1 <= i + 1) {
                        dp[j + 1] = mod.plus(dp[j + 1], dp[j]);
                    }
                    if (j + 2 <= i + 1) {
                        dp[j + 2] = mod.plus(dp[j + 2], dp[j]);
                    }
                    if (j + 3 <= i + 1) {
                        dp[j + 3] = mod.plus(dp[j + 3], dp[j]);
                    }
                    long h = DigitUtils.asLong(h11.partialVerbose(j, j + 3),
                            h31.partialVerbose(j, j + 3));
                    if (j + 4 <= i + 1 && !(h == f1 || h == f2 || h == f3 || h == f4)) {
                        dp[j + 4] = mod.plus(dp[j + 4], dp[j]);
                    }
                }
                ans = mod.plus(ans, dp[i + 1]);
                out.println(ans);
            }

            return;
        }

    }

    static class LongHashSet {
        private int[] slot;
        private int[] next;
        private long[] values;
        private int alloc;
        private boolean[] removed;
        private int mask;
        private int size;

        public LongHashSet(int cap) {
            this.mask = (1 << (32 - Integer.numberOfLeadingZeros(cap - 1))) - 1;
            slot = new int[mask + 1];
            next = new int[cap + 1];
            values = new long[cap + 1];
            removed = new boolean[cap + 1];
        }

        public void alloc() {
            alloc++;
            next[alloc] = 0;
            removed[alloc] = false;
            size++;
        }

        private int hash(long x) {
            int h = Long.hashCode(x);
            return h ^ (h >>> 16);
        }

        public void add(long x) {
            int h = hash(x);
            int s = h & mask;
            if (slot[s] == 0) {
                alloc();
                slot[s] = alloc;
                values[alloc] = x;
                return;
            }
            int index = findIndexOrLastEntry(s, x);
            if (values[index] != x) {
                alloc();
                next[index] = alloc;
                values[alloc] = x;
            }
        }

        public boolean contain(long x) {
            int h = hash(x);
            int s = h & mask;
            if (slot[s] == 0) {
                return false;
            }
            return values[findIndexOrLastEntry(s, x)] == x;
        }

        private int findIndexOrLastEntry(int s, long x) {
            int iter = slot[s];
            while (values[iter] != x) {
                if (next[iter] != 0) {
                    iter = next[iter];
                } else {
                    return iter;
                }
            }
            return iter;
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

    static class NumberTheory {
        public static class Modular {
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

            public String toString() {
                return "mod " + m;
            }

        }

        public static class Power {
            final NumberTheory.Modular modular;

            public Power(NumberTheory.Modular modular) {
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

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static long asLong(int high, int low) {
            return (((long) high) << 32) | low;
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

    static class Hash {
        public static final NumberTheory.Modular MOD = new NumberTheory.Modular((int) (1e9 + 7));
        public static final NumberTheory.Power POWER = new NumberTheory.Power(MOD);
        private int[] inverse;
        private int[] xs;
        private int[] hash;

        public Hash(Hash model) {
            inverse = model.inverse;
            hash = new int[model.hash.length];
            xs = model.xs;
        }

        public Hash(int size, int x) {
            inverse = new int[size + 1];
            hash = new int[size + 1];
            xs = new int[size + 1];
            int invX = POWER.inverse(x);
            inverse[0] = 1;
            xs[0] = 1;
            for (int i = 1; i <= size; i++) {
                this.inverse[i] = MOD.mul(this.inverse[i - 1], invX);
                xs[i] = MOD.mul(xs[i - 1], x);
            }
        }

        public void populate(int[] data, int n) {
            hash[0] = data[0];
            for (int i = 1; i < n; i++) {
                hash[i] = MOD.plus(hash[i - 1], MOD.mul(data[i], xs[i]));
            }
        }

        public int partialVerbose(int l, int r) {
            int h = partial(l, r);
            h = MOD.plus(h, xs[r - l + 1]);
            return MOD.valueOf(h);
        }

        public int partial(int l, int r) {
            long h = hash[r];
            if (l > 0) {
                h -= hash[l - 1];
                h *= inverse[l];
            }
            return MOD.valueOf(h);
        }

    }
}