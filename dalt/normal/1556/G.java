import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.PrintStream;
import java.io.IOException;
import java.lang.reflect.Field;
import java.nio.charset.StandardCharsets;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.util.Comparator;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) throws Exception {
        new TaskAdapter().run();
    }

    static class TaskAdapter implements Runnable {
        @Override
        public void run() {
            InputStream inputStream = System.in;
            OutputStream outputStream = System.out;
            FastInput in = new FastInput(inputStream);
            FastOutput out = new FastOutput(outputStream);
            GGatesToAnotherWorld solver = new GGatesToAnotherWorld();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class GGatesToAnotherWorld {
        Debug debug = new Debug(false);
        DSU dsu;
        List<Node> nodeList;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int m = in.ri();
            List<Query> qs = new ArrayList<>(m);
            List<Query> updates = new ArrayList<>(m);
            for (int i = 0; i < m; i++) {
                int t = in.rs().equals("block") ? 0 : 1;
                Query q = new Query(t, in.rl(), in.rl());
                qs.add(q);
                if (q.type == 0) {
                    updates.add(q);
                }
            }
            debug.debug("updates", updates);
            List<Query> revQs = new ArrayList<>(qs);
            Collections.reverse(revQs);
            debug.debug("revQs", revQs);
            nodeList = new ArrayList<>(m * 2);
            updates.sort(Comparator.comparingLong(x -> x.l));
            long last = 0;
            for (Query q : updates) {
                long l = last;
                long r = q.l - 1;
                addNode(l, r, false);
                addNode(q.l, q.r, true);
                last = q.r + 1;
            }
            addNode(last, (1L << n) - 1, false);
            debug.elapse("createNode");
            Node[] nodes = nodeList.toArray(new Node[0]);
            debug.debug("nodes", nodes);
            for (int i = 0; i < nodes.length; i++) {
                nodes[i].id = i;
            }
            assert SortUtils.notStrictAscending(nodes, 0, nodes.length - 1, Comparator.comparingLong(x -> x.l));
            dac(nodes, 0, nodes.length - 1, 0, (1L << n) - 1, n - 1);

            dsu = new DSU(nodes.length);
            dsu.init();

            for (Node root : nodes) {
                recalc(root);
            }

            debug.elapse("build");

//        search(nodes, nodes[0], nodes[12]);
//        for(Node cur = nodes[12]; cur != null; cur = cur.prev){
//            debug.debug("cur", cur);
//        }
            for (Query q : revQs) {
                Node a = search(nodes, q.l);
                Node b = search(nodes, q.r);
                if (q.type == 0) {
                    assert a.del;
                    assert b.del;
                    a.del = false;
                    b.del = false;
                    recalc(a);
                    recalc(b);
                } else {
                    assert !a.del;
                    assert !b.del;
                    q.ans = dsu.find(a.id) == dsu.find(b.id);
                }
            }

            debug.elapse("answer");
            for (Query q : qs) {
                if (q.type == 1) {
                    out.println(q.ans ? 1 : 0);
                }
            }
        }

        public boolean intersect(long l, long r, long L, long R) {
            return l <= R && r >= L;
        }

        public boolean checkInRange(Node[] nodes, int l, int r, long L, long R) {
            for (int i = l; i <= r; i++) {
                if (nodes[i].l < L || nodes[i].r > R) {
                    return false;
                }
            }
            return true;
        }

        public void dac(Node[] nodes, int l, int r, long L, long R, int D) {
            assert checkInRange(nodes, l, r, L, R);
            if (l >= r) {
                return;
            }
            if (D < 0) {
                assert l == r;
            }
            long M = (L + R) / 2;
            int ml = l - 1;
            while (ml + 1 <= r && nodes[ml + 1].r <= M) {
                ml++;
            }
            int mr = r + 1;
            while (mr - 1 >= l && nodes[mr - 1].l > M) {
                mr--;
            }

            dac(nodes, l, ml, L, M, D - 1);
            dac(nodes, mr, r, M + 1, R, D - 1);

            if (ml + 1 < mr) {
                for (int j = ml + 1; j < mr; j++) {
                    for (int i = l; i <= ml; i++) {
                        addEdge(nodes[i], nodes[j]);
                    }
                    for (int i = mr; i <= r; i++) {
                        addEdge(nodes[i], nodes[j]);
                    }
                }
            } else {
                int lIter = l;
                int rIter = mr;
                long mask = (1L << D) - 1;
                while (lIter <= ml && rIter <= r) {
                    int comp = Long.compare(nodes[lIter].r & mask, nodes[rIter].r & mask);
                    if (intersect(nodes[lIter].l & mask, nodes[lIter].r & mask,
                            nodes[rIter].l & mask, nodes[rIter].r & mask)) {
                        addEdge(nodes[lIter], nodes[rIter]);
                    }
                    if (comp <= 0) {
                        lIter++;
                    }
                    if (comp >= 0) {
                        rIter++;
                    }
                }
            }
        }

        public void recalc(Node root) {
            if (root.del) {
                return;
            }
            for (Node node : root.adj) {
                if (node.del) {
                    continue;
                }
                dsu.merge(root.id, node.id);
            }
        }

        public boolean check(Node a, Node b) {
            for (int i = 0; i < 50; i++) {
                for (long j = a.l; j <= a.r; j++) {
                    long to = j ^ (1L << i);
                    if (b.l <= to && b.r >= to) {
                        return true;
                    }
                }
            }
            return false;
        }

        public void addEdge(Node a, Node b) {
            assert check(a, b);
            a.adj.add(b);
            b.adj.add(a);
        }

        public Node search(Node[] nodes, long x) {
            int l = 0;
            int r = nodes.length - 1;
            while (l < r) {
                int m = (l + r + 1) >> 1;
                if (nodes[m].l <= x) {
                    l = m;
                } else {
                    r = m - 1;
                }
            }
            return nodes[l];
        }

        void addNode(long l, long r, boolean del) {
            if (r < l) {
                return;
            }
            if (l == r) {
                addNode0(l, r, del);
                return;
            }
            int index = Bits.theFirstDifferentIndex(l, r);
            long prefix = (l >> (index + 1)) << (index + 1);
            long mid = prefix | (1L << index);
            addNode0(l, mid - 1, del);
            addNode0(mid, r, del);
        }

        void addNode0(long l, long r, boolean del) {
            if (r < l) {
                return;
            }
            nodeList.add(new Node(l, r, del));
        }

    }

    static class Bits {
        private Bits() {
        }

        public static int theFirstDifferentIndex(long x, long y) {
            return Log2.floorLog(x ^ y);
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private static final int THRESHOLD = 32 << 10;
        private OutputStream writer;
        private StringBuilder cache = new StringBuilder(THRESHOLD * 2);
        private static Field stringBuilderValueField;
        private char[] charBuf = new char[THRESHOLD * 2];
        private byte[] byteBuf = new byte[THRESHOLD * 2];

        static {
            try {
                stringBuilderValueField = StringBuilder.class.getSuperclass().getDeclaredField("value");
                stringBuilderValueField.setAccessible(true);
            } catch (Exception e) {
                stringBuilderValueField = null;
            }
            stringBuilderValueField = null;
        }

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

        private void afterWrite() {
            if (cache.length() < THRESHOLD) {
                return;
            }
            flush();
        }

        public FastOutput(OutputStream writer) {
            this.writer = writer;
        }

        public FastOutput append(char c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(int c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(int c) {
            return append(c).println();
        }

        public FastOutput println() {
            return append('\n');
        }

        public FastOutput flush() {
            try {
                if (stringBuilderValueField != null) {
                    try {
                        byte[] value = (byte[]) stringBuilderValueField.get(cache);
                        writer.write(value, 0, cache.length());
                    } catch (Exception e) {
                        stringBuilderValueField = null;
                    }
                }
                if (stringBuilderValueField == null) {
                    int n = cache.length();
                    if (n > byteBuf.length) {
                        //slow
                        writer.write(cache.toString().getBytes(StandardCharsets.UTF_8));
//                writer.append(cache);
                    } else {
                        cache.getChars(0, n, charBuf, 0);
                        for (int i = 0; i < n; i++) {
                            byteBuf[i] = (byte) charBuf[i];
                        }
                        writer.write(byteBuf, 0, n);
                    }
                }
                writer.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
            return this;
        }

        public void close() {
            flush();
            try {
                writer.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

        public String toString() {
            return cache.toString();
        }

    }

    static class Debug {
        private boolean offline;
        private PrintStream out = System.err;
        private long time = System.currentTimeMillis();
        static int[] empty = new int[0];

        public Debug(boolean enable) {
            offline = enable && System.getSecurityManager() == null;
        }

        public Debug elapse(String name) {
            if (offline) {
                debug(name, System.currentTimeMillis() - time);
                time = System.currentTimeMillis();
            }
            return this;
        }

        public Debug debug(String name, long x) {
            if (offline) {
                debug(name, "" + x);
            }
            return this;
        }

        public Debug debug(String name, String x) {
            if (offline) {
                out.printf("%s=%s", name, x);
                out.println();
            }
            return this;
        }

        public Debug debug(String name, Object x) {
            return debug(name, x, empty);
        }

        public Debug debug(String name, Object x, int... indexes) {
            if (offline) {
                if (x == null || !x.getClass().isArray()) {
                    out.append(name);
                    for (int i : indexes) {
                        out.printf("[%d]", i);
                    }
                    out.append("=").append("" + x);
                    out.println();
                } else {
                    indexes = Arrays.copyOf(indexes, indexes.length + 1);
                    if (x instanceof byte[]) {
                        byte[] arr = (byte[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof short[]) {
                        short[] arr = (short[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof boolean[]) {
                        boolean[] arr = (boolean[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof char[]) {
                        char[] arr = (char[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof int[]) {
                        int[] arr = (int[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof float[]) {
                        float[] arr = (float[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof double[]) {
                        double[] arr = (double[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof long[]) {
                        long[] arr = (long[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else {
                        Object[] arr = (Object[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    }
                }
            }
            return this;
        }

    }

    static class DSU {
        protected int[] p;
        public int[] size;
        protected int n;

        public DSU(int n) {
            p = new int[n];
            size = new int[n];
        }

        public void init() {
            init(p.length);
        }

        public void init(int n) {
            this.n = n;
            for (int i = 0; i < n; i++) {
                p[i] = i;
                size[i] = 1;
            }
        }

        public final int find(int a) {
            if (p[a] == p[p[a]]) {
                return p[a];
            }
            find(p[a]);
            preAccess(a);
            return p[a] = p[p[a]];
        }

        protected void preAccess(int a) {

        }

        protected void preMerge(int a, int b) {
            size[a] += size[b];
        }

        public final void merge(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) {
                return;
            }

            if (size[a] < size[b]) {
                int tmp = a;
                a = b;
                b = tmp;
            }
            preMerge(a, b);
            p[b] = a;
        }

        public String toString() {
            return Arrays.toString(Arrays.copyOf(p, n));
        }

    }

    static class Log2 {
        public static int floorLog(long x) {
            if (x <= 0) {
                throw new IllegalArgumentException();
            }
            return 63 - Long.numberOfLeadingZeros(x);
        }

    }

    static class Query {
        int type;
        long l;
        long r;
        boolean ans;

        public Query(int type, long l, long r) {
            this.type = type;
            this.l = l;
            this.r = r;
        }

        public String toString() {
            return "Query{" +
                    "type=" + type +
                    ", l=" + l +
                    ", r=" + r +
                    '}';
        }

    }

    static class SortUtils {
        private SortUtils() {
        }

        public static <T> boolean notStrictAscending(T[] data, int l, int r, Comparator<T> comp) {
            for (int i = l + 1; i <= r; i++) {
                if (comp.compare(data[i], data[i - 1]) < 0) {
                    return false;
                }
            }
            return true;
        }

    }

    static class Node {
        long l;
        long r;
        boolean del;
        int id;
        List<Node> adj = new ArrayList<>();

        public Node(long l, long r, boolean del) {
            this.l = l;
            this.r = r;
            this.del = del;
        }

        public String toString() {
            return "Node{" +
                    "l=" + l +
                    ", r=" + r +
                    ", del=" + del +
                    ", id=" + id +
                    '}';
        }

    }

    static class FastInput {
        private final InputStream is;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 13);
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

        public int ri() {
            return readInt();
        }

        public int readInt() {
            boolean rev = false;

            skipBlank();
            if (next == '+' || next == '-') {
                rev = next == '-';
                next = read();
            }

            int val = 0;
            while (next >= '0' && next <= '9') {
                val = val * 10 - next + '0';
                next = read();
            }

            return rev ? val : -val;
        }

        public long rl() {
            return readLong();
        }

        public long readLong() {
            boolean rev = false;

            skipBlank();
            if (next == '+' || next == '-') {
                rev = next == '-';
                next = read();
            }

            long val = 0;
            while (next >= '0' && next <= '9') {
                val = val * 10 - next + '0';
                next = read();
            }

            return rev ? val : -val;
        }

        public String rs() {
            return readString();
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
}