import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
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
            FEmployment solver = new FEmployment();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FEmployment {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int m = in.readInt();
            int n = in.readInt();
            int[] a = new int[n];
            int[] b = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.readInt() - 1;
            }
            for (int j = 0; j < n; j++) {
                b[j] = in.readInt() - 1;
            }

            OnCircleMinCostMatchProblem problem = new OnCircleMinCostMatchProblem(m, a, b);
            out.println(problem.getMinimumCost());

            for (int i = 0; i < n; i++) {
                out.append(problem.getMateOf(i) + 1).append(' ');
            }
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

        public static int mod(int x, int mod) {
            x %= mod;
            if (x < 0) {
                x += mod;
            }
            return x;
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

    static class IntList implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

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

        public int pop() {
            return data[--size];
        }

        public int size() {
            return size;
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public boolean isEmpty() {
            return size == 0;
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

    static class CandyAssignProblem {
        private int c;
        List<CandyAssignProblem.Candy> addedCandies;
        CandyAssignProblem.Candy[] candies;
        int candieCnt;
        long minimumCost;

        public CandyAssignProblem(int c, int exp) {
            this.c = c;
            addedCandies = new ArrayList<>(exp);
        }

        public void requestOn(int i, int x, int y) {
            CandyAssignProblem.Candy candy = new CandyAssignProblem.Candy();
            candy.location = i;
            candy.x = x;
            candy.y = y;
            addedCandies.add(candy);
        }

        public void assignCandyOn(int i, int x) {
            requestOn(i, x, 0);
        }

        public void requireCandyOn(int i, int y) {
            requestOn(i, 0, y);
        }

        public void solve() {
            if (addedCandies.isEmpty()) {
                addedCandies.add(new CandyAssignProblem.Candy());
            }
            candies = addedCandies.toArray(new CandyAssignProblem.Candy[0]);
            Arrays.sort(candies, CandyAssignProblem.Candy.sortByA);
            candieCnt = 0;
            for (int i = 1; i < candies.length; i++) {
                if (candies[i].location == candies[candieCnt].location) {
                    candies[candieCnt].x += candies[i].x;
                    candies[candieCnt].y += candies[i].y;
                } else {
                    candieCnt++;
                    candies[candieCnt] = candies[i];
                }
            }
            candieCnt++;

            for (int i = 0; i < candieCnt - 1; i++) {
                candies[i].w = candies[i + 1].location - candies[i].location;
            }
            candies[candieCnt - 1].w = c + candies[0].location - candies[candieCnt - 1].location;

            for (int i = 1; i < candieCnt; i++) {
                candies[i].a = candies[i - 1].a + candies[i].x - candies[i].y;
            }

            CandyAssignProblem.Candy[] sortedByA = Arrays.copyOf(candies, candieCnt);
            Arrays.sort(sortedByA, (a, b) -> Long.compare(a.a, b.a));
            long prefix = 0;
            long half = DigitUtils.ceilDiv(c, 2);
            for (int i = 0; i < candieCnt; i++) {
                prefix += sortedByA[i].w;
                if (prefix >= half) {
                    candies[0].a = -sortedByA[i].a;
                    break;
                }
            }

            for (int i = 1; i < candieCnt; i++) {
                candies[i].a += candies[0].a;
            }

            for (int i = 0; i < candieCnt; i++) {
                minimumCost += Math.abs(candies[i].a) * candies[i].w;
            }
        }

        static class Candy {
            int location;
            int x;
            int y;
            long a;
            int w;
            static Comparator<CandyAssignProblem.Candy> sortByA = (a, b) -> Integer.compare(a.location, b.location);

        }

    }

    static interface LongObjectEntryIterator<V> {
        boolean hasNext();

        void next();

        long getEntryKey();

        V getEntryValue();

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

    static class OnCircleMinCostMatchProblem {
        int[] matching;
        long minimumCost;
        LongObjectHashMap<IntList> peopleMap;
        LongObjectHashMap<IntList> houseMap;
        CandyAssignProblem problem;
        IntList pending;

        public long getMinimumCost() {
            return minimumCost;
        }

        public int getMateOf(int i) {
            return matching[i];
        }

        private IntList getIntList(LongObjectHashMap<IntList> map, long key) {
            IntList list = map.get(key);
            if (list == null) {
                list = new IntList(1);
                map.put(key, list);
            }
            return list;
        }

        public OnCircleMinCostMatchProblem(int c, int[] people, int[] houses) {
            if (c <= 0 || people.length != houses.length) {
                throw new IllegalArgumentException();
            }

            int n = people.length;
            problem = new CandyAssignProblem(c, n * 2);
            peopleMap = new LongObjectHashMap<>(n, false);
            houseMap = new LongObjectHashMap<>(n, false);
            matching = new int[n];
            pending = new IntList(n);

            for (int i = 0; i < n; i++) {
                getIntList(peopleMap, people[i]).add(i);
                getIntList(houseMap, houses[i]).add(i);
            }

            for (int i = 0; i < n; i++) {
                problem.assignCandyOn(people[i], 1);
            }

            for (int i = 0; i < n; i++) {
                problem.requireCandyOn(houses[i], 1);
            }

            problem.solve();
            minimumCost = problem.minimumCost;

            for (int i = 0; i < problem.candieCnt; i++) {
                int last = DigitUtils.mod(i - 1, problem.candieCnt);
                if (problem.candies[i].a >= 0 && problem.candies[last].a <= 0) {
                    buildMatching(i);
                }
            }
        }

        private void buildMatching(int i) {
            IntList people = peopleMap.get(problem.candies[i].location);
            IntList houses = houseMap.get(problem.candies[i].location);

            if (people != null && houses != null) {
                while (!people.isEmpty() && !houses.isEmpty()) {
                    matching[people.pop()] = houses.pop();
                }
            }

            if (houses != null) {
                while (!houses.isEmpty() && !pending.isEmpty()) {
                    matching[pending.pop()] = houses.pop();
                }
            }

            if (problem.candies[i].a > 0) {
                while (pending.size() < problem.candies[i].a) {
                    pending.add(people.pop());
                }
                buildMatching((i + 1) % problem.candieCnt);
            }

            int last = DigitUtils.mod(i - 1, problem.candieCnt);
            if (problem.candies[last].a < 0) {
                while (pending.size() < -problem.candies[last].a) {
                    pending.add(people.pop());
                }
                buildMatching(last);
            }
        }

    }
}