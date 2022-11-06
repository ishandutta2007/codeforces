

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.util.*;

public class CFECR47F {
    public static void main(String[] args) throws Exception {
        boolean local = System.getProperty("ONLINE_JUDGE") == null;
        boolean async = false;

        Charset charset = Charset.forName("ascii");

        FastIO io = local ? new FastIO(new FileInputStream("/Users/daltao/DATABASE/TESTCASE/CFECR47F.in"), System.out, charset) : new FastIO(System.in, System.out, charset);
        Task task = new Task(io);

        if (async) {
            Thread t = new Thread(null, task, "dalt", 1 << 27);
            t.setPriority(Thread.MAX_PRIORITY);
            t.start();
            t.join();
        } else {
            task.run();
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

            Node[] nodes = new Node[n + 1];
            for (int i = 0; i <= n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
            }

            for (int i = 1; i < n; i++) {
                Node a = nodes[io.readInt()];
                Node b = nodes[io.readInt()];

                a.nearby.add(b);
                b.nearby.add(a);
            }

            dfs(nodes[1], nodes[0]);

            for (int i = 1; i <= n; i++) {
                io.cache.append(nodes[i].domainDepth).append('\n');
            }
        }

        public static FastDepthMap dfs(Node root, Node father) {
            root.depth = father.depth + 1;

            FastDepthMap map = null;
            for (Node child : root.nearby) {
                if (child == father) {
                    continue;
                }
                FastDepthMap childMap = dfs(child, root);
                if (map == null) {
                    map = childMap;
                } else {
                    map = FastDepthMap.merge(map, childMap);
                }
            }

            if (map == null) {
                map = new FastDepthMap();
            } else {
                map.list.extend(1);
            }

            root.domainDepth = map.list.getDistanceToTail();

            return map;
        }
    }


    public static class Node {
        List<Node> nearby = new ArrayList<>(1);
        int depth;
        int domainDepth;
        int id;

        @Override
        public String toString() {
            return "" + id;
        }
    }

    public static class MaxList {
        List<Integer> list = new ArrayList<>(1);
        int maxIndex = 0;
        int maxValue = 0;

        public void extend(int i) {
            list.add(i);
            if (i >= maxValue) {
                maxIndex = list.size() - 1;
                maxValue = i;
            }
        }

        public void add(int i, int v) {
            int newVal = list.get(i) + v;
            list.set(i, newVal);
            if (newVal != maxValue ? newVal > maxValue : i > maxIndex) {
                maxIndex = i;
                maxValue = newVal;
            }
        }

        public int getMaxIndex() {
            return maxIndex;
        }

        public int getDistanceToTail() {
            return list.size() - maxIndex - 1;
        }

        public int getSize() {
            return list.size();
        }

        public int get(int i) {
            return list.get(i);
        }
    }

    public static class FastDepthMap {
        MaxList list = new MaxList();

        public FastDepthMap() {
            list.extend(1);
        }

        public static FastDepthMap merge(FastDepthMap a, FastDepthMap b) {
            if (a.list.getSize() < b.list.getSize()) {
                FastDepthMap tmp = a;
                a = b;
                b = tmp;
            }


            for (int i = a.list.getSize() - 1, j = b.list.getSize() - 1; j >= 0; i--, j--) {
                a.list.add(i, b.list.get(j));
            }

            return a;
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