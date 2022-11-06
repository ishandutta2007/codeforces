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
            EVasyaAndTemplates solver = new EVasyaAndTemplates();
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                solver.solve(i, in, out);
            out.close();
        }
    }

    static class EVasyaAndTemplates {
        int[] s = new int[1000000];
        int[] a = new int[1000000];
        int[] b = new int[1000000];
        int[] perm = new int[26];
        int[] used = new int[26];
        int n;
        int m;
        boolean valid;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            n = in.readInt();
            m = in.readString(s, 0);
            in.readString(a, 0);
            in.readString(b, 0);

            for (int i = 0; i < m; i++) {
                s[i] -= 'a';
                a[i] -= 'a';
                b[i] -= 'a';
            }

            Arrays.fill(perm, -1);
            Arrays.fill(used, -1);
            valid = true;
            handle(0, true, true, true);
            if (!valid) {
                Arrays.fill(perm, -1);
                Arrays.fill(used, -1);
                valid = true;
                handle(0, true, true, false);
            }

            if (!valid) {
                out.println("NO");
                return;
            }

            out.println("YES");
            for (int i = 0; i < n; i++) {
                out.append((char) (perm[i] + 'a'));
            }
            out.println();
        }

        private void check(int i, boolean bot, boolean top) {
            if (bot && perm[s[i]] < a[i]) {
                valid = false;
            }
            if (top && perm[s[i]] > b[i]) {
                valid = false;
            }
        }

        public void handle(int i, boolean bot, boolean top, boolean pickUp) {
            if (!valid) {
                return;
            }
            if (i >= m || (!bot && !top)) {
                int usedIter = 0;
                for (int j = 0; j < n; j++) {
                    if (perm[j] != -1) {
                        continue;
                    }
                    while (usedIter < n && used[usedIter] != -1) {
                        usedIter++;
                    }
                    perm[j] = usedIter++;
                }
                return;
            }

            if (perm[s[i]] != -1) {
                check(i, bot, top);
                handle(i + 1, perm[s[i]] == a[i] && bot, perm[s[i]] == b[i] && top, pickUp);
                return;
            }

            if (bot != top) {
                int j;
                if (bot) {
                    j = n - 1;
                    for (; used[j] != -1; j--) ;
                } else {
                    j = 0;
                    for (; used[j] != -1; j++) ;
                }
                perm[s[i]] = j;
                used[j] = s[i];
                check(i, bot, top);
                handle(i + 1, perm[s[i]] == a[i] && bot, perm[s[i]] == b[i] && top, pickUp);
                return;
            }

            int j = -1;
            if (pickUp) {
                for (int k = a[i]; k <= b[i]; k++) {
                    if (used[k] == -1 && (j == -1 || j == a[i])) {
                        j = k;
                    }
                }
            } else {
                for (int k = b[i]; k >= a[i]; k--) {
                    if (used[k] == -1 && (j == -1 || j == b[i])) {
                        j = k;
                    }
                }
            }
            if (j == -1) {
                valid = false;
                return;
            }
            perm[s[i]] = j;
            used[j] = s[i];

            handle(i + 1, perm[s[i]] == a[i] && bot, perm[s[i]] == b[i] && top, pickUp);
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

        public int readString(int[] data, int offset) {
            skipBlank();

            int originalOffset = offset;
            while (next > 32) {
                data[offset++] = (char) next;
                next = read();
            }

            return offset - originalOffset;
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

        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(String c) {
            cache.append(c).append('\n');
            return this;
        }

        public FastOutput println() {
            cache.append('\n');
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