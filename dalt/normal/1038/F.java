import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Collection;
import java.io.IOException;
import java.util.Deque;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 27);
        thread.start();
        thread.join();
    }

    static class TaskAdapter implements Runnable {
        @Override
        public void run() {
            InputStream inputStream = System.in;
            OutputStream outputStream = System.out;
            FastInput in = new FastInput(inputStream);
            FastOutput out = new FastOutput(outputStream);
            FWrapAround solver = new FWrapAround();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FWrapAround {
        ACAutomaton.Node end;
        ACAutomaton.Node begin;
        int n;
        char[] s;
        ACAutomaton.Node[] nodes;
        ACAutomaton at;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            n = in.readInt();
            s = in.readString().toCharArray();
            at = new ACAutomaton('0', '1');
            at.beginBuilding();
            for (char c : s) {
                at.build(c);
            }
            at.endBuilding();
            end = at.getBuildLast();
            nodes = at.getAllNodes().toArray(new ACAutomaton.Node[0]);
            begin = nodes[0];

            long ans = 0;
            for (int i = 0; i < n; i++) {
                ans += way(i);
            }

            out.println(ans);
        }

        public long pow(long x, long n) {
            if (n == 0) {
                return 1;
            }
            long ans = pow(x, n / 2);
            ans *= ans;
            if (n % 2 == 1) {
                ans *= x;
            }
            return ans;
        }

        public long way(int offset) {
            char[] data = new char[1 + 2 * n];
            for (int i = 0; i < s.length; i++) {
                data[1 + i + offset] = s[i];
                data[1 + (i + offset) % n] = s[i];
            }
            int dpLen = offset + s.length;
            long[][] dp = new long[dpLen + 1][nodes.length];
            dp[0][begin.getId()] = 1;
            for (int i = 0; i < dpLen; i++) {
                for (int j = 0; j < nodes.length; j++) {
                    if (dp[i][j] == 0 || j == end.getId()) {
                        continue;
                    }
                    if (data[i + 1] == 0) {
                        dp[i + 1][nodes[j].next[0].getId()] += dp[i][j];
                        dp[i + 1][nodes[j].next[1].getId()] += dp[i][j];
                    } else {
                        dp[i + 1][nodes[j].next[data[i + 1] - '0'].getId()] += dp[i][j];
                    }
                }
            }
            long ans = dp[dpLen][end.getId()];
            if (offset + s.length < n) {
                ans *= pow(2, n - offset - s.length);
            }
            return ans;
        }

    }

    static class FastOutput implements AutoCloseable, Closeable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput println(long c) {
            cache.append(c);
            println();
            return this;
        }

        public FastOutput println() {
            cache.append(System.lineSeparator());
            return this;
        }

        public FastOutput flush() {
            try {
                os.append(cache);
                os.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
            return this;
        }

        public void close() {
            flush();
            try {
                os.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

        public String toString() {
            return cache.toString();
        }

    }

    static class FastInput {
        private final InputStream is;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 13);
        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;

        public FastInput(InputStream is) {
            this.is = is;
        }

        private int read() {
            while (bufLen == bufOffset) {
                bufOffset = 0;
                try {
                    bufLen = is.read(buf);
                } catch (IOException e) {
                    bufLen = -1;
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

    }

    static class ACAutomaton {
        private final int MIN_CHARACTER;
        private final int MAX_CHARACTER;
        private final int RANGE;
        private ACAutomaton.Node root;
        private ACAutomaton.Node buildLast;
        private List<ACAutomaton.Node> allNodes = new ArrayList();

        public ACAutomaton.Node getBuildLast() {
            return buildLast;
        }

        public List<ACAutomaton.Node> getAllNodes() {
            return allNodes;
        }

        private ACAutomaton.Node addNode() {
            ACAutomaton.Node node = new ACAutomaton.Node(RANGE);
            node.id = allNodes.size();
            allNodes.add(node);
            return node;
        }

        public ACAutomaton(int minCharacter, int maxCharacter) {
            MIN_CHARACTER = minCharacter;
            MAX_CHARACTER = maxCharacter;
            RANGE = maxCharacter - minCharacter + 1;
            root = addNode();
        }

        public void beginBuilding() {
            buildLast = root;
        }

        public void endBuilding() {
            Deque<ACAutomaton.Node> deque = new ArrayDeque(allNodes.size());
            for (int i = 0; i < RANGE; i++) {
                if (root.next[i] != null) {
                    deque.addLast(root.next[i]);
                }
            }

            while (!deque.isEmpty()) {
                ACAutomaton.Node head = deque.removeFirst();
                ACAutomaton.Node fail = visit(head.father.fail, head.index);
                if (fail == null) {
                    head.fail = root;
                } else {
                    head.fail = fail.next[head.index];
                }
                head.preSum = head.cnt + head.fail.preSum;
                for (int i = 0; i < RANGE; i++) {
                    if (head.next[i] != null) {
                        deque.addLast(head.next[i]);
                    }
                }
            }

            for (int i = 0; i < RANGE; i++) {
                if (root.next[i] != null) {
                    deque.addLast(root.next[i]);
                } else {
                    root.next[i] = root;
                }
            }
            while (!deque.isEmpty()) {
                ACAutomaton.Node head = deque.removeFirst();
                for (int i = 0; i < RANGE; i++) {
                    if (head.next[i] != null) {
                        deque.addLast(head.next[i]);
                    } else {
                        head.next[i] = head.fail.next[i];
                    }
                }
            }
        }

        public ACAutomaton.Node visit(ACAutomaton.Node trace, int index) {
            while (trace != null && trace.next[index] == null) {
                trace = trace.fail;
            }
            return trace;
        }

        public void build(char c) {
            int index = c - MIN_CHARACTER;
            if (buildLast.next[index] == null) {
                ACAutomaton.Node node = addNode();
                node.father = buildLast;
                node.index = index;
                buildLast.next[index] = node;
            }
            buildLast = buildLast.next[index];
        }

        public static class Node {
            public ACAutomaton.Node[] next;
            ACAutomaton.Node fail;
            ACAutomaton.Node father;
            int index;
            int id;
            int cnt;
            int preSum;

            public int getId() {
                return id;
            }

            public Node(int range) {
                next = new ACAutomaton.Node[range];
            }

        }

    }
}