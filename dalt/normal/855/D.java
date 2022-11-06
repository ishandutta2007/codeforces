
import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PushbackInputStream;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by Administrator on 2017/11/23.
 */
public class RowenaRavenclawsDiadem {
    private static final String YES = "YES\n";
    private static final String NO = "NO\n";
    int n;
    Node[] nodes;
    AcmInputReader reader;

    public static void main(String[] args) throws IOException {
        RowenaRavenclawsDiadem solution = new RowenaRavenclawsDiadem();
        solution.init();
        String result = solution.solve();
        System.out.println(result);
    }

    public void init() throws IOException {
        reader = new AcmInputReader(System.in);

        n = reader.nextInteger();

        nodes = new Node[n];

        for (int i = 0; i < n; i++) {
            nodes[i] = new Node();

            int parent = reader.nextInteger() - 1;
            int relation = reader.nextInteger();

            switch (relation) {
                //No relation
                case -1:
                    nodes[i].ancestor = nodes[i];
                    nodes[i].eldestBrother = nodes[i];
                    break;
                //Brother
                case 0:
                    nodes[i].eldestBrother = nodes[parent].eldestBrother;
                    nodes[i].ancestor = nodes[i];
                    nodes[parent].brothers.add(nodes[i]);
                    break;
                //Parent
                case 1:
                    nodes[i].eldestBrother = nodes[i];
                    nodes[i].ancestor = nodes[parent].ancestor;
                    nodes[parent].children.add(nodes[i]);
                    break;
            }
        }

        //Allocate the num
        int[] horizontalNum = new int[]{0};
        int[] verticalNum = new int[]{0};
        for (Node node : nodes) {
            horizontalVisit(node, horizontalNum);
            verticalVisit(node, verticalNum);
        }
    }

    public String solve() throws IOException {
        StringBuilder result = new StringBuilder();

        int q = reader.nextInteger();
        for (int i = 0; i < q; i++) {
            int type = reader.nextInteger();
            int u = reader.nextInteger() - 1;
            int v = reader.nextInteger() - 1;


            switch (type) {
                //Brother test
                case 1:
                    result.append(u != v && nodes[u].isBrotherOf(nodes[v]) ? YES : NO);
                    break;
                //Ancestor test
                case 2:
                    result.append(
                            u != v && !nodes[v].isBrotherOf(nodes[u]) &&
                             (nodes[v].ancestor == nodes[u]
                                     || nodes[v].ancestor.isBrotherOf(nodes[u])
                                     || nodes[u].eldestBrother.isAncestorOf(nodes[v]))
                                    ? YES : NO
                    );
                    break;
            }
        }

        return result.toString();
    }

    public void horizontalVisit(Node node, int[] horizontalVal) {
        if (node == null || node.horizontalRange.hasBeenInitialized()) {
            return;
        }

        node.horizontalRange.begin = ++horizontalVal[0];
        for (Node brother : node.brothers) {
            horizontalVisit(brother, horizontalVal);
        }
        node.horizontalRange.end = horizontalVal[0];
    }

    public void verticalVisit(Node node, int[] verticalVal) {
        if (node == null || node.verticalRange.hasBeenInitialized()) {
            return;
        }

        node.verticalRange.begin = ++verticalVal[0];
        for (Node child : node.children) {
            verticalVisit(child, verticalVal);
        }
        node.verticalRange.end = verticalVal[0];
    }

    static class Node {
        public Node eldestBrother;
        public Node ancestor;
        public List<Node> brothers = new ArrayList<>();
        public List<Node> children = new ArrayList<>();

        Range horizontalRange = new Range();
        Range verticalRange = new Range();

        public boolean isBrotherOf(Node other) {
            return horizontalRange.contain(other.horizontalRange.begin - 1);
        }

        public boolean isAncestorOf(Node other) {
            return verticalRange.contain(other.verticalRange.begin - 1);
        }
    }

    static class Range {
        int begin = -1;
        int end = -1;

        public boolean hasBeenInitialized() {
            return begin != -1;
        }

        public boolean contain(int other) {
            return other >= begin && other < end;
        }
    }


    /**
     * @author dalt
     * @see java.lang.AutoCloseable
     * @since java1.7
     */
    static class AcmInputReader implements AutoCloseable {
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