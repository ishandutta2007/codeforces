import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.Deque;
import java.util.ArrayList;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
import java.util.ArrayDeque;
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
            GSwitchAndFlip solver = new GSwitchAndFlip();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class GSwitchAndFlip {
        int[] a;
        int[] inv;
        List<int[]> ops = new ArrayList<>();

        public void swap(int i, int j) {
            i = inv[i];
            j = inv[j];
            int tmp = a[i];
            a[i] = -a[j];
            a[j] = -tmp;
            inv[Math.abs(a[i])] = i;
            inv[Math.abs(a[j])] = j;
            ops.add(new int[]{i, j});
        }

        boolean check(IntegerArrayList list) {
            for (int x : list.toArray()) {
                if (a[x] != x) {
                    return false;
                }
            }
            return true;
        }

        public void solve(int testNumber, FastInput in, FastOutput out) {
            Deque<int[]> sol = new ArrayDeque<>();

            int n = in.ri();
            a = new int[n + 1];
            inv = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                a[i] = in.ri();
                inv[a[i]] = i;
            }
            Permutation permutation = new Permutation(a);
            List<IntegerArrayList> circles = permutation.extractCircles(2);
            while (circles.size() >= 2) {
                IntegerArrayList a = CollectionUtils.pop(circles);
                IntegerArrayList b = CollectionUtils.pop(circles);
                swap(a.first(), b.first());
                for (int i = 1; i < a.size(); i++) {
                    swap(a.get(i - 1), a.get(i));
                }
                for (int i = 1; i < b.size(); i++) {
                    swap(b.get(i - 1), b.get(i));
                }
                swap(a.tail(), b.tail());
                assert check(a);
                assert check(b);
            }
            if (circles.size() == 1) {
                IntegerArrayList only = CollectionUtils.pop(circles);
                if (only.size() == 2) {
                    int proper = -1;
                    for (int i = 1; i <= n; i++) {
                        if (a[i] == i) {
                            proper = i;
                            break;
                        }
                    }
                    assert proper != -1;
                    swap(proper, only.first());
                    swap(only.first(), only.tail());
                    swap(only.tail(), proper);
                } else {
                    swap(only.get(0), only.get(1));
                    for (int i = 2; i + 1 < only.size(); i++) {
                        swap(only.get(i - 1), only.get(i));
                    }

                    //cool
                    int a2 = only.get(0);
                    int a3 = only.get(only.size() - 2);
                    int a1 = only.get(only.size() - 1);
                    swap(a1, a2);
                    swap(a2, a3);
                    swap(a1, a2);
                }
                assert check(only);
            }
            for (int i = 1; i <= n; i++) {
                assert a[i] == i;
            }
            out.println(ops.size());
            for (int[] x : ops) {
                out.append(x[0]).append(' ').append(x[1]).println();
            }
        }

    }

    static class CollectionUtils {
        public static <T> T pop(List<T> list) {
            return list.remove(list.size() - 1);
        }

    }

    static class SequenceUtils {
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

        public FastOutput append(String c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(int c) {
            return append(c).println();
        }

        public FastOutput println() {
            return append(System.lineSeparator());
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

    static class IntegerArrayList implements Cloneable {
        private int size;
        private int cap;
        private int[] data;
        private static final int[] EMPTY = new int[0];

        public IntegerArrayList(int cap) {
            this.cap = cap;
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
        }

        public IntegerArrayList(int[] data) {
            this(0);
            addAll(data);
        }

        public IntegerArrayList(IntegerArrayList list) {
            this.size = list.size;
            this.cap = list.cap;
            this.data = Arrays.copyOf(list.data, size);
        }

        public IntegerArrayList() {
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
                throw new ArrayIndexOutOfBoundsException("Access [" + i + "]");
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

        public void addAll(int[] x) {
            addAll(x, 0, x.length);
        }

        public void addAll(int[] x, int offset, int len) {
            ensureSpace(size + len);
            System.arraycopy(x, offset, data, size, len);
            size += len;
        }

        public void addAll(IntegerArrayList list) {
            addAll(list.data, 0, list.size);
        }

        public int first() {
            checkRange(0);
            return data[0];
        }

        public int tail() {
            checkRange(0);
            return data[size - 1];
        }

        public int size() {
            return size;
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public String toString() {
            return Arrays.toString(toArray());
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof IntegerArrayList)) {
                return false;
            }
            IntegerArrayList other = (IntegerArrayList) obj;
            return SequenceUtils.equal(data, 0, size - 1, other.data, 0, other.size - 1);
        }

        public int hashCode() {
            int h = 1;
            for (int i = 0; i < size; i++) {
                h = h * 31 + Integer.hashCode(data[i]);
            }
            return h;
        }

        public IntegerArrayList clone() {
            IntegerArrayList ans = new IntegerArrayList();
            ans.addAll(this);
            return ans;
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int mod(int x, int mod) {
            if (x < -mod || x >= mod) {
                x %= mod;
            }
            if (x < 0) {
                x += mod;
            }
            return x;
        }

    }

    static class Permutation {
        int[] g;
        int[] idx;
        int[] l;
        int[] r;
        int n;

        public List<IntegerArrayList> extractCircles(int threshold) {
            List<IntegerArrayList> ans = new ArrayList<>(n);
            for (int i = 0; i < n; i = r[i] + 1) {
                int size = r[i] - l[i] + 1;
                if (size < threshold) {
                    continue;
                }
                IntegerArrayList list = new IntegerArrayList(r[i] - l[i] + 1);
                for (int j = l[i]; j <= r[i]; j++) {
                    list.add(g[j]);
                }
                ans.add(list);
            }
            return ans;
        }

        public Permutation(int[] p) {
            this(p, p.length);
        }

        public Permutation(int[] p, int len) {
            n = len;
            boolean[] visit = new boolean[n];
            g = new int[n];
            l = new int[n];
            r = new int[n];
            idx = new int[n];
            int wpos = 0;
            for (int i = 0; i < n; i++) {
                int val = p[i];
                if (visit[val]) {
                    continue;
                }
                visit[val] = true;
                g[wpos] = val;
                l[wpos] = wpos;
                idx[val] = wpos;
                wpos++;
                while (true) {
                    int x = p[g[wpos - 1]];
                    if (visit[x]) {
                        break;
                    }
                    visit[x] = true;
                    g[wpos] = x;
                    l[wpos] = l[wpos - 1];
                    idx[x] = wpos;
                    wpos++;
                }
                for (int j = l[wpos - 1]; j < wpos; j++) {
                    r[j] = wpos - 1;
                }
            }
        }

        public int apply(int x, int p) {
            int i = idx[x];
            int dist = DigitUtils.mod((i - l[i]) + p, r[i] - l[i] + 1);
            return g[dist + l[i]];
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < n; i++) {
                builder.append(apply(i, 1)).append(' ');
            }
            return builder.toString();
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
}