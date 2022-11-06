import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.util.Deque;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 29);
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
            FGraphTraveler solver = new FGraphTraveler();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FGraphTraveler {
        static int lcm = 8 * 9 * 7 * 5;
        static Modular mod = new Modular(lcm);
        Deque<Node> deque = new ArrayDeque<>(lcm * 1000);
        IntegerVersionArray iva = new IntegerVersionArray(1000);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int[] tags = new int[n];
            for (int i = 0; i < n; i++) {
                tags[i] = mod.valueOf(in.readInt());
            }
            int[][] edges = new int[n][];
            for (int i = 0; i < n; i++) {
                int k = in.readInt();
                edges[i] = new int[k];
                for (int j = 0; j < k; j++) {
                    edges[i][j] = in.readInt() - 1;
                }
            }
            Node[][] nodes = new Node[n][lcm];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < lcm; j++) {
                    nodes[i][j] = new Node();
                    nodes[i][j].id = i;
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < lcm; j++) {
                    int val = mod.plus(j, tags[i]);
                    nodes[i][j].next = nodes[edges[i][val % edges[i].length]][val];
                }
            }

            int q = in.readInt();
            for (int i = 0; i < q; i++) {
                int x = in.readInt() - 1;
                int y = mod.valueOf(in.readInt());
                int ans = dp(nodes[x][y]);
                out.println(ans);
            }
        }

        public int dp(Node root) {
            if (root.cnt == -2) {
                //find a loop
                iva.clear();
                root.cnt = 0;
                while (true) {
                    Node last = deque.removeLast();
                    last.instk = false;
                    if (iva.get(last.id) == 0) {
                        iva.set(last.id, 1);
                        root.cnt++;
                    }
                    if (last == root) {
                        break;
                    }
                }
                return root.cnt;
            }
            if (root.cnt != -1) {
                return root.cnt;
            }

            deque.addLast(root);
            root.cnt = -2;
            root.cnt = dp(root.next);
            if (root.instk) {
                deque.removeLast();
                root.instk = false;
            }
            return root.cnt;
        }

    }

    static class IntegerVersionArray {
        int[] data;
        int[] version;
        int now;
        int def;

        public IntegerVersionArray(int cap) {
            this(cap, 0);
        }

        public IntegerVersionArray(int cap, int def) {
            data = new int[cap];
            version = new int[cap];
            now = 0;
            this.def = def;
        }

        public void clear() {
            now++;
        }

        public void visit(int i) {
            if (version[i] < now) {
                version[i] = now;
                data[i] = def;
            }
        }

        public void set(int i, int v) {
            version[i] = now;
            data[i] = v;
        }

        public int get(int i) {
            visit(i);
            return data[i];
        }

    }

    static class Modular {
        int m;

        public Modular(int m) {
            this.m = m;
        }

        public Modular(long m) {
            this.m = (int) m;
            if (this.m != m) {
                throw new IllegalArgumentException();
            }
        }

        public Modular(double m) {
            this.m = (int) m;
            if (this.m != m) {
                throw new IllegalArgumentException();
            }
        }

        public int valueOf(int x) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            return x;
        }

        public int plus(int x, int y) {
            return valueOf(x + y);
        }

        public String toString() {
            return "mod " + m;
        }

    }

    static class Node {
        Node next;
        int cnt = -1;
        int id;
        boolean instk;

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(int c) {
            cache.append(c);
            println();
            return this;
        }

        public FastOutput println() {
            cache.append(System.lineSeparator());
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
        private byte[] buf = new byte[1 << 20];
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