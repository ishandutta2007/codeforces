
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.util.Arrays;

public class CF449D {
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
        Modular mod = new Modular(1000000007);
        int[] pow2;
        int limit = 1 << 20;
        int[] cnts;

        public Task(FastIO io, Debug debug) {
            this.io = io;
            this.debug = debug;
        }

        @Override
        public void run() {
            solve();
        }

        public void solve() {
            int n = io.readInt();
            int[] A = new int[n];
            for (int i = 0; i < n; i++) {
                A[i] = io.readInt();
            }

            pow2 = new int[limit];
            pow2[0] = 1;
            for (int i = 1; i < limit; i++) {
                pow2[i] = mod.mul(pow2[i - 1], 2);
            }

            cnts = new int[limit];
            for (int i = 0; i < n; i++) {
                cnts[A[i]]++;
            }

            FastWalshHadamardTransform.AndFWT(cnts, 0, limit - 1, mod);
            int ans = inclusiveExclusive(20, 0, 0);
            io.cache.append(ans);
        }

        public int inclusiveExclusive(int i, int or, int cnt) {
            if (or >= limit) {
                return 0;
            }
            if (i < 0) {
//                if (cnts[or] > 0) {
//                    debug.debug("or", or);
//                    debug.debug("cnt", cnts[or]);
//                }
                if (cnt % 2 == 0) {
                    return mod.subtract(pow2[cnts[or]], 1);
                } else {
                    return mod.valueOf(-mod.subtract(pow2[cnts[or]], 1));
                }
            }
            int ans = mod.plus(inclusiveExclusive(i - 1, or, cnt), inclusiveExclusive(i - 1, or | (1 << i), cnt + 1));
            return ans;
        }
    }


    /**
     * Mod operations
     */
    public static class Modular {
        int m;

        public Modular(int m) {
            this.m = m;
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

        public int mul(long x, long y) {
            x = valueOf(x);
            y = valueOf(y);
            return valueOf(x * y);
        }

        public int plus(int x, int y) {
            return valueOf(x + y);
        }

        public int plus(long x, long y) {
            x = valueOf(x);
            y = valueOf(y);
            return valueOf(x + y);
        }

        public int subtract(int x, int y) {
            return valueOf(x - y);
        }

        public int subtract(long x, long y) {
            return valueOf(x - y);
        }

        @Override
        public String toString() {
            return "mod " + m;
        }
    }

    public static class FastWalshHadamardTransform {
        public static void OrFWT(int[] p, int l, int r) {
            if (l == r) {
                return;
            }
            int m = (l + r) >> 1;
            OrFWT(p, l, m);
            OrFWT(p, m + 1, r);
            for (int i = 0, until = m - l; i <= until; i++) {
                int a = p[l + i];
                int b = p[m + 1 + i];
                p[m + 1 + i] = a + b;
            }
        }

        public static void OrIFWT(int[] p, int l, int r) {
            if (l == r) {
                return;
            }
            int m = (l + r) >> 1;
            for (int i = 0, until = m - l; i <= until; i++) {
                int a = p[l + i];
                int b = p[m + 1 + i];
                p[m + 1 + i] = b - a;
            }
            OrIFWT(p, l, m);
            OrIFWT(p, m + 1, r);
        }

        public static void AndFWT(int[] p, int l, int r, Modular mod) {
            if (l == r) {
                return;
            }
            int m = (l + r) >> 1;
            AndFWT(p, l, m, mod);
            AndFWT(p, m + 1, r, mod);
            for (int i = 0, until = m - l; i <= until; i++) {
                int a = p[l + i];
                int b = p[m + 1 + i];
                p[l + i] = mod.plus(a, b);
            }
        }

        public static void AndIFWT(int[] p, int l, int r) {
            if (l == r) {
                return;
            }
            int m = (l + r) >> 1;
            for (int i = 0, until = m - l; i <= until; i++) {
                int a = p[l + i];
                int b = p[m + 1 + i];
                p[l + i] = a - b;
            }
            AndIFWT(p, l, m);
            AndIFWT(p, m + 1, r);
        }

        public static void XorFWT(int[] p, int l, int r) {
            if (l == r) {
                return;
            }
            int m = (l + r) >> 1;
            XorFWT(p, l, m);
            XorFWT(p, m + 1, r);
            for (int i = 0, until = m - l; i <= until; i++) {
                int a = p[l + i];
                int b = p[m + 1 + i];
                p[l + i] = a + b;
                p[m + 1 + i] = a - b;
            }
        }

        public static void XorIFWT(int[] p, int l, int r) {
            if (l == r) {
                return;
            }
            int m = (l + r) >> 1;
            for (int i = 0, until = m - l; i <= until; i++) {
                int a = p[l + i];
                int b = p[m + 1 + i];
                p[l + i] = (a + b) / 2;
                p[m + 1 + i] = (a - b) / 2;
            }
            XorIFWT(p, l, m);
            XorIFWT(p, m + 1, r);
        }

        public static void DotMul(int[] a, int[] b, int n) {
            for (int i = 0; i < n; i++) {
                a[i] = a[i] * b[i];
            }
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