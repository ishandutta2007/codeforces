import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.io.IOException;
import java.lang.reflect.Field;
import java.nio.charset.StandardCharsets;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.util.Comparator;
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
            EGregorAndTheTwoPainters solver = new EGregorAndTheTwoPainters();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class EGregorAndTheTwoPainters {
        Debug debug = new Debug(false);
        int inf = (int) 3e5;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int m = in.ri();
            int x = in.ri();
            int[] a = in.ri(n);
            int[] b = in.ri(m);
            int[] na = na(a);
            int[] nb = na(b);

            debug.debugArray("na", na);
            debug.debugArray("nb", nb);
            Item[] aItems = new Item[n];
            Item[] bItems = new Item[m];
            for (int i = 0; i < n; i++) {
                aItems[i] = new Item(na[i], a[i], 0);
            }
            for (int i = 0; i < m; i++) {
                bItems[i] = new Item(nb[i], b[i], 1);
            }
            Item[] mix = new Item[n + m];
            System.arraycopy(aItems, 0, mix, 0, n);
            System.arraycopy(bItems, 0, mix, n, m);
            Arrays.sort(mix, Comparator.<Item>comparingInt(y -> y.na - y.a).reversed());
            IntegerBIT[] bit = new IntegerBIT[2];
            for (int i = 0; i < 2; i++) {
                bit[i] = new IntegerBIT(inf);
            }
            long ans = 0;
            for (Item item : mix) {
                int L = x - item.na + 1;
                int R = x - item.a;
                L = Math.max(1, L);
                if (L <= R) {
                    ans += bit[item.type ^ 1].query(L, R);
                }
                bit[item.type].update(item.a, 1);
            }
            out.println(ans);
        }

        public int[] na(int[] a) {
            int n = a.length;
            IntegerDeque dq = new IntegerDequeImpl(n);
            int[] left = new int[n];
            int[] right = new int[n];
            for (int i = 0; i < n; i++) {
                while (!dq.isEmpty() && a[dq.peekLast()] > a[i]) {
                    dq.removeLast();
                }
                left[i] = dq.isEmpty() ? -1 : dq.peekLast();
                dq.addLast(i);
            }
            dq.clear();
            for (int i = n - 1; i >= 0; i--) {
                while (!dq.isEmpty() && a[dq.peekLast()] >= a[i]) {
                    dq.removeLast();
                }
                right[i] = dq.isEmpty() ? n : dq.peekLast();
                dq.addLast(i);
            }
            RMQBeta rmq = new RMQBeta(n, (i, j) -> -Integer.compare(a[i], a[j]));
            int[] ans = new int[n];
            for (int i = 0; i < n; i++) {
                ans[i] = inf;
                if (left[i] >= 0) {
                    ans[i] = Math.min(ans[i], a[rmq.query(left[i] + 1, i)]);
                }
                if (right[i] < n) {
                    ans[i] = Math.min(ans[i], a[rmq.query(i, right[i] - 1)]);
                }
            }
            return ans;
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

        public FastOutput append(long c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(long c) {
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

    static interface IntToIntegerFunction {
        int apply(int x);

    }

    static class IntegerDequeImpl implements IntegerDeque {
        private int[] data;
        private int bpos;
        private int epos;
        private static final int[] EMPTY = new int[0];
        private int n;

        public IntegerDequeImpl(int cap) {
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
            bpos = 0;
            epos = 0;
            n = cap;
        }

        private void expandSpace(int len) {
            while (n < len) {
                n = Math.max(n + 10, n * 2);
            }
            int[] newData = new int[n];
            if (bpos <= epos) {
                if (bpos < epos) {
                    System.arraycopy(data, bpos, newData, 0, epos - bpos);
                }
            } else {
                System.arraycopy(data, bpos, newData, 0, data.length - bpos);
                System.arraycopy(data, 0, newData, data.length - bpos, epos);
            }
            epos = size();
            bpos = 0;
            data = newData;
        }

        public IntegerIterator iterator() {
            return new IntegerIterator() {
                int index = bpos;


                public boolean hasNext() {
                    return index != epos;
                }


                public int next() {
                    int ans = data[index];
                    index = IntegerDequeImpl.this.next(index);
                    return ans;
                }
            };
        }

        public int removeLast() {
            int ans = data[last(epos)];
            epos = last(epos);
            return ans;
        }

        public void addLast(int x) {
            ensureMore();
            data[epos] = x;
            epos = next(epos);
        }

        public int peekLast() {
            return data[last(epos)];
        }

        public void clear() {
            bpos = epos = 0;
        }

        private int last(int x) {
            return (x == 0 ? n : x) - 1;
        }

        private int next(int x) {
            return x + 1 >= n ? 0 : x + 1;
        }

        private void ensureMore() {
            if (next(epos) == bpos) {
                expandSpace(n + 1);
            }
        }

        public int size() {
            int ans = epos - bpos;
            if (ans < 0) {
                ans += data.length;
            }
            return ans;
        }

        public boolean isEmpty() {
            return bpos == epos;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (IntegerIterator iterator = iterator(); iterator.hasNext(); ) {
                builder.append(iterator.next()).append(' ');
            }
            return builder.toString();
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int floorDiv(int a, int b) {
            return a < 0 ? -ceilDiv(-a, b) : a / b;
        }

        public static int ceilDiv(int a, int b) {
            if (a < 0) {
                return -floorDiv(-a, b);
            }
            int c = a / b;
            if (c * b < a) {
                return c + 1;
            }
            return c;
        }

    }

    static interface IntegerDeque extends IntegerStack {
    }

    static interface IntegerIterator {
        boolean hasNext();

        int next();

    }

    static interface IntegerComparator {
        public int compare(int a, int b);

    }

    static interface IntegerStack {
        void addLast(int x);

        int removeLast();

        int peekLast();

        boolean isEmpty();

        void clear();

    }

    static class IntegerSparseTable {
        private int[][] st;
        private IntegerBinaryFunction merger;
        int m;

        public void init(int length, IntToIntegerFunction function, IntegerBinaryFunction merger) {
            this.merger = merger;
            for (int i = 0; i < length; i++) {
                st[0][i] = function.apply(i);
            }
            for (int i = 0; i < m; i++) {
                int interval = 1 << i;
                for (int j = 0; j < length; j++) {
                    if (j + interval < length) {
                        st[i + 1][j] = merge(st[i][j], st[i][j + interval]);
                    } else {
                        st[i + 1][j] = st[i][j];
                    }
                }
            }
        }

        public IntegerSparseTable(int length) {
            m = Log2.floorLog(length);
            st = new int[m + 1][length];
        }

        public IntegerSparseTable(int length, IntToIntegerFunction function, IntegerBinaryFunction merger) {
            this(length);
            init(length, function, merger);
        }

        private int merge(int a, int b) {
            return merger.apply(a, b);
        }

        public int query(int left, int right) {
            int queryLen = right - left + 1;
            int bit = Log2.floorLog(queryLen);
            // x + 2^bit == right + 1
            // So x should be right + 1 - 2^bit - left=queryLen - 2^bit
            return merge(st[bit][left], st[bit][right + 1 - (1 << bit)]);
        }

        public String toString() {
            return Arrays.toString(st[0]);
        }

    }

    static class Log2 {
        public static int floorLog(int x) {
            if (x <= 0) {
                throw new IllegalArgumentException();
            }
            return 31 - Integer.numberOfLeadingZeros(x);
        }

    }

    static interface IntegerBinaryFunction {
        int apply(int a, int b);

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

    }

    static class IntegerBIT {
        private int[] data;
        private int n;

        public IntegerBIT(int n) {
            this.n = n;
            data = new int[n + 1];
        }

        public int query(int i) {
            i = Math.min(i, n);
            int sum = 0;
            for (; i > 0; i -= i & -i) {
                sum += data[i];
            }
            return sum;
        }

        public int query(int l, int r) {
            return query(r) - query(l - 1);
        }

        public void update(int i, int mod) {
            if (i <= 0) {
                return;
            }
            for (; i <= n; i += i & -i) {
                data[i] += mod;
            }
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 1; i <= n; i++) {
                builder.append(query(i) - query(i - 1)).append(' ');
            }
            return builder.toString();
        }

    }

    static class Debug {
        private boolean offline;
        private PrintStream out = System.err;

        public Debug(boolean enable) {
            offline = enable && System.getSecurityManager() == null;
        }

        public Debug debugArray(String name, int[] matrix) {
            if (offline) {
                debug(name, Arrays.toString(matrix));
            }
            return this;
        }

        public Debug debug(String name, String x) {
            if (offline) {
                out.printf("%s=%s", name, x);
                out.println();
            }
            return this;
        }

    }

    static class Bits {
        private Bits() {
        }

        public static int set(int x, int i) {
            return x | (1 << i);
        }

        public static int clear(int x, int i) {
            return x & (~(1 << i));
        }

        public static int highestOneBitOffset(int x) {
            return 31 - Integer.numberOfLeadingZeros(x);
        }

        public static int tailIntMask(int n) {
            if (n == 0) {
                return 0;
            }
            return -1 << (32 - n);
        }

    }

    static class RMQBeta {
        int n;
        IntegerComparator comp;
        static int shift = 5;
        static int blockSize = 1 << shift;
        static int andMask = blockSize - 1;
        int[] minIndices;
        int[] toLeft;
        IntegerSparseTable st;

        private int min(int a, int b) {
            return comp.compare(a, b) <= 0 ? a : b;
        }

        public void init(int n, IntegerComparator comp) {
            this.comp = comp;
            int considerPart = ((n - 1) >>> shift) + 1;
            Arrays.fill(minIndices, 0, considerPart, -1);
            for (int i = 0; i < n; i++) {
                int to = i >>> shift;
                if (minIndices[to] == -1 ||
                        comp.compare(minIndices[to], i) > 0) {
                    minIndices[to] = i;
                }
            }
            st.init(considerPart, i -> minIndices[i], (a, b) -> comp.compare(a, b) <= 0 ? a : b);
            int mask = 0;
            for (int i = 0; i < n; i++) {
                if ((i & andMask) == 0) {
                    mask = 0;
                }
                int b = i >>> shift;
                while (mask != 0) {
                    int head = Bits.highestOneBitOffset(mask);
                    if (comp.compare(i, (b << shift) | head) <= 0) {
                        mask = Bits.clear(mask, head);
                    } else {
                        break;
                    }
                }
                mask = Bits.set(mask, i & andMask);
                toLeft[i] = mask;
            }
        }

        public RMQBeta(int n, IntegerComparator comp) {
            this(n);
            init(n, comp);
        }

        public RMQBeta(int n) {
            this.n = n;
            minIndices = new int[DigitUtils.ceilDiv(n, blockSize)];
            st = new IntegerSparseTable(minIndices.length);
            toLeft = new int[n];
        }

        public int query(int l, int r) {
            assert l <= r;
            int bl = l >>> shift;
            int br = r >>> shift;
            int tl = l & andMask;
//        int tr = r & andMask;
            if (bl == br) {
                return Integer.numberOfTrailingZeros(toLeft[r] & Bits.tailIntMask(32 - tl)) | (bl << shift);
            }
            int res1 = Integer.numberOfTrailingZeros(toLeft[(bl << shift) | andMask] & Bits.tailIntMask(32 - tl)) | (bl << shift);
            int res2 = Integer.numberOfTrailingZeros(toLeft[r]) | (br << shift);
            int best = min(res1, res2);
            if (bl + 1 < br) {
                best = min(best, st.query(bl + 1, br - 1));
            }
            return best;
        }

    }

    static class Item {
        int na;
        int a;
        int type;

        public Item(int na, int a, int type) {
            this.na = na;
            this.a = a;
            this.type = type;
        }

    }
}