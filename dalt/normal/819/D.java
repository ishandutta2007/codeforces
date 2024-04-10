
import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PushbackInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.TreeMap;

/**
 * Created by dalt on 2017/7/4.
 */
public class Main {
    public static void main(String[] args) throws IOException {
        AcmInputReader reader = new AcmInputReader(System.in);

        //Read all input
        int T = reader.nextInteger();
        int n = reader.nextInteger();

        AstronomerNode[] astronomerNodes = new AstronomerNode[n];
        astronomerNodes[0] = new AstronomerNode(0);
        astronomerNodes[0].startTime = 0;
        int firstTakeTime = reader.nextInteger();
        int L = 0;
        for (int i = 1; i < n; i++) {
            int wi = reader.nextInteger();
            L = (L + wi) % T;
            astronomerNodes[i] = new AstronomerNode(i);
            astronomerNodes[i].startTime = L;
        }
        L = (L + firstTakeTime) % T;

        //Link all astronomer with cycles
        int c = DiscreteMath.gcd(T, L);
        TreeMap<Integer, List<AstronomerNode>> map = new TreeMap<Integer, List<AstronomerNode>>();

        for (int i = 0; i < n; i++) {
            Integer cycleId = astronomerNodes[i].startTime % c;
            List<AstronomerNode> list = map.get(cycleId);
            if (list == null) {
                list = new ArrayList<>();
                map.put(cycleId, list);
            }
            list.add(astronomerNodes[i]);
        }

        int[] coe = DiscreteMath.axPlusByEqualToZeroCoefficients(L, T, c);
        int q = coe[0];
        int w = coe[1];
        coe = DiscreteMath.axPlusByEqualToCCoefficients(L, T);
        coe = DiscreteMath.minimizeXOfAxPlusByEqualToZEquation(coe[0], coe[1], q, w);
        int x = (int)coe[0];
        int y = (int)coe[1];

        for (List<AstronomerNode> list : map.values()) {
            AstronomerNode base = list.get(0);
            base.loopCount = 0;
            for (int i = 1, bound = list.size(); i < bound; i++) {
                AstronomerNode node = list.get(i);
                int offset = node.startTime - base.startTime;
                if (offset < 0) {
                    offset += T;
                }
                int loopCount = offset / c;
                int[] minCoe = DiscreteMath.minimizeXOfAxPlusByEqualToZEquation((long)x * loopCount, (long)y * loopCount, q, w);
                node.loopCount = minCoe[0];
            }

            Collections.sort(list);
            AstronomerNode lastNode = list.get(0);
            for(int i = 1, bound = list.size(); i < bound; i++)
            {
                AstronomerNode curNode = list.get(i);
                lastNode.timePieceCount = curNode.loopCount - lastNode.loopCount;
                lastNode = curNode;
            }
            lastNode.timePieceCount = q - lastNode.loopCount;
        }

        for(AstronomerNode node : astronomerNodes)
        {
            System.out.print(node.timePieceCount);
            System.out.print(' ');
        }
    }

    private static class AstronomerNode implements Comparable<AstronomerNode> {
        public int id;
        public int timePieceCount;
        public int loopCount;
        public int startTime;

        public AstronomerNode(int id) {
            this.id = id;
        }

        @Override
        public int compareTo(AstronomerNode o) {
            int res = this.loopCount - o.loopCount;
            if (res == 0) {
                return o.id - this.id;
            }
            return res;
        }
    }

    /**
     * Created by dalt on 2017/7/4.
     */
    private static final class DiscreteMath {
        private DiscreteMath() {
        }

        ;

        /**
         * Calculate the greatest common divisor of a and b
         *
         * @param a a non-negative integer
         * @param b a non-negative integer or a positive integer if a == 0
         * @return the greatest common divisor of a and b
         */
        public static int gcd(int a, int b) {
            if (a < 0 || b < 0 || (a + b <= 0)) {
                throw new IllegalArgumentException();
            }
            if (a >= b) {
                return gcdInner(a, b);
            }
            return gcdInner(b, a);
        }

        private static int gcdInner(int a, int b) {
            if (b == 0) {
                return a;
            }
            return gcdInner(b, a % b);
        }

        /**
         * Calculate a possible coefficent(x,y) of equation xa + yb = c, and {@code c=gcd(a,b)}
         *
         * @param a a non-negative integer
         * @param b a non-negative integer or a positive integer if a == 0
         * @return an array contains integer, the first element represent x and the second one is y.
         */
        public static int[] axPlusByEqualToCCoefficients(int a, int b) {
            if (a < 0 || b < 0 || (a + b <= 0)) {
                throw new IllegalArgumentException();
            }
            if (a >= b) {
                return axPlusByEqualToCCoefficientsInner(a, b);
            }
            int[] r = axPlusByEqualToCCoefficientsInner(b, a);
            int rx = r[0];
            r[0] = r[1];
            r[1] = rx;
            return r;
        }


        private static int[] axPlusByEqualToCCoefficientsInner(int a, int b) {
            if (b == 0) {
                return new int[]{1, 0};
            }
            int[] r = axPlusByEqualToCCoefficientsInner(b, a % b);
            int rx = r[0];
            r[0] = r[1];
            r[1] = rx - r[1] * (a / b);
            return r;
        }

        /**
         * Calculate coefficent(x,y) of equation xa + yb = 0, and {@code c=gcd(a,b)},
         * and the returned x is the minimun postive integer of all posible x, the same rule for y.
         *
         * @param a a non-negative integer
         * @param b a non-negative integer or a positive integer if a == 0
         * @return an array contains integer, the first element represent x and the second one is y.
         */
        public static int[] axPlusByEqualToZeroCoefficients(int a, int b) {
            return axPlusByEqualToZeroCoefficients(a, b, gcd(a, b));
        }

        /**
         * Calculate coefficent(x,y) of equation xa + yb = 0, and {@code c=gcd(a,b)},
         * and the returned x is the minimun postive integer of all posible x, the same rule for y.
         * This method is faster than {@link #axPlusByEqualToCCoefficients(int, int)}
         *
         * @param a a non-negative integer
         * @param b a non-negative integer or a positive integer if a == 0
         * @param c the greatest common divisor of a and b
         * @return an array contains integer, the first element represent x and the second one is y.
         */
        public static int[] axPlusByEqualToZeroCoefficients(int a, int b, int c) {
            return new int[]{b / c, a / c};
        }

        /**
         * Minimize such coefficient as x,y suffice for equation xa + yb = z.This method try to minize x as an positive integer.
         *
         * @param x coefficient
         * @param y coefficient
         * @param i the first element of axPlusByEqualToZeroCoefficients(a, b)
         * @param j the second element of axPlusByEqualToZeroCoefficients(a, b)
         * @return the minimized x and corresponding y
         */
        public static int[] minimizeXOfAxPlusByEqualToZEquation(long x, long y, int i, int j) {
            if (x < 0) {
                return new int[]{(int)(x % i + i), (int)(y - (x / i + 1) * j)};
            }
            return new int[]{(int)(x % i), (int)(y - x / i * j)};
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