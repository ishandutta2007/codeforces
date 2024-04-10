import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
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
            DPortals solver = new DPortals();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DPortals {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            int k = in.readInt();
            int[] inEdge = new int[n];
            for (int i = 0; i < n; i++) {
                inEdge[i] = i;
            }
            Castle[] castles = new Castle[n];
            for (int i = 0; i < n; i++) {
                castles[i] = new Castle(in.readInt(), in.readInt(), in.readInt());
            }
            for (int i = 0; i < m; i++) {
                int u = in.readInt() - 1;
                int v = in.readInt() - 1;
                inEdge[v] = Math.max(inEdge[v], u);
            }
            List<DirectedEdge>[] g = Graph.createDirectedGraph(n);
            for (int i = 0; i < n; i++) {
                Graph.addEdge(g, inEdge[i], i);
            }
            int[] total = new int[n];
            int cur = k;
            for (int i = 0; i < n; i++) {
                total[i] = cur;
                if (cur < castles[i].a) {
                    out.println(-1);
                    return;
                }
                cur += castles[i].b;
            }
            int limit = 5000;
            Loop<long[]> loop = new Loop<>(new long[limit + 1], new long[limit + 1]);
            SequenceUtils.deepFill(loop.get(), -(long) 1e18);
            loop.get()[0] = 0;
            for (int i = 1; i <= n; i++) {
                long[] last = loop.get();
                for (int j = 0; j <= limit; j++) {
                    if (j > total[i - 1] - castles[i - 1].a) {
                        last[j] = -(long) 1e18;
                    }
                }
                for (DirectedEdge e : g[i - 1]) {
                    int to = e.to;
                    last = loop.get();
                    long[] next = loop.turn();
                    for (int j = 0; j <= limit; j++) {
                        next[j] = last[j];
                        if (j > 0) {
                            next[j] = Math.max(next[j], last[j - 1] + castles[to].c);
                        }
                    }
                }
            }
            long[] last = loop.get();
            for (int j = 0; j <= limit; j++) {
                if (j > cur) {
                    last[j] = -(long) 1e18;
                }
            }

            long ans = 0;
            for (int i = 0; i <= limit; i++) {
                ans = Math.max(ans, last[i]);
            }

            out.println(ans);
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

    static class SequenceUtils {
        public static void deepFill(Object array, long val) {
            if (!array.getClass().isArray()) {
                throw new IllegalArgumentException();
            }
            if (array instanceof long[]) {
                long[] longArray = (long[]) array;
                Arrays.fill(longArray, val);
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

        public FastOutput append(int c) {
            cache.append(c);
            return this;
        }

        public FastOutput append(long c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(int c) {
            return append(c).println();
        }

        public FastOutput println(long c) {
            return append(c).println();
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

    static class Loop<T> {
        T[] data;
        int pos;

        public Loop(T... data) {
            this.data = data;
        }

        public T turn(int i) {
            pos += i;
            return get(0);
        }

        public T turn() {
            return turn(1);
        }

        public T get(int i) {
            return data[(pos + i) % data.length];
        }

        public T get() {
            return get(0);
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

    static class Graph {
        public static void addEdge(List<DirectedEdge>[] g, int s, int t) {
            g[s].add(new DirectedEdge(t));
        }

        public static List<DirectedEdge>[] createDirectedGraph(int n) {
            List<DirectedEdge>[] ans = new List[n];
            for (int i = 0; i < n; i++) {
                ans[i] = new ArrayList<>();
            }
            return ans;
        }

    }

    static class Castle {
        int a;
        int b;
        int c;

        public Castle(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

    }
}