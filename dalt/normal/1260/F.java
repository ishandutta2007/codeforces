import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
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
            TaskF solver = new TaskF();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskF {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            Modular mod = new Modular(1e9 + 7);
            Power pow = new Power(mod);

            Node[] nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new Node();
                nodes[i].l = in.readInt();
                nodes[i].r = in.readInt();
                nodes[i].g = nodes[i].r - nodes[i].l + 1;
                nodes[i].invG = pow.inverse(nodes[i].g);
                nodes[i].depth = 0;
                nodes[i].rep = new LCTNode();
                nodes[i].rep.id = i;
                nodes[i].rep.pushUp();
            }
            for (int i = 1; i < n; i++) {
                Node a = nodes[in.readInt() - 1];
                Node b = nodes[in.readInt() - 1];
                a.next.add(b);
                b.next.add(a);
                LCTNode.join(a.rep, b.rep);
            }

            int ans = 0;
            dfs(nodes[0], null);
            Node[] nodeSortByL = nodes.clone();
            Node[] nodeSortByR = nodes.clone();
            Arrays.sort(nodeSortByL, (a, b) -> a.l - b.l);
            Arrays.sort(nodeSortByR, (a, b) -> a.r - b.r);

            Deque<Node> dequeByL = new ArrayDeque<>(Arrays.asList(nodeSortByL));
            Deque<Node> dequeByR = new ArrayDeque<>(Arrays.asList(nodeSortByR));
            int p = 1;
            for (int i = 0; i < n; i++) {
                p = mod.mul(p, nodes[i].g);
            }
            int stateL = 0;
            int stateR = 0;
            LCTNode.makeRoot(nodes[0].rep);
            int allInvG = 0;

            for (int i = 1; i <= 100000; i++) {
                while (!dequeByL.isEmpty() && dequeByL.peekFirst().l <= i) {
                    //add
                    Node head = dequeByL.removeFirst();
                    int x = mod.mul(head.depth, head.invG);
                    stateL = mod.plus(stateL, x);

                    LCTNode.access(head.rep);
                    LCTNode.splay(head.rep);
                    stateR = mod.plus(stateR, mod.mul(head.invG, head.rep.sum));
                    head.rep.update(head.invG);
                    stateR = mod.plus(stateR, mod.mul(head.invG, head.rep.sum));

                    allInvG = mod.plus(allInvG, head.invG);
                }
                while (!dequeByR.isEmpty() && dequeByR.peekFirst().r < i) {
                    //remove
                    Node head = dequeByR.removeFirst();

                    int x = mod.mul(head.depth, head.invG);
                    stateL = mod.subtract(stateL, x);

                    LCTNode.access(head.rep);
                    LCTNode.splay(head.rep);
                    stateR = mod.subtract(stateR, mod.mul(head.invG, head.rep.sum));
                    head.rep.update(-head.invG);
                    stateR = mod.subtract(stateR, mod.mul(head.invG, head.rep.sum));

                    allInvG = mod.subtract(allInvG, head.invG);
                }

                int state = mod.subtract(mod.mul(stateL, allInvG), stateR);
                int plus = mod.mul(state, p);
                ans = mod.plus(ans, plus);
            }

            out.println(ans);
        }

        public void dfs(Node root, Node p) {
            if (p == null) {
                root.depth = 1;
            } else {
                root.depth = p.depth + 1;
            }
            root.next.remove(p);
            for (Node node : root.next) {
                dfs(node, root);
            }
        }

    }

    static class LCTNode {
        public static final LCTNode NIL = new LCTNode();
        public static final Modular mod = new Modular(1e9 + 7);
        LCTNode left = NIL;
        LCTNode right = NIL;
        LCTNode father = NIL;
        LCTNode treeFather = NIL;
        boolean reverse;
        int id;
        int sum;
        int val;
        int size;
        int dirty;

        static {
            NIL.left = NIL;
            NIL.right = NIL;
            NIL.father = NIL;
            NIL.treeFather = NIL;
        }

        public void update(int x) {
            if (this == NIL) {
                return;
            }
            sum = mod.valueOf((long) size * x + sum);
            dirty = mod.plus(dirty, x);
            val = mod.plus(val, x);
        }

        public static void access(LCTNode x) {
            LCTNode last = NIL;
            while (x != NIL) {
                splay(x);
                x.right.father = NIL;
                x.right.treeFather = x;
                x.setRight(last);
                x.pushUp();

                last = x;
                x = x.treeFather;
            }
        }

        public static void makeRoot(LCTNode x) {
            access(x);
            splay(x);
            x.reverse();
        }

        public static void join(LCTNode y, LCTNode x) {
            makeRoot(x);
            x.treeFather = y;
        }

        public static void splay(LCTNode x) {
            if (x == NIL) {
                return;
            }
            LCTNode y, z;
            while ((y = x.father) != NIL) {
                if ((z = y.father) == NIL) {
                    y.pushDown();
                    x.pushDown();
                    if (x == y.left) {
                        zig(x);
                    } else {
                        zag(x);
                    }
                } else {
                    z.pushDown();
                    y.pushDown();
                    x.pushDown();
                    if (x == y.left) {
                        if (y == z.left) {
                            zig(y);
                            zig(x);
                        } else {
                            zig(x);
                            zag(x);
                        }
                    } else {
                        if (y == z.left) {
                            zag(x);
                            zig(x);
                        } else {
                            zag(y);
                            zag(x);
                        }
                    }
                }
            }

            x.pushDown();
            x.pushUp();
        }

        public static void zig(LCTNode x) {
            LCTNode y = x.father;
            LCTNode z = y.father;
            LCTNode b = x.right;

            y.setLeft(b);
            x.setRight(y);
            z.changeChild(y, x);

            y.pushUp();
        }

        public static void zag(LCTNode x) {
            LCTNode y = x.father;
            LCTNode z = y.father;
            LCTNode b = x.left;

            y.setRight(b);
            x.setLeft(y);
            z.changeChild(y, x);

            y.pushUp();
        }

        public String toString() {
            return "" + id;
        }

        public void pushDown() {
            if (reverse) {
                reverse = false;

                LCTNode tmpNode = left;
                left = right;
                right = tmpNode;

                left.reverse();
                right.reverse();
            }

            if (dirty != 0) {
                left.update(dirty);
                right.update(dirty);
                dirty = 0;
            }

            left.treeFather = treeFather;
            right.treeFather = treeFather;
        }

        public void reverse() {
            reverse = !reverse;
        }

        public void setLeft(LCTNode x) {
            left = x;
            x.father = this;
        }

        public void setRight(LCTNode x) {
            right = x;
            x.father = this;
        }

        public void changeChild(LCTNode y, LCTNode x) {
            if (left == y) {
                setLeft(x);
            } else {
                setRight(x);
            }
        }

        public void pushUp() {
            if (this == NIL) {
                return;
            }
            size = left.size + right.size + 1;
            sum = mod.valueOf((long) left.sum + right.sum + val);
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

        public int subtract(int x, int y) {
            return valueOf(x - y);
        }

        public String toString() {
            return "mod " + m;
        }

    }

    static class Power {
        final Modular modular;

        public Power(Modular modular) {
            this.modular = modular;
        }

        public int pow(int x, long n) {
            if (n == 0) {
                return modular.valueOf(1);
            }
            long r = pow(x, n >> 1);
            r = modular.valueOf(r * r);
            if ((n & 1) == 1) {
                r = modular.valueOf(r * x);
            }
            return (int) r;
        }

        public int inverse(int x) {
            return pow(x, modular.m - 2);
        }

    }

    static class Node {
        List<Node> next = new ArrayList<>();
        int depth;
        int g;
        int l;
        int r;
        int invG;
        LCTNode rep;

    }
}