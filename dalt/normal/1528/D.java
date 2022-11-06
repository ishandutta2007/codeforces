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
            DItsABirdNoItsAPlaneNoItsAaParsa solver = new DItsABirdNoItsAPlaneNoItsAaParsa();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class DItsABirdNoItsAPlaneNoItsAaParsa {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int m = in.ri();
            int[][] mat = new int[n][n];
            SequenceUtils.deepFill(mat, -1);
            for (int i = 0; i < m; i++) {
                int a = in.ri();
                int b = in.ri();
                int c = in.ri();
                mat[a][b] = c;
            }

            int[][] dists = new int[n][n];
            int inf = (int) (1e9 + 1e6);
            int[] dist = new int[n];
            int[] dirty = new int[n];
            boolean[] handled = new boolean[n];
            for (int u = 0; u < n; u++) {
                Arrays.fill(dist, inf);
                Arrays.fill(dirty, inf);
                dist[u] = 0;
                Arrays.fill(handled, false);
                for (int round = 0; round < n; round++) {
                    int head = -1;
                    for (int i = 0; i < n; i++) {
                        if (!handled[i] && (head == -1 || dist[head] > dist[i])) {
                            head = i;
                        }
                    }
                    handled[head] = true;
                    for (int i = 0, offset = dist[head] % n; i < n; i++, offset = offset + 1 == n ? 0 : offset + 1) {
                        if (mat[head][i] == -1) {
                            continue;
                        }
                        //start at
                        dirty[offset] = Math.min(dirty[offset], dist[head] + mat[head][i] - offset);
                        dirty[0] = Math.min(dirty[0], dist[head] + n - offset + mat[head][i]);
                    }

                    for (int i = 0; i < n; i++) {
                        if (i > 0) {
                            dirty[i] = Math.min(dirty[i], dirty[i - 1]);
                        }
                        dist[i] = Math.min(dist[i], dirty[i] + i);
                    }
                }

                dists[u] = dist.clone();
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    out.append(dists[i][j]).append(' ');
                }
                out.println();
            }
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
}