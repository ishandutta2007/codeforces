import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Iterator;
import java.util.function.IntUnaryOperator;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.Objects;
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
            HSecurity solver = new HSecurity();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class HSecurity {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            String s = in.readString();
            int n = s.length();
            SuffixTree st = new SuffixTree(i -> i < n ? s.charAt(i) : 'a' - 1, n + 1, 'a' - 1, 'z');
            st.dfs(st.getRoot());
            int q = in.readInt();
            Query[] queries = new Query[q];
            for (int i = 0; i < q; i++) {
                queries[i] = new Query();
                queries[i].l = in.readInt() - 1;
                queries[i].r = in.readInt() - 1;
                queries[i].x = in.readString();
            }
            Query[] sorted = queries.clone();
            Arrays.sort(sorted, (a, b) -> a.l - b.l);
            SimplifiedDeque<Query> deque = new Array2DequeAdapter<>(sorted);
            for (int i = s.length() - 1; i >= 0; i--) {
                st.enable(i);
                while (!deque.isEmpty() && deque.peekLast().l == i) {
                    Query query = deque.removeLast();
                    int m = query.x.length();
                    query.ans = st.search(j -> j < m ? query.x.charAt(j) : 'a' - 1, m + 1, query.r);
                }
            }

            for (Query query : queries) {
                if (query.ans == -1) {
                    out.println(query.ans);
                    continue;
                }
                for (int j = query.ans; ; j++) {
                    out.append(s.charAt(j));
                    if (query.x.length() <= j - query.ans || s.charAt(j) != query.x.charAt(j - query.ans)) {
                        break;
                    }
                }
                out.println();
            }
        }

    }

    static class SequenceUtils {
        public static <T> int indexOf(T[] array, int l, int r, T val) {
            for (int i = l; i <= r; i++) {
                if (Objects.equals(array[i], val)) {
                    return i;
                }
            }
            return -1;
        }

    }

    static interface SimplifiedDeque<T> extends SimplifiedStack<T> {
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

    static class SuffixTree {
        private int minCharacter;
        private int maxCharacter;
        private int alphabet;
        private SuffixTree.Node root;
        private int n;
        private IntUnaryOperator s;
        private SuffixTree.Node[] suffixIndex2Node;
        private Segment segment;
        int idAlloc = 0;

        public void enable(int suffix) {
            segment.update(suffixIndex2Node[suffix].l, suffixIndex2Node[suffix].l, 1, n, suffix);
        }

        public void dfs(SuffixTree.Node root) {
            if (root.end == n) {
                root.l = root.r = ++idAlloc;
                suffixIndex2Node[root.begin - root.depth] = root;
                return;
            }
            root.l = Integer.MAX_VALUE;
            root.r = Integer.MIN_VALUE;
            for (SuffixTree.Node node : root.children) {
                if (node == null) {
                    continue;
                }
                dfs(node);
                root.l = Math.min(root.l, node.l);
                root.r = Math.max(root.r, node.r);
            }
        }

        public int find(SuffixTree.Node node) {
            return segment.query(node.l, node.r, 1, n);
        }

        public int search(IntUnaryOperator x, int m, int r) {
            SuffixTree.Node trace = root;
            int sl = trace.begin;
            int sr = trace.end - 1;

            SuffixTree.Node startPoint = null;
            int startIndex = -1;

            int i;
            for (i = 0; i < m; i++) {
                int val = x.applyAsInt(i);
                if (sl > sr) {
                    if (trace.children[val - minCharacter] == null) {
                        startPoint = trace;
                        startIndex = val - minCharacter + 1;
                        break;
                    }
                    trace = trace.children[val - minCharacter];
                    sl = trace.begin;
                    sr = trace.end - 1;
                }
                if (s.applyAsInt(sl) != val) {
                    startPoint = trace.parent;
                    startIndex = SequenceUtils.indexOf(startPoint.children, 0, alphabet - 1, trace) + 1;
                    if (s.applyAsInt(sl) > val) {
                        int suffix = find(trace);
                        if (r - suffix + 1 > i) {
                            return suffix;
                        }
                    }
                    break;
                }
                sl++;
                if (i == m - 1) {
                    if (sl <= sr) {
                        throw new RuntimeException();
                    }
                    startPoint = trace.parent;
                    startIndex = SequenceUtils.indexOf(startPoint.children, 0, alphabet - 1, trace) + 1;
                }
            }

            while (startPoint != null) {
                if (startIndex >= alphabet) {
                    SuffixTree.Node last = startPoint;
                    startPoint = startPoint.parent;
                    if (startPoint == null) {
                        break;
                    }
                    startIndex = x.applyAsInt(last.depth) - minCharacter + 1;
                    continue;
                }
                if (startPoint.children[startIndex] != null) {
                    int suffix = find(startPoint.children[startIndex]);
                    if (r - suffix + 1 > startPoint.children[startIndex].depth) {
                        return suffix;
                    }
                }
                startIndex++;
            }
            return -1;
        }

        public SuffixTree.Node getRoot() {
            return root;
        }

        public SuffixTree(IntUnaryOperator s, int n, int minCharacter, int maxCharacter) {
            suffixIndex2Node = new SuffixTree.Node[n];
            segment = new Segment(1, n);
            this.n = n;
            this.s = s;
            int[] a = new int[n];
            this.minCharacter = minCharacter;
            this.maxCharacter = maxCharacter;
            alphabet = maxCharacter - minCharacter + 1;
            for (int i = 0; i < n; i++) a[i] = s.applyAsInt(i) - minCharacter;
            root = new SuffixTree.Node(0, 0, 0, null, alphabet);
            SuffixTree.Node node = root;
            for (int i = 0, tail = 0; i < n; i++, tail++) {
                SuffixTree.Node last = null;
                while (tail >= 0) {
                    SuffixTree.Node ch = node.children[a[i - tail]];
                    while (ch != null && tail >= ch.end - ch.begin) {
                        tail -= ch.end - ch.begin;
                        node = ch;
                        ch = ch.children[a[i - tail]];
                    }
                    if (ch == null) {
                        node.children[a[i]] = new SuffixTree.Node(i, n, node.depth + node.end - node.begin, node, alphabet);
                        if (last != null) last.suffixLink = node;
                        last = null;
                    } else {
                        int afterTail = a[ch.begin + tail];
                        if (afterTail == a[i]) {
                            if (last != null) last.suffixLink = node;
                            break;
                        } else {
                            SuffixTree.Node splitNode = new SuffixTree.Node(ch.begin, ch.begin + tail, node.depth + node.end - node.begin, node, alphabet);
                            splitNode.children[a[i]] = new SuffixTree.Node(i, n, ch.depth + tail, splitNode, alphabet);
                            splitNode.children[afterTail] = ch;
                            ch.begin += tail;
                            ch.depth += tail;
                            ch.parent = splitNode;
                            node.children[a[i - tail]] = splitNode;
                            if (last != null) last.suffixLink = splitNode;
                            last = splitNode;
                        }
                    }
                    if (node == root) {
                        --tail;
                    } else {
                        node = node.suffixLink;
                    }
                }
            }
        }

        public static class Node {
            public int begin;
            public int end;
            public int depth;
            public SuffixTree.Node parent;
            public SuffixTree.Node[] children;
            public SuffixTree.Node suffixLink;
            int l;
            int r;

            Node(int begin, int end, int depth, SuffixTree.Node parent, int alphabet) {
                this.begin = begin;
                this.end = end;
                this.parent = parent;
                this.depth = depth;
                children = new SuffixTree.Node[alphabet];
            }

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

    static class Array2DequeAdapter<T> implements SimplifiedDeque<T> {
        T[] data;
        int l;
        int r;

        public Array2DequeAdapter(T[] data) {
            this(data, 0, data.length - 1);
        }

        public Array2DequeAdapter(T[] data, int l, int r) {
            this.data = data;
            this.l = l;
            this.r = r;
        }

        public boolean isEmpty() {
            return l > r;
        }

        public T peekLast() {
            return data[r];
        }

        public T removeLast() {
            return data[r--];
        }

        public Iterator<T> iterator() {
            return new Iterator<T>() {
                int iter = l;


                public boolean hasNext() {
                    return iter <= r;
                }


                public T next() {
                    return data[iter++];
                }
            };
        }

    }

    static class Segment implements Cloneable {
        private Segment left;
        private Segment right;
        private static int inf = (int) 1e9;
        private int min = inf;

        public void pushUp() {
            min = Math.min(left.min, right.min);
        }

        public void pushDown() {
        }

        public Segment(int l, int r) {
            if (l < r) {
                int m = (l + r) >> 1;
                left = new Segment(l, m);
                right = new Segment(m + 1, r);
                pushUp();
            } else {

            }
        }

        private boolean covered(int ll, int rr, int l, int r) {
            return ll <= l && rr >= r;
        }

        private boolean noIntersection(int ll, int rr, int l, int r) {
            return ll > r || rr < l;
        }

        public void update(int ll, int rr, int l, int r, int x) {
            if (noIntersection(ll, rr, l, r)) {
                return;
            }
            if (covered(ll, rr, l, r)) {
                min = Math.min(min, x);
                return;
            }
            pushDown();
            int m = (l + r) >> 1;
            left.update(ll, rr, l, m, x);
            right.update(ll, rr, m + 1, r, x);
            pushUp();
        }

        public int query(int ll, int rr, int l, int r) {
            if (noIntersection(ll, rr, l, r)) {
                return inf;
            }
            if (covered(ll, rr, l, r)) {
                return min;
            }
            pushDown();
            int m = (l + r) >> 1;
            return Math.min(left.query(ll, rr, l, m),
                    right.query(ll, rr, m + 1, r));
        }

    }

    static class Query {
        int l;
        int r;
        String x;
        int ans;

    }

    static interface SimplifiedStack<T> extends Iterable<T> {
        boolean isEmpty();

        T peekLast();

        T removeLast();

    }
}