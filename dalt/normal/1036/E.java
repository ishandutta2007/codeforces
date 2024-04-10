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
            ECoveredPoints solver = new ECoveredPoints();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class ECoveredPoints {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            //Segment2D[] segs = new Segment2D[n];
            int[][] segs = new int[n][4];
            for (int i = 0; i < n; i++) {
                //Point2D a = new Point2D(in.readInt(), in.readInt());
                //Point2D b = new Point2D(in.readInt(), in.readInt());
                //segs[i] = new Segment2D(a, b);
                for (int j = 0; j < 4; j++) {
                    segs[i][j] = in.readInt();
                }
            }

            long ans = 0;
//        for (Segment2D seg : segs) {
//            int a = DigitUtils.roundToInt(Math.abs(seg.a.x - seg.b.x));
//            int b = DigitUtils.roundToInt(Math.abs(seg.a.y - seg.b.y));
//            if (a == 0) {
//                ans += b + 1;
//            } else if (b == 0) {
//                ans += a + 1;
//            } else {
//                int g = GCDs.gcd(a, b);
//                ans += 1 + g;
//            }
//        }

            for (int[] seg : segs) {
                long a = Math.abs(seg[0] - seg[2]);
                long b = Math.abs(seg[1] - seg[3]);
                long g = GCDs.gcd(a, b);
                ans += g + 1;
            }

            LongHashSet set = new LongHashSet(n, false);
            //Randomized.randomizedArray(segs, 0, n - 1);
            for (int i = 0; i < n; i++) {
                set.clear();
                for (int j = i + 1; j < n; j++) {
                    long[] pos;
                    if (!isCrossOrTouchIntersect(segs[i][0], segs[i][1], segs[i][2], segs[i][3],
                            segs[j][0], segs[j][1], segs[j][2], segs[j][3]) ||
                            (pos = intersect(segs[i][0], segs[i][1], segs[i][2], segs[i][3],
                                    segs[j][0], segs[j][1], segs[j][2], segs[j][3])) == null) {
                        continue;
                    }

                    long key = DigitUtils.asLong((int) pos[0], (int) pos[1]);
                    set.add(key);
                }
                ans -= set.size();
            }

            out.println(ans);
        }

        static boolean isCrossOrTouchIntersect(long x1, long y1, long x2, long y2, long x3, long y3, long x4, long y4) {
            if (Math.max(x1, x2) < Math.min(x3, x4) || Math.max(x3, x4) < Math.min(x1, x2)
                    || Math.max(y1, y2) < Math.min(y3, y4) || Math.max(y3, y4) < Math.min(y1, y2))
                return false;
            long z1 = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
            long z2 = (x2 - x1) * (y4 - y1) - (y2 - y1) * (x4 - x1);
            long z3 = (x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3);
            long z4 = (x4 - x3) * (y2 - y3) - (y4 - y3) * (x2 - x3);
            return (z1 <= 0 || z2 <= 0) && (z1 >= 0 || z2 >= 0) && (z3 <= 0 || z4 <= 0) && (z3 >= 0 || z4 >= 0);
        }

        static long[] intersect(long x1, long y1, long x2, long y2, long x3, long y3, long x4, long y4) {
            long a1 = y2 - y1;
            long b1 = x1 - x2;
            long c1 = -(x1 * y2 - x2 * y1);
            long a2 = y4 - y3;
            long b2 = x3 - x4;
            long c2 = -(x3 * y4 - x4 * y3);
            long det = a1 * b2 - a2 * b1;
            if (det == 0)
                return null;
            if ((c1 * b2 - c2 * b1) % det == 0 && (a1 * c2 - a2 * c1) % det == 0) {
                return new long[]{-(c1 * b2 - c2 * b1) / det, -(a1 * c2 - a2 * c1) / det};
            }
            return null;
        }

    }

    static class LongHashSet {
        private int[] slot;
        private int[] next;
        private long[] keys;
        private int alloc;
        private boolean[] removed;
        private int mask;
        private int size;
        private boolean rehash;

        public LongHashSet(int cap, boolean rehash) {
            this.mask = (1 << (32 - Integer.numberOfLeadingZeros(cap - 1))) - 1;
            this.rehash = rehash;
            slot = new int[mask + 1];
            next = new int[cap + 1];
            keys = new long[cap + 1];
            removed = new boolean[cap + 1];
        }

        private void doubleCapacity() {
            int newSize = Math.max(next.length + 10, next.length * 2);
            next = Arrays.copyOf(next, newSize);
            keys = Arrays.copyOf(keys, newSize);
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

        private int hash(long x) {
            int h = Long.hashCode(x);
            return h ^ (h >>> 16);
        }

        public void add(long x) {
            int h = hash(x);
            int s = h & mask;
            if (slot[s] == 0) {
                alloc();
                slot[s] = alloc;
                keys[alloc] = x;
                return;
            } else {
                int index = findIndexOrLastEntry(s, x);
                if (keys[index] != x) {
                    alloc();
                    next[index] = alloc;
                    keys[alloc] = x;
                }
            }
            if (rehash && size >= slot.length) {
                rehash();
            }
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

        public LongIterator iterator() {
            return new LongIterator() {
                int index = 1;


                public boolean hasNext() {
                    while (index <= alloc && removed[index]) {
                        index++;
                    }
                    return index <= alloc;
                }


                public long next() {
                    if (!hasNext()) {
                        throw new IllegalStateException();
                    }
                    return keys[index++];
                }
            };
        }

        public int size() {
            return size;
        }

        public String toString() {
            LongIterator iterator = iterator();
            StringBuilder builder = new StringBuilder("{");
            while (iterator.hasNext()) {
                builder.append(iterator.next()).append(',');
            }
            if (builder.charAt(builder.length() - 1) == ',') {
                builder.setLength(builder.length() - 1);
            }
            builder.append('}');
            return builder.toString();
        }

    }

    static interface LongIterator {
        boolean hasNext();

        long next();

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

    static class DigitUtils {
        private static long mask32 = (1L << 32) - 1;

        private DigitUtils() {
        }

        public static long asLong(int high, int low) {
            return ((((long) high)) << 32) | (((long) low) & mask32);
        }

    }

    static class GCDs {
        private GCDs() {
        }

        public static long gcd(long a, long b) {
            return a >= b ? gcd0(a, b) : gcd0(b, a);
        }

        private static long gcd0(long a, long b) {
            return b == 0 ? a : gcd0(b, a % b);
        }

    }
}