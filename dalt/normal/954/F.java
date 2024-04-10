

import java.io.*;
import java.util.Arrays;
import java.util.Comparator;

/**
 * Created by dalt on 2018/4/2.
 */
public class CF954F {
    public static final long MOD = (long) (1e9 + 7);
    public static BlockReader input;
    public static PrintStream output;

    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF954F.in"));
            output = System.out;
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }

        solve();

        output.flush();
    }

    public static void solve() {
        Vector vector = new Vector(0, 1, 0);

        int n = input.nextInteger();
        long m = Long.parseLong(input.nextBlock());

        long[][] obstacles = new long[n + 1][3];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                obstacles[i][j] = Long.parseLong(input.nextBlock());
            }
        }
        obstacles[n][0] = 1;
        obstacles[n][1] = (long) 1e18 + 1;
        obstacles[n][2] = (long) 1e18 + 1;

        int[] available = new int[]{1, 1, 1};
        int[] obstacleCnt = new int[3];

        long[][] orderByBegin = obstacles.clone();
        long[][] orderByEnd = obstacles.clone();
        Arrays.sort(orderByBegin, new Comparator<long[]>() {
            @Override
            public int compare(long[] o1, long[] o2) {
                return Long.compare(o1[1], o2[1]);
            }
        });
        Arrays.sort(orderByEnd, new Comparator<long[]>() {
            @Override
            public int compare(long[] o1, long[] o2) {
                return Long.compare(o1[2], o2[2]);
            }
        });

        int orderByBeginIndex = 0;
        int orderByEndIndex = 0;
        long curPos = 1;
        Loop<Vector> vectorLoop = new Loop<>(new Vector(0, 1, 0), new Vector(), new Vector());
        Loop<Loop<Matrix>> matrixLoop = new Loop<>(
                new Loop<>(new Matrix(), new Matrix(), new Matrix()),
                new Loop<>(new Matrix(), new Matrix(), new Matrix())
        );

        while (curPos < m) {
            //Next appearance or disappearance of obstacles
            long nextEvent = Math.min(m + 1, Math.min(orderByBegin[orderByBeginIndex][1], orderByEnd[orderByEndIndex][2] + 1));

            //Go foward until next event occur
            matrixLoop.get(0).get(0).asRoute(available);
            long step = nextEvent - 1 - curPos;
            Matrix.power(matrixLoop.get(0).get(0), step, matrixLoop.turn());
            Matrix.mul(matrixLoop.get(0).get(0), vectorLoop.get(0), vectorLoop.turn());
            curPos += step;

            //Handle event
            if (nextEvent > m) {
                break;
            }
            for (; orderByBegin[orderByBeginIndex][1] == nextEvent; orderByBeginIndex++) {
                addObstacle(available, obstacleCnt, (int) orderByBegin[orderByBeginIndex][0] - 1);
            }
            for (; orderByEnd[orderByEndIndex][2] + 1 == nextEvent; orderByEndIndex++) {
                removeObstacle(available, obstacleCnt, (int) orderByEnd[orderByEndIndex][0] - 1);
            }
        }

        output.println(vectorLoop.get(0).data[1]);
    }

    public static void addObstacle(int[] available, int[] obstacleCnt, int row) {
        obstacleCnt[row]++;
        if (obstacleCnt[row] == 1) {
            available[row] = 0;
        }
    }

    public static void removeObstacle(int[] available, int[] obstacleCnt, int row) {
        obstacleCnt[row]--;
        if (obstacleCnt[row] == 0) {
            available[row] = 1;
        }
    }

    public static class Loop<T> {
        T[] data;
        int offset;

        public Loop(T... data) {
            this.data = data;
        }

        public T turn() {
            offset++;
            return get(0);
        }

        public T get(int index) {
            return data[(offset + index) % data.length];
        }

        @Override
        public String toString() {
            return get(0).toString();
        }
    }

    public static class Matrix {
        long[][] data = new long[3][3];

        public static void power(Matrix a, long n, Loop<Matrix> res) {
            int bit = 63 - Long.numberOfLeadingZeros(n);
            res.get(0).asStandard();
            for (; bit >= 0; bit--) {
                mul(res.get(0), res.get(0), res.turn());
                if ((n & (1L << bit)) != 0) {
                    mul(res.get(0), a, res.turn());
                }
            }
        }

        public void asStandard() {
            fill(0);
            for (int i = 0; i < 3; i++) {
                data[i][i] = 1;
            }
        }

        public static void mul(Matrix a, Matrix b, Matrix r) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    long v = 0;
                    for (int k = 0; k < 3; k++) {
                        v = (v + a.data[i][k] * b.data[k][j]) % MOD;
                    }
                    r.data[i][j] = v;
                }
            }
        }

        public void fill(int v) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    data[i][j] = v;
                }
            }
        }

        public static void mul(Matrix a, Vector vec, Vector res) {
            for (int i = 0; i < 3; i++) {
                long v = 0;
                for (int k = 0; k < 3; k++) {
                    v = (v + a.data[i][k] * vec.data[k]) % MOD;
                }
                res.data[i] = v;
            }
        }

        public void asRoute(int[] available) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    data[i][j] = available[i];
                }
            }

            data[0][2] = data[2][0] = 0;
        }

        @Override
        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < 3; i++) {
                builder.append(Arrays.toString(data[i])).append('\n');
            }
            return builder.toString();
        }
    }

    public static class Vector {
        long[] data;

        public Vector() {
            data = new long[3];
        }

        public Vector(long... ele) {
            this.data = ele;
        }

        @Override
        public String toString() {
            return Arrays.toString(data);
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