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
            BSeatingOfStudents solver = new BSeatingOfStudents();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class BSeatingOfStudents {
        int n;
        int m;
        int[][] dirs = new int[][]{
                {1, 0},
                {-1, 0},
                {0, 1},
                {0, -1}
        };

        public void solve(int testNumber, FastInput in, FastOutput out) {
            n = in.readInt();
            m = in.readInt();
            int[][] ans = new int[n][m];

            if (n <= 3 && m <= 3) {
                int[][][] mat = new int[n][m][];
                List<int[]> vals = new ArrayList<>();
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        vals.add(new int[]{i, j});
                    }
                }
                if (!bf(mat, vals.toArray(new int[0][]), n - 1, m - 1)) {
                    out.println("NO");
                    return;
                }
                out.println("YES");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        out.append(ceilId(mat[i][j][0], mat[i][j][1])).append(' ');
                    }
                    out.println();
                }

                return;
            }

            out.println("YES");
            if (n == 1) {
                IntegerList l1 = new IntegerList(m);
                IntegerList l2 = new IntegerList(m);
                for (int i = 0; i < m; i++) {
                    if (i % 2 == 0) {
                        l1.add(ceilId(0, i));
                    } else {
                        l2.add(ceilId(0, i));
                    }
                }
                l2.addAll(l1);
                for (int i = 0; i < m; i++) {
                    out.append(l2.get(i)).append(' ');
                }
                return;
            }
            if (m == 1) {
                IntegerList l1 = new IntegerList(n);
                IntegerList l2 = new IntegerList(n);
                for (int i = 0; i < n; i++) {
                    if (i % 2 == 0) {
                        l1.add(ceilId(i, 0));
                    } else {
                        l2.add(ceilId(i, 0));
                    }
                }
                l2.addAll(l1);
                for (int i = 0; i < n; i++) {
                    out.append(l2.get(i)).println();
                }
                return;
            }


            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ans[i][j] = ceilId(i, j);
                }
            }
            if (m > 3) {
                for (int i = 1; i < m; i += 2) {
                    vr(ans, i);
                }
                for (int i = 1; i < n; i += 2) {
                    rr(ans, i);
                    rr(ans, i);
                }
            } else {
                for (int i = 1; i < n; i += 2) {
                    rr(ans, i);
                }
                for (int i = 1; i < m; i += 2) {
                    vr(ans, i);
                    vr(ans, i);
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    out.append(ans[i][j]).append(' ');
                }
                out.println();
            }
        }

        public boolean near(int[] a, int[] b) {
            return a[1] == b[1] && Math.abs(a[0] - b[0]) == 1 || a[0] == b[0] && Math.abs(a[1] - b[1]) == 1;
        }

        public boolean bf(int[][][] perm, int[][] vals, int r, int c) {
            if (c < 0) {
                return bf(perm, vals, r - 1, m - 1);
            }
            if (r < 0) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < m; k++) {
                        for (int[] d : dirs) {
                            int nj = j + d[0];
                            int nk = k + d[1];
                            if (nj < 0 || nj >= n || nk < 0 || nk >= m) {
                                continue;
                            }
                            if (near(perm[j][k], perm[nj][nk])) {
                                return false;
                            }
                        }
                    }
                }
                return true;
            }
            for (int j = 0; j < vals.length; j++) {
                if (vals[j] == null) {
                    continue;
                }
                perm[r][c] = vals[j];
                vals[j] = null;
                if (bf(perm, vals, r, c - 1)) {
                    return true;
                }
                vals[j] = perm[r][c];
            }
            return false;
        }

        public void vr(int[][] mat, int c) {
            int n = mat.length;
            int m = mat[0].length;

            int head = mat[0][c];
            for (int j = 0; j < n - 1; j++) {
                mat[j][c] = mat[j + 1][c];
            }
            mat[n - 1][c] = head;
        }

        public void rr(int[][] mat, int r) {
            int n = mat.length;
            int m = mat[0].length;
            SequenceUtils.rotate(mat[r], 0, m - 1, 1);
        }

        int ceilId(int i, int j) {
            return i * m + j + 1;
        }

    }

    static class FastInput {
        private final InputStream is;
        private byte[] buf = new byte[1 << 20];
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

    static class IntegerList implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public IntegerList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public IntegerList(IntegerList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public IntegerList() {
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

        public void addAll(IntegerList list) {
            addAll(list.data, 0, list.size);
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public String toString() {
            return Arrays.toString(toArray());
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof IntegerList)) {
                return false;
            }
            IntegerList other = (IntegerList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Integer.hashCode(data[i]);
            }
            return h;
        }

        public IntegerList clone() {
            IntegerList ans = new IntegerList();
            ans.addAll(this);
            return ans;
        }

    }

    static class SequenceUtils {
        public static void swap(int[] data, int i, int j) {
            int tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

        public static void rotate(int[] list, int l, int r, int to) {
            SequenceUtils.reverse(list, l, r);
            SequenceUtils.reverse(list, l, to - 1);
            SequenceUtils.reverse(list, to, r);
        }

        public static void reverse(int[] data, int l, int r) {
            while (l < r) {
                swap(data, l, r);
                l++;
                r--;
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

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }

        public FastOutput append(int c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(String c) {
            cache.append(c);
            println();
            return this;
        }

        public FastOutput println() {
            cache.append(System.lineSeparator());
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
}