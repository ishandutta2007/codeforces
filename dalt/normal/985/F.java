

import java.io.*;
import java.util.*;

public class ECR44F {
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
            input = new BlockReader(new FileInputStream("E:\\DATABASE\\TESTCASE\\codeforces\\ECR44F.in"));
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
        int m = input.nextInteger();
        char[] data = new char[n];
        input.nextBlock(data, 0);

        CharHash hash31 = new CharHash(data, 31);
        CharHash hash61 = new CharHash(data, 61);

        boolean[] occupied = new boolean[27];
        for (int i = 0; i < m; i++) {
            int x = input.nextInteger() - 1;
            int y = input.nextInteger() - 1;
            int l = input.nextInteger();

            Arrays.fill(occupied, false);

            boolean success = true;
            for (char c = 'a'; c <= 'z'; c++) {
                int xHash31 = hash31.hash(x, x + l - 1, c);
                int xHash61 = hash61.hash(x, x + l - 1, c);
                boolean find = false;
                for (int mapTo = 0; mapTo < 27; mapTo++) {
                    if (occupied[mapTo]) {
                        continue;
                    }
                    int yHash31 = hash31.hash(y, y + l - 1, (char) (mapTo + 'a'));
                    int yHash61 = hash61.hash(y, y + l - 1, (char) (mapTo + 'a'));
                    if (yHash31 == xHash31 && yHash61 == xHash61) {
                        occupied[mapTo] = true;
                        find = true;
                        break;
                    }
                }
                if (!find) {
                    success = false;
                    break;
                }
            }

            output.println(success ? "YES" : "NO");
        }
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

    public static class CharHash {
        private static int MOD = (int) (1e9 + 7);
        private int[] inverse;
        private int[][] hash;
        private int n;
        private int x;

        public CharHash(char[] data, int x) {
            n = data.length;
            inverse = new int[n];
            this.x = x;
            inverse[0] = 1;
            long inv = pow(x, MOD - 2);
            for (int i = 1; i < n; i++) {
                this.inverse[i] = (int) (this.inverse[i - 1] * inv % MOD);
            }

            hash = new int[27][n];
            for(int i = 0; i < 27; i++) {
                char c = (char) (i + 'a');
                hash[i][n - 1] = data[n - 1] == c ? 1 : 0;
                long baseInc = 1;
                for (int j = n - 2; j >= 0; j--) {
                    baseInc = baseInc * x % MOD;

                    int dataval = data[j] == c ? 1 : 0;

                    hash[i][j] = (int) (((long) hash[i][j + 1] + dataval * baseInc) % MOD);
                }
            }
        }

        public static long pow(int x, int n) {
            int bit = 31 - Integer.numberOfLeadingZeros(n);
            long product = 1;
            for (; bit >= 0; bit--) {
                product = product * product % MOD;
                if (((1 << bit) & n) != 0) {
                    product = product * x % MOD;
                }
            }
            return product;
        }

        public int hash(int l, int r, char c) {
            int index = c - 'a';
            long hash = this.hash[index][l];
            if (r < n - 1) {
                hash = hash - this.hash[index][r + 1];
                if (hash < 0) {
                    hash += MOD;
                }
                hash = hash * inverse[n - 1 - r] % MOD;
            }
            return (int) hash;
        }
    }
}