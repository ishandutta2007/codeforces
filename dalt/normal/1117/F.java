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
            TaskF solver = new TaskF();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskF {
        BitOperator bo = new BitOperator();
        int p;
        int[] charCnt;
        int[] dp;
        int[] cnts;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            p = in.readInt();
            int[] s = new int[n];
            for (int i = 0; i < n; i++) {
                s[i] = in.readChar() - 'a';
            }
            int[] mask = new int[p];

            for (int i = 0; i < p; i++) {
                for (int j = 0; j < p; j++) {
                    mask[i] = bo.setBit(mask[i], j, in.readInt() == 0);
                }
            }
            IntList[] next = new IntList[n];
            IntList[] prev = new IntList[n];

            prev[0] = new IntList();
            for (int i = 1; i < n; i++) {
                prev[i] = new IntList(prev[i - 1].size() + 1);
                prev[i].addAll(prev[i - 1]);
                int index = prev[i].indexOf(s[i - 1]);
                if (index >= 0) {
                    prev[i].remove(index);
                }
                prev[i].add(s[i - 1]);
            }
            next[n - 1] = new IntList();
            for (int i = n - 2; i >= 0; i--) {
                next[i] = new IntList(next[i + 1].size() + 1);
                next[i].addAll(next[i + 1]);
                int index = next[i].indexOf(s[i + 1]);
                if (index >= 0) {
                    next[i].remove(index);
                }
                next[i].add(s[i + 1]);
            }

            cnts = new int[1 << p];
            for (int i = 0; i < n; i++) {
                int v = s[i];
                int m = 0;
                for (int j = prev[i].size() - 1; j >= 0; j--) {
                    int u = prev[i].get(j);
                    if (bo.bitAt(mask[v], u) == 1) {
                        cnts[m]++;
                        cnts[m | (1 << u)]--;
                        cnts[m | (1 << v)]--;
                        cnts[m | (1 << u) | (1 << v)]++;
                    }
                    m = bo.setBit(m, u, true);
                }
                m = 0;
                for (int j = next[i].size() - 1; j >= 0; j--) {
                    int u = next[i].get(j);
                    if (bo.bitAt(mask[v], u) == 1) {
                        cnts[m]++;
                        cnts[m | (1 << u)]--;
                        cnts[m | (1 << v)]--;
                        cnts[m | (1 << u) | (1 << v)]++;
                    }
                    m = bo.setBit(m, u, true);
                }
            }

            FastWalshHadamardTransform.orFWT(cnts, 0, cnts.length - 1);
            charCnt = new int[p];
            for (int i = 0; i < n; i++) {
                charCnt[s[i]]++;
            }
            dp = new int[1 << p];
            SequenceUtils.deepFill(dp, -1);
            int ans = dp(0);
            out.println(ans);
        }

        public int dp(int s) {
            if (dp[s] == -1) {
                dp[s] = 0;
                if (cnts[s] > 0) {
                    return dp[s] = (int) 1e8;
                }
                for (int i = 0; i < p; i++) {
                    if (bo.bitAt(s, i) == 0) {
                        dp[s] += charCnt[i];
                    }
                }
                for (int i = 0; i < p; i++) {
                    if (bo.bitAt(s, i) == 0) {
                        dp[s] = Math.min(dp[s], dp(bo.setBit(s, i, true)));
                    }
                }
            }
            return dp[s];
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

    static class BitOperator {
        public int bitAt(int x, int i) {
            return (x >> i) & 1;
        }

        public int setBit(int x, int i, boolean v) {
            if (v) {
                x |= 1 << i;
            } else {
                x &= ~(1 << i);
            }
            return x;
        }

    }

    static class IntList {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public IntList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public IntList(IntList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public IntList() {
            this(0);
        }

        public void ensureSpace(int req) {
            if (req > cap) {
                while (cap < req) {
                    cap = Math.max(cap + 10, 2 * cap);
                }
                data = Arrays.copyOf(data, cap);
            }
        }

        private void checkRange(int i) {
            if (i < 0 || i >= size) {
                throw new ArrayIndexOutOfBoundsException();
            }
        }

        public int get(int i) {
            checkRange(i);
            return data[i];
        }

        public void add(int x) {
            ensureSpace(size + 1);
            data[size++] = x;
        }

        public void addAll(int[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(IntList list) {
            addAll(list.data, 0, list.size);
        }

        public int indexOf(int x) {
            for (int i = 0; i < size; i++) {
                if (x == data[i]) {
                    return i;
                }
            }
            return -1;
        }

        public int pop() {
            return data[--size];
        }

        public int size() {
            return size;
        }

        public void remove(int index) {
            checkRange(index);
            if (index == size - 1) {
                pop();
                return;
            }
            System.arraycopy(data, index + 1, data, index, size - index);
            size--;
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public String toString() {
            return Arrays.toString(toArray());
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof IntList)) {
                return false;
            }
            IntList other = (IntList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + data[i];
            }
            return h;
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

    static class FastWalshHadamardTransform {
        public static void orFWT(int[] p, int l, int r) {
            if (l == r) {
                return;
            }
            int m = (l + r) >> 1;
            orFWT(p, l, m);
            orFWT(p, m + 1, r);
            for (int i = 0, until = m - l; i <= until; i++) {
                int a = p[l + i];
                int b = p[m + 1 + i];
                p[m + 1 + i] = a + b;
            }
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

        public static boolean equal(int[] a, int al, int ar, int[] b, int bl, int br) {
            if ((ar - al) != (br - bl)) {
                return false;
            }
            for (int i = al, j = bl; i <= ar; i++, j++) {
                if (a[i] != b[j]) {
                    return false;
                }
            }
            return true;
        }

    }
}