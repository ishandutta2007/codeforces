

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.util.ArrayDeque;
import java.util.Comparator;
import java.util.Deque;

public class CF1071B {
    public static void main(String[] args) throws Exception {
        boolean local = System.getProperty("ONLINE_JUDGE") == null;
        boolean async = false;

        Charset charset = Charset.forName("ascii");

        FastIO io = local ? new FastIO(new FileInputStream("/Users/daltao/DATABASE/TESTCASE/Code.in"), System.out, charset) : new FastIO(System.in, System.out,
                charset);
        Task task = new Task(io);

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

        public Task(FastIO io) {
            this.io = io;
        }

        @Override
        public void run() {
            solve();
        }

        public void solve() {
            int n = io.readInt();
            int k = io.readInt();

            char[][] mat = new char[n][n];
            int[][] dp = new int[n][n];
            boolean[][] visited = new boolean[n][n];
            int longest = -1;
            Deque<int[]> deque = new ArrayDeque<>(2 * n);

            for (int i = 0; i < n; i++) {
                io.readString(mat[i], 0);
                for (int j = 0; j < n; j++) {
                    int need = mat[i][j] == 'a' ? 0 : 1;
                    if (i == 0 && j == 0) {
                        dp[i][j] = 0;
                    } else if (i == 0) {
                        dp[i][j] = dp[i][j - 1];
                    } else if (j == 0) {
                        dp[i][j] = dp[i - 1][j];
                    } else {
                        dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1]);
                    }

                    dp[i][j] += need;
                    if (dp[i][j] <= k) {
                        if (i + j > longest) {
                            deque.clear();
                            longest = i + j;
                        }
                        if (i + j == longest) {
                            deque.add(new int[] { i, j });
                        }
                    }
                }
            }

            if (longest == -1) {
                longest = 0;
                io.cache.append(mat[0][0]);
                deque.add(new int[] { 0, 0 });
            } else {
                for (int i = 0; i <= longest; i++) {
                    io.cache.append('a');
                }
            }

            Loop<Deque<int[]>> loop = new Loop<>(deque, new ArrayDeque<>(2 * n));
            for (int until = 2 * n - 2; longest < until; longest++) {
                Deque<int[]> lastLevel = loop.get(0);
                Deque<int[]> nextLevel = loop.turn(1);

                char standard = 'z';
                while (!lastLevel.isEmpty()) {
                    int[] pos = lastLevel.removeFirst();
                    if (pos[0] < n - 1) {
                        int i = pos[0] + 1;
                        int j = pos[1];
                        if (!visited[i][j]) {
                            visited[i][j] = true;
                            if (mat[i][j] < standard) {
                                standard = mat[i][j];
                                nextLevel.clear();
                            }
                            if (mat[i][j] == standard) {
                                nextLevel.add(new int[] { i, j });
                            }
                        }
                    }
                    if (pos[1] < n - 1) {
                        int i = pos[0];
                        int j = pos[1] + 1;
                        if (!visited[i][j]) {
                            visited[i][j] = true;
                            if (mat[i][j] < standard) {
                                standard = mat[i][j];
                                nextLevel.clear();
                            }
                            if (mat[i][j] == standard) {
                                nextLevel.add(new int[] { i, j });
                            }
                        }
                    }
                }
                io.cache.append(standard);
            }
        }
    }

    public static class Loop<T> {
        T[] data;
        int pos;

        public Loop(T... data) {
            this.data = data;
        }

        public T turn(int i) {
            pos += i;
            return get(0);
        }

        public T get(int i) {
            return data[(pos + i) % data.length];
        }
    }

    public static class FastIO {
        private final InputStream is;
        private final OutputStream os;
        private final Charset charset;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 8);
        public final StringBuilder cache = new StringBuilder();

        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;

        public FastIO(InputStream is, OutputStream os, Charset charset) {
            this.is = is;
            this.os = os;
            this.charset = charset;
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
            long num = readLong();
            if (next != '.') {
                return num;
            }

            next = read();
            long divisor = 1;
            long later = 0;
            while (next >= '0' && next <= '9') {
                divisor = divisor * 10;
                later = later * 10 + next - '0';
                next = read();
            }

            if (num >= 0) {
                return num + (later / (double) divisor);
            } else {
                return num - (later / (double) divisor);
            }
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

    public static class Memory {
        public static <T> void swap(T[] data, int i, int j) {
            T tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

        public static <T> int min(T[] data, int from, int to, Comparator<T> cmp) {
            int m = from;
            for (int i = from + 1; i < to; i++) {
                if (cmp.compare(data[m], data[i]) > 0) {
                    m = i;
                }
            }
            return m;
        }

        public static <T> void move(T[] data, int from, int to, int step) {
            int len = to - from;
            step = len - (step % len + len) % len;
            Object[] buf = new Object[len];
            for (int i = 0; i < len; i++) {
                buf[i] = data[(i + step) % len + from];
            }
            System.arraycopy(buf, 0, data, from, len);
        }

        public static <T> void reverse(T[] data, int f, int t) {
            int l = f, r = t - 1;
            while (l < r) {
                swap(data, l, r);
                l++;
                r--;
            }
        }

        public static void copy(Object[] src, Object[] dst, int srcf, int dstf, int len) {
            if (len < 8) {
                for (int i = 0; i < len; i++) {
                    dst[dstf + i] = src[srcf + i];
                }
            } else {
                System.arraycopy(src, srcf, dst, dstf, len);
            }
        }
    }
}