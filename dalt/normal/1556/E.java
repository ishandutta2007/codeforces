import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.function.Supplier;
import java.util.function.IntFunction;
import java.io.OutputStream;
import java.io.PrintStream;
import java.io.IOException;
import java.lang.reflect.Field;
import java.nio.charset.StandardCharsets;
import java.io.UncheckedIOException;
import java.util.function.Consumer;
import java.io.Closeable;
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
            EEquilibrium solver = new EEquilibrium();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class EEquilibrium {
        Debug debug = new Debug(false);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int q = in.ri();
            long[] ab = new long[n];
            for (int i = 0; i < n; i++) {
                ab[i] -= in.ri();
            }
            for (int i = 0; i < n; i++) {
                ab[i] += in.ri();
            }
            SegTree<SumImpl, Update.NIL> st = new SegTree<>(0, n - 1, SumImpl::new,
                    Update.NIL.SUPPLIER,
                    i -> {
                        SumImpl s = new SumImpl();
                        s.maxPs = Math.max(0, ab[i]);
                        s.minPs = Math.min(0, ab[i]);
                        s.ps = ab[i];
                        return s;
                    });


            debug.debug("ab", ab);
            SumImpl sum = new SumImpl();
            for (int i = 0; i < q; i++) {
                int l = in.ri() - 1;
                int r = in.ri() - 1;
                sum.clear();
                st.query(l, r, 0, n - 1, sum);
                if (sum.minPs < 0 || sum.ps != 0) {
                    out.println(-1);
                } else {
                    out.println(sum.maxPs);
                }
            }
        }

    }

    static interface Sum<S> {
        void add(S s);

        void copy(S s);

        S clone();

    }

    static class SumImpl implements UpdatableSum<SumImpl, Update.NIL> {
        long ps;
        long minPs;
        long maxPs;

        void clear() {
            ps = minPs = maxPs = 0;
        }

        public void add(SumImpl sum) {
            minPs = Math.min(minPs, ps + sum.minPs);
            maxPs = Math.max(maxPs, ps + sum.maxPs);
            ps += sum.ps;
        }

        public void copy(SumImpl sum) {
            ps = sum.ps;
            minPs = sum.minPs;
            maxPs = sum.maxPs;
        }

        public SumImpl clone() {
            SumImpl ans = new SumImpl();
            ans.copy(this);
            return ans;
        }

        public void update(Update.NIL nil) {

        }

        public String toString() {
            return "" + ps;
        }

    }

    static class SegTree<S extends UpdatableSum<S, U>, U extends Update<U>> implements Cloneable {
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
            boolean rev = false;

            skipBlank();
            if (next == '+' || next == '-') {
                rev = next == '-';
                next = read();
            }

            int val = 0;
            while (next >= '0' && next <= '9') {
                val = val * 10 - next + '0';
                next = read();
            }

            return rev ? val : -val;
        }

    }

    static class Debug {
        private boolean offline;
        private PrintStream out = System.err;
        static int[] empty = new int[0];

        public Debug(boolean enable) {
            offline = enable && System.getSecurityManager() == null;
        }

        public Debug debug(String name, Object x) {
            return debug(name, x, empty);
        }

        public Debug debug(String name, Object x, int... indexes) {
            if (offline) {
                if (x == null || !x.getClass().isArray()) {
                    out.append(name);
                    for (int i : indexes) {
                        out.printf("[%d]", i);
                    }
                    out.append("=").append("" + x);
                    out.println();
                } else {
                    indexes = Arrays.copyOf(indexes, indexes.length + 1);
                    if (x instanceof byte[]) {
                        byte[] arr = (byte[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof short[]) {
                        short[] arr = (short[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof boolean[]) {
                        boolean[] arr = (boolean[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof char[]) {
                        char[] arr = (char[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof int[]) {
                        int[] arr = (int[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof float[]) {
                        float[] arr = (float[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof double[]) {
                        double[] arr = (double[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else if (x instanceof long[]) {
                        long[] arr = (long[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    } else {
                        Object[] arr = (Object[]) x;
                        for (int i = 0; i < arr.length; i++) {
                            indexes[indexes.length - 1] = i;
                            debug(name, arr[i], indexes);
                        }
                    }
                }
            }
            return this;
        }

    }

    static interface Update<U extends Update<U>> extends Cloneable {
        void update(U u);

        void clear();

        boolean ofBoolean();

        U clone();

        static class NIL implements Update<Update.NIL> {
            public static final Update.NIL INSTANCE = new Update.NIL();
            public static final Supplier<Update.NIL> SUPPLIER = () -> INSTANCE;

            private NIL() {
            }

            public void update(Update.NIL nilUpdate) {
            }

            public void clear() {
            }

            public boolean ofBoolean() {
                return false;
            }

            public Update.NIL clone() {
                return this;
            }

        }

    }

    static interface UpdatableSum<S, U> extends Cloneable, Sum<S> {
        void update(U u);

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private static final int THRESHOLD = 32 << 10;
        private OutputStream writer;
        private StringBuilder cache = new StringBuilder(THRESHOLD * 2);
        private static Field stringBuilderValueField;
        private char[] charBuf = new char[THRESHOLD * 2];
        private byte[] byteBuf = new byte[THRESHOLD * 2];

        static {
            try {
                stringBuilderValueField = StringBuilder.class.getSuperclass().getDeclaredField("value");
                stringBuilderValueField.setAccessible(true);
            } catch (Exception e) {
                stringBuilderValueField = null;
            }
            stringBuilderValueField = null;
        }

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

        public FastOutput(OutputStream writer) {
            this.writer = writer;
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
                if (stringBuilderValueField != null) {
                    try {
                        byte[] value = (byte[]) stringBuilderValueField.get(cache);
                        writer.write(value, 0, cache.length());
                    } catch (Exception e) {
                        stringBuilderValueField = null;
                    }
                }
                if (stringBuilderValueField == null) {
                    int n = cache.length();
                    if (n > byteBuf.length) {
                        //slow
                        writer.write(cache.toString().getBytes(StandardCharsets.UTF_8));
//                writer.append(cache);
                    } else {
                        cache.getChars(0, n, charBuf, 0);
                        for (int i = 0; i < n; i++) {
                            byteBuf[i] = (byte) charBuf[i];
                        }
                        writer.write(byteBuf, 0, n);
                    }
                }
                writer.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
            return this;
        }

        public void close() {
            flush();
            try {
                writer.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

        public String toString() {
            return cache.toString();
        }

    }

    static class DigitUtils {
        private DigitUtils() {
        }

        public static int floorAverage(int x, int y) {
            return (x & y) + ((x ^ y) >> 1);
        }

    }
}