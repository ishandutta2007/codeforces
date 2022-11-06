

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.util.*;
import java.util.regex.Pattern;

public class CF1156G {
    public static void main(String[] args) throws Exception {
        boolean local = System.getProperty("ONLINE_JUDGE") == null;
        boolean async = false;

        Charset charset = Charset.forName("ascii");

        FastIO io = local ? new FastIO(new FileInputStream("D:\\DATABASE\\TESTCASE\\Code.in"), System.out, charset) : new FastIO(System.in, System.out, charset);
        Task task = new Task(io, new Debug(local));

        if (async) {
            Thread t = new Thread(null, task, "dalt", 1 << 27);
            t.setPriority(Thread.MAX_PRIORITY);
            t.start();
            t.join();
        } else {
            task.run();
        }

        if (local) {
            io.cache.append("\n\n--memory -- \n" + ((Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()) >> 20) + "M");
        }

        io.flush();
    }

    public static class Task implements Runnable {
        final FastIO io;
        final Debug debug;
        int inf = (int) 1e8;
        int mod = (int) 1e9 + 7;

        public int mod(int val) {
            val %= mod;
            if (val < 0) {
                val += mod;
            }
            return val;
        }

        public int mod(long val) {
            val %= mod;
            if (val < 0) {
                val += mod;
            }
            return (int) val;
        }

        public Task(FastIO io, Debug debug) {
            this.io = io;
            this.debug = debug;
        }

        @Override
        public void run() {
            solve();
        }

        Map<String, Var> context = new HashMap<>();
        HashSet<String> remainNames = new HashSet<>();
        Deque<String> useable = new ArrayDeque<>();

        public void solve() {
            int n = io.readInt();

            for (int i = 0; i < n; i++) {
                parseLine();
            }

            StringBuilder builder = new StringBuilder();
            for (int i = 'a'; i <= 'z'; i++) {
                for (int i2 = 'a'; i2 <= 'z'; i2++) {
                    for (int i3 = 'a'; i3 <= 'z'; i3++) {
                        for (int i4 = 'a'; i4 <= 'z'; i4++) {
                            builder.setLength(0);
                            builder.append((char) i).append((char) i2).append((char) i3).append((char) i4);
                            remainNames.add(builder.toString());
                        }
                    }
                }
            }

            remainNames.removeAll(context.keySet());
            useable.addAll(remainNames);

            String finalName = rebuild(getVar("res"));
            if (trace.isEmpty() && !finalName.equals("res")) {
                trace.add("res=" + finalName);
                finalName = "res";
            }
            if (!trace.isEmpty()) {
                trace.add(trace.remove(trace.size() - 1).replace(finalName, "res"));
            }
            io.cache.append(trace.size()).append('\n');
            for (String s : trace) {
                io.cache.append(s).append('\n');
            }
        }

        List<String> trace = new ArrayList<>();

        Random random = new Random(12345678);
        Map<String, String> exprToName = new HashMap<>();

        public String randomName() {
            return useable.removeFirst();
        }

        public String register(String expr, String name) {
            if (exprToName.containsKey(expr)) {
                return exprToName.get(expr);
            } else {
                trace.add(name + "=" + expr);
                exprToName.put(expr, name);
                return name;
            }
        }

        StringBuilder common = new StringBuilder(1024);

        public String concat(String... parts) {
            common.setLength(0);
            for (String part : parts) {
                common.append(part);
            }
            return common.toString();
        }

        Map<Var, String> cache = new IdentityHashMap<>();

        public String rebuild(Var var) {
            if (cache.containsKey(var)) {
                return cache.get(var);
            }
            String retName = null;
            if (var instanceof UnknownVar) {
                retName = ((UnknownVar) var).name;
            }
            if (var instanceof Reference) {
                retName = rebuild(var.arg1);
            }
            if (var instanceof Expr) {
                String name = randomName();
                String arg1 = rebuild(var.arg1);
                String arg2 = rebuild(((Expr) var).arg2);
                retName = register(concat(arg1, ((Expr) var).op, arg2), name);
            }
            cache.put(var, retName);
            return retName;
        }

        char[] line = new char[100];
        Lexer lexer = new Lexer();

        public Var getVar(String s) {
            if (!context.containsKey(s)) {
                UnknownVar var = new UnknownVar();
                var.name = s;
                context.put(s, var);
            }
            return context.get(s);
        }

        public void parseLine() {
            int len = io.readString(line, 0);
            lexer.reset(line, len);
            String variable = lexer.readName();
            lexer.readOp();
            String arg1 = lexer.readName();
            if (!lexer.hasMore()) {
                Reference reference = new Reference();
                reference.arg1 = getVar(arg1);
                context.put(variable, reference);
            } else {
                Expr expr = new Expr();
                expr.arg1 = getVar(arg1);
                expr.op = lexer.readOp();
                expr.arg2 = getVar(lexer.readName());
                Reference reference = new Reference();
                reference.arg1 = expr;
                context.put(variable, reference);
            }
        }
    }

    public static class Lexer {
        char[] data;
        int len;
        int rpos = 0;
        StringBuilder builder = new StringBuilder();

        public void reset(char[] data, int len) {
            this.data = data;
            this.len = len;
            rpos = 0;
        }

        public boolean hasMore() {
            return rpos != len;
        }

        public String readName() {
            builder.setLength(0);
            while (rpos < len && data[rpos] != '=' &&
                    data[rpos] != '$' && data[rpos] != '^' && data[rpos] != '#' && data[rpos] != '&') {
                builder.append(data[rpos++]);
            }
            return builder.toString();
        }

        public String readOp() {
            builder.setLength(0);
            builder.append(data[rpos++]);
            return builder.toString();
        }
    }

    public static class Var {
        Var arg1;
    }

    public static class Expr extends Var {
        String op;
        Var arg2;
    }

    public static class UnknownVar extends Var {
        String name;
    }

    public static class Reference extends Var {

    }

    public static class FastIO {
        public final StringBuilder cache = new StringBuilder();
        private final InputStream is;
        private final OutputStream os;
        private final Charset charset;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 8);
        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;

        public FastIO(InputStream is, OutputStream os, Charset charset) {
            this.is = is;
            this.os = os;
            this.charset = charset;
        }

        public FastIO(InputStream is, OutputStream os) {
            this(is, os, Charset.forName("ascii"));
        }

        private int read() {
            while (bufLen == bufOffset) {
                bufOffset = 0;
                try {
                    bufLen = is.read(buf);
                } catch (IOException e) {
                    throw new RuntimeException(e);
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

        public long readLong() {
            int sign = 1;

            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+' ? 1 : -1;
                next = read();
            }

            long val = 0;
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

        public double readDouble() {
            boolean sign = true;
            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+';
                next = read();
            }

            long val = 0;
            while (next >= '0' && next <= '9') {
                val = val * 10 + next - '0';
                next = read();
            }
            if (next != '.') {
                return sign ? val : -val;
            }
            next = read();
            long radix = 1;
            long point = 0;
            while (next >= '0' && next <= '9') {
                point = point * 10 + next - '0';
                radix = radix * 10;
                next = read();
            }
            double result = val + (double) point / radix;
            return sign ? result : -result;
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

        public int readLine(char[] data, int offset) {
            int originalOffset = offset;
            while (next != -1 && next != '\n') {
                data[offset++] = (char) next;
                next = read();
            }
            return offset - originalOffset;
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

        public int readString(byte[] data, int offset) {
            skipBlank();

            int originalOffset = offset;
            while (next > 32) {
                data[offset++] = (byte) next;
                next = read();
            }

            return offset - originalOffset;
        }

        public char readChar() {
            skipBlank();
            char c = (char) next;
            next = read();
            return c;
        }

        public void flush() {
            try {
                os.write(cache.toString().getBytes(charset));
                os.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        public boolean hasMore() {
            skipBlank();
            return next != -1;
        }
    }

    public static class Debug {
        private boolean allowDebug;

        public Debug(boolean allowDebug) {
            this.allowDebug = allowDebug;
        }

        public void assertTrue(boolean flag) {
            if (!allowDebug) {
                return;
            }
            if (!flag) {
                fail();
            }
        }

        public void fail() {
            throw new RuntimeException();
        }

        public void assertFalse(boolean flag) {
            if (!allowDebug) {
                return;
            }
            if (flag) {
                fail();
            }
        }

        private void outputName(String name) {
            System.out.print(name + " = ");
        }

        public void debug(String name, int x) {
            if (!allowDebug) {
                return;
            }

            outputName(name);
            System.out.println("" + x);
        }

        public void debug(String name, long x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println("" + x);
        }

        public void debug(String name, double x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println("" + x);
        }

        public void debug(String name, int[] x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.toString(x));
        }

        public void debug(String name, long[] x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.toString(x));
        }

        public void debug(String name, double[] x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.toString(x));
        }

        public void debug(String name, Object x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println("" + x);
        }

        public void debug(String name, Object... x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.deepToString(x));
        }
    }
}