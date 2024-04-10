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
            FClassical solver = new FClassical();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FClassical {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.readInt();
            }
            GcdLcmProblem problem = new GcdLcmProblem(100000, a);
            int[] pair = problem.findAnyPairIndexesWhileLCMMaximized();
            long lcm = LCMs.lcm(a[pair[0]], a[pair[1]]);
            out.println(lcm);
        }

    }

    static class GcdLcmProblem {
        private MultiWayIntegerStack primeFactors;
        private MultiWayIntegerStack factors;
        private IntegerList allFactors = new IntegerList(20);
        private int[] cntOfMultiple;
        private int m;
        private int[] seq;
        private int[] coprime;
        private MultiWayIntegerDeque indexesOfSeq;

        public GcdLcmProblem(int m, int[] seq) {
            this.m = m;
            this.seq = seq;
            primeFactors = Factorization.factorizeRangePrime(m);
            factors = Factorization.factorizeRange(m);
            prepareCntOfMultiple();
            coprime = new int[m + 1];
            Arrays.fill(coprime, -1);
            indexesOfSeq = new MultiWayIntegerDeque(m + 1, seq.length);
            for (int i = 0; i < seq.length; i++) {
                indexesOfSeq.addLast(seq[i], i);
            }
        }

        private void prepareCntOfMultiple() {
            cntOfMultiple = new int[m + 1];
            for (int x : seq) {
                cntOfMultiple[x]++;
            }
            for (int i = 1; i <= m; i++) {
                for (int j = i + i; j <= m; j += i) {
                    cntOfMultiple[i] += cntOfMultiple[j];
                }
            }
        }

        private void factorize(int x) {
            allFactors.clear();
            allFactors.addAll(primeFactors.iterator(x));
        }

        public int[] findAnyPairIndexesWhileLCMMaximized() {
            if (seq.length < 2) {
                return null;
            }
            int size = 0;
            for (int i = 1; i <= m; i++) {
                size += m / i;
            }

            MultiWayIntegerDeque deque = new MultiWayIntegerDeque(m + 1, size);
            for (int i = 1; i <= m; i++) {
                for (int j = i; j <= m; j += i) {
                    if (!indexesOfSeq.isEmpty(j)) {
                        deque.addLast(i, j / i);
                    }
                }
            }

            long lcm = -1;
            int v1 = 0;
            int v2 = 0;

            for (int i = m; i >= 1; i--) {
                if (!indexesOfSeq.isEmpty(i) && indexesOfSeq.peekFirst(i) != indexesOfSeq.peekLast(i)) {
                    lcm = v1 = v2 = i;
                    break;
                }
            }

            IntegerVersionArray iva = new IntegerVersionArray(m + 1);
            IntegerDequeImpl stack = new IntegerDequeImpl(m);
            for (int i = 1; i <= m; i++) {
                iva.clear();
                stack.clear();
                while (!deque.isEmpty(i)) {
                    int last = deque.removeLast(i);
                    factorize(last);
                    int total = ie(iva, allFactors.size() - 1, 1, 0);
                    if (total > 0) {
                        int pop = 0;
                        while (total > 0) {
                            pop = stack.removeLast();
                            if (GCDs.gcd(pop, last) == 1) {
                                total--;
                            }
                            add(iva, pop, -1);
                        }
                        long l = LCMs.lcm(last, pop) * i;
                        if (l > lcm) {
                            lcm = l;
                            v1 = last * i;
                            v2 = pop * i;
                        }
                    }
                    add(iva, last, 1);
                    stack.addLast(last);
                }
            }

            return new int[]{indexesOfSeq.peekFirst(v1), indexesOfSeq.peekLast(v2)};
        }

        private void add(IntegerVersionArray cnts, int x, int c) {
            for (IntegerIterator iterator = factors.iterator(x); iterator.hasNext(); ) {
                int d = iterator.next();
                cnts.modify(d, c);
            }
        }

        private int ie(IntegerVersionArray cnts, int i, int divisor, int numberOfFactors) {
            if (i < 0) {
                int ans = cnts.get(divisor);
                if ((numberOfFactors & 1) == 1) {
                    ans = -ans;
                }
                return ans;
            }
            return ie(cnts, i - 1, divisor, numberOfFactors) +
                    ie(cnts, i - 1, divisor * allFactors.get(i),
                            numberOfFactors + 1);
        }

    }

    static interface IntegerStack {
    }

    static interface IntegerDeque extends IntegerStack {
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

    static class IntegerVersionArray {
        int[] data;
        int[] version;
        int now;
        int def;

        public IntegerVersionArray(int cap) {
            this(cap, 0);
        }

        public IntegerVersionArray(int cap, int def) {
            data = new int[cap];
            version = new int[cap];
            now = 0;
            this.def = def;
        }

        public void clear() {
            now++;
        }

        public void visit(int i) {
            if (version[i] < now) {
                version[i] = now;
                data[i] = def;
            }
        }

        public int get(int i) {
            visit(i);
            return data[i];
        }

        public int modify(int i, int x) {
            visit(i);
            return data[i] = data[i] + x;
        }

    }

    static interface IntegerIterator {
        boolean hasNext();

        int next();

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

    static class LCMs {
        private LCMs() {
        }

        public static long lcm(long x, long y) {
            return x / GCDs.gcd(x, y) * y;
        }

    }

    static class GCDs {
        private GCDs() {
        }

        public static long gcd(long a, long b) {
            return a >= b ? gcd0(a, b) : gcd0(b, a);
        }

        private static long gcd0(long a, long b) {
            return b == 0 ? a : gcd0(b, a % b);
        }

        public static int gcd(int a, int b) {
            return a >= b ? gcd0(a, b) : gcd0(b, a);
        }

        private static int gcd0(int a, int b) {
            return b == 0 ? a : gcd0(b, a % b);
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

        public FastOutput println(long c) {
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

    static class Factorization {
        public static MultiWayIntegerStack factorizeRangePrime(int n) {
            int size = 0;
            for (int i = 1; i <= n; i++) {
                size += n / i;
            }
            MultiWayIntegerStack stack = new MultiWayIntegerStack(n + 1, size);
            boolean[] isComp = new boolean[n + 1];
            for (int i = 2; i <= n; i++) {
                if (isComp[i]) {
                    continue;
                }
                for (int j = i; j <= n; j += i) {
                    isComp[j] = true;
                    stack.addLast(j, i);
                }
            }
            return stack;
        }

        public static MultiWayIntegerStack factorizeRange(int n) {
            int size = 0;
            for (int i = 1; i <= n; i++) {
                size += n / i;
            }
            MultiWayIntegerStack stack = new MultiWayIntegerStack(n + 1, size);
            for (int i = 1; i <= n; i++) {
                for (int j = i; j <= n; j += i) {
                    stack.addLast(j, i);
                }
            }
            return stack;
        }

    }

    static class MultiWayIntegerDeque {
        private int[] values;
        private int[] next;
        private int[] prev;
        private int[] heads;
        private int[] tails;
        private int alloc;
        private int queueNum;

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
            prev = Arrays.copyOf(prev, newSize);
            values = Arrays.copyOf(values, newSize);
        }

        public void alloc() {
            alloc++;
            if (alloc >= next.length) {
                doubleCapacity();
            }
            next[alloc] = 0;
        }

        public boolean isEmpty(int qId) {
            return heads[qId] == 0;
        }

        public MultiWayIntegerDeque(int qNum, int totalCapacity) {
            values = new int[totalCapacity + 1];
            next = new int[totalCapacity + 1];
            prev = new int[totalCapacity + 1];
            heads = new int[qNum];
            tails = new int[qNum];
            queueNum = qNum;
        }

        public void addLast(int qId, int x) {
            alloc();
            values[alloc] = x;

            if (heads[qId] == 0) {
                heads[qId] = tails[qId] = alloc;
                return;
            }
            next[tails[qId]] = alloc;
            prev[alloc] = tails[qId];
            tails[qId] = alloc;
        }

        public int peekFirst(int qId) {
            return values[heads[qId]];
        }

        public int peekLast(int qId) {
            return values[tails[qId]];
        }

        public int removeLast(int qId) {
            int ans = values[tails[qId]];
            if (heads[qId] == tails[qId]) {
                heads[qId] = tails[qId] = 0;
            } else {
                tails[qId] = prev[tails[qId]];
                next[tails[qId]] = 0;
            }
            return ans;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < queueNum; i++) {
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

        public void addAll(IntegerIterator iterator) {
            while (iterator.hasNext()) {
                add(iterator.next());
            }
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
                throw new ArrayIndexOutOfBoundsException("index " + i + " out of range");
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

    static class IntegerDequeImpl implements IntegerDeque {
        private int[] data;
        private int bpos;
        private int epos;
        private static final int[] EMPTY = new int[0];
        private int n;

        public IntegerDequeImpl(int cap) {
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
            bpos = 0;
            epos = 0;
            n = cap;
        }

        private void expandSpace(int len) {
            while (n < len) {
                n = Math.max(n + 10, n * 2);
            }
            int[] newData = new int[n];
            if (bpos <= epos) {
                if (bpos < epos) {
                    System.arraycopy(data, bpos, newData, 0, epos - bpos);
                }
            } else {
                System.arraycopy(data, bpos, newData, 0, data.length - bpos);
                System.arraycopy(data, 0, newData, data.length - bpos, epos);
            }
            epos = size();
            bpos = 0;
            data = newData;
        }

        public IntegerIterator iterator() {
            return new IntegerIterator() {
                int index = bpos;


                public boolean hasNext() {
                    return index != epos;
                }


                public int next() {
                    int ans = data[index];
                    index = IntegerDequeImpl.this.next(index);
                    return ans;
                }
            };
        }

        public int removeLast() {
            int ans = data[last(epos)];
            epos = last(epos);
            return ans;
        }

        public void addLast(int x) {
            ensureMore();
            data[epos] = x;
            epos = next(epos);
        }

        public void clear() {
            bpos = epos = 0;
        }

        private int last(int x) {
            return (x == 0 ? n : x) - 1;
        }

        private int next(int x) {
            return x + 1 >= n ? 0 : x + 1;
        }

        private void ensureMore() {
            if (next(epos) == bpos) {
                expandSpace(n + 1);
            }
        }

        public int size() {
            int ans = epos - bpos;
            if (ans < 0) {
                ans += data.length;
            }
            return ans;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (IntegerIterator iterator = iterator(); iterator.hasNext(); ) {
                builder.append(iterator.next()).append(' ');
            }
            return builder.toString();
        }

    }
}