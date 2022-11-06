

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.util.Arrays;

public class CF1115F {
    public static void main(String[] args) throws Exception {
        boolean local = System.getProperty("ONLINE_JUDGE") == null;
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
        int mod = (int) 1e9 + 7;

        public int mod(int val) {
            val %= mod;
            if (val < 0) {
                val += mod;
            }
            return val;
        }

        public int mod(long val) {
            val %= mod;
            if (val < 0) {
                val += mod;
            }
            return (int) val;
        }

        public Task(FastIO io, Debug debug) {
            this.io = io;
            this.debug = debug;
        }

        @Override
        public void run() {
            solve();
        }

        int n;
        int m;
        boolean[][] edges;
        int[] connectedComponent;
        int mask;
        int[][][] asChain;
        int[] minEdgeMaintained;
        SubsetGenerator generator;

        public void solve() {
            n = io.readInt();
            m = io.readInt();
            edges = new boolean[n][n];
            connectedComponent = new int[n];
            for (int i = 0; i < m; i++) {
                int a = io.readInt() - 1;
                int b = io.readInt() - 1;
                edges[a][b] = edges[b][a] = true;
                connectedComponent[a] |= 1 << b;
                connectedComponent[b] |= 1 << a;
            }

            mask = 1 << n;

            asChain = new int[n][n][mask];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    Arrays.fill(asChain[i][j], -1);
                }
            }
            for (int i = 0; i < n; i++) {
                asChain[i][i][1 << i] = 0;
            }
            for (int k = 0; k < mask; k++) {
                for (int i = 0; i < n; i++) {
                    if (bitAt(k, i) == 0) {
                        continue;
                    }
                    for (int j = 0; j < n; j++) {
                        if (i == j) {
                            continue;
                        }
                        if (bitAt(k, j) != 1) {
                            continue;
                        }
                        for (int t = 0; t < n; t++) {
                            if (!edges[i][t]) {
                                continue;
                            }
                            if (bitAt(k, t) != 1) {
                                continue;
                            }
                            if (asChain[t][j][k ^ (1 << i)] != -1) {
                                asChain[i][j][k] = asChain[t][j][k ^ (1 << i)] + 1;
                                break;
                            }
                        }
                    }
                }
            }

            minEdgeMaintained = new int[mask];
            Arrays.fill(minEdgeMaintained, inf);
            minEdgeMaintained[0] = 0;
            for (int i = 0; i < n; i++) {
                minEdgeMaintained[1 << i] = 0;
            }
            generator = new SubsetGenerator();

            for (int i = 1; i < mask; i += 2) {
                if ((i & (i - 1)) == 0) {
                    continue;
                }
                generator.setSet(i ^ 1);
                while (generator.hasNext()) {
                    int subset = generator.next();
                    if (subset == 0 || subset == i) {
                        continue;
                    }
                    int remainPart = i ^ subset;
                    //only one bit
                    if ((subset & (subset - 1)) == 0) {
                        int k = 31 - Integer.numberOfLeadingZeros(subset);
                        int connect = Integer.bitCount(connectedComponent[k] & remainPart);
                        if (connect >= 2) {
                            minEdgeMaintained[i] = Math.min(minEdgeMaintained[i], minEdgeMaintained[remainPart]
                                    + 2);
                        }
                    } else {
                        //several bits
                        for (int j = 1; j < n; j++) {
                            if (bitAt(subset, j) == 0) {
                                continue;
                            }
                            if ((connectedComponent[j] & remainPart) == 0) {
                                continue;
                            }
                            for (int k = 1; k < n; k++) {
                                if (j == k) {
                                    continue;
                                }
                                if (asChain[j][k][subset] == -1) {
                                    continue;
                                }
                                if ((connectedComponent[k] & remainPart) == 0) {
                                    continue;
                                }
                                minEdgeMaintained[i] = Math.min(minEdgeMaintained[i],
                                        asChain[j][k][subset] + 2 + minEdgeMaintained[remainPart]);
                            }
                        }
                    }
                }
            }

            io.cache.append(minEdgeMaintained[(1 << n) - 1]).append('\n');
            resolveMinEdgeMaintained((1 << n) - 1);
        }

        public void outputEdge(int i, int j) {
            io.cache.append(i + 1).append(' ').append(j + 1).append('\n');
        }

        public void resolveMinEdgeMaintained(int status) {
            if ((status & (status - 1)) == 0) {
                return;
            }
            generator.setSet(status ^ 1);
            while (generator.hasNext()) {
                int subset = generator.next();
                if (subset == 0 || subset == status) {
                    continue;
                }
                int remainPart = status ^ subset;
                if ((subset & (subset - 1)) == 0) {
                    int k = 31 - Integer.numberOfLeadingZeros(subset);
                    int connect = Integer.bitCount(connectedComponent[k] & remainPart);
                    if (connect >= 2) {
                        if (minEdgeMaintained[status] == minEdgeMaintained[remainPart]
                                + 2) {
                            int bits = connectedComponent[k] & remainPart;
                            outputEdge(k, getId(bits & -bits));
                            bits = bits & (bits - 1);
                            outputEdge(k, getId(bits & -bits));
                            resolveMinEdgeMaintained(remainPart);
                            return;
                        }
                    }
                } else {
                    //several bits
                    for (int j = 1; j < n; j++) {
                        if (bitAt(subset, j) == 0) {
                            continue;
                        }
                        if ((connectedComponent[j] & remainPart) == 0) {
                            continue;
                        }
                        for (int k = 1; k < n; k++) {
                            if (j == k) {
                                continue;
                            }
                            if (asChain[j][k][subset] == -1) {
                                continue;
                            }
                            if ((connectedComponent[k] & remainPart) == 0) {
                                continue;
                            }
                            if (minEdgeMaintained[status] ==
                                    asChain[j][k][subset] + 2 + minEdgeMaintained[remainPart]) {
                                int bits = connectedComponent[j] & remainPart;
                                outputEdge(j, getId(bits & -bits));
                                bits = connectedComponent[k] & remainPart;
                                outputEdge(k, getId(bits & -bits));
                                resolveChain(j, k, subset);
                                resolveMinEdgeMaintained(remainPart);
                                return;
                            }
                        }
                    }
                }
            }
        }

        public int getId(int bit) {
            return 31 - Integer.numberOfLeadingZeros(bit);
        }

        public void resolveChain(int i, int j, int status) {
            if (i == j) {
                return;
            }
            for (int k = 0; k < n; k++) {
                if (!edges[i][k]) {
                    continue;
                }
                int remainStatus = status ^ (1 << i);
                if (asChain[k][j][remainStatus] == -1) {
                    continue;
                }
                if (asChain[k][j][remainStatus] + 1 != asChain[i][j][status]) {
                    continue;
                }
                outputEdge(i, k);
                resolveChain(k, j, remainStatus);
                return;
            }
        }

        public static int bitAt(int mask, int i) {
            return (mask >> i) & 1;
        }
    }

    public static class SubsetGenerator {
        private int[] meanings = new int[33];
        private int[] bits = new int[33];
        private int remain;
        private int next;

        public void setSet(int set) {
            int bitCount = 0;
            while (set != 0) {
                meanings[bitCount] = set & -set;
                bits[bitCount] = 0;
                set -= meanings[bitCount];
                bitCount++;
            }
            remain = 1 << bitCount;
            next = 0;
        }

        public boolean hasNext() {
            return remain > 0;
        }

        private void consume() {
            remain = remain - 1;
            int i;
            for (i = 0; bits[i] == 1; i++) {
                bits[i] = 0;
                next -= meanings[i];
            }
            bits[i] = 1;
            next += meanings[i];
        }

        public int next() {
            int returned = next;
            consume();
            return returned;
        }
    }


    public static class FastIO {
        public final StringBuilder cache = new StringBuilder();
        private final InputStream is;
        private final OutputStream os;
        private final Charset charset;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 8);
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

        public void flush() {
            try {
                os.write(cache.toString().getBytes(charset));
                os.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
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