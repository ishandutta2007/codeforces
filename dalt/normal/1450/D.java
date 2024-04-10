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
            DRatingCompression solver = new DRatingCompression();
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                solver.solve(i, in, out);
            out.close();
        }
    }

    static class DRatingCompression {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int[] a = new int[n];
            in.populate(a);
            List<Integer>[] indices = new List[n + 1];
            for (int i = 1; i <= n; i++) {
                indices[i] = new ArrayList<>();
            }
            for (int i = 0; i < n; i++) {
                indices[a[i]].add(i);
            }
            int l = 0;
            int r = n - 1;
            int inf = (int) 1e9;
            int[] atLeast = new int[n + 1];
            Arrays.fill(atLeast, inf);
            for (int i = 1; i <= n; i++) {
                int size = 0;
                int min = n;
                int max = -1;
                for (int j : indices[i]) {
                    if (j < l || j > r) {
                        continue;
                    }
                    size++;
                    min = Math.min(min, j);
                    max = Math.max(max, j);
                }
                if (size == 1 && min == l) {
                    l++;
                    atLeast[i] = 0;
                    continue;
                }
                if (size == 1 && max == r) {
                    r--;
                    atLeast[i] = 0;
                    continue;
                }
                if (size == 1) {
                    atLeast[i] = r - l + 1;
                    break;
                }
                if (size >= 2) {
                    l++;
                    r--;
                    atLeast[i] = r - l + 1;
                    break;
                }
                break;
            }
            int now = 0;
            boolean[] ok = new boolean[n + 1];
            for (int i = 1; i <= n; i++) {
                now = Math.max(now, atLeast[i]);
                if (now <= n - i + 1) {
                    ok[i] = true;
                }
            }
            ok[n] = true;
            for (int i = 1; i <= n; i++) {
                if (indices[i].isEmpty()) {
                    ok[n] = false;
                }
            }
            for (int i = n; i >= 1; i--) {
                out.append(ok[i] ? '1' : '0');
            }
            out.println();
        }

    }

    static class FastInput {
        private final InputStream is;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 13);
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

        public String next() {
            return readString();
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

        public String readString(StringBuilder builder) {
            skipBlank();

            while (next > 32) {
                builder.append((char) next);
                next = read();
            }

            return builder.toString();
        }

        public String readString() {
            defaultStringBuf.setLength(0);
            return readString(defaultStringBuf);
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private static final int THRESHOLD = 1 << 13;
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

        public FastOutput append(String c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println() {
            return append(System.lineSeparator());
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