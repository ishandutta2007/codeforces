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
            FCards solver = new FCards();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FCards {
        Modular mod = new Modular(998244353);
        Composite comp = new Composite(5000, mod);
        Power power = new Power(mod);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            int k = in.readInt();

            CachedPow pm = new CachedPow(m, mod);
            int[] xk = new int[k + 1];
            for (int i = 0; i <= k; i++) {
                xk[i] = power.pow(i, k);
            }

            int ans = 0;
            BinomialComposite bc = new BinomialComposite(n, k, mod);
            for (int t = 0; t <= k; t++) {
                int p1 = bc.get(t);
                int p2 = 0;
                for (int i = 0; i <= t; i++) {
                    int contrib = comp.composite(t, i);
                    contrib = mod.mul(contrib, xk[t - i]);
                    if (i % 2 == 1) {
                        contrib = mod.valueOf(-contrib);
                    }
                    p2 = mod.plus(p2, contrib);
                }
                int p3 = pm.inverse(t);

                int contrib = mod.mul(p1, p2);
                contrib = mod.mul(contrib, p3);
                ans = mod.plus(ans, contrib);
            }

            out.println(ans);
        }

    }

    static class IntegerList implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public int[] getData() {
            return data;
        }

        public void remove(int l, int r) {
            if (l > r) {
                return;
            }
            checkRange(l);
            checkRange(r);
            if (r == size - 1) {
                size = l;
                return;
            } else {
                System.arraycopy(data, r + 1, data, l, size - (r + 1));
                size -= (r - l + 1);
            }
        }

        public IntegerList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public IntegerList(IntegerList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public IntegerList() {
            this(0);
        }

        public void ensureSpace(int req) {
            if (req > cap) {
                while (cap < req) {
                    cap = Math.max(cap + 10, 2 * cap);
                }
                data = Arrays.copyOf(data, cap);
            }
        }

        private void checkRange(int i) {
            if (i < 0 || i >= size) {
                throw new ArrayIndexOutOfBoundsException("index " + i + " out of range");
            }
        }

        public int get(int i) {
            checkRange(i);
            return data[i];
        }

        public void add(int x) {
            ensureSpace(size + 1);
            data[size++] = x;
        }

        public void addAll(int[] x) {
            addAll(x, 0, x.length);
        }

        public void addAll(int[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(IntegerList list) {
            addAll(list.data, 0, list.size);
        }

        public void expandWith(int x, int len) {
            ensureSpace(len);
            while (size < len) {
                data[size++] = x;
            }
        }

        public void set(int i, int x) {
            checkRange(i);
            data[i] = x;
        }

        public int size() {
            return size;
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public void clear() {
            size = 0;
        }

        public String toString() {
            return Arrays.toString(toArray());
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof IntegerList)) {
                return false;
            }
            IntegerList other = (IntegerList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Integer.hashCode(data[i]);
            }
            return h;
        }

        public IntegerList clone() {
            IntegerList ans = new IntegerList();
            ans.addAll(this);
            return ans;
        }

    }

    static class FastFourierTransform {
        private static double[][] realLevels = new double[30][];
        private static double[][] imgLevels = new double[30][];

        private static void prepareLevel(int i) {
            if (realLevels[i] == null) {
                realLevels[i] = new double[1 << i];
                imgLevels[i] = new double[1 << i];
                for (int j = 0, s = 1 << i; j < s; j++) {
                    realLevels[i][j] = Math.cos(Math.PI / s * j);
                    imgLevels[i][j] = Math.sin(Math.PI / s * j);
                }
            }
        }

        public static void dft(double[][] p, int m) {
            int n = 1 << m;

            int shift = 32 - Integer.numberOfTrailingZeros(n);
            for (int i = 1; i < n; i++) {
                int j = Integer.reverse(i << shift);
                if (i < j) {
                    SequenceUtils.swap(p[0], i, j);
                    SequenceUtils.swap(p[1], i, j);
                }
            }

            double[][] t = new double[2][1];
            for (int d = 0; d < m; d++) {
                int s = 1 << d;
                int s2 = s << 1;
                prepareLevel(d);
                for (int i = 0; i < n; i += s2) {
                    for (int j = 0; j < s; j++) {
                        int a = i + j;
                        int b = a + s;
                        mul(realLevels[d][j], imgLevels[d][j], p[0][b], p[1][b], t, 0);
                        sub(p[0][a], p[1][a], t[0][0], t[1][0], p, b);
                        add(p[0][a], p[1][a], t[0][0], t[1][0], p, a);
                    }
                }
            }
        }

        public static void idft(double[][] p, int m) {
            dft(p, m);

            int n = 1 << m;
            div(p[0][0], p[1][0], n, p, 0);
            div(p[0][n / 2], p[1][n / 2], n, p, n / 2);
            for (int i = 1, until = n / 2; i < until; i++) {
                double a = p[0][n - i];
                double b = p[1][n - i];
                div(p[0][i], p[1][i], n, p, n - i);
                div(a, b, n, p, i);
            }
        }

        private static void add(double r1, double i1, double r2, double i2, double[][] r, int i) {
            r[0][i] = r1 + r2;
            r[1][i] = i1 + i2;
        }

        private static void sub(double r1, double i1, double r2, double i2, double[][] r, int i) {
            r[0][i] = r1 - r2;
            r[1][i] = i1 - i2;
        }

        private static void mul(double r1, double i1, double r2, double i2, double[][] r, int i) {
            r[0][i] = r1 * r2 - i1 * i2;
            r[1][i] = r1 * i2 + i1 * r2;
        }

        private static void div(double r1, double i1, double r2, double[][] r, int i) {
            r[0][i] = r1 / r2;
            r[1][i] = i1 / r2;
        }

        public static int[] multiplyMod(int[] a, int aLen, int[] b, int bLen, int m) {
            int need = aLen + bLen - 1;
            int n = 1 << CachedLog2.ceilLog(need);

            double[] aReal = new double[n];
            double[] aImag = new double[n];
            for (int i = 0; i < aLen; i++) {
                int x = (a[i] % m + m) % m;
                aReal[i] = x & ((1 << 15) - 1);
                aImag[i] = x >> 15;
            }
            dft(new double[][]{aReal, aImag}, CachedLog2.floorLog(n));

            double[] bReal = new double[n];
            double[] bImag = new double[n];
            for (int i = 0; i < bLen; i++) {
                int x = (b[i] % m + m) % m;
                bReal[i] = x & ((1 << 15) - 1);
                bImag[i] = x >> 15;
            }
            dft(new double[][]{bReal, bImag}, CachedLog2.floorLog(n));

            double[] faReal = new double[n];
            double[] faImag = new double[n];
            double[] fbReal = new double[n];
            double[] fbImag = new double[n];

            for (int i = 0; i < n; i++) {
                int j = (n - i) & (n - 1);

                double a1r = (aReal[i] + aReal[j]) / 2;
                double a1i = (aImag[i] - aImag[j]) / 2;
                double a2r = (aImag[i] + aImag[j]) / 2;
                double a2i = (aReal[j] - aReal[i]) / 2;

                double b1r = (bReal[i] + bReal[j]) / 2;
                double b1i = (bImag[i] - bImag[j]) / 2;
                double b2r = (bImag[i] + bImag[j]) / 2;
                double b2i = (bReal[j] - bReal[i]) / 2;

                faReal[i] = a1r * b1r - a1i * b1i - a2r * b2i - a2i * b2r;
                faImag[i] = a1r * b1i + a1i * b1r + a2r * b2r - a2i * b2i;

                fbReal[i] = a1r * b2r - a1i * b2i + a2r * b1r - a2i * b1i;
                fbImag[i] = a1r * b2i + a1i * b2r + a2r * b1i + a2i * b1r;
            }

            idft(new double[][]{faReal, faImag}, CachedLog2.floorLog(n));
            idft(new double[][]{fbReal, fbImag}, CachedLog2.floorLog(n));
            int[] res = new int[need];
            for (int i = 0; i < need; i++) {
                long aa = (long) (faReal[i] + 0.5);
                long bb = (long) (fbReal[i] + 0.5);
                long cc = (long) (faImag[i] + 0.5);
                res[i] = (int) ((aa % m + (bb % m << 15) + (cc % m << 30)) % m);
            }
            return res;
        }

    }

    static class CachedPow {
        private int[] first;
        private int[] second;
        private Modular mod;
        private Modular powMod;

        public CachedPow(int x, Modular mod) {
            this(x, mod.getMod(), mod);
        }

        public CachedPow(int x, int maxExp, Modular mod) {
            this.mod = mod;
            this.powMod = mod.getModularForPowerComputation();
            int k = Math.max(1, (int) DigitUtils.round(Math.sqrt(maxExp)));
            first = new int[k];
            second = new int[maxExp / k + 1];
            first[0] = 1;
            for (int i = 1; i < k; i++) {
                first[i] = mod.mul(x, first[i - 1]);
            }
            second[0] = 1;
            int step = mod.mul(x, first[k - 1]);
            for (int i = 1; i < second.length; i++) {
                second[i] = mod.mul(second[i - 1], step);
            }
        }

        public int pow(int exp) {
            return mod.mul(first[exp % first.length], second[exp / first.length]);
        }

        public int inverse(int exp) {
            return pow(powMod.valueOf(-exp));
        }

    }

    static class BinomialComposite {
        private int m;
        private Modular mod;
        private IntegerList composites;

        public BinomialComposite(long n, int m, Modular mod) {
            this.m = m;
            this.mod = mod;
            composites = pow(n);
            composites.expandWith(0, m + 1);
        }

        public int get(int i) {
            return composites.get(i);
        }

        private void mul(IntegerList a, IntegerList b, IntegerList c) {
            Polynomials.mul(a, b, c, mod);
            trim(c);
        }

        private void trim(IntegerList x) {
            if (x.size() > m + 1) {
                x.remove(m + 1, x.size() - 1);
            }
        }

        private void mul(IntegerList p, IntegerList ans) {
            ans.clear();
            ans.expandWith(0, p.size() + 1);

            int n = p.size();
            for (int i = 0; i < n; i++) {
                int val = p.get(i);
                ans.set(i, mod.plus(ans.get(i), val));
                ans.set(i + 1, val);
            }

            trim(ans);
        }

        private IntegerList pow(long exp) {
            int ceil = CachedLog2.ceilLog(m + 1 + m);
            Loop<IntegerList> loop = new Loop<>(new IntegerList(1 << ceil), new IntegerList(1 << ceil));
            loop.get().add(1);
            for (int i = CachedLog2.floorLog(exp); i >= 0; i--) {
                mul(loop.get(), loop.get(), loop.turn());
                if (1 == Bits.bitAt(exp, i)) {
                    mul(loop.get(), loop.turn());
                }
            }
            return loop.get();
        }

    }

    static class Factorial {
        int[] fact;
        int[] inv;
        Modular modular;

        public Modular getModular() {
            return modular;
        }

        public Factorial(int[] fact, int[] inv, InverseNumber in, int limit, Modular modular) {
            this.modular = modular;
            this.fact = fact;
            this.inv = inv;
            fact[0] = inv[0] = 1;
            for (int i = 1; i <= limit; i++) {
                fact[i] = modular.mul(fact[i - 1], i);
                inv[i] = modular.mul(inv[i - 1], in.inv[i]);
            }
        }

        public Factorial(int limit, Modular modular) {
            this(new int[limit + 1], new int[limit + 1], new InverseNumber(limit, modular), limit, modular);
        }

        public int fact(int n) {
            return fact[n];
        }

        public int invFact(int n) {
            return inv[n];
        }

    }

    static class Composite {
        final Factorial factorial;
        final Modular modular;

        public Composite(Factorial factorial) {
            this.factorial = factorial;
            this.modular = factorial.getModular();
        }

        public Composite(int limit, Modular modular) {
            this(new Factorial(limit, modular));
        }

        public int composite(int m, int n) {
            if (n > m) {
                return 0;
            }
            return modular.mul(modular.mul(factorial.fact(m), factorial.invFact(n)), factorial.invFact(m - n));
        }

    }

    static class CachedLog2 {
        private static final int BITS = 16;
        private static final int LIMIT = 1 << BITS;
        private static final byte[] CACHE = new byte[LIMIT];

        static {
            int b = 0;
            for (int i = 0; i < LIMIT; i++) {
                while ((1 << (b + 1)) <= i) {
                    b++;
                }
                CACHE[i] = (byte) b;
            }
        }

        public static int ceilLog(int x) {
            int ans = floorLog(x);
            if ((1 << ans) < x) {
                ans++;
            }
            return ans;
        }

        public static int floorLog(int x) {
            return x < LIMIT ? CACHE[x] : (BITS + CACHE[x >>> BITS]);
        }

        public static int floorLog(long x) {
            int ans = 0;
            while (x >= LIMIT) {
                ans += BITS;
                x >>>= BITS;
            }
            return ans + CACHE[(int) x];
        }

    }

    static class InverseNumber {
        int[] inv;

        public InverseNumber(int[] inv, int limit, Modular modular) {
            this.inv = inv;
            inv[1] = 1;
            int p = modular.getMod();
            for (int i = 2; i <= limit; i++) {
                int k = p / i;
                int r = p % i;
                inv[i] = modular.mul(-k, inv[r]);
            }
        }

        public InverseNumber(int limit, Modular modular) {
            this(new int[limit + 1], limit, modular);
        }

    }

    static class SequenceUtils {
        public static void swap(double[] data, int i, int j) {
            double tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

        public static boolean equal(int[] a, int al, int ar, int[] b, int bl, int br) {
            if ((ar - al) != (br - bl)) {
                return false;
            }
            for (int i = al, j = bl; i <= ar; i++, j++) {
                if (a[i] != b[j]) {
                    return false;
                }
            }
            return true;
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

    static class Modular {
        int m;

        public int getMod() {
            return m;
        }

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

        public Modular getModularForPowerComputation() {
            return new Modular(m - 1);
        }

        public String toString() {
            return "mod " + m;
        }

    }

    static class Power {
        final Modular modular;

        public Power(Modular modular) {
            this.modular = modular;
        }

        public int pow(int x, int n) {
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

    }

    static class Loop<T> {
        T[] data;
        int pos;

        public Loop(T... data) {
            this.data = data;
        }

        public T turn(int i) {
            pos += i;
            return get(0);
        }

        public T turn() {
            return turn(1);
        }

        public T get(int i) {
            return data[(pos + i) % data.length];
        }

        public T get() {
            return get(0);
        }

    }

    static class Polynomials {
        public static int rankOf(IntegerList p) {
            int[] data = p.getData();
            int r = p.size() - 1;
            while (r >= 0 && data[r] == 0) {
                r--;
            }
            return Math.max(0, r);
        }

        public static void mul(IntegerList a, IntegerList b, IntegerList c, Modular mod) {
            int rA = rankOf(a);
            int rB = rankOf(b);
            c.clear();
            c.expandWith(0, rA + rB + 1);
            if (rA >= 64 && rB >= 64) {
                int[] ans = FastFourierTransform.multiplyMod(a.getData(), rA + 1,
                        b.getData(), rB + 1, mod.getMod());
                c.clear();
                c.addAll(ans);
                return;
            }
            int[] aData = a.getData();
            int[] bData = b.getData();
            int[] cData = c.getData();
            for (int i = 0; i <= rA; i++) {
                for (int j = 0; j <= rB; j++) {
                    cData[i + j] = mod.plus(cData[i + j], mod.mul(aData[i], bData[j]));
                }
            }
        }

    }

    static class Bits {
        private Bits() {
        }

        public static int bitAt(long x, int i) {
            return (int) ((x >> i) & 1);
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static long round(double x) {
            if (x >= 0) {
                return (long) (x + 0.5);
            } else {
                return (long) (x - 0.5);
            }
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
}