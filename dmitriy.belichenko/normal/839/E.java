/**
 *
 * @author bossbelik
 */
import java.io.*;
import java.util.*;
import java.math.*;


public class Main{
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

    static int[] calcz(String s) {
        int l = 0;
        int r = 0;
        int n = s.length();
        int z[] = new int[n];
        for (int i = 1; i < n; i++) {

            if (i <= r) {
                z[i] = Math.min(z[i - l], r - i + 1);
            }
            while (i + z[i] < n && s.charAt(z[i]) == s.charAt(i + z[i])) z[i]++;
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }

        }
        return z;
    }

    static int[] calcpref(String s) {
        int p[] = new int[s.length() + 1];
        int n = s.length();
        p[0] = 0;
        for (int i = 2; i <= n; i++) {
            p[i] = p[i - 1];
            while (p[i] > 0 && s.charAt(p[i]) != s.charAt(i - 1)) p[i] = p[p[i]];
            if (s.charAt(p[i]) == s.charAt(i - 1)) p[i]++;
        }
        return p;
    }
    static long MOD =  1000000007;

    static long binpow (long a, long n)
    {
        if (n == 0)
            return 1;
        if (n % 2 == 1)
            return binpow (a % MOD, (n-1) % MOD ) * a % MOD;
        else {
            long b = binpow(a % MOD, n/2 % MOD) % MOD;
            return (b * b) % MOD;
        }
    }

static int maxnum=105;
  static   int a[][] = new int[maxnum][maxnum];
  static   boolean used[] = new boolean[maxnum];
   static int curr , cnt ,n ,m;

 static    void dfs(int i)
    {
        int j;
        boolean flag;
        if(i > n)
        {
            cnt = curr;
            return ;
        }

        flag=true;
        for(j = 1 ; j < i; j++)
        {
            if (used[j] && a[j][i] == 0)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            curr++;
            used[i]=true;
            dfs(i+1);
            curr--;
        }
        if(curr + n - i > cnt)
        {
            used[i]=false;
            dfs(i+1);
        }
    }



    public static void main(String[] args) throws  Exception
    {

//
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter((System.out));
        n = in.nextInt();
        m = in.nextInt();


            for(int i = 1 ; i <= n ; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    a[i][j] = in.nextInt();
                }
            }
            dfs(1);
           out.printf( "%.10f", (double) m * m * (cnt-1) / (2 * cnt ));


        out.println();
        out.close();
        return;
    }
}