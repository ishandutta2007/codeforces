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
            GBeautifulMatrix solver = new GBeautifulMatrix();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class GBeautifulMatrix {
        Modular mod = new Modular(998244353);
        Factorial factorial = new Factorial(2000, mod);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int[][] mat = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    mat[i][j] = in.readInt();
                }
            }

            PermutationWithDistinctForbiddenMatch permutation = new PermutationWithDistinctForbiddenMatch(mod, n);
            int[] follow = new int[n + 1];
            follow[0] = 1;
            for (int i = 1; i <= n; i++) {
                follow[i] = mod.mul(follow[i - 1], permutation.get(n, 0));
            }

            int ans = 0;

            int[] indexOfVal = new int[n + 1];
            int[] indexOfDim = new int[n + 1];
            IntegerBIT deleteBit = new IntegerBIT(n);
            IntegerBIT leftBIT = new IntegerBIT(n);
            IntegerBIT rightBIT = new IntegerBIT(n);

            int[][] live = new int[n][n];
            int[][] left = new int[n][n];
            int[][] right = new int[n][n];
            MultiWayIntegerStack s1 = new MultiWayIntegerStack(n, n);
            MultiWayIntegerStack s2 = new MultiWayIntegerStack(n, n);
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    indexOfVal[mat[i][j]] = j;
                    indexOfDim[mat[i - 1][j]] = j;
                }

                leftBIT.clear();
                rightBIT.clear();
                s1.clear();
                s2.clear();
                for (int j = n - 1; j >= 0; j--) {
                    right[i][j] = rightBIT.query(mat[i][j] - 1);
                    if (mat[i - 1][j] < mat[i][j]) {
                        right[i][j] -= rightBIT.query(mat[i - 1][j]) - rightBIT.query(mat[i - 1][j] - 1);
                    }
                    left[i][j] = leftBIT.query(mat[i][j] - 1);
                    if (mat[i - 1][j] < mat[i][j]) {
                        left[i][j] -= leftBIT.query(mat[i - 1][j]) - leftBIT.query(mat[i - 1][j] - 1);
                    }
                    live[i][j] = rightBIT.query(n);

                    if (indexOfVal[mat[i - 1][j]] <= j) {
                        s1.addLast(indexOfVal[mat[i - 1][j]], j);
                    } else {
                        rightBIT.update(mat[i - 1][j], 1);
                    }

                    if (indexOfDim[mat[i][j]] <= j) {
                        s2.addLast(indexOfDim[mat[i][j]], j);
                        leftBIT.update(mat[i][j], 1);
                    } else {
                    }

                    while (!s1.isEmpty(j)) {
                        int tail = s1.removeLast(j);
                        //leftBIT.update(mat[i - 1][tail], -1);
                        rightBIT.update(mat[i - 1][tail], 1);
                    }

                    while (!s2.isEmpty(j)) {
                        int tail = s2.removeLast(j);
                        leftBIT.update(mat[i][tail], -1);
                    }
                }

            }

            deleteBit.clear();
            for (int j = 0; j < n; j++) {
                int cnt = mat[0][j] - 1 - deleteBit.query(mat[0][j] - 1);
                int contrib = mod.mul(cnt, factorial.fact(n - j - 1));
                contrib = mod.mul(contrib, follow[n - 1]);
                ans = mod.plus(ans, contrib);
                deleteBit.update(mat[0][j], 1);
            }

            for (int i = 1; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    indexOfVal[mat[i][j]] = j;
                    indexOfDim[mat[i - 1][j]] = j;
                }
                for (int j = 0; j < n; j++) {
                    //from left
                    if (left[i][j] == 0) {
                        continue;
                    }
                    int contrib = left[i][j];
                    int remain = n - 1 - j;
                    int l = live[i][j];
                    if (indexOfDim[mat[i][j]] > j) {
                        l++;
                    }
                    contrib = mod.mul(contrib, permutation.get(l, remain - l));
                    contrib = mod.mul(contrib, follow[n - 1 - i]);
                    ans = mod.plus(ans, contrib);
                }
                for (int j = 0; j < n; j++) {
                    //from right
                    if (right[i][j] == 0) {
                        continue;
                    }
                    int contrib = right[i][j];
                    int remain = n - 1 - j;
                    int l = live[i][j];
                    if (indexOfDim[mat[i][j]] > j) {
                        l++;
                    }
                    contrib = mod.mul(contrib, permutation.get(l - 1, remain - (l - 1)));
                    contrib = mod.mul(contrib, follow[n - 1 - i]);
                    ans = mod.plus(ans, contrib);
                }
            }

            out.println(ans);
        }

    }

    static class PermutationWithDistinctForbiddenMatch {
        private int[][] dp;
        private int[][] dp2;

        public PermutationWithDistinctForbiddenMatch(Modular mod, int n) {
            this.dp = new int[n + 1][n + 1];
            dp[0][0] = 1;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j <= i; j++) {
                    dp[i][j] = mod.mul(dp[i - 1][j], j + j);
                    if (j + 1 <= n) {
                        dp[i][j] = mod.plus(dp[i][j], dp[i - 1][j + 1]);
                    }
                    if (j > 0) {
                        dp[i][j] = mod.plus(dp[i][j], mod.mul(dp[i - 1][j - 1], mod.mul(j, j)));
                    }
                }
            }

            dp2 = new int[n + 1][n + 1];
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    if (j == 0) {
                        dp2[i][j] = dp[i][j];
                        continue;
                    }
                    if (j > 0) {
                        dp2[i][j] = mod.plus(dp2[i][j], mod.mul(dp2[i][j - 1], j));
                    }
                    if (i > 0) {
                        dp2[i][j] = mod.plus(dp2[i][j], mod.mul(dp2[i - 1][j], i));
                    }
                }
            }

//        System.err.println(Arrays.deepToString(dp));
//        System.err.println(Arrays.deepToString(dp2));
        }

        public int get(int i, int j) {
            return dp2[i][j];
        }

    }

    static interface IntegerIterator {
        boolean hasNext();

        int next();

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

    static class MultiWayIntegerStack {
        private int[] values;
        private int[] next;
        private int[] heads;
        private int alloc;
        private int stackNum;

        public IntegerIterator iterator(final int queue) {
            return new IntegerIterator() {
                int ele = heads[queue];


                public boolean hasNext() {
                    return ele != 0;
                }


                public int next() {
                    int ans = values[ele];
                    ele = next[ele];
                    return ans;
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

        public void clear() {
            alloc = 0;
            Arrays.fill(heads, 0, stackNum, 0);
        }

        public boolean isEmpty(int qId) {
            return heads[qId] == 0;
        }

        public MultiWayIntegerStack(int qNum, int totalCapacity) {
            values = new int[totalCapacity + 1];
            next = new int[totalCapacity + 1];
            heads = new int[qNum];
            stackNum = qNum;
        }

        public void addLast(int qId, int x) {
            alloc();
            values[alloc] = x;
            next[alloc] = heads[qId];
            heads[qId] = alloc;
        }

        public int removeLast(int qId) {
            int ans = values[heads[qId]];
            heads[qId] = next[heads[qId]];
            return ans;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < stackNum; i++) {
                builder.append(i).append(": ");
                for (IntegerIterator iterator = iterator(i); iterator.hasNext(); ) {
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

    static class Modular {
        int m;

        public int getMod() {
            return m;
        }

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

        public int valueOf(int x) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            return x;
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

        public int plus(int x, int y) {
            return valueOf(x + y);
        }

        public String toString() {
            return "mod " + m;
        }

    }

    static class IntegerBIT {
        private int[] data;
        private int n;

        public IntegerBIT(int n) {
            this.n = n;
            data = new int[n + 1];
        }

        public int query(int i) {
            int sum = 0;
            for (; i > 0; i -= i & -i) {
                sum += data[i];
            }
            return sum;
        }

        public void update(int i, int mod) {
            if (i <= 0) {
                return;
            }
            for (; i <= n; i += i & -i) {
                data[i] += mod;
            }
        }

        public void clear() {
            Arrays.fill(data, 0);
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 1; i <= n; i++) {
                builder.append(query(i) - query(i - 1)).append(' ');
            }
            return builder.toString();
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

    static class InverseNumber {
        int[] inv;

        public InverseNumber(int[] inv, int limit, Modular modular) {
            this.inv = inv;
            inv[1] = 1;
            int p = modular.getMod();
            for (int i = 2; i <= limit; i++) {
                int k = p / i;
                int r = p % i;
                inv[i] = modular.mul(-k, inv[r]);
            }
        }

        public InverseNumber(int limit, Modular modular) {
            this(new int[limit + 1], limit, modular);
        }

    }

    static class Factorial {
        int[] fact;
        int[] inv;
        Modular modular;

        public Factorial(int[] fact, int[] inv, InverseNumber in, int limit, Modular modular) {
            this.modular = modular;
            this.fact = fact;
            this.inv = inv;
            fact[0] = inv[0] = 1;
            for (int i = 1; i <= limit; i++) {
                fact[i] = modular.mul(fact[i - 1], i);
                inv[i] = modular.mul(inv[i - 1], in.inv[i]);
            }
        }

        public Factorial(int limit, Modular modular) {
            this(new int[limit + 1], new int[limit + 1], new InverseNumber(limit, modular), limit, modular);
        }

        public int fact(int n) {
            return fact[n];
        }

    }
}