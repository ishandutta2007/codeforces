import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in Actual solution is at the top
 * 
 * @author daltao
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "daltao", 1 << 27);
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
            Node[] nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i + 1;
                nodes[i].x = in.readInt();
                nodes[i].y = in.readInt();

            }

            for (int i = 0; i < n; i++) {
                nodes[i].c = in.readInt();
                nodes[i].dist = nodes[i].c;
            }

            for (int i = 0; i < n; i++) {
                nodes[i].k = in.readInt();
            }


            List<Node> light = new ArrayList<>();
            List<Node[]> edges = new ArrayList<>();
            long totalFee = 0;
            for (int i = 0; i < n; i++) {
                Node nearest = null;
                for (int j = 0; j < n; j++) {
                    if (nodes[j].handled) {
                        continue;
                    }
                    if (nearest == null || nearest.dist > nodes[j].dist) {
                        nearest = nodes[j];
                    }
                }
                nearest.handled = true;
                totalFee += nearest.dist;
                if (nearest.last == null) {
                    light.add(nearest);
                } else {
                    edges.add(SequenceUtils.wrapObjectArray(nearest, nearest.last));
                }
                for (int j = 0; j < n; j++) {
                    if (nodes[j].handled) {
                        continue;
                    }
                    long dist = distBetween(nearest, nodes[j]);
                    if (dist < nodes[j].dist) {
                        nodes[j].dist = dist;
                        nodes[j].last = nearest;
                    }
                }
            }

            out.println(totalFee);
            out.println(light.size());
            for (Node node : light) {
                out.append(node.id).append(' ');
            }
            out.println();
            out.println(edges.size());
            for (Node[] e : edges) {
                out.append(e[0].id).append(' ').append(e[1].id).append('\n');
            }
        }

        public long distBetween(Node a, Node b) {
            return (long) (a.k + b.k) * (Math.abs(a.x - b.x) + Math.abs(a.y - b.y));
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
    static class SequenceUtils {
        public static <T> T[] wrapObjectArray(T... x) {
            return x;
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

        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }

        public FastOutput append(int c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(int c) {
            cache.append(c).append('\n');
            return this;
        }

        public FastOutput println(long c) {
            cache.append(c).append('\n');
            return this;
        }

        public FastOutput println() {
            cache.append('\n');
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
        int x;
        int y;
        int k;
        int c;
        int id;
        Node last;
        boolean handled;
        long dist;

    }
}