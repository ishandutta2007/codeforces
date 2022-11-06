import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.util.stream.Stream;
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
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int m = in.ri();
            char[][] mat = new char[n][m];
            int[][] id = new int[n][m];
            SequenceUtils.deepFill(id, -1);
            int idAlloc = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    mat[i][j] = in.rc();
                    if (mat[i][j] == '#') {
                        id[i][j] = idAlloc++;
                    }
                }
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

            DirectedTarjanSCC scc = new DirectedTarjanSCC(idAlloc);
            scc.init(g);
            boolean[] indeg = new boolean[idAlloc];
            for (int i = 0; i < idAlloc; i++) {
                for (DirectedEdge e : g[i]) {
                    if (scc.set[i] == scc.set[e.to]) {
                        continue;
                    }
                    indeg[scc.set[e.to]] = true;
                }
            }
            int ans = 0;
            for (int i = 0; i < idAlloc; i++) {
                if (scc.set[i] != i) {
                    continue;
                }
                if (!indeg[i]) {
                    ans++;
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

    static interface IntegerIterator {
        boolean hasNext();

        int next();

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

    static interface IntegerStack {
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

    static interface IntegerDeque extends IntegerStack {
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
}