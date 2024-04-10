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

    static int n;
    static  int is[] = new int[1000005];
    static  long ps[] = new long[1000005];
    static  long cnt[] = new long[1000005];
    static  int mx;
    static long ans;



    public static void main(String[] args) {

//
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter((System.out));
        int i = 0, j = 0;

        n = in.nextInt();
        int a[] = new int[n];
        while (n > 0)
        {
            n--;
            a[i] = in.nextInt();
            if (a[i] > mx) mx = a[i];
            is[a[i]]++;
        }
        for (i = 2; i <= mx; i++)
        {
            for (j = i; j <= mx; j += i)
            {
                cnt[i] += is[j];
            }
        }
        for(i = mx; i >= 2; i--)
        {
            if(cnt[i] == 0) continue;
            long u = binpow(2,cnt[i]-1);
            ps[i] = (cnt[i] * u) % MOD;
            for( j = i + i ; j <= mx; j += i)
            {
                ps[i] = (ps[i] - ps[j] + MOD) % MOD;
            }
            u = (ps[i] * i) % MOD;
            ans = (ans + u) % MOD;
        }
        out.println(ans);
        out.close();
        return;
    }
}