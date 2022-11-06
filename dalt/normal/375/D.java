

import java.io.*;
import java.nio.charset.Charset;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class CF375D {
    public static void main(String[] args) throws FileNotFoundException {
        boolean local = System.getProperty("ONLINE_JUDGE") == null;
        IOUtil io;
        if (local) {
            io = new IOUtil(new FileInputStream("E:\\DATABASE\\TESTCASE\\CF375D.in"), new FileOutputStream("E:\\DATABASE\\TESTCASE\\CF375D.out"));
        } else {
            io = new IOUtil(System.in, System.out);
        }

        Task task = new Task(io);
        task.run();
        io.flush();
    }

    public static class Task implements Runnable {
        IOUtil io;

        public Task(IOUtil io) {
            this.io = io;
        }

        @Override
        public void run() {
            int n = io.readInt();
            int m = io.readInt();

            Node[] nodes = new Node[n + 1];
            for (int i = 1; i <= n; i++) {
                nodes[i] = new Node();
                nodes[i].color = io.readInt();
            }

            for (int i = 1; i < n; i++) {
                Node a = nodes[io.readInt()];
                Node b = nodes[io.readInt()];
                a.children.add(b);
                b.children.add(a);
            }

            List<Node> seq = new ArrayList<>(n);
            flat(nodes[1], null, seq);

            Node[] seqArray = seq.toArray(new Node[0]);
            QueryImpl[] queries = new QueryImpl[m];
            for (int i = 0; i < m; i++) {
                queries[i] = new QueryImpl(nodes[io.readInt()], io.readInt());
            }

            MDAlgorithm<Node> md = new MDAlgorithm<>();
            md.setData(seqArray);
            md.setInterval(new IntervalImpl());
            md.setQueries(queries);

            md.solve();

            for (int i = 0; i < m; i++) {
                io.write(queries[i].answer);
                io.write('\n');
            }
        }

        public static void flat(Node root, Node father, List<Node> list) {
            root.dfn = list.size();
            list.add(root);

            for (Node child : root.children) {
                if (child == father) {
                    continue;
                }
                flat(child, root, list);
            }

            root.maxDfnOfSubtree = list.size() - 1;
        }
    }

    public static class Node {
        List<Node> children = new ArrayList<>(1);
        int dfn;
        int maxDfnOfSubtree;
        int color;
    }

    public static class IntervalImpl implements MDAlgorithm.Interval<Node> {
        static final int LIMIT = 100000;
        int[] colorCnt = new int[LIMIT + 1];
        int[] suffixCnt = new int[LIMIT + 1];

        @Override
        public void add(Node add) {
            int c = add.color;
            int cnt = colorCnt[c];

            colorCnt[c] = ++cnt;
            suffixCnt[cnt]++;
        }

        @Override
        public void remove(Node remove) {
            int c = remove.color;
            int cnt = colorCnt[c];

            suffixCnt[cnt]--;
            colorCnt[c] = --cnt;
        }

        @Override
        public void clear() {
            Arrays.fill(colorCnt, 0);
            Arrays.fill(suffixCnt, 0);
            suffixCnt[0] = (int) 1e8;
        }

        public int summary(QueryImpl query) {
            return suffixCnt[query.k];
        }
    }

    public static class QueryImpl implements MDAlgorithm.Queries<Node> {
        final Node node;
        final int k;
        int answer;


        public QueryImpl(Node node, int k) {
            this.node = node;
            this.k = k;
        }

        @Override
        public void setAnswer(MDAlgorithm.Interval<Node> interval) {
            answer = ((IntervalImpl) interval).summary(this);
        }

        @Override
        public int getLeft() {
            return node.dfn;
        }

        @Override
        public int getRight() {
            return node.maxDfnOfSubtree;
        }
    }

    public static class Mathematics {
        /**
         * Get the greatest common divisor of a and b
         */
        public static int gcd(int a, int b) {
            return a >= b ? gcd0(a, b) : gcd0(b, a);
        }

        private static int gcd0(int a, int b) {
            return b == 0 ? a : gcd0(b, a % b);
        }

        public static int extgcd(int a, int b, int[] coe) {
            return a >= b ? extgcd0(a, b, coe) : extgcd0(b, a, coe);
        }

        private static int extgcd0(int a, int b, int[] coe) {
            if (b == 0) {
                coe[0] = 1;
                coe[1] = 0;
                return a;
            }
            int g = extgcd0(b, a % b, coe);
            int n = coe[0];
            int m = coe[1];
            coe[0] = m;
            coe[1] = n - m * (a / b);
            return g;
        }

        /**
         * Get the greatest common divisor of a and b
         */
        public static long gcd(long a, long b) {
            return a >= b ? gcd0(a, b) : gcd0(b, a);
        }

        private static long gcd0(long a, long b) {
            return b == 0 ? a : gcd0(b, a % b);
        }

        public static long extgcd(long a, long b, long[] coe) {
            return a >= b ? extgcd0(a, b, coe) : extgcd0(b, a, coe);
        }

        private static long extgcd0(long a, long b, long[] coe) {
            if (b == 0) {
                coe[0] = 1;
                coe[1] = 0;
                return a;
            }
            long g = extgcd0(b, a % b, coe);
            long n = coe[0];
            long m = coe[1];
            coe[0] = m;
            coe[1] = n - m * (a / b);
            return g;
        }

        /**
         * Get y where x * y = 1 (% mod)
         */
        public static int inverse(int x, int mod) {
            return pow(x, mod - 2, mod);
        }

        /**
         * Get x^n(% mod)
         */
        public static int pow(int x, int n, int mod) {
            n = mod(n, mod - 1);
            x = mod(x, mod);
            int bit = 31 - Integer.numberOfLeadingZeros(n);
            long product = 1;
            for (; bit >= 0; bit--) {
                product = product * product % mod;
                if (((1 << bit) & n) != 0) {
                    product = product * x % mod;
                }
            }
            return (int) product;
        }

        /**
         * Get x % mod
         */
        public static int mod(int x, int mod) {
            return x >= 0 ? x % mod : (((x % mod) + mod) % mod);
        }

        /**
         * Get n!/(n-m)!
         */
        public static long permute(int n, int m) {
            return m == 0 ? 1 : n * permute(n - 1, m - 1);
        }

        /**
         * Put all primes less or equal to limit into primes after offset
         */
        public static int eulerSieve(int limit, int[] primes, int offset) {
            boolean[] isComp = new boolean[limit + 1];
            int wpos = offset;
            for (int i = 2; i <= limit; i++) {
                if (!isComp[i]) {
                    primes[wpos++] = i;
                }
                for (int j = offset, until = limit / i; j < wpos && primes[j] <= until; j++) {
                    int pi = primes[j] * i;
                    isComp[pi] = true;
                    if (i % primes[j] == 0) {
                        break;
                    }
                }
            }
            return wpos - offset;
        }

        /**
         * Round x into integer
         */
        public static int intRound(double x) {
            if (x < 0) {
                return -(int) (-x + 0.5);
            }
            return (int) (x + 0.5);
        }

        /**
         * Round x into long
         */
        public static long longRound(double x) {
            if (x < 0) {
                return -(long) (-x + 0.5);
            }
            return (long) (x + 0.5);
        }
    }

    public static class IOUtil {
        private static int BUF_SIZE = 1 << 13;

        private byte[] r_buf = new byte[BUF_SIZE];
        private int r_cur;
        private int r_total;
        private int r_next;
        private final InputStream in;
        private StringBuilder temporary = new StringBuilder();

        StringBuilder w_buf = new StringBuilder();
        private final OutputStream out;

        public IOUtil(InputStream in, OutputStream out) {
            this.in = in;
            this.out = out;
        }

        private void skipBlank() {
            while (r_next >= 0 && r_next <= 32) {
                r_next = read();
            }
        }

        public int readString(char[] data, int offset, int limit) {
            skipBlank();

            int originalLimit = limit;
            while (limit > 0 && r_next > 32) {
                data[offset++] = (char) r_next;
                limit--;
                r_next = read();
            }

            return originalLimit - limit;
        }

        public String readString(StringBuilder builder) {
            skipBlank();

            while (r_next > 32) {
                builder.append((char) r_next);
                r_next = read();
            }

            return builder.toString();
        }

        public String readString() {
            temporary.setLength(0);
            return readString(temporary);
        }

        public long readUnsignedLong() {
            skipBlank();

            long num = 0;
            while (r_next >= '0' && r_next <= '9') {
                num = num * 10 + r_next - '0';
                r_next = read();
            }
            return num;
        }

        public long readLong() {
            skipBlank();

            int sign = 1;
            while (r_next == '+' || r_next == '-') {
                if (r_next == '-') {
                    sign *= -1;
                }
                r_next = read();
            }

            return sign == 1 ? readUnsignedLong() : readNegativeLong();
        }

        public long readNegativeLong() {
            skipBlank();

            long num = 0;
            while (r_next >= '0' && r_next <= '9') {
                num = num * 10 - r_next + '0';
                r_next = read();
            }
            return num;
        }

        public int readUnsignedInt() {
            skipBlank();

            int num = 0;
            while (r_next >= '0' && r_next <= '9') {
                num = num * 10 + r_next - '0';
                r_next = read();
            }
            return num;
        }

        public int readNegativeInt() {
            skipBlank();

            int num = 0;
            while (r_next >= '0' && r_next <= '9') {
                num = num * 10 - r_next + '0';
                r_next = read();
            }
            return num;
        }

        public int readInt() {
            skipBlank();

            int sign = 1;
            while (r_next == '+' || r_next == '-') {
                if (r_next == '-') {
                    sign *= -1;
                }
                r_next = read();
            }

            return sign == 1 ? readUnsignedInt() : readNegativeInt();
        }

        public int read() {
            while (r_total <= r_cur) {
                try {
                    r_total = in.read(r_buf);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                r_cur = 0;
                if (r_total == -1) {
                    return -1;
                }
            }
            return r_buf[r_cur++];
        }

        public boolean hasMore() {
            skipBlank();
            return r_next != -1;
        }

        public void write(char c) {
            w_buf.append(c);
        }

        public void write(int n) {
            w_buf.append(n);
        }

        public void write(String s) {
            w_buf.append(s);
        }

        public void write(long s) {
            w_buf.append(s);
        }

        public void write(double s) {
            w_buf.append(s);
        }

        public void write(float s) {
            w_buf.append(s);
        }

        public void write(Object s) {
            w_buf.append(s);
        }

        public void write(char[] data, int offset, int cnt) {
            for (int i = offset, until = offset + cnt; i < until; i++) {
                write(data[i]);
            }
        }

        public void flush() {
            try {
                out.write(w_buf.toString().getBytes(Charset.forName("ascii")));
                w_buf.setLength(0);
                out.flush();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        public double readDouble() {
            return Double.parseDouble(readString());
        }
    }

    public static class Utils {
        public static <T> void swap(T[] data, int i, int j) {
            T tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

        public static <T> int min(T[] data, int from, int to, Comparator<T> cmp) {
            int m = from;
            for (int i = from + 1; i < to; i++) {
                if (cmp.compare(data[m], data[i]) > 0) {
                    m = i;
                }
            }
            return m;
        }

        public static <T> void move(T[] data, int from, int to, int step) {
            int len = to - from;
            step = len - (step % len + len) % len;
            Object[] buf = new Object[len];
            for (int i = 0; i < len; i++) {
                buf[i] = data[(i + step) % len + from];
            }
            System.arraycopy(buf, 0, data, from, len);
        }
    }

    public static class MDAlgorithm<T> {

        public static interface Queries<T> {
            void setAnswer(Interval<T> interval);

            int getLeft();

            int getRight();
        }

        public static interface Interval<T> {
            void add(T add);

            void remove(T remove);

            void clear();
        }

        public void setData(T[] data) {
            this.data = data;
        }

        public void setQueries(Queries<T>[] queries) {
            this.queries = queries.clone();
        }

        public void setInterval(Interval<T> interval) {
            this.interval = interval;
        }

        public void solve() {
            int n = data.length;
            int m = queries.length;

            if (n == 0 || m == 0) {
                return;
            }

            int k = Math.max(1, Mathematics.intRound(n / Math.sqrt(m)));

            Arrays.sort(queries, new Comparator<Queries<T>>() {
                @Override
                public int compare(Queries<T> o1, Queries<T> o2) {
                    int c = o1.getLeft() / k - o2.getLeft() / k;
                    if (c == 0) {
                        c = o1.getRight() - o2.getRight();
                    }
                    return c;
                }
            });

            interval.clear();
            int left = queries[0].getLeft();
            int right = left - 1;
            for (int i = 0; i < m; i++) {
                Queries<T> q = queries[i];
                int l = q.getLeft();
                int r = q.getRight();

                while (left > l) {
                    interval.add(data[--left]);
                }

                while (right < r) {
                    interval.add(data[++right]);
                }

                while (left < l) {
                    interval.remove(data[left++]);
                }

                while (right > r) {
                    interval.remove(data[right--]);
                }

                q.setAnswer(interval);
            }

            return;
        }

        T[] data;
        Queries<T>[] queries;
        Interval<T> interval;
    }
}