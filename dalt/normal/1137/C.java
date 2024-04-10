import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Collection;
import java.io.IOException;
import java.util.Deque;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
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
            CMuseumsTour solver = new CMuseumsTour();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class CMuseumsTour {
        Deque<Node> deque = new ArrayDeque<>(100000);
        int dfn;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            int d = in.readInt();

            Node[] nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
                nodes[i].leave = new int[d];
                nodes[i].dp = new int[d];
            }
            for (int i = 0; i < m; i++) {
                Node a = nodes[in.readInt() - 1];
                Node b = nodes[in.readInt() - 1];
                a.next.add(b);
                b.prev.add(a);
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < d; j++) {
                    nodes[i].open = Bits.setBit(nodes[i].open, j, in.readChar() == '1');
                }
            }

            for (Node node : nodes) {
                tarjan(node);
            }

            for (Node node : nodes) {
                if (node.set == node) {
                    node.accessible = 1;
                    deque.addLast(node);
                    node.inque = true;
                    node.distFromSet = 0;
                }
            }

            long mask = (1L << d) - 1;
            while (!deque.isEmpty()) {
                Node head = deque.removeFirst();
                head.inque = false;
                long prov = head.accessible << 1;
                prov = Bits.swapBit(prov, d, 0);
                for (Node node : head.next) {
                    if (node.set != head.set) {
                        continue;
                    }
                    if ((node.accessible | prov) == node.accessible) {
                        continue;
                    }
                    node.distFromSet = head.distFromSet + 1;
                    node.accessible = node.accessible | prov;
                    if (node.inque) {
                        continue;
                    }
                    node.inque = true;
                    deque.addLast(node);
                }
            }

            for (Node node : nodes) {
                if (node.set == node) {
                    //dfsForPeriod(node, 0, 0);
                    dfsForDistToSet(node, 0);
                    countForPeriod(node);
                }
            }


            int ans = queryOn(nodes[0], 0);
            out.println(ans);
        }

        public static void dfsForDistToSet(Node root, int dist) {
            if (root.distToSet != -1) {
                return;
            }
            root.distToSet = dist;
            for (Node node : root.prev) {
                if (node.set != root.set) {
                    continue;
                }
                dfsForDistToSet(node, dist + 1);
            }
        }

        public static int queryOn(Node root, int i) {
            dfsForDp(root);
            i = (i + root.distToSet) % root.set.period;
            return root.set.dp[i];
        }

        public static void countForPeriod(Node root) {
            root.period = 1;
            while (0 == Bits.bitAt(root.accessible, root.period % root.dp.length)) {
                root.period++;
            }
        }

        public static void dfsForDp(Node root) {
            if (root.visited) {
                return;
            }
            root.visited = true;
            int d = root.dp.length;
            for (int i = 0; i < root.set.period; i++) {
                boolean possible = false;
                for (int j = i; j < d; j += root.set.period) {
                    possible = possible || Bits.bitAt(root.open, j) == 1;
                }
                if (possible) {
                    root.set.dp[DigitUtils.mod(i - root.distFromSet, root.set.period)]++;
                }
            }
            for (Node node : root.next) {
                if (node.set == root.set) {
                    dfsForDp(node);
                } else {
                    for (int i = 0; i < d; i++) {
                        int index = DigitUtils.mod(i - root.distFromSet, d);
                        root.set.leave[index] = Math.max(root.set.leave[index], queryOn(node, i + 1));
                    }
                }
            }


            if (root.set == root) {
                for (int i = 0; i < root.period; i++) {
                    int mx = 0;
                    for (int j = i; j < d; j += root.period) {
                        mx = Math.max(mx, root.leave[j]);
                    }
                    root.dp[i] += mx;
                }
            }

        }

        public void tarjan(Node root) {
            if (root.dfn != 0) {
                return;
            }
            root.dfn = root.low = ++dfn;
            root.instk = true;
            deque.addLast(root);
            for (Node node : root.next) {
                tarjan(node);
                if (node.instk && node.low < root.low) {
                    root.low = node.low;
                }
            }

            if (root.low == root.dfn) {
                while (true) {
                    Node head = deque.removeLast();
                    head.set = root;
                    head.instk = false;
                    if (head == root) {
                        break;
                    }
                }
            }
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int mod(int x, int mod) {
            x %= mod;
            if (x < 0) {
                x += mod;
            }
            return x;
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

        public char readChar() {
            skipBlank();
            char c = (char) next;
            next = read();
            return c;
        }

    }

    static class Node {
        long accessible;
        int[] leave;
        int[] dp;
        int period;
        List<Node> next = new ArrayList<>();
        List<Node> prev = new ArrayList<>();
        int id;
        Node set;
        int dfn;
        int low;
        boolean instk;
        long open;
        int distToSet = -1;
        int distFromSet;
        boolean visited;
        boolean inque;

        public String toString() {
            return "" + id;
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

    static class Bits {
        private Bits() {
        }

        public static int bitAt(long x, int i) {
            return (int) ((x >> i) & 1);
        }

        public static long setBit(long x, int i, boolean v) {
            if (v) {
                x |= 1L << i;
            } else {
                x &= ~(1L << i);
            }
            return x;
        }

        public static long swapBit(long x, int i, int j) {
            int bi = bitAt(x, i);
            int bj = bitAt(x, j);
            x = setBit(x, i, bj == 1);
            x = setBit(x, j, bi == 1);
            return x;
        }

    }
}