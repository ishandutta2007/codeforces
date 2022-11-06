

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class CFContest {
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
        int inf = (int) 1e9 + 2;

        public Task(FastIO io, Debug debug) {
            this.io = io;
            this.debug = debug;
        }

        @Override
        public void run() {
            solve();
        }

        List<Interval> compressedList = new ArrayList<>();

        public void solve() {
            int n = io.readInt();
            int m = io.readInt();
            Interval[] intervals = new Interval[n];
            for (int i = 0; i < n; i++) {
                intervals[i] = new Interval(io.readInt(), io.readInt());
            }
            Arrays.sort(intervals, Interval.ORDER_BY_L);

            int r = -inf;
            for (int i = 0; i < n; i++) {
                Interval largest = intervals[i];
                while (i + 1 < n && intervals[i].l == intervals[i + 1].l) {
                    i++;
                    if (intervals[i].r > largest.r) {
                        largest = intervals[i];
                    }
                }
                if (largest.r > r) {
                    compressedList.add(largest);
                    r = largest.r;
                }
            }

            Interval invalid = new Interval(0, 0);
            for (Interval interval : compressedList) {
                int index = preceedingIndex(interval.r);
                if (index >= 0 && compressedList.get(index) != interval) {
                    interval.next = compressedList.get(index);
                } else {
                    interval.next = invalid;
                }
            }

            Query[] queries = new Query[m];
            for (int i = 0; i < m; i++) {
                queries[i] = new Query(io.readInt(), io.readInt());
                queries[i].id = i;
            }
            Arrays.sort(queries, Query.ORDER_BY_R);
            for (int i = 0; i < m; i++) {
                int l = queries[i].l;
                int index = preceedingIndex(l);
                Interval interval = index >= 0 ? compressedList.get(index) : invalid;
                Splay candidate = new Splay();
                candidate.key = i;
                interval.queries = Splay.add(interval.queries, candidate);
            }

            for (Interval interval : compressedList) {
                Splay root = interval.queries;
                if (root == Splay.NIL) {
                    continue;
                }
                root.modify(1);
                while (root != Splay.NIL) {
                    root = Splay.selectMinAsRoot(root);
                    if (queries[root.key].r <= interval.r) {
                        queries[root.key].ans = root.val;
                        root = Splay.deleteRoot(root);
                    } else {
                        break;
                    }
                }

                interval.next.queries = Splay.bruteForceMerge(interval.next.queries, root);
            }

            Arrays.sort(queries, Query.ORDER_BY_ID);
            for (int i = 0; i < m; i++) {
                io.cache.append(queries[i].ans).append('\n');
            }
        }

        public int preceedingIndex(int l) {
            int index = Collections.binarySearch(compressedList, new Interval(l, 0), Interval.ORDER_BY_L);
            if (index < 0) {
                index = -(index + 1) - 1;
            }
            return index;
        }
    }

    public static class Splay implements Cloneable {
        public static final Splay NIL = new Splay();

        static {
            NIL.left = NIL;
            NIL.right = NIL;
            NIL.father = NIL;
            NIL.size = 0;
        }

        Splay left = NIL;
        Splay right = NIL;
        Splay father = NIL;
        int size = 1;
        int key;
        int val;
        int modify;

        public void modify(int m) {
            modify += m;
            val += m;
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
            size = left.size + right.size + 1;
        }

        public void pushDown() {
            left.modify(modify);
            right.modify(modify);
            modify = 0;
        }

        public static int toArray(Splay root, int[] data, int offset) {
            if (root == NIL) {
                return offset;
            }
            offset = toArray(root.left, data, offset);
            data[offset++] = root.key;
            offset = toArray(root.right, data, offset);
            return offset;
        }

        public static void toString(Splay root, StringBuilder builder) {
            if (root == NIL) {
                return;
            }
            root.pushDown();
            toString(root.left, builder);
            builder.append(root.key).append(',');
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

        public static Splay add(Splay root, Splay node) {
            if (root == NIL) {
                return node;
            }
            Splay p = root;
            while (root != NIL) {
                p = root;
                root.pushDown();
                if (root.key < node.key) {
                    root = root.right;
                } else {
                    root = root.left;
                }
            }

            if (p.key < node.key) {
                p.setRight(node);
            } else {
                p.setLeft(node);
            }
            p.pushUp();
            splay(node);
            return node;
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

        public static Splay selectKeyAsRoot(Splay root, int k) {
            if (root == NIL) {
                return NIL;
            }
            Splay trace = root;
            Splay father = NIL;
            Splay find = NIL;
            while (trace != NIL) {
                father = trace;
                trace.pushDown();
                if (trace.key > k) {
                    trace = trace.left;
                } else {
                    if (trace.key == k) {
                        find = trace;
                        trace = trace.left;
                    } else {
                        trace = trace.right;
                    }
                }
            }

            splay(father);
            if (find != NIL) {
                splay(find);
                return find;
            }
            return father;
        }

        public static Splay bruteForceMerge(Splay a, Splay b) {
            if (a == NIL) {
                return b;
            } else if (b == NIL) {
                return a;
            }
            if (a.size < b.size) {
                Splay tmp = a;
                a = b;
                b = tmp;
            }

            a = selectMaxAsRoot(a);
            int k = a.key;
            while (b != NIL) {
                b = selectMinAsRoot(b);
                if (b.key >= k) {
                    break;
                }
                Splay kickedOut = b;
                b = deleteRoot(b);
                a = add(a, kickedOut);
            }
            return merge(a, b);
        }

        public static Splay[] split(Splay root, int key) {
            if (root == NIL) {
                return new Splay[]{NIL, NIL};
            }
            Splay p = root;
            while (root != NIL) {
                p = root;
                root.pushDown();
                if (root.key > key) {
                    root = root.left;
                } else {
                    root = root.right;
                }
            }

            splay(p);
            if (p.key <= key) {
                return new Splay[]{p, splitRight(p)};
            } else {
                return new Splay[]{splitLeft(p), p};
            }
        }

        @Override
        public String toString() {
            StringBuilder builder = new StringBuilder().append(key).append(":");
            toString(cloneTree(this), builder);
            return builder.toString();
        }
    }

    public static class Query {
        final int l;
        final int r;
        int ans = -1;
        int id;
        static final Comparator<Query> ORDER_BY_R = (a, b) -> (a.r - b.r);
        static final Comparator<Query> ORDER_BY_ID = (a, b) -> (a.id - b.id);


        public Query(int l, int r) {
            this.l = l;
            this.r = r;
        }
    }

    public static class Interval {
        static final Comparator<Interval> ORDER_BY_L = (a, b) -> a.l - b.l;
        final int l;
        final int r;
        Interval next;
        Splay queries = Splay.NIL;

        public Interval(int l, int r) {
            this.l = l;
            this.r = r;
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