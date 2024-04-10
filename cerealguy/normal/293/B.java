import java.io.*;
import java.util.*;

public class B {

    static final int MOD = 1000000007;

    static int[][] color;
    static int r, c;
    static int colors;

    static int[] possibleMask;

    static int[][] haveLater;

    static long answer;

    static long[] factorial = new long[15];
    static {
        factorial[0] = 1;
        for (int i = 0; i < factorial.length - 1; i++) {
            factorial[i + 1] = factorial[i] * (i + 1);
        }
    }

    static int[] BITCOUNT;
    static {
        BITCOUNT = new int[1 << 12];
        for (int i = 0; i < BITCOUNT.length; i++) {
            BITCOUNT[i] = Integer.bitCount(i);
        }
    }

    static int allEquivalent;
    
    static int[][] arrays = new int[100][];

    static void go(int sum, int col) {
        if (sum == r + c - 1) {
            int leftE = BITCOUNT[equivalentColorsMask];
            answer += factorial[allEquivalent] / factorial[leftE];
            return;
        }
        if (col == sum + 1 || col == c) {
            if (col < c) {
                possibleMask[col] = (1 << colors) - 1;
            }
            if (arrays[sum] == null) {
                arrays[sum] = possibleMask.clone();
            } else {
                System.arraycopy(possibleMask, 0, arrays[sum], 0, c);
            }
            for (int i = c - 1; i > 0; --i) {
                possibleMask[i] &= possibleMask[i - 1];
            }

            for (int i = c - 1; i >= 0; --i) {
                int row = sum - i;
                if (row < 0 || row >= r) {
                    continue;
                }
                possibleMask[i] &= ~(1 << color[row][i]);
                if (i < c - 1) {
                    possibleMask[i + 1] &= ~(1 << color[row][i]);
                }
            }

            go(sum + 1, Math.max(0, sum + 1 - (r - 1)));
            System.arraycopy(arrays[sum], 0, possibleMask, 0, c);
            return;
        }
        int good = possibleMask[col] & ~haveLater[sum - col][col];

        int checkEquivalent = possibleMask[col] & equivalentColorsMask;
        int okCheckEquivalent = checkEquivalent == 0 ? -1 : Integer
                .numberOfTrailingZeros(checkEquivalent);

        int wasEquivalent = equivalentColorsMask;
        for (int i = 0; i < colors; i++) {
            if ((good & (1 << i)) == 0) {
                continue;
            }
            if (color[sum - col][col] >= 0 && color[sum - col][col] != i) {
                continue;
            }

            if (((1 << i) & checkEquivalent) != 0 && i != okCheckEquivalent) {
                continue;
            }

            int was = color[sum - col][col];
            color[sum - col][col] = i;

            equivalentColorsMask &= ~(1 << i);

            if (BITCOUNT[possibleMask[col]] >= (r + c - 2 - sum)) {
                go(sum, col + 1);
            }
            equivalentColorsMask = wasEquivalent;

            color[sum - col][col] = was;
        }
    }

    static int equivalentColorsMask;

    static void solve() throws IOException {
        r = nextInt();
        c = nextInt();
        colors = nextInt();
        int length = r + c - 1;
        if (length > colors) {
            out.println(0);
            return;
        }
        color = new int[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                color[i][j] = nextInt() - 1;
            }
        }
        if (r < c) {
            swapRC();
        }
        answer = 0;
        possibleMask = new int[c];
        possibleMask[0] = (1 << colors) - 1;
        haveLater = new int[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                haveLater[i][j] = 0;
                for (int a = i; a < r; a++) {
                    for (int b = j; b < c; b++) {
                        if (a == i && b == j) {
                            continue;
                        }
                        if (color[a][b] >= 0) {
                            haveLater[i][j] |= (1 << color[a][b]);
                        }
                    }
                }
            }
        }
        equivalentColorsMask = ~(haveLater[0][0]);
        if (color[0][0] >= 0) {
            equivalentColorsMask &= ~(1 << color[0][0]);
        }
        equivalentColorsMask &= (1 << colors) - 1;
        allEquivalent = Integer.bitCount(equivalentColorsMask);
        go(0, 0);
        long ans = answer;
        out.println(ans % MOD);
    }

    private static void swapRC() {
        int t = r;
        r = c;
        c = t;
        int[][] newCol = new int[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                newCol[i][j] = color[j][i];
            }
        }
        color = newCol;
    }

    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;
        File file = new File("b.in");
        if (file.exists() && file.canRead()) {
            input = new FileInputStream(file);
        }
        br = new BufferedReader(new InputStreamReader(input));
        out = new PrintWriter(output);
        solve();
        out.close();
    }

    static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }
}