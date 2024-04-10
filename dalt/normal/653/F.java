import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.util.Deque;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.util.Collection;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
import java.util.ArrayDeque;
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
            FPaperTask solver = new FPaperTask();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FPaperTask {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            char[] s = new char[n];
            in.rs(s);
            int[] right = new int[n];
            for (int i = n - 1; i >= 0; i--) {
                if (i + 1 >= n || s[i] == ')') {
                    right[i] = n;
                    continue;
                }
                right[i] = i + 1;
                while (right[i] < n && s[right[i]] != ')') {
                    right[i] = right[right[i]] + 1;
                }
            }
            NoTagPersistentSegment[] sts = new NoTagPersistentSegment[n + 1];
            sts[n] = NoTagPersistentSegment.NIL;
            for (int i = n - 1; i >= 0; i--) {
                if (right[i] >= n) {
                    sts[i] = NoTagPersistentSegment.NIL;
                    continue;
                }
                sts[i] = sts[right[i] + 1].clone();
                sts[i].update(right[i], right[i], 0, n - 1, 1);
            }
            SubstringCompare sc = new SubstringCompare(new IntFunctionIntSequenceAdapter(i -> s[i], 0, n - 1));
            int[] lcp = sc.lcp();
            int[] rank = sc.rank();
            long ans = 0;
            for (int i = 0; i < n; i++) {
                int l = i + 1;
                int r = n - 1;
                if (rank[i] < n - 1) {
                    l += lcp[rank[i]];
                }
                ans += sts[i].query(l, r, 0, n - 1);
            }
            out.println(ans);
        }

    }

    static interface IntToIntegerFunction {
        int apply(int x);

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private static final int THRESHOLD = 32 << 10;
        private final Writer os;
        private StringBuilder cache = new StringBuilder(THRESHOLD * 2);

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

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput append(char c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(long c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(String c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(long c) {
            return append(c).println();
        }

        public FastOutput println() {
            return append(System.lineSeparator());
        }

        public FastOutput flush() {
            try {
//            boolean success = false;
//            if (stringBuilderValueField != null) {
//                try {
//                    char[] value = (char[]) stringBuilderValueField.get(cache);
//                    os.write(value, 0, cache.length());
//                    success = true;
//                } catch (Exception e) {
//                }
//            }
//            if (!success) {
                os.append(cache);
//            }
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

    static class RMQ {
        private IntegerMultiWayStack stack;
        private RMQ.LcaOnTree lca;
        private Deque deque;
        private RMQ.Node[] nodes;
        private int offset;

        public RMQ(RMQ model) {
            this.stack = model.stack;
            this.deque = model.deque;
            this.nodes = model.nodes;
            this.lca = new RMQ.LcaOnTree(this.nodes.length);
        }

        public RMQ(int n) {
            stack = new IntegerMultiWayStack(n, n - 1);
            lca = new RMQ.LcaOnTree(n);
            deque = new ArrayDeque(n);
            nodes = new RMQ.Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new RMQ.Node();
            }
        }

        public void init(int l, int r, IntegerComparator comp) {
            assert l <= r;
            int len = r - l + 1;
            stack.expandStackNum(len);
            stack.clear();
            deque.clear();
            offset = l;

            for (int i = 0; i < len; i++) {
                nodes[i].index = i;
                nodes[i].left = nodes[i].right = null;
            }
            Deque<RMQ.Node> deque = new ArrayDeque<>(len);
            for (int i = 0; i < len; i++) {
                while (!deque.isEmpty() && comp.compare(deque.peekLast().index + offset,
                        nodes[i].index + offset) > 0) {
                    RMQ.Node tail = deque.removeLast();
                    tail.right = nodes[i].left;
                    nodes[i].left = tail;
                }
                deque.addLast(nodes[i]);
            }
            while (deque.size() > 1) {
                RMQ.Node tail = deque.removeLast();
                deque.peekLast().right = tail;
            }
            RMQ.Node root = deque.removeLast();
            for (int i = 0; i < len; i++) {
                if (nodes[i].left != null) {
                    stack.addLast(i, nodes[i].left.index);
                }
                if (nodes[i].right != null) {
                    stack.addLast(i, nodes[i].right.index);
                }
            }

            lca.reset(stack, root.index);
        }

        private static class LcaOnTree {
            int[] parent;
            int[] preOrder;
            int[] i;
            int[] head;
            int[] a;
            int time;

            void dfs1(IntegerMultiWayStack tree, int u, int p) {
                parent[u] = p;
                i[u] = preOrder[u] = time++;
                for (IntegerIterator iterator = tree.iterator(u); iterator.hasNext(); ) {
                    int v = iterator.next();
                    if (v == p) continue;
                    dfs1(tree, v, u);
                    if (Integer.lowestOneBit(i[u]) < Integer.lowestOneBit(i[v])) {
                        i[u] = i[v];
                    }
                }
                head[i[u]] = u;
            }

            void dfs2(IntegerMultiWayStack tree, int u, int p, int up) {
                a[u] = up | Integer.lowestOneBit(i[u]);
                for (IntegerIterator iterator = tree.iterator(u); iterator.hasNext(); ) {
                    int v = iterator.next();
                    if (v == p) continue;
                    dfs2(tree, v, u, a[u]);
                }
            }

            public void reset(IntegerMultiWayStack tree, int root) {
                time = 0;
                dfs1(tree, root, -1);
                dfs2(tree, root, -1, 0);
            }

            public LcaOnTree(int n) {
                preOrder = new int[n];
                i = new int[n];
                head = new int[n];
                a = new int[n];
                parent = new int[n];
            }

        }

        private static class Node {
            public int index;
            public RMQ.Node left;
            public RMQ.Node right;

            public String toString() {
                return "" + index;
            }

        }

    }

    static interface IntegerIterator {
        boolean hasNext();

        int next();

    }

    static class IntFunctionIntSequenceAdapter implements IntSequence {
        IntToIntegerFunction data;
        int l;
        int r;

        public IntFunctionIntSequenceAdapter(IntToIntegerFunction data, int l, int r) {
            this.data = data;
            this.l = l;
            this.r = r;
        }

        public int get(int i) {
            return data.apply(l + i);
        }

        public int length() {
            return r - l + 1;
        }

    }

    static interface IntSequence {
        int get(int i);

        int length();

    }

    static class SuffixArrayDC3 {
        static boolean leq(int a1, int a2, int b1, int b2) {
            return a1 < b1 || a1 == b1 && a2 <= b2;
        }

        static boolean leq(int a1, int a2, int a3, int b1, int b2, int b3) {
            return a1 < b1 || a1 == b1 && leq(a2, a3, b2, b3);
        }

        static void radixPass(int[] a, int[] b, int[] r, int offset, int n, int K) {
            int[] cnt = new int[K + 1];
            for (int i = 0; i < n; i++)
                ++cnt[r[a[i] + offset]];
            for (int i = 1; i < cnt.length; i++)
                cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; i--)
                b[--cnt[r[a[i] + offset]]] = a[i];
        }

        private static void suffixArray(int[] T, int[] SA, int n, int K) {
            int n0 = (n + 2) / 3;
            int n1 = (n + 1) / 3;
            int n2 = n / 3;
            int n02 = n0 + n2;

            //******* Step 0: Construct sample ********
            // generate positions of mod 1 and mod 2 suffixes
            // the "+(n0-n1)" adds a dummy mod 1 suffix if n%3 == 1
            int[] R = new int[n02 + 3];
            for (int i = 0, j = 0; i < n + (n0 - n1); i++) if (i % 3 != 0) R[j++] = i;

            //******* Step 1: Sort sample suffixes ********
            // lsb radix sort the mod 1 and mod 2 triples
            int[] SA12 = new int[n02 + 3];
            radixPass(R, SA12, T, 2, n02, K);
            radixPass(SA12, R, T, 1, n02, K);
            radixPass(R, SA12, T, 0, n02, K);

            // find lexicographic names of triples and
            // write them to correct places in R
            int name = 0;
            for (int i = 0; i < n02; i++) {
                if (i == 0 || T[SA12[i]] != T[SA12[i - 1]] || T[SA12[i] + 1] != T[SA12[i - 1] + 1] || T[SA12[i] + 2] != T[SA12[i - 1] + 2]) {
                    ++name;
                }
                R[SA12[i] / 3 + (SA12[i] % 3 == 1 ? 0 : n0)] = name;
            }

            if (name < n02) {
                // recurse if names are not yet unique
                suffixArray(R, SA12, n02, name);
                // store unique names in R using the suffix array
                for (int i = 0; i < n02; i++)
                    R[SA12[i]] = i + 1;
            } else {
                // generate the suffix array of R directly
                for (int i = 0; i < n02; i++)
                    SA12[R[i] - 1] = i;
            }

            //******* Step 2: Sort nonsample suffixes ********
            // stably sort the mod 0 suffixes from SA12 by their first character
            int[] R0 = new int[n0];
            for (int i = 0, j = 0; i < n02; i++)
                if (SA12[i] < n0) R0[j++] = 3 * SA12[i];
            int[] SA0 = new int[n0];
            radixPass(R0, SA0, T, 0, n0, K);

            //******* Step 3: Merge ********
            // merge sorted SA0 suffixes and sorted SA12 suffixes
            for (int p = 0, t = n0 - n1, k = 0; k < n; k++) {
                int i = SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2; // pos of current offset 12 suffix
                int j = SA0[p]; // pos of current offset 0 suffix
                if (SA12[t] < n0 ? // different compares for mod 1 and mod 2 suffixes
                        leq(T[i], R[SA12[t] + n0], T[j], R[j / 3]) :
                        leq(T[i], T[i + 1], R[SA12[t] - n0 + 1], T[j], T[j + 1], R[j / 3 + n0])) { // suffix from SA12 is smaller
                    SA[k] = i;
                    if (++t == n02) // done --- only SA0 suffixes left
                        for (k++; p < n0; p++, k++)
                            SA[k] = SA0[p];
                } else { // suffix from SA0 is smaller
                    SA[k] = j;
                    if (++p == n0) // done --- only SA12 suffixes left
                        for (k++; t < n02; t++, k++)
                            SA[k] = SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2;
                }
            }
        }

        public static int[] suffixArray(IntSequence s) {
            int n = s.length();
            if (n <= 1)
                return new int[n];
            int[] S = IntStream.range(0, n + 3).map(i -> i < n ? s.get(i) : 0).toArray();
            int[] sa = new int[n];
            suffixArray(S, sa, n, 255);
            return sa;
        }

        public static int[] rank(int[] sa) {
            int[] inv = new int[sa.length];
            for (int i = 0; i < sa.length; i++) {
                inv[sa[i]] = i;
            }
            return inv;
        }

        public static int[] lcp(int[] sa, int[] rank, IntSequence s) {
            int n = sa.length;
            int[] lcp = new int[n - 1];
            for (int i = 0, h = 0; i < n; i++) {
                if (rank[i] < n - 1) {
                    for (int j = sa[rank[i] + 1]; Math.max(i, j) + h < s.length() && s.get(i + h) == s.get(j + h); ++h)
                        ;
                    lcp[rank[i]] = h;
                    if (h > 0)
                        --h;
                }
            }
            return lcp;
        }

    }

    static class NoTagPersistentSegment implements Cloneable {
        public static final NoTagPersistentSegment NIL = new NoTagPersistentSegment();
        private NoTagPersistentSegment left;
        private NoTagPersistentSegment right;
        int cnt;

        static {
            NIL.left = NIL.right = NIL;
        }

        public void pushUp() {
            cnt = left.cnt + right.cnt;
        }

        public NoTagPersistentSegment() {
            left = right = NIL;
        }

        private boolean covered(int ll, int rr, int l, int r) {
            return ll <= l && rr >= r;
        }

        private boolean noIntersection(int ll, int rr, int l, int r) {
            return ll > r || rr < l;
        }

        public void update(int ll, int rr, int l, int r, int x) {
            if (covered(ll, rr, l, r)) {
                cnt += x;
                return;
            }
            int m = DigitUtils.floorAverage(l, r);
            if (!noIntersection(ll, rr, l, m)) {
                left = left.clone();
                left.update(ll, rr, l, m, x);
            }
            if (!noIntersection(ll, rr, m + 1, r)) {
                right = right.clone();
                right.update(ll, rr, m + 1, r, x);
            }
            pushUp();
        }

        public int query(int ll, int rr, int l, int r) {
            if (this == NIL || noIntersection(ll, rr, l, r)) {
                return 0;
            }
            if (covered(ll, rr, l, r)) {
                return cnt;
            }
            int m = DigitUtils.floorAverage(l, r);
            return left.query(ll, rr, l, m) +
                    right.query(ll, rr, m + 1, r);
        }

        public NoTagPersistentSegment clone() {
            try {
                return (NoTagPersistentSegment) super.clone();
            } catch (CloneNotSupportedException e) {
                throw new RuntimeException(e);
            }
        }

    }

    static class SubstringCompare {
        int[] sa;
        int[] lcp;
        int[] rank;
        RMQ rmq;

        public int[] lcp() {
            return lcp;
        }

        public int[] rank() {
            return rank;
        }

        public SubstringCompare(IntSequence seq) {
            if (seq.length() <= 1) {
                sa = new int[1];
                rank = new int[1];
                lcp = new int[0];
                return;
            }
            sa = SuffixArrayDC3.suffixArray(seq);
            rank = SuffixArrayDC3.rank(sa);
            lcp = SuffixArrayDC3.lcp(sa, rank, seq);
            rmq = new RMQ(lcp.length);
            rmq.init(0, lcp.length - 1, (i, j) -> Integer.compare(lcp[i], lcp[j]));
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

        public int ri() {
            return readInt();
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

        public int rs(char[] data, int offset) {
            return readString(data, offset);
        }

        public int rs(char[] data) {
            return rs(data, 0);
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

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int floorAverage(int x, int y) {
            return (x & y) + ((x ^ y) >> 1);
        }

    }

    static class IntegerMultiWayStack {
        private int[] values;
        private int[] next;
        private int[] heads;
        private int alloc;
        private int stackNum;

        public IntegerIterator iterator(final int queue) {
            return new IntegerIterator() {
                int ele = heads[queue];


                public boolean hasNext() {
                    return ele != 0;
                }


                public int next() {
                    int ans = values[ele];
                    ele = next[ele];
                    return ans;
                }
            };
        }

        private void doubleCapacity() {
            int newSize = Math.max(next.length + 10, next.length * 2);
            next = Arrays.copyOf(next, newSize);
            values = Arrays.copyOf(values, newSize);
        }

        public void alloc() {
            alloc++;
            if (alloc >= next.length) {
                doubleCapacity();
            }
            next[alloc] = 0;
        }

        public void clear() {
            alloc = 0;
            Arrays.fill(heads, 0, stackNum, 0);
        }

        public boolean isEmpty(int qId) {
            return heads[qId] == 0;
        }

        public void expandStackNum(int qNum) {
            if (qNum <= stackNum) {
            } else if (qNum <= heads.length) {
                Arrays.fill(heads, stackNum, qNum, 0);
            } else {
                Arrays.fill(heads, stackNum, heads.length, 0);
                heads = Arrays.copyOf(heads, qNum);
            }
            stackNum = qNum;
        }

        public IntegerMultiWayStack(int qNum, int totalCapacity) {
            values = new int[totalCapacity + 1];
            next = new int[totalCapacity + 1];
            heads = new int[qNum];
            stackNum = qNum;
        }

        public void addLast(int qId, int x) {
            alloc();
            values[alloc] = x;
            next[alloc] = heads[qId];
            heads[qId] = alloc;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < stackNum; i++) {
                if (isEmpty(i)) {
                    continue;
                }
                builder.append(i).append(": ");
                for (IntegerIterator iterator = iterator(i); iterator.hasNext(); ) {
                    builder.append(iterator.next()).append(",");
                }
                if (builder.charAt(builder.length() - 1) == ',') {
                    builder.setLength(builder.length() - 1);
                }
                builder.append('\n');
            }
            return builder.toString();
        }

    }

    static interface IntegerComparator {
        public int compare(int a, int b);

    }
}