import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.util.Random;
import java.lang.reflect.Field;
import java.nio.charset.StandardCharsets;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.math.BigInteger;
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
            DTopNotchInsertions solver = new DTopNotchInsertions();
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                solver.solve(i, in, out);
            out.close();
        }
    }

    static class DTopNotchInsertions {
        int mod = 998244353;
        Combination comb = new Combination((int) 5e5, mod);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int m = in.ri();
            Treap root = Treap.NIL;

            for (int i = 0; i < m; i++) {
                int x = in.ri() - 1;
                int y = in.ri();
                Treap[] p = Treap.splitByKey(root, y - 1);
                Treap first = first(p[1]);
                if (first == Treap.NIL || first.key > y) {
                    Treap newNode = new Treap();
                    newNode.key = y;
                    newNode.pushUp();
                    p[1] = Treap.merge(newNode, p[1]);
                }
                p[1].modify(1);
                root = Treap.merge(p[0], p[1]);
            }
            int smallCnt = root.size + 1;

            if (smallCnt > n) {
                out.println(0);
                return;
            }

            int remain = n - smallCnt;
            int var = n + 1;
            long way = comb.combination(remain + var - 1, var - 1);
            out.println(way);
        }

        public Treap first(Treap t) {
            if (t == Treap.NIL) {
                return Treap.NIL;
            }
            t.pushDown();
            while (t.left != Treap.NIL) {
                t = t.left;
                t.pushDown();
            }
            return t;
        }

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

    static class Factorial {
        int[] fact;
        int[] inv;
        int mod;

        public int getMod() {
            return mod;
        }

        public Factorial(int[] fact, int[] inv, int mod) {
            this.mod = mod;
            this.fact = fact;
            this.inv = inv;
            fact[0] = inv[0] = 1;
            int n = Math.min(fact.length, mod);
            for (int i = 1; i < n; i++) {
                fact[i] = i;
                fact[i] = (int) ((long) fact[i] * fact[i - 1] % mod);
            }
            if (n - 1 >= 0) {
                inv[n - 1] = BigInteger.valueOf(fact[n - 1]).modInverse(BigInteger.valueOf(mod)).intValue();
            }
            for (int i = n - 2; i >= 1; i--) {
                inv[i] = (int) ((long) inv[i + 1] * (i + 1) % mod);
            }
        }

        public Factorial(int limit, int mod) {
            this(new int[Math.min(limit + 1, mod)], new int[Math.min(limit + 1, mod)], mod);
        }

        public int fact(int n) {
            if (n >= mod) {
                return 0;
            }
            return fact[n];
        }

        public int invFact(int n) {
            if (n >= mod) {
                throw new IllegalArgumentException();
            }
            return inv[n];
        }

    }

    static class Combination implements IntCombination {
        final Factorial factorial;
        int modVal;

        public Combination(Factorial factorial) {
            this.factorial = factorial;
            this.modVal = factorial.getMod();
        }

        public Combination(int limit, int mod) {
            this(new Factorial(limit, mod));
        }

        public int combination(int m, int n) {
            if (n > m || n < 0) {
                return 0;
            }
            return (int) ((long) factorial.fact(m) * factorial.invFact(n) % modVal * factorial.invFact(m - n) % modVal);
        }

    }

    static class RandomWrapper {
        private Random random;
        public static final RandomWrapper INSTANCE = new RandomWrapper();

        public RandomWrapper() {
            this(new Random());
        }

        public RandomWrapper(Random random) {
            this.random = random;
        }

        public RandomWrapper(long seed) {
            this(new Random(seed));
        }

        public int nextInt(int n) {
            return random.nextInt(n);
        }

    }

    static interface IntCombination {
    }

    static class Treap implements Cloneable {
        public static final Treap NIL = new Treap();
        public Treap left = NIL;
        public Treap right = NIL;
        public int size = 1;
        public int key;
        public int mod;

        static {
            NIL.left = NIL.right = NIL;
            NIL.size = 0;
        }

        public Treap clone() {
            try {
                return (Treap) super.clone();
            } catch (CloneNotSupportedException e) {
                throw new RuntimeException(e);
            }
        }

        public void modify(int x) {
            if (this == NIL) {
                return;
            }
            mod += x;
            key += x;
        }

        public void pushDown() {
            if (this == NIL) {
                return;
            }
            if (mod != 0) {
                left.modify(mod);
                right.modify(mod);
                mod = 0;
            }
        }

        public void pushUp() {
            if (this == NIL) {
                return;
            }
            size = left.size + right.size + 1;
        }

        public static Treap merge(Treap a, Treap b) {
            if (a == NIL) {
                return b;
            }
            if (b == NIL) {
                return a;
            }
            if (RandomWrapper.INSTANCE.nextInt(a.size + b.size) < a.size) {
                a.pushDown();
                a.right = merge(a.right, b);
                a.pushUp();
                return a;
            } else {
                b.pushDown();
                b.left = merge(a, b.left);
                b.pushUp();
                return b;
            }
        }

        public static void toString(Treap root, StringBuilder builder) {
            if (root == NIL) {
                return;
            }
            root.pushDown();
            toString(root.left, builder);
            builder.append(root.key).append(',');
            toString(root.right, builder);
        }

        public static Treap clone(Treap root) {
            if (root == NIL) {
                return NIL;
            }
            Treap clone = root.clone();
            clone.left = clone(root.left);
            clone.right = clone(root.right);
            return clone;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder().append(key).append(":");
            toString(clone(this), builder);
            return builder.toString();
        }

        public static Treap[] splitByKey(Treap root, int key) {
            if (root == NIL) {
                return new Treap[]{NIL, NIL};
            }
            root.pushDown();
            Treap[] result;
            if (root.key > key) {
                result = splitByKey(root.left, key);
                root.left = result[1];
                result[1] = root;
            } else {
                result = splitByKey(root.right, key);
                root.right = result[0];
                result[0] = root;
            }
            root.pushUp();
            return result;
        }

    }
}