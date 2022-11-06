
import java.io.*;
import java.util.*;

public class CF962B {
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
            input = new BlockReader(new FileInputStream("E:\\DATABASE\\TESTCASE\\codeforces\\CF962B.in"));
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
            nodes[i].id = i;
        }
        for (int i = 1; i <= n; i++) {
            int f = input.nextInteger();
            if (f == 0) {
                continue;
            }
            Node father = nodes[f];
            father.children.add(nodes[i]);
            nodes[i].children.add(father);
        }

        dfs(nodes[1], null);

        if (nodes[1].type == FATHER_NOT_EXIST || nodes[1].type == NO_PROBLEM) {
            output.println("YES");
            dfs2(nodes[1], null, 0);
        } else {
            output.println("NO");
        }
    }

    public static final int FATHER_EXIST = 0;
    public static final int FATHER_NOT_EXIST = 1;
    public static final int NO_PROBLEM = 2;

    public static void dfs(Node root, Node father) {
        int[] cnt = new int[3];
        for (Node child : root.children) {
            if (child == father) {
                continue;
            }
            dfs(child, root);
            cnt[child.type]++;
        }

        if (cnt[NO_PROBLEM] > 0) {
            root.type = NO_PROBLEM;
        } else if ((cnt[FATHER_NOT_EXIST] & 1) == 1) {
            root.type = FATHER_EXIST;
        } else {
            root.type = FATHER_NOT_EXIST;
        }
        root.cnt = cnt;
    }

    public static void dfs2(Node root, Node father, int fatherCnt) {
        root.removed = true;
        boolean remove = false;
        if (((root.cnt[FATHER_NOT_EXIST] + root.cnt[NO_PROBLEM] + fatherCnt) & 1) == 1) {
            remove = true;
        }
        for (Node child : root.children) {
            if (child == father) {
                continue;
            }
            if (child.type == FATHER_EXIST) {
                dfs2(child, root, 1);
            } else if (child.type == NO_PROBLEM && remove) {
                remove = false;
                dfs2(child, root, 1);
            }
        }

        output.println(root.id);

        for (Node child : root.children) {
            if (child == father) {
                continue;
            }
            if (!child.removed) {
                dfs2(child, root, 0);
            }
        }
    }


    public static class Node {
        List<Node> children = new ArrayList<>(1);
        int type;
        int id;
        int[] cnt;
        boolean removed;

        @Override
        public String toString() {
            return "" + id;
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
}