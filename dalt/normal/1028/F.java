

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.util.*;

public class CF1028F {
    public static void main(String[] args) throws Exception {
        boolean local = System.getProperty("ONLINE_JUDGE") == null;
        boolean async = false;

        Charset charset = Charset.forName("ascii");

        FastIO io = local ? new FastIO(new FileInputStream("E:\\DATABASE\\TESTCASE\\CF1028F.in"), System.out, charset) : new FastIO(System.in, System.out, charset);
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
        static Point reuse = new Point(0, 0);

        public Task(FastIO io) {
            this.io = io;
        }

        @Override
        public void run() {
            solve();
        }

        public void solve() {
            int n = io.readInt();

            Map<Point, int[]> countMap = new TreeMap<>();
            Map<Long, List<Point>> distanceMap = new HashMap<>();

            int[][] query = new int[n][3];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 3; j++) {
                    query[i][j] = io.readInt();
                }
                if (query[i][0] == 1) {
                    Point point = new Point(query[i][1], query[i][2]);
                    distanceMap.put(point.distance(), new ArrayList<>());
                } else if (query[i][0] == 3) {
                    Point point = new Point(query[i][1], query[i][2]);
                    countMap.put(point, new int[1]);
                }
            }

            int totalPointNumber = 0;
            for (int i = 0; i < n; i++) {
                int type = query[i][0];
                int x = query[i][1];
                int y = query[i][2];

                Point mentionedPoint = new Point(x, y);

                List<Point> distanceList = distanceMap.get(mentionedPoint.distance());

                switch (type) {
                    case 1: {
                        //check distanceList
                        for (Point point : distanceList) {
                            //for point (a, b)
                            //the cross value is a * (x1 - x2) + b * (y1 - y2) = 0
                            //so let's assume a = x1, then b = -x1 * (x1 - x2) / (y1 - y2)
                            long dx = x - point.x;
                            long dy = y - point.y;
                            long a = Math.abs(dy);
                            long b = Math.abs(dx);

                            reuse.x = a;
                            reuse.y = b;

                            int[] count = countMap.get(reuse);
                            if (count != null) {
                                count[0] -= 2;
                            }
                        }

                        int[] count = countMap.get(mentionedPoint);
                        if (count != null) {
                            count[0]--;
                        }
                        distanceList.add(mentionedPoint);
                        totalPointNumber++;
                        break;
                    }
                    case 2: {
                        distanceList.remove(mentionedPoint);
                        //check distanceList
                        for (Point point : distanceList) {
                            long dx = x - point.x;
                            long dy = y - point.y;
                            long a = Math.abs(dy);
                            long b = Math.abs(dx);
                            reuse.x = a;
                            reuse.y = b;

                            int[] count = countMap.get(reuse);
                            if (count != null) {
                                count[0] += 2;
                            }
                        }
                        int[] count = countMap.get(mentionedPoint);
                        if (count != null) {
                            count[0]++;
                        }
                        totalPointNumber--;
                        break;
                    }
                    case 3: {
                        //Do query
                        int fix = countMap.get(mentionedPoint)[0];
                        io.cache.append(totalPointNumber + fix).append('\n');
                        break;
                    }
                }
            }
        }
    }

    public static class Point implements Comparable<Point> {
        long x;
        long y;

        public Point(long x, long y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Point o) {
            return Long.compare(cross(this, o), 0);
        }

        public static long cross(Point a, Point b) {
            return a.x * b.y - a.y * b.x;
        }

        public long distance() {
            return x * x + y * y;
        }

        @Override
        public boolean equals(Object obj) {
            Point other = (Point) obj;
            return x == other.x && y == other.y;
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