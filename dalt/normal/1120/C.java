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
 * Built using CHelper plug-in Actual solution is at the top
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
            TaskC solver = new TaskC();
            solver.solve(1, in, out);
            out.close();
        }
    }
    static class TaskC {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int a = in.readInt();
            int b = in.readInt();

            char[] s = new char[n];
            in.readString(s, 0);

            boolean[][] isSubstring = new boolean[n][n];
            SuffixAutomaton sa = new SuffixAutomaton('a', 'z');
            sa.build(s[0]);
            for (int i = 1; i < n; i++) {
                sa.beginMatch();
                for (int j = i; j < n; j++) {
                    sa.match(s[j]);
                    if (sa.lengthMatch() != j - i + 1) {
                        break;
                    }
                    isSubstring[i][j] = true;
                }
                sa.build(s[i]);
            }

            long[] dp = new long[n];
            dp[0] = a;
            for (int i = 1; i < n; i++) {
                dp[i] = dp[i - 1] + a;
                for (int j = 0; j <= i; j++) {
                    if (isSubstring[j][i]) {
                        dp[i] = Math.min(dp[i], dp[j - 1] + b);
                    }
                }
            }

            out.println(dp[n - 1]);
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

        public int readString(char[] data, int offset) {
            skipBlank();

            int originalOffset = offset;
            while (next > 32) {
                data[offset++] = (char) next;
                next = read();
            }

            return offset - originalOffset;
        }

    }
    static class SuffixAutomaton {
        final int minCharacter;
        final int maxCharacter;
        final int alphabet;
        SuffixAutomaton.Node root;
        SuffixAutomaton.Node buildLast;
        SuffixAutomaton.Node matchLast;
        int matchLength;

        public int lengthMatch() {
            return matchLength;
        }

        public SuffixAutomaton(int minCharacter, int maxCharacter) {
            this.minCharacter = minCharacter;
            this.maxCharacter = maxCharacter;
            alphabet = maxCharacter - minCharacter + 1;
            buildLast = root = new SuffixAutomaton.Node(alphabet);
            root.fail = null;
        }

        public void beginMatch() {
            matchLast = root;
            matchLength = 0;
        }

        public void match(char c) {
            int index = c - minCharacter;
            if (matchLast.next[index] != null) {
                matchLast = matchLast.next[index];
                matchLength = matchLength + 1;
                return;
            }
            while (matchLast != null && matchLast.next[index] == null) {
                matchLast = matchLast.fail;
            }
            if (matchLast == null) {
                matchLast = root;
                matchLength = 0;
            } else {
                matchLength = matchLast.maxlen + 1;
                matchLast = matchLast.next[index];
            }
        }

        public void build(char c) {
            int index = c - minCharacter;
            SuffixAutomaton.Node now = new SuffixAutomaton.Node(alphabet);
            now.maxlen = buildLast.maxlen + 1;

            SuffixAutomaton.Node p = visit(index, buildLast, null, now);
            if (p == null) {
                now.fail = root;
            } else {
                SuffixAutomaton.Node q = p.next[index];
                if (q.maxlen == p.maxlen + 1) {
                    now.fail = q;
                } else {
                    SuffixAutomaton.Node clone = q.clone();
                    clone.maxlen = p.maxlen + 1;

                    now.fail = q.fail = clone;
                    visit(index, p, q, clone);
                }
            }

            buildLast = now;
        }

        public SuffixAutomaton.Node visit(int index, SuffixAutomaton.Node trace, SuffixAutomaton.Node target,
                        SuffixAutomaton.Node replacement) {
            while (trace != null && trace.next[index] == target) {
                trace.next[index] = replacement;
                trace = trace.fail;
            }
            return trace;
        }

        public static class Node implements Cloneable {
            SuffixAutomaton.Node[] next;
            SuffixAutomaton.Node fail;
            int maxlen;

            public Node(int alphabet) {
                next = new SuffixAutomaton.Node[alphabet];
            }

            public SuffixAutomaton.Node clone() {
                try {
                    SuffixAutomaton.Node res = (SuffixAutomaton.Node) super.clone();
                    res.next = res.next.clone();
                    return res;
                } catch (CloneNotSupportedException e) {
                    throw new RuntimeException(e);
                }
            }

        }

    }
}