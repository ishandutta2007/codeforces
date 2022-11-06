
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.List;

public class CF1207G {
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

        public Task(FastIO io, Debug debug) {
            this.io = io;
            this.debug = debug;
        }

        @Override
        public void run() {
            solve();
        }

        public void solve() {
            int n = io.readInt();
            CharTree[] trees = new CharTree[n + 1];
            List<CharTree> roots = new ArrayList<>();
            for (int i = 1; i <= n; i++) {
                trees[i] = new CharTree();
                int t = io.readInt();
                if (t == 1) {
                    trees[i].c = io.readChar();
                    roots.add(trees[i]);
                } else {
                    trees[io.readInt()].children.add(trees[i]);
                    trees[i].c = io.readChar();
                }
            }

            int m = io.readInt();
            acAutomaton = new ACAutomaton();
            Question[] questions = new Question[m];
            char[] t = new char[500000];
            for (int i = 0; i < m; i++) {
                questions[i] = new Question();
                trees[io.readInt()].questions.add(questions[i]);
                int len = io.readString(t, 0);
                acAutomaton.beginBuilding();
                for (int j = 0; j < len; j++) {
                    acAutomaton.build(t[j]);
                }
                questions[i].node = acAutomaton.buildLast;

            }
            acAutomaton.endBuilding();
            acAutomaton.beginMatching();
            bit = new BIT(acAutomaton.idAllocator);

            for (CharTree root : roots) {
                dfs(root);
            }

            for (Question q : questions) {
                io.cache.append(q.ans).append('\n');
            }
        }

        ACAutomaton acAutomaton;
        BIT bit;

        public void dfs(CharTree tree) {
            ACAutomaton.Node originState = acAutomaton.matchLast;
            acAutomaton.match(tree.c);
            bit.update(acAutomaton.matchLast.idFrom, 1);

            for (Question q : tree.questions) {
                q.ans = bit.query(q.node.idTo) - bit.query(q.node.idFrom - 1);
            }
            for (CharTree subtree : tree.children) {
                dfs(subtree);
            }

            bit.update(acAutomaton.matchLast.idFrom, -1);
            acAutomaton.matchLast = originState;
        }
    }

    public static class CharTree {
        char c;
        List<CharTree> children = new ArrayList<>(1);
        List<Question> questions = new ArrayList<>(1);
    }

    public static class Question {
        ACAutomaton.Node node;
        int ans;
    }


    public static class BIT {
        private int[] data;
        private int n;

        /**
         * A[1...n]
         */
        public BIT(int n) {
            this.n = n;
            data = new int[n + 1];
        }

        /**
         * A[1]+A[2]+...+A[i]
         */
        public int query(int i) {
            int sum = 0;
            for (; i > 0; i -= i & -i) {
                sum += data[i];
            }
            return sum;
        }

        /**
         * A[i]A[i]+mod
         */
        public void update(int i, int mod) {
            for (; i <= n; i += i & -i) {
                data[i] += mod;
            }
        }

        /**
         * A0
         */
        public void clear() {
            Arrays.fill(data, 0);
        }

        @Override
        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 1; i <= n; i++) {
                builder.append(query(i) - query(i - 1)).append(' ');
            }
            return builder.toString();
        }
    }


    /**
     * Created by dalt on 2018/5/25.
     */
    public static class ACAutomaton {
        static final int MIN_CHARACTER = 'a';
        static final int MAX_CHARACTER = 'z';
        static final int RANGE_SIZE = MAX_CHARACTER - MIN_CHARACTER + 1;
        Node root;
        Node buildLast;
        Node matchLast;
        List<Node> allNodes = new ArrayList(1);
        int idAllocator = 0;

        public void dfs(Node root) {
            root.idFrom = ++idAllocator;
            for (Node child : root.children) {
                dfs(child);
            }
            root.idTo = idAllocator;
        }

        private Node addNode() {
            Node node = new Node();
            node.id = allNodes.size();
            allNodes.add(node);
            return node;
        }

        public ACAutomaton() {
            root = addNode();
        }

        public void beginBuilding() {
            buildLast = root;
        }

        public void endBuilding() {
            Deque<Node> deque = new ArrayDeque(allNodes.size());
            for (int i = 0; i < RANGE_SIZE; i++) {
                if (root.next[i] != null) {
                    deque.addLast(root.next[i]);
                }
            }

            while (!deque.isEmpty()) {
                Node head = deque.removeFirst();
                Node fail = visit(head.father.fail, head.index);
                if (fail == null) {
                    head.fail = root;
                } else {
                    head.fail = fail.next[head.index];
                }
                head.fail.children.add(head);
                head.word = head.word || head.fail.word;
                for (int i = 0; i < RANGE_SIZE; i++) {
                    if (head.next[i] != null) {
                        deque.addLast(head.next[i]);
                    }
                }
            }

            for (int i = 0; i < RANGE_SIZE; i++) {
                if (root.next[i] != null) {
                    deque.addLast(root.next[i]);
                } else {
                    root.next[i] = root;
                }
            }
            while (!deque.isEmpty()) {
                Node head = deque.removeFirst();
                for (int i = 0; i < RANGE_SIZE; i++) {
                    if (head.next[i] != null) {
                        deque.addLast(head.next[i]);
                    } else {
                        head.next[i] = head.fail.next[i];
                    }
                }
            }

            dfs(root);
        }

        public Node visit(Node trace, int index) {
            while (trace != null && trace.next[index] == null) {
                trace = trace.fail;
            }
            return trace;
        }

        public void build(char c) {
            int index = c - MIN_CHARACTER;
            if (buildLast.next[index] == null) {
                Node node = addNode();
                node.father = buildLast;
                node.index = index;
                buildLast.next[index] = node;
            }
            buildLast = buildLast.next[index];
        }

        public void beginMatching() {
            matchLast = root;
        }

        public void match(char c) {
            int index = c - MIN_CHARACTER;
            matchLast = matchLast.next[index];
        }

        public static class Node {
            Node[] next = new Node[RANGE_SIZE];
            Node fail;
            Node father;
            int index;
            int id;
            boolean word;
            List<Node> children = new ArrayList<>(1);
            int idFrom;
            int idTo;

            @Override
            public String toString() {
                return father == null ? "" : (father.toString() + (char) (MIN_CHARACTER + index));
            }
        }
    }

    public static class FastIO {
        public final StringBuilder cache = new StringBuilder(1 << 13);
        private final InputStream is;
        private final OutputStream os;
        private final Charset charset;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 13);
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

        public void flush() throws IOException {
            os.write(cache.toString().getBytes(charset));
            os.flush();
            cache.setLength(0);
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