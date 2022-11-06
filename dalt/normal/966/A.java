

import java.io.*;
import java.util.*;

public class CF966A {
    static final int INF = (int) 1e8;
    static final int MOD = (int) 1e9 + 7;
    public static BlockReader input;
    public static PrintStream output;
    public static Debug debug;

    public static void main(String[] args) throws FileNotFoundException {

        init();

        solve();

        destroy();
    }

    public static void init() throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("E:\\DATABASE\\TESTCASE\\codeforces\\CF966A.in"));
            output = System.out;
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }

        debug = new Debug();
        debug.enter("main");
    }

    public static void solve() {
        int r = input.nextInteger();
        int c = input.nextInteger();
        int lNum = input.nextInteger();
        int eNum = input.nextInteger();
        int v = input.nextInteger();

        TreeSet<Integer> stairs = new TreeSet<>();
        TreeSet<Integer> ele = new TreeSet<>();
        for (int i = 0; i < lNum; i++) {
            stairs.add(input.nextInteger());
        }
        for (int i = 0; i < eNum; i++) {
            ele.add(input.nextInteger());
        }

        int q = input.nextInteger();
        for (int i = 0; i < q; i++) {
            int y1 = input.nextInteger();
            int x1 = input.nextInteger();
            int y2 = input.nextInteger();
            int x2 = input.nextInteger();

            int min = Integer.MAX_VALUE;
            if (y1 == y2) {
                min = Math.min(min, Math.abs(x2 - x1));
            }

            Integer ll = (stairs).floor(x1);
            Integer rl = stairs.ceiling(x1);
            Integer le = ele.floor(x1);
            Integer re = ele.ceiling(x1);

            if (ll != null) {
                min = Math.min(min, cost(x1, y1, ll, 1, x2, y2));
            }

            if (rl != null) {
                min = Math.min(min, cost(x1, y1, rl, 1, x2, y2));
            }

            if (le != null) {
                min = Math.min(min, cost(x1, y1, le, v, x2, y2));
            }

            if (re != null) {
                min = Math.min(min, cost(x1, y1, re, v, x2, y2));
            }

            output.println(min);
        }
    }

    public static int cost(int x1, int y1, int cen, int v, int x2, int y2) {
        int t1 = Math.abs(cen - x1);
        int t2 = (Math.abs(y2 - y1) + v - 1) / v;
        int t3 = Math.abs(x2 - cen);
        return t1 + t2 + t3;
    }

    public static void destroy() {
        output.flush();
        debug.exit();
        debug.statistic();
    }


    public static class Debug {
        boolean debug = System.getProperty("ONLINE_JUDGE") == null;
        Deque<ModuleRecorder> stack = new ArrayDeque<>();
        Map<String, Module> fragmentMap = new HashMap<>();

        public void enter(String module) {
            if (debug) {
                stack.push(new ModuleRecorder(getModule(module)));
            }
        }

        public Module getModule(String moduleName) {
            Module module = fragmentMap.get(moduleName);
            if (module == null) {
                module = new Module(moduleName);
                fragmentMap.put(moduleName, module);
            }
            return module;
        }

        public void exit() {
            if (debug) {
                ModuleRecorder fragment = stack.pop();
                fragment.exit();
            }
        }

        public void statistic() {
            if (!debug) {
                return;
            }

            if (stack.size() > 0) {
                throw new RuntimeException("Exist unexited tag");
            }
            System.out.println("\n------------------------------------------");

            System.out.println("memory used " + ((Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()) >> 20) + "M");

            System.out.println("\n------------------------------------------");
            for (Module module : fragmentMap.values()) {
                System.out.println(String.format("Module %s : enter %d : cost %d", module.moduleName, module.enterTime, module.totaltime));
            }

            System.out.println("------------------------------------------");
        }

        public static class ModuleRecorder {
            Module fragment;
            long time;

            public ModuleRecorder(Module fragment) {
                this.fragment = fragment;
                time = System.currentTimeMillis();
            }

            public void exit() {
                fragment.totaltime += System.currentTimeMillis() - time;
                fragment.enterTime++;
            }
        }

        public static class Module {
            String moduleName;
            long totaltime;
            long enterTime;

            public Module(String moduleName) {
                this.moduleName = moduleName;
            }
        }
    }

    public static class BlockReader {
        static final int EOF = -1;
        InputStream is;
        byte[] dBuf;
        int dPos, dSize, next;
        StringBuilder builder = new StringBuilder();

        public BlockReader(InputStream is) {
            this(is, 8192);
        }

        public BlockReader(InputStream is, int bufSize) {
            this.is = is;
            dBuf = new byte[bufSize];
            next = nextByte();
        }

        public int nextByte() {
            while (dPos >= dSize) {
                if (dSize == -1) {
                    return EOF;
                }
                dPos = 0;
                try {
                    dSize = is.read(dBuf);
                } catch (Exception e) {
                }
            }
            return dBuf[dPos++];
        }

        public String nextBlock() {
            builder.setLength(0);
            skipBlank();
            while (next != EOF && !Character.isWhitespace(next)) {
                builder.append((char) next);
                next = nextByte();
            }
            return builder.toString();
        }

        public void skipBlank() {
            while (Character.isWhitespace(next)) {
                next = nextByte();
            }
        }

        public int nextInteger() {
            skipBlank();
            int ret = 0;
            boolean rev = false;
            if (next == '+' || next == '-') {
                rev = next == '-';
                next = nextByte();
            }
            while (next >= '0' && next <= '9') {
                ret = (ret << 3) + (ret << 1) + next - '0';
                next = nextByte();
            }
            return rev ? -ret : ret;
        }

        public int nextBlock(char[] data, int offset) {
            skipBlank();
            int index = offset;
            int bound = data.length;
            while (next != EOF && index < bound && !Character.isWhitespace(next)) {
                data[index++] = (char) next;
                next = nextByte();
            }
            return index - offset;
        }

        public boolean hasMore() {
            skipBlank();
            return next != EOF;
        }
    }
}