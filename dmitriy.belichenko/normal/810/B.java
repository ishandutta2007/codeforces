

/**
 *
 * @author bossbelik
 */
        import java.io.*;
        import java.util.*;
        import java.math.*;
        import java.util.concurrent.ThreadLocalRandom;

public class Main
{
    static long N = 100;
    static long CNT = 62;
    static long INF = 1 << 62;


    static void merge(long u, long v) {
        long pr[] = new long[50005];
        long si[] = new long[50005];
        u = get(u);
        v = get(v);
        if (si[(int) v] > si[(int) u]) {
            long k = v;
            v = u;
            u = k;
        }
        pr[(int) v] = u;
        si[(int) u] += si[(int) v];
    }

    static long get(long u) {
        long pr[] = new long[50005];
        long si[] = new long[50005];
        if (pr[(int) u] == u) return u;
        else return pr[(int) u] = get(pr[(int) u]);
    }

    static void init() {
        long pr[] = new long[50005];
        long si[] = new long[50005];

        int n = 5;
        for (int i = 0; i <= n; i++) {
            pr[i] = i;
            si[i] = 1;
        }
    }

    static long clc(long c, long m, long n, long k) {
        return k - c * m * (2 * n - 2);
    }

    static long call(long n2, long m2, long n, long m, long k) {
        if (n == 1 && true) {
            long r = k / m;
            if (m2 <= k - r * m) r = r + 1;
            return r;
        }
        long r = k / m;
        long c = r / (2 * n - 2);
        long res = -1;
        if (n2 != n && n2 != 1)
            res = res + 2 * c + 1;
        else
            res = res + c + 1;
        long l = clc(c, m, n, k);
        for (int i = 1; l > 0 && i <= n; i++) {
            for (int j = 1; k > 0 && j <= m; j++, l = l - 1) {
                if (i == n2 && j == m2)
                    res = res + 1;
            }
        }
        for (int i = (int) n - 1; l > 0 && i > 0; i++) {
            for (int j = 1; l > 0 && j < m + 1; j++, l = l - 1) {
                if (i == n2 && j == m2)
                    res = res + 1;
            }
        }
        return res;
    }

    // static String k;


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




    static long bsearch(int i, int cnt) {
        long t[] = new long[100];
        int mid;
        int l = -1;
        int r = i;
        while (r - l > 1) {
            mid = (l + r) / 2;
            if (t[i] - t[mid] < cnt) r = mid;
            else l = mid;
        }

        return r;
    }

    static int n, m;


    static void calc(int x, int y, int mask, int next_mask, int d[][]) {
        if (x == n)
            return;
        if (y >= m)
            d[x + 1][next_mask] += d[x][mask];
        else {
            int my_mask = 1 << y;
            if (mask > 0 & my_mask > 0)
                calc(x, y + 1, mask, next_mask, d);
            else {
                calc(x, y + 1, mask, next_mask | my_mask, d);
                if (y + 1 < m && !(mask > 0 & my_mask > 0) && !(mask > 0 & (my_mask << 1) > 0))
                    calc(x, y + 2, mask, next_mask, d);
            }
        }
    }
   static long solve(int x, int y , int p , int q)
{
    if((p == q && x != y) || (p == 0 && x != 0 ))return -1;
     long l = ( y + q - 1)/ q - 1 , r = 1L<<30;
    while( l < r - 1)
    {
         long mid = ( l + r ) >> 1;
        long last = mid* q;
         long num = mid * p;
         long have = last - y;
        if(num <= have + x && num >= x)
            r = mid;
        else l = mid;
    }
     long last = r * q;
    long have = last - y;
    return have;
}
static  long sec(long r , long cnt , long a , long n)
{
    long c = 0;
    long ans = 0L;
    while (r< n-a + 1 && c <5001)
    {
        if ((5000 - r % 5000) % 500 +  (5000 - (n-r) % 5000) % 500 > ans) ans =  (5000 - r % 5000) % 500 +  (5000 - (n-r) % 5000) % 500;
        r++;
        c++;
    }
    return  ans;
}
static long  first(long l , long cnt , long a , long n)
{
    long ans = 0L;
    while (l>=a && cnt<=5000)
    {

        if ((5000 - l % 5000) % 500 +  (5000 - (n-l) % 5000) % 500 > ans) ans =  (5000 - l % 5000) % 500 +  (5000 - (n-l) % 5000) % 500;
        l--;
        cnt++;
    }
    return ans;
}
   static boolean used[] = new boolean[200005];

    static long p[] = new long[200005];

    static long v1[][] = new long[3][200005];
    static long v2[][] = new long[3][200005];
    static int ptr[] = new int[3];



    public static void main(String[] args) throws Exception
    {

//
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter((System.out));

        //  Scanner in = new Scanner(new File("rect.in"));
        //   PrintWriter out = new PrintWriter(new File("rect.out"));




    long n, f , k , l;
       n = in.nextLong();
        f = in.nextLong();
        Long a[] = new Long[(int)n];
      long s = 0;
        for (int i=0; i<n; i++)
        {
            k = in.nextLong();
            l = in.nextLong();
            long p = Math.min(k,l);
            s += p;
            a[i]= Math.min (2*k,l)- p;
        }
        Arrays.sort(a);
        for (int i = (int)n - 1; i >=  n  - f; i--)
        {
            s+=a[i];
        }
        out.print(s);
        out.close();
    }



}