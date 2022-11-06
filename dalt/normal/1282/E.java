import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Collection;
import java.io.IOException;
import java.util.Deque;
import java.util.TreeSet;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
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
            ETheCakeIsALie solver = new ETheCakeIsALie();
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                solver.solve(i, in, out);
            out.close();
        }
    }

    static class ETheCakeIsALie {
        LongObjectHashMap<Deque<Triangle>> map;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            Number[] nums = new Number[n + 1];
            for (int i = 1; i <= n; i++) {
                nums[i] = new Number();
                nums[i].val = i;
            }

            Triangle[] triangles = new Triangle[n - 2];
            for (int i = 0; i < n - 2; i++) {
                triangles[i] = new Triangle();
                triangles[i].id = i;
                for (int j = 0; j < 3; j++) {
                    triangles[i].vertexes[j] = in.readInt();
                    nums[triangles[i].vertexes[j]].list.add(triangles[i]);
                    nums[triangles[i].vertexes[j]].cnt++;
                }
            }

            TreeSet<Number> set = new TreeSet<>((a, b) -> a.cnt == b.cnt ? a.val - b.val : a.cnt - b.cnt);
            for (int i = 1; i <= n; i++) {
                set.add(nums[i]);
            }

            int order = 0;
            while (!set.isEmpty()) {
                Number number = set.pollFirst();
                for (Triangle t : number.list) {
                    if (t.order > 0) {
                        continue;
                    }
                    t.order = ++order;
                    for (int i = 0; i < 3; i++) {
                        if (t.vertexes[i] == number.val) {
                            SequenceUtils.swap(t.vertexes, i, 1);
                            break;
                        }
                    }
                    for (int i = 0; i < 3; i++) {
                        boolean removed = set.remove(nums[t.vertexes[i]]);
                        nums[t.vertexes[i]].cnt--;
                        if (removed) {
                            set.add(nums[t.vertexes[i]]);
                        }
                    }
                }
            }

            Arrays.sort(triangles, (a, b) -> a.order - b.order);
            map = new LongObjectHashMap<>(3 * n, false);
            for (Triangle t : triangles) {
                putIfNotExist(map, idOfEdge(t.vertexes[0], t.vertexes[1])).addLast(t);
                putIfNotExist(map, idOfEdge(t.vertexes[0], t.vertexes[2])).addLast(t);
                putIfNotExist(map, idOfEdge(t.vertexes[1], t.vertexes[2])).addLast(t);
            }

            triangles[n - 3].handled = true;
            out.append(triangles[n - 3].vertexes[0]).append(' ');
            dfs(triangles[n - 3].vertexes[0], triangles[n - 3].vertexes[1], out);
            out.append(triangles[n - 3].vertexes[1]).append(' ');
            dfs(triangles[n - 3].vertexes[1], triangles[n - 3].vertexes[2], out);
            out.append(triangles[n - 3].vertexes[2]).append(' ');
            dfs(triangles[n - 3].vertexes[2], triangles[n - 3].vertexes[0], out);

            out.println();

            for (Triangle t : triangles) {
                out.append(t.id + 1).append(' ');
            }
            out.println();
        }

        public void dfs(int a, int b, FastOutput out) {
            Deque<Triangle> list = map.remove(idOfEdge(a, b));
            if (list == null) {
                return;
            }
            while (!list.isEmpty()) {
                dfs(a, b, list.removeFirst(), out);
            }
        }

        public void dfs(int a, int b, Triangle t, FastOutput out) {
            if (t.handled) {
                return;
            }
            t.handled = true;

            boolean flip;
            if (a != t.vertexes[0] && b != t.vertexes[0]) {
                flip = a == t.vertexes[2];
            } else if (a != t.vertexes[1] && b != t.vertexes[1]) {
                flip = a == t.vertexes[2];
            } else {
                flip = a == t.vertexes[1];
            }
            if (flip) {
                SequenceUtils.swap(t.vertexes, 0, 2);
            }
            dfs(t.vertexes[0], t.vertexes[1], out);
            out.append(t.vertexes[1]).append(' ');
            dfs(t.vertexes[1], t.vertexes[2], out);
            dfs(t.vertexes[2], t.vertexes[0], out);
        }

        public long idOfEdge(int a, int b) {
            if (a > b) {
                int tmp = a;
                a = b;
                b = tmp;
            }
            return DigitUtils.asLong(a, b);
        }

        public Deque<Triangle> putIfNotExist(LongObjectHashMap<Deque<Triangle>> map, long key) {
            Deque<Triangle> list = map.get(key);
            if (list == null) {
                list = new LinkedList<>();
                map.put(key, list);
            }
            return list;
        }

    }

    static class Triangle {
        int[] vertexes = new int[3];
        boolean handled;
        int order;
        int id;

        public String toString() {
            return Arrays.toString(vertexes);
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

    static class Number {
        int val;
        int cnt;
        List<Triangle> list = new ArrayList<>();

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static long asLong(int high, int low) {
            return (((long) high) << 32) | low;
        }

    }

    static interface LongObjectEntryIterator<V> {
        boolean hasNext();

        void next();

        long getEntryKey();

        V getEntryValue();

    }

    static class SequenceUtils {
        public static void swap(int[] data, int i, int j) {
            int tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
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

        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }

        public FastOutput append(int c) {
            cache.append(c);
            return this;
        }

        public FastOutput println() {
            cache.append('\n');
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

    static class LongObjectHashMap<V> {
        private int[] slot;
        private int[] next;
        private long[] keys;
        private Object[] values;
        private int alloc;
        private boolean[] removed;
        private int mask;
        private int size;
        private boolean rehash;

        public LongObjectHashMap(int cap, boolean rehash) {
            this.mask = (1 << (32 - Integer.numberOfLeadingZeros(cap - 1))) - 1;
            slot = new int[mask + 1];
            next = new int[cap + 1];
            keys = new long[cap + 1];
            values = new Object[cap + 1];
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

        public void alloc() {
            alloc++;
            if (alloc >= next.length) {
                doubleCapacity();
            }
            next[alloc] = 0;
            removed[alloc] = false;
            size++;
        }

        private int hash(long x) {
            int h = Long.hashCode(x);
            return h ^ (h >>> 16);
        }

        public void put(long x, V y) {
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
                } else {
                    values[index] = y;
                }
            }
            if (rehash && size >= slot.length) {
                rehash();
            }
        }

        public V getOrDefault(long x, V def) {
            int h = hash(x);
            int s = h & mask;
            if (slot[s] == 0) {
                return def;
            }
            int index = findIndexOrLastEntry(s, x);
            return keys[index] == x ? (V) values[index] : def;
        }

        public V get(long x) {
            return getOrDefault(x, null);
        }

        public V remove(long x) {
            int h = hash(x);
            int s = h & mask;
            if (slot[s] == 0) {
                return null;
            }
            int pre = 0;
            int index = slot[s];
            while (keys[index] != x) {
                pre = index;
                if (next[index] != 0) {
                    index = next[index];
                } else {
                    break;
                }
            }
            if (keys[index] != x) {
                return null;
            }
            if (slot[s] == index) {
                slot[s] = next[index];
            } else {
                next[pre] = next[index];
            }
            removed[index] = true;
            size--;
            return (V) values[index];
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

        public LongObjectEntryIterator<V> iterator() {
            return new LongObjectEntryIterator() {
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


                public Object getEntryValue() {
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
            LongObjectEntryIterator<V> iterator = iterator();
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
}