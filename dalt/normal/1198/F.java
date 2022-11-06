

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.util.*;

public class CF1198F {
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
        Gcd gcd = new Gcd();
        BitOperator bitOperator = new BitOperator();
        Random random = new Random(2);
        boolean[][] dp = new boolean[200][1 << 18];

        {
            dp[0][0] = true;
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
        int[] data;
        int[] group;
        boolean[] selected;

        public void solve() {
            n = io.readInt();
            data = new int[n];
            group = new int[n];
            selected = new boolean[n];
            for (int i = 0; i < n; i++) {
                data[i] = io.readInt();
            }

            if (n <= 20) {
                if (!bruteForce(0, 0, 0)) {
                    io.cache.append("NO");
                    return;
                }
                printGroups();
                return;
            }


            for (int i = 0; i < 5; i++) {
                int pick = random.nextInt(n - 1) + 1;
                swap(data, 1, pick);
                boolean flag = solveByDp();
                swap(data, 1, pick);
                swap(group, 1, pick);
                if (flag) {
                    printGroups();
                    return;
                }
            }

            io.cache.append("NO");
            return;
        }


        public void swap(int[] data, int i, int j) {
            int tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

        public int indexOf(int a, int b) {
            return (a << 9) | b;
        }


        int[] consideredData;
        int[] indexOfData = new int[200];
        int m;
        int[] a;
        int[] b;
        int aMask;
        int bMask;
        int aFactorNum;
        int bFactorNum;

        public void pick(int e, int remain, List<Integer> consideredList) {
            for (int i = 2; i < n && remain > 0; i++) {
                if (data[i] % e != 0) {
                    if (!selected[i]) {
                        selected[i] = true;
                        indexOfData[consideredList.size()] = i;
                        consideredList.add(data[i]);
                    }
                    remain--;
                }
            }
        }

        public boolean solveByDp() {
            Arrays.fill(group, 1);
            Arrays.fill(selected, false);
            group[0] = 1;
            group[1] = 2;

            int[] aFactor = factorOf(data[0]);
            int[] bFactor = factorOf(data[1]);
            aFactorNum = aFactor.length;
            bFactorNum = bFactor.length;
            aMask = (1 << aFactorNum) - 1;
            bMask = (1 << bFactorNum) - 1;

            List<Integer> consideredList = new ArrayList<>();
            consideredList.add(0);

            for (int e : aFactor) {
                int remain = bFactor.length + 1;
                pick(e, remain, consideredList);
            }

            for (int e : bFactor) {
                int remain = aFactor.length + 1;
                pick(e, remain, consideredList);
            }

            consideredData = consideredList.stream().mapToInt(Integer::intValue).toArray();
            m = consideredData.length;
            a = new int[m];
            b = new int[m];
            for (int i = 1; i < m; i++) {
                a[i] = bitOf(consideredData[i], aFactor);
                b[i] = bitOf(consideredData[i], bFactor);
            }


            for (int i = 1; i < m; i++) {
                for (int j = 0; j <= aMask; j++) {
                    for (int k = 0; k <= bMask; k++) {
                        int index = indexOf(j, k);
                        dp[i][index] = false;
                    }
                }

                for (int j = 0; j <= aMask; j++) {
                    for (int k = 0; k <= bMask; k++) {
                        int index = indexOf(j, k);
                        if (!dp[i - 1][index]) {
                            continue;
                        }
                        dp[i][indexOf(j | a[i], k)] = true;
                        dp[i][indexOf(j, k | b[i])] = true;
                    }
                }
            }

            if (dp[m - 1][indexOf(aMask, bMask)]) {
                display(m - 1, indexOf(aMask, bMask));
                return true;
            }

            return false;
        }

        public void display(int i, int status) {
            if (i == 0) {
                return;
            }
            for (int j = 0; j <= aMask; j++) {
                for (int k = 0; k <= bMask; k++) {
                    int index = indexOf(j, k);
                    if (!dp[i - 1][index]) {
                        continue;
                    }
                    if (indexOf(j | a[i], k) == status) {
                        display(i - 1, index);
                        group[indexOfData[i]] = 1;
                        return;
                    } else if (indexOf(j, k | b[i]) == status) {
                        display(i - 1, index);
                        group[indexOfData[i]] = 2;
                        return;
                    }
                }
            }
        }

        public int bitOf(int x, int[] factors) {
            int ans = 0;
            for (int i = 0, until = factors.length; i < until; i++) {
                if (x % factors[i] != 0) {
                    ans = bitOperator.setBit(ans, i, true);
                }
            }
            return ans;
        }

        public int[] factorOf(int x) {
            List<Integer> factors = new ArrayList<>();
            for (int i = 2; i * i <= x; i++) {
                if (x % i != 0) {
                    continue;
                }
                factors.add(i);
                while (x % i == 0) {
                    x /= i;
                }
            }
            if (x != 1) {
                factors.add(x);
            }
            return factors.stream().mapToInt(Integer::intValue).toArray();
        }

        public void printGroups() {
            io.cache.append("YES\n");
            for (int i = 0; i < n; i++) {
                io.cache.append(group[i]).append(' ');
            }
        }

        public boolean bruteForce(int i, int a, int b) {
            if (i == n) {
                return a == 1 && b == 1;
            }
            group[i] = 1;
            if (bruteForce(i + 1, gcd.gcd(a, data[i]), b)) {
                return true;
            }
            group[i] = 2;
            if (bruteForce(i + 1, a, gcd.gcd(b, data[i]))) {
                return true;
            }
            return false;
        }
    }

    /**
     * Bit operations
     */
    public static class BitOperator {
        public int bitAt(int x, int i) {
            return (x >> i) & 1;
        }

        public int bitAt(long x, int i) {
            return (int) ((x >> i) & 1);
        }

        public int setBit(int x, int i, boolean v) {
            if (v) {
                x |= 1 << i;
            } else {
                x &= ~(1 << i);
            }
            return x;
        }

        public long setBit(long x, int i, boolean v) {
            if (v) {
                x |= 1L << i;
            } else {
                x &= ~(1L << i);
            }
            return x;
        }

        /**
         * Determine whether x is subset of y
         */
        public boolean subset(long x, long y) {
            return intersect(x, y) == x;
        }

        /**
         * Merge two set
         */
        public long merge(long x, long y) {
            return x | y;
        }

        public long intersect(long x, long y) {
            return x & y;
        }

        public long differ(long x, long y) {
            return x - intersect(x, y);
        }
    }

    public static class Gcd {
        public long gcd(long a, long b) {
            return a >= b ? gcd0(a, b) : gcd0(b, a);
        }

        private long gcd0(long a, long b) {
            return b == 0 ? a : gcd0(b, a % b);
        }

        public int gcd(int a, int b) {
            return a >= b ? gcd0(a, b) : gcd0(b, a);
        }

        private int gcd0(int a, int b) {
            return b == 0 ? a : gcd0(b, a % b);
        }
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