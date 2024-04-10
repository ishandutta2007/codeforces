

import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Random;

/**
 * Created by dalt on 2018/4/2.
 */
public class CF924D {
    public static final long MOD = (long) (1e9 + 7);
    public static BlockReader input;
    public static PrintStream output;

    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF924D.in"));
            output = System.out;
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }

        solve();

        output.flush();
    }

    public static void solve() {
        int n = input.nextInteger();
        double w = input.nextInteger();

        final int X_INDEX = 0;
        final int V_INDEX = 1;
        final int N1_INDEX = 2;
        final int P1_INDEX = 3;
        double[][] data = new double[n][4];
        for (int i = 0; i < n; i++) {
            data[i][X_INDEX] = input.nextInteger();
            data[i][V_INDEX] = input.nextInteger();
            data[i][N1_INDEX] = -data[i][X_INDEX] / (data[i][V_INDEX] - w);
            data[i][P1_INDEX] = -data[i][X_INDEX] / (data[i][V_INDEX] + w);
        }

        //Rearrange
        Random random = new Random(19950823);
        for (int i = 0; i < n; i++) {
            int j = random.nextInt(n);
            double[] tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }


        double[][] orderByP1 = data.clone();

        Arrays.sort(data, new Comparator<double[]>() {
            @Override
            public int compare(double[] o1, double[] o2) {
                int v = -Double.compare(o1[N1_INDEX], o2[N1_INDEX]);
                if (v == 0) {
                    v = Double.compare(o1[P1_INDEX], o2[P1_INDEX]);
                }
                return v;
            }
        });

        Comparator<double[]> cmp = new Comparator<double[]>() {
            @Override
            public int compare(double[] o1, double[] o2) {
                int v = Double.compare(o1[P1_INDEX], o2[P1_INDEX]);
                if (v == 0) {
                    v = -Double.compare(o1[N1_INDEX], o2[N1_INDEX]);
                }
                return v;
            }
        };
        Arrays.sort(orderByP1, cmp);

        BIT bit = new BIT(n);
        long sum = 0;
        for (int i = 0; i < n; i++) {
            int index = Arrays.binarySearch(orderByP1, data[i], cmp);
            sum += bit.sum(index);
            bit.update(index, 1);
        }

        output.println(sum);
    }

    public static class BIT {
        int[] data;
        int n;

        public BIT(int cap) {
            this.data = new int[cap + 1];
            this.n = data.length;
        }

        public int sum(int i) {
            int sum = 0;
            for (i++; i > 0; i -= i & -i) {
                sum += data[i];
            }
            return sum;
        }

        public void update(int i, int mod) {
            for (i++; i < n; i += i & -i) {
                data[i] += mod;
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
            this(is, 4096);
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