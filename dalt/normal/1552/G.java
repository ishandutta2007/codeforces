import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
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
            GASeriousReferee solver = new GASeriousReferee();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class GASeriousReferee {
        int n;
        long[] S;
        long[][] sortedS;
        int[] delta;
        boolean ok = true;
        long whole;

        public void dfs(int i, long bitset) {
            if (!ok) {
                return;
            }
            if (i == S.length) {
                int bc = Long.bitCount(bitset);
                if (bitset != (~Bits.headLongMask(n - bc) & whole)) {
                    ok = false;
                }
                return;
            }
            int cur = Long.bitCount(bitset & S[i]);
            long cleanBitset = bitset & ~S[i];
            for (int j = 0; j <= delta[i]; j++) {
                dfs(i + 1, cleanBitset | sortedS[i][j + cur]);
            }
        }

        public void solve(int testNumber, FastInput in, FastOutput out) {
            n = in.ri();
            whole = (1L << n) - 1;
            int k = in.ri();
            S = new long[k];
            sortedS = new long[k][];
            delta = new int[k];
            long prev = 0;
            for (int i = 0; i < k; i++) {
                int q = in.ri();
                for (int j = 0; j < q; j++) {
                    int index = in.ri() - 1;
                    S[i] |= 1L << index;
                }
                sortedS[i] = new long[q + 1];
                long v = S[i];
                for (int j = 1; j <= q; j++) {
                    sortedS[i][j] = sortedS[i][j - 1];
                    long highest = Long.highestOneBit(v);
                    v -= highest;
                    sortedS[i][j] |= highest;
                }
                delta[i] = Long.bitCount(S[i] ^ (S[i] & prev));
                prev |= S[i];
            }
            if (prev != whole && n > 1) {
                ok = false;
            }
            dfs(0, 0);

            if (ok) {
                out.println("ACCEPTED");
            } else {
                out.println("REJECTED");
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

    static class Bits {
        private Bits() {
        }

        public static long headLongMask(int n) {
            if (n == 0) {
                return 0;
            }
            return -1L >>> (64 - n);
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

        public FastOutput append(String c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(String c) {
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
}