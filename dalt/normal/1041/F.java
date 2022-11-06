

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.util.*;
import java.util.function.Supplier;

public class CFContest {
    public static void main(String[] args) throws Exception {
        boolean local = System.getProperty("ONLINE_JUDGE") == null;
        boolean async = false;

        Charset charset = Charset.forName("ascii");

        FastIO io = local ? new FastIO(new FileInputStream("D:\\DATABASE\\TESTCASE\\CFContest.in"), System.out, charset) : new FastIO(System.in, System.out, charset);
        Task task = new Task(io);

        if (async) {
            Thread t = new Thread(null, task, "dalt", 1 << 27);
            t.setPriority(Thread.MAX_PRIORITY);
            t.start();
            t.join();
        } else {
            task.run();
        }

        if (local) {
            io.cache.append("\n\n--memory -- \n" + ((Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()) >> 20) + "M");
        }

        io.flush();
    }

    public static class Task implements Runnable {
        final FastIO io;

        public Task(FastIO io) {
            this.io = io;
        }

        @Override
        public void run() {
            solve();
        }

        public void solve() {
            int n = io.readInt();
            io.readInt();

            int[] upPoints = new int[n];
            for (int i = 0; i < n; i++) {
                upPoints[i] = io.readInt();
            }

            int m = io.readInt();
            io.readInt();

            int[] downPoints = new int[m];
            for (int i = 0; i < m; i++) {
                downPoints[i] = io.readInt();
            }

            IntPoolLinkedHashMap.RewindableSupplier<IntPoolLinkedHashMap.Entry[]> entriesSupplier = new IntPoolLinkedHashMap.RewindableSupplier<IntPoolLinkedHashMap.Entry[]>() {
                IntPoolLinkedHashMap.Entry[] cache = new IntPoolLinkedHashMap.Entry[1 << 19];

                @Override
                public IntPoolLinkedHashMap.Entry[] get() {
                    return cache;
                }

                @Override
                public void rewind() {
                    Arrays.fill(cache, null);
                }
            };
            IntPoolLinkedHashMap.RewindableSupplier<IntPoolLinkedHashMap.Entry> entrySupplier = new IntPoolLinkedHashMap.RewindableSupplier<IntPoolLinkedHashMap.Entry>() {
                IntPoolLinkedHashMap.Entry[] cache = new IntPoolLinkedHashMap.Entry[300000];
                int head = 0;

                {
                    for (int i = 0, until = cache.length; i < until; i++) {
                        cache[i] = new IntPoolLinkedHashMap.Entry();
                    }
                }

                @Override
                public IntPoolLinkedHashMap.Entry get() {
                    cache[head].clear();
                    return cache[head++];
                }

                @Override
                public void rewind() {
                    head = 0;
                }
            };

            int max = 0;
            for (int i = 1; i <= 30; i++) {
                int bigBit = 1 << i;
                int littleBit = bigBit >> 1;
                int mask = bigBit - 1;

                entriesSupplier.rewind();
                entrySupplier.rewind();
                IntPoolLinkedHashMap map = new IntPoolLinkedHashMap(entriesSupplier, entrySupplier, null, null);

                for (int v : upPoints) {
                    int k = v & mask;
                    int cnt = map.getOrDefault(k, 0) + 1;
                    max = Math.max(max, cnt);
                    map.put(k, cnt);
                }
                for (int v : downPoints) {
                    int k = (v & mask) ^ littleBit;
                    int cnt = map.getOrDefault(k, 0) + 1;
                    max = Math.max(max, cnt);
                    map.put(k, cnt);
                }
            }


            {
                entriesSupplier.rewind();
                entrySupplier.rewind();
                IntPoolLinkedHashMap map = new IntPoolLinkedHashMap(entriesSupplier, entrySupplier, null, null);
                for (int v : upPoints) {
                    int k = v;
                    int cnt = map.getOrDefault(k, 0) + 1;
                    max = Math.max(max, cnt);
                    map.put(k, cnt);
                }
                for (int v : downPoints) {
                    int k = v;
                    int cnt = map.getOrDefault(k, 0) + 1;
                    max = Math.max(max, cnt);
                    map.put(k, cnt);
                }
            }

            io.cache.append(max);
        }

        public static int total(Integer v, List<Integer> a) {
            int index = Collections.binarySearch(a, v);
            if (index < 0) {
                index = -index - 1;
            } else {
                index++;
            }
            return a.size() - index;
        }
    }

    public static class IntPoolLinkedHashMap {
        public IntPoolLinkedHashMap(Supplier<Entry[]> slotSupplier, Supplier<Entry> entrySupplier, Hash hash, EqualChecker equalChecker) {
            this.slotSupplier = slotSupplier;
            this.entrySupplier = entrySupplier;
            this.hash = hash;
            this.equalChecker = equalChecker;

            if (this.slotSupplier == null) {
                this.slotSupplier = () -> new Entry[128];
            }
            if (this.entrySupplier == null) {
                this.entrySupplier = Entry::new;
            }
            if (this.hash == null) {
                this.hash = x -> x;
            }
            if (this.equalChecker == null) {
                this.equalChecker = (a, b) -> a == b;
            }

            this.slots = this.slotSupplier.get();
            if (slots.length != (slots.length & -slots.length)) {
                throw new IllegalStateException();
            }
            mask = slots.length - 1;

            linkedListHead = this.entrySupplier.get();
            linkedListHead.linkedListFormer = linkedListHead;
            linkedListHead.linkedListNext = linkedListHead;
        }

        public static class Entry {
            private Entry linkedListNext;
            private Entry linkedListFormer;
            private Entry slotNext;
            private int h;
            private int key;
            private int value;

            public void clear() {
                linkedListNext = null;
                linkedListFormer = null;
                slotNext = null;
                key = 0;
                value = 0;
                h = 0;
            }

            public int getKey() {
                return key;
            }

            public int getValue() {
                return value;
            }

            public int setValue(int value) {
                int old = this.value;
                this.value = value;
                return old;
            }
        }

        public static interface Hash<K> {
            int hash(int k);
        }

        public static interface EqualChecker<K> {
            boolean equal(int a, int b);
        }

        public static interface RewindableSupplier<T> extends Supplier<T> {
            void rewind();
        }

        public int get(int key) {
            return getOrDefault(key, 0);
        }

        private Entry searchSlot(int index, int h, int key) {
            Entry last = slots[index];
            while (last != null && (last.h != h || !equalChecker.equal(last.key, key))) {
                last = last.slotNext;
            }
            return last;
        }

        public int put(int key, int value) {
            int h = hash(key);
            int slotNum = h & mask;

            Entry entry = searchSlot(slotNum, h, key);
            if (entry != null) {
                int old = entry.value;
                entry.value = value;
                return old;
            }

            entry = new Entry();
            entry.value = value;
            entry.key = key;
            entry.h = h;

            entry.slotNext = slots[slotNum];
            slots[slotNum] = entry;

            linkedListHead.linkedListFormer.linkedListNext = entry;
            entry.linkedListFormer = linkedListHead.linkedListFormer;
            linkedListHead.linkedListFormer = entry;
            entry.linkedListNext = linkedListHead;

            return 0;
        }

        public int remove(int key) {
            int h = hash(key);
            int slotNum = h & mask;

            Entry last = null;
            Entry entry = slots[slotNum];
            while (entry != null && (entry.h != h || !equalChecker.equal(entry.key, key))) {
                last = entry;
                entry = entry.slotNext;
            }

            if (entry == null) {
                return 0;
            }

            //Remove from slot
            if (last == null) {
                slots[slotNum] = entry.slotNext;
            } else {
                last.slotNext = entry.slotNext;
            }

            //Remove from linkedlist
            entry.linkedListNext.linkedListFormer = entry.linkedListFormer;
            entry.linkedListFormer.linkedListNext = entry.linkedListNext;

            return entry.value;
        }

        private final int hash(int key) {
            int h;
            return (h = hash.hash(key)) ^ (h >>> 16);
        }

        public boolean containsKey(int key) {
            int h = hash(key);
            int slotNum = h & mask;
            return searchSlot(slotNum, h, key) != null;
        }

        public int size() {
            return size;
        }

        public boolean isEmpty() {
            return size == 0;
        }

        public void clear() {
            Arrays.fill(slots, null);
            size = 0;
            linkedListHead.linkedListNext = linkedListHead.linkedListFormer = linkedListHead;
        }

        public Set<Entry> entrySet() {
            if (set == null) {
                set = new AbstractSet<Entry>() {
                    @Override
                    public Iterator<Entry> iterator() {
                        return new Iterator<Entry>() {
                            Entry head = linkedListHead;

                            @Override
                            public boolean hasNext() {
                                return head.linkedListNext != linkedListHead;
                            }

                            @Override
                            public Entry next() {
                                return head = head.linkedListNext;
                            }
                        };
                    }

                    @Override
                    public int size() {
                        return size;
                    }
                };
            }
            return set;
        }

        public int getOrDefault(int key, int defaultValue) {
            int h = hash(key);
            int slotNum = h & mask;

            Entry entry = searchSlot(slotNum, h, key);
            if (entry == null) {
                return defaultValue;
            }
            return entry.value;
        }

        @Override
        public String toString() {
            StringBuilder builder = new StringBuilder("{");
            for (Entry entry : entrySet()) {
                builder.append(entry.key).append("=>").append(entry.value).append(",");
            }
            if (builder.charAt(builder.length() - 1) == ',') {
                builder.setLength(builder.length() - 1);
            }
            builder.append("}");
            return builder.toString();
        }

        private Entry[] slots;
        private Supplier<Entry[]> slotSupplier;
        private Supplier<Entry> entrySupplier;
        private Hash hash;
        private EqualChecker equalChecker;
        private int mask;
        private int size;
        private Entry linkedListHead;
        private Set<Entry> set;
    }

    public static class FastIO {
        private final InputStream is;
        private final OutputStream os;
        private final Charset charset;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 8);
        public final StringBuilder cache = new StringBuilder();

        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;

        public FastIO(InputStream is, OutputStream os, Charset charset) {
            this.is = is;
            this.os = os;
            this.charset = charset;
        }

        private int read() {
            while (bufLen == bufOffset) {
                bufOffset = 0;
                try {
                    bufLen = is.read(buf);
                } catch (IOException e) {
                    throw new RuntimeException(e);
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

        public double readDouble() {
            long num = readLong();
            if (next != '.') {
                return num;
            }

            next = read();
            long divisor = 1;
            long later = 0;
            while (next >= '0' && next <= '9') {
                divisor = divisor * 10;
                later = later * 10 + next - '0';
                next = read();
            }

            if (num >= 0) {
                return num + (later / (double) divisor);
            } else {
                return num - (later / (double) divisor);
            }
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

        public int readString(char[] data, int offset) {
            skipBlank();

            int originalOffset = offset;
            while (next > 32) {
                data[offset++] = (char) next;
                next = read();
            }

            return offset - originalOffset;
        }

        public int readString(byte[] data, int offset) {
            skipBlank();

            int originalOffset = offset;
            while (next > 32) {
                data[offset++] = (byte) next;
                next = read();
            }

            return offset - originalOffset;
        }

        public void flush() {
            try {
                os.write(cache.toString().getBytes(charset));
                os.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        public boolean hasMore() {
            skipBlank();
            return next != -1;
        }
    }

    public static class Memory {
        public static <T> void swap(T[] data, int i, int j) {
            T tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

        public static <T> void swap(int[] data, int i, int j) {
            int tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

        public static <T> void swap(char[] data, int i, int j) {
            char tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

        public static <T> int min(T[] data, int from, int to, Comparator<T> cmp) {
            int m = from;
            for (int i = from + 1; i < to; i++) {
                if (cmp.compare(data[m], data[i]) > 0) {
                    m = i;
                }
            }
            return m;
        }

        public static <T> void move(T[] data, int from, int to, int step) {
            int len = to - from;
            step = len - (step % len + len) % len;
            Object[] buf = new Object[len];
            for (int i = 0; i < len; i++) {
                buf[i] = data[(i + step) % len + from];
            }
            System.arraycopy(buf, 0, data, from, len);
        }

        public static <T> void reverse(T[] data, int f, int t) {
            int l = f, r = t - 1;
            while (l < r) {
                swap(data, l, r);
                l++;
                r--;
            }
        }

        public static void copy(Object[] src, Object[] dst, int srcf, int dstf, int len) {
            if (len < 8) {
                for (int i = 0; i < len; i++) {
                    dst[dstf + i] = src[srcf + i];
                }
            } else {
                System.arraycopy(src, srcf, dst, dstf, len);
            }
        }
    }

    public static class Randomized {
        static Random random = new Random();

        public static double nextDouble(double min, double max) {
            return random.nextDouble() * (max - min) + min;
        }

        public static void randomizedArray(int[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                int tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static void randomizedArray(long[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                long tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static void randomizedArray(double[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                double tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static void randomizedArray(float[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                float tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static <T> void randomizedArray(T[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                T tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static int nextInt(int l, int r) {
            return random.nextInt(r - l + 1) + l;
        }
    }

}