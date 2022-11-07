
import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by dalt on 2018/4/11.
 */
public class CF962E {
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
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF962E.in"));
            output = System.out;
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }

        debug = new Debug();
        debug.enter("main");
    }

    public static void solve() {
        int n = input.nextInteger();
        int[] x = new int[n + 1];
        int[] type = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            x[i] = input.nextInteger();
            type[i] = input.nextBlock().charAt(0);
        }

        long sum = 0;
        int index = 1;
        int firstA = 0;
        int firstB = 0;
        int lastA = 0;
        int lastB = 0;
        for (; index <= n && type[index] != 'P'; index++) {
            if (type[index] == 'B') {
                if (firstA == 0) {
                    lastA = firstA = index;
                } else {
                    lastA = index;
                }
            } else {
                if (firstB == 0) {
                    lastB = firstB = index;
                } else {
                    lastB = index;
                }
            }
        }

        if (index > n) {
            if (firstA != 0) {
                sum += x[lastA] - x[firstA];
            }
            if (firstB != 0) {
                sum += x[lastB] - x[firstB];
            }
            output.println(sum);
            return;
        }

        if (firstA != 0) {
            sum += x[index] - x[firstA];
        }
        if (firstB != 0) {
            sum += x[index] - x[firstB];
        }

        while (index < n) {
            int lastC = index;
            lastA = index;
            lastB = index;
            int maxA = 0;
            int maxB = 0;
            for (index++; index <= n && type[index] != 'P'; index++) {
                if (type[index] == 'B') {
                    maxA = Math.max(maxA, x[index] - x[lastA]);
                    lastA = index;
                } else {
                    maxB = Math.max(maxB, x[index] - x[lastB]);
                    lastB = index;
                }
            }
            if (index > n) {
                sum += x[lastA] - x[lastC];
                sum += x[lastB] - x[lastC];
                break;
            }
            maxA = Math.max(maxA, x[index] - x[lastA]);
            maxB = Math.max(maxB, x[index] - x[lastB]);
            long interval = x[index] - x[lastC];

            sum += Math.min(0, interval - maxA - maxB) + interval + interval;
        }

        output.println(sum);
        return;
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