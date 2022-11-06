import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Iterator;
import java.io.IOException;
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
            FNumberOfComponents solver = new FNumberOfComponents();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FNumberOfComponents {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            int q = in.readInt();
            int[][] mat = new int[n + 1][m + 1];
            int[][] times = new int[n + 1][m + 1];

            MultiWayStack<Event> events = new MultiWayStack((int) 2e6 + 1, n * m + q);
            for (int i = 1; i <= q; i++) {
                int x = in.readInt();
                int y = in.readInt();
                int c = in.readInt();
                if (mat[x][y] == c) {
                    continue;
                }
                events.addLast(mat[x][y], new Event(x, y, times[x][y], i));
                mat[x][y] = c;
                times[x][y] = i;
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    events.addLast(mat[i][j], new Event(i, j, times[i][j], q + 1));
                }
            }
            int[] ans = new int[q + 2];
            Node[][] nodes = new Node[n + 1][m + 1];
            List<Event> list = new ArrayList<>(q);
            int[][] dirs = new int[][]{
                    {1, 0},
                    {-1, 0},
                    {0, 1},
                    {0, -1}
            };
            for (int i = 0; i < events.numberOfQueue(); i++) {
                if (events.isEmpty(i)) {
                    continue;
                }
                fill(nodes);
                list.clear();

                while (!events.isEmpty(i)) {
                    list.add(events.removeLast(i));
                }
                list.sort((a, b) -> a.add - b.add);
                int cc = 0;
                for (Event event : list) {
                    int o = cc;
                    int x = event.x;
                    int y = event.y;
                    nodes[x][y] = new Node();
                    cc++;
                    for (int[] dir : dirs) {
                        int nx = x + dir[0];
                        int ny = y + dir[1];
                        if (nx < 1 || nx > n || ny < 1 || ny > m) {
                            continue;
                        }
                        if (nodes[nx][ny] == null) {
                            continue;
                        }
                        if (nodes[nx][ny].find() == nodes[x][y].find()) {
                            continue;
                        }
                        Node.merge(nodes[nx][ny], nodes[x][y]);
                        cc--;
                    }
                    ans[event.add] += cc - o;
                }

                fill(nodes);
                list.sort((a, b) -> -(a.die - b.die));
                cc = 0;
                for (Event event : list) {
                    int o = cc;
                    int x = event.x;
                    int y = event.y;
                    nodes[x][y] = new Node();
                    cc++;
                    for (int[] dir : dirs) {
                        int nx = x + dir[0];
                        int ny = y + dir[1];
                        if (nx < 1 || nx > n || ny < 1 || ny > m) {
                            continue;
                        }
                        if (nodes[nx][ny] == null) {
                            continue;
                        }
                        if (nodes[nx][ny].find() == nodes[x][y].find()) {
                            continue;
                        }
                        Node.merge(nodes[nx][ny], nodes[x][y]);
                        cc--;
                    }
                    ans[event.die] += -(cc - o);
                }
            }

            for (int i = 1; i <= q; i++) {
                ans[i] += ans[i - 1];
                out.println(ans[i]);
            }
        }

        public void fill(Node[][] nodes) {
            for (Node[] x : nodes) {
                Arrays.fill(x, null);
            }
        }

    }

    static class Event {
        int x;
        int y;
        int add;
        int die;

        public Event(int x, int y, int add, int die) {
            this.x = x;
            this.y = y;
            this.add = add;
            this.die = die;
        }

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

        public int numberOfQueue() {
            return stackNum;
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

    static class Node {
        Node p = this;
        int rank = 0;

        public Node find() {
            return p.p == p ? p : (p = p.find());
        }

        public static void merge(Node a, Node b) {
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