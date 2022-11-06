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
            DIsolation solver = new DIsolation();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DIsolation {
        static Modular mod = new Modular(998244353);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int k = in.readInt();
            int[] a = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                a[i] = in.readInt();
            }
            int[] registries = new int[n + 1];
            int[] last = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                last[i] = registries[a[i]];
                registries[a[i]] = i;
            }

            int[] dp = new int[n + 1];
            BlockManager bm = new BlockManager(n, k);
            bm.append(0, new Element(0, 1));

            for (int i = 1; i <= n; i++) {
                if (last[i] == 0) {
                    bm.add(0, i - 1, 1);
                } else {
                    int l = last[last[i]] + 1;
                    int m = last[i];
                    bm.add(l - 1, m - 1, -1);
                    bm.add(m, i - 1, 1);
                }
                dp[i] = mod.valueOf(bm.sumOf());
                bm.append(i, new Element(0, dp[i]));
            }

            out.println(dp[n]);
        }

    }

    static class Element {
        int k;
        int val;

        public Element(int k, int val) {
            this.k = k;
            this.val = val;
        }

    }

    static interface LongEntryIterator {
        boolean hasNext();

        void next();

        long getEntryKey();

        long getEntryValue();

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

        public int valueOf(long x) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            return (int) x;
        }

        public String toString() {
            return "mod " + m;
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

    static class BlockManager {
        Block[] blocks;
        int bSize;

        public BlockManager(int n, int k) {
            bSize = (int) Math.ceil(Math.sqrt(n + 1));
            int m = DigitUtils.ceilDiv(n + 1, bSize);
            blocks = new Block[m];
            for (int i = 0; i < m; i++) {
                blocks[i] = new Block(bSize, k);
            }
        }

        public void append(int i, Element e) {
            blocks[i / bSize].append(e);
        }

        public void add(int ll, int rr, int x) {
            for (int i = 0; i < blocks.length; i++) {
                int l = i * bSize;
                int r = l + bSize - 1;
                if (r < ll || l > rr) {
                    continue;
                }
                if (ll <= l && r <= rr) {
                    blocks[i].add(x);
                } else {
                    blocks[i].add(Math.max(ll, l) - l, Math.min(rr, r) - l, x);
                }
            }
        }

        public long sumOf() {
            long ans = 0;
            for (Block b : blocks) {
                ans += b.sum;
            }
            return ans;
        }

    }

    static class Block {
        Element[] elements;
        LongHashMap map;
        int size;
        int add;
        long sum;
        int k;

        public Block(int n, int k) {
            elements = new Element[n];
            this.k = k;
            map = new LongHashMap(n, true);
        }

        public void add(int x) {
            if (x > 0) {
                sum -= map.getOrDefault(k - add, 0);
                add++;
            } else {
                add--;
                sum += map.getOrDefault(k - add, 0);
            }
        }

        public void add(int l, int r, int x) {
            pushDown();
            for (int i = l; i <= r; i++) {
                map.put(elements[i].k, map.getOrDefault(elements[i].k, 0) - elements[i].val);
                if (x > 0) {
                    if (elements[i].k == k) {
                        sum -= elements[i].val;
                    }
                    elements[i].k++;
                } else {
                    elements[i].k--;
                    if (elements[i].k == k) {
                        sum += elements[i].val;
                    }
                }
                map.put(elements[i].k, map.getOrDefault(elements[i].k, 0) + elements[i].val);
            }
        }

        private void pushDown() {
            if (add != 0) {
                map.clear();
                for (int i = 0; i < size; i++) {
                    elements[i].k += add;
                    map.put(elements[i].k, map.getOrDefault(elements[i].k, 0L) + elements[i].val);
                }
                add = 0;
            }
        }

        public void append(Element e) {
            pushDown();
            elements[size++] = e;
            map.put(e.k, map.getOrDefault(e.k, 0) + e.val);
            if (e.k <= k) {
                sum += e.val;
            }
        }

    }

    static class LongHashMap {
        private int[] slot;
        private int[] next;
        private long[] keys;
        private long[] values;
        private int alloc;
        private boolean[] removed;
        private int mask;
        private int size;
        private boolean rehash;

        public LongHashMap(int cap, boolean rehash) {
            this.mask = (1 << (32 - Integer.numberOfLeadingZeros(cap - 1))) - 1;
            slot = new int[mask + 1];
            next = new int[cap + 1];
            keys = new long[cap + 1];
            values = new long[cap + 1];
            removed = new boolean[cap + 1];
            this.rehash = rehash;
        }

        private void doubleCapacity() {
            int newSize = Math.max(next.length + 10, next.length * 2);
            next = Arrays.copyOf(next, newSize);
            keys = Arrays.copyOf(keys, newSize);
            values = Arrays.copyOf(values, newSize);
            removed = Arrays.copyOf(removed, newSize);
        }

        public void alloc() {
            alloc++;
            if (alloc >= next.length) {
                doubleCapacity();
            }
            next[alloc] = 0;
            removed[alloc] = false;
            size++;
        }

        private void rehash() {
            int[] newSlots = new int[Math.max(16, slot.length * 2)];
            int newMask = newSlots.length - 1;
            for (int i = 0; i < slot.length; i++) {
                if (slot[i] == 0) {
                    continue;
                }
                int head = slot[i];
                while (head != 0) {
                    int n = next[head];
                    int s = hash(keys[head]) & newMask;
                    next[head] = newSlots[s];
                    newSlots[s] = head;
                    head = n;
                }
            }
            this.slot = newSlots;
            this.mask = newMask;
        }

        private int hash(long x) {
            int h = Long.hashCode(x);
            return h ^ (h >>> 16);
        }

        public void put(long x, long y) {
            put(x, y, true);
        }

        public void put(long x, long y, boolean cover) {
            int h = hash(x);
            int s = h & mask;
            if (slot[s] == 0) {
                alloc();
                slot[s] = alloc;
                keys[alloc] = x;
                values[alloc] = y;
            } else {
                int index = findIndexOrLastEntry(s, x);
                if (keys[index] != x) {
                    alloc();
                    next[index] = alloc;
                    keys[alloc] = x;
                    values[alloc] = y;
                } else if (cover) {
                    values[index] = y;
                }
            }
            if (rehash && size >= slot.length) {
                rehash();
            }
        }

        public long getOrDefault(long x, long def) {
            int h = hash(x);
            int s = h & mask;
            if (slot[s] == 0) {
                return def;
            }
            int index = findIndexOrLastEntry(s, x);
            return keys[index] == x ? values[index] : def;
        }

        private int findIndexOrLastEntry(int s, long x) {
            int iter = slot[s];
            while (keys[iter] != x) {
                if (next[iter] != 0) {
                    iter = next[iter];
                } else {
                    return iter;
                }
            }
            return iter;
        }

        public void clear() {
            alloc = 0;
            Arrays.fill(slot, 0);
            size = 0;
        }

        public LongEntryIterator iterator() {
            return new LongEntryIterator() {
                int index = 1;
                int readIndex = -1;


                public boolean hasNext() {
                    while (index <= alloc && removed[index]) {
                        index++;
                    }
                    return index <= alloc;
                }


                public long getEntryKey() {
                    return keys[readIndex];
                }


                public long getEntryValue() {
                    return values[readIndex];
                }


                public void next() {
                    if (!hasNext()) {
                        throw new IllegalStateException();
                    }
                    readIndex = index;
                    index++;
                }
            };
        }

        public String toString() {
            LongEntryIterator iterator = iterator();
            StringBuilder builder = new StringBuilder("{");
            while (iterator.hasNext()) {
                iterator.next();
                builder.append(iterator.getEntryKey()).append("->").append(iterator.getEntryValue()).append(',');
            }
            if (builder.charAt(builder.length() - 1) == ',') {
                builder.setLength(builder.length() - 1);
            }
            builder.append('}');
            return builder.toString();
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
}