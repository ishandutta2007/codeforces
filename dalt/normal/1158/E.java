

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.util.Arrays;
import java.util.Iterator;
import java.util.TreeMap;
import java.util.TreeSet;

public class CF1158E {
    public static void main(String[] args) throws Exception {
        boolean local = false;
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
        char[] lights = new char[1001];

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

        int bitAt(int x, int i) {
            return (x >> i) & 1;
        }

        int bitAt(long x, int i) {
            return (int) ((x >> i) & 1);
        }

        public Task(FastIO io, Debug debug) {
            this.io = io;
            this.debug = debug;
        }

        @Override
        public void run() {
            solve();
        }

        Node[] nodes;
        int n;
        TreeSet<Integer> activeDepth = new TreeSet<>();
        TreeMap<Integer, Integer> queryDepth = new TreeMap<>();
        TreeSet<Integer> extra = new TreeSet<>();
        int m;
        int remain;
        int max = 0;

        public void solve() {
            //step 1
            n = io.readInt();
            nodes = new Node[n + 1];
            for (int i = 1; i <= n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
                nodes[i].depthLeq = n;
                nodes[i].depthGeq = 1;
                nodes[i].depth = -1;
            }

            nodes[1].depthLeq = nodes[1].depthGeq = nodes[1].depth = 0;
            activeDepth.add(nodes[1].depth);
            remain = n - 1;


            while (remain > 0) {
                max = 0;
                addQuery(0, 0);
                ask();
                addQuery(0, -1);
                ask();
                addQuery(1, 0);
                ask();
                addQuery(1, -1);
                ask();
                activeDepth.addAll(extra);
                extra.clear();
            }

            //step 2
            for (int i = 0; i < 3; i++) {
                findFather(i);
            }

            io.cache.append("!\n");
            for (int i = 2; i <= n; i++) {
                io.cache.append(i).append(' ').append(nodes[i].fatherId).append('\n');
            }
        }

        public void addQuery(int skip, int fix) {
            for (int i = 1; i <= n; i++) {
                max = Math.max(max, nodes[i].depthLeq);
            }

            queryDepth.clear();
            Iterator<Integer> iter = activeDepth.iterator();
            for (int i = 0; i < skip && iter.hasNext(); i++) {
                iter.next();
            }
            while (iter.hasNext()) {
                int next = iter.next();
                int dist = iter.hasNext() ? iter.next() : max;
                dist = (dist - next) / 2;
                dist += fix;
                if (dist > 0) {
                    queryDepth.put(next, dist);
                }
            }
        }

        public void findFather(int r) {
            for (int b = 1; b <= n; b <<= 1) {
                io.cache.append("? ");
                for (int i = 1; i <= n; i++) {
                    Node node = nodes[i];
                    if (node.depth % 3 != r || (i & b) == 0) {
                        io.cache.append(0).append(' ');
                    } else {
                        io.cache.append(1).append(' ');
                    }
                }
                io.cache.append('\n');
                io.flush();

                io.readString(lights, 1);
                for (int i = 1; i <= n; i++) {
                    if (lights[i] == '0' || nodes[i].depth % 3 != (r + 1) % 3) {
                        continue;
                    }
                    nodes[i].fatherId |= b;
                }
            }
        }

        public void ask() {
            io.cache.append("? ");
            for (int i = 1; i <= n; i++) {
                if (!queryDepth.containsKey(nodes[i].depth)) {
                    io.cache.append(0).append(' ');
                } else {
                    io.cache.append(queryDepth.get(nodes[i].depth)).append(' ');
                }
            }
            io.cache.append('\n');
            io.flush();
            io.readString(lights, 1);
            for (int i = 1; i <= n; i++) {
                Node node = nodes[i];
                if (node.depth != -1) {
                    continue;
                }
                Integer floor = queryDepth.floorKey(node.depthGeq);
                if (floor == null || floor + queryDepth.get(floor) < node.depthGeq) {
                    continue;
                }
                if (lights[i] == '1') {
                    node.depthLeq = Math.min(node.depthLeq, queryDepth.get(floor) + floor);
                } else {
                    node.depthGeq = Math.max(node.depthGeq, queryDepth.get(floor) + floor + 1);
                }

                if (node.depthLeq == node.depthGeq) {
                    node.depth = node.depthLeq;
                    extra.add(node.depth);
                    remain--;
                }
            }

            //debug.allowDebug = true;
            debug.debug("nodes", nodes);
        }
    }


    public static class Node {
        int fatherId;
        int depthGeq;
        int depthLeq;
        int depth;
        int id;
        int dist;

        @Override
        public String toString() {
            return id + "(" + depthGeq + "<" + depthLeq + ")";
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