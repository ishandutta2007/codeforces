import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Iterator;
import java.util.function.IntUnaryOperator;
import java.io.IOException;
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
            GYetAnotherLCPProblem solver = new GYetAnotherLCPProblem();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class GYetAnotherLCPProblem {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int q = in.readInt();
            char[] s = new char[n + 1];
            in.readString(s, 1);
            SAIS sais = new SAIS(s, 1, n);
            int[] lcp = new int[n];
            for (int i = 0; i + 1 < n; i++) {
                lcp[i] = sais.longestCommonPrefixBetween(i + 1);
            }
            lcp[n - 1] = 0;
            IntegerRMQ rmq = new IntegerRMQ(lcp, (a, b) -> a - b);

            for (int i = 0; i < q; i++) {
                int k = in.readInt();
                int l = in.readInt();
                Node[] nodes = new Node[k + l];
                for (int j = 0; j < k; j++) {
                    nodes[j] = new Node();
                    nodes[j].type = 0;
                    nodes[j].index = sais.queryRank(in.readInt());
                }
                for (int j = k; j < k + l; j++) {
                    nodes[j] = new Node();
                    nodes[j].type = 1;
                    nodes[j].index = sais.queryRank(in.readInt());
                }
                Arrays.sort(nodes, (a, b) -> a.index - b.index);
                for (int j = 0; j + 1 < k + l; j++) {
                    if (nodes[j].index == nodes[j + 1].index) {
                        nodes[j].lcpWithNext = n + 1 - sais.queryKth(nodes[j].index);
                    } else {
                        nodes[j].lcpWithNext = lcp[rmq.query(nodes[j].index, nodes[j + 1].index - 1)];
                    }
                }
                nodes[k + l - 1].lcpWithNext = 0;
                long ans = dac(nodes, 0, k + l - 1);
                out.println(ans);
            }
        }

        public long dac(Node[] nodes, int l, int r) {
            if (l >= r) {
                return 0;
            }
            int m = (l + r) >>> 1;
            long ans = dac(nodes, l, m) + dac(nodes, m + 1, r);
            long contrib = 0;

            SimplifiedDeque<Node> deque = new Array2DequeAdapter<>(nodes, m, r);
            long[] cnts = new long[2];
            int lMin = nodes[m].lcpWithNext;
            int rMin = (int) 1e8;
            for (int i = m; i >= l; i--) {
                lMin = Math.min(lMin, nodes[i].lcpWithNext);
                while (!deque.isEmpty() && Math.min(deque.peekFirst().lcpWithNext, rMin) >= lMin) {
                    deque.removeFirst();
                    if (!deque.isEmpty()) {
                        cnts[deque.peekFirst().type]++;
                    }
                }
                contrib += lMin * cnts[1 - nodes[i].type];
            }
            deque = new Array2DequeAdapter<>(nodes, l, m);
            cnts[0] = cnts[1] = 0;
            lMin = (int) 1e8;
            rMin = nodes[m].lcpWithNext;
            for (int i = m + 1; i <= r; i++) {
                rMin = Math.min(rMin, nodes[i - 1].lcpWithNext);
                while (!deque.isEmpty() && Math.min(deque.peekLast().lcpWithNext, lMin) > rMin) {
                    cnts[deque.removeLast().type]++;
                }
                contrib += rMin * cnts[1 - nodes[i].type];
            }

            return ans + contrib;
        }

    }

    static interface IntegerIterator {
        boolean hasNext();

        int next();

    }

    static interface IntegerComparator {
        public int compare(int a, int b);

    }

    static class CompareUtils {
        private static final int[] BUF8 = new int[1 << 8];
        private static final IntegerList INT_LIST = new IntegerList();

        private CompareUtils() {
        }

        public static int minOf(int[] a, int l, int r) {
            int x = a[l];
            for (int i = l; i <= r; i++) {
                x = Math.min(x, a[i]);
            }
            return x;
        }

        public static void radixSort(int[] data, int l, int r, IntUnaryOperator indexFetcher) {
            INT_LIST.clear();
            INT_LIST.expandWith(0, r - l + 1);
            int[] output = INT_LIST.getData();
            for (int i = 0; i < 4; i++) {
                int rightShift = i * 8;
                int mask = BUF8.length - 1;
                radixSort0(data, output, BUF8, l, r, (x) -> (indexFetcher.applyAsInt(x) >>> rightShift) & mask);
                System.arraycopy(output, 0, data, l, r - l + 1);
            }
        }

        private static void radixSort0(int[] data, int[] output, int[] buf, int l, int r, IntUnaryOperator indexFetcher) {
            Arrays.fill(buf, 0);
            for (int i = l; i <= r; i++) {
                buf[indexFetcher.applyAsInt(data[i])]++;
            }
            for (int i = 1; i < buf.length; i++) {
                buf[i] += buf[i - 1];
            }
            for (int i = r; i >= l; i--) {
                output[--buf[indexFetcher.applyAsInt(data[i])]] = data[i];
            }
        }

    }

    static class SAIS {
        private int l;
        private int[] rank2Index;
        private int[] index2Rank;
        private int[] lcp;
        private int[] data;
        private static final int TYPE_MINUS = 0;
        private static final int TYPE_PLUS = 1;

        public int queryRank(int i) {
            return index2Rank[i - l];
        }

        public int queryKth(int k) {
            return rank2Index[k] + l;
        }

        public int longestCommonPrefixBetween(int i) {
            return lcp[i];
        }

        public SAIS(char[] array) {
            this(array, 0, array.length - 1);
        }

        public SAIS(int[] array) {
            this(array, 0, array.length - 1);
        }

        public SAIS(char[] array, int l, int r) {
            if (l > r) {
                throw new IllegalArgumentException();
            }
            this.l = l;
            int n = r - l + 1;
            data = new int[n];
            for (int i = 0; i < n; i++) {
                data[i] = array[i + l];
            }
            process();
        }

        public SAIS(int[] array, int l, int r) {
            if (l > r) {
                throw new IllegalArgumentException();
            }
            int n = r - l + 1;
            data = new int[n];
            for (int i = 0; i < n; i++) {
                data[i] = array[i + l];
            }
            process();
        }

        private void process() {
            int n = data.length;
            rank2Index = new int[n];
            index2Rank = new int[n];
            lcp = new int[n];
            for (int i = 0; i < n; i++) {
                rank2Index[i] = i;
            }
            int minElement = CompareUtils.minOf(data, 0, n - 1);
            CompareUtils.radixSort(rank2Index, 0, n - 1, x -> data[x] - minElement);
            int rank = 0;
            index2Rank[rank2Index[0]] = 0;
            for (int i = 1; i < data.length; i++) {
                if (data[rank2Index[i]] > data[rank2Index[i - 1]]) {
                    rank++;
                }
                index2Rank[rank2Index[i]] = rank;
            }

            System.arraycopy(index2Rank, 0, rank2Index, 0, n);
            buildSA(rank2Index, new IntegerList(n), new IntegerList(n), new MultiWayIntegerDeque(n, n), index2Rank);
            for (int i = 0; i < n; i++) {
                rank2Index[index2Rank[i]] = i;
            }
            buildLcp();
        }

        private void buildLcp() {
            int n = lcp.length;
            for (int i = 0; i < n; i++) {
                int ri = index2Rank[i];
                if (ri == 0) {
                    continue;
                }
                int j = rank2Index[ri - 1];
                int same = i == 0 ? 0 : Math.max(lcp[index2Rank[i - 1]] - 1, 0);
                while (j + same < n && i + same < n && data[j + same] == data[i + same]) {
                    same++;
                }
                lcp[index2Rank[i]] = same;
            }
        }

        private static void buildSA(int[] data, IntegerList plus, IntegerList minus, MultiWayIntegerDeque deque, int[] output) {
            int n = data.length;
            if (n == 1) {
                output[0] = 0;
                return;
            }
            byte[] type = new byte[n];
            for (int i = n - 1; i >= 0; i--) {
                if (i == n - 1 || data[i] > data[i + 1] || data[i] == data[i + 1] && type[i + 1] == TYPE_MINUS) {
                    type[i] = TYPE_MINUS;
                } else {
                    type[i] = TYPE_PLUS;
                }
            }

            plus.clear();
            minus.clear();

            // find relation between star type
            deque.expandQueueNum(n);
            deque.clear();
            for (int i = 1; i < n; i++) {
                if (type[i - 1] == TYPE_MINUS && type[i] == TYPE_PLUS) {
                    deque.addLast(data[i], i);
                }
            }
            for (int i = 0; i < n; i++) {
                while (!deque.isEmpty(i)) {
                    plus.add(deque.removeFirst(i));
                }
            }

            if (!plus.isEmpty()) {
                induceSort(plus, minus, type, data, deque);

                minus.clear();
                minus.addAll(plus);
                plus.clear();
                for (int i = 0, until = minus.size(); i < until; i++) {
                    int index = minus.get(i);
                    if (index > 0 && type[index - 1] == TYPE_MINUS && type[index] == TYPE_PLUS) {
                        plus.add(index);
                    }
                }

                minus.clear();
                for (int i = 1; i < n; i++) {
                    if (type[i - 1] == TYPE_MINUS && type[i] == TYPE_PLUS) {
                        minus.add(i);
                    }
                }

                int[] order2Index = minus.toArray();
                int[] alias = new int[order2Index.length];
                int[] index2Order = new int[n];
                for (int i = 0; i < order2Index.length; i++) {
                    index2Order[order2Index[i]] = i;
                }
                // assign alias
                int r = 0;
                alias[index2Order[plus.get(0)]] = r;
                for (int i = 1; i < order2Index.length; i++) {
                    int l1 = plus.get(i);
                    int l2 = plus.get(i - 1);
                    int r1 = index2Order[l1];
                    if (r1 + 1 == order2Index.length) {
                        r1 = n - 1;
                    } else {
                        r1 = order2Index[r1 + 1];
                    }
                    int r2 = index2Order[l2];
                    if (r2 + 1 == order2Index.length) {
                        r2 = n - 1;
                    } else {
                        r2 = order2Index[r2 + 1];
                    }
                    if (compareArray(data, l1, r1, data, l2, r2) != 0) {
                        r++;
                    }
                    alias[index2Order[plus.get(i)]] = r;
                }
                buildSA(alias, plus, minus, deque, output);
                int[] index2Rank = output;
                plus.clear();
                plus.expandWith(0, order2Index.length);
                for (int i = 0; i < order2Index.length; i++) {
                    plus.set(index2Rank[i], order2Index[i]);
                }
            }

            // find relation between minus type
            induceSort(plus, minus, type, data, deque);
            plus.reverse(0, plus.size() - 1);
            minus.reverse(0, minus.size() - 1);

            // merge
            int[] index2Rank = output;
            int rank = 0;
            while (plus.size() + minus.size() > 0) {
                if (plus.isEmpty() || (!minus.isEmpty() && data[minus.tail()] <= data[plus.tail()])) {
                    index2Rank[minus.pop()] = rank++;
                } else {
                    index2Rank[plus.pop()] = rank++;
                }
            }

            return;
        }

        private static int compareArray(int[] a, int al, int ar, int[] b, int bl, int br) {
            for (int i = al, j = bl; i <= ar && j <= br; i++, j++) {
                if (a[i] != b[j]) {
                    return a[i] - b[j];
                }
            }
            return -((ar - al) - (br - bl));
        }

        private static void induceSort(IntegerList plus, IntegerList minus, byte[] type, int[] data, MultiWayIntegerDeque deque) {
            int n = data.length;
            deque.expandQueueNum(n);
            minus.clear();
            plus.reverse(0, plus.size() - 1);

            // from star to minus
            deque.clear();
            deque.addFirst(data[n - 1], n - 1);
            for (int i = 0; i < n; i++) {
                while (!deque.isEmpty(i)) {
                    int index = deque.removeFirst(i);
                    if (type[index] == TYPE_MINUS) {
                        minus.add(index);
                    }
                    if (index > 0 && type[index - 1] == TYPE_MINUS) {
                        deque.addLast(data[index - 1], index - 1);
                    }
                }
                while (!plus.isEmpty() && data[plus.tail()] == i) {
                    int index = plus.pop();
                    if (index > 0 && type[index - 1] == TYPE_MINUS) {
                        deque.addLast(data[index - 1], index - 1);
                    }
                }
            }
            deque.clear();
            int rightScan = minus.size() - 1;
            // from minus to plus
            for (int i = n - 1; i >= 0; i--) {
                while (!deque.isEmpty(i)) {
                    int index = deque.removeFirst(i);
                    if (type[index] == TYPE_PLUS) {
                        plus.add(index);
                    }
                    if (index > 0 && type[index - 1] == TYPE_PLUS) {
                        deque.addLast(data[index - 1], index - 1);
                    }
                }
                while (rightScan >= 0 && data[minus.get(rightScan)] == i) {
                    int index = minus.get(rightScan--);
                    if (index > 0 && type[index - 1] == TYPE_PLUS) {
                        deque.addLast(data[index - 1], index - 1);
                    }
                }
            }
            plus.reverse(0, plus.size() - 1);
        }

    }

    static class SequenceUtils {
        public static void swap(int[] data, int i, int j) {
            int tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

        public static void reverse(int[] data, int l, int r) {
            while (l < r) {
                swap(data, l, r);
                l++;
                r--;
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

    static class FastOutput implements AutoCloseable, Closeable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput println(long c) {
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

    static interface SimplifiedDeque<T> extends SimplifiedStack<T> {
        T peekFirst();

        T removeFirst();

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

    static class IntegerList implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public int[] getData() {
            return data;
        }

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

        public void reverse(int l, int r) {
            SequenceUtils.reverse(data, l, r);
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

        public int get(int i) {
            checkRange(i);
            return data[i];
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

        public void expandWith(int x, int len) {
            ensureSpace(len);
            while (size < len) {
                data[size++] = x;
            }
        }

        public int tail() {
            checkRange(0);
            return data[size - 1];
        }

        public void set(int i, int x) {
            checkRange(i);
            data[i] = x;
        }

        public int pop() {
            return data[--size];
        }

        public int size() {
            return size;
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public boolean isEmpty() {
            return size == 0;
        }

        public void clear() {
            size = 0;
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

    static class Node {
        int type;
        int index;
        int lcpWithNext;

    }

    static class IntegerRMQ {
        public static final int NIL = Integer.MIN_VALUE;
        int[] data;
        int[] vals;
        IntegerComparator comp;
        int n;

        private int left(int i) {
            return i << 1;
        }

        private int right(int i) {
            return (i << 1) | 1;
        }

        public IntegerRMQ(int[] vals, IntegerComparator comp) {
            this.comp = comp;
            n = vals.length;
            n = 1 << CachedLog2.ceilLog(n);
            this.vals = vals;
            data = new int[2 * n];
            build(vals, 0, n - 1, 1);
        }

        private int merge(int a, int b) {
            if (a == NIL || b == NIL) {
                return a == NIL ? b : a;
            }
            return comp.compare(vals[a], vals[b]) < 0 ? a : b;
        }

        private void build(int[] vals, int l, int r, int i) {
            if (l < r) {
                int m = (l + r) >> 1;
                build(vals, l, m, left(i));
                build(vals, m + 1, r, right(i));
                data[i] = merge(data[left(i)], data[right(i)]);
            } else {
                data[i] = l >= vals.length ? NIL : l;
            }
        }

        public int query(int l, int r) {
            return query(l, r, 0, n - 1, 1);
        }

        private int query(int ll, int rr, int l, int r, int i) {
            if (ll > r || l > rr) {
                return NIL;
            }
            if (ll <= l && r <= rr) {
                return data[i];
            }
            int m = (l + r) >> 1;
            return merge(query(ll, rr, l, m, left(i)),
                    query(ll, rr, m + 1, r, right(i)));
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

        public T peekFirst() {
            return data[l];
        }

        public T removeFirst() {
            return data[l++];
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

    static class MultiWayIntegerDeque {
        private int[] values;
        private int[] next;
        private int[] prev;
        private int[] heads;
        private int[] tails;
        private int alloc;
        private int queueNum;

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
            prev = Arrays.copyOf(prev, newSize);
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
            Arrays.fill(heads, 0, queueNum, 0);
            Arrays.fill(tails, 0, queueNum, 0);
        }

        public boolean isEmpty(int qId) {
            return heads[qId] == 0;
        }

        public void expandQueueNum(int qNum) {
            if (qNum <= queueNum) {
            } else if (qNum <= heads.length) {
                Arrays.fill(heads, queueNum, qNum, 0);
                Arrays.fill(tails, queueNum, qNum, 0);
            } else {
                Arrays.fill(heads, queueNum, heads.length, 0);
                Arrays.fill(tails, queueNum, heads.length, 0);
                heads = Arrays.copyOf(heads, qNum);
                tails = Arrays.copyOf(tails, qNum);
            }
            queueNum = qNum;
        }

        public MultiWayIntegerDeque(int qNum, int totalCapacity) {
            values = new int[totalCapacity + 1];
            next = new int[totalCapacity + 1];
            prev = new int[totalCapacity + 1];
            heads = new int[qNum];
            tails = new int[qNum];
            queueNum = qNum;
        }

        public void addLast(int qId, int x) {
            alloc();
            values[alloc] = x;

            if (heads[qId] == 0) {
                heads[qId] = tails[qId] = alloc;
                return;
            }
            next[tails[qId]] = alloc;
            prev[alloc] = tails[qId];
            tails[qId] = alloc;
        }

        public void addFirst(int qId, int x) {
            alloc();
            values[alloc] = x;

            if (heads[qId] == 0) {
                heads[qId] = tails[qId] = alloc;
                return;
            }
            next[alloc] = heads[qId];
            prev[heads[qId]] = alloc;
            heads[qId] = alloc;
        }

        public int removeFirst(int qId) {
            int ans = values[heads[qId]];
            if (heads[qId] == tails[qId]) {
                heads[qId] = tails[qId] = 0;
            } else {
                heads[qId] = next[heads[qId]];
                prev[tails[qId]] = 0;
            }
            return ans;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < queueNum; i++) {
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

    static interface SimplifiedStack<T> extends Iterable<T> {
        boolean isEmpty();

        T peekLast();

        T removeLast();

    }
}