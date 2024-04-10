import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.List;
import java.util.stream.Stream;
import java.io.Closeable;
import java.io.Writer;
import java.util.Comparator;
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
            F1FallingSandEasyVersion solver = new F1FallingSandEasyVersion();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class F1FallingSandEasyVersion {
        DirectedTarjanSCC scc;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int m = in.ri();
            char[][] mat = new char[n][m];
            int[][] id = new int[n][m];
            SequenceUtils.deepFill(id, -1);
            int idAlloc = 0;
            int[] col = new int[m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    mat[i][j] = in.rc();
                    if (mat[i][j] == '#') {
                        id[i][j] = idAlloc++;
                        col[j]++;
                    }
                }
            }

            int[] a = in.ri(m);
            int sum = Arrays.stream(a).sum();
            if (sum == 0) {
                out.println(0);
                return;
            }
            int[][] next = new int[n + 1][m];
            for (int i = 0; i < m; i++) {
                next[n][i] = n;
                for (int j = n - 1; j >= 0; j--) {
                    next[j][i] = next[j + 1][i];
                    if (id[j][i] != -1) {
                        next[j][i] = j;
                    }
                }
            }
            List<DirectedEdge>[] g = Graph.createGraph(idAlloc);
            int[][] dirs = new int[][]{
                    {0, 1},
                    {0, -1},
                    {1, 0},
                    {-1, 0}
            };
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (id[i][j] == -1) {
                        continue;
                    }
                    for (int[] d : dirs) {
                        int ni = i + d[0];
                        int nj = j + d[1];
                        if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
                            continue;
                        }
                        if (id[ni][nj] == -1) {
                            continue;
                        }
                        Graph.addEdge(g, id[i][j], id[ni][nj]);
                    }
                }
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (id[j][i] == -1) {
                        continue;
                    }
                    for (int t = i - 1; t <= i + 1; t++) {
                        if (t < 0 || t >= m) {
                            continue;
                        }
                        if (next[j + 1][t] < n) {
                            Graph.addEdge(g, id[j][i], id[next[j + 1][t]][t]);
                        }
                    }
                }
            }

            scc = new DirectedTarjanSCC(idAlloc);
            scc.init(g);
            int[][] left = new int[n][m];
            int[][] right = new int[n][m];
            IntegerArrayList cand = new IntegerArrayList(n);
            for (int i = 0; i < m; i++) {
                int cnt = 0;
                for (int j = 0; j < n; j++) {
                    if (id[j][i] == -1) {
                        continue;
                    }
                    cand.clear();
                    int l = j;
                    int r = j;
                    cand.add(l);
                    while (r < n && next[r + 1][i] < n && scc.set[id[next[r + 1][i]][i]] == scc.set[id[j][i]]) {
                        r = next[r + 1][i];
                        cand.add(r);
                    }

                    j = r;
                    int L = col[i] - cnt >= a[i] ? i : i + 1;
                    if (L == i && i - 1 >= 0 && next[l][i - 1] < n) {
                        L = left[next[l][i - 1]][i - 1];
                    } else {
                        while (L - 1 >= 0 && a[L - 1] == 0) {
                            L--;
                        }
                    }
                    for (int k = 0; k < cand.size(); k++) {
                        left[cand.get(k)][i] = L;
                    }

                    cnt += cand.size();
                }
            }

            for (int i = m - 1; i >= 0; i--) {
                int cnt = 0;
                for (int j = 0; j < n; j++) {
                    if (id[j][i] == -1) {
                        continue;
                    }
                    cand.clear();
                    int l = j;
                    int r = j;
                    cand.add(l);
                    while (r < n && next[r + 1][i] < n && scc.set[id[next[r + 1][i]][i]] == scc.set[id[j][i]]) {
                        r = next[r + 1][i];
                        cand.add(r);
                    }
                    j = r;
                    int R = col[i] - cnt >= a[i] ? i : i - 1;
                    if (R == i && i + 1 < m && next[l][i + 1] < n) {
                        R = right[next[l][i + 1]][i + 1];
                    } else {
                        while (R + 1 < m && a[R + 1] == 0) {
                            R++;
                        }
                    }
                    for (int k = 0; k < cand.size(); k++) {
                        right[cand.get(k)][i] = R;
                    }


                    cnt += cand.size();
                }
            }

            List<int[]> intervals = new ArrayList<>(m);
            for (int i = 0; i < m; i++) {
                int top = next[0][i];
                if (top >= n) {
                    continue;
                }
                intervals.add(new int[]{left[top][i], right[top][i]});
            }

            intervals.sort(Comparator.comparingInt(x -> x[0]));
            int curMax = 0;
            int curNext = 0;
            int head = 0;
            while (head < intervals.size() && intervals.get(head)[0] <= curNext) {
                curMax = Math.max(curMax, intervals.get(head)[1]);
                head++;
            }
            int ans = 0;
            while (curNext < m) {
                ans++;
                curNext = curMax + 1;
                while (head < intervals.size() && intervals.get(head)[0] <= curNext) {
                    curMax = Math.max(curMax, intervals.get(head)[1]);
                    head++;
                }
            }

            out.println(ans);
        }

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

    static interface IntegerStack {
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

        public void populate(int[] data) {
            for (int i = 0; i < data.length; i++) {
                data[i] = readInt();
            }
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

        public int[] ri(int n) {
            int[] ans = new int[n];
            populate(ans);
            return ans;
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

        public char rc() {
            return readChar();
        }

        public char readChar() {
            skipBlank();
            char c = (char) next;
            next = read();
            return c;
        }

    }

    static interface IntegerDeque extends IntegerStack {
    }

    static class IntegerArrayList implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public IntegerArrayList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public IntegerArrayList(int[] data) {
            this(0);
            addAll(data);
        }

        public IntegerArrayList(IntegerArrayList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public IntegerArrayList() {
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
                throw new ArrayIndexOutOfBoundsException("Access [" + i + "]");
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

        public void addAll(int[] x) {
            addAll(x, 0, x.length);
        }

        public void addAll(int[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(IntegerArrayList list) {
            addAll(list.data, 0, list.size);
        }

        public int size() {
            return size;
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public void clear() {
            size = 0;
        }

        public String toString() {
            return Arrays.toString(toArray());
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof IntegerArrayList)) {
                return false;
            }
            IntegerArrayList other = (IntegerArrayList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Integer.hashCode(data[i]);
            }
            return h;
        }

        public IntegerArrayList clone() {
            IntegerArrayList ans = new IntegerArrayList();
            ans.addAll(this);
            return ans;
        }

    }

    static interface IntegerIterator {
        boolean hasNext();

        int next();

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

    static class IntegerDequeImpl implements IntegerDeque {
        private int[] data;
        private int bpos;
        private int epos;
        private static final int[] EMPTY = new int[0];
        private int n;

        public IntegerDequeImpl(int cap) {
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

        public IntegerIterator iterator() {
            return new IntegerIterator() {
                int index = bpos;


                public boolean hasNext() {
                    return index != epos;
                }


                public int next() {
                    int ans = data[index];
                    index = IntegerDequeImpl.this.next(index);
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
            for (IntegerIterator iterator = iterator(); iterator.hasNext(); ) {
                builder.append(iterator.next()).append(' ');
            }
            return builder.toString();
        }

    }

    static class Graph {
        public static DirectedEdge addEdge(List<DirectedEdge>[] g, int s, int t) {
            DirectedEdge e = new DirectedEdge(t);
            g[s].add(e);
            return e;
        }

        public static List[] createGraph(int n) {
            return IntStream.range(0, n).mapToObj(i -> new ArrayList<>()).toArray(i -> new List[i]);
        }

    }

    static class DirectedEdge {
        public int to;

        public DirectedEdge(int to) {
            this.to = to;
        }

        public String toString() {
            return "->" + to;
        }

    }

    static class DirectedTarjanSCC {
        private List<? extends DirectedEdge>[] g;
        public int[] low;
        public int[] dfn;
        public int[] set;
        private IntegerDequeImpl dq;
        private int order;
        private boolean[] instk;

        public DirectedTarjanSCC(int n) {
            low = new int[n];
            dfn = new int[n];
            set = new int[n];
            instk = new boolean[n];
            dq = new IntegerDequeImpl(n);
        }

        public void init(List<? extends DirectedEdge>[] g) {
            this.g = g;
            Arrays.fill(dfn, 0, g.length, -1);
            order = 0;
            for (int i = 0; i < g.length; i++) {
                if (dfn[i] != -1) {
                    continue;
                }
                dfs(i);
                assert dq.isEmpty();
            }
        }

        private void dfs(int root) {
            if (dfn[root] != -1) {
                return;
            }
            dfn[root] = low[root] = order++;
            instk[root] = true;
            dq.addLast(root);
            for (DirectedEdge e : g[root]) {
                dfs(e.to);
                if (instk[e.to]) {
                    low[root] = Math.min(low[root], low[e.to]);
                }
            }
            if (dfn[root] == low[root]) {
                while (true) {
                    int tail = dq.removeLast();
                    set[tail] = root;
                    instk[tail] = false;
                    if (tail == root) {
                        break;
                    }
                }
            }
        }

    }
}