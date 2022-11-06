

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.util.*;

public class CF1217F {
    public static void main(String[] args) throws Exception {
        boolean local = System.getSecurityManager() == null;
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

            int last = 0;
            DynamicConnectionChecker checker = new DynamicConnectionChecker(n, m);
            for (int i = 0; i < m; i++) {
                int op = io.readInt();
                int x = (io.readInt() + last - 1) % n;
                int y = (io.readInt() + last - 1) % n;
                if (op == 1) {
                    if (checker.containEdge(x, y)) {
                        checker.deleteEdge(x, y);
                    } else {
                        checker.addEdge(x, y);
                    }
                } else {
                    last = checker.check(x, y) ? 1 : 0;
                    io.cache.append(last);
                }
            }
        }
    }

    public static class FastIO {
        public final StringBuilder cache = new StringBuilder(1 << 13);
        private final InputStream is;
        private final OutputStream os;
        private final Charset charset;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 13);
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

        public void flush() throws IOException {
            os.write(cache.toString().getBytes(charset));
            os.flush();
            cache.setLength(0);
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

    public static class DynamicConnectionChecker {
        EulerTourTree[] levels;
        int n;
        int log2;
        Map<Long, EdgeInfo> map;

        public boolean containEdge(int i, int j) {
            return map.containsKey(idOfEdge(i, j));
        }

        public DynamicConnectionChecker(int n, int m) {
            this.n = n;
            this.log2 = 32 - Integer.numberOfLeadingZeros(n - 1);
            levels = new EulerTourTree[log2 + 1];
            Deque deque = new ArrayDeque(3 * n);
            for (int i = 1; i <= log2; i++) {
                levels[i] = new EulerTourTree(n, deque);
                levels[i].id = i;
            }
            map = new HashMap<>(m);
        }

        public boolean check(int i, int j) {
            if (i == j) {
                return true;
            }
            int r1 = levels[log2].rootOf(i);
            int r2 = levels[log2].rootOf(j);
            return r1 == r2;
        }

        public void addEdge(int i, int j) {
            EdgeInfo info = new EdgeInfo();
            info.a = i;
            info.b = j;
            info.level = log2 + 1;
            map.put(idOfEdge(i, j), info);
            pushDownEdge(info, levels[log2].rootOf(info.a) != levels[log2].rootOf(info.b));
        }

        private void pushDownEdge(EdgeInfo info, boolean link) {
            info.level--;
            if (info.level == 0) {
                return;
            }

            addEdgeChain(info);
            if (link) {
                levels[info.level].link(info);
            }
        }

        private void addEdgeChain(EdgeInfo info) {
            EdgeChain chain1 = new EdgeChain(info);
            EdgeChain chain2 = new EdgeChain(info);
            Splay.splay(levels[info.level].nodes[info.a]);
            levels[info.level].nodes[info.a].addEdge(chain1);
            levels[info.level].nodes[info.a].pushUp();
            Splay.splay(levels[info.level].nodes[info.b]);
            levels[info.level].nodes[info.b].addEdge(chain2);
            levels[info.level].nodes[info.b].pushUp();
        }

        public void deleteEdge(int i, int j) {
            long idOfEdge = idOfEdge(i, j);
            EdgeInfo info = map.remove(idOfEdge);
            if (info.level == 0) {
                return;
            }

            int curLevel = info.level;
            info.level = -1;
            if (!levels[log2].map.containsKey(idOfEdge)) {
                return;
            }

            for (int k = curLevel; k <= log2; k++) {
                levels[k].cut(i, j);
            }

            for (int k = curLevel; k <= log2; k++) {
                Splay ti = levels[k].nodes[i];
                Splay tj = levels[k].nodes[j];
                Splay.splay(ti);
                Splay.splay(tj);

                if (ti.size > tj.size) {
                    Splay tmp = ti;
                    ti = tj;
                    tj = tmp;
                }

                Splay.splay(ti);
                while (ti.infoWithMaxLevel != null) {
                    ti = ti.infoWithMaxLevel;
                    Splay.splay(ti);
                    if (ti.infoWithMaxLevel.info.level < k) {
                        break;
                    }
                    pushDownEdge(ti.info, true);
                    Splay.splay(ti);
                }
                Splay.splay(ti);
                while (ti.containEdge != null) {
                    ti = ti.containEdge;
                    Splay.splay(ti);
                    EdgeInfo e = ti.popEdge().info;
                    ti.pushUp();
                    if (e.level < k) {
                    } else if (levels[log2].rootOf(e.a) ==
                            levels[log2].rootOf(e.b)) {
                        if (e.level == k) {
                            pushDownEdge(e, false);
                        }
                    } else {
                        addEdgeChain(e);
                        for (int t = k; t <= log2; t++) {
                            levels[t].link(e);
                        }
                        return;
                    }
                    Splay.splay(ti);
                }
            }
        }

        private static class EdgeInfo {
            int a;
            int b;
            int level;

            @Override
            public String toString() {
                return String.format("%d -> %d", a, b);
            }
        }

        private static class EdgeChain {
            final EdgeInfo info;
            EdgeChain next;

            private EdgeChain(EdgeInfo info) {
                this.info = info;
            }

            @Override
            public String toString() {
                if (next == null) {
                    return info.toString();
                }
                return info.toString() + ", " + next.toString();
            }
        }

        private static long idOfEdge(int i, int j) {
            if (i > j) {
                int tmp = i;
                i = j;
                j = tmp;
            }
            return (((long) i) << 32) | j;
        }

        public static class EulerTourTree {
            Splay[] nodes;
            Deque<Splay> deque;
            Map<Long, Edge> map;
            int id;

            public EulerTourTree(int n) {
                this(n, new ArrayDeque<>(3 * n));
            }

            public EulerTourTree(int n, Deque<Splay> deque) {
                this.deque = deque;
                map = new HashMap(n);
                nodes = new Splay[n];
                for (int i = 0; i < n; i++) {
                    nodes[i] = alloc(i);
                }
            }

            private Splay alloc(int id) {
                Splay splay = deque.isEmpty() ? new Splay() : deque.removeFirst();
                splay.id = id;
                return splay;
            }

            private void destroy(Splay s) {
                s.info = null;
                s.chain = null;
                s.infoWithMaxLevel = null;
                s.containEdge = null;

                deque.addLast(s);
            }

            public int rootOf(int i) {
                return rootOf(nodes[i]).id;
            }

            public void setRoot(int i) {
                if (rootOf(i) == i) {
                    return;
                }

                Splay.splay(nodes[i]);
                Splay l = Splay.splitLeft(nodes[i]);
                if (l == Splay.NIL) {
                    return;
                }
                Splay a = Splay.selectMinAsRoot(l);
                Splay b = Splay.selectMaxAsRoot(nodes[i]);

                if (nodes[a.id] == a) {
                    Splay.splitLeft(b);
                    destroy(b);
                } else {
                    l = Splay.splitRight(a);
                    destroy(a);
                }

                Splay newNode = alloc(i);
                Splay.splay(nodes[i]);
                Splay.splay(l);
                Splay.merge(nodes[i], Splay.merge(l, newNode));
            }


            public void link(EdgeInfo info) {
                int i = info.a;
                int j = info.b;
                setRoot(i);
                setRoot(j);

                Edge e = new Edge();

                long id = idOfEdge(i, j);
                e.a = alloc(-i * 10000 - j);
                e.b = alloc(-i * 10000 - j);
                e.a.info = info;
                e.a.pushUp();
                e.b.pushUp();
                map.put(id, e);

                Splay.splay(nodes[i]);
                Splay.splay(nodes[j]);
                Splay.merge(nodes[i], e.a);
                Splay.merge(nodes[j], e.b);
                Splay.splay(nodes[i]);
                Splay.splay(nodes[j]);
                Splay.merge(nodes[i], nodes[j]);

                Splay newNode = alloc(i);
                Splay.splay(nodes[i]);
                Splay.merge(nodes[i], newNode);
            }

            private Splay rootOf(Splay x) {
                Splay.splay(x);
                return Splay.selectMinAsRoot(x);
            }

            public void cut(int i, int j) {
                long id = idOfEdge(i, j);
                Edge e = map.remove(id);

                Splay.splay(e.a);
                Splay al = Splay.splitLeft(e.a);
                Splay ar = Splay.splitRight(e.a);


                Splay l, r;
                if (rootOf(ar) == rootOf(e.b)) {
                    Splay.splay(e.b);
                    Splay bl = Splay.splitLeft(e.b);
                    Splay br = Splay.splitRight(e.b);

                    l = al;
                    r = br;
                } else {
                    Splay.splay(e.b);
                    Splay bl = Splay.splitLeft(e.b);
                    Splay br = Splay.splitRight(e.b);

                    l = bl;
                    r = ar;
                }

                Splay.splay(l);
                Splay.splay(r);
                l = Splay.selectMaxAsRoot(l);
                r = Splay.selectMinAsRoot(r);

                if (nodes[l.id] == l) {
                    Splay rSnapshot = r;
                    r = Splay.splitRight(r);
                    destroy(rSnapshot);
                } else {
                    Splay lSnapshot = l;
                    l = Splay.splitLeft(l);
                    destroy(lSnapshot);
                }

                Splay.merge(l, r);
                destroy(e.a);
                destroy(e.b);
            }


            private static class Edge {
                Splay a;
                Splay b;
            }


        }

        /**
         * Created by dalt on 2018/5/20.
         */
        public static class Splay implements Cloneable {
            public static final Splay NIL = new Splay();

            static {
                NIL.left = NIL;
                NIL.right = NIL;
                NIL.father = NIL;
                NIL.size = 0;
                NIL.id = -2;
            }

            Splay left = NIL;
            Splay right = NIL;
            Splay father = NIL;
            int size = 1;
            int id;

            EdgeChain chain;
            EdgeInfo info;
            Splay containEdge;
            Splay infoWithMaxLevel;

            public void addEdge(EdgeChain newChain) {
                newChain.next = chain;
                chain = newChain;
                containEdge = this;
            }

            public EdgeChain popEdge() {
                EdgeChain head = chain;
                chain = head.next;
                head.next = null;
                return head;
            }

            public static void splay(Splay x) {
                if (x == NIL) {
                    return;
                }
                Splay y, z;
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

            public static void zig(Splay x) {
                Splay y = x.father;
                Splay z = y.father;
                Splay b = x.right;

                y.setLeft(b);
                x.setRight(y);
                z.changeChild(y, x);

                y.pushUp();
            }

            public static void zag(Splay x) {
                Splay y = x.father;
                Splay z = y.father;
                Splay b = x.left;

                y.setRight(b);
                x.setLeft(y);
                z.changeChild(y, x);

                y.pushUp();
            }

            public void setLeft(Splay x) {
                left = x;
                x.father = this;
            }

            public void setRight(Splay x) {
                right = x;
                x.father = this;
            }

            public void changeChild(Splay y, Splay x) {
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

                containEdge = null;
                if (chain != null) {
                    containEdge = this;
                } else if (left.containEdge != null) {
                    containEdge = left.containEdge;
                } else {
                    containEdge = right.containEdge;
                }

                infoWithMaxLevel = null;
                if (info != null) {
                    infoWithMaxLevel = this;
                }
                if (left.infoWithMaxLevel != null &&
                        (infoWithMaxLevel == null || infoWithMaxLevel.info.level < left.infoWithMaxLevel.info.level)) {
                    infoWithMaxLevel = left.infoWithMaxLevel;
                }
                if (right.infoWithMaxLevel != null &&
                        (infoWithMaxLevel == null || infoWithMaxLevel.info.level < right.infoWithMaxLevel.info.level)) {
                    infoWithMaxLevel = right.infoWithMaxLevel;
                }
            }

            public void pushDown() {
            }

            public static void toString(Splay root, StringBuilder builder) {
                if (root == NIL) {
                    return;
                }
                root.pushDown();
                toString(root.left, builder);
                builder.append(root.id).append(',');
                toString(root.right, builder);
            }

            public Splay clone() {
                try {
                    return (Splay) super.clone();
                } catch (CloneNotSupportedException e) {
                    throw new RuntimeException(e);
                }
            }

            public static Splay cloneTree(Splay splay) {
                if (splay == NIL) {
                    return NIL;
                }
                splay = splay.clone();
                splay.left = cloneTree(splay.left);
                splay.right = cloneTree(splay.right);
                return splay;
            }

            /**
             * Make the node with the minimum key as the root of tree
             */
            public static Splay selectMinAsRoot(Splay root) {
                if (root == NIL) {
                    return root;
                }
                root.pushDown();
                while (root.left != NIL) {
                    root = root.left;
                    root.pushDown();
                }
                splay(root);
                return root;
            }

            /**
             * Make the node with the maximum key as the root of tree
             */
            public static Splay selectMaxAsRoot(Splay root) {
                if (root == NIL) {
                    return root;
                }
                root.pushDown();
                while (root.right != NIL) {
                    root = root.right;
                    root.pushDown();
                }
                splay(root);
                return root;
            }

            /**
             * delete root of tree, then merge remain nodes into a new tree, and return the new root
             */
            public static Splay deleteRoot(Splay root) {
                root.pushDown();
                Splay left = splitLeft(root);
                Splay right = splitRight(root);
                return merge(left, right);
            }

            /**
             * detach the left subtree from root and return the root of left subtree
             */
            public static Splay splitLeft(Splay root) {
                root.pushDown();
                Splay left = root.left;
                left.father = NIL;
                root.setLeft(NIL);
                root.pushUp();
                return left;
            }

            /**
             * detach the right subtree from root and return the root of right subtree
             */
            public static Splay splitRight(Splay root) {
                root.pushDown();
                Splay right = root.right;
                right.father = NIL;
                root.setRight(NIL);
                root.pushUp();
                return right;
            }


            public static Splay merge(Splay a, Splay b) {
                if (a == NIL) {
                    return b;
                }
                if (b == NIL) {
                    return a;
                }
                a = selectMaxAsRoot(a);
                a.setRight(b);
                a.pushUp();
                return a;
            }

            public static Splay selectKthAsRoot(Splay root, int k) {
                if (root == NIL) {
                    return NIL;
                }
                Splay trace = root;
                Splay father = NIL;
                while (trace != NIL) {
                    father = trace;
                    trace.pushDown();
                    if (trace.left.size >= k) {
                        trace = trace.left;
                    } else {
                        k -= trace.left.size + 1;
                        if (k == 0) {
                            break;
                        } else {
                            trace = trace.right;
                        }
                    }
                }
                splay(father);
                return father;
            }

            @Override
            public String toString() {
                StringBuilder builder = new StringBuilder().append(id).append(":");
                toString(cloneTree(this), builder);
                return builder.toString();
            }
        }
    }
}