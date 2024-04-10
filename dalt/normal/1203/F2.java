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
            TaskF2 solver = new TaskF2();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskF2 {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int r = in.readInt();
            List<Project> pos = new ArrayList<>(n);
            List<Project> neg = new ArrayList<>(n);
            for (int i = 0; i < n; i++) {
                Project p = new Project();
                p.a = in.readInt();
                p.b = in.readInt();
                if (p.b < 0) {
                    neg.add(p);
                } else {
                    pos.add(p);
                }
            }

            pos.sort((a, b) -> a.a - b.a);
            int ans = 0;
            for (Project p : pos) {
                if (p.a > r) {
                    break;
                }
                ans++;
                r += p.b;
            }

            neg.sort((a, b) -> -(a.a + a.b - b.a - b.b));
            int m = neg
                    .size();
            int[][] dp = new int[m + 1][m + 1];
            SequenceUtils.deepFill(dp, -1);
            dp[0][0] = r;
            for (int i = 1; i <= m; i++) {
                Project p = neg.get(i - 1);
                for (int j = 0; j <= m; j++) {
                    dp[i][j] = dp[i - 1][j];
                    if (j > 0 && dp[i - 1][j - 1] >= p.a) {
                        dp[i][j] = Math.max(dp[i][j],
                                dp[i - 1][j - 1] + p.b);
                    }
                }
            }

            int max = 0;
            for (int i = 0; i <= m; i++) {
                if (dp[m][i] >= 0) {
                    max = i;
                }
            }

            out.println(ans + max);
        }

    }

    static class Project {
        int a;
        int b;

        public String toString() {
            return String.format("(%d,%d)", a, b);
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