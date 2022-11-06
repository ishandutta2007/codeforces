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
            F2MicrotransactionsHardVersion solver = new F2MicrotransactionsHardVersion();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class F2MicrotransactionsHardVersion {
        long inf = (long) 1e18;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            int[] k = new int[n];
            int[] remains = new int[n];
            for (int i = 0; i < n; i++) {
                k[i] = in.readInt();
            }

            Discount[] discounts = new Discount[m];
            for (int j = 0; j < m; j++) {
                discounts[j] = new Discount();
                discounts[j].d = in.readInt();
                discounts[j].t = in.readInt() - 1;
            }

            Arrays.sort(discounts, (a, b) -> a.d - b.d);
            long[] lastDay = new long[n];
            Arrays.fill(lastDay, inf);
            for (int i = m - 1; i >= 0; i--) {
                discounts[i].nextDay = lastDay[discounts[i].t];
                lastDay[discounts[i].t] = discounts[i].d;
            }

            LongBinarySearch bs = new LongBinarySearch() {

                public boolean check(long mid) {
                    long used = 0;
                    System.arraycopy(k, 0, remains, 0, n);
                    for (int i = 0; i < m && discounts[i].d <= mid; i++) {
                        if (discounts[i].nextDay <= mid) {
                            continue;
                        }
                        int consume = (int) Math.min(discounts[i].d - used, remains[discounts[i].t]);
                        used += consume;
                        remains[discounts[i].t] -= consume;
                    }
                    for (int i = 0; i < n; i++) {
                        used += 2 * remains[i];
                    }
                    return used <= mid;
                }
            };

            long ans = bs.binarySearch(0, (long) 1e11);
            out.println(ans);
        }

    }

    static class Discount {
        int d;
        int t;
        long nextDay;

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

    static abstract class LongBinarySearch {
        public abstract boolean check(long mid);

        public long binarySearch(long l, long r) {
            if (l > r) {
                throw new IllegalArgumentException();
            }
            while (l < r) {
                long mid = (l + r) >>> 1;
                if (check(mid)) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return l;
        }

    }
}