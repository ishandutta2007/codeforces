
import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PushbackInputStream;
import java.math.BigDecimal;
import java.util.Map;
import java.util.TreeMap;

/**
 * Created by dalt on 2017/9/10.
 */
public class BruteForcePrefixSums {
    int n;
    long threshold;
    long[] basic;

    public static void main(String[] args) throws Exception {
        BruteForcePrefixSums solution = new BruteForcePrefixSums();
        solution.init();
        long result = solution.solve();
        System.out.println(result);
    }

    public void init() throws Exception {
        AcmInputReader input = new AcmInputReader(System.in);
        n = input.nextInteger();
        threshold = input.nextLong();
        basic = new long[n];

        for (int i = 0; i < n; i++) {
            basic[i] = input.nextLong();
        }
    }

    public long solve() {
        //Remove prefix blank
        {
            int firstNotZero = 0;
            while (basic[firstNotZero] == 0) {
                firstNotZero++;
            }
            long[] tmp = new long[n - firstNotZero];
            System.arraycopy(basic, firstNotZero, tmp, 0, tmp.length);
            n = tmp.length;
            basic = tmp;
        }

        //Test whether A0 satisfy the threshold
        for (long value : basic) {
            if (value >= threshold) {
                return 0;
            }
        }

        //n is more than 18, so brute force
        if (n >= 10) {
            return bruteForceProcess();
        }
        //Try fast matrix
        else {
            return binarySearch(basic);
        }
    }

    public long binarySearch(long[] vector) {
        long[][] a0 = new long[vector.length][vector.length];
        for (int i = 0, bound = vector.length; i < bound; i++) {
            for (int j = 0; j <= i; j++) {
                a0[i][j] = 1;
            }
        }

        TreeMap<Long, long[][]> cache = new TreeMap<>();
        cache.put(1L, a0);

        //Find lower bound and upper bound
        long lowerAge = 0;
        long[][] lowerMat = null;
        long upperAge = 1;
        long[][] upperMat = a0;
        while (!contain(upperMat, vector)) {
            lowerMat = upperMat;
            lowerAge = upperAge;
            cache.put(lowerAge, lowerMat);
            upperMat = multiply(upperMat, upperMat);
            upperAge *= 2;
        }

        //Binary search part
        while (lowerAge < upperAge) {
            long halfAge = (lowerAge + upperAge + 1) / 2;

            //Calculate a0^half in fast way
            Map.Entry<Long, long[][]> entry = cache.floorEntry(halfAge);
            long remain = halfAge - entry.getKey();
            long[][] halfMat = entry.getValue();
            while (remain > 0) {
                entry = cache.floorEntry(remain);
                remain = remain - entry.getKey();
                halfMat = multiply(halfMat, entry.getValue());
            }

            if (contain(halfMat, vector)) {
                upperAge = halfAge - 1;
                upperMat = halfMat;
            } else {
                lowerAge = halfAge;
                lowerMat = halfMat;
            }
        }
        return lowerAge + 1;
    }

    public boolean contain(long[][] mat, long[] vector) {
        long[] result = new long[vector.length];
        int row = mat.length;
        long max = 0;
        int col = mat[0].length;
        for (int i = 0; i < row; i++) {
            long aggregation = 0;
            for (int j = 0; j < col; j++) {
                long value = mat[i][j] * vector[j];
                if (value >= threshold) {
                    return true;
                }
                aggregation += mat[i][j] * vector[j];
            }
            if (aggregation < 0 || aggregation >= threshold) {
                return true;
            }
        }
        return false;
    }

    public long[][] multiply(long[][] a, long[][] b) {
        long[][] result = new long[a.length][b[0].length];
        int row = a.length;
        int col = b[0].length;
        int mid = b.length;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                long aggregation = 0;
                for (int k = 0; k < mid; k++) {
                    aggregation += a[i][k] * b[k][j];
                }
                result[i][j] = aggregation < 0 ? Long.MAX_VALUE : aggregation;
            }
        }
        return result;
    }

    public long bruteForceProcess() {
        int age = 0;
        while (true) {
            age++;
            for (int i = 1; i < n; i++) {
                basic[i] = basic[i - 1] + basic[i];
                if (basic[i] >= threshold) {
                    return age;
                }
            }
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