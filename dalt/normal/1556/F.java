import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.io.IOException;
import java.lang.reflect.Field;
import java.nio.charset.StandardCharsets;
import java.io.UncheckedIOException;
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
            FSportsBetting solver = new FSportsBetting();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FSportsBetting {
        int mod = (int) 1e9 + 7;
        Power pow = new Power(mod);
        Debug debug = new Debug(false);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int[] a = in.ri(n);
            long[] I = new long[1 << n];
            long[] invI = new long[1 << n];
            long[][] fp = new long[n][n];
            for (int i = 0; i < n; i++) {
                fp[i][0] = 1;
                for (int j = 1; j < n; j++) {
                    fp[i][j] = fp[i][j - 1] * a[i] % mod;
                }
            }
            long[][] subsetfp = new long[n][1 << n];
            for (int j = 0; j < n; j++) {
                subsetfp[j][0] = 1;
            }
            for (int i = 1; i < 1 << n; i++) {
                int lb = Integer.lowestOneBit(i);
                int log = Log2.floorLog(lb);
                for (int j = 0; j < n; j++) {
                    subsetfp[j][i] = subsetfp[j][i - lb] * fp[log][j] % mod;
                }
            }
            I[0] = 1;
            invI[0] = 1;
            for (int i = 1; i < 1 << n; i++) {
                int lb = Integer.lowestOneBit(i);
                int log = Log2.floorLog(lb);
                I[i] = I[i - lb];
                for (int j = 0; j < n; j++) {
                    if (Bits.get(i, j) == 0 || j == log) {
                        continue;
                    }
                    I[i] = I[i] * (a[log] + a[j]) % mod;
                }
                invI[i] = pow.inverse((int) I[i]);
            }
            debug.debug("I", I);
            long[] f = new long[1 << n];
            f[0] = 1;
            for (int i = 1; i < 1 << n; i++) {
                int lb = Integer.lowestOneBit(i);
                if (lb == i) {
                    f[i] = 1;
                    continue;
                }
                long invalid = 0;
                int subset = i;
                while (subset > 0) {
                    subset = (subset - 1) & i;
                    if (subset == 0) {
                        continue;
                    }
                    int other = i - subset;
                    int remain = FastBitCount2.count(other);
                    invalid += f[subset] * subsetfp[remain][subset] % mod
                            * I[other] % mod;
                }
                invalid %= mod;
                f[i] = I[i] - invalid;
                f[i] = DigitUtils.mod(f[i], mod);
            }
            debug.debug("f", f);
            long[] prob = new long[n];
            int mask = (1 << n) - 1;
            for (int i = 1; i < 1 << n; i++) {
                int other = mask - i;
                int remain = FastBitCount2.count(other);
                long p = f[i] * subsetfp[remain][i] % mod * I[other] % mod;
                for (int j = 0; j < n; j++) {
                    if (Bits.get(i, j) == 0) {
                        continue;
                    }
                    prob[j] += p;
                }
            }
            debug.debug("prob", prob);
            long ans = 0;
            for (int i = 0; i < n; i++) {
                ans += prob[i] % mod;
            }
            debug.debug("3/2", 3L * pow.inverse(2) % mod);
            ans = ans % mod * invI[mask] % mod;
            ans = DigitUtils.mod(ans, mod);
            out.println(ans);
        }

    }

    static class SequenceUtils {
        public static void swap(long[] data, int i, int j) {
            long tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

    }

    static class Log2 {
        public static int floorLog(int x) {
            if (x <= 0) {
                throw new IllegalArgumentException();
            }
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

        public Debug debug(String name, long x) {
            if (offline) {
                debug(name, "" + x);
            }
            return this;
        }

        public Debug debug(String name, String x) {
            if (offline) {
                out.printf("%s=%s", name, x);
                out.println();
            }
            return this;
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

    static class ExtGCD {
        public static long extGCD(long a, long b, long[] xy) {
            if (a >= b) {
                return extGCD0(a, b, xy);
            }
            long ans = extGCD0(b, a, xy);
            SequenceUtils.swap(xy, 0, 1);
            return ans;
        }

        private static long extGCD0(long a, long b, long[] xy) {
            if (b == 0) {
                xy[0] = 1;
                xy[1] = 0;
                return a;
            }
            long ans = extGCD0(b, a % b, xy);
            long x = xy[0];
            long y = xy[1];
            xy[0] = y;
            xy[1] = x - a / b * y;
            return ans;
        }

    }

    static class FastBitCount2 {
        private static byte[] size = new byte[1 << 16];
        static final int MASK = (1 << 16) - 1;

        static {
            for (int i = 0; i < size.length; i++) {
                size[i] = (byte) Integer.bitCount(i);
            }
        }

        public static int count(int x) {
            return size[x & MASK] + size[(x >>> 16) & MASK];
        }

    }

    static class Power implements InverseNumber {
        int mod;

        public Power(int mod) {
            this.mod = mod;
        }

        public int inverse(int x) {
            int ans = inverseExtGCD(x);
//        if(modular.mul(ans, x) != 1){
//            throw new IllegalStateException();
//        }
            return ans;
        }

        public int inverseExtGCD(int x) {
            return (int) DigitUtils.modInverse(x, mod);
        }

    }

    static class Bits {
        private Bits() {
        }

        public static int get(int x, int i) {
            return (x >>> i) & 1;
        }

    }

    static class LongExtGCDObject {
        private long[] xy = new long[2];

        public long extgcd(long a, long b) {
            return ExtGCD.extGCD(a, b, xy);
        }

        public long getX() {
            return xy[0];
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
        private static LongExtGCDObject longExtGCDObject = new LongExtGCDObject();

        private DigitUtils() {
        }

        public static int mod(long x, int mod) {
            if (x < -mod || x >= mod) {
                x %= mod;
            }
            if (x < 0) {
                x += mod;
            }
            return (int) x;
        }

        public static long mod(long x, long mod) {
            if (x < -mod || x >= mod) {
                x %= mod;
            }
            if (x < 0) {
                x += mod;
            }
            return x;
        }

        public static long modInverse(long x, long mod) {
            long g = longExtGCDObject.extgcd(x, mod);
            assert g == 1;
            long a = longExtGCDObject.getX();
            return DigitUtils.mod(a, mod);
        }

    }

    static interface InverseNumber {
    }
}