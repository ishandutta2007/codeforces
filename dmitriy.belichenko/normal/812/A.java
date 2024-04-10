

/**
 *
 * @author bossbelik
 */
        import java.io.*;
        import java.util.*;
        import java.math.*;
        import java.util.concurrent.ThreadLocalRandom;

public class Main {
    static long N = 100;
    static long CNT = 62;
    static long INF = 1 << 62;



    static long parsenum(long j, long l) {
        String k = "";
        long cur = 0;
        for (int i = (int) j; i <= l; ++i) {
            cur *= 10;
            cur += k.charAt(i) - '0';
        }
        return cur;
    }

    static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }

    static boolean pri(int k) {
        if (k == 1) return false;
        for (int i = 2; i * i <= k; i++) {

            if (k % i == 0) return false;
        }
        return true;
    }








    static long solve(int x, int y, int p, int q)
    {
        if ((p == q && x != y) || (p == 0 && x != 0)) return -1;
        long l = (y + q - 1) / q - 1, r = 1L << 30;
        while (l < r - 1) {
            long mid = (l + r) >> 1;
            long last = mid * q;
            long num = mid * p;
            long have = last - y;
            if (num <= have + x && num >= x)
                r = mid;
            else l = mid;
        }
        long last = r * q;
        long have = last - y;
        return have;
    }


    public static void main(String[] args) throws Exception
    {

//
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter((System.out));

        //  Scanner in = new Scanner(new File("rect.in"));
        //   PrintWriter out = new PrintWriter(new File("rect.out"))

        int a[][] = new int[4][4];

            for (int i = 0; i < 4; i++) 
            {
                for (int j = 0; j < 4; j++) 
                {
                    a[i][j] = in.nextInt();
                }
            }
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 3; ++j) 
                {
                    if (a[i][j] == 1 && a[i][3] == 1) 
                    {
                        out.println("YES");
                        out.close();
                        return;
                    }
                }
            }
            for (int i = 0; i < 4; ++i)
            {
                int p = (i + 1) % 4;
                if (a[p][3] > 0 && a[i][2] > 0)
                {
                    out.println("YES");
                    out.close();
                    return;
                }
                int u = (i + 3) % 4;
                if (a[u][3] > 0  && a[i][0] > 0) 
                {
                    out.println("YES");
                    out.close();
                    return;
                }
               

                p = (i + 2) % 4;
                if (a[p][3] > 0 && a[i][1] > 0)
                {
                    out.println("YES");
                    out.close();
                    return;
                }
            }
        {
            {
                out.println("NO");
                out.close();
                return;
            }
        }

        }
}