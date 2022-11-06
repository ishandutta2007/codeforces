import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.function.BiFunction;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in Actual solution is at the top
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
            TaskD solver = new TaskD();
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                solver.solve(i, in, out);
            out.close();
        }
    }
    static class TaskD {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            Integer[] monster = new Integer[n];

            for (int i = 0; i < n; i++) {
                monster[i] = in.readInt();
            }
            SparseTable<Integer> st = new SparseTable<>(monster, n, (a, b) -> a > b ? a : b);
            int m = in.readInt();
            int[] s = new int[n + 1];
            for (int i = 0; i < m; i++) {
                int p = in.readInt();
                int live = in.readInt();
                s[live] = Math.max(s[live], p);
            }
            for (int i = n - 1; i >= 1; i--) {
                s[i] = Math.max(s[i], s[i + 1]);
            }

            if (st.query(0, n - 1) > s[1]) {
                out.println(-1);
                return;
            }

            int day = 0;
            int pos = 0;

            while (pos < n) {
                int l = pos;
                int r = n - 1;
                while (l < r) {
                    int mid = (l + r + 1) / 2;
                    if (st.query(pos, mid) > s[mid - pos + 1]) {
                        r = mid - 1;
                    } else {
                        l = mid;
                    }
                }

                day++;
                pos = l + 1;
            }

            out.println(day);
        }

    }
    static class SparseTable<T> {
        private Object[][] st;
        private BiFunction<T, T, T> merger;
        private DigitUtils.CachedLog2 log2;

        public SparseTable(Object[] data, int length, BiFunction<T, T, T> merger) {
            log2 = new DigitUtils.CachedLog2(length);
            int m = log2.floorLog(length);

            st = new Object[m + 1][length];
            this.merger = merger;
            for (int i = 0; i < length; i++) {
                st[0][i] = data[i];
            }
            for (int i = 0; i < m; i++) {
                int interval = 1 << i;
                for (int j = 0; j < length; j++) {
                    if (j + interval < length) {
                        st[i + 1][j] = merge((T) st[i][j], (T) st[i][j + interval]);
                    } else {
                        st[i + 1][j] = st[i][j];
                    }
                }
            }
        }

        private T merge(T a, T b) {
            return merger.apply(a, b);
        }

        public T query(int left, int right) {
            int queryLen = right - left + 1;
            int bit = log2.floorLog(queryLen);
            // x + 2^bit == right + 1
            // So x should be right + 1 - 2^bit - left=queryLen - 2^bit
            return merge((T) st[bit][left], (T) st[bit][right + 1 - (1 << bit)]);
        }

        public String toString() {
            return Arrays.toString(st[0]);
        }

    }
    static class DigitUtils {
        private DigitUtils() {}

        public static class Log2 {
            public int floorLog(int x) {
                return 31 - Integer.numberOfLeadingZeros(x);
            }

        }

        public static class CachedLog2 {
            private int[] cache;
            private DigitUtils.Log2 log2;

            public CachedLog2(int n) {
                cache = new int[n + 1];
                int b = 0;
                for (int i = 0; i <= n; i++) {
                    while ((1 << (b + 1)) <= i) {
                        b++;
                    }
                    cache[i] = b;
                }
            }

            public int floorLog(int x) {
                if (x >= cache.length) {
                    return log2.floorLog(x);
                }
                return cache[x];
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
}