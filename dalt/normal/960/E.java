
import java.io.*;
import java.util.*;

/**
 * Created by dalt on 2018/4/26.
 */
public class CF960E {
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
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF960E.in"));
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
        Node[] nodes = new Node[n + 1];
        for (int i = 1; i <= n; i++) {
            nodes[i] = new Node();
            nodes[i].weight = input.nextInteger();
        }

        for (int i = 1; i < n; i++) {
            Node a = nodes[input.nextInteger()];
            Node b = nodes[input.nextInteger()];
            a.children.add(b);
            b.children.add(a);
        }

        output.println(dfs(nodes[1], null));
    }

    public static void destroy() {
        output.flush();
        debug.exit();
        debug.statistic();
    }

    public static long dfs(Node root, Node father) {
        root.oddCnt = 1;
        root.oddSum = root.weight;
        root.sum = root.weight;

        long result = 0;
        for (Node child : root.children) {
            if (child == father) {
                continue;
            }
            result += dfs(child, root);
            //From left to right
            root.sum = root.sum + ((root.evenCnt - root.oddCnt) % MOD) * ((-child.evenSum + child.oddSum) % MOD) % MOD;
            root.sum = root.sum + ((root.evenSum + root.oddSum) % MOD) * ((child.evenCnt + child.oddCnt) % MOD) % MOD;
            //From right to left
            root.sum = root.sum + ((root.evenCnt + root.oddCnt) % MOD) * ((child.evenSum + child.oddSum) % MOD) % MOD;
            root.sum = root.sum + ((-root.evenSum + root.oddSum) % MOD) * ((child.evenCnt - child.oddCnt) % MOD) % MOD;

            root.oddCnt = (root.oddCnt + child.evenCnt) % MOD;
            root.oddSum = (root.oddSum + child.evenSum + child.evenCnt * root.weight % MOD) % MOD;
            root.evenCnt = (root.evenCnt + child.oddCnt) % MOD;
            root.evenSum = (root.evenSum + child.oddSum - child.oddCnt * root.weight % MOD) % MOD;
        }

        result += root.sum;
        return (result % MOD + MOD) % MOD;
    }

    public static class Node {
        List<Node> children = new ArrayList<>(1);
        long weight;
        long oddCnt;
        long evenCnt;
        long oddSum;
        long evenSum;
        long sum;
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