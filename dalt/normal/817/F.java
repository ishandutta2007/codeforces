import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Arrays;

/**
 * Created by dalt on 2017/6/30.
 */
public class Main {
    public static void main(String[] args) throws Exception {
        AcmInputReader reader = new AcmInputReader(System.in);
        int num = reader.nextInteger();

        if (num == 0) {
            return;
        }

        int[] cmds = new int[num];
        long[] leftBounds = new long[num];
        long[] rightBounds = new long[num];

        //read all input into memory
        for (int i = 0; i < num; i++) {
            cmds[i] = reader.nextInteger();
            leftBounds[i] = reader.nextLong();
            rightBounds[i] = reader.nextLong();
        }

        //Generate g
        long[] g = new long[num * 4 + 2];
        System.arraycopy(leftBounds, 0, g, 0, num);
        System.arraycopy(rightBounds, 0, g, num, num);
        for (int i = 0, base1 = num * 2, base2 = num * 3; i < num; i++) {

            g[base1 + i] = Math.max(rightBounds[i] - 1, 1);
            g[base2 + i] = rightBounds[i] + 1;
        }
        g[num * 4] = 1;
        g[num * 4 + 1] = Long.MAX_VALUE;
        Arrays.sort(g);
        //Remove all repeated elements
        int gLen = 0;
        for (int i = 1, bound = g.length; i < bound; i++) {
            if (g[i] != g[gLen]) {
                g[++gLen] = g[i];
            }
        }
        gLen++;

        //Build section tree
        SectionTree tree = new SectionTree(0, gLen);

        //Handle all cmds and output the MEX
        for (int i = 0; i < num; i++) {
            int cmd = cmds[i];
            int leftBound = Arrays.binarySearch(g, 0, gLen, leftBounds[i]);
            int rightBound = Arrays.binarySearch(g, 0, gLen, rightBounds[i] + 1) - 1;

            tree.update(leftBound, rightBound, cmd);

            //Query all information
//            for (int j = 0; j < gLen - 1; j++) {
//                if (tree.queryValue(j, j).maxValue == 1) {
//                    System.out.print(String.format("[%d, %d], ", g[j], g[j + 1] - 1));
//                }
//            }
//            System.out.println();

            System.out.println(g[tree.queryMEX()]);
        }
    }

    /**
     * @author dalt
     * @see java.lang.AutoCloseable
     * @since java1.7
     */
    private static class AcmInputReader implements AutoCloseable {
        private PushbackInputStream in;

        @Override
        public void close() throws IOException {
            in.close();
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

        /**
         * 
         *
         * @param input 
         */
        public AcmInputReader(InputStream input) {
            in = new PushbackInputStream(new BufferedInputStream(input));
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
    }

    private static /**
     * Created by F on 2017/6/29.
     */
    class SectionTree {
        /**
         * 
         */
        private SectionTreeNode root;

        /**
         * 
         */
        public static class ValuePair {
            public static final ValuePair EMPTY_VALUE_PAIR = new ValuePair(Integer.MAX_VALUE, Integer.MIN_VALUE);
            public final int minValue;
            public final int maxValue;

            public ValuePair(int minValue, int maxValue) {
                this.minValue = minValue;
                this.maxValue = maxValue;
            }

            @Override
            public String toString() {
                return String.format("max:%d, min:%d", maxValue, minValue);
            }

            public static ValuePair combine(ValuePair a, ValuePair b) {
                return new ValuePair(Math.min(a.minValue, b.minValue),
                        Math.max(a.maxValue, b.maxValue));
            }
        }

        /**
         * 
         */
        private static class Section {
            /**
             * 
             */
            public static enum SectionRelation {
                INCLUDED, INTERSECT, NONE
            }

            private int leftBound, rightBound;

            public int getLeftBound() {
                return leftBound;
            }

            public int getRightBound() {
                return rightBound;
            }

            public Section(int leftBound, int rightBound) {
                if (rightBound < leftBound) {
                    throw new IllegalArgumentException(String.format("A section should obey leftBound<=rightBound, but current state is %d > %d", leftBound, rightBound));
                }
                this.leftBound = leftBound;
                this.rightBound = rightBound;
            }

            /**
             * thisother
             *
             * @param other 
             * @return thisother
             */
            public SectionRelation relationWith(Section other) {
                if (rightBound < other.leftBound || leftBound > other.rightBound) {
                    return SectionRelation.NONE;
                }
                if (rightBound <= other.rightBound && leftBound >= other.leftBound) {
                    return SectionRelation.INCLUDED;
                }
                return SectionRelation.INTERSECT;
            }

            /**
             * 
             *
             * @return 
             */
            public Section leftHalfSection() {
                return new Section(leftBound, (leftBound + rightBound) / 2);
            }

            /**
             * 
             *
             * @return 
             */
            public Section rightHalfSection() {
                return new Section((leftBound + rightBound) / 2 + 1, rightBound);
            }

            @Override
            public String toString() {
                return String.format("[%d, %d]", leftBound, rightBound);
            }

            /**
             * 
             *
             * @return 
             */
            public int size() {
                return rightBound - leftBound + 1;
            }

            /**
             * 
             *
             * @return truefalse
             */
            public boolean containSingleElement() {
                return rightBound == leftBound;
            }
        }

        /**
         * 
         */
        private static class SectionTreeNode {
            public SectionTreeNode leftChild, rightChild;
            private Section section;
            private int cachedMinValue, cachedMaxValue;
            private int dirtyMark;

            /**
             * 
             *
             * @return
             */
            public Section getSection() {
                return section;
            }

            /**
             * 
             *
             * @param dirtyMark 
             */
            public void setDirtyMark(int dirtyMark) {
                this.dirtyMark += dirtyMark;
            }

            /**
             * section
             *
             * @param section 
             */
            public SectionTreeNode(Section section) {
                this.section = section;
            }

            /**
             * 
             *
             * @return 
             */
            public int getMinValue() {
                switch (dirtyMark) {
                    case 0:
                        return cachedMinValue;
                    case 1:
                        return 1;
                    case 2:
                        return 0;
                    default:
                        return (cachedMaxValue + 1) % 2;
                }
            }

            /**
             * 
             *
             * @return 
             */
            public int getMaxValue() {
                switch (dirtyMark) {
                    case 0:
                        return cachedMaxValue;
                    case 1:
                        return 1;
                    case 2:
                        return 0;
                    default:
                        return (cachedMinValue + 1) % 2;
                }
            }

            /**
             * 
             */
            public void updateCachedValue() {
                cachedMinValue = Math.min(leftChild.getMinValue(), rightChild.getMinValue());
                cachedMaxValue = Math.max(leftChild.getMaxValue(), rightChild.getMaxValue());
            }

            @Override
            public String toString() {
                StringBuilder sb = new StringBuilder(String.format("{lrBound:%s,minMaxValue:[%d,%d],dirtyMark:%d(",
                        section.toString(), cachedMinValue, cachedMaxValue, dirtyMark));
                if (leftChild != null) {
                    sb.append(leftChild.toString());
                }
                sb.append(", ");
                if (rightChild != null) {
                    sb.append(rightChild.toString());
                }
                sb.append(")}");
                return sb.toString();
            }
        }

        /**
         * data
         *
         * @param data 
         */
        public SectionTree(int[] data) {
            this(data, 0, data.length);
        }

        /**
         * data
         *
         * @param data 
         */
        public SectionTree(int[] data, int from, int to) {
            if (from >= to) {
                throw new IllegalArgumentException("You can't build a section tree with empty array");
            }
            this.root = buildTreeNode(data, new Section(from, to - 1));
        }

        @Override
        public String toString() {
            return root.toString();
        }

        /**
         * [leftBound, rightBound]val
         *
         * @param leftBound  
         * @param rightBound 
         * @param val        
         */
        public void update(int leftBound, int rightBound, int val) {
            update(root, new Section(leftBound, rightBound), val);
        }

        /**
         * [leftBound, rightBound]
         *
         * @param leftBound  
         * @param rightBound 
         * @return ValuePair
         */
        public ValuePair queryValue(int leftBound, int rightBound) {
            return queryValue(root, new Section(leftBound, rightBound));
        }

        public static ValuePair queryValue(SectionTreeNode node, Section section) {
            switch (node.getSection().relationWith(section)) {
                case INCLUDED:
                    return new ValuePair(node.getMinValue(), node.getMaxValue());
                case INTERSECT:
                    ValuePair vp = ValuePair.combine(queryValue(node.leftChild, section),
                            queryValue(node.rightChild, section));
                    int min = vp.minValue;
                    int max = vp.maxValue;
                    switch (node.dirtyMark) {
                        case 0:
                            return vp;
                        case 1:
                            return new ValuePair(1, 1);
                        case 2:
                            return new ValuePair(0, 0);
                        case 3:
                            return new ValuePair((max + 1) % 2, (min + 1) % 2);
                    }
            }
            return ValuePair.EMPTY_VALUE_PAIR;
        }

        public static void update(SectionTreeNode node, Section section, int val) {
            switch (node.getSection().relationWith(section)) {
                case INCLUDED:
                    if (val != 3) {
                        node.dirtyMark = val;
                    } else {
                        node.dirtyMark = 3 - node.dirtyMark;
                    }
                    return;
                case INTERSECT:
                    if (node.dirtyMark != 0) {
                        update(node.leftChild, node.section, node.dirtyMark);
                        update(node.rightChild, node.section, node.dirtyMark);
                        node.dirtyMark = 0;
                    }
                    update(node.leftChild, section, val);
                    update(node.rightChild, section, val);
                    node.updateCachedValue();
                    return;
                case NONE:
                    return;
            }
        }

        private static SectionTreeNode buildTreeNode(int[] data, Section section) {
            SectionTreeNode current = new SectionTreeNode(section);
            if (section.containSingleElement()) {
                current.cachedMinValue = current.cachedMaxValue = data[section.getLeftBound()];
                return current;
            }
            current.leftChild = buildTreeNode(data, section.leftHalfSection());
            current.rightChild = buildTreeNode(data, section.rightHalfSection());
            current.updateCachedValue();
            return current;
        }

        public SectionTree(int from, int to) {
            if (to <= from) {
                throw new IllegalArgumentException("You can't build a section tree with empty array");
            }
            this.root = buildZeroizeTreeNode(new Section(from, to - 1));
        }

        private static SectionTreeNode buildZeroizeTreeNode(Section section) {
            SectionTreeNode current = new SectionTreeNode(section);
            if (section.containSingleElement()) {
                return current;
            }
            current.leftChild = buildZeroizeTreeNode(section.leftHalfSection());
            current.rightChild = buildZeroizeTreeNode(section.rightHalfSection());
            return current;
        }

        public int queryMEX() {
            return queryMEX(root, 0);
        }

        private static int queryMEX(SectionTreeNode node, int reverse) {
            if (node.getSection().containSingleElement()) {
                return node.getSection().leftBound;
            }
            reverse = reverse ^ (node.dirtyMark == 3 ? 1 : 0);
            if (reverse == 0) {
                if (node.dirtyMark == 2) {
                    return node.section.leftBound;
                }
                if (node.leftChild.getMinValue() == 0) {
                    return queryMEX(node.leftChild, reverse);
                }
                return queryMEX(node.rightChild, reverse);
            } else {
                if (node.dirtyMark == 1) {
                    return node.section.leftBound;
                }
                if (node.leftChild.getMaxValue() == 1) {
                    return queryMEX(node.leftChild, reverse);
                }
                return queryMEX(node.rightChild, reverse);
            }
        }
    }
}