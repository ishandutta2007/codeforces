import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 27);
        thread.start();
        thread.join();
    }

    static class TaskAdapter implements Runnable {
        @Override
        public void run() {
            InputStream inputStream = System.in;
            OutputStream outputStream = System.out;
            FastInput in = new FastInput(inputStream);
            FastOutput out = new FastOutput(outputStream);
            TaskD solver = new TaskD();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskD {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();

            TaskD.Node[] nodes = new TaskD.Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new TaskD.Node();
                nodes[i].l = nodes[i].r = i;
            }

            int[][] edges = new int[m][2];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < 2; j++) {
                    edges[i][j] = in.readInt() - 1;
                }
            }

            for (int[] e : edges) {
                TaskD.Node.merge(nodes[e[0]], nodes[e[1]]);
            }

            int cc = 0;
            for (int i = 0; i < n; i++) {
                if (nodes[i].find() == nodes[i]) {
                    cc++;
                }
            }

            for (int i = 0; i < n; i++) {
                nodes[i].init();
            }

            for (int[] e : edges) {
                TaskD.Node a = nodes[e[0]].find();
                TaskD.Node b = nodes[e[1]].find();
                if (a.r > b.l) {
                    TaskD.Node tmp = a;
                    a = b;
                    b = tmp;
                }

                while (a.find().r < b.find().l) {
                    TaskD.Node next = nodes[a.find().r + 1].find();
                    TaskD.Node.merge(a, next);
                    a.find().r = next.r;
                }
            }

            int curCC = 0;
            for (int i = 0; i < n; i++) {
                if (nodes[i].find() == nodes[i]) {
                    curCC++;
                }
            }

            out.println(cc - curCC);
        }

        static class Node {
            TaskD.Node p = this;
            int rank;
            int l;
            int r;

            public void init() {
                p = this;
                rank = 0;
            }

            public TaskD.Node find() {
                return p.p == p ? p : (p = p.find());
            }

            public static void merge(TaskD.Node a, TaskD.Node b) {
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
                } else {
                    a.p = b;
                }
            }

        }

    }

    static class FastOutput implements AutoCloseable, Closeable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput println(int c) {
            cache.append(c).append('\n');
            return this;
        }

        public FastOutput flush() {
            try {
                os.append(cache);
                os.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
            return this;
        }

        public void close() {
            flush();
            try {
                os.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

        public String toString() {
            return cache.toString();
        }

    }

    static class FastInput {
        private final InputStream is;
        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;

        public FastInput(InputStream is) {
            this.is = is;
        }

        private int read() {
            while (bufLen == bufOffset) {
                bufOffset = 0;
                try {
                    bufLen = is.read(buf);
                } catch (IOException e) {
                    bufLen = -1;
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

    }
}