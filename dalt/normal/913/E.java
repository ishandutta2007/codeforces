
import java.io.*;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

/**
 * Created by Administrator on 2018/3/22.
 */
public class CF913E {
    static final int PARENTHESIS = 0;
    static final int NOT = 1;
    static final int AND = 2;
    static final int OR = 3;
    public static BlockReader input;
    public static PrintStream output;
    static Node[][] nodes = new Node[256][4];

    public static void main(String[] args) throws FileNotFoundException {
        init();

        for (int t = input.nextInteger(); t > 0; t--) {
            solve();
        }

        output.flush();
    }

    public static int parseBinaryText(String s) {
        int r = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            r = (r << 1) + s.charAt(i) - '0';
        }
        return r;
    }

    public static void init() throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF913E.in"));
            output = System.out;
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }

        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 4; j++) {
                nodes[i][j] = new Node();
                nodes[i][j].op = j;
            }
        }

        Node x = nodes[parseBinaryText("00001111")][0];
        x.expression = "x";
        x.op = 0;

        Node y = nodes[parseBinaryText("00110011")][0];
        y.expression = "y";
        y.op = 0;

        Node z = nodes[parseBinaryText("01010101")][0];
        z.expression = "z";
        z.op = 0;

        for (int i = 0; i < 256; i++) {
            //Parenthesis
            for (int t = 1; t < 4; t++) {
                buildEdge(nodes[i][t], null, nodes[i][PARENTHESIS]);
            }
            int not = (~i) & 255;
            buildEdge(nodes[i][0], null, nodes[not][NOT]);
            for (int j = 0; j < 4; j++) {
                for (int k = i + 1; k < 256; k++) {
                    int or = i | k;
                    int and = i & k;

                    for (int t = 0; t < 4; t++) {
                        if (j <= AND && t <= AND && (and & i) != i) {
                            buildEdge(nodes[i][j], nodes[k][t], nodes[and][AND]);
                        }
                        if (or != k) {
                            buildEdge(nodes[i][j], nodes[k][t], nodes[or][OR]);
                        }
                    }
                }
            }
        }

        //Run spfa
        Deque<Node> deque = new ArrayDeque<>(1024);
        deque.add(x);
        deque.add(y);
        deque.add(z);
        x.instk = true;
        y.instk = true;
        z.instk = true;

        while (!deque.isEmpty()) {
            Node head = deque.removeFirst();
            head.instk = false;
            for (Edge edge : head.edgeList) {
                if (improve(edge) && !edge.dst.instk) {
                    edge.dst.instk = true;
                    deque.addLast(edge.dst);
                }
            }
        }
    }

    public static boolean improve(Edge edge) {
        Node s1 = edge.src;
        Node s2 = edge.src2;
        Node dst = edge.dst;

        switch (dst.op) {
            case PARENTHESIS:
                if (dst.expression == null || dst.expression.length() > s1.expression.length() + 2) {
                    dst.expression = "(" + s1.expression + ")";
                    return true;
                }
                if (dst.expression.length() == s1.expression.length() + 2) {
                    String newOne = "(" + s1.expression + ")";
                    if (dst.expression.compareTo(newOne) > 0) {
                        dst.expression = newOne;
                        return true;
                    }
                }
                break;
            case NOT:
                if (dst.expression == null || dst.expression.length() > s1.expression.length() + 1) {
                    dst.expression = "!" + s1.expression;
                    return true;
                }
                if (dst.expression.length() == s1.expression.length() + 1) {
                    String newOne = "!" + s1.expression;
                    if (dst.expression.compareTo(newOne) > 0) {
                        dst.expression = newOne;
                        return true;
                    }
                }
                break;
            case AND:
            case OR:
                if (s2.expression == null || s1.expression == null) {
                    return false;
                }
                char sign = dst.op == AND ? '&' : '|';
                String minExpression = s1.expression.compareTo(s2.expression) < 0 ? s1.expression : s2.expression;
                String maxExpression = s1.expression == minExpression ? s2.expression : s1.expression;
                if (dst.expression == null || dst.expression.length() > minExpression.length() + maxExpression.length() + 1) {
                    dst.expression = minExpression + sign + maxExpression;
                    return true;
                }
                if (dst.expression.length() == minExpression.length() + maxExpression.length() + 1) {
                    String newOne = minExpression + sign + maxExpression;
                    if (dst.expression.compareTo(newOne) > 0) {
                        dst.expression = newOne;
                        return true;
                    }
                }
                break;
        }
        return false;
    }

    public static void buildEdge(Node src, Node src2, Node dst) {
        Edge edge = new Edge();
        edge.src = src;
        edge.src2 = src2;
        edge.dst = dst;

        src.edgeList.add(edge);
        if (src2 != null) {
            src2.edgeList.add(edge);
        }
    }

    public static void solve() {
        output.println(minExpression(nodes[parseBinaryText(input.nextBlock())]));
    }

    public static String minExpression(Node[] nodes) {
        String best = nodes[0].expression;
        for (int i = 1, until = nodes.length; i < until; i++) {
            String newExp = nodes[i].expression;
            if (newExp == null) {
                continue;
            }
            if (best == null || newExp.length() < best.length() || (newExp.length() == best.length() && newExp.compareTo(best) < 0)) {
                best = newExp;
            }
        }
        return best;
    }

    public static class Node {
        boolean instk;

        List<Edge> edgeList = new ArrayList<>();
        String expression;
        int op;

        @Override
        public String toString() {
            return expression;
        }
    }

    public static class Edge {
        Node src;
        Node src2;
        Node dst;
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