import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.function.IntConsumer;
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
            FTheNeutralZone solver = new FTheNeutralZone();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FTheNeutralZone {
        int a;
        int b;
        int c;
        int d;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            a = in.readInt();
            b = in.readInt();
            c = in.readInt();
            d = in.readInt();

            Consumer consumer = new Consumer(n);
            EratosthenesSieve.sieve(consumer, n);
            int ans = consumer.sum;
            out.println(DigitUtils.asLong(0, ans));
        }

        public int log(int x, int n) {
            return n < x ? 0 : (n / x + log(x, n / x));
        }

        public int f(int x) {
            int x1 = x;
            int x2 = x1 * x;
            int x3 = x2 * x;
            return x3 * a + x2 * b + x1 * c + d;
        }

        class Consumer implements IntConsumer {
            int n;
            int sum;

            public Consumer(int n) {
                this.n = n;
            }

            public void accept(int value) {
                sum += log(value, n) * f(value);
            }

        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private StringBuilder cache = new StringBuilder(1 << 20);
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

        public FastOutput println(long c) {
            cache.append(c);
            println();
            return this;
        }

        public FastOutput println() {
            cache.append(System.lineSeparator());
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

    static class DigitUtils {
        private static long mask32 = (1L << 32) - 1;

        private DigitUtils() {
        }

        public static int roundToInt(double x) {
            return (int) round(x);
        }

        public static long round(double x) {
            if (x >= 0) {
                return (long) (x + 0.5);
            } else {
                return (long) (x - 0.5);
            }
        }

        public static long asLong(int high, int low) {
            return ((((long) high)) << 32) | (((long) low) & mask32);
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

    static class EratosthenesSieve {
        public static void sieve(IntConsumer consumer, int n) {
            if (n <= 1) {
                return;
            }
            int block = DigitUtils.roundToInt(Math.sqrt(n));
            boolean[] isComp = new boolean[block + 1];
            int[] primes = new int[block + 1];
            int primeCnt = 0;
            for (int i = 2; i <= block; i++) {
                if (isComp[i]) {
                    continue;
                }
                primes[primeCnt++] = i;
                for (int j = i + i; j <= block; j += i) {
                    isComp[j] = true;
                }
            }
            for (int i = 0; i < primeCnt; i++) {
                int p = primes[i];
                consumer.accept(p);
            }
            for (int l = block + 1; l <= n; l += block) {
                int r = Math.min(l + block - 1, n);
                Arrays.fill(isComp, false);
                for (int i = 0; i < primeCnt; i++) {
                    int p = primes[i];
                    if (r < p * p) {
                        break;
                    }
                    int top = Math.max(0, l - p * p);
                    int bot = p;
                    for (int j = (top + bot - 1) / bot * p + p * p; j <= r; j += p) {
                        isComp[j - l] = true;
                    }
                }
                for (int j = l; j <= r; j++) {
                    if (!isComp[j - l]) {
                        consumer.accept(j);
                    }
                }
            }
        }

    }
}