import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
            EConstructTheBinaryTree solver = new EConstructTheBinaryTree();
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                solver.solve(i, in, out);
            out.close();
        }
    }

    static class EConstructTheBinaryTree {
        Node[] nodes;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int d = in.readInt();
            if (minH(n) > d || maxH(n) < d) {
                out.println("NO");
                return;
            }
            out.println("YES");
            nodes = new Node[n + 1];
            build(1, n, d);
            for (int i = 2; i <= n; i++) {
                out.append(nodes[i].p.id).append(' ');
            }
            out.println();
        }

        public Node build(int l, int r, int d) {
            if (l > r) {
                return null;
            }
            Node root = new Node();
            root.id = l;
            nodes[root.id] = root;
            d -= (r - l + 1) - 1;
            for (int i = l; i <= r; i++) {
                int left = (i - (l + 1) + 1);
                int right = r - i;
                if (minH(left) + minH(right) <= d &&
                        maxH(left) + maxH(right) >= d) {
                    int leftAlloc = Math.max(minH(left), d - maxH(right));
                    Node leftChild = build(l + 1, i, leftAlloc);
                    Node rightChild = build(i + 1, r, d - leftAlloc);
                    if (leftChild != null) {
                        leftChild.p = root;
                    }
                    if (rightChild != null) {
                        rightChild.p = root;
                    }
                    break;
                }
            }
            return root;
        }

        public int minH(int n) {
            int min = 0;
            int remain = n;
            for (int level = 0; remain > 0; level++) {
                int cnt = Math.min(1 << level, remain);
                remain -= cnt;
                min += cnt * level;
            }
            return min;
        }

        public int maxH(int n) {
            int max = (n - 1) * n / 2;
            return max;
        }

    }

    static class FastInput {
        private final InputStream is;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 13);
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

        public String next() {
            return readString();
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

    }

    static class Node {
        Node p;
        int id;

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

        public FastOutput append(int c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(String c) {
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
}