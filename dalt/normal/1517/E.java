import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
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
            EGroupPhoto solver = new EGroupPhoto();
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                solver.solve(i, in, out);
            out.close();
        }
    }

    static class EGroupPhoto {
        int mod = 998244353;
        Debug debug = new Debug(false);
        LongPreSum ps;
        LongPreSum[] delta = new LongPreSum[2];

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int[] a = in.ri(n);
            if (n == 1) {
                out.println(1);
                return;
            }
            ps = new LongPreSum(i -> a[i], n);
            for (int i = 0; i < 2; i++) {
                delta[i] = new LongPreSum(n);
            }
            long ans = 0;
            //all one side
//        ans++;
            //only one
            //for x
//        if (n > 2 && ps.intervalSum(0, n - 1) < a[n - 2] * 2) {
//            ans++;
//        }
//        if (n > 2 && ps.intervalSum(0, n - 1) > a[1] * 2) {
//            ans++;
//        }
            //different side
            for (int i = -1; i < n; i++) {
                if (ps.intervalSum(0, i) > ps.intervalSum(i + 1, n - 1)) {
                    ans++;
                }
            }
            debug.debug("ans", ans);
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    int[] data = Arrays.copyOfRange(a, i, n - j);
                    long y = i * a[0];
                    long x = j * a[n - 1];
                    long contrib = solve(data, x, y);
                    ans += contrib;
                    debug.debug("i", i);
                    debug.debug("j", j);
                    debug.debug("contrib", contrib);
                }
            }

            debug.debug("ans", ans);
            ans %= mod;
            out.println(ans);
        }

        public long solve(int[] seq, long x, long y) {
            if (seq.length <= 1) {
                return 0;
            }
            int n = seq.length;
            ps.populate(i -> seq[i], n);
            for (int i = 0; i < 2; i++) {
                int finalI = i;
                delta[i].populate(j -> (j & 1) != finalI ? 0 : seq[j] - seq[j + 1], n - 1);
            }
            long sum = x;
            long ans = 0;
            for (int i = 0; i < n - 1; i++) {
                sum += seq[i];
                int l = i + 1;
                int r = n - 1;
                if (r % 2 != l % 2) {
                    r--;
                }
                int bit = l & 1;
                l >>= 1;
                r >>= 1;
                while (l < r) {
                    int mid = ((r + l + 1) / 2) * 2 + bit;
                    //check
                    long right = y + ps.post(mid) + delta[bit].intervalSum(i + 1, mid - 1);
                    if (sum < right) {
                        //ok
                        l = mid >> 1;
                    } else {
                        r = (mid >> 1) - 1;
                    }
                }
                l = l * 2 + bit;
                r = r * 2 + bit;
                int mid = r;
                long right = y + ps.post(mid) + delta[bit].intervalSum(i + 1, mid - 1);
                if (sum < right) {
                    //ok
                    int choice = (l - i - 1) / 2 + 1;
                    ans += choice;
                }
            }
            return ans;
        }

    }

    static class LongPreSum {
        private long[] pre;
        private int n;

        public LongPreSum(int n) {
            pre = new long[n];
        }

        public void populate(IntToLongFunction a, int n) {
            this.n = n;
            if (n == 0) {
                return;
            }
            pre[0] = a.apply(0);
            for (int i = 1; i < n; i++) {
                pre[i] = pre[i - 1] + a.apply(i);
            }
        }

        public LongPreSum(IntToLongFunction a, int n) {
            this(n);
            populate(a, n);
        }

        public long intervalSum(int l, int r) {
            return prefix(r) - prefix(l - 1);
        }

        public long prefix(int i) {
            i = Math.min(i, n - 1);
            if (i < 0) {
                return 0;
            }
            return pre[i];
        }

        public long post(int i) {
            return prefix(n) - prefix(i - 1);
        }

        public String toString() {
            StringBuilder ans = new StringBuilder();
            for (int i = 0; i < n; i++) {
                ans.append(intervalSum(i, i)).append(',');
            }
            if (ans.length() > 0) {
                ans.setLength(ans.length() - 1);
            }
            return ans.toString();
        }

    }

    static interface IntToLongFunction {
        long apply(int x);

    }

    static class Debug {
        private boolean offline;
        private PrintStream out = System.err;

        public Debug(boolean enable) {
            offline = enable && System.getSecurityManager() == null;
        }

        public Debug debug(String name, int x) {
            if (offline) {
                debug(name, "" + x);
            }
            return this;
        }

        public Debug debug(String name, long x) {
            if (offline) {
                debug(name, "" + x);
            }
            return this;
        }

        public Debug debug(String name, String x) {
            if (offline) {
                out.printf("%s=%s", name, x);
                out.println();
            }
            return this;
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

        public FastOutput append(long c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(int c) {
            return append(c).println();
        }

        public FastOutput println(long c) {
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

        public int[] ri(int n) {
            int[] ans = new int[n];
            populate(ans);
            return ans;
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