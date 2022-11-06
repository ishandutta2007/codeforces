import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.TreeSet;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
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
            FKoalaAndNotebook solver = new FKoalaAndNotebook();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FKoalaAndNotebook {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            Node[] nodes = new Node[n + 1];
            for (int i = 1; i <= n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
            }

            DigitBase base = new DigitBase(10);
            for (int i = 1; i <= m; i++) {
                Node a = nodes[in.readInt()];
                Node b = nodes[in.readInt()];
                Edge e = new Edge();
                e.a = a;
                e.b = b;
                e.len = i;
                a.next.add(e);
                b.next.add(e);
            }

            StringTree tree = new StringTree(0, 9, 1000000);
            TreeSet<Node> set = new TreeSet<>((a, b) -> {
                int ans = StringTree.TrieNode.compare(a.t, b.t);
                if (ans == 0) {
                    ans = a.id - b.id;
                }
                return ans;
            });
            nodes[1].t = tree.getRoot();
            StringTree.TrieNode inf = tree.getMax();
            for (int i = 2; i <= n; i++) {
                nodes[i].t = inf;
            }

            set.add(nodes[1]);
            while (!set.isEmpty()) {
                Node head = set.pollFirst();
                for (Edge e : head.next) {
                    Node node = e.other(head);
                    StringTree.TrieNode trie = insert(tree, head.t, e.len);
                    if (StringTree.TrieNode.compare(node.t, trie) <= 0) {
                        continue;
                    }
                    set.remove(node);
                    node.t = trie;
                    set.add(node);
                }
            }

            for (int i = 2; i <= n; i++) {
                out.println(nodes[i].t.r);
            }
        }

        public StringTree.TrieNode insert(StringTree tree, StringTree.TrieNode root, int digit) {
            if (digit == 0) {
                return root;
            }
            root = insert(tree, root, digit / 10);
            return tree.insert(root, digit % 10);
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static boolean isMultiplicationOverflow(long a, long b, long limit) {
            if (limit < 0) {
                limit = -limit;
            }
            if (a < 0) {
                a = -a;
            }
            if (b < 0) {
                b = -b;
            }
            if (a == 0 || b == 0) {
                return false;
            }
            //a * b > limit => a > limit / b
            return a > limit / b;
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

        public int valueOf(long x) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            return (int) x;
        }

        public String toString() {
            return "mod " + m;
        }

    }

    static class LongList implements Cloneable {
        private int size;
        private int cap;
        private long[] data;
        private static final long[] EMPTY = new long[0];

        public LongList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new long[cap];
            }
        }

        public LongList(LongList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public LongList() {
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

        private void checkRange(int i) {
            if (i < 0 || i >= size) {
                throw new ArrayIndexOutOfBoundsException();
            }
        }

        public void add(long x) {
            ensureSpace(size + 1);
            data[size++] = x;
        }

        public void addAll(long[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(LongList list) {
            addAll(list.data, 0, list.size);
        }

        public long tail() {
            checkRange(0);
            return data[size - 1];
        }

        public long[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public String toString() {
            return Arrays.toString(toArray());
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof LongList)) {
                return false;
            }
            LongList other = (LongList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Long.hashCode(data[i]);
            }
            return h;
        }

        public LongList clone() {
            LongList ans = new LongList();
            ans.addAll(this);
            return ans;
        }

    }

    static class Edge {
        Node a;
        Node b;
        int len;

        Node other(Node x) {
            return a == x ? b : a;
        }

    }

    static class DigitBase {
        private long[] pow;
        private long base;

        public DigitBase(long base) {
            if (base <= 1) {
                throw new IllegalArgumentException();
            }
            this.base = base;
            LongList ll = new LongList(64);
            ll.add(1);
            while (!DigitUtils.isMultiplicationOverflow(ll.tail(), base, Long.MAX_VALUE)) {
                ll.add(ll.tail() * base);
            }
            pow = ll.toArray();
        }

    }

    static class CachedLog2 {
        private static final int BITS = 16;
        private static final int LIMIT = 1 << BITS;
        private static final byte[] CACHE = new byte[LIMIT];

        static {
            int b = 0;
            for (int i = 0; i < LIMIT; i++) {
                while ((1 << (b + 1)) <= i) {
                    b++;
                }
                CACHE[i] = (byte) b;
            }
        }

        public static int ceilLog(int x) {
            int ans = floorLog(x);
            if ((1 << ans) < x) {
                ans++;
            }
            return ans;
        }

        public static int floorLog(int x) {
            return x < LIMIT ? CACHE[x] : (BITS + CACHE[x >>> BITS]);
        }

    }

    static class SequenceUtils {
        public static boolean equal(long[] a, int al, int ar, long[] b, int bl, int br) {
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

    static class StringTree {
        static Modular mod = new Modular(1e9 + 7);
        int l;
        int r;
        int log;
        StringTree.TrieNode root;
        StringTree.TrieNode max;
        StringTree.TrieNode min;

        public StringTree.TrieNode getRoot() {
            return root;
        }

        public StringTree.TrieNode getMax() {
            return max;
        }

        public StringTree(int l, int r, int maxDepth) {
            if (maxDepth == Integer.MAX_VALUE) {
                maxDepth--;
            }

            this.l = l;
            this.r = r;
            log = CachedLog2.ceilLog(maxDepth + 1);
            root = newTrieNode();
            max = newTrieNode(root, 0);
            min = newTrieNode(root, 0);
            max.depth = maxDepth + 1;
            min.depth = -1;
        }

        private StringTree.TrieNode newTrieNode() {
            StringTree.TrieNode ans = new StringTree.TrieNode();
            ans.next = new StringTree.TrieNode[r - l + 1];
            ans.jump = new StringTree.TrieNode[log + 1];
            return ans;
        }

        public StringTree.TrieNode newTrieNode(StringTree.TrieNode p, int c) {
            StringTree.TrieNode node = newTrieNode();
            node.depth = p.depth + 1;
            node.value = c;
            node.jump[0] = p;
            node.r = mod.valueOf(p.r * 10L + c);
            for (int i = 0; node.jump[i] != null; i++) {
                node.jump[i + 1] = node.jump[i].jump[i];
            }
            return node;
        }

        public StringTree.TrieNode insert(StringTree.TrieNode root, int digit) {
            if (root.next[digit - l] == null) {
                root.next[digit - l] = newTrieNode(root, digit);
            }
            return root.next[digit - l];
        }

        public static class TrieNode {
            int depth;
            int value;
            StringTree.TrieNode[] next;
            StringTree.TrieNode[] jump;
            int r;

            public static int compare(StringTree.TrieNode a, StringTree.TrieNode b) {
                if (a.depth != b.depth) {
                    return a.depth - b.depth;
                }
                if (a == b) {
                    return 0;
                }
                StringTree.TrieNode lca = lca(a, b);
                a = gotoDepth(a, lca.depth + 1);
                b = gotoDepth(b, lca.depth + 1);
                return a.value - b.value;
            }

            public static StringTree.TrieNode lca(StringTree.TrieNode a, StringTree.TrieNode b) {
                if (a.depth > b.depth) {
                    StringTree.TrieNode tmp = a;
                    a = b;
                    b = tmp;
                }
                b = gotoDepth(b, a.depth);
                if (a == b) {
                    return a;
                }
                for (int i = 20; i >= 0; i--) {
                    if (a.jump[i] == b.jump[i]) {
                        continue;
                    }
                    a = a.jump[i];
                    b = b.jump[i];
                }
                return a.jump[0];
            }

            public static StringTree.TrieNode gotoDepth(StringTree.TrieNode t, int d) {
                if (t.depth == d) {
                    return t;
                }
                int log = CachedLog2.floorLog(t.depth - d);
                return gotoDepth(t.jump[log], d);
            }

            public String toString() {
                return jump[0] == null ? "" : jump[0].toString() + value;
            }

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

    static class Node {
        List<Edge> next = new ArrayList<>();
        StringTree.TrieNode t;
        int id;

    }
}