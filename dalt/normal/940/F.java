

import java.io.*;
import java.util.*;

/**
 * Created by Administrator on 2018/3/12.
 */
public class CF940F {
    public static BlockReader input;
    public static PrintStream output;

    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF940F.in"));
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
        int q = input.nextInteger();
        int[] ori = new int[n + 1];
        //Compress the number inputted at first
        TreeMap<Integer, Integer> map = new TreeMap();

        for (int i = 1; i <= n; i++) {
            ori[i] = input.nextInteger();
            map.put(ori[i], null);
        }
        int[][] reqs = new int[q][4];
        for (int i = 0; i < q; i++) {
            for (int j = 0; j < 3; j++) {
                reqs[i][j] = input.nextInteger();
            }
            if (reqs[i][0] == 2) {
                map.put(reqs[i][2], null);
            }
        }

        int order = 0;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            entry.setValue(order);
            order++;
        }
        for (int i = 1; i <= n; i++) {
            ori[i] = map.get(ori[i]);
        }
        List<int[]> changeReqList = new ArrayList<>(q);
        List<int[]> queryReqList = new ArrayList<>(q);
        int[] clone = ori.clone();
        for (int i = 0; i < q; i++) {
            if (reqs[i][0] == 2) {
                reqs[i][2] = map.get(reqs[i][2]);
                reqs[i][3] = clone[reqs[i][1]];
                clone[reqs[i][1]] = reqs[i][2];
                changeReqList.add(reqs[i]);
            } else {
                queryReqList.add(reqs[i]);
                reqs[i][3] = changeReqList.size();
            }
        }

        final int p = Math.max(1, (int) Math.pow(n, 2.0 / 3));

        //Sort to part the requests into different block
        queryReqList.sort(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                int d0 = o1[3] / p - o2[3] / p;
                if (d0 != 0) {
                    return d0;
                }
                int d1 = o1[1] / p - o2[1] / p;
                if (d1 != 0) {
                    return d1;
                }
                return o1[2] - o2[2];
            }
        });

        //Handle requests
        int x = -1;
        int y = -1;
        int[] cntsOfNumber = new int[order];
        int[] cntsOfTimes = new int[n + q];

        int l = -1;
        int r = -1; //r not include
        int c = 0;
        for (int[] req : queryReqList) {
            //Discard all message we have known
            if (req[3] / p != x || req[1] / p != y) {
                Arrays.fill(cntsOfNumber, 0);
                Arrays.fill(cntsOfTimes, 0);
                cntsOfTimes[0] = cntsOfNumber.length;
                l = req[1];
                r = l;
                c = 0;

                System.arraycopy(ori, 1, clone, 1, n);

                x = req[3] / p;
                y = req[1] / p;
            }

            //move l to match req[1]
            while (l > req[1]) {
                l--;
                meet(cntsOfNumber, cntsOfTimes, clone[l]);
            }
            while (r <= req[2]) {
                meet(cntsOfNumber, cntsOfTimes, clone[r]);
                r++;
            }
            while (l < req[1]) {
                lose(cntsOfNumber, cntsOfTimes, clone[l]);
                l++;
            }
            while (r - 1 > req[2]) {
                r--;
                lose(cntsOfNumber, cntsOfTimes, clone[r]);
            }

            //if changed any word
            while (c < req[3]) {
                int[] changeReq = changeReqList.get(c);
                if (changeReq[1] >= l && changeReq[1] < r) {
                    lose(cntsOfNumber, cntsOfTimes, changeReq[3]);
                    meet(cntsOfNumber, cntsOfTimes, changeReq[2]);
                }
                clone[changeReq[1]] = changeReq[2];
                c++;
            }
            //if roll-back change
            while (c > req[3]) {
                c--;
                int[] changeReq = changeReqList.get(c);
                if (changeReq[1] >= l && changeReq[1] < r) {
                    lose(cntsOfNumber, cntsOfTimes, changeReq[2]);
                    meet(cntsOfNumber, cntsOfTimes, changeReq[3]);
                }
                clone[changeReq[1]] = changeReq[3];
            }

            //OK, we have collect all information needed to handle the request
            int mex = 1;
            while (mex < cntsOfTimes.length && cntsOfTimes[mex] > 0) {
                mex++;
            }
            req[3] = mex;
        }

        for (int i = 0; i < q; i++) {
            if (reqs[i][0] == 1) {
                output.println(reqs[i][3]);
            }
        }
    }

    public static void meet(int[] cntsOfNumber, int[] cntsOfTimes, int e) {
        cntsOfTimes[cntsOfNumber[e]]--;
        cntsOfTimes[++cntsOfNumber[e]]++;
    }

    public static void lose(int[] cntsOfNumber, int[] cntsOfTimes, int e) {
        cntsOfTimes[cntsOfNumber[e]]--;
        cntsOfTimes[--cntsOfNumber[e]]++;
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