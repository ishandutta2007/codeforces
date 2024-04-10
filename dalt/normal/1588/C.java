import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.PrintStream;
import java.io.IOException;
import java.lang.reflect.Field;
import java.nio.charset.StandardCharsets;
import java.io.UncheckedIOException;
import java.util.List;
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
            CGameWithStones solver = new CGameWithStones();
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                solver.solve(i, in, out);
            out.close();
        }
    }

    static class CGameWithStones {
        LongHashMap map = new LongHashMap((int) 1e6, false);
        Query q = new Query();
        Debug debug = new Debug(false);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int[] a = in.ri(n);
            long[] ps = new long[n];
            for (int i = 0; i < n; i++) {
                if (i > 0) {
                    ps[i] = -ps[i - 1];
                }
                ps[i] += a[i];
            }
            long inf = (long) 1e18;
            long[] p0 = ps.clone();
            long[] p1 = ps.clone();
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    p1[i] = inf;
                } else {
                    p0[i] = inf;
                }
            }
            Segment st = new Segment(0, n - 1, i -> ps[i]);
            List<Event> E0 = new ArrayList<>(n);
            List<Event> E1 = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                debug.debug("i", i);
                long prev = i > 0 ? ps[i - 1] : 0;
                long d0, d1;
                if (i % 2 == 0) {
                    d0 = -prev;
                    d1 = prev;
                } else {
                    d1 = -prev;
                    d0 = prev;
                }
                q.init(d0, d1);
                st.search(i, n - 1, 0, n - 1, q);
                if (q.rightest < i) {
                    continue;
                }
                int l = i;
                int r = q.rightest;
                debug.debug("l", l);
                debug.debug("r", r);
                E0.add(new Event(l - 1, -1, d0));
                E0.add(new Event(r, 1, d0));
                E1.add(new Event(l - 1, -1, d1));
                E1.add(new Event(r, 1, d1));
            }
            map.clear();

            long ans = 0;
            E0.sort(Comparator.comparingInt(x -> x.l));
            E1.sort(Comparator.comparingInt(x -> x.l));
            for (int i = 0, iter = 0; i < n; i++) {
                if (i % 2 == 0) {
                    map.modify(ps[i], 1);
                }
                while (iter < E0.size() && E0.get(iter).l <= i) {
                    Event e = E0.get(iter++);
                    if (e.l == i) {
                        ans += map.getOrDefault(e.v, 0) * e.sigh;
                    }
                }
            }
            map.clear();
            for (int i = 0, iter = 0; i < n; i++) {
                if (i % 2 == 1) {
                    map.modify(ps[i], 1);
                }
                while (iter < E1.size() && E1.get(iter).l <= i) {
                    Event e = E1.get(iter++);
                    if (e.l == i) {
                        ans += map.getOrDefault(e.v, 0) * e.sigh;
                    }
                }
            }
            out.println(ans);
        }

    }

    static class Debug {
        private boolean offline;
        private PrintStream out = System.err;

        public Debug(boolean enable) {
            offline = enable && System.getSecurityManager() == null;
        }

        public Debug debug(String name, int x) {
            if (offline) {
                debug(name, "" + x);
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

    static class Segment implements Cloneable {
        private Segment left;
        private Segment right;
        static long inf = (long) 1e18;
        long min0;
        long min1;

        public void pushUp() {
            min0 = Math.min(left.min0, right.min0);
            min1 = Math.min(left.min1, right.min1);
        }

        public void pushDown() {
        }

        public Segment(int l, int r, IntToLongFunction func) {
            if (l < r) {
                int m = DigitUtils.floorAverage(l, r);
                left = new Segment(l, m, func);
                right = new Segment(m + 1, r, func);
                pushUp();
            } else {
                min0 = min1 = inf;
                if (l % 2 == 0) {
                    min0 = func.apply(l);
                } else {
                    min1 = func.apply(l);
                }
            }
        }

        private boolean enter(int L, int R, int l, int r) {
            return L <= l && R >= r;
        }

        private boolean leave(int L, int R, int l, int r) {
            return L > r || R < l;
        }

        public boolean search(int L, int R, int l, int r, Query q) {
            if (leave(L, R, l, r)) {
                return false;
            }
            if (enter(L, R, l, r) && q.update(min0, min1, r)) {
                return false;
            }
            if (l == r) {
                return true;
            }
            pushDown();
            int m = DigitUtils.floorAverage(l, r);
            if (!left.search(L, R, l, m, q)) {
                return right.search(L, R, m + 1, r, q);
            }
            return true;
        }

        private Segment deepClone() {
            Segment seg = clone();
            if (seg.left != null) {
                seg.left = seg.left.deepClone();
            }
            if (seg.right != null) {
                seg.right = seg.right.deepClone();
            }
            return seg;
        }

        protected Segment clone() {
            try {
                return (Segment) super.clone();
            } catch (CloneNotSupportedException e) {
                throw new RuntimeException(e);
            }
        }

        private void toString(StringBuilder builder) {
            if (left == null && right == null) {
                builder.append("val").append(",");
                return;
            }
            pushDown();
            left.toString(builder);
            right.toString(builder);
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            deepClone().toString(builder);
            if (builder.length() > 0) {
                builder.setLength(builder.length() - 1);
            }
            return builder.toString();
        }

    }

    static interface LongEntryIterator {
        boolean hasNext();

        void next();

        long getEntryKey();

        long getEntryValue();

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int floorAverage(int x, int y) {
            return (x & y) + ((x ^ y) >> 1);
        }

    }

    static class Event {
        int l;
        int sigh;
        long v;

        public Event(int l, int sign, long v) {
            this.l = l;
            this.sigh = sign;
            this.v = v;
        }

    }

    static class Hasher {
        private final long time = System.nanoTime() + System.currentTimeMillis() * 31L;

        public int shuffle(long z) {
            z += time;
            z = (z ^ (z >>> 33)) * 0x62a9d9ed799705f5L;
            return (int) (((z ^ (z >>> 28)) * 0xcb24d0a5c88c35b3L) >>> 32);
        }

        public int hash(long x) {
            return shuffle(x);
        }

    }

    static class Query {
        static long inf = (long) 1e18;
        long min0 = inf;
        long min1 = inf;
        long d0;
        long d1;
        int rightest = -1;

        void init(long d0, long d1) {
            min0 = min1 = inf;
            rightest = -1;
            this.d0 = d0;
            this.d1 = d1;
        }

        public boolean update(long min0, long min1, int rightest) {
            if (min0 < d0 || min1 < d1) {
                return false;
            }
            this.min0 = Math.min(this.min0, min0);
            this.min1 = Math.min(this.min1, min1);
            this.rightest = Math.max(this.rightest, rightest);
            return true;
        }

    }

    static interface IntToLongFunction {
        long apply(int x);

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
        private Hasher hasher = new Hasher();

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
            return hasher.hash(x);
        }

        public void modify(long x, long dy) {
            int h = hash(x);
            int s = h & mask;
            if (slot[s] == 0) {
                alloc();
                slot[s] = alloc;
                keys[alloc] = x;
                values[alloc] = dy;
            } else {
                int index = findIndexOrLastEntry(s, x);
                if (keys[index] != x) {
                    alloc();
                    next[index] = alloc;
                    keys[alloc] = x;
                    values[alloc] = dy;
                } else {
                    values[index] += dy;
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
            while (alloc > 0) {
                int h = hash(keys[alloc]);
                slot[h & mask] = 0;
                alloc--;
            }
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
}