import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
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
            TaskF solver = new TaskF();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskF {
        int p;
        int M;

        public int idOfStation(int x) {
            return x - 1;
        }

        public int idOfGE(int x) {
            return p + x - 1;
        }

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            p = in.readInt();
            M = in.readInt();
            int m = in.readInt();

            TwoSatBeta ts = new TwoSatBeta(p + M + 1, (n + M + p + m));
            for (int i = 0; i < n; i++) {
                int a = in.readInt();
                int b = in.readInt();
                ts.atLeastOneIsTrue(ts.elementId(idOfStation(a)), ts.elementId(idOfStation(b)));
            }

            for (int i = 2; i <= M + 1; i++) {
                ts.deduce(ts.elementId(idOfGE(i)), ts.elementId(idOfGE(i - 1)));
            }

            for (int i = 1; i <= p; i++) {
                int l = in.readInt();
                int r = in.readInt();
                ts.deduce(ts.elementId(idOfStation(i)),
                        ts.elementId(idOfGE(l)));
                ts.deduce(ts.elementId(idOfStation(i)),
                        ts.negateElementId(idOfGE(r + 1)));
            }

            for (int i = 0; i < m; i++) {
                int a = in.readInt();
                int b = in.readInt();
                ts.atLeastOneIsFalse(ts.elementId(idOfStation(a)), ts.elementId(idOfStation(b)));
            }

            boolean solvable = ts.solve(true);
            if (!solvable) {
                out.println(-1);
                return;
            }
            int k = 0;
            int f = 0;
            for (int i = 1; i <= p; i++) {
                if (ts.valueOf(idOfStation(i))) {
                    k++;
                }
            }
            for (int i = 1; i <= M + 1; i++) {
                if (ts.valueOf(idOfGE(i))) {
                    f = i;
                }
            }
            out.append(k).append(' ').append(f).println();
            for (int i = 1; i <= p; i++) {
                if (ts.valueOf(idOfStation(i))) {
                    out.append(i).append(' ');
                }
            }
        }

    }

    static class MultiWayIntStack {
        private int[] values;
        private int[] next;
        private int[] heads;
        private int alloc;
        private int queueNum;

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
            queueNum = qNum;
        }

        public void addFirst(int qId, int x) {
            alloc();
            values[alloc] = x;
            next[alloc] = heads[qId];
            heads[qId] = alloc;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < queueNum; i++) {
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

    static class IntDequeBeta {
        private int[] data;
        private int bpos;
        private int epos;
        private static final int[] EMPTY = new int[0];
        private int n;

        public IntDequeBeta(int cap) {
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
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
                    index = IntDequeBeta.this.next(index);
                    return ans;
                }
            };
        }

        public int removeLast() {
            int ans = data[last(epos)];
            epos = last(epos);
            return ans;
        }

        public void addLast(int x) {
            ensureMore();
            data[epos] = x;
            epos = next(epos);
        }

        public void clear() {
            bpos = epos = 0;
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

    static interface IntIterator {
        boolean hasNext();

        int next();

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

        public FastOutput append(int c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(int c) {
            cache.append(c).append('\n');
            return this;
        }

        public FastOutput println() {
            cache.append('\n');
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

    static class TwoSatBeta {
        private MultiWayIntStack edges;
        private boolean[] values;
        private int[] sets;
        private int[] dfns;
        private int[] lows;
        private boolean[] instk;
        private IntDequeBeta deque;
        private int n;
        private int dfn = 0;

        public TwoSatBeta(int n, int m) {
            values = new boolean[n * 2];
            sets = new int[n * 2];
            edges = new MultiWayIntStack(n * 2, m * 2);
            dfns = new int[n * 2];
            lows = new int[n * 2];
            instk = new boolean[n * 2];
            deque = new IntDequeBeta(n * 2);
            this.n = n;
        }

        public boolean valueOf(int x) {
            return values[sets[elementId(x)]];
        }

        public boolean solve(boolean fetchValue) {
            Arrays.fill(values, false);
            Arrays.fill(dfns, 0);
            deque.clear();
            dfn = 0;

            for (int i = 0; i < sets.length; i++) {
                tarjan(i);
            }
            for (int i = 0; i < n; i++) {
                if (sets[elementId(i)] == sets[negateElementId(i)]) {
                    return false;
                }
            }

            if (!fetchValue) {
                return true;
            }

            Arrays.fill(dfns, 0);
            for (int i = 0; i < sets.length; i++) {
                assign(i);
            }
            return true;
        }

        private void assign(int root) {
            if (dfns[root] > 0) {
                return;
            }
            dfns[root] = 1;
            for (IntIterator iterator = edges.iterator(root); iterator.hasNext(); ) {
                int node = iterator.next();
                assign(node);
            }
            if (sets[root] == root) {
                values[root] = !values[sets[negate(root)]];
            }
        }

        private void tarjan(int root) {
            if (dfns[root] > 0) {
                return;
            }
            lows[root] = dfns[root] = ++dfn;
            instk[root] = true;
            deque.addLast(root);
            for (IntIterator iterator = edges.iterator(root); iterator.hasNext(); ) {
                int node = iterator.next();
                tarjan(node);
                if (instk[node] && lows[node] < lows[root]) {
                    lows[root] = lows[node];
                }
            }
            if (lows[root] == dfns[root]) {
                int last;
                do {
                    last = deque.removeLast();
                    sets[last] = root;
                    instk[last] = false;
                } while (last != root);
            }
        }

        public int elementId(int x) {
            return x << 1;
        }

        public int negateElementId(int x) {
            return (x << 1) | 1;
        }

        private int negate(int x) {
            return x ^ 1;
        }

        public void deduce(int a, int b) {
            edges.addFirst(a, b);
            edges.addFirst(negate(b), negate(a));
        }

        public void or(int a, int b) {
            deduce(negate(a), b);
        }

        public void atLeastOneIsFalse(int a, int b) {
            deduce(a, negate(b));
        }

        public void atLeastOneIsTrue(int a, int b) {
            or(a, b);
        }

    }
}