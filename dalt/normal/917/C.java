

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by dalt on 2018/2/25.
 */
public class CF917C {
    public static final long INF = (long) 1e18;
    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;

    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF917C.in"));
        }
        input = new BlockReader(System.in);

        int x, k, n, q;
        x = input.nextInteger();
        k = input.nextInteger();
        n = input.nextInteger();
        q = input.nextInteger();

        long[] cost = new long[k + 1];
        for (int i = 1; i <= k; i++) {
            cost[i] = input.nextInteger();
        }

        int[][] specialStone = new int[q + 1][2];
        for (int i = 0; i < q; i++) {
            specialStone[i][0] = input.nextInteger();
            specialStone[i][1] = input.nextInteger();
        }
        specialStone[q][0] = n + 1000000;
        Map<Integer, Integer> specialMap = new HashMap<>();
        for (int i = 0; i <= q; i++) {
            specialMap.put(specialStone[i][0], specialStone[i][1]);
        }

        //Ensure ascending order
        Arrays.sort(specialStone, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        });

        int[] states = new int[choose(x, k)];
        int[] stateIndexes = new int[256];
        int mask = (1 << k) - 1;
        for (int i = 0, len = 0; i <= mask; i++) {
            if (Integer.bitCount(i) == x) {
                states[len] = i;
                stateIndexes[i] = len;
                len++;
            }
        }


        Matrix transform = new Matrix(states.length, states.length);
        transform.fill(INF);
        for (int i = 0, bound = states.length; i < bound; i++) {
            int state = states[i];
            int lowbit = Integer.lowestOneBit(state);
            state -= lowbit;
            for (int j = 1; j <= k; j++) {
                if ((state & (lowbit << j)) == 0) {
                    int newState = state | (lowbit << j);
                    newState >>= 1;
                    if (newState <= mask) {
                        transform.set(i, stateIndexes[newState], cost[j]);
                    }
                }
            }

            if (lowbit != 1) {
                transform.set(i, stateIndexes[states[i] >> 1], 0);
            }
        }

        int initState = (1 << x) - 1;

        Loop<Matrix> bufLoop = new Loop<>(new Matrix(states.length, states.length), new Matrix(states.length, states.length));
        Loop<Matrix> vecDp = new Loop<>(new Matrix(1, states.length), new Matrix(1, states.length));
        vecDp.turn(0).fill(INF);
        vecDp.turn(0).set(0, stateIndexes[initState], 0);

        int cur = 1;
        int target = n - x + 1;
        int nextStoneIndex = 0;
        for (; cur < target; ) {
            for (; specialStone[nextStoneIndex][0] <= cur; nextStoneIndex++) ;
            int nextStonePos = specialStone[nextStoneIndex][0];

            int until = Math.min(nextStonePos - k, target);

            if (until > cur) {
                Matrix.power(transform, bufLoop, until - cur);
                Matrix.mul(vecDp.turn(0), bufLoop.turn(0), vecDp.turn(1));
                cur = until;

                if (cur >= target) {
                    break;
                }
            }

            for (; specialStone[nextStoneIndex + 1][0] - specialStone[nextStoneIndex][0] < k; nextStoneIndex++) ;
            int curUntil = Math.min(target, specialStone[nextStoneIndex][0]);
            for (; cur < curUntil; cur++) {
                long[] curVec = vecDp.turn(0).data[0];
                long[] nextVec = vecDp.turn(1).data[0];
                Arrays.fill(nextVec, INF);

                for (int i = 0, bound = states.length; i < bound; i++) {
                    int state = states[i];
                    int lowestBitPos = 0;
                    while ((state & (1 << lowestBitPos)) == 0) {
                        lowestBitPos++;
                    }
                    int lowbit = Integer.lowestOneBit(state);
                    state -= lowbit;
                    for (int j = 1; j <= k; j++) {
                        if ((state & (lowbit << j)) == 0) {
                            int newState = state | (lowbit << j);
                            newState >>= 1;
                            if (newState <= mask) {
                                int newStateIndex = stateIndexes[newState];
                                long price = curVec[i] + cost[j] + specialMap.getOrDefault(cur + j + lowestBitPos, 0);
                                nextVec[newStateIndex] = Math.min(nextVec[newStateIndex], price);
                            }
                        }
                    }

                    if (lowbit != 1) {
                        int newState = stateIndexes[states[i] >> 1];
                        nextVec[newState] = Math.min(nextVec[newState], curVec[i]);
                    }
                }
            }
        }

        long minCost = vecDp.turn(0).elementAt(stateIndexes[initState], 0);
        System.out.println(minCost);
    }

    //choose a objects from b objects
    public static int choose(int a, int b) {
        int upIter = b;
        int lowIter = 1;
        int upMul = 1;
        int lowMul = 1;
        for (int i = 1; i <= a; i++) {
            upMul *= upIter;
            lowMul *= lowIter;
            upIter--;
            lowIter++;
        }

        return upMul / lowMul;
    }

    public static class Matrix {
        long[][] data;
        int col;
        int row;

        public Matrix(int row, int col) {
            this.row = row;
            this.col = col;
            data = new long[row][col];
        }

        public static void power(Matrix a, Loop<Matrix> loop, int p) {
            loop.turn(0).asStandard();
            if (p == 0) {
                return;
            }

            int i = 31;
            while (p >> i == 0) {
                i--;
            }


            for (; i >= 0; i--) {
                mul(loop.turn(0), loop.turn(0), loop.turn(1));
                if ((p & (1 << i)) != 0) {
                    mul(a, loop.turn(0), loop.turn(1));
                }
            }
        }

        public static Matrix mul(Matrix a, Matrix b, Matrix res) {
            int row = res.row;
            int col = res.col;
            int mid = a.col;

            long[][] resdata = res.data;
            long[][] adata = a.data;
            long[][] bdata = b.data;
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    long val = INF;
                    for (int k = 0; k < mid; k++) {
                        val = Math.min(val, adata[i][k] + bdata[k][j]);
                    }
                    resdata[i][j] = Math.min(val, INF);
                }
            }

            return res;
        }

        public void asStandard() {
            fill(INF);
            for (int i = 0; i < row; i++) {
                data[i][i] = 0;
            }
        }

        public void fill(long val) {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    data[i][j] = val;
                }
            }
        }

        public void copy(Matrix a) {
            for (int i = 0; i < row; i++) {
                System.arraycopy(a.data[i], 0, data[i], 0, col);
            }
        }

        public void set(int row, int col, long val) {
            data[row][col] = val;
        }

        public void mod(int row, int col, long val) {
            data[row][col] += val;
        }

        public long elementAt(int row, int col) {
            return data[row][col];
        }

        @Override
        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    builder.append(data[i][j]).append(' ');
                }
                builder.append('\n');
            }
            return builder.toString();
        }
    }

    public static class Loop<T> {
        private T[] data;
        private int index;

        public Loop(T... data) {
            this.data = data;
        }

        public T turn(int i) {
            index += i;
            return data[index % data.length];
        }

        @Override
        public String toString() {
            return turn(0).toString();
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