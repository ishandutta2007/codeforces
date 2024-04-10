import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
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
            CLeavingTheBar solver = new CLeavingTheBar();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class CLeavingTheBar {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            Node[] nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                int x = in.readInt();
                int y = in.readInt();
                nodes[i] = new Node();
                nodes[i].x = x;
                nodes[i].y = y;
            }
            Deque<Node> deque = new ArrayDeque<>(Arrays.asList(nodes));
            long limit = (long) 1e12;
            while (deque.size() >= 3) {
                Node a = deque.removeFirst();
                Node b = deque.removeFirst();
                Node c = deque.removeFirst();
                Node[] abc = new Node[]{a, b, c};
                if (same(abc[0], abc[1]) <= limit) {
                    abc[0].sign = 1;
                    abc[1].sign = 1;
                } else if (diff(abc[0], abc[1]) <= limit) {
                    abc[0].sign = 1;
                    abc[1].sign = -1;
                } else if (same(abc[0], abc[2]) <= limit) {
                    abc[0].sign = 1;
                    abc[2].sign = 1;
                    SequenceUtils.swap(abc, 1, 2);
                } else if (diff(abc[0], abc[2]) <= limit) {
                    abc[0].sign = 1;
                    abc[2].sign = -1;
                    SequenceUtils.swap(abc, 1, 2);
                } else if (same(abc[1], abc[2]) <= limit) {
                    abc[1].sign = 1;
                    abc[2].sign = 1;
                    SequenceUtils.swap(abc, 0, 2);
                } else if (diff(abc[1], abc[2]) <= limit) {
                    abc[1].sign = 1;
                    abc[2].sign = -1;
                    SequenceUtils.swap(abc, 0, 2);
                }
                deque.addLast(abc[2]);
                Node merge = new Node();
                abc[0].p = merge;
                abc[1].p = merge;
                merge.x = abc[0].sign * abc[0].x + abc[1].sign * abc[1].x;
                merge.y = abc[0].sign * abc[0].y + abc[1].sign * abc[1].y;
                deque.addLast(merge);
            }

            if (deque.size() == 2) {
                if (same(deque.getFirst(), deque.getLast()) <= limit) {
                    deque.getFirst().sign = 1;
                    deque.getLast().sign = 1;
                } else {
                    deque.getFirst().sign = 1;
                    deque.getLast().sign = -1;
                }
            }

            for (Node node : nodes) {
                out.println(getSign(node));
            }
        }

        public int getSign(Node node) {
            if (node == null) {
                return 1;
            }
            if (node.visited) {
                return node.sign;
            }
            node.visited = true;
            node.sign *= getSign(node.p);
            return node.sign;
        }

        public long same(Node a, Node b) {
            return dist(a.x + b.x, a.y + b.y);
        }

        public long diff(Node a, Node b) {
            return dist(a.x - b.x, a.y - b.y);
        }

        public long dist(int x, int y) {
            return (long) x * x + (long) y * y;
        }

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

    static class Node {
        Node p;
        boolean visited;
        int sign = 1;
        int x;
        int y;

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

    static class SequenceUtils {
        public static <T> void swap(T[] data, int i, int j) {
            T tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

    }
}