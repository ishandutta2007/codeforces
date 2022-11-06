import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Collection;
import java.io.IOException;
import java.util.Deque;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Comparator;
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
            FMaximumReduction solver = new FMaximumReduction();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FMaximumReduction {
        int[] as;
        int k;
        int n;
        Modular mod = new Modular(1e9 + 7);
        int ans = 0;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            n = in.readInt();
            k = in.readInt() - 1;

            as = new int[n];
            for (int i = 0; i < n; i++) {
                as[i] = in.readInt();
            }

            DescartesTree tree = new DescartesTree(as, 0, n - 1, (a, b) -> -Integer.compare(a, b));
            dfs(tree.getRoot(), 0, n - 1);

            out.println(ans);
        }

        public void dfs(DescartesTree.Node root, int l, int r) {
            if (root == null) {
                return;
            }

            if (l + k > r) {
                return;
            }

            int rightLen = r - (root.index + 1) + 1 + 1;
            int leftLen = root.index - l;
            int l0 = DigitUtils.ceilDiv(rightLen, k) * k - rightLen;
            int l1 = k - l0;
            if (l0 == 0) {
                l0 = l1;
                l1 = 0;
            }
            int d = rightLen / k;

            int blockContri = mod.mul(leftLen / k, mod.plus(mod.mul(l0, d), mod.mul(l1, d + 1)));

            int extraContri = 0;
            if (leftLen % k <= l0) {
                extraContri = mod.mul(leftLen % k, d);
            } else {
                extraContri = mod.plus(mod.mul(l0, d), mod.mul(leftLen % k - l0, d + 1));
            }

            //index + kt <= r => t <= (r - index) / k
            if (root.index + k <= r) {
                extraContri = mod.plus(extraContri, (r - root.index) / k);
            }

            int localContri = mod.plus(blockContri, extraContri);
            //System.err.println("f(" + as[root.index] + ") = " + localContri);
            localContri = mod.mul(localContri, as[root.index]);
            ans = mod.plus(ans, localContri);

            dfs(root.left, l, root.index - 1);
            dfs(root.right, root.index + 1, r);
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

        public int valueOf(long x) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            return (int) x;
        }

        public int mul(int x, int y) {
            return valueOf((long) x * y);
        }

        public int plus(int x, int y) {
            return valueOf(x + y);
        }

        public String toString() {
            return "mod " + m;
        }

    }

    static class DescartesTree {
        DescartesTree.Node root;

        public <T> DescartesTree(T[] data, int l, int r, Comparator<T> comp) {
            int len = r - l + 1;
            DescartesTree.Node[] nodes = new DescartesTree.Node[len];
            for (int i = 0; i < len; i++) {
                nodes[i] = new DescartesTree.Node();
                nodes[i].index = i + l;
            }
            Deque<DescartesTree.Node> deque = new ArrayDeque<>(len);
            for (int i = 0; i < len; i++) {
                while (!deque.isEmpty() && comp.compare(data[deque.peekLast().index], data[nodes[i].index]) > 0) {
                    DescartesTree.Node tail = deque.removeLast();
                    tail.right = nodes[i].left;
                    nodes[i].left = tail;
                }
                deque.addLast(nodes[i]);
            }
            while (deque.size() > 1) {
                DescartesTree.Node tail = deque.removeLast();
                deque.peekLast().right = tail;
            }
            root = deque.removeLast();
        }

        public DescartesTree(int[] data, int l, int r, IntComparator comparator) {
            int len = r - l + 1;
            DescartesTree.Node[] nodes = new DescartesTree.Node[len];
            for (int i = 0; i < len; i++) {
                nodes[i] = new DescartesTree.Node();
                nodes[i].index = i + l;
            }
            Deque<DescartesTree.Node> deque = new ArrayDeque<>(len);
            for (int i = 0; i < len; i++) {
                while (!deque.isEmpty() && comparator.compare(data[deque.peekLast().index], data[nodes[i].index]) > 0) {
                    DescartesTree.Node tail = deque.removeLast();
                    tail.right = nodes[i].left;
                    nodes[i].left = tail;
                }
                deque.addLast(nodes[i]);
            }
            while (deque.size() > 1) {
                DescartesTree.Node tail = deque.removeLast();
                deque.peekLast().right = tail;
            }
            root = deque.removeLast();
        }

        public DescartesTree.Node getRoot() {
            return root;
        }

        public static class Node {
            public int index;
            public DescartesTree.Node left;
            public DescartesTree.Node right;

            public String toString() {
                return "" + index;
            }

        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int floorDiv(int a, int b) {
            return a < 0 ? -ceilDiv(-a, b) : a / b;
        }

        public static int ceilDiv(int a, int b) {
            if (a < 0) {
                return -floorDiv(-a, b);
            }
            int c = a / b;
            if (c * b < a) {
                return c + 1;
            }
            return c;
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

    static interface IntComparator {
        public int compare(int a, int b);

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
}