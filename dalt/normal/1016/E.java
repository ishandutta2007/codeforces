
import java.io.*;
import java.nio.charset.Charset;
import java.text.DecimalFormat;
import java.util.Comparator;
import java.util.TreeMap;
import java.util.TreeSet;

public class CF1016E {
    public static void main(String[] args) throws Exception {
        boolean local = System.getProperty("ONLINE_JUDGE") == null;
        boolean async = false;

        Charset charset = Charset.forName("ascii");

        FastIO io = local ? new FastIO(new FileInputStream("/Users/daltao/DATABASE/TESTCASE/CF1016E.in"), System.out, charset) : new FastIO(System.in, System.out, charset);
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
            io.cache.append("\n\n--memory -- " + (Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()));
        }

        io.flush();
    }

    public static class Task implements Runnable {
        final FastIO io;
        final int MAX = (int) (1e9 + 1);
        final int MIN = (int) (0);

        public Task(FastIO io) {
            this.io = io;
        }

        @Override
        public void run() {
            solve();
        }

        public void solve() {
            int sy = io.readInt();
            int left = io.readInt();
            int right = io.readInt();

            int n = io.readInt();
            int[][] lines = new int[n + 1][3];

            TreeSet<int[]> leftEndpointSet = new TreeSet<>((a, b) -> Integer.compare(a[0], b[0]));
            for (int i = 1; i <= n; i++) {
                lines[i][0] = io.readInt();
                lines[i][1] = io.readInt();
                lines[i][2] = i;
                leftEndpointSet.add(lines[i]);
            }

            double[] totalLength = new double[n + 1];
            for (int i = 1; i <= n; i++) {
                totalLength[i] = totalLength[i - 1] + lines[i][1] - lines[i][0];
            }

            int q = io.readInt();
            int[] reuse = new int[3];
            DecimalFormat format = new DecimalFormat("0.0000000000#");
            for (int i = 0; i < q; i++) {
                int x = io.readInt();
                int y = io.readInt();

                double rate = (double) y / (y - sy);

                double leftIntersect = x - (x - left) * rate;
                double rightIntersect = x + (right - x) * rate;

                reuse[0] = roundInto(leftIntersect);
                int[] leftLine = leftEndpointSet.floor(reuse);

                reuse[0] = roundInto(rightIntersect);
                int[] rightLine = leftEndpointSet.floor(reuse);

                int lIndex;
                int rIndex;
                double subtract = 0;
                if (leftLine == null) {
                    lIndex = 1;
                } else if (isInclude(leftLine[0], leftLine[1], leftIntersect)) {
                    lIndex = leftLine[2];
                    subtract += leftIntersect - leftLine[0];
                } else {
                    lIndex = leftLine[2] + 1;
                }

                if (rightLine == null) {
                    rIndex = 0;
                } else if (isInclude(rightLine[0], rightLine[1], rightIntersect)) {
                    rIndex = rightLine[2];
                    subtract += rightLine[1] - rightIntersect;
                } else {
                    rIndex = rightLine[2];
                }

                double totalXCoverage = totalLength[rIndex] - totalLength[lIndex - 1] - subtract;
                double shadowSize = totalXCoverage / rate;

                io.cache.append(format.format(shadowSize)).append('\n');
            }
        }

        public int roundInto(double val) {
            if (val > MAX) {
                return MAX;
            }
            if (val < MIN) {
                return MIN;
            }
            return (int) val;
        }

        public boolean isInclude(int l, int r, double p) {
            return l <= p && r >= p;
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
    }
}