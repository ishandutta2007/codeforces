

import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by dalt on 2018/4/11.
 */
public class CF961F {
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
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF961F.in"));
            //output = System.out;
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }

        debug = new Debug();
        debug.enter("main");
    }

    public static void solve() {
        int n = input.nextInteger();
        char[] data = new char[n];
        input.nextBlock(data, 0);


        int[] rcpos = new int[n];

        int blc, brc;
        if (n % 2 == 0) {
            blc = n / 2 - 1;
            brc = blc + 1;
        } else {
            blc = n / 2 - 1;
            brc = blc + 2;
        }
        int lc = blc;
        int rc = brc;
        int covered = -1;

        Hash[] hash = new Hash[]{new Hash(data, 31)};

        while (lc >= 0) {
            if (data[lc] == data[rc]) {
                int maxRadius = binarySearch(hash, lc, rc, data);
                int until = rc + maxRadius;
                for (covered = Math.max(covered, rc); covered <= until; covered++) {
                    rcpos[covered] = rc;
                }
            }
            lc--;
            rc++;
        }


        for (int i = n - 1; i >= brc; i--) {
            if (rcpos[i] == 0) {
                output.print("-1 ");
            } else {
                int radius = i - rcpos[i];
                output.print((radius << 1) + 1);
                output.print(' ');
            }
        }
        if (n % 2 == 1) {
            output.print("-1 ");
        }
    }

    public static void destroy() {
        output.flush();
        debug.exit();
        debug.statistic();
    }

    public static int binarySearch(Hash[] hash, int lc, int rc, char[] data) {
        int max = lc;
        int min = 0;
        while (min < max) {
            int m = (min + max + 1) >> 1;
            boolean equal = true;
            for (Hash h : hash) {
                if (h.getHash(lc - m, lc + m) != h.getHash(rc - m, rc + m)) {
                    equal = false;
                    break;
                }
            }
            if (equal) {
                min = m;
            } else {
                max = m - 1;
            }
        }
        return min;
    }

    public static class Hash {
        public int[] rev;
        public int[] batch;
        public int n;
        public int base;

        public Hash(char[] data, int base) {
            n = data.length;
            rev = new int[n];
            this.base = base;
            rev[0] = 1;
            long reverse = pow(base, MOD - 2);
            for (int i = 1; i < n; i++) {
                this.rev[i] = (int) (this.rev[i - 1] * reverse % MOD);
            }

            batch = new int[n];
            batch[n - 1] = data[n - 1];
            long baseInc = 1;
            for (int i = n - 2; i >= 0; i--) {
                baseInc = baseInc * base % MOD;
                batch[i] = (int) (((long) batch[i + 1] + data[i] * baseInc) % MOD);
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

        public int getHash(int l, int r) {
            long hash = batch[l];
            if (r < n - 1) {
                hash = hash - batch[r + 1];
                if (hash < 0) {
                    hash += MOD;
                }
                hash = hash * rev[n - 1 - r] % MOD;
            }
            return (int) hash;
        }
    }

    public static class Debug {
        boolean debug = System.getProperty("ONLINE_JUDGE") == null;
        Deque<ModuleRecorder> stack = new ArrayDeque<>();
        StringBuilder msg = new StringBuilder();
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
                System.out.println(String.format("MOD %s : enter %d : cost %d", module.moduleName, module.enterTime, module.totaltime));
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