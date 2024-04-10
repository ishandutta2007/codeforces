import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.function.IntPredicate;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.IOException;
import java.lang.reflect.Field;
import java.nio.charset.StandardCharsets;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 29);
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
            BXorOf3 solver = new BXorOf3();
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                solver.solve(i, in, out);
            out.close();
        }
    }

    static class BXorOf3 {
        int[] a;
        IntegerArrayList ops = new IntegerArrayList();

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            a = in.ri(n);
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum ^= a[i];
            }
            if (sum == 1) {
                out.println("NO");
                return;
            }
            ops.clear();
            if (n % 2 == 1) {
                solve(a, 0, n - 1);
            } else {
                BitPreSum ps = new BitPreSum(n);
                ps.init(n, i -> a[i] == 1);
                boolean find = false;
                for (int i = 0; i < n; i += 2) {
                    if (ps.prefix(i) % 2 == 0) {
                        solve(a, 0, i);
                        solve(a, i + 1, n - 1);
                        find = true;
                        break;
                    }
                }
                if (!find) {
                    out.println("NO");
                    return;
                }
            }
            out.println("YES");
            out.println(ops.size());
            for (int op : ops.toArray()) {
                out.append(op + 1).append(' ');
            }
            for (int i = 0; i < n; i++) {
                assert a[i] == 0;
            }

            out.println();
        }

        public void solve(int[] a, int l, int r) {
            if (l > r) {
                return;
            }
            assert (r - l + 1) % 2 == 1;
            for (int i = l; i + 2 <= r; i += 2) {
                op(i);
            }
            assert a[r] == 0;
            for (int i = r - 2; i >= l; i -= 2) {
                op(i);
            }
        }

        public void op(int i) {
            assert i >= 0 && i + 2 < a.length;
            int xor = a[i] ^ a[i + 1] ^ a[i + 2];
            a[i] = a[i + 1] = a[i + 2] = xor;
            ops.add(i);
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private static final int THRESHOLD = 32 << 10;
        private OutputStream writer;
        private StringBuilder cache = new StringBuilder(THRESHOLD * 2);
        private static Field stringBuilderValueField;
        private char[] charBuf = new char[THRESHOLD * 2];
        private byte[] byteBuf = new byte[THRESHOLD * 2];

        static {
            try {
                stringBuilderValueField = StringBuilder.class.getSuperclass().getDeclaredField("value");
                stringBuilderValueField.setAccessible(true);
            } catch (Exception e) {
                stringBuilderValueField = null;
            }
            stringBuilderValueField = null;
        }

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

        private void afterWrite() {
            if (cache.length() < THRESHOLD) {
                return;
            }
            flush();
        }

        public FastOutput(OutputStream writer) {
            this.writer = writer;
        }

        public FastOutput append(char c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(int c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(String c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(String c) {
            return append(c).println();
        }

        public FastOutput println(int c) {
            return append(c).println();
        }

        public FastOutput println() {
            return append('\n');
        }

        public FastOutput flush() {
            try {
                if (stringBuilderValueField != null) {
                    try {
                        byte[] value = (byte[]) stringBuilderValueField.get(cache);
                        writer.write(value, 0, cache.length());
                    } catch (Exception e) {
                        stringBuilderValueField = null;
                    }
                }
                if (stringBuilderValueField == null) {
                    int n = cache.length();
                    if (n > byteBuf.length) {
                        //slow
                        writer.write(cache.toString().getBytes(StandardCharsets.UTF_8));
//                writer.append(cache);
                    } else {
                        cache.getChars(0, n, charBuf, 0);
                        for (int i = 0; i < n; i++) {
                            byteBuf[i] = (byte) charBuf[i];
                        }
                        writer.write(byteBuf, 0, n);
                    }
                }
                writer.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
            return this;
        }

        public void close() {
            flush();
            try {
                writer.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

        public String toString() {
            return cache.toString();
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

    static class IntegerArrayList implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public IntegerArrayList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public IntegerArrayList(int[] data) {
            this(0);
            addAll(data);
        }

        public IntegerArrayList(IntegerArrayList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public IntegerArrayList() {
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

        public void addAll(IntegerArrayList list) {
            addAll(list.data, 0, list.size);
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
            if (!(obj instanceof IntegerArrayList)) {
                return false;
            }
            IntegerArrayList other = (IntegerArrayList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Integer.hashCode(data[i]);
            }
            return h;
        }

        public IntegerArrayList clone() {
            IntegerArrayList ans = new IntegerArrayList();
            ans.addAll(this);
            return ans;
        }

    }

    static class FastInput {
        private final InputStream is;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 13);
        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;

        public FastInput(InputStream is) {
            this.is = is;
        }

        public void populate(int[] data) {
            for (int i = 0; i < data.length; i++) {
                data[i] = readInt();
            }
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

        public String next() {
            return readString();
        }

        public int ri() {
            return readInt();
        }

        public int[] ri(int n) {
            int[] ans = new int[n];
            populate(ans);
            return ans;
        }

        public int readInt() {
            boolean rev = false;

            skipBlank();
            if (next == '+' || next == '-') {
                rev = next == '-';
                next = read();
            }

            int val = 0;
            while (next >= '0' && next <= '9') {
                val = val * 10 - next + '0';
                next = read();
            }

            return rev ? val : -val;
        }

        public String readString(StringBuilder builder) {
            skipBlank();

            while (next > 32) {
                builder.append((char) next);
                next = read();
            }

            return builder.toString();
        }

        public String readString() {
            defaultStringBuf.setLength(0);
            return readString(defaultStringBuf);
        }

    }

    static class Bits {
        private Bits() {
        }

        public static int get(long x, int i) {
            return (int) ((x >>> i) & 1);
        }

        public static long headLongMask(int n) {
            if (n == 0) {
                return 0;
            }
            return -1L >>> (64 - n);
        }

    }

    static class BitPreSum {
        private long[] bits;
        private int[] ps;
        private int n;

        public BitPreSum(int n) {
            bits = new long[(n + 63) / 64];
            ps = new int[(n + 63) / 64];
            this.n = n;
        }

        public void set(int i) {
            bits[i >> 6] |= 1L << (i & 63);
            ps[i >> 6]++;
        }

        public void clear(int n) {
            this.n = n;
            Arrays.fill(bits, 0, (n + 63) / 64, 0);
            Arrays.fill(ps, 0, (n + 63) / 64, 0);
        }

        public void build() {
            for (int i = 1, to = (n + 63) / 64; i < to; i++) {
                ps[i] += ps[i - 1];
            }
        }

        public void init(int n, IntPredicate predicate) {
            clear(n);
            for (int i = 0; i < n; i++) {
                if (predicate.test(i)) {
                    set(i);
                }
            }
            build();
        }

        public int prefix(int m) {
            if (m > n) {
                m = n - 1;
            }
            if (m < 0) {
                return 0;
            }
            int head = m >> 6;
            int tail = m & 63;
            return (head == 0 ? 0 : ps[head - 1]) + Long.bitCount(bits[head] & Bits.headLongMask(tail + 1));
        }

        public String toString() {
            List<Integer> list = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                list.add(Bits.get(bits[i >> 6], i & 63));
            }
            return list.toString();
        }

    }
}