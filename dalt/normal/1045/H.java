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
            HSelfExploration solver = new HSelfExploration();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class HSelfExploration {
        Modular mod = new Modular(1e9 + 7);
        Composite comp = new Composite(100000, mod);
        IntegerList blockOfA;
        IntegerList blockOfB;
        IntegerList actualBlock;

        public int comp(int n, int m) {
            if (n < 0 || m < 0) {
                return 0;
            }
            if (n == 0 && m == 0) {
                return 1;
            }
            return comp.composite(n + m - 1, m);
        }

        public int way(int one, int zero, int c1, int c0) {

            int p1 = comp(one, c1);
            int p2 = comp(zero, c0);
            return mod.mul(p1, p2);
        }

        public int dp(boolean ceil, boolean floor, int c11, int c00, int i) {
            if (c11 < 0 || c00 < 0) {
                return 0;
            }
            if (i == actualBlock.size()) {
                return c11 == 0 && c00 == 0 ? 1 : 0;
            }
            int oneBlock = (actualBlock.size() + 1) / 2 - (i + 1) / 2;
            int zeroBlock = actualBlock.size() - i - oneBlock;
            if (!ceil && !floor) {
                return way(oneBlock, zeroBlock, c11, c00);
            }
            if (!ceil) {
                int limit = blockOfA.get(i) - 1;
                if (i % 2 == 1) {
                    int ans = 0;
                    for (int j = 0; j <= limit; j++) {
                        ans = mod.plus(dp(ceil, j == limit, c11, c00 - j, i + 1), ans);
                    }
                    return ans;
                } else {
                    int addition = way(oneBlock, zeroBlock, c11 - limit - 1, c00);
                    int ans = dp(ceil, floor, c11 - limit, c00, i + 1);
                    return mod.plus(ans, addition);
                }
            }
            if (!floor) {
                int limit = blockOfB.get(i) - 1;
                if (i % 2 == 0) {
                    int ans = 0;
                    for (int j = 0; j <= limit; j++) {
                        ans = mod.plus(dp(j == limit, floor, c11 - j, c00, i + 1), ans);
                    }
                    return ans;
                } else {
                    int addition = way(oneBlock, zeroBlock, c11, c00 - limit - 1);
                    int ans = dp(ceil, floor, c11, c00 - limit, i + 1);
                    return mod.plus(ans, addition);
                }
            }
            int ans = 0;
            if (i % 2 == 0) {
                int l = blockOfA.get(i) - 1;
                int r = blockOfB.get(i) - 1;
                for (int j = l; j <= r; j++) {
                    ans = mod.plus(dp(j == r, j == l, c11 - j, c00, i + 1), ans);
                }
            } else {
                int l = blockOfB.get(i) - 1;
                int r = blockOfA.get(i) - 1;
                for (int j = l; j <= r; j++) {
                    ans = mod.plus(dp(j == l, j == r, c11, c00 - j, i + 1), ans);
                }
            }
            return ans;
        }

        private IntegerList asBlock(int[] x, int n) {
            int cnt = 1;
            int last = x[0];
            IntegerList blocks = new IntegerList(x.length);
            for (int i = 1; i < n; i++) {
                if (x[i] != last) {
                    blocks.add(cnt);
                    cnt = 0;
                    last = x[i];
                }
                cnt++;
            }
            blocks.add(cnt);
            return blocks;
        }

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int[] a = new int[100000];
            int[] b = new int[100000];
            int aLen = in.readString(a, 0);
            int bLen = in.readString(b, 0);
            for (int i = 0; i < aLen; i++) {
                a[i] -= '0';
            }
            for (int i = 0; i < bLen; i++) {
                b[i] -= '0';
            }

            int[][] c = new int[2][2];
            int actualLength = 1;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    c[i][j] = in.readInt();
                    actualLength += c[i][j];
                }
            }

            if (c[1][0] == 0 && (c[0][0] > 0 || c[0][1] > 0)) {
                out.println(0);
                return;
            }
            if (c[1][0] - c[0][1] > 1 || c[1][0] < c[0][1]) {
                out.println(0);
                return;
            }


            actualBlock = new IntegerList(c[1][0] + c[0][1]);
            for (int i = 0; i < 1 + c[1][0] + c[0][1]; i++) {
                actualBlock.add(1);
            }

            if (aLen > actualLength || bLen < actualLength) {
                out.println(0);
                return;
            }
            if (aLen < actualLength) {
                a[0] = 1;
                for (int i = 1; i < actualLength; i++) {
                    a[i] = 0;
                }
            }
            if (bLen > actualLength) {
                for (int i = 0; i < actualLength; i++) {
                    b[i] = 1;
                }
            }

            blockOfA = asBlock(a, actualLength);
            blockOfB = asBlock(b, actualLength);

            int ans = dp(true, true, c[1][1], c[0][0], 0);
            out.println(ans);
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

    static class IntegerList implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

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

        public void addAll(int[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(IntegerList list) {
            addAll(list.data, 0, list.size);
        }

        public int size() {
            return size;
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
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

    static class SequenceUtils {
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

        public String toString() {
            return "mod " + m;
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

        public int readString(int[] data, int offset) {
            skipBlank();

            int originalOffset = offset;
            while (next > 32) {
                data[offset++] = (char) next;
                next = read();
            }

            return offset - originalOffset;
        }

    }
}