import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.AbstractQueue;
import java.util.HashMap;
import java.util.Random;
import java.util.Deque;
import java.util.function.Supplier;
import java.util.ArrayList;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.util.Collection;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.function.Consumer;
import java.util.List;
import java.util.stream.Stream;
import java.io.Closeable;
import java.io.Writer;
import java.util.ArrayDeque;
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
        Modular mod = new Modular(998244353);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int k = in.readInt();
            int[] allow = new int[10];
            for (int i = 0; i < k; i++) {
                allow[in.readInt()] = 1;
            }
            IntList p = new IntList();
            p.addAll(allow);

            int m = n / 2;
            IntList last = p.clone();
            NumberTheoryTransform ntt = new NumberTheoryTransform(mod, 3);
            List<IntList> lists = new ArrayList<>();
            while (m > 1) {
                if (m % 2 == 1) {
                    lists.add(last.clone());
                }
                ntt.pow2(last);
                Polynomials.normalize(last);
                m /= 2;
            }
            lists.add(last);

            IntList prod = new IntList();
            ntt.mulByPQ(lists.toArray(new IntList[0]), prod);

            int ans = 0;
            for (int i = 0; i < prod.size(); i++) {
                int plus = prod.get(i);
                ans = mod.plus(ans, mod.mul(plus, plus));
            }

            out.println(ans);
        }

    }

    static class PrimitiveRoot {
        private int[] factors;
        private Modular mod;
        private Power pow;
        int phi;
        private static PollardRho rho = new PollardRho();

        public PrimitiveRoot(Modular x) {
            phi = x.getMod() - 1;
            mod = x;
            pow = new Power(mod);
            factors = rho.findAllFactors(phi).keySet().stream().mapToInt(Integer::intValue).toArray();
        }

        public PrimitiveRoot(int x) {
            this(new Modular(x));
        }

        public int findMinPrimitiveRoot() {
            return findMinPrimitiveRoot(2);
        }

        public int findMinPrimitiveRoot(int since) {
            for (int i = since; i < mod.m; i++) {
                boolean flag = true;
                for (int f : factors) {
                    if (pow.pow(i, phi / f) == 1) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return i;
                }
            }
            return -1;
        }

    }

    static class PollardRho {
        MillerRabin mr = new MillerRabin();
        Random random = new Random();

        public int findFactor(int n) {
            if (mr.mr(n, 10)) {
                return n;
            }
            while (true) {
                int f = findFactor0(random.nextInt(n), random.nextInt(n), n);
                if (f != -1) {
                    return f;
                }
            }
        }

        public Map<Integer, Integer> findAllFactors(int n) {
            Map<Integer, Integer> map = new HashMap();
            findAllFactors(map, n);
            return map;
        }

        private void findAllFactors(Map<Integer, Integer> map, int n) {
            if (n == 1) {
                return;
            }
            int f = findFactor(n);
            if (f == n) {
                Integer value = map.get(f);
                if (value == null) {
                    value = 1;
                }
                map.put(f, value * f);
                return;
            }
            findAllFactors(map, f);
            findAllFactors(map, n / f);
        }

        private int findFactor0(int x, int c, int n) {
            int xi = x;
            int xj = x;
            int j = 2;
            int i = 1;
            while (i < n) {
                i++;
                xi = (int) ((long) xi * xi + c) % n;
                int g = GCDs.gcd(n, Math.abs(xi - xj));
                if (g != 1 && g != n) {
                    return g;
                }
                if (i == j) {
                    j = j << 1;
                    xj = xi;
                }
            }
            return -1;
        }

    }

    static class MillerRabin {
        Modular modular;
        Power power;
        Random random = new Random();

        public boolean mr(int n, int s) {
            if (n == 2) {
                return true;
            }
            if (n % 2 == 0) {
                return false;
            }
            modular = new Modular(n);
            power = new Power(modular);
            for (int i = 0; i < s; i++) {
                int x = random.nextInt(n - 2) + 2;
                if (!mr0(x, n)) {
                    return false;
                }
            }
            return true;
        }

        private boolean mr0(int x, int n) {
            int exp = n - 1;
            while (true) {
                int y = power.pow(x, exp);
                if (y != 1 && y != n - 1) {
                    return false;
                }
                if (y != 1 || exp % 2 == 1) {
                    break;
                }
                exp = exp / 2;
            }
            return true;
        }

    }

    static class IntList implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public int[] getData() {
            return data;
        }

        public IntList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public IntList(IntList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public IntList() {
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
                throw new ArrayIndexOutOfBoundsException();
            }
        }

        public int get(int i) {
            checkRange(i);
            return data[i];
        }

        public void addAll(int[] x) {
            addAll(x, 0, x.length);
        }

        public void addAll(int[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(IntList list) {
            addAll(list.data, 0, list.size);
        }

        public void expandWith(int x, int len) {
            ensureSpace(len);
            while (size < len) {
                data[size++] = x;
            }
        }

        public void retain(int n) {
            if (n < 0) {
                throw new IllegalArgumentException();
            }
            if (n >= size) {
                return;
            }
            size = n;
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
            if (!(obj instanceof IntList)) {
                return false;
            }
            IntList other = (IntList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + data[i];
            }
            return h;
        }

        public IntList clone() {
            IntList ans = new IntList();
            ans.addAll(this);
            return ans;
        }

    }

    static class NumberTheoryTransform {
        private Modular modular;
        private Power power;
        private int g;
        private int[] wCache = new int[30];
        private int[] invCache = new int[30];
        public static Buffer<IntList> listBuffer = Polynomials.listBuffer;
        private Log2 log2 = new Log2();

        public NumberTheoryTransform(Modular mod) {
            this(mod, mod.getMod() == 998244353 ? 3 : new PrimitiveRoot(mod.getMod()).findMinPrimitiveRoot());
        }

        public NumberTheoryTransform(Modular mod, int g) {
            this.modular = mod;
            this.power = new Power(mod);
            this.g = g;
            for (int i = 0, until = wCache.length; i < until; i++) {
                int s = 1 << i;
                wCache[i] = power.pow(this.g, (modular.getMod() - 1) / 2 / s);
                invCache[i] = power.inverse(s);
            }
        }

        public void dotMul(int[] a, int[] b, int[] c, int m) {
            for (int i = 0, n = 1 << m; i < n; i++) {
                c[i] = modular.mul(a[i], b[i]);
            }
        }

        public void dft(int[] p, int m) {
            int n = 1 << m;

            int shift = 32 - Integer.numberOfTrailingZeros(n);
            for (int i = 1; i < n; i++) {
                int j = Integer.reverse(i << shift);
                if (i < j) {
                    int temp = p[i];
                    p[i] = p[j];
                    p[j] = temp;
                }
            }

            int w = 0;
            int t = 0;
            for (int d = 0; d < m; d++) {
                int w1 = wCache[d];
                int s = 1 << d;
                int s2 = s << 1;
                for (int i = 0; i < n; i += s2) {
                    w = 1;
                    for (int j = 0; j < s; j++) {
                        int a = i + j;
                        int b = a + s;
                        t = modular.mul(w, p[b]);
                        p[b] = modular.plus(p[a], -t);
                        p[a] = modular.plus(p[a], t);
                        w = modular.mul(w, w1);
                    }
                }
            }

        }

        public void idft(int[] p, int m) {
            dft(p, m);

            int n = 1 << m;
            int invN = invCache[m];

            p[0] = modular.mul(p[0], invN);
            p[n / 2] = modular.mul(p[n / 2], invN);
            for (int i = 1, until = n / 2; i < until; i++) {
                int a = p[n - i];
                p[n - i] = modular.mul(p[i], invN);
                p[i] = modular.mul(a, invN);
            }
        }

        public void mulByPQ(IntList[] lists, IntList ans) {
            PriorityQueue<IntList> pqs = new PriorityQueue<>(lists.length, (a, b) -> a.size() - b.size());
            for (IntList list : lists) {
                IntList clone = listBuffer.alloc();
                clone.addAll(list);
                pqs.add(clone);
            }
            while (pqs.size() > 1) {
                IntList a = pqs.remove();
                IntList b = pqs.remove();
                multiplyAndStoreAnswerIntoA(a, b);
                listBuffer.release(b);
                pqs.add(a);
            }

            IntList last = pqs.remove();
            ans.clear();
            ans.addAll(last);
            listBuffer.release(last);
            return;
        }

        public void pow2(IntList a) {
            int rankAns = (a.size() - 1) * 2;
            int proper = log2.ceilLog(rankAns + 1);
            a.expandWith(0, (1 << proper));
            dft(a.getData(), proper);
            dotMul(a.getData(), a.getData(), a.getData(), proper);
            idft(a.getData(), proper);
            Polynomials.normalize(a);
        }

        private void multiplyAndStoreAnswerIntoA(IntList a, IntList b) {
            int rankAns = a.size() - 1 + b.size() - 1;
            int proper = log2.ceilLog(rankAns + 1);
            a.expandWith(0, (1 << proper));
            b.expandWith(0, (1 << proper));
            dft(a.getData(), proper);
            dft(b.getData(), proper);
            dotMul(a.getData(), b.getData(), a.getData(), proper);
            idft(a.getData(), proper);
            Polynomials.normalize(a);
        }

    }

    static class Polynomials {
        public static Buffer<IntList> listBuffer = new Buffer<>(IntList::new, list -> list.clear());

        public static int rankOf(IntList p) {
            int[] data = p.getData();
            int r = p.size() - 1;
            while (r >= 0 && data[r] == 0) {
                r--;
            }
            return Math.max(0, r);
        }

        public static void normalize(IntList list) {
            list.retain(rankOf(list) + 1);
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

        public int inverse(int x) {
            return pow(x, modular.m - 2);
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

    static class Buffer<T> {
        private Deque<T> deque;
        private Supplier<T> supplier;
        private Consumer<T> cleaner;

        public Buffer(Supplier<T> supplier) {
            this(supplier, (x) -> {
            });
        }

        public Buffer(Supplier<T> supplier, Consumer<T> cleaner) {
            this(supplier, cleaner, 0);
        }

        public Buffer(Supplier<T> supplier, Consumer<T> cleaner, int exp) {
            this.supplier = supplier;
            this.cleaner = cleaner;
            deque = new ArrayDeque<>(exp);
        }

        public T alloc() {
            return deque.isEmpty() ? supplier.get() : deque.removeFirst();
        }

        public void release(T e) {
            cleaner.accept(e);
            deque.addLast(e);
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

    static class Log2 {
        public int ceilLog(int x) {
            return 32 - Integer.numberOfLeadingZeros(x - 1);
        }

    }

    static class GCDs {
        private GCDs() {
        }

        public static int gcd(int a, int b) {
            return a >= b ? gcd0(a, b) : gcd0(b, a);
        }

        private static int gcd0(int a, int b) {
            return b == 0 ? a : gcd0(b, a % b);
        }

    }
}