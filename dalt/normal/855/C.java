
import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PushbackInputStream;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by dalt on 2017/9/24.
 */
public class HelgaHufflepuffsCup {

    final int LESS_THAN_K = 0;
    final int EQUAL_TO_K = 1;
    final int GREATER_THAN_K = 2;
    int n;
    int m;
    int k;
    int x;
    Node[] allNodes;
    long[][] backup;
    long modulo = 1000000000 + 7;
    int lessInitVal;
    int equalInitVal;
    int greaterInitVal;

    public static void main(String[] args) throws Exception {
        HelgaHufflepuffsCup solution = new HelgaHufflepuffsCup();
        solution.init();
        long result = solution.solve();
        System.out.println(result);
    }

    public void init() throws Exception {
        AcmInputReader input = new AcmInputReader(System.in);
        n = input.nextInteger();
        m = input.nextInteger();

        allNodes = new Node[n];
        for (int i = 0; i < n; i++) {
            allNodes[i] = new Node();
            allNodes[i].id = i + 1;
        }
        for (int i = 1; i < n; i++) {
            int n1 = input.nextInteger() - 1;
            int n2 = input.nextInteger() - 1;
            allNodes[n1].nearBy.add(allNodes[n2]);
            allNodes[n2].nearBy.add(allNodes[n1]);
        }

        k = input.nextInteger();
        x = input.nextInteger();
    }

    public long solve() {
        //Mark allNodes[0] as the root of tree
        backup = new long[3][x + 1];

        lessInitVal = k - 1;
        equalInitVal = 1;
        greaterInitVal = m - k;

        detect(allNodes[0], null);

        long sum = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j <= x; j++) {
                sum += allNodes[0].maybe[i][j];
            }
        }
        return sum % modulo;
    }

    public void detect(Node node, Node parent) {
        long[][] maybe = new long[3][x + 1];

        maybe[0][0] = lessInitVal;
        maybe[1][1] = equalInitVal;
        maybe[2][0] = greaterInitVal;

        for (Node nearby : node.nearBy) {
            if (nearby == parent) {
                continue;
            }

            detect(nearby, node);
            combineInto(backup, maybe, nearby.maybe);
            {
                long[][] tmp = backup;
                backup = maybe;
                maybe = tmp;
            }
        }

        node.maybe = maybe;
    }

    public void combineInto(long[][] result, long[][] father, long[][] kid) {
        for (int i = 0; i <= x; i++) {
            long result0i = 0;
            long result1i = 0;
            long result2i = 0;
            for (int j = 0; j <= i; j++) {
                result0i += (father[0][i - j] * (kid[0][j] + kid[1][j] + kid[2][j])) % modulo;
                result1i += (father[1][i - j] * kid[0][j]) % modulo;
                result2i += (father[2][i - j] * (kid[0][j] + kid[2][j])) % modulo;
            }
            result[0][i] = result0i % modulo;
            result[1][i] = result1i % modulo;
            result[2][i] = result2i % modulo;
        }
    }


    static class Node {
        List<Node> nearBy = new ArrayList<>();
        long[][] maybe;
        int id;

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append(id);
            sb.append("\n");
            if (maybe != null) {
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < maybe[i].length; j++) {
                        sb.append(maybe[i][j]);
                        sb.append(", ");
                    }
                    sb.setLength(sb.length() - 2);
                    sb.append("\n");
                }
            }
            return sb.toString();
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