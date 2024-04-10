import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Collection;
import java.io.IOException;
import java.util.Deque;
import java.util.function.Supplier;
import java.io.UncheckedIOException;
import java.util.function.Consumer;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
            TaskD solver = new TaskD();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskD {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            long n = in.readLong();
            int m = in.readInt();
            Modular mod = new Modular(1e9 + 7);
            int[][] dp = new int[m * 2][m];
            Arrays.fill(dp[0], 1);
            for (int i = 1; i < 2 * m; i++) {
                for (int j = 0; j < m - 1; j++) {
                    dp[i][j] = dp[i - 1][j + 1];
                }
                dp[i][m - 1] = mod.plus(dp[i - 1][m - 1], dp[i - 1][0]);
            }
            ModLinearFeedbackShiftRegister lfsr = new ModLinearFeedbackShiftRegister(mod, 2 * m);
            for (int i = 0; i < 2 * m; i++) {
                lfsr.add(dp[i][0]);
            }
            IntList p = new IntList(lfsr.length() + 1);
            for (int i = 0; i < lfsr.length(); i++) {
                p.add(mod.valueOf(-lfsr.codeAt(lfsr.length() - i)));
            }
            p.add(1);

            IntList remainder = new IntList(m * 2);
            Polynomials.module(n, p, remainder, new Power(mod));

            long ans = 0;
            for (int i = 0; i < remainder.size(); i++) {
                ans = mod.plus(ans, mod.mul(remainder.get(i), dp[i][0]));
            }

            out.println(ans);
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

        public int plus(long x, long y) {
            x = valueOf(x);
            y = valueOf(y);
            return valueOf(x + y);
        }

        public int subtract(int x, int y) {
            return valueOf(x - y);
        }

        public String toString() {
            return "mod " + m;
        }

    }

    static class ModLinearFeedbackShiftRegister {
        private IntList cm;
        int m = -1;
        int dm;
        private IntList cn;
        private IntList buf;
        private IntList seq;
        private Modular mod;
        private Power pow;

        public ModLinearFeedbackShiftRegister(Modular mod, int cap) {
            cm = new IntList(cap + 1);
            cn = new IntList(cap + 1);
            seq = new IntList(cap + 1);
            buf = new IntList(cap + 1);
            cn.add(1);

            this.mod = mod;
            this.pow = new Power(mod);
        }

        public ModLinearFeedbackShiftRegister(Modular mod) {
            this(mod, 0);
        }

        private int estimateDelta() {
            int n = seq.size() - 1;
            int ans = 0;
            int[] cnData = cn.getData();
            int[] seqData = seq.getData();
            for (int i = 0, until = cn.size(); i < until; i++) {
                ans = mod.plus(ans, mod.mul(cnData[i], seqData[n - i]));
            }
            return ans;
        }

        public void add(int x) {
            x = mod.valueOf(x);
            int n = seq.size();

            seq.add(x);
            int dn = estimateDelta();
            if (dn == 0) {
                return;
            }

            if (m < 0) {
                cm.clear();
                cm.addAll(cn);
                dm = dn;
                m = n;

                cn.expandWith(0, n + 2);
                return;
            }

            int ln = cn.size() - 1;
            int len = Math.max(ln, n + 1 - ln);
            buf.clear();
            buf.addAll(cn);
            buf.expandWith(0, len + 1);

            int factor = mod.mul(dn, pow.inverse(dm));

            int[] bufData = buf.getData();
            int[] cmData = cm.getData();
            for (int i = n - m, until = n - m + cm.size(); i < until; i++) {
                bufData[i] = mod.subtract(bufData[i], mod.mul(factor, cmData[i - (n - m)]));
            }

            if (cn.size() < buf.size()) {
                IntList tmp = cm;
                cm = cn;
                cn = tmp;
                m = n;
                dm = dn;
            }
            {
                IntList tmp = cn;
                cn = buf;
                buf = tmp;
            }


        }

        public int length() {
            return cn.size() - 1;
        }

        public String toString() {
            return cn.toString();
        }

        public int codeAt(int i) {
            return mod.valueOf(-cn.get(i));
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

    static class IntList {
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

        public void add(int x) {
            ensureSpace(size + 1);
            data[size++] = x;
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
            if (!(obj instanceof IntList)) {
                return false;
            }
            IntList other = (IntList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

    }

    static class Buffer<T> {
        private Deque<T> deque = new ArrayDeque<>();
        private Supplier<T> supplier;
        private Consumer<T> cleaner;

        public Buffer(Supplier<T> supplier) {
            this(supplier, (x) -> {
            });
        }

        public Buffer(Supplier<T> supplier, Consumer<T> cleaner) {
            this.supplier = supplier;
            this.cleaner = cleaner;
        }

        public T alloc() {
            return deque.isEmpty() ? supplier.get() : deque.removeFirst();
        }

        public void release(T e) {
            cleaner.accept(e);
            deque.addLast(e);
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

        public long readLong() {
            int sign = 1;

            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+' ? 1 : -1;
                next = read();
            }

            long val = 0;
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

        public static void mul(IntList a, IntList b, IntList c, Modular mod) {
            int rA = rankOf(a);
            int rB = rankOf(b);
            c.clear();
            c.expandWith(0, rA + rB + 1);
            int[] aData = a.getData();
            int[] bData = b.getData();
            int[] cData = c.getData();
            for (int i = 0; i <= rA; i++) {
                for (int j = 0; j <= rB; j++) {
                    cData[i + j] = mod.plus(cData[i + j], mod.mul(aData[i], bData[j]));
                }
            }
        }

        public static void divide(IntList a, IntList b, IntList c, IntList remainder, Power pow) {
            Modular mod = pow.getModular();
            int rA = rankOf(a);
            int rB = rankOf(b);

            if (rA < rB) {
                c.clear();
                c.add(0);
                remainder.clear();
                remainder.addAll(a);
                return;
            }

            int rC = Math.max(0, rA - rB);
            c.clear();
            c.expandWith(0, rC + 1);
            remainder.clear();
            remainder.addAll(a);

            int[] bData = b.getData();
            int[] cData = c.getData();
            int[] rData = remainder.getData();

            int inv = pow.inverse(b.get(rB));
            for (int i = rA, j = rC; i >= rB; i--, j--) {
                if (rData[i] == 0) {
                    continue;
                }
                int factor = mod.mul(-rData[i], inv);
                cData[j] = mod.valueOf(-factor);
                for (int k = rB; k >= 0; k--) {
                    rData[k + j] = mod.plus(rData[k + j], mod.mul(factor, bData[k]));
                }
            }

            normalize(remainder);
        }

        public static void module(long k, IntList p, IntList remainder, Power pow) {
            int rP = rankOf(p);
            if (rP == 0) {
                remainder.clear();
                remainder.add(0);
                return;
            }

            IntList a = listBuffer.alloc();
            IntList c = listBuffer.alloc();

            module(k, a, p, c, remainder, rP, pow);

            listBuffer.release(a);
            listBuffer.release(c);
        }

        private static void module(long k, IntList a, IntList b, IntList c, IntList remainder, int rb, Power pow) {
            Modular mod = pow.getModular();
            if (k < rb) {
                remainder.clear();
                remainder.expandWith(0, (int) k + 1);
                remainder.set((int) k, 1);
                return;
            }
            module(k / 2, a, b, c, remainder, rb, pow);
            mul(remainder, remainder, a, mod);
            if (k % 2 == 1) {
                int ra = rankOf(a);
                a.expandWith(0, ra + 2);
                int[] aData = a.getData();
                for (int i = ra; i >= 0; i--) {
                    aData[i + 1] = aData[i];
                }
                aData[0] = 0;
            }
            divide(a, b, c, remainder, pow);
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

    static class Power {
        final Modular modular;

        public Modular getModular() {
            return modular;
        }

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
}