import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.Random;
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
            DStrangeLCS solver = new DStrangeLCS();
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                solver.solve(i, in, out);
            out.close();
        }
    }

    static class DStrangeLCS {
        int charset = remake('Z') + 1;
        Debug debug = new Debug(false);
        LongHashMap map = new LongHashMap((int) 2e6, false);
        Comparator<E> comp = Comparator.<E>comparingLong(x -> x.a).thenComparing(x -> x.b);
        E buf = new E();
        List<E> allList = new ArrayList<>((int) 1e5);
        int[][][] next;
        char[][] s;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            s = new char[n][];
            next = new int[n][][];
            for (int i = 0; i < n; i++) {
                s[i] = in.rs().toCharArray();
                for (int j = 0; j < s[i].length; j++) {
                    s[i][j] = (char) remake(s[i][j]);
                }
                next[i] = next(s[i]);
            }

            allList.clear();
            for (int i = 0; i < charset; i++) {
                buf.init();
                dfs(0, n, i);
            }
            allList.sort(comp);
            E[] all = allList.toArray(new E[0]);

            map.clear();
            for (int i = 0; i < all.length; i++) {
                all[i].index = i;
                all[i].score = 1;
                all[i].prev = null;

                map.put(all[i].hash(), i);
            }


            for (E e : all) {
                for (int j = 0; j < charset; j++) {
                    buf.init();
                    boolean ok = true;
                    for (int k = 0; k < n && ok; k++) {
                        int to = next[k][e.get(k) + 1][j];
                        ok = to < s[k].length;
                        buf.set(k, to);
                    }
                    if (!ok) {
                        continue;
                    }
                    E obj = all[(int) map.get(buf.hash())];
                    if (obj.score < e.score + 1) {
                        obj.score = e.score + 1;
                        obj.prev = e;
                    }
                }
            }

            if (all.length == 0) {
                out.println(0);
                out.println();
                return;
            }
            E best = null;
            for (E e : all) {
                if (best == null || e.score > best.score) {
                    best = e;
                }
            }
            StringBuilder sb = new StringBuilder(charset * 2);
            while (best != null) {
                int v = s[0][best.get(0)];
                sb.append(goback(v));
                best = best.prev;
            }
            sb = sb.reverse();
            out.println(sb.length());
            out.println(sb);

            debug.debug("secondLevel", FastUniversalHashFunction0.numberOfInstance);
            debug.debug("numberOfHighestLevel", UniversalHashFunction.numberOfInstance);
        }

        public void dfs(int cur, int n, int c) {
            if (cur == n) {
                allList.add(buf.clone());
                return;
            }
            for (int iter = next[cur][0][c]; iter < s[cur].length; iter = next[cur][iter + 1][c]) {
                buf.set(cur, iter);
                dfs(cur + 1, n, c);
            }
        }

        public int[][] next(char[] s) {
            int n = s.length;
            int[][] next = new int[n + 1][];
            int[] prev = new int[charset];
            Arrays.fill(prev, n);
            next[n] = prev.clone();
            for (int i = n - 1; i >= 0; i--) {
                prev[s[i]] = i;
                next[i] = prev.clone();
            }
            return next;
        }

        public int remake(int x) {
            if ('a' <= x && x <= 'z') {
                return x - 'a';
            }
            return x - 'A' + 'z' - 'a' + 1;
        }

        public char goback(int x) {
            if (x < 'z' - 'a' + 1) {
                return (char) (x + 'a');
            } else {
                return (char) (x + 'A' - 'z' + 'a' - 1);
            }
        }

    }

    static class FastLongHash {
        static ILongModular modular = LongModular2305843009213693951.getInstance();
        static long mod = modular.getMod();
        long x = RandomWrapper.INSTANCE.nextLong(1, mod - 1);

        public long hash(long x0, long x1) {
            long ans = modular.mul(x1, x) + x0;
            if (ans >= mod) {
                ans -= mod;
            }
            return ans;
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

    static class E extends CloneSupportObject<E> {
        long a;
        long b;
        int index;
        int score;
        E prev;
        static FastLongHash fh = new FastLongHash();

        void init() {
            a = b = 0;
        }

        private int get(long x, int i) {
            return (int) ((x >>> (i << 3)) & 255);
        }

        private long set(long x, int i, long v) {
            i <<= 3;
            v &= 255;
            return (x & ~(255L << i)) | (v << i);
        }

        public int get(int i) {
            if (i < 6) {
                return get(a, i);
            }
            i -= 6;
            return get(b, i);
        }

        public void set(int i, int v) {
            if (i < 6) {
                a = set(a, i, v);
                return;
            }
            i -= 6;
            b = set(b, i, v);
        }

        long hash() {
            return fh.hash(a, b);
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

        public Debug debug(String name, long x) {
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

        public String rs() {
            return readString();
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

        public long get(long x) {
            return getOrDefault(x, 0);
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

    static class RandomWrapper {
        private Random random;
        public static final RandomWrapper INSTANCE = new RandomWrapper();

        public RandomWrapper() {
            this(new Random());
        }

        public RandomWrapper(Random random) {
            this.random = random;
        }

        public RandomWrapper(long seed) {
            this(new Random(seed));
        }

        public long nextLong(long l, long r) {
            return nextLong(r - l + 1) + l;
        }

        public long nextLong(long n) {
            return Math.round(random.nextDouble() * (n - 1));
        }

    }

    static class FastUniversalHashFunction0 implements HashFunction {
        public static long numberOfInstance = 0;

        private FastUniversalHashFunction0() {
        }

    }

    static interface HashFunction {
    }

    static interface ILongModular {
        long getMod();

        long mul(long a, long b);

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

        public FastOutput append(Object c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(int c) {
            return append(c).println();
        }

        public FastOutput println(Object c) {
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

    static abstract class CloneSupportObject<T> implements Cloneable {
        public T clone() {
            try {
                return (T) super.clone();
            } catch (CloneNotSupportedException e) {
                throw new RuntimeException(e);
            }
        }

    }

    static class LongModular2305843009213693951 implements ILongModular {
        private static long mod = 2305843009213693951L;
        private static final LongModular2305843009213693951 INSTANCE = new LongModular2305843009213693951();
        private static long mask = (1L << 32) - 1;

        private LongModular2305843009213693951() {
        }

        public static final LongModular2305843009213693951 getInstance() {
            return INSTANCE;
        }

        public long getMod() {
            return mod;
        }

        public long mul(long a, long b) {
            long l1 = a & mask;
            long h1 = (a >> 32) & mask;
            long l2 = b & mask;
            long h2 = (b >> 32) & mask;
            long l = l1 * l2;
            long m = l1 * h2 + l2 * h1;
            long h = h1 * h2;
            long ret = (l & mod) + (l >>> 61) + (h << 3) + (m >>> 29) + ((m << 35) >>> 3) + 1;
            ret = (ret & mod) + (ret >>> 61);
            ret = (ret & mod) + (ret >>> 61);
            return ret - 1;
        }

    }

    static interface LongEntryIterator {
        boolean hasNext();

        void next();

        long getEntryKey();

        long getEntryValue();

    }

    static class UniversalHashFunction implements HashFunction {
        public static int numberOfInstance = 0;
        private static ILongModular modular = LongModular2305843009213693951.getInstance();
        private static long mod = modular.getMod();
        long a;
        long b;

        {
            numberOfInstance++;
            upgrade();
        }

        public HashFunction upgrade() {
            this.a = RandomWrapper.INSTANCE.nextLong(1, mod - 1);
            this.b = RandomWrapper.INSTANCE.nextLong(0, mod - 1);
            return this;
        }

    }
}