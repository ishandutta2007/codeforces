import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
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
            BLetsGoHiking solver = new BLetsGoHiking();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class BLetsGoHiking {
        int[] p;

        boolean isTop(int i) {
            boolean ans = true;
            if (i - 1 >= 0 && p[i - 1] > p[i]) {
                ans = false;
            }
            if (i + 1 < p.length && p[i + 1] > p[i]) {
                ans = false;
            }
            return ans;
        }

        boolean isBot(int i) {
            boolean ans = true;
            if (i - 1 >= 0 && p[i - 1] < p[i]) {
                ans = false;
            }
            if (i + 1 < p.length && p[i + 1] < p[i]) {
                ans = false;
            }
            return ans;
        }

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            p = in.ri(n);
            int[] leftTop = new int[n];
            int[] leftBot = new int[n];
            int[] rightTop = new int[n];
            int[] rightBot = new int[n];
            leftTop[0] = leftBot[0] = 0;
            for (int i = 1; i < n; i++) {
                leftTop[i] = isTop(i - 1) ? i - 1 : leftTop[i - 1];
                leftBot[i] = isBot(i - 1) ? i - 1 : leftBot[i - 1];
            }
            rightTop[n - 1] = rightBot[n - 1] = n - 1;
            for (int i = n - 2; i >= 0; i--) {
                rightTop[i] = isTop(i + 1) ? i + 1 : rightTop[i + 1];
                rightBot[i] = isBot(i + 1) ? i + 1 : rightBot[i + 1];
            }
            int[] leftDist = new int[n];
            int[] leftMaxDist = new int[n];
            int[] rightDist = new int[n];
            int[] rightMaxDist = new int[n];
            for (int i = 0; i < n; i++) {
                leftDist[i] = i - Math.max(leftBot[i], leftTop[i]);
                leftMaxDist[i] = leftDist[i];
                if (i > 0) {
                    leftMaxDist[i] = Math.max(leftMaxDist[i], leftMaxDist[i - 1]);
                }
            }
            for (int i = n - 1; i >= 0; i--) {
                rightDist[i] = Math.min(rightBot[i], rightTop[i]) - i;
                rightMaxDist[i] = rightDist[i];
                if (i + 1 < n) {
                    rightMaxDist[i] = Math.max(rightMaxDist[i], rightMaxDist[i + 1]);
                }
            }
            int ans = 0;
            for (int i = 0; i < n; i++) {
                if (!isTop(i)) {
                    continue;
                }
                if (leftDist[i] != rightDist[i]) {
                    continue;
                }
                if (leftDist[i] % 2 == 1) {
                    continue;
                }
                int leftPartner = leftBot[i];
                int rightPartner = rightBot[i];
                if (leftPartner >= 0 && leftMaxDist[leftPartner] >= leftDist[i]) {
                    continue;
                }
                if (rightPartner < n && rightMaxDist[rightPartner] >= leftDist[i]) {
                    continue;
                }
                ans++;
            }
            out.println(ans);
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
}