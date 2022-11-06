import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Collection;
import java.io.IOException;
import java.util.Random;
import java.util.Deque;
import java.util.function.Supplier;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.function.Consumer;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
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
            FTreeAndXOR solver = new FTreeAndXOR();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FTreeAndXOR {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            long k = in.readLong();

            long[] weights = new long[n];
            for (int i = 1; i < n; i++) {
                int p = in.readInt() - 1;
                long w = in.readLong();
                weights[i] = weights[p] ^ w;
            }
            long mask = KthXorTwoElement.solve(weights, k);
            out.println(mask);
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

    }

    static class Randomized {
        static Random random = new Random();

        public static void randomizedArray(long[] data) {
            randomizedArray(data, 0, data.length - 1);
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

        public static int nextInt(int l, int r) {
            return random.nextInt(r - l + 1) + l;
        }

    }

    static class Bits {
        private Bits() {
        }

        public static int bitAt(long x, int i) {
            return (int) ((x >> i) & 1);
        }

        public static long setBit(long x, int i, boolean v) {
            if (v) {
                x |= 1L << i;
            } else {
                x &= ~(1L << i);
            }
            return x;
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

    static class CachedLog2 {
        private static final int BITS = 16;
        private static final int LIMIT = 1 << BITS;
        private static final byte[] CACHE = new byte[LIMIT];

        static {
            int b = 0;
            for (int i = 0; i < LIMIT; i++) {
                while ((1 << (b + 1)) <= i) {
                    b++;
                }
                CACHE[i] = (byte) b;
            }
        }

        public static int floorLog(long x) {
            int ans = 0;
            while (x >= LIMIT) {
                ans += BITS;
                x >>>= BITS;
            }
            return ans + CACHE[(int) x];
        }

    }

    static class Buffer<T> {
        private Deque<T> deque;
        private Supplier<T> supplier;
        private Consumer<T> cleaner;

        public Buffer(Supplier<T> supplier) {
            this(supplier, (x) -> {
            });
        }

        public Buffer(Supplier<T> supplier, Consumer<T> cleaner) {
            this(supplier, cleaner, 0);
        }

        public Buffer(Supplier<T> supplier, Consumer<T> cleaner, int exp) {
            this.supplier = supplier;
            this.cleaner = cleaner;
            deque = new ArrayDeque<>(exp);
        }

        public T alloc() {
            return deque.isEmpty() ? supplier.get() : deque.removeFirst();
        }

        public void release(T e) {
            cleaner.accept(e);
            deque.addLast(e);
        }

    }

    static class KthXorTwoElement {
        public static long solve(long[] data, long k) {
            int n = data.length;

            Buffer<KthXorTwoElement.Interval> buffer = new Buffer<>(KthXorTwoElement.Interval::new, x -> {
            }, n * 2);

            Randomized.randomizedArray(data);
            Arrays.sort(data);

            List<KthXorTwoElement.Interval> lastLevel = new ArrayList<>(n);
            List<KthXorTwoElement.Interval> curLevel = new ArrayList<>(n);
            lastLevel.add(newInterval(buffer, 0, n - 1));
            int level = CachedLog2.floorLog(data[n - 1]);
            long mask = 0;
            for (; level >= 0; level--) {
                curLevel.clear();
                for (KthXorTwoElement.Interval interval : lastLevel) {
                    int l = interval.l;
                    int r = interval.r;
                    int m = r;
                    while (m >= l && Bits.bitAt(data[m], level) == 1) {
                        m--;
                    }
                    interval.m = m;
                }
                long total = 0;
                for (KthXorTwoElement.Interval interval : lastLevel) {
                    total += (long) (interval.m - interval.l + 1) * (interval.relative.m - interval.relative.l + 1);
                    total += (long) (interval.r - interval.m) * (interval.relative.r - interval.relative.m);
                }
                if (total < k) {
                    k -= total;
                    mask = Bits.setBit(mask, level, true);
                    for (KthXorTwoElement.Interval interval : lastLevel) {
                        if (interval.relative == interval) {
                            if (interval.l <= interval.m && interval.m < interval.r) {
                                KthXorTwoElement.Interval a = newInterval(buffer, interval.l, interval.m);
                                KthXorTwoElement.Interval b = newInterval(buffer, interval.m + 1, interval.r);
                                a.relative = b;
                                b.relative = a;
                                curLevel.add(a);
                                curLevel.add(b);
                            }
                        } else if (interval.r >= interval.relative.r) {
                            if (interval.l <= interval.m && interval.relative.r > interval.relative.m) {
                                KthXorTwoElement.Interval a = newInterval(buffer, interval.l, interval.m);
                                KthXorTwoElement.Interval b = newInterval(buffer, interval.relative.m + 1, interval.relative.r);
                                a.relative = b;
                                b.relative = a;
                                curLevel.add(a);
                                curLevel.add(b);
                            }
                            if (interval.m < interval.r && interval.relative.m >= interval.relative.l) {
                                KthXorTwoElement.Interval a = newInterval(buffer, interval.m + 1, interval.r);
                                KthXorTwoElement.Interval b = newInterval(buffer, interval.relative.l, interval.relative.m);
                                a.relative = b;
                                b.relative = a;
                                curLevel.add(a);
                                curLevel.add(b);
                            }
                        }
                    }
                } else {
                    for (KthXorTwoElement.Interval interval : lastLevel) {
                        if (interval.relative == interval) {
                            if (interval.l <= interval.m) {
                                KthXorTwoElement.Interval a = newInterval(buffer, interval.l, interval.m);
                                a.relative = a;
                                curLevel.add(a);
                            }
                            if (interval.m < interval.r) {
                                KthXorTwoElement.Interval a = newInterval(buffer, interval.m + 1, interval.r);
                                a.relative = a;
                                curLevel.add(a);
                            }
                        } else if (interval.r >= interval.relative.r) {
                            if (interval.l <= interval.m && interval.relative.l <= interval.relative.m) {
                                KthXorTwoElement.Interval a = newInterval(buffer, interval.l, interval.m);
                                KthXorTwoElement.Interval b = newInterval(buffer, interval.relative.l, interval.relative.m);
                                a.relative = b;
                                b.relative = a;
                                curLevel.add(a);
                                curLevel.add(b);
                            }
                            if (interval.m < interval.r && interval.relative.m < interval.relative.r) {
                                KthXorTwoElement.Interval a = newInterval(buffer, interval.m + 1, interval.r);
                                KthXorTwoElement.Interval b = newInterval(buffer, interval.relative.m + 1, interval.relative.r);
                                a.relative = b;
                                b.relative = a;
                                curLevel.add(a);
                                curLevel.add(b);
                            }
                        }
                    }
                }

                for (KthXorTwoElement.Interval interval : lastLevel) {
                    buffer.release(interval);
                }

                List<KthXorTwoElement.Interval> tmp = curLevel;
                curLevel = lastLevel;
                lastLevel = tmp;
            }

            return mask;
        }

        private static KthXorTwoElement.Interval newInterval(Buffer<KthXorTwoElement.Interval> buffer, int l, int r) {
            KthXorTwoElement.Interval ans = buffer.alloc();
            ans.l = l;
            ans.r = r;
            return ans;
        }

        static class Interval {
            int l;
            int r;
            int m;
            KthXorTwoElement.Interval relative = this;

        }

    }
}