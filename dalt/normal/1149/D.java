

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.List;

public class CF1149DV2 {
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

        public void solve() {
            int n = io.readInt();
            int m = io.readInt();

            int light = io.readInt();
            int heavy = io.readInt();

            Node[] nodes = new Node[n + 1];
            for (int i = 1; i <= n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
            }

            for (int i = 1; i <= m; i++) {
                Edge edge = new Edge();
                edge.a = nodes[io.readInt()];
                edge.b = nodes[io.readInt()];
                edge.w = io.readInt();
                edge.light = edge.w == light;

                edge.a.edges.add(edge);
                edge.b.edges.add(edge);


                if (edge.light) {
                    Node.union(edge.a, edge.b);
                }
            }

            int numberOfConnectedComponents = 0;
            for (int i = 1; i <= n; i++) {
                if (nodes[i].find() != nodes[i] ||
                        nodes[i].find().size < 4) {
                    continue;
                }
                nodes[i].bit = 1 << numberOfConnectedComponents;
                numberOfConnectedComponents++;
            }

            for (int i = 1; i <= n; i++) {
                nodes[i].bit = nodes[i].find().bit;
                nodes[i].set = nodes[i].find().id;
            }

            int mask = 1 << numberOfConnectedComponents;
            Status[][] statuses = new Status[n + 1][mask];
            Deque<Status> lightDeque = new ArrayDeque<>();
            Deque<Status> heavyDeque = new ArrayDeque<>();
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < mask; j++) {
                    statuses[i][j] = new Status();
                    statuses[i][j].status = j;
                    statuses[i][j].vertex = i;
                    statuses[i][j].dist = Integer.MAX_VALUE;
                    statuses[i][j].inque = true;
                }
            }

            lightDeque.add(statuses[1][0]);
            statuses[1][0].dist = 0;

            while (!(lightDeque.isEmpty() && heavyDeque.isEmpty())) {
                Status head;
                if (lightDeque.isEmpty()) {
                    head = heavyDeque.removeFirst();
                } else if (heavyDeque.isEmpty()) {
                    head = lightDeque.removeFirst();
                } else {
                    if (lightDeque.peekFirst().dist < heavyDeque.peekFirst().dist) {
                        head = lightDeque.removeFirst();
                    } else {
                        head = heavyDeque.removeFirst();
                    }
                }
                if (!head.inque) {
                    continue;
                }
                head.inque = false;

                Node vertex = nodes[head.vertex];
                for (Edge edge : vertex.edges) {
                    Node nextNode = edge.another(vertex);
                    int nextStatus = head.status;
                    if (nextNode.set == vertex.set) {
                        //forbidden heavy edge
                        if (!edge.light) {
                            continue;
                        }
                    } else {
                        if ((nextNode.bit & nextStatus) != 0) {
                            //forbidden
                            continue;
                        }
                        nextStatus |= vertex.bit;
                    }
                    int dist = edge.w + head.dist;
                    Status next = statuses[nextNode.id][nextStatus];
                    if (next.dist <= dist) {
                        continue;
                    }
                    next.dist = dist;
                    if (edge.light) {
                        lightDeque.add(next);
                    } else {
                        heavyDeque.add(next);
                    }
                }
            }

            for (int i = 1; i <= n; i++) {
                int min = Integer.MAX_VALUE;
                for (int j = 0; j < mask; j++) {
                    min = Math.min(statuses[i][j].dist, min);
                }
                io.cache.append(min).append('\n');
            }
        }
    }

    public static class Status {
        int status;
        int dist;
        int vertex;
        boolean inque;

        @Override
        public String toString() {
            return "" + vertex;
        }
    }

    public static class Node {
        List<Edge> edges = new ArrayList<>();
        int id;
        Node p = this;
        int rank = 0;
        int bit;
        int size = 1;
        int set;

        Node find() {
            return p.p == p ? p : (p = p.find());
        }

        static void union(Node a, Node b) {
            a = a.find();
            b = b.find();
            if (a == b) {
                return;
            }
            if (a.rank == b.rank) {
                a.rank++;
            }
            if (a.rank > b.rank) {
                b.p = a;
                a.size += b.size;
            } else {
                a.p = b;
                b.size += a.size;
            }
        }

        @Override
        public String toString() {
            return "" + id;
        }
    }

    public static class Edge {
        Node a;
        Node b;
        int w;
        boolean light;

        Node another(Node x) {
            return a == x ? b : a;
        }

        @Override
        public String toString() {
            return a + "->" + b;
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