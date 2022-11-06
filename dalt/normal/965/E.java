
import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;

public class CF965E {
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
            input = new BlockReader(new FileInputStream("E:\\DATABASE\\TESTCASE\\codeforces\\CF965E.in"));
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
        char[] data = new char[100000];
        Tries tries = new Tries();

        for (int i = 0; i < n; i++) {
            int len = input.nextBlock(data, 0);
            tries.beginBuild();
            for (int j = 0; j < len; j++) {
                tries.build(data[j]);
            }
            tries.buildLast.isLeaf = true;
        }

        Segment segment = Segment.build(1, 100000);
        int sum = 0;
        int[] ids = new int[]{1};
        for (Tries.Node next : tries.root.next) {
            if (next == null) {
                continue;
            }
            dpOnTree(next, ids, segment);
            sum += next.dp;
        }

        output.println(sum);
    }


    static int[] buf = new int[128];
    static Tries.Node[] nodes = new Tries.Node[100001];

    public static void dpOnTree(Tries.Node node, int[] ids, Segment root) {
        node.rangeFrom = ids[0];

        for (Tries.Node next : node.next) {
            if (next == null) {
                continue;
            }
            dpOnTree(next, ids, root);
            node.size += next.size;
            node.dp += next.dp;
        }

        if (node.isLeaf) {
            if (node.size == 0) {
                nodes[ids[0]] = node;
                Segment.update(ids[0], ids[0], 1, 100000, 0, 1, root);
                ids[0]++;
            }
            node.size += 1;
        }

        node.rangeTo = ids[0];
        node.dp += node.size;
        Segment.update(node.rangeFrom, node.rangeTo - 1, 1, 100000, 1, 0, root);

        if (!node.isLeaf) {
            buf[0] = -1;
            Segment.query(node.rangeFrom, node.rangeTo - 1, 1, 100000, buf, root);

            Tries.Node longestNode = nodes[buf[1]].father;
            int cnt = Segment.queryCnt(longestNode.rangeFrom, longestNode.rangeTo - 1, 1, 100000, root);

            if (cnt == 1) {
                Segment.update(buf[1], buf[1], 1, 100000, -1, 0, root);
                nodes[buf[1]] = longestNode;
            } else {
                Segment.update(buf[1], buf[1], 1, 100000, -INF, -1, root);
                nodes[buf[1]] = null;
            }

            node.dp -= buf[0] - 1;
        }
    }

    public static class Tries {
        public static class Node {
            Node[] next = new Node[26];
            Node father;
            char c;

            @Override
            public String toString() {
                return father == null ? "" : (father.toString() + (char) (c + 'a'));
            }

            int size;
            int dp;
            boolean isLeaf;
            int rangeFrom;
            int rangeTo;
        }

        Node root = new Node();
        Node buildLast;

        public void beginBuild() {
            buildLast = root;
        }

        public void build(char c) {
            c -= 'a';
            if (buildLast.next[c] == null) {
                Node node = new Node();
                node.father = buildLast;
                node.c = c;
                buildLast.next[c] = node;
            }
            buildLast = buildLast.next[c];
        }
    }

    public static class Segment {
        Segment left;
        Segment right;

        int val;
        int valIndex;
        int dirty;
        int cnt;

        public static Segment build(int l, int r) {
            Segment segment = new Segment();
            if (l != r) {
                int m = (l + r) >> 1;
                segment.left = build(l, m);
                segment.right = build(m + 1, r);
                segment.pushUp();
            } else {
                segment.valIndex = l;
            }
            return segment;
        }

        public void modVal(int mod) {
            val += mod;
            dirty += mod;
        }

        public void modCnt(int mod) {
            cnt += mod;
        }


        public void pushUp() {
            if (left.val > right.val) {
                val = left.val;
                valIndex = left.valIndex;
            } else {
                val = right.val;
                valIndex = right.valIndex;
            }

            cnt = left.cnt + right.cnt;
        }

        public void pushDown() {
            if (dirty != 0) {
                left.modVal(dirty);
                right.modVal(dirty);
                dirty = 0;
            }
        }

        public static void update(int f, int t, int l, int r, int mod, int cnt, Segment segment) {
            if (r < f || l > t) {
                return;
            }
            if (f <= l && t >= r) {
                segment.modVal(mod);
                segment.modCnt(cnt);
                return;
            }

            int m = (l + r) >> 1;

            segment.pushDown();
            update(f, t, l, m, mod, cnt, segment.left);
            update(f, t, m + 1, r, mod, cnt, segment.right);
            segment.pushUp();
        }

        public static int queryCnt(int f, int t, int l, int r, Segment segment)
        {
            if (f > r || t < l) {
                return 0;
            }
            if (f <= l && t >= r) {
                return segment.cnt;
            }

            int m = (l + r) >> 1;

            segment.pushDown();
            return queryCnt(f, t, l, m, segment.left) + queryCnt(f, t, m + 1, r, segment.right);
        }

        public static void query(int f, int t, int l, int r, int[] valIndex, Segment segment) {
            if (f > r || t < l) {
                return;
            }
            if (f <= l && t >= r) {
                if (segment.val > valIndex[0]) {
                    valIndex[0] = segment.val;
                    valIndex[1] = segment.valIndex;
                }
                return;
            }

            int m = (l + r) >> 1;
            segment.pushDown();
            query(f, t, l, m, valIndex, segment.left);
            query(f, t, m + 1, r, valIndex, segment.right);
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