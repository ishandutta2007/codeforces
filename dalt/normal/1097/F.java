import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.BitSet;
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
            TaskF solver = new TaskF();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskF {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int q = in.readInt();
            int limit = 7000;
            MultiplicativeFunctionSieve sieve = new MultiplicativeFunctionSieve(limit,
                    true, false, false);
            BitSet[] mu = new BitSet[limit + 1];
            BitSet[] divisors = new BitSet[limit + 1];
            for (int i = 1; i <= limit; i++) {
                mu[i] = new BitSet(limit + 1);
                divisors[i] = new BitSet(limit + 1);
            }
            for (int i = 1; i <= limit; i++) {
                for (int j = i; j <= limit; j += i) {
                    mu[i].set(j, sieve.mobius[j / i] != 0);
                    divisors[j].set(i, true);
                }
            }

            BitSet[] sets = new BitSet[n + 1];
            for (int i = 0; i <= n; i++) {
                sets[i] = new BitSet(limit + 1);
            }

            for (int i = 1; i <= q; i++) {
                int t = in.readInt();
                if (t == 1) {
                    int x = in.readInt();
                    int v = in.readInt();
                    sets[x].clear();
                    sets[x].or(divisors[v]);
                } else if (t == 2) {
                    int x = in.readInt();
                    int y = in.readInt();
                    int z = in.readInt();
                    if (x == y && x == z) {
                        sets[x].xor(sets[x]);
                    } else if (x == y) {
                        sets[x].xor(sets[z]);
                    } else if (x == z) {
                        sets[x].xor(sets[y]);
                    } else {
                        sets[x].clear();
                        sets[x].or(sets[y]);
                        sets[x].xor(sets[z]);
                    }
                } else if (t == 3) {
                    int x = in.readInt();
                    int y = in.readInt();
                    int z = in.readInt();
                    if (x == y && x == z) {
                        sets[x].and(sets[x]);
                    } else if (x == y) {
                        sets[x].and(sets[z]);
                    } else if (x == z) {
                        sets[x].and(sets[y]);
                    } else {
                        sets[x].clear();
                        sets[x].or(sets[y]);
                        sets[x].and(sets[z]);
                    }
                } else {
                    int x = in.readInt();
                    int v = in.readInt();
                    sets[0].clear();
                    sets[0].or(sets[x]);
                    sets[0].and(mu[v]);
                    out.append(sets[0].cardinality() % 2);
                }
            }
        }

    }

    static class MultiplicativeFunctionSieve {
        public int[] primes;
        public boolean[] isComp;
        public int primeLength;
        public int[] mobius;
        public int[] euler;
        public int[] factors;
        public int[] smallestPrimeFactor;
        public int[] numberOfSmallestPrimeFactor;

        public MultiplicativeFunctionSieve(int limit, boolean enableMobius, boolean enableEuler, boolean enableFactors) {
            isComp = new boolean[limit + 1];
            primes = new int[limit + 1];
            numberOfSmallestPrimeFactor = new int[limit + 1];
            smallestPrimeFactor = new int[limit + 1];
            primeLength = 0;
            for (int i = 2; i <= limit; i++) {
                if (!isComp[i]) {
                    primes[primeLength++] = i;
                    numberOfSmallestPrimeFactor[i] = smallestPrimeFactor[i] = i;
                }
                for (int j = 0, until = limit / i; j < primeLength && primes[j] <= until; j++) {
                    int pi = primes[j] * i;
                    smallestPrimeFactor[pi] = primes[j];
                    numberOfSmallestPrimeFactor[pi] = smallestPrimeFactor[i] == primes[j]
                            ? (numberOfSmallestPrimeFactor[i] * numberOfSmallestPrimeFactor[primes[j]])
                            : numberOfSmallestPrimeFactor[primes[j]];
                    isComp[pi] = true;
                    if (i % primes[j] == 0) {
                        break;
                    }
                }
            }

            if (enableMobius) {
                mobius = new int[limit + 1];
                mobius[1] = 1;
                for (int i = 2; i <= limit; i++) {
                    if (!isComp[i]) {
                        mobius[i] = -1;
                    } else {
                        if (numberOfSmallestPrimeFactor[i] != smallestPrimeFactor[i]) {
                            mobius[i] = 0;
                        } else {
                            mobius[i] = mobius[numberOfSmallestPrimeFactor[i]] * mobius[i / numberOfSmallestPrimeFactor[i]];
                        }
                    }
                }
            }

            if (enableEuler) {
                euler = new int[limit + 1];
                euler[1] = 1;
                for (int i = 2; i <= limit; i++) {
                    if (!isComp[i]) {
                        euler[i] = i - 1;
                    } else {
                        if (numberOfSmallestPrimeFactor[i] == i) {
                            euler[i] = i - i / smallestPrimeFactor[i];
                        } else {
                            euler[i] = euler[numberOfSmallestPrimeFactor[i]] * euler[i / numberOfSmallestPrimeFactor[i]];
                        }
                    }
                }
            }

            if (enableFactors) {
                factors = new int[limit + 1];
                factors[1] = 1;
                for (int i = 2; i <= limit; i++) {
                    if (!isComp[i]) {
                        factors[i] = 2;
                    } else {
                        if (numberOfSmallestPrimeFactor[i] == i) {
                            factors[i] = 1 + factors[i / smallestPrimeFactor[i]];
                        } else {
                            factors[i] = factors[numberOfSmallestPrimeFactor[i]]
                                    * factors[i / numberOfSmallestPrimeFactor[i]];
                        }
                    }
                }
            }
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
}