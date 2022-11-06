import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Collection;
import java.io.IOException;
import java.util.Deque;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author daltao
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "daltao", 1 << 27);
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
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskD {
        int n;
        Segment seg;
        int[] a;
        int[] dp;
        int[] next;
        int[] half;

        public int dp(int i) {
            i %= n;
            if (dp[i] == -1) {
                if (next[i] != -1 && seg.query(i + 1, next[i], 0, 2 * n) * 2 >= a[i]) {
                    int ans = dp(next[i]);
                    if (ans == -1) {
                        dp[i] = -1;
                    } else {
                        dp[i] = ans + next[i] - i;
                    }
                    return dp[i];
                }

                int l = i + 1;
                int r = 2 * n;
                while (l < r) {
                    int m = (l + r) >> 1;
                    int v = seg.query(i + 1, m, 0, 2 * n);
                    if (v * 2 < a[i]) {
                        r = m;
                    } else {
                        l = m + 1;
                    }
                }
                if (next[i] != -1 && next[i] <= l) {
                    int ans = dp(next[i]);
                    if (ans == -1) {
                        dp[i] = -1;
                    } else {
                        dp[i] = ans + next[i] - i;
                    }
                } else if (l == 2 * n) {
                    dp[i] = -1;
                } else {
                    dp[i] = l - i;
                }
            }
            return dp[i];
        }

        public void solve(int testNumber, FastInput in, FastOutput out) {
            n = in.readInt();
            a = new int[2 * n + 1];
            for (int i = 0; i < n; i++) {
                a[n + i] = a[i] = in.readInt();
            }

            seg = new Segment(0, 2 * n, a);
            dp = new int[n];
            Arrays.fill(dp, -1);

            next = new int[n];
            Deque<Integer> minQue = new ArrayDeque<>(n * 2);
            for (int i = 2 * n - 1; i >= n; i--) {
                while (!minQue.isEmpty() && a[minQue.peekFirst()] <= a[i]) {
                    minQue.removeFirst();
                }
                minQue.addFirst(i);
            }
            for (int i = n - 1; i >= 0; i--) {
                while (!minQue.isEmpty() && a[minQue.peekFirst()] <= a[i]) {
                    minQue.removeFirst();
                }
                if (minQue.isEmpty()) {
                    next[i] = -1;
                } else {
                    next[i] = minQue.peekFirst();
                }
                minQue.addFirst(i);
            }

            half = new int[n];
            int last = 2 * n - 1;
            for (int i = n - 1; i >= 0; i--) {

            }

            for (int i = 0; i < n; i++) {
                int ans = dp(i);
                out.println(ans);
            }
        }

    }

    static class Segment implements Cloneable {
        private Segment left;
        private Segment right;
        private int min;
        private int max;
        private int maxIndex;

        public void pushUp() {
            min = Math.min(left.min, right.min);
            max = Math.max(left.max, right.max);
            if (max == left.max) {
                maxIndex = left.maxIndex;
            } else {
                maxIndex = right.maxIndex;
            }
        }

        public void pushDown() {
        }

        public Segment(int l, int r, int[] a) {
            if (l < r) {
                int m = (l + r) >> 1;
                left = new Segment(l, m, a);
                right = new Segment(m + 1, r, a);
                pushUp();
            } else {
                maxIndex = l;
                min = max = a[l];
            }
        }

        private boolean covered(int ll, int rr, int l, int r) {
            return ll <= l && rr >= r;
        }

        private boolean noIntersection(int ll, int rr, int l, int r) {
            return ll > r || rr < l;
        }

        public int query(int ll, int rr, int l, int r) {
            if (noIntersection(ll, rr, l, r)) {
                return Integer.MAX_VALUE;
            }
            if (covered(ll, rr, l, r)) {
                return min;
            }
            pushDown();
            int m = (l + r) >> 1;
            return Math.min(left.query(ll, rr, l, m),
                    right.query(ll, rr, m + 1, r));
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
                    throw new RuntimeException(e);
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

    static class FastOutput implements AutoCloseable, Closeable {
        private StringBuilder cache = new StringBuilder(1 << 20);
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

    }
}