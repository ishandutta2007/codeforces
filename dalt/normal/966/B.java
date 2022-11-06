
import java.io.*;
import java.util.*;

public class CF966B {
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
            input = new BlockReader(new FileInputStream("E:\\DATABASE\\TESTCASE\\codeforces\\CF966B.in"));
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
        int x1 = input.nextInteger();
        int x2 = input.nextInteger();
        int[][] servers = new int[n][2];
        for (int i = 0; i < n; i++) {
            servers[i][0] = input.nextInteger();
            servers[i][1] = i + 1;
        }
        Random random = new Random();
        for (int i = n - 1; i >= 0; i--) {
            int j = random.nextInt(i + 1);
            int[] tmp = servers[i];
            servers[i] = servers[j];
            servers[j] = tmp;
        }
        Arrays.sort(servers, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return Integer.compare(o1[0], o2[0]);
            }
        });

        for (int i = 2; i <= n; i++) {
            int worse = n - i;

            {
                //worse belong to x1
                int num = (x1 + servers[worse][0] - 1) / servers[worse][0];
                int remain = i - num;
                int next = worse + num;
                if (remain > 0 && (x2 + remain - 1) / remain <= servers[next][0]) {
                    output.println("Yes");
                    output.print(num);
                    output.print(' ');
                    output.print(remain);
                    output.println();
                    for (int j = worse, until = worse + num; j < until; j++) {
                        output.print(servers[j][1]);
                        output.print(' ');
                    }
                    output.println();
                    for (int j = next, until = n; j < until; j++) {
                        output.print(servers[j][1]);
                        output.print(' ');
                    }
                    return;
                }
            }

            {
                //worse belong to x1
                int num = (x2 + servers[worse][0] - 1) / servers[worse][0];
                int remain = i - num;
                int next = worse + num;
                if (remain > 0 && (x1 + remain - 1) / remain <= servers[next][0]) {
                    output.println("Yes");
                    output.print(remain);
                    output.print(' ');
                    output.print(num);
                    output.println();
                    for (int j = next, until = n; j < until; j++) {
                        output.print(servers[j][1]);
                        output.print(' ');
                    }
                    output.println();
                    for (int j = worse, until = worse + num; j < until; j++) {
                        output.print(servers[j][1]);
                        output.print(' ');
                    }
                    return;
                }
            }
        }

        output.println("No");
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