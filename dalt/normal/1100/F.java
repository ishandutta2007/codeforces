import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Iterator;
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
            FIvanAndBurgers solver = new FIvanAndBurgers();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FIvanAndBurgers {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int[] c = new int[n];
            for (int i = 0; i < n; i++) {
                c[i] = in.readInt();
            }
            int qCnt = in.readInt();
            Query[] qs = new Query[qCnt];
            for (int i = 0; i < qCnt; i++) {
                qs[i] = new Query();
                qs[i].l = in.readInt() - 1;
                qs[i].r = in.readInt() - 1;
            }
            Query[] qsSorted = qs.clone();
            Arrays.sort(qsSorted, (a, b) -> a.l == b.l ? a.r - b.r : b.l - a.l);
            SimplifiedDeque<Query> deque = new Array2DequeAdapter<>(qsSorted);
            LinearBasis basis = new LinearBasis();
            IntList last = new IntList();
            IntList next = new IntList();
            for (int i = n - 1; i >= 0; i--) {
                basis.clear();
                next.clear();
                basis.add(c[i]);
                next.add(i);
                int j = 0;
                while (!deque.isEmpty() && deque.peekFirst().l == i) {
                    Query q = deque.removeFirst();
                    while (j < last.size() && last.get(j) <= q.r) {
                        next.add(last.get(j++));
                        if (!basis.add(c[next.tail()])) {
                            next.pop();
                        }
                    }
                    q.ans = basis.theMaximumNumberXor(0);
                }
                while (j < last.size()) {
                    next.add(last.get(j++));
                    if (!basis.add(c[next.tail()])) {
                        next.pop();
                    }
                }
                IntList tmp = last;
                last = next;
                next = tmp;
            }

            for (Query q : qs) {
                out.println(q.ans);
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

    static interface SimplifiedStack<T> extends Iterable<T> {
        boolean isEmpty();

    }

    static interface SimplifiedDeque<T> extends SimplifiedStack<T> {
        T peekFirst();

        T removeFirst();

    }

    static class Array2DequeAdapter<T> implements SimplifiedDeque<T> {
        T[] data;
        int l;
        int r;

        public Array2DequeAdapter(T[] data) {
            this(data, 0, data.length - 1);
        }

        public Array2DequeAdapter(T[] data, int l, int r) {
            this.data = data;
            this.l = l;
            this.r = r;
        }

        public boolean isEmpty() {
            return l > r;
        }

        public T peekFirst() {
            return data[l];
        }

        public T removeFirst() {
            return data[l++];
        }

        public Iterator<T> iterator() {
            return new Iterator<T>() {
                int iter = l;


                public boolean hasNext() {
                    return iter <= r;
                }


                public T next() {
                    return data[iter++];
                }
            };
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

    static class Log2 {
        public int floorLog(int x) {
            return 31 - Integer.numberOfLeadingZeros(x);
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

        public int tail() {
            checkRange(0);
            return data[size - 1];
        }

        public int pop() {
            return data[--size];
        }

        public int size() {
            return size;
        }

        public int[] toArray() {
            return Arrays.copyOf(data, size);
        }

        public void clear() {
            size = 0;
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

    static class Query {
        int l;
        int r;
        int ans;

    }

    static class LinearBasis {
        private int[] map = new int[20];
        private int size;
        private Log2 log2 = new Log2();

        public void clear() {
            size = 0;
            Arrays.fill(map, 0);
        }

        private void afterAddBit(int bit) {
            for (int i = 19; i >= 0; i--) {
                if (i == bit || map[i] == 0) {
                    continue;
                }
                if (bitAt(map[i], bit) == 1) {
                    map[i] ^= map[bit];
                }
            }
        }

        public boolean add(int val) {
            for (int i = 19; i >= 0 && val != 0; i--) {
                if (bitAt(val, i) == 0) {
                    continue;
                }
                val ^= map[i];
            }
            if (val != 0) {
                int log = log2.floorLog(val);
                map[log] = val;
                size++;
                afterAddBit(log);
                return true;
            }
            return false;
        }

        private long bitAt(int val, int i) {
            return (val >>> i) & 1;
        }

        public int theMaximumNumberXor(int x) {
            for (int i = 0; i < 20; i++) {
                if (map[i] == 0) {
                    continue;
                }
                if (bitAt(x, i) == 0) {
                    x ^= map[i];
                }
            }
            return x;
        }

    }
}