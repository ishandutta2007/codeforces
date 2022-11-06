import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
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
            ESonyaAndMatrixBeauty solver = new ESonyaAndMatrixBeauty();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class ESonyaAndMatrixBeauty {
        int[] d1 = new int[300];
        int[] d2 = new int[300];

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            int[][] mat = new int[n][m];
            int[][] bits = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    mat[i][j] = in.readChar() - 'a';
                    bits[i][j] = 1 << mat[i][j];
                }
            }

            int ans = 0;
            int limit = 'z' - 'a' + 1;
            ModifiableWholeHash[][] wholeHashes = new ModifiableWholeHash[n][2];
            for (int i = 0; i < n; i++) {
                if (i == 0) {
                    wholeHashes[i][0] = new ModifiableWholeHash(31, limit);
                    //wholeHashes[i][1] = new ModifiableWholeHash(61, limit);
                } else {
                    wholeHashes[i][0] = new ModifiableWholeHash(wholeHashes[i - 1][0]);
                    //wholeHashes[i][1] = new ModifiableWholeHash(wholeHashes[i - 1][1]);
                }
            }
            PreXor[] xors = new PreXor[n];
            for (int i = 0; i < n; i++) {
                xors[i] = new PreXor(bits[i]);
            }
            int[] hashes = new int[n];
            for (int l = 0; l < m; l++) {
                for (int i = 0; i < n; i++) {
                    wholeHashes[i][0].clear();
                    //wholeHashes[i][1].clear();
                }
                for (int r = l; r < m; r++) {
                    int invalidCnt = 0;
                    for (int i = 0; i < n; i++) {
                        wholeHashes[i][0].modify(mat[i][r], 1);
                        //wholeHashes[i][1].modify(mat[i][r], 1);
                        int interval = (int) xors[i].intervalSum(l, r);
                        if (interval != Integer.lowestOneBit(interval)) {
                            invalidCnt++;
                            hashes[i] = -invalidCnt;
                            continue;
                        }
                        hashes[i] = wholeHashes[i][0].hash();//DigitUtils.asLong(wholeHashes[i][0].hash(), wholeHashes[i][1].hash());
                    }
                    int contrib = howMany(hashes, n);
                    //System.err.printf("[%d,%d]=>%d\n", l, r, contrib);
                    ans += contrib;
                }
            }

            //System.err.println(invoke);
            out.println(ans);
        }

        public int howMany(int[] hash, int n) {
            int ans = 0;
//        Arrays.fill(d1, 0);
//        Arrays.fill(d2, 0);
            Manacher.oddPalindrome(hash, n, d1);
            Manacher.evenPalindrome(hash, n, d2);
            for (int i = 0; i < n; i++) {
                if (hash[i] < 0) {
                    continue;
                }
                ans += d1[i] + d2[i];
                //invoke++;
            }

            return ans;
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

        public char readChar() {
            skipBlank();
            char c = (char) next;
            next = read();
            return c;
        }

    }

    static class Modular {
        int m;

        public Modular(int m) {
            this.m = m;
        }

        public Modular(long m) {
            this.m = (int) m;
            if (this.m != m) {
                throw new IllegalArgumentException();
            }
        }

        public Modular(double m) {
            this.m = (int) m;
            if (this.m != m) {
                throw new IllegalArgumentException();
            }
        }

        public int valueOf(long x) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            return (int) x;
        }

        public int mul(int x, int y) {
            return valueOf((long) x * y);
        }

        public String toString() {
            return "mod " + m;
        }

    }

    static class Manacher {
        public static void oddPalindrome(int[] s, int n, int[] ans) {
            int c = -1;
            int mx = -1;
            for (int i = 0; i < n; i++) {
                int len = 0;
                if (mx > i) {
                    int mirror = c - (i - c);
                    len = Math.min(ans[mirror] - 1, mx - i);
                }
                while (i - (len + 1) >= 0 && i + (len + 1) < n && s[i - (len + 1)] == s[i + (len + 1)]) {
                    len++;
                }
                ans[i] = len + 1;
                if (mx < i + len) {
                    mx = i + len;
                    c = i;
                }
            }
        }

        public static void evenPalindrome(int[] s, int n, int[] ans) {
            int c = -1;
            int mx = -1;
            ans[0] = 0;
            for (int i = 1; i < n; i++) {
                int len = 0;
                if (mx >= i) {
                    int mirror = c - (i - c);
                    len = Math.min(ans[mirror], mx - (i - 1));
                }
                while (i - (len + 1) >= 0 && i - 1 + (len + 1) < n && s[i - (len + 1)] == s[i - 1 + (len + 1)]) {
                    len++;
                }
                ans[i] = len;
                if (mx < i - 1 + len) {
                    mx = i - 1 + len;
                    c = i;
                }
            }
        }

    }

    static class PreXor {
        private long[] pre;

        public PreXor(int n) {
            pre = new long[n];
        }

        public void populate(long[] a) {
            int n = a.length;
            pre[0] = a[0];
            for (int i = 1; i < n; i++) {
                pre[i] = pre[i - 1] ^ a[i];
            }
        }

        public void populate(int[] a) {
            int n = a.length;
            pre[0] = a[0];
            for (int i = 1; i < n; i++) {
                pre[i] = pre[i - 1] ^ a[i];
            }
        }

        public PreXor(long[] a) {
            this(a.length);
            populate(a);
        }

        public PreXor(int[] a) {
            this(a.length);
            populate(a);
        }

        public long intervalSum(int l, int r) {
            if (r < l) {
                return 0;
            }
            if (l == 0) {
                return pre[r];
            }
            return pre[r] ^ pre[l - 1];
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

    static class ModifiableWholeHash {
        public static final Modular MOD = new Modular((int) (1e9 + 7));
        private int[] xs;
        private int hash;

        public ModifiableWholeHash(int x, int n) {
            xs = new int[n + 1];
            xs[0] = 1;
            for (int i = 1; i <= n; i++) {
                xs[i] = MOD.mul(xs[i - 1], x);
            }
            clear();
        }

        public ModifiableWholeHash(ModifiableWholeHash hash) {
            xs = hash.xs;
            clear();
        }

        public void clear() {
            hash = 0;
        }

        public void modify(int i, int v) {
            hash = MOD.valueOf(hash + (long) v * xs[i]);
        }

        public int hash() {
            return hash;
        }

    }
}