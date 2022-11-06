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
            ECowAndTreats solver = new ECowAndTreats();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class ECowAndTreats {
        private int[] left;
        private int[] right;
        Machine machine;
        int[] f;
        int[] h;
        int[][] status;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            Modular mod = new Modular(1e9 + 7);

            int[] s = new int[n];
            for (int i = 0; i < n; i++) {
                s[i] = in.readInt();
            }
            f = new int[m];
            h = new int[m];
            left = new int[m];
            right = new int[m];
            status = new int[m][4];
            IntegerHashMap map = new IntegerHashMap(m, false);
            for (int i = 0; i < m; i++) {
                f[i] = in.readInt();
                h[i] = in.readInt();
                left[i] = right[i] = -1;
                map.put(get(f[i], h[i]), i);
            }

            int[] cnts = new int[n + 1];
            for (int i = 0; i < n; i++) {
                cnts[s[i]]++;
                int key = get(s[i], cnts[s[i]]);
                if (map.containKey(key)) {
                    left[map.get(key)] = i;
                }
            }
            Arrays.fill(cnts, 0);
            for (int i = n - 1; i >= 0; i--) {
                cnts[s[i]]++;
                int key = get(s[i], cnts[s[i]]);
                if (map.containKey(key)) {
                    right[map.get(key)] = i;
                }
            }

            int[] inverseLeft = new int[n];
            int[] inverseRight = new int[n];
            Arrays.fill(inverseLeft, -1);
            Arrays.fill(inverseRight, -1);
            for (int i = 0; i < m; i++) {
                if (left[i] != -1) {
                    inverseLeft[left[i]] = i;
                }
                if (right[i] != -1) {
                    inverseRight[right[i]] = i;
                }
            }

            machine = new Machine(n + 1);
            for (int i = 0; i < m; i++) {
                calc(i, -1);
            }

            int max = machine.max;
            int maxCnt = machine.cnt;
            for (int i = 0; i < n; i++) {
                clear(inverseRight[i]);
                calc(inverseRight[i], i);
                clear(inverseLeft[i]);
                if (inverseLeft[i] != -1) {
                    int cow = inverseLeft[i];
                    int recordLeft = machine.left[f[cow]];
                    int recordBoth = machine.both[f[cow]];
                    machine.update(f[cow], -recordLeft, recordBoth, -recordBoth);
                    if (max < machine.max + 1) {
                        max = machine.max + 1;
                        maxCnt = 0;
                    }
                    if (max == machine.max + 1) {
                        maxCnt = mod.plus(maxCnt, machine.cnt);
                    }
                    machine.update(f[cow], recordLeft, -recordBoth, recordBoth);
                }
                calc(inverseLeft[i], i);
            }

            out.append(max).append(' ').append(maxCnt);
        }

        public void clear(int cow) {
            if (cow == -1) {
                return;
            }
            machine.update(f[cow], -status[cow][1], -status[cow][2], -status[cow][3]);
            Arrays.fill(status[cow], 0);
        }

        public void calc(int cow, int leftBound) {
            if (cow == -1) {
                return;
            }
            int mask = 0;
            mask = Bits.setBit(mask, 0, left[cow] != -1 && left[cow] <= leftBound);
            mask = Bits.setBit(mask, 1, right[cow] != -1 && right[cow] > leftBound);
            status[cow][mask] = 1;
            machine.update(f[cow], status[cow][1], status[cow][2], status[cow][3]);
        }

        public int get(int f, int h) {
            return f * 10000 + h;
        }

    }

    static class Machine {
        int[] left;
        int[] right;
        int[] both;
        Modular mod = new Modular(1e9 + 7);
        Power power = new Power(mod);
        int max;
        int cnt = 1;

        public Machine(int n) {
            left = new int[n];
            right = new int[n];
            both = new int[n];
        }

        public void takeEffect(int i) {
            if (left[i] + right[i] + both[i] == 0) {
            } else if (both[i] + left[i] + right[i] == 1 ||
                    left[i] + both[i] == 0 || right[i] + both[i] == 0) {
                max += 1;
                int cnt1 = left[i] + right[i] + 2 * both[i];
                cnt = mod.mul(cnt, cnt1);
            } else {
                max += 2;
                int cnt1 = mod.mul(left[i], right[i] + both[i]);
                int cnt2 = mod.mul(both[i], right[i] + both[i] - 1);
                int cnt3 = mod.plus(cnt1, cnt2);
                cnt = mod.mul(cnt, cnt3);
            }
        }

        public void clearEffect(int i) {
            if (left[i] + right[i] + both[i] == 0) {
            } else if (both[i] + left[i] + right[i] == 1 ||
                    left[i] + both[i] == 0 || right[i] + both[i] == 0) {
                max -= 1;
                int cnt1 = left[i] + right[i] + 2 * both[i];
                cnt = mod.mul(cnt, power.inverseByFermat(cnt1));
            } else {
                max -= 2;
                int cnt1 = mod.mul(left[i], right[i] + both[i]);
                int cnt2 = mod.mul(both[i], right[i] + both[i] - 1);
                int cnt3 = mod.plus(cnt1, cnt2);
                cnt = mod.mul(cnt, power.inverseByFermat(cnt3));
            }
        }

        public void update(int i, int l, int r, int b) {
            clearEffect(i);
            left[i] += l;
            right[i] += r;
            both[i] += b;
            takeEffect(i);
        }

    }

    static class Bits {
        private Bits() {
        }

        public static int setBit(int x, int i, boolean v) {
            if (v) {
                x |= 1 << i;
            } else {
                x &= ~(1 << i);
            }
            return x;
        }

    }

    static class FastInput {
        private final InputStream is;
        private byte[] buf = new byte[1 << 20];
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

    static interface IntegerEntryIterator {
        boolean hasNext();

        void next();

        int getEntryKey();

        int getEntryValue();

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

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

        public String toString() {
            return "mod " + m;
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

        public int inverseByFermat(int x) {
            return pow(x, modular.m - 2);
        }

    }

    static class IntegerHashMap {
        private int[] slot;
        private int[] next;
        private int[] keys;
        private int[] values;
        private int alloc;
        private boolean[] removed;
        private int mask;
        private int size;
        private boolean rehash;

        public IntegerHashMap(int cap, boolean rehash) {
            this.mask = (1 << (32 - Integer.numberOfLeadingZeros(cap - 1))) - 1;
            slot = new int[mask + 1];
            next = new int[cap + 1];
            keys = new int[cap + 1];
            values = new int[cap + 1];
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

        private int hash(int x) {
            int h = Integer.hashCode(x);
            return h ^ (h >>> 16);
        }

        public void put(int x, int y) {
            put(x, y, true);
        }

        public void put(int x, int y, boolean cover) {
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

        public boolean containKey(int x) {
            int h = hash(x);
            int s = h & mask;
            if (slot[s] == 0) {
                return false;
            }
            return keys[findIndexOrLastEntry(s, x)] == x;
        }

        public int getOrDefault(int x, int def) {
            int h = hash(x);
            int s = h & mask;
            if (slot[s] == 0) {
                return def;
            }
            int index = findIndexOrLastEntry(s, x);
            return keys[index] == x ? values[index] : def;
        }

        public int get(int x) {
            return getOrDefault(x, 0);
        }

        private int findIndexOrLastEntry(int s, int x) {
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

        public IntegerEntryIterator iterator() {
            return new IntegerEntryIterator() {
                int index = 1;
                int readIndex = -1;


                public boolean hasNext() {
                    while (index <= alloc && removed[index]) {
                        index++;
                    }
                    return index <= alloc;
                }


                public int getEntryKey() {
                    return keys[readIndex];
                }


                public int getEntryValue() {
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
            IntegerEntryIterator iterator = iterator();
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