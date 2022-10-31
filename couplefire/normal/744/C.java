import java.util.Arrays;
import java.util.Scanner;

public class RedAndBlueCards {
    public static int n;
    public static char[] color;
    public static int[] r,b;
    public static int[] countred, countblue;
    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        color = new char[n];
        r = new int[n];
        b = new int[n];
        int base = 0;
        int needred = 0, needblue = 0;
        for (int i = 0; i < n; i++) {
            color[i] = in.next().charAt(0);
            r[i] = in.nextInt();
            b[i] = in.nextInt();
            needred += Math.max(0, r[i] - n);
            needblue += Math.max(0, b[i] - n);
            r[i] = Math.min(n, r[i]);
            b[i] = Math.min(n, b[i]);
        }
        base = Math.max(needred, needblue);

        countred = new int[1<<n];
        countblue = new int[1<<n];
        for (int i = 1; i < 1 << n; i++) {
            int lowbit = Integer.numberOfTrailingZeros(i & -i);
            countred[i] = countred[i ^ (1 << lowbit)];
            countblue[i] = countblue[i ^ (1 << lowbit)];
            if (color[lowbit] == 'R') countred[i]++;
            else countblue[i]++;
        }

        dp = new int[2][n*n+1][1<<n];
        for (int[][] x : dp) for (int[] y : x) Arrays.fill(y, -1);

        int ans = base + n;
        if (needred < needblue) {
            ans += solve(0, 0, needblue - needred);
        } else {
            ans += solve(0, 1, needred - needblue);
        }
        System.out.println(ans);
        System.exit(0);
    }

    public static int[][][] dp;
    public static int solve(int mask, int redempty, int other) {
        other = Math.min(other, n*n);
        if (mask == (1<<n)-1) return 0;
        if (dp[redempty][other][mask] != -1) return dp[redempty][other][mask];
        int ret = 1 << 29;
        for (int i = 0; i < n; i++) {
            if (((mask>>i)&1) == 1) continue;
            int pmask = mask | (1 << i);
            int havered = redempty == 1 ? 0 : other;
            int haveblue = redempty == 0 ? 0 : other;
            int cardred = countred[mask], cardblue = countblue[mask];

            int nred = Math.max(0, r[i]-(cardred+havered));
            int nblue = Math.max(0, b[i]-(cardblue+haveblue));
            int needmoves = Math.max(nred, nblue);
            int nextred = havered + needmoves - Math.max(0, r[i] - cardred);
            int nextblue = haveblue + needmoves - Math.max(0, b[i] - cardblue);

            if (nextred == 0) {
                ret = Math.min(ret, needmoves + solve(pmask, 1, nextblue));
            }
            if (nextblue == 0) {
                ret = Math.min(ret, needmoves + solve(pmask, 0, nextred));
            }
        }
        return dp[redempty][other][mask] = ret;
    }
}