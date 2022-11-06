

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.util.*;

public class CF442E {
    public static void main(String[] args) throws Exception {
        boolean local = System.getSecurityManager() == null;
        boolean async = false;

        Charset charset = Charset.forName("ascii");

        FastIO io = local ? new FastIO(new FileInputStream("D:\\DATABASE\\TESTCASE\\Code.in"), System.out, charset) : new FastIO(System.in, System.out, charset);
        Task task = new Task(io, new Debug(local));

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
        final Debug debug;
        int inf = (int) 1e8;
        long lInf = (long) 1e18;
        double dInf = 1e50;

        public Task(FastIO io, Debug debug) {
            this.io = io;
            this.debug = debug;
        }

        @Override
        public void run() {
            solve();
        }


        public void solve() {
            int w = io.readInt();
            int h = io.readInt();
            int n = io.readInt();

            double[][] pts = new double[n][2];
            for (int i = 0; i < n; i++) {
                pts[i][0] = io.readInt();
                pts[i][1] = io.readInt();
            }

            ThreeElementHeap heap = new ThreeElementHeap();
            SimulatedAnnealing<double[]> sa = new SimulatedAnnealing<double[]>(1e-10, 1, 0.98) {
                @Override
                public double[] next(double[] old, double temperature) {
                    double[] next = old.clone();
                    next[0] += nextDouble(-temperature, temperature);
                    next[1] += nextDouble(-temperature, temperature);
                    next[0] = Math.max(0, next[0]);
                    next[1] = Math.max(0, next[1]);
                    next[0] = Math.min(w, next[0]);
                    next[1] = Math.min(h, next[1]);
                    return next;
                }

                @Override
                public double eval(double[] status) {
                    heap.clear();
                    for (double[] pt : pts) {
                        double dx = status[0] - pt[0];
                        double dy = status[1] - pt[1];
                        heap.add(-(dx * dx + dy * dy));
                    }
                    return -heap.second();
                }
            };

            long now = System.nanoTime();
            long until = now + 1500_000_000;
            for (; System.nanoTime() <= until; ) {
                sa.optimize(100000, new double[]{sa.nextDouble(0, w), sa.nextDouble(0, h)});
            }

            io.cache.append(Math.sqrt(sa.getBestWeight()));
        }

    }

    public static class ThreeElementHeap {
        double[] abc = new double[3];

        public void add(double x) {
            if (abc[0] < x) {
                abc[0] = x;
            }
            if (abc[1] < x) {
                abc[0] = abc[1];
                abc[1] = x;
            }
            if (abc[2] < x) {
                abc[1] = abc[2];
                abc[2] = x;
            }
        }

        public double max(double x) {
            if (abc[2] != x) {
                return abc[2];
            }
            return abc[1];
        }

        public double max() {
            return abc[2];
        }

        public double min() {
            return abc[0];
        }

        public double second() {
            return abc[1];
        }

        public double min(long x) {
            if (abc[0] != x) {
                return abc[0];
            }
            return abc[1];
        }

        public double second(long x) {
            int emit = 0;
            boolean find = false;
            for (int i = 2; ; i--) {
                if (abc[i] == x && !find) {
                    find = true;
                    continue;
                }
                if (emit == 0) {
                    emit++;
                    continue;
                }
                return abc[i];
            }
        }

        public void clear() {
            Arrays.fill(abc, -Double.MAX_VALUE);
        }

        @Override
        public String toString() {
            return Arrays.toString(abc);
        }
    }

    public static abstract class SimulatedAnnealing<S> {
        public SimulatedAnnealing(double threshold, double k, double reduce) {
            this.threshold = threshold;
            this.k = k;
            this.reduce = reduce;
        }

        public abstract S next(S old, double temperature);

        public abstract double eval(S status);

        public void abandon(S old) {
        }

        public void optimize(double temperature, S init) {
            S now = init;
            double weight = eval(now);
            double t = temperature;
            while (t > threshold) {
                S next = next(now, t);
                double nextWeight = eval(next);
                if (nextWeight > weight || random.nextDouble() < Math.exp((nextWeight - weight) / (k * t))) {
                    abandon(now);
                    now = next;
                    weight = nextWeight;
                }
                t *= reduce;
            }

            if (best == null || bestWeight < weight) {
                best = now;
                bestWeight = weight;
            }
        }

        protected int nextInt(int l, int r) {
            return random.nextInt(r - l + 1) + l;
        }

        protected double nextDouble(double l, double r) {
            return (r - l) * random.nextDouble() + l;
        }

        public S getBest() {
            return best;
        }

        public double getBestWeight() {
            return bestWeight;
        }

        private S best;
        private double bestWeight;
        private Random random = new Random();
        private double threshold;
        /**
         * The larger k is, the more possible to challenge
         */
        private double k;
        /**
         * The smaller reduce is, the fast to reduce temperature
         */
        private double reduce;
    }

    public static class FastIO {
        public final StringBuilder cache = new StringBuilder(1 << 13);
        private final InputStream is;
        private final OutputStream os;
        private final Charset charset;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 13);
        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;

        public FastIO(InputStream is, OutputStream os, Charset charset) {
            this.is = is;
            this.os = os;
            this.charset = charset;
        }

        public FastIO(InputStream is, OutputStream os) {
            this(is, os, Charset.forName("ascii"));
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
            boolean sign = true;
            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+';
                next = read();
            }

            long val = 0;
            while (next >= '0' && next <= '9') {
                val = val * 10 + next - '0';
                next = read();
            }
            if (next != '.') {
                return sign ? val : -val;
            }
            next = read();
            long radix = 1;
            long point = 0;
            while (next >= '0' && next <= '9') {
                point = point * 10 + next - '0';
                radix = radix * 10;
                next = read();
            }
            double result = val + (double) point / radix;
            return sign ? result : -result;
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

        public int readLine(char[] data, int offset) {
            int originalOffset = offset;
            while (next != -1 && next != '\n') {
                data[offset++] = (char) next;
                next = read();
            }
            return offset - originalOffset;
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

        public char readChar() {
            skipBlank();
            char c = (char) next;
            next = read();
            return c;
        }

        public void flush() throws IOException {
            os.write(cache.toString().getBytes(charset));
            os.flush();
            cache.setLength(0);
        }

        public boolean hasMore() {
            skipBlank();
            return next != -1;
        }
    }

    public static class Debug {
        private boolean allowDebug;

        public Debug(boolean allowDebug) {
            this.allowDebug = allowDebug;
        }

        public void assertTrue(boolean flag) {
            if (!allowDebug) {
                return;
            }
            if (!flag) {
                fail();
            }
        }

        public void fail() {
            throw new RuntimeException();
        }

        public void assertFalse(boolean flag) {
            if (!allowDebug) {
                return;
            }
            if (flag) {
                fail();
            }
        }

        private void outputName(String name) {
            System.out.print(name + " = ");
        }

        public void debug(String name, int x) {
            if (!allowDebug) {
                return;
            }

            outputName(name);
            System.out.println("" + x);
        }

        public void debug(String name, long x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println("" + x);
        }

        public void debug(String name, double x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println("" + x);
        }

        public void debug(String name, int[] x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.toString(x));
        }

        public void debug(String name, long[] x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.toString(x));
        }

        public void debug(String name, double[] x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.toString(x));
        }

        public void debug(String name, Object x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println("" + x);
        }

        public void debug(String name, Object... x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.deepToString(x));
        }
    }
}