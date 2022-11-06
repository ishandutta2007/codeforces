import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.TreeSet;
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
            TaskG solver = new TaskG();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskG {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int k = in.readInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.readInt();
            }
            MultiWayIntStack stack = new MultiWayIntStack(n, n);
            IntDeque deque = new IntDequeImpl(n);
            for (int i = n - 1; i >= 0; i--) {
                while (!deque.isEmpty() && a[deque.peekFirst()] <= a[i]) {
                    deque.removeFirst();
                }
                if (deque.isEmpty()) {
                } else {
                    stack.addLast(deque.peekFirst(), i);
                }
                deque.addFirst(i);
            }
            DSU[] dsus = new DSU[n];
            for (int i = 0; i < n; i++) {
                dsus[i] = new DSU();
                dsus[i].belong = i;
            }
            IntLeftistTree[] trees = new IntLeftistTree[n];
            for (int i = 0; i < n; i++) {
                trees[i] = new IntLeftistTree(1, i);
            }
            TreeSet<IntLeftistTree> set = new TreeSet<>((x, y) ->
                    x.key == y.key ? x.index - y.index : x.key - y.key);
            for (int i = 0; i < n; i++) {
                IntLeftistTree tree = IntLeftistTree.NIL;
                for (IntIterator iterator = stack.iterator(i); iterator.hasNext(); ) {
                    int next = iterator.next();
                    set.remove(trees[next]);
                    tree = IntLeftistTree.merge(tree, trees[next]);
                    DSU.merge(dsus[i], dsus[next]);
                }
                tree.modify(1);
                tree = IntLeftistTree.merge(tree, trees[i]);
                set.add(tree);
                trees[i] = tree;
                dsus[i].find().belong = i;

                if (i < k - 1) {
                    continue;
                }

                while (set.last().index <= i - k) {
                    IntLeftistTree last = set.pollLast();
                    last = IntLeftistTree.pop(last);
                    trees[dsus[last.index].find().belong] = last;
                    if (!last.isEmpty()) {
                        set.add(last);
                    }
                }

                out.println(set.last().peek());
            }
        }

    }

    static class IntLeftistTree {
        public static final IntLeftistTree NIL = new IntLeftistTree(0, 0);
        IntLeftistTree left = NIL;
        IntLeftistTree right = NIL;
        int dist;
        int key;
        int dirty;
        int index;

        static {
            NIL.left = NIL;
            NIL.right = NIL;
            NIL.dist = -1;
        }

        public void modify(int x) {
            if (this == NIL) {
                return;
            }
            key += x;
            dirty += x;
        }

        public void pushDown() {
            if (dirty != 0) {
                left.modify(dirty);
                right.modify(dirty);
                dirty = 0;
            }
        }

        public IntLeftistTree(int key, int index) {
            this.key = key;
            this.index = index;
        }

        public static IntLeftistTree merge(IntLeftistTree a, IntLeftistTree b) {
            if (a == NIL) {
                return b;
            } else if (b == NIL) {
                return a;
            }

            if (a.key < b.key) {
                IntLeftistTree tmp = a;
                a = b;
                b = tmp;
            }
            a.pushDown();
            a.right = merge(a.right, b);
            if (a.left.dist < a.right.dist) {
                IntLeftistTree tmp = a.left;
                a.left = a.right;
                a.right = tmp;
            }
            a.dist = a.right.dist + 1;
            return a;
        }

        public boolean isEmpty() {
            return this == NIL;
        }

        public int peek() {
            return key;
        }

        public static IntLeftistTree pop(IntLeftistTree root) {
            root.pushDown();
            IntLeftistTree ans = merge(root.left, root.right);
            root.left = root.right = NIL;
            return ans;
        }

        private void toStringDfs(StringBuilder builder) {
            if (this == NIL) {
                return;
            }
            builder.append(key).append(' ');
            left.toStringDfs(builder);
            right.toStringDfs(builder);
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            toStringDfs(builder);
            return builder.toString();
        }

    }

    static class DSU {
        DSU p = this;
        int rank;
        int belong;

        public DSU find() {
            return p.p == p ? p : (p = p.find());
        }

        public static void merge(DSU a, DSU b) {
            a = a.find();
            b = b.find();
            if (a == b) {
                return;
            }
            if (a.rank == b.rank) {
                a.rank++;
            }
            if (a.rank > b.rank) {
                b.p = a;
            } else {
                a.p = b;
            }
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

    static class IntDequeImpl implements IntDeque {
        private int[] data;
        private int bpos;
        private int epos;
        private int n;

        public IntDequeImpl(int cap) {
            cap++;
            data = new int[cap];
            bpos = 0;
            epos = 0;
            n = cap;
        }

        private void expandSpace(int len) {
            while (n < len) {
                n = Math.max(n + 10, n * 2);
            }
            int[] newData = new int[n];
            if (bpos <= epos) {
                if (bpos < epos) {
                    System.arraycopy(data, bpos, newData, 0, epos - bpos);
                }
            } else {
                System.arraycopy(data, bpos, newData, 0, data.length - bpos);
                System.arraycopy(data, 0, newData, data.length - bpos, epos);
            }
            epos = size();
            bpos = 0;
            data = newData;
        }

        public IntIterator iterator() {
            return new IntIterator() {
                int index = bpos;


                public boolean hasNext() {
                    return index != epos;
                }


                public int next() {
                    int ans = data[index];
                    index = IntDequeImpl.this.next(index);
                    return ans;
                }
            };
        }

        public int removeFirst() {
            int ans = data[bpos];
            bpos = next(bpos);
            return ans;
        }

        public void addFirst(int x) {
            ensureMore();
            bpos = last(bpos);
            data[bpos] = x;
        }

        public int peekFirst() {
            return data[bpos];
        }

        private int last(int x) {
            return (x == 0 ? n : x) - 1;
        }

        private int next(int x) {
            return x + 1 >= n ? 0 : x + 1;
        }

        private void ensureMore() {
            if (next(epos) == bpos) {
                expandSpace(n + 1);
            }
        }

        public int size() {
            int ans = epos - bpos;
            if (ans < 0) {
                ans += data.length;
            }
            return ans;
        }

        public boolean isEmpty() {
            return bpos == epos;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (IntIterator iterator = iterator(); iterator.hasNext(); ) {
                builder.append(iterator.next()).append(' ');
            }
            return builder.toString();
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

    static interface IntDeque extends IntStack {
        void addFirst(int x);

        int removeFirst();

        int peekFirst();

    }

    static interface IntStack {
        boolean isEmpty();

    }

    static interface IntIterator {
        boolean hasNext();

        int next();

    }

    static class MultiWayIntStack {
        private int[] values;
        private int[] next;
        private int[] heads;
        private int alloc;
        private int stackNum;

        public IntIterator iterator(final int queue) {
            return new IntIterator() {
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

        public MultiWayIntStack(int qNum, int totalCapacity) {
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
                builder.append(i).append(": ");
                for (IntIterator iterator = iterator(i); iterator.hasNext(); ) {
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
}