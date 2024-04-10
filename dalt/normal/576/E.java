import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.Random;
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
            EPaintingEdges solver = new EPaintingEdges();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class EPaintingEdges {
        void no(FastOutput out) {
            out.println("NO");
        }

        void yes(FastOutput out) {
            out.println("YES");
        }

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            int k = in.readInt();
            int q = in.readInt();

            Edge[] edges = new Edge[m + 1];
            for (int i = 1; i <= m; i++) {
                edges[i] = new Edge();
                edges[i].a = in.readInt();
                edges[i].b = in.readInt();
            }

            Query[] qs = new Query[q];
            for (int i = 0; i < q; i++) {
                qs[i] = new Query();
                qs[i].e = in.readInt();
                qs[i].c = in.readInt();
            }
            int[] registries = new int[m + 1];
            SequenceUtils.deepFill(registries, q);
            for (int i = q - 1; i >= 0; i--) {
                qs[i].endTime = registries[qs[i].e];
                registries[qs[i].e] = i;
            }

            IntegerList[] list = new IntegerList[k + 1];
            for (int i = 1; i <= k; i++) {
                list[i] = new IntegerList();
            }
            for (Query query : qs) {
                list[query.c].add(edges[query.e].a);
                list[query.c].add(edges[query.e].b);
            }
            for (int i = 1; i <= k; i++) {
                list[i].unique();
            }
            ConnectionChecker[] checks = new ConnectionChecker[k + 1];
            for (int i = 1; i <= k; i++) {
                checks[i] = new ConnectionChecker(list[i].size());
            }
            for (int i = 0; i < q; i++) {
                Edge e = edges[qs[i].e];
                int c = qs[i].c;
                checks[c].elapse(i);
                int len = checks[c].check(list[c].binarySearch(e.a), list[c].binarySearch(e.b));
                if (len >= 0 && len % 2 == 1) {
                    no(out);
                } else {
                    yes(out);
                    e.c = c;
                }
                if (e.c != 0) {
                    checks[e.c].addEdge(list[e.c].binarySearch(e.a), list[e.c].binarySearch(e.b), qs[i].endTime);
                }
            }
        }

    }

    static class Edge {
        int a;
        int b;
        int c;

    }

    static class Query {
        int e;
        int c;
        int endTime;

    }

    static class IntegerList implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public IntegerList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public IntegerList(IntegerList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public IntegerList() {
            this(0);
        }

        public void ensureSpace(int req) {
            if (req > cap) {
                while (cap < req) {
                    cap = Math.max(cap + 10, 2 * cap);
                }
                data = Arrays.copyOf(data, cap);
            }
        }

        public void add(int x) {
            ensureSpace(size + 1);
            data[size++] = x;
        }

        public void addAll(int[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(IntegerList list) {
            addAll(list.data, 0, list.size);
        }

        public void sort() {
            if (size <= 1) {
                return;
            }
            Randomized.shuffle(data, 0, size);
            Arrays.sort(data, 0, size);
        }

        public void unique() {
            if (size <= 1) {
                return;
            }

            sort();
            int wpos = 1;
            for (int i = 1; i < size; i++) {
                if (data[i] != data[wpos - 1]) {
                    data[wpos++] = data[i];
                }
            }
            size = wpos;
        }

        public int binarySearch(int x) {
            return Arrays.binarySearch(data, 0, size, x);
        }

        public int size() {
            return size;
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public String toString() {
            return Arrays.toString(toArray());
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof IntegerList)) {
                return false;
            }
            IntegerList other = (IntegerList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Integer.hashCode(data[i]);
            }
            return h;
        }

        public IntegerList clone() {
            IntegerList ans = new IntegerList();
            ans.addAll(this);
            return ans;
        }

    }

    static class ConnectionChecker {
        private ConnectionChecker.LCTNode[] nodes;
        private int time = -1;

        public ConnectionChecker(int n) {
            nodes = new ConnectionChecker.LCTNode[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new ConnectionChecker.LCTNode();
                nodes[i].id = i;
                nodes[i].dieTime = Integer.MAX_VALUE;
                nodes[i].w = 1;
                nodes[i].pushUp();
            }
            for (int i = 1; i < n; i++) {
                ConnectionChecker.LCTNode node = new ConnectionChecker.LCTNode();
                node.dieTime = time;
                node.a = nodes[i - 1];
                node.b = nodes[i];
                node.pushUp();
                ConnectionChecker.LCTNode.join(node.a, node);
                ConnectionChecker.LCTNode.join(node.b, node);
            }
        }

        public void addEdge(int aId, int bId, int dieTime) {
            ConnectionChecker.LCTNode a = nodes[aId];
            ConnectionChecker.LCTNode b = nodes[bId];
            ConnectionChecker.LCTNode.findRoute(a, b);
            ConnectionChecker.LCTNode.splay(a);
            if (a.eldest.dieTime >= dieTime) {
                return;
            }
            ConnectionChecker.LCTNode eldest = a.eldest;
            ConnectionChecker.LCTNode.splay(eldest);
            ConnectionChecker.LCTNode.cut(eldest.a, eldest);
            ConnectionChecker.LCTNode.cut(eldest.b, eldest);

            ConnectionChecker.LCTNode node = new ConnectionChecker.LCTNode();
            node.dieTime = dieTime;
            node.a = a;
            node.b = b;
            node.pushUp();
            ConnectionChecker.LCTNode.join(node.a, node);
            ConnectionChecker.LCTNode.join(node.b, node);
        }

        public int check(int aId, int bId) {
            ConnectionChecker.LCTNode a = nodes[aId];
            ConnectionChecker.LCTNode b = nodes[bId];
            ConnectionChecker.LCTNode.findRoute(a, b);
            ConnectionChecker.LCTNode.splay(b);
            return b.eldest.dieTime > time ? b.sum : -1;
        }

        public void elapse(int t) {
            time = t;
        }

        private static class LCTNode {
            public static final ConnectionChecker.LCTNode NIL = new ConnectionChecker.LCTNode();
            ConnectionChecker.LCTNode left = NIL;
            ConnectionChecker.LCTNode right = NIL;
            ConnectionChecker.LCTNode father = NIL;
            ConnectionChecker.LCTNode treeFather = NIL;
            boolean reverse;
            int id;
            int sum = 0;
            int w = 0;
            ConnectionChecker.LCTNode a;
            ConnectionChecker.LCTNode b;
            ConnectionChecker.LCTNode eldest;
            int dieTime;

            static {
                NIL.left = NIL;
                NIL.right = NIL;
                NIL.father = NIL;
                NIL.treeFather = NIL;
                NIL.dieTime = Integer.MAX_VALUE;
                NIL.eldest = NIL;
            }

            public static ConnectionChecker.LCTNode elder(ConnectionChecker.LCTNode a, ConnectionChecker.LCTNode b) {
                return a.dieTime < b.dieTime ? a : b;
            }

            public static void access(ConnectionChecker.LCTNode x) {
                ConnectionChecker.LCTNode last = NIL;
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

            public static void makeRoot(ConnectionChecker.LCTNode x) {
                access(x);
                splay(x);
                x.reverse();
            }

            public static void cut(ConnectionChecker.LCTNode y, ConnectionChecker.LCTNode x) {
                makeRoot(y);
                access(x);
                splay(y);
                y.right.treeFather = NIL;
                y.right.father = NIL;
                y.setRight(NIL);
                y.pushUp();
            }

            public static void join(ConnectionChecker.LCTNode y, ConnectionChecker.LCTNode x) {
                makeRoot(x);
                x.treeFather = y;
            }

            public static void findRoute(ConnectionChecker.LCTNode x, ConnectionChecker.LCTNode y) {
                makeRoot(y);
                access(x);
            }

            public static void splay(ConnectionChecker.LCTNode x) {
                if (x == NIL) {
                    return;
                }
                ConnectionChecker.LCTNode y, z;
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

            public static void zig(ConnectionChecker.LCTNode x) {
                ConnectionChecker.LCTNode y = x.father;
                ConnectionChecker.LCTNode z = y.father;
                ConnectionChecker.LCTNode b = x.right;

                y.setLeft(b);
                x.setRight(y);
                z.changeChild(y, x);

                y.pushUp();
            }

            public static void zag(ConnectionChecker.LCTNode x) {
                ConnectionChecker.LCTNode y = x.father;
                ConnectionChecker.LCTNode z = y.father;
                ConnectionChecker.LCTNode b = x.left;

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

                    ConnectionChecker.LCTNode tmpNode = left;
                    left = right;
                    right = tmpNode;

                    left.reverse();
                    right.reverse();
                }

                left.treeFather = treeFather;
                right.treeFather = treeFather;
            }

            public void reverse() {
                reverse = !reverse;
            }

            public void setLeft(ConnectionChecker.LCTNode x) {
                left = x;
                x.father = this;
            }

            public void setRight(ConnectionChecker.LCTNode x) {
                right = x;
                x.father = this;
            }

            public void changeChild(ConnectionChecker.LCTNode y, ConnectionChecker.LCTNode x) {
                if (left == y) {
                    setLeft(x);
                } else {
                    setRight(x);
                }
            }

            public void pushUp() {
                eldest = elder(this, left.eldest);
                eldest = elder(eldest, right.eldest);
                sum = left.sum + right.sum + w;
            }

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

    static class Randomized {
        private static Random random = new Random(0);

        public static void shuffle(int[] data, int from, int to) {
            to--;
            for (int i = from; i <= to; i++) {
                int s = nextInt(i, to);
                int tmp = data[i];
                data[i] = data[s];
                data[s] = tmp;
            }
        }

        public static int nextInt(int l, int r) {
            return random.nextInt(r - l + 1) + l;
        }

    }

    static class SequenceUtils {
        public static void deepFill(Object array, int val) {
            if (!array.getClass().isArray()) {
                throw new IllegalArgumentException();
            }
            if (array instanceof int[]) {
                int[] intArray = (int[]) array;
                Arrays.fill(intArray, val);
            } else {
                Object[] objArray = (Object[]) array;
                for (Object obj : objArray) {
                    deepFill(obj, val);
                }
            }
        }

        public static boolean equal(int[] a, int al, int ar, int[] b, int bl, int br) {
            if ((ar - al) != (br - bl)) {
                return false;
            }
            for (int i = al, j = bl; i <= ar; i++, j++) {
                if (a[i] != b[j]) {
                    return false;
                }
            }
            return true;
        }

    }
}