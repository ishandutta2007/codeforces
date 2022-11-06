import java.io.*;
import java.util.*;

public class CF963D {
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
            input = new BlockReader(new FileInputStream("E:\\DATABASE\\TESTCASE\\codeforces\\CF963D.in"));
            output = System.out;
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }

        debug = new Debug();
        debug.enter("main");
    }

    public static void solve() {
        char[] s = new char[100001];
        int sLen = input.nextBlock(s, 1);

        char[] m = new char[100001];
        int mLen = 0;

        int n = input.nextInteger();
        Request[] requests = new Request[n];

        for (int i = 0; i < n; i++) {
            Request request = new Request();
            request.offset = mLen;
            request.k = input.nextInteger();
            request.len = input.nextBlock(m, mLen);
            mLen += request.len;

            requests[i] = request;
        }

        Integer[] indexes = new Integer[100001];
        for (int i = 0, until = indexes.length; i < until; i++) {
            indexes[i] = i;
        }

        FixedQueue<Integer> fixedQueue = new FixedQueue<Integer>(100001);

        //Build AC-automan
        ACAutoman automan = new ACAutoman();
        for (Request request : requests) {
            automan.beginBuild();
            for (int i = request.offset, until = request.offset + request.len; i < until; i++) {
                automan.build(m[i]);
            }
            automan.buildLast.request = request;
            automan.buildLast.set = new TreeSet<>();
            request.node = automan.buildLast;
        }

        //Find all index
        automan.endBuild();
        automan.beginMatch();
        for (int i = 1; i <= sLen; i++) {
            automan.match(s[i]);

            automan.matchLast.set.add(indexes[i]);
        }

        List<Node> topology = automan.topology;
        for (int i = topology.size() - 1; i >= 0; i--) {
            Node node = topology.get(i);
            if (node.request != null) {
                Request request = node.request;
                if (node.set.size() < request.k) {
                    request.answer = -1;
                } else if (request.k == 1) {
                    request.answer = request.len;
                } else {
                    fixedQueue.init(request.k);

                    int min = Integer.MAX_VALUE;
                    for (Integer index : node.set) {
                        fixedQueue.enque(index);
                        if (fixedQueue.isFull()) {
                            min = Math.min(index.intValue() - fixedQueue.getHead().intValue(), min);
                        }
                    }

                    request.answer = min + request.len;
                }
            }

            node.fail.set = combine(node.fail.set, node.set);
        }

        for (Request request : requests) {
            output.println(request.answer);
        }
    }


    public static void destroy() {
        output.flush();
        debug.exit();
        debug.statistic();
    }

    public static class ACAutoman {
        public Node root = new Node();
        public Node buildLast;
        public Node matchLast;
        public int size;
        public List<Node> topology;

        public void beginBuild() {
            buildLast = root;
        }

        public void build(char c) {
            int i = c - 'a';
            if (buildLast.next[i] != null) {
                buildLast = buildLast.next[i];
                return;
            }

            Node node = new Node();
            node.father = buildLast;
            node.c = i;
            buildLast.next[i] = node;
            buildLast = node;
            size++;
        }

        public Node find(Node point, int i) {
            while (point != null && point.next[i] == null) {
                point = point.fail;
            }
            return point;
        }

        public void beginMatch() {
            matchLast = root;
        }

        public void match(char c) {
            int i = c - 'a';
            Node fail = find(matchLast, i);
            matchLast = fail == null ? root : fail.next[i];
        }

        public void endBuild() {
            Deque<Node> deque = new ArrayDeque<>(size);
            for (Node node : root.next) {
                if (node == null) {
                    continue;
                }
                deque.addLast(node);
            }

            topology = new ArrayList<>(size);
            while (!deque.isEmpty()) {
                Node head = deque.removeFirst();
                topology.add(head);
                Node fail = find(head.father.fail, head.c);
                head.fail = fail == null ? root : fail.next[head.c];

                for (Node node : head.next) {
                    if (node == null) {
                        continue;
                    }
                    deque.addLast(node);
                }
            }
        }
    }

    public static Set<Integer> combine(Set<Integer> a, Set<Integer> b) {
        if (a.size() < b.size()) {
            b.addAll(a);
            return b;
        } else {
            a.addAll(b);
            return a;
        }

    }

    public static class Node {

        @Override
        public String toString() {
            return father == null ? "" : father.toString() + (char) (c + 'a');
        }

        Node[] next = new Node[26];
        Node father;
        int c;
        Request request;
        Set<Integer> set = new TreeSet<>();
        Node fail;
    }

    public static class Request {
        int offset;
        int len;
        int k;
        int answer;
        Node node;
    }


    public static class FixedQueue<T> {
        Object[] data;
        int rpos;
        int wpos;
        int size;

        public FixedQueue(int cap) {
            data = new Object[cap];
        }

        public void init(int size) {
            rpos = wpos = 0;
            this.size = size;
        }

        public void enque(T obj) {
            if (isFull()) {
                deque();
            }
            data[wpos++] = obj;
        }

        public boolean isFull() {
            return wpos - rpos == size;
        }

        public T deque() {
            return (T) data[rpos++];
        }

        public T getHead() {
            return (T) data[rpos];
        }

        public T getTail() {
            return (T) data[wpos - 1];
        }
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