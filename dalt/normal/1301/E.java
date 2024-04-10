import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Iterator;
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
            ENanosoft solver = new ENanosoft();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class ENanosoft {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            int q = in.readInt();
            char[][] mat = new char[n + 1][m + 1];
            int[][] rep = new int[n + 1][m + 1];
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    mat[i][j] = in.readChar();
                }
            }
            for (int i = n; i >= 1; i--) {
                for (int j = m; j >= 1; j--) {
                    if (i + 1 <= n && j + 1 <= m && mat[i][j] == mat[i + 1][j] &&
                            mat[i][j] == mat[i][j + 1] && mat[i][j] == mat[i + 1][j + 1]) {
                        rep[i][j] = 1 + rep[i + 1][j + 1];
                    } else {
                        rep[i][j] = 1;
                    }
                }
            }

            MultiWayStack<int[]> stack = new MultiWayStack<>(n + 1, n * m);
            int[][] size = new int[n + 1][m + 1];
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    int r = rep[i][j];
                    int x = i + r;
                    int y = j + r;
                    if (x > n || y > m) {
                        continue;
                    }
                    if (mat[i][j] == 'R' && mat[i][y] == 'G' &&
                            mat[x][j] == 'Y' && mat[x][y] == 'B' &&
                            rep[i][y] >= r && rep[x][j] >= r && rep[x][y] >= r) {
                        size[i][j] = r * 2;
                        stack.addLast(r * 2, SequenceUtils.wrapArray(i, j));
                    }
                }
            }

            Query[] qs = new Query[q];
            for (int i = 0; i < q; i++) {
                qs[i] = new Query();
                qs[i].x1 = in.readInt();
                qs[i].y1 = in.readInt();
                qs[i].x2 = in.readInt();
                qs[i].y2 = in.readInt();
            }

            int[][] ps = new int[n + 1][m + 1];
            for (int i = 1; i <= n; i++) {
                if (stack.isEmpty(i)) {
                    continue;
                }
                SequenceUtils.deepFill(ps, 0);
                while (!stack.isEmpty(i)) {
                    int[] xy = stack.removeLast(i);
                    ps[xy[0]][xy[1]] = 1;
                }
                presum(ps);
                for (Query query : qs) {
                    int x2 = query.x2 - i + 1;
                    int y2 = query.y2 - i + 1;
                    int cnt = rect(ps, query.x1, query.y1, x2, y2);
                    if (cnt > 0) {
                        query.ans = i;
                    }
                }
            }

            for (Query query : qs) {
                out.println(query.ans * query.ans);
            }
        }

        public void presum(int[][] ps) {
            int n = ps.length;
            int m = ps[0].length;
            for (int i = 0; i < n; i++) {
                for (int j = 1; j < m; j++) {
                    ps[i][j] += ps[i][j - 1];
                }
            }
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ps[i][j] += ps[i - 1][j];
                }
            }
        }

        public int rect(int[][] ps, int x1, int y1, int x2, int y2) {
            if (x1 > x2 || y1 > y2) {
                return 0;
            }
            return ps[x2][y2] - ps[x1 - 1][y2] - ps[x2][y1 - 1] + ps[x1 - 1][y1 - 1];
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

        public char readChar() {
            skipBlank();
            char c = (char) next;
            next = read();
            return c;
        }

    }

    static class Query {
        int x1;
        int y1;
        int x2;
        int y2;
        int ans;

    }

    static class MultiWayStack<T> {
        private Object[] values;
        private int[] next;
        private int[] heads;
        private int alloc;
        private int stackNum;

        public RevokeIterator<T> iterator(final int queue) {
            return new RevokeIterator<T>() {
                int ele = heads[queue];
                int pre = 0;


                public boolean hasNext() {
                    return ele != 0;
                }


                public T next() {
                    T ans = (T) values[ele];
                    pre = ele;
                    ele = next[ele];
                    return ans;
                }


                public void revoke() {
                    ele = pre;
                    pre = 0;
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

        public boolean isEmpty(int qId) {
            return heads[qId] == 0;
        }

        public MultiWayStack(int qNum, int totalCapacity) {
            values = new Object[totalCapacity + 1];
            next = new int[totalCapacity + 1];
            heads = new int[qNum];
            stackNum = qNum;
        }

        public void addLast(int qId, T x) {
            alloc();
            values[alloc] = x;
            next[alloc] = heads[qId];
            heads[qId] = alloc;
        }

        public T removeLast(int qId) {
            T ans = (T) values[heads[qId]];
            heads[qId] = next[heads[qId]];
            return ans;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < stackNum; i++) {
                builder.append(i).append(": ");
                for (Iterator iterator = iterator(i); iterator.hasNext(); ) {
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

    static interface RevokeIterator<E> extends Iterator<E> {
    }

    static class SequenceUtils {
        public static int[] wrapArray(int... x) {
            return x;
        }

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
}