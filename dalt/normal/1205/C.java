
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.UncheckedIOException;
import java.nio.charset.Charset;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

public class CF1205C {
    public static void main(String[] args) throws Exception {
        boolean local = false;//System.getProperty("ONLINE_JUDGE") == null;
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
            Ceil[][] grids = new Ceil[n + 1][n + 1];
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    grids[i][j] = new Ceil();
                    grids[i][j].i = i;
                    grids[i][j].j = j;
                }
            }
            grids[1][1].actualVal = 1;
            grids[n][n].actualVal = 0;

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if ((i + j) % 2 != 0 || grids[i][j].actualVal != -1) {
                        continue;
                    }
                    if (j > 2) {
                        grids[i][j].actualVal = ask(i, j - 2, i, j, grids[i][j - 2].actualVal);
                    } else if (i > 2) {
                        grids[i][j].actualVal = ask(i - 2, j, i, j, grids[i - 2][j].actualVal);
                    } else {
                        grids[i][j].actualVal = ask(i - 1, j - 1, i, j, grids[i - 1][j - 1].actualVal);
                    }
                }
            }

            grids[2][1].actualVal = 1;
            for (int i = 2; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if ((i + j) % 2 == 0 || grids[i][j].actualVal != -1) {
                        continue;
                    }
                    if (j > 2) {
                        grids[i][j].actualVal = ask(i, j - 2, i, j, grids[i][j - 2].actualVal);
                    } else if (i > 3) {
                        grids[i][j].actualVal = ask(i - 2, j, i, j, grids[i - 2][j].actualVal);
                    } else {
                        grids[i][j].actualVal = ask(i - 1, j - 1, i, j, grids[i - 1][j - 1].actualVal);
                    }
                }
            }

            for (int j = 1; j <= n; j++) {
                if ((1 + j) % 2 == 0 || grids[1][j].actualVal != -1) {
                    continue;
                }
                grids[1][j].actualVal = ask(1, j, 3, j, grids[3][j].actualVal);
            }

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (dfs(grids, i, j, 0)) {
                        break;
                    }
                }
            }

            int same = ask(deque.peekFirst().i,
                    deque.peekFirst().j,
                    deque.peekLast().i,
                    deque.peekLast().j);

            boolean holdOn;
            Ceil even = deque.peekFirst().isEven() ? deque.peekFirst() : deque.peekLast();
            Ceil odd = deque.peekFirst().isEven() ? deque.peekLast() : deque.peekFirst();
            if (same == 1) {
                holdOn = odd.actualVal == even.actualVal;
            } else {
                holdOn = odd.actualVal != even.actualVal;
            }

            if (!holdOn) {
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        if ((i + j) % 2 == 0) {
                            continue;
                        }
                        grids[i][j].actualVal = 1 - grids[i][j].actualVal;
                    }
                }
            }

            io.cache.append("!\n");
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    io.cache.append(grids[i][j].actualVal);
                }
                io.cache.append('\n');
            }
        }

        Deque<Ceil> deque = new ArrayDeque<>();

        public boolean dfs(Ceil[][] grids, int i, int j, int xor) {
            if (deque.size() == 4) {
                return xor == 0;
            }
            if (i >= grids.length || j >= grids[0].length) {
                return false;
            }
            deque.addLast(grids[i][j]);
            xor ^= grids[i][j].actualVal;
            boolean ans = dfs(grids, i + 1, j, xor) ||
                    dfs(grids, i, j + 1, xor);
            if (ans) {
                return true;
            }
            deque.removeLast();
            return false;
        }

        public int ask(int x1, int y1, int x2, int y2, int def) {
            return ask(x1, y1, x2, y2) == 1 ? def : (1 - def);
        }

        public int ask(int x1, int y1, int x2, int y2) {
            io.cache.append("? ").append(x1).append(' ')
                    .append(y1).append(' ').append(x2).append(' ')
                    .append(y2).append('\n');
            io.flush();
            return io.readInt();
        }
    }

    public static class Ceil {
        int i;
        int j;
        int actualVal = -1;

        public boolean isEven() {
            return (i + j) % 2 == 0;
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

        public void flush() {

            try {
                os.write(cache.toString().getBytes(charset));
                os.flush();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
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