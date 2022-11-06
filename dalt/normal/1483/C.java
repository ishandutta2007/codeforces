import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.util.function.Supplier;
import java.io.UncheckedIOException;
import java.util.function.Consumer;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;
import java.util.function.IntFunction;

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
            CSkylinePhoto solver = new CSkylinePhoto();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class CSkylinePhoto {
        static long inf = (long) 1e18;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int[] h = in.ri(n);
            int[] b = in.ri(n);
            int[] prev = new int[n];
            for (int i = 0; i < n; i++) {
                prev[i] = i - 1;
                while (prev[i] >= 0 && h[prev[i]] > h[i]) {
                    prev[i] = prev[prev[i]];
                }
            }
            SegTree<SumImpl, UpdateImpl> st = new SegTree<>(0, n,
                    SumImpl::new, UpdateImpl::new,
                    i -> {
                        SumImpl ans = new SumImpl();
                        ans.a = -inf;
                        ans.max = -inf;
                        return ans;
                    });
            UpdateImpl upd = new UpdateImpl();
            SumImpl sum = new SumImpl();
            upd.setA = 0;
            upd.setB = 0;
            st.update(0, 0, 0, n, upd);
            for (int i = 0; i < n; i++) {
                int last = prev[i] + 1;
                upd.clear();
                upd.setB = b[i];
                st.update(last, i, 0, n, upd);
                sum.clear();
                st.query(0, i, 0, n, sum);
                if (i == n - 1) {
                    out.println(sum.max);
                    return;
                }
                upd.setA = sum.max;
                upd.setB = 0;
                st.update(i + 1, i + 1, 0, n, upd);
            }
        }

    }

    static interface Sum<S, U> extends Cloneable {
        void add(S s);

        void update(U u);

        void copy(S s);

        S clone();

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int floorAverage(int x, int y) {
            return (x & y) + ((x ^ y) >> 1);
        }

    }

    static class SegTree<S extends Sum<S, U>, U extends Update<U>> implements Cloneable {
        private SegTree<S, U> left;
        private SegTree<S, U> right;
        public S sum;
        private U update;

        private void modify(U x) {
            update.update(x);
            sum.update(x);
        }

        private void pushDown() {
            if (update.ofBoolean()) {
                left.modify(update);
                right.modify(update);
                update.clear();
                assert !update.ofBoolean();
            }
        }

        private void pushUp() {
            sum.copy(left.sum);
            sum.add(right.sum);
        }

        public SegTree(int l, int r, Supplier<S> sSupplier, Supplier<U> uSupplier,
                       IntFunction<S> func) {
            update = uSupplier.get();
            update.clear();
            if (l < r) {
                sum = sSupplier.get();
                int m = DigitUtils.floorAverage(l, r);
                left = new SegTree<>(l, m, sSupplier, uSupplier, func);
                right = new SegTree<>(m + 1, r, sSupplier, uSupplier, func);
                pushUp();
            } else {
                sum = func.apply(l);
            }
        }

        private boolean cover(int L, int R, int l, int r) {
            return L <= l && R >= r;
        }

        private boolean leave(int L, int R, int l, int r) {
            return R < l || L > r;
        }

        public void update(int L, int R, int l, int r, U u) {
            if (leave(L, R, l, r)) {
                return;
            }
            if (cover(L, R, l, r)) {
                modify(u);
                return;
            }
            int m = DigitUtils.floorAverage(l, r);
            pushDown();
            left.update(L, R, l, m, u);
            right.update(L, R, m + 1, r, u);
            pushUp();
        }

        public void query(int L, int R, int l, int r, S s) {
            if (leave(L, R, l, r)) {
                return;
            }
            if (cover(L, R, l, r)) {
                s.add(sum);
                return;
            }
            int m = DigitUtils.floorAverage(l, r);
            pushDown();
            left.query(L, R, l, m, s);
            right.query(L, R, m + 1, r, s);
        }

        public SegTree<S, U> deepClone() {
            SegTree<S, U> clone = clone();
            clone.sum = clone.sum.clone();
            clone.update = clone.update.clone();
            if (clone.left != null) {
                clone.left = clone.left.deepClone();
                clone.right = clone.right.deepClone();
            }
            return clone;
        }

        public void visitLeave(Consumer<SegTree<S, U>> consumer) {
            if (left == null) {
                consumer.accept(this);
                return;
            }
            pushDown();
            left.visitLeave(consumer);
            right.visitLeave(consumer);
        }

        public String toString() {
            StringBuilder ans = new StringBuilder();
            deepClone().visitLeave(x -> ans.append(x.sum).append(' '));
            return ans.toString();
        }

        public SegTree<S, U> clone() {
            try {
                return (SegTree<S, U>) super.clone();
            } catch (CloneNotSupportedException e) {
                throw new UnsupportedOperationException(e);
            }
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

    }

    static interface Update<U extends Update<U>> extends Cloneable {
        void update(U u);

        void clear();

        boolean ofBoolean();

        U clone();

    }

    static class SumImpl implements Sum<SumImpl, UpdateImpl> {
        long a;
        long max;
        static long inf = (long) 1e18;

        public void clear() {
            a = max = -inf;
        }

        public void add(SumImpl sum) {
            a = Math.max(a, sum.a);
            max = Math.max(max, sum.max);
        }

        public void update(UpdateImpl update) {
            if (update.setA != UpdateImpl.unset) {
                a = update.setA;
            }
            if (update.setB != UpdateImpl.unset) {
                max = a + update.setB;
            }
        }

        public void copy(SumImpl sum) {
            a = sum.a;
            max = sum.max;
        }

        public SumImpl clone() {
            SumImpl ans = new SumImpl();
            ans.copy(this);
            return this;
        }

    }

    static class UpdateImpl extends CloneSupportObject<UpdateImpl> implements Update<UpdateImpl> {
        static long unset = Long.MIN_VALUE;
        long setA;
        long setB;

        public void update(UpdateImpl update) {
            if (update.setA != unset) {
                setA = update.setA;
            }
            if (update.setB != unset) {
                setB = update.setB;
            }
        }

        public void clear() {
            setA = setB = unset;
        }

        public boolean ofBoolean() {
            return !(setA == unset && setB == unset);
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

        public FastOutput append(long c) {
            cache.append(c);
            afterWrite();
            return this;
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

    static abstract class CloneSupportObject<T> implements Cloneable {
        public T clone() {
            try {
                return (T) super.clone();
            } catch (CloneNotSupportedException e) {
                throw new RuntimeException(e);
            }
        }

    }
}