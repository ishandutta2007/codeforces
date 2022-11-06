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
            TaskB1 solver = new TaskB1();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskB1 {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int[] a = new int[n];
            long sum = 0;
            for (int i = 0; i < n; i++) {
                a[i] = in.readInt();
                sum += a[i];
            }
            if (sum == 1) {
                out.println(-1);
                return;
            }
            long ans = Long.MAX_VALUE;
            LongList allPrimes = new LongList();
            for (long i = 2; i * i <= sum; i++) {
                if (sum % i != 0) {
                    continue;
                }
                allPrimes.add(i);
                while (sum % i == 0) {
                    sum /= i;
                }
            }
            if (sum > 1) {
                allPrimes.add(sum);
            }
            for (int i = 0; i < allPrimes.size(); i++) {
                ans = Math.min(ans, solve(a, allPrimes.get(i), n, ans));

            }
            out.println(ans);
        }

        public long solve(int[] a, long k, int n, long now) {
            if (k == 1) {
                return Long.MAX_VALUE;
            }
            long sum = 0;
            int middleIndex = -1;
            long dist = 0;
            long middle = DigitUtils.ceilDiv(k, 2);
            for (int i = 0; i < n; i++) {
                if (middleIndex == -1) {
                    dist += sum;
                }
                long remain = a[i] % k;
                if (remain + sum >= middle && middleIndex == -1) {
                    middleIndex = i;
                }
                long used = Math.min(k - sum, remain);
                remain -= used;
                sum += used;
                if (middleIndex != -1) {
                    dist += used * (i - middleIndex);
                }
                remain %= k;
                if (sum == k) {
                    sum = remain;
                    middleIndex = remain >= middle ? i : -1;
                }
                if (dist >= now) {
                    return now;
                }
            }

            return dist;
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

    static class LongList {
        private int size;
        private int cap;
        private long[] data;
        private static final long[] EMPTY = new long[0];

        public LongList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new long[cap];
            }
        }

        public LongList(LongList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public LongList() {
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

        private void checkRange(int i) {
            if (i < 0 || i >= size) {
                throw new ArrayIndexOutOfBoundsException();
            }
        }

        public long get(int i) {
            checkRange(i);
            return data[i];
        }

        public void add(long x) {
            ensureSpace(size + 1);
            data[size++] = x;
        }

        public int size() {
            return size;
        }

        public String toString() {
            return Arrays.toString(Arrays.copyOf(data, size));
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static long floorDiv(long a, long b) {
            return a < 0 ? -ceilDiv(-a, b) : a / b;
        }

        public static long ceilDiv(long a, long b) {
            if (a < 0) {
                return -floorDiv(-a, b);
            }
            long c = a / b;
            if (c * b < a) {
                return c + 1;
            }
            return c;
        }

    }
}