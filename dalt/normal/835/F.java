import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PushbackInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;


/**
 * Created by Administrator on 2017/9/6.
 */
public class RoadsInTheKingdom2 {
    private static final long INFINITE_SMALL = (long) (-1e14);
    int n;
    Node[] allNodes;
    LinkedList<Node> loop = new LinkedList<>();
    LinkedList<Long> distanceToNextNode = new LinkedList<>();

    public static void main(String[] args) throws Exception {
        RoadsInTheKingdom2 instance = new RoadsInTheKingdom2();
        instance.init(new AcmInputReader(System.in));
        long result = instance.solve();
        System.out.println(result);
    }

    void init(AcmInputReader input) throws Exception {
        n = input.nextInteger();
        allNodes = new Node[n];
        for (int i = 0; i < n; i++) {
            allNodes[i] = new Node();
            allNodes[i].id = i + 1;
        }
        for (int i = 0; i < n; i++) {
            int ui = input.nextInteger() - 1;
            int vi = input.nextInteger() - 1;
            int li = input.nextInteger();
            allNodes[ui].addNearNode(allNodes[vi], li);
            allNodes[vi].addNearNode(allNodes[ui], li);
        }
    }

    boolean searchLoop(Node node, Node from)
    {
        if (node.flag == Node.FLAG_VISITED) {
            //find a loop, and (from, node) is an edge in loop
            //Remove (from, node)
            long distance = node.removeNearNode(from);
            from.removeNearNode(node);
            searchLoop0(node, from, null);
            loop.add(node);
            distanceToNextNode.add(distance);
            node.flag = Node.FLAG_IN_LOOP;
            return true;
        }
        node.flag = Node.FLAG_VISITED;
        for (Node next : node.nearNodes) {
            if (next == from) {
                continue;
            }
            if(searchLoop(next, node))
            {
                return true;
            }
        }
        return false;
    }

    boolean searchLoop0(Node node, Node target, Node from) {
        if (node == target) {
            return true;
        }
        Iterator<Long> distanceIterator = node.distanceTo.iterator();
        for (Node next : node.nearNodes) {
            Long distanceTo = distanceIterator.next();
            if (next == from) {
                continue;
            }
            if (searchLoop0(next, target, node)) {
                loop.add(next);
                distanceToNextNode.add(distanceTo);
                next.flag = Node.FLAG_IN_LOOP;
                return true;
            }
        }
        return false;
    }

    void preCalculateEndAndMid(Node node, Node from) {
        Iterator<Long> distanceIterator = node.distanceTo.iterator();
        SimpleHeap heap = new SimpleHeap();
        long maxMid = 0;
        for (Node next : node.nearNodes) {
            Long distanceTo = distanceIterator.next();
            if (next.flag == Node.FLAG_IN_LOOP) {
                continue;
            }
            if (next == from) {
                continue;
            }
            preCalculateEndAndMid(next, node);
            heap.update(distanceTo + next.end);
            maxMid = Math.max(maxMid, next.mid);
        }

        node.end = heap.max;
        node.mid = Math.max(heap.max + heap.secondaryMax, maxMid);
    }

    void preCalculateAloneRelatedGraph() {
        for (Node node : loop) {
            preCalculateEndAndMid(node, null);
        }
    }

    long solve() {
        searchLoop(allNodes[0], null);
        preCalculateAloneRelatedGraph();
        long possibleResult = 0;
        for (Node node : loop) {
            possibleResult = possibleResult > node.mid ? possibleResult : node.mid;
        }

        //DP part
        int loopSize = loop.size();
        long[] cross = new long[loopSize];
        long[] left = new long[loopSize];
        long[] right = new long[loopSize];
        {
            long[] w = new long[loopSize];
            long[] m = new long[loopSize];
            long[] lw = new long[loopSize];
            long[] lm = new long[loopSize];
            long[] rw = new long[loopSize];
            long[] rm = new long[loopSize];
            long distanceToFirstVertexInLoop = 0;
            {
                int i = 0;
                Iterator<Long> distanceIterator = distanceToNextNode.iterator();
                for (Node node : loop) {
                    w[i] = node.end + distanceToFirstVertexInLoop;
                    m[i] = node.end - distanceToFirstVertexInLoop;
                    distanceToFirstVertexInLoop += distanceIterator.next();
                    i++;
                }
            }
            lw[0] = INFINITE_SMALL;
            lm[0] = INFINITE_SMALL;
            left[0] = INFINITE_SMALL;
            for (int i = 1; i < loopSize; i++) {
                lw[i] = Math.max(lw[i - 1], w[i - 1]);
                lm[i] = Math.max(lm[i - 1], m[i - 1]);
                left[i] = Math.max(left[i - 1], lm[i] + w[i]);
            }
            rw[loopSize - 1] = INFINITE_SMALL;
            rm[loopSize - 1] = INFINITE_SMALL;
            right[loopSize - 1] = INFINITE_SMALL;
            for (int i = loopSize - 2; i >= 0; i--) {
                rw[i] = Math.max(rw[i + 1], w[i + 1]);
                rm[i] = Math.max(rm[i + 1], m[i + 1]);
                right[i] = Math.max(right[i + 1], rw[i + 1] + m[i + 1]);
            }

            for (int i = 0, bound = loopSize - 1; i < bound; i++) {
                cross[i] = rm[i] + lw[i + 1] + distanceToFirstVertexInLoop;
            }
        }

        //Find the best solution with DP results
        long minInconvenienceCrossLoop = left[loopSize - 1];
        for (int i = 0, bound = loopSize - 1; i < bound; i++) {
            long inconvenience = 0;
            inconvenience = Math.max(left[i], inconvenience);
            inconvenience = Math.max(right[i], inconvenience);
            inconvenience = Math.max(cross[i], inconvenience);
            minInconvenienceCrossLoop = Math.min(minInconvenienceCrossLoop, inconvenience);
        }
        return Math.max(minInconvenienceCrossLoop, possibleResult);
    }

    private static class SimpleHeap {
        long max = 0;
        long secondaryMax = 0;

        void update(long value) {
            if (value > max) {
                secondaryMax = max;
                max = value;
            } else if (value > secondaryMax) {
                secondaryMax = value;
            }
        }
    }

    private static class Node {
        public static final int FLAG_VISITED = 1;
        public static final int FLAG_IN_LOOP = 2;
        List<Node> nearNodes = new LinkedList<>();
        List<Long> distanceTo = new LinkedList<>();
        long end;
        long mid;
        int flag;
        int id;

        @Override
        public String toString() {
            return "" + id;
        }

        void addNearNode(Node node, long distance) {
            nearNodes.add(node);
            distanceTo.add(distance);
        }

        long distanceTo(Node node) {
            Iterator<Node> nodeIterator = nearNodes.iterator();
            Iterator<Long> distanceIteartor = distanceTo.iterator();
            while (nodeIterator.next() != node) {
                distanceIteartor.next();
            }
            return distanceIteartor.next();
        }

        long removeNearNode(Node node) {
            Iterator<Node> nodeIterator = nearNodes.iterator();
            Iterator<Long> distanceIteartor = distanceTo.iterator();

            while (nodeIterator.next() != node) {
                distanceIteartor.next();
            }
            nodeIterator.remove();
            long result =  distanceIteartor.next();
            distanceIteartor.remove();
            return result;
        }
    }

    /**
     * @author dalt
     * @see java.lang.AutoCloseable
     * @since java1.7
     */
    private static class AcmInputReader implements AutoCloseable {
        private PushbackInputStream in;

        /**
         * 
         *
         * @param input 
         */
        public AcmInputReader(InputStream input) {
            in = new PushbackInputStream(new BufferedInputStream(input));
        }

        @Override
        public void close() throws IOException {
            in.close();
        }

        private int nextByte() throws IOException {
            return in.read() & 0xff;
        }

        /**
         * b
         *
         * @param b 
         * @throws IOException if 
         */
        public void skipByte(int b) throws IOException {
            int c;
            if ((c = nextByte()) != b) {
                in.unread(c);
            }
        }

        /**
         * kbk{@literal k<times}
         *
         * @param b     
         * @param times -1
         * @throws IOException if 
         */
        public void skipByte(int b, int times) throws IOException {
            int c;
            while ((c = nextByte()) == b && times > 0) {
                times--;
            }
            if (c != b) {
                in.unread(c);
            }
        }

        /**
         * {@link #skipByte(int, int)}, 
         *
         * @param b     
         * @param times -1
         * @throws IOException if 
         */
        public void skipBlankAndByte(int b, int times) throws IOException {
            int c;
            skipBlank();
            while ((c = nextByte()) == b && times > 0) {
                times--;
                skipBlank();
            }
            if (c != b) {
                in.unread(c);
            }
        }

        /**
         * 
         *
         * @return 
         * @throws IOException if 
         */
        public String nextBlock() throws IOException {
            skipBlank();
            StringBuilder sb = new StringBuilder();
            int c = nextByte();
            while (AsciiMarksLazyHolder.asciiMarks[c = nextByte()] != AsciiMarksLazyHolder.BLANK_MARK) {
                sb.append((char) c);
            }
            in.unread(c);
            return sb.toString();
        }

        /**
         * 
         *
         * @throws IOException if 
         */
        private void skipBlank() throws IOException {
            int c;
            while ((c = nextByte()) <= 32) ;
            in.unread(c);
        }

        /**
         * 
         *
         * @return 
         * @throws IOException if 
         */
        public int nextInteger() throws IOException {
            skipBlank();
            int value = 0;
            boolean positive = true;
            int c = nextByte();
            if (AsciiMarksLazyHolder.asciiMarks[c] == AsciiMarksLazyHolder.SIGN_MARK) {
                positive = c == '+';
            } else {
                value = '0' - c;
            }
            c = nextByte();
            while (AsciiMarksLazyHolder.asciiMarks[c] == AsciiMarksLazyHolder.NUMERAL_MARK) {
                value = (value << 3) + (value << 1) + '0' - c;
                c = nextByte();
            }

            in.unread(c);
            return positive ? -value : value;
        }

        /**
         * 
         *
         * @return truefalse
         * @throws IOException if 
         */
        public boolean isMeetEOF() throws IOException {
            int c = nextByte();
            if (AsciiMarksLazyHolder.asciiMarks[c] == AsciiMarksLazyHolder.EOF) {
                return true;
            }
            in.unread(c);
            return false;
        }

        /**
         * 
         *
         * @return truefalse
         * @throws IOException if 
         */
        public boolean isMeetBlankAndEOF() throws IOException {
            skipBlank();
            int c = nextByte();
            if (AsciiMarksLazyHolder.asciiMarks[c] == AsciiMarksLazyHolder.EOF) {
                return true;
            }
            in.unread(c);
            return false;
        }

        /**
         * 
         *
         * @return 
         */
        public String nextWord() throws IOException {
            StringBuilder sb = new StringBuilder(16);
            skipBlank();
            int c;
            while ((AsciiMarksLazyHolder.asciiMarks[(c = nextByte())] & AsciiMarksLazyHolder.LETTER_MARK) != 0) {
                sb.append((char) c);
            }
            in.unread(c);
            return sb.toString();
        }

        /**
         * 
         *
         * @return 
         * @throws IOException if 
         */
        public long nextLong() throws IOException {
            skipBlank();
            long value = 0;
            boolean positive = true;
            int c = nextByte();
            if (AsciiMarksLazyHolder.asciiMarks[c] == AsciiMarksLazyHolder.SIGN_MARK) {
                positive = c == '+';
            } else {
                value = '0' - c;
            }
            c = nextByte();
            while (AsciiMarksLazyHolder.asciiMarks[c] == AsciiMarksLazyHolder.NUMERAL_MARK) {
                value = (value << 3) + (value << 1) + '0' - c;
                c = nextByte();
            }
            in.unread(c);
            return positive ? -value : value;
        }

        /**
         * 
         *
         * @return 
         * @throws IOException if 
         */
        public float nextFloat() throws IOException {
            return (float) nextDouble();
        }

        /**
         * 
         *
         * @return 
         * @throws IOException if 
         */
        public double nextDouble() throws IOException {
            skipBlank();
            double value = 0;
            boolean positive = true;
            int c = nextByte();
            if (AsciiMarksLazyHolder.asciiMarks[c] == AsciiMarksLazyHolder.SIGN_MARK) {
                positive = c == '+';
            } else {
                value = c - '0';
            }
            c = nextByte();
            while (AsciiMarksLazyHolder.asciiMarks[c] == AsciiMarksLazyHolder.NUMERAL_MARK) {
                value = value * 10.0 + c - '0';
                c = nextByte();
            }

            if (c == '.') {
                double littlePart = 0;
                double base = 1;
                c = nextByte();
                while (AsciiMarksLazyHolder.asciiMarks[c] == AsciiMarksLazyHolder.NUMERAL_MARK) {
                    littlePart = littlePart * 10.0 + c - '0';
                    base *= 10.0;
                    c = nextByte();
                }
                value += littlePart / base;
            }
            in.unread(c);
            return positive ? value : -value;
        }

        /**
         * 
         *
         * @return 
         * @throws IOException if 
         */
        public BigDecimal nextDecimal() throws IOException {
            skipBlank();
            StringBuilder sb = new StringBuilder();
            sb.append((char) nextByte());
            int c = nextByte();
            while (AsciiMarksLazyHolder.asciiMarks[c] == AsciiMarksLazyHolder.NUMERAL_MARK) {
                sb.append((char) c);
                c = nextByte();
            }
            if (c == '.') {
                sb.append('.');
                c = nextByte();
                while (AsciiMarksLazyHolder.asciiMarks[c] == AsciiMarksLazyHolder.NUMERAL_MARK) {
                    sb.append((char) c);
                    c = nextByte();
                }
            }
            in.unread(c);
            return new BigDecimal(sb.toString());
        }

        /**
         * 
         *
         * @return 
         * @throws IOException if 
         */
        public BigInteger nextBigInteger() throws IOException {
            skipBlank();
            StringBuilder sb = new StringBuilder();
            sb.append((char) nextByte());
            int c = nextByte();
            while (AsciiMarksLazyHolder.asciiMarks[c] == AsciiMarksLazyHolder.NUMERAL_MARK) {
                sb.append((char) c);
                c = nextByte();
            }
            in.unread(c);
            return new BigInteger(sb.toString());
        }

        private static class AsciiMarksLazyHolder {
            public static final byte BLANK_MARK = 1;
            public static final byte SIGN_MARK = 1 << 1;
            public static final byte NUMERAL_MARK = 1 << 2;
            public static final byte UPPERCASE_LETTER_MARK = 1 << 3;
            public static final byte LOWERCASE_LETTER_MARK = 1 << 4;
            public static final byte LETTER_MARK = UPPERCASE_LETTER_MARK | LOWERCASE_LETTER_MARK;
            public static final byte EOF = 1 << 5;
            public static byte[] asciiMarks = new byte[256];

            static {
                for (int i = 0; i <= 32; i++) {
                    asciiMarks[i] = BLANK_MARK;
                }
                asciiMarks['+'] = SIGN_MARK;
                asciiMarks['-'] = SIGN_MARK;
                for (int i = '0'; i <= '9'; i++) {
                    asciiMarks[i] = NUMERAL_MARK;
                }
                for (int i = 'a'; i <= 'z'; i++) {
                    asciiMarks[i] = LOWERCASE_LETTER_MARK;
                }
                for (int i = 'A'; i <= 'Z'; i++) {
                    asciiMarks[i] = UPPERCASE_LETTER_MARK;
                }
                asciiMarks[0xff] = EOF;
            }
        }
    }
}