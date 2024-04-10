import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Set;
import java.io.IOException;
import java.util.HashMap;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.util.Map;
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
            C2MadhouseHardVersion solver = new C2MadhouseHardVersion();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class C2MadhouseHardVersion {
        FastInput in;
        FastOutput out;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            this.in = in;
            this.out = out;

            int n = in.readInt();
            if (n == 1) {
                answer(actual(1));
                return;
            }

            int m = (n + 1) / 2;
            String left = actual(m);
            Map<Summary, Integer> total = ask(1, n);

            char[] ans = new char[n];
            Arrays.fill(ans, 'a');
            for (int i = 0; i < m; i++) {
                ans[i] = left.charAt(i);
            }

            Summary all = null;
            for (Summary s : total.keySet()) {
                if (s.sum == n) {
                    all = s;
                    total.remove(all);
                    break;
                }
            }

            Summary last = all;
            for (int i = n - 1; i >= m; i--) {
                Summary trace = new Summary(all);
                int j;
                for (j = 0; i + j - 1 < n - 1; j++) {
                    trace.dec(ans[j] - 'a');
                }
                for (; j >= 1; j--) {
                    remove(total, trace);
                    trace.inc(ans[j - 1] - 'a');
                    trace.dec(ans[i + j - 1] - 'a');
                }
                Summary now = null;
                for (Summary s : total.keySet()) {
                    if (s.sum == i) {
                        now = s;
                        total.remove(now);
                        break;
                    }
                }

                ans[i] = (char) (last.differIndex(now) + 'a');
                last = now;
            }

            answer(new String(ans));
        }

        public void remove(Map<Summary, Integer> total, Summary s) {
            int remain = total.get(s) - 1;
            if (remain == 0) {
                total.remove(s);
            } else {
                total.put(s, remain);
            }
        }

        public String actual(int m) {
            if (m == 1) {
                Map<Summary, Integer> map = ask(1, 1);
                String s = "" + (char) (map.keySet().iterator().next().differIndex(new Summary("")) + 'a');
                return s;
            }
            Map<Summary, Integer> h1 = ask(1, m);
            Map<Summary, Integer> h2 = ask(2, m);
            for (Summary s : h2.keySet()) {
                int remain = h1.get(s) - h2.get(s);
                if (remain == 0) {
                    h1.remove(s);
                } else {
                    h1.put(s, remain);
                }
            }

            List<Summary> list = new ArrayList<>(h1.keySet());
            list.sort((a, b) -> a.sum - b.sum);
            Summary last = new Summary("");
            StringBuilder ans = new StringBuilder(m);
            for (Summary s : list) {
                ans.append((char) (s.differIndex(last) + 'a'));
                last = s;
            }
            return ans.toString();
        }

        void answer(String ans) {
            out.printf("! %s", ans).println().flush();
        }

        Map<Summary, Integer> ask(int l, int r) {
            int n = r - l + 1;
            int m = n * (n + 1) / 2;
            Map<Summary, Integer> map = new HashMap<>(m);
            out.printf("? %d %d", l, r).println().flush();
            for (int i = 0; i < m; i++) {
                Summary s = new Summary(in.readString());
                map.put(s, map.getOrDefault(s, 0) + 1);
            }
            return map;
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

    static class FastOutput implements AutoCloseable, Closeable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput printf(String format, Object... args) {
            cache.append(String.format(format, args));
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

    }

    static class Summary {
        int[] cnts = new int['z' - 'a' + 1];
        int sum;

        public void dec(int i) {
            cnts[i]--;
            sum--;
        }

        public void inc(int i) {
            cnts[i]++;
            sum++;
        }

        public Summary(Summary model) {
            this.cnts = model.cnts.clone();
            this.sum = model.sum;
        }

        public Summary(String s) {
            sum = s.length();
            for (char c : s.toCharArray()) {
                cnts[c - 'a']++;
            }
        }

        public int differIndex(Summary s) {
            for (int i = 0; i < cnts.length; i++) {
                if (cnts[i] != s.cnts[i]) {
                    return i;
                }
            }
            return -1;
        }

        public int hashCode() {
            int hash = 1;
            for (int i = 0; i < cnts.length; i++) {
                hash = hash * 31 + cnts[i];
            }
            return hash;
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof Summary)) {
                return false;
            }
            Summary other = (Summary) obj;
            return SequenceUtils.equal(cnts, 0, cnts.length - 1,
                    other.cnts, 0, cnts.length - 1);
        }

    }
}