import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.util.Collection;
import java.io.IOException;
import java.util.stream.Collectors;
import java.io.UncheckedIOException;
import java.util.List;
import java.util.stream.Stream;
import java.io.Closeable;
import java.io.Writer;
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
            DUsefulEdges solver = new DUsefulEdges();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DUsefulEdges {
        long inf = (long) 1e18;
        long[][] dist;
        int[][] edges;
        int[] largest;
        int n;
        int to;

        public void updateLargest(int a) {
            int largestIndex = -1;
            for (int b = 0; b < n; b++) {
                if (edges[a][b] == -1) {
                    continue;
                }
                if (largestIndex == -1 || edges[a][largestIndex] + dist[largestIndex][to] > edges[a][b] + dist[b][to]) {
                    largestIndex = b;
                }
            }
            largest[a] = largestIndex;
        }

        public void solve(int testNumber, FastInput in, FastOutput out) {
            n = in.ri();
            int m = in.ri();
            dist = new long[n][n];
            SequenceUtils.deepFill(dist, inf);
            for (int i = 0; i < n; i++) {
                dist[i][i] = 0;
            }
            edges = new int[n][n];
            SequenceUtils.deepFill(edges, -1);
            List<int[]> allEdges = new ArrayList<>(m);
            for (int i = 0; i < m; i++) {
                int u = in.ri() - 1;
                int v = in.ri() - 1;
                int d = in.ri();
                edges[u][v] = d;
                edges[v][u] = d;
                dist[u][v] = d;
                dist[v][u] = d;
                allEdges.add(new int[]{v, u});
            }

            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }

            int q = in.ri();
            List<int[]> qs = new ArrayList<>(q);
            for (int i = 0; i < q; i++) {
                int u = in.ri() - 1;
                int v = in.ri() - 1;
                int l = in.ri();
                qs.add(new int[]{u, v, l});
            }
            Map<Integer, List<int[]>> groupBy = qs.stream().collect(Collectors.groupingBy(x -> x[1]));
            largest = new int[n];
            for (List<int[]> list : groupBy.values()) {
                to = list.get(0)[1];
                for (int a = 0; a < n; a++) {
                    updateLargest(a);
                }

                for (int[] query : list) {
                    int u = query[0];
                    int l = query[2];
                    for (int a = 0; a < n; a++) {
                        while (largest[a] != -1 && dist[u][a] + edges[a][largest[a]] + dist[largest[a]][to] <= l) {
                            edges[a][largest[a]] = -1;
                            updateLargest(a);
                        }
                    }
                }
            }

            int ans = 0;
            for (int[] e : allEdges) {
                int u = e[0];
                int v = e[1];
                if (edges[u][v] == -1 || edges[v][u] == -1) {
                    ans++;
                }
            }
            out.println(ans);
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
}