import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.HashMap;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.util.Map;
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
            FCowmpanyCowmpensation solver = new FCowmpanyCowmpensation();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FCowmpanyCowmpensation {
        Modular mod = new Modular(1e9 + 7);

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int d = in.readInt();
            Node[] nodes = new Node[n];
            for (int i = 0; i < n; i++) {
                nodes[i] = new Node();
                nodes[i].presum = new int[n + 1];
            }
            for (int i = 1; i < n; i++) {
                Node p = nodes[in.readInt() - 1];
                p.next.add(nodes[i]);
            }
            dfs(nodes[0]);
            GravityModLagrangeInterpolation interpolation = new GravityModLagrangeInterpolation(mod, n + 1);
            for (int i = 0; i < n + 1; i++) {
                interpolation.addPoint(i + 1, nodes[0].presum[i]);
            }
            int ans = interpolation.getYByInterpolation(d);
            out.println(ans);
        }

        public void dfs(Node root) {
            Arrays.fill(root.presum, 1);
            for (Node node : root.next) {
                dfs(node);
                for (int i = 0; i < root.presum.length; i++) {
                    root.presum[i] = mod.mul(root.presum[i], node.presum[i]);
                }
            }
            for (int i = 1; i < root.presum.length; i++) {
                root.presum[i] = mod.plus(root.presum[i], root.presum[i - 1]);
            }
        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

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

        public FastOutput println(int c) {
            cache.append(c);
            println();
            return this;
        }

        public FastOutput println() {
            cache.append(System.lineSeparator());
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

    static class Power {
        final Modular modular;

        public Modular getModular() {
            return modular;
        }

        public Power(Modular modular) {
            this.modular = modular;
        }

        public int pow(int x, int n) {
            if (n == 0) {
                return modular.valueOf(1);
            }
            long r = pow(x, n >> 1);
            r = modular.valueOf(r * r);
            if ((n & 1) == 1) {
                r = modular.valueOf(r * x);
            }
            return (int) r;
        }

        public int inverseByFermat(int x) {
            return pow(x, modular.m - 2);
        }

    }

    static class GravityModLagrangeInterpolation {
        private Power power;
        private Modular modular;
        Map<Integer, Integer> points = new HashMap<>();
        Polynomial xs;
        Polynomial ys;
        Polynomial lx;
        Polynomial lxBuf;
        Polynomial invW;
        int n;

        public GravityModLagrangeInterpolation(Modular modular, int expect) {
            this(new Power(modular), expect);
        }

        public GravityModLagrangeInterpolation(Power power, int expect) {
            this.modular = power.getModular();
            this.power = power;
            xs = new Polynomial(expect);
            ys = new Polynomial(expect);
            lx = new Polynomial(expect);
            lxBuf = new Polynomial(expect);
            invW = new Polynomial(expect);
            lx.setN(1);
            lx.coes[0] = 1;
        }

        public void addPoint(int x, int y) {
            x = modular.valueOf(x);
            y = modular.valueOf(y);
            Integer exist = points.get(x);
            if (exist != null) {
                if (exist != y) {
                    throw new RuntimeException();
                }
                return;
            }
            points.put(x, y);

            xs.setN(n + 1);
            xs.coes[n] = x;
            ys.setN(n + 1);
            ys.coes[n] = y;
            lx.multiply(modular.valueOf(-x), lxBuf);
            switchBuf();
            invW.setN(n + 1);
            invW.coes[n] = 1;
            for (int i = 0; i < n; i++) {
                invW.coes[i] = modular.mul(invW.coes[i], modular.subtract(xs.coes[i], x));
                invW.coes[n] = modular.mul(invW.coes[n], modular.subtract(x, xs.coes[i]));
            }
            n++;
        }

        public int getYByInterpolation(int x) {
            x = modular.valueOf(x);
            if (points.containsKey(x)) {
                return points.get(x);
            }

            int y = lx.function(x);
            int sum = 0;
            for (int i = 0; i < n; i++) {
                int val = modular.mul(invW.coes[i], modular.subtract(x, xs.coes[i]));
                val = modular.mul(power.inverseByFermat(val), ys.coes[i]);
                sum = modular.plus(sum, val);
            }

            return modular.mul(y, sum);
        }

        public Polynomial preparePolynomial() {
            Polynomial ans = new Polynomial(n);
            Polynomial ansBuf = new Polynomial(n);
            for (int i = 0; i < n; i++) {
                int c = modular.mul(ys.coes[i], power.inverseByFermat(invW.coes[i]));
                lx.div(modular.valueOf(-xs.coes[i]), ansBuf);
                ansBuf.mulConstant(c, ansBuf);
                ans.plus(ansBuf, ans);
            }
            return ans;
        }

        private void switchBuf() {
            Polynomial tmp = lx;
            lx = lxBuf;
            lxBuf = tmp;
        }

        public String toString() {
            return preparePolynomial().toString();
        }

        public class Polynomial {
            private int[] coes;
            private int n;

            public int function(int x) {
                int ans = 0;
                int xi = 1;
                for (int i = 0; i < n; i++) {
                    ans = modular.plus(ans, modular.mul(xi, coes[i]));
                    xi = modular.mul(xi, x);
                }
                return ans;
            }

            public Polynomial(int n) {
                this.n = 0;
                coes = new int[n];
            }

            public void ensureLength() {
                if (coes.length >= n) {
                    return;
                }
                int proper = coes.length;
                while (proper < n) {
                    proper = Math.max(proper + proper, proper + 10);
                }
                coes = Arrays.copyOf(coes, proper);
            }

            public void setN(int n) {
                this.n = n;
                ensureLength();
            }

            public void multiply(int b, Polynomial ans) {
                ans.setN(n + 1);
                for (int i = 0; i < n; i++) {
                    ans.coes[i] = modular.mul(coes[i], b);
                }
                ans.coes[n] = 0;
                for (int i = 0; i < n; i++) {
                    ans.coes[i + 1] = modular.plus(ans.coes[i + 1], coes[i]);
                }
            }

            public void mulConstant(int b, Polynomial ans) {
                ans.setN(n);
                for (int i = 0; i < n; i++) {
                    ans.coes[i] = modular.mul(coes[i], b);
                }
            }

            public void plus(Polynomial a, Polynomial ans) {
                ans.setN(Math.max(n, a.n));
                for (int i = 0; i < n; i++) {
                    ans.coes[i] = coes[i];
                }
                for (int i = 0; i < a.n; i++) {
                    ans.coes[i] = modular.plus(ans.coes[i], a.coes[i]);
                }
            }

            public void div(int b, Polynomial ans) {
                ans.setN(n - 1);
                int affect = 0;
                for (int i = n - 1; i >= 1; i--) {
                    affect = modular.plus(affect, coes[i]);
                    ans.coes[i - 1] = affect;
                    affect = modular.mul(-affect, b);
                }
            }

            public String toString() {
                return Arrays.toString(Arrays.copyOfRange(coes, 0, n));
            }

        }

    }

    static class Node {
        List<Node> next = new ArrayList<>();
        int[] presum;

    }

    static class Modular {
        int m;

        public Modular(int m) {
            this.m = m;
        }

        public Modular(long m) {
            this.m = (int) m;
            if (this.m != m) {
                throw new IllegalArgumentException();
            }
        }

        public Modular(double m) {
            this.m = (int) m;
            if (this.m != m) {
                throw new IllegalArgumentException();
            }
        }

        public int valueOf(int x) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            return x;
        }

        public int valueOf(long x) {
            x %= m;
            if (x < 0) {
                x += m;
            }
            return (int) x;
        }

        public int mul(int x, int y) {
            return valueOf((long) x * y);
        }

        public int plus(int x, int y) {
            return valueOf(x + y);
        }

        public int subtract(int x, int y) {
            return valueOf(x - y);
        }

        public String toString() {
            return "mod " + m;
        }

    }

    static class FastInput {
        private final InputStream is;
        private byte[] buf = new byte[1 << 20];
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

    }
}