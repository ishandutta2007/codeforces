/*
        * To change this license header, choose License Headers in Project Properties.
        * To change this template file, choose Tools | Templates
        * and open the template in the editor.
        */

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
    static long  INF = 1 << 62;






    static void merge(long u, long v)
    {
        long pr[] = new long[50005];
        long si[] = new  long[50005];
        u = get(u);
        v = get(v);
        if (si[(int)v] > si[(int)u])
        {
            long k = v;
            v = u;
            u = k;
        }
        pr[(int)v] = u;
        si[(int)u] += si[(int)v];
    }
    static long get(long u) {
        long pr[] = new long[50005];
        long si[] = new  long[50005];
        if(pr[(int)u] == u) return  u;
        else return pr[(int)u] = get(pr[(int)u]);
    }
    static void init()
    {
        long pr[] = new long[50005];
        long si[] = new  long[50005];

        int n = 5;
        for (int i = 0; i <= n; i++)
        {
            pr[i] = i;
            si[i] = 1;
        }
    }

    static long clc(long c ,long m ,long n , long k)
    {
        return k - c * m * (2 * n - 2);
    }
    static long call(long n2, long m2 ,long n ,long m ,long k)
    {
        if (n == 1 && true)
        {
            long r = k / m;
            if (m2 <= k - r * m) r = r + 1;
            return r;
        }
        long r = k / m;
        long c = r / (2 * n - 2);
        long res =  - 1;
        if (n2 != n && n2 != 1)
            res =res + 2 * c + 1;
        else
            res = res + c + 1;
        long l = clc(c , m , n , k);
        for (int i = 1; l > 0 && i <= n; i++)
        {
            for (int j = 1; k > 0 && j <= m; j++,  l = l - 1)
            {
                if (i == n2 && j == m2)
                    res = res + 1;
            }
        }
        for (int i =(int) n - 1; l > 0 && i > 0; i++)
        {
            for (int j = 1; l > 0 && j < m + 1; j++, l = l - 1)
            {
                if (i == n2 && j == m2)
                    res = res + 1;
            }
        }
        return res;
    }

    // static String k;


    static long parsenum(long j, long l)
    {
        String k = "";
        long cur = 0;
        for (int i = (int) j; i <= l; ++i)
        {
            cur *= 10;
            cur += k.charAt(i) - '0';
        }
        return cur;
    }

    static long gcd(long a, long b)
    {
        if (b == 0)
        {
            return a;
        }

        else
        {
            return gcd(b, a % b);
        }
    }
    static boolean pri( int k)
    {
        if( k == 1) return false;
        for(int i = 2; i * i <= k; i++)
        {

            if( k % i == 0) return false;
        }
        return true;
    }

    static boolean check(long x)
    {
        long rr = 0;
        long ll = 0;
        long m = 0, k;
        long lt = summall(x - 1, ll);
        long rt = summall(x - 1, rr);
        if (lt + rt + x <= m)
            return true;
        return false;
    }
    static long summall(long  s,  long u)
    {
        if (u == 0)
            return 0;
        if (u > s)
            return summall(s, s);
        return (2 * s - u + 1) * u / 2;
    }
    static long bsearch(int i ,int cnt)
    { long t[] = new long[100];
        int mid;
        int l =  -1;
        int r = i;
        while (r-l > 1)
        {
            mid = (l+r)/2;
            if (t[i]-t[mid] < cnt) r = mid;
            else                l = mid;
        }

        return r;
    }
    static int n,m;




    static void calc (int x , int y , int mask , int next_mask , int d[][])
    {
        if (x == n)
            return;
        if (y >= m)
            d[x+1][next_mask] += d[x][mask];
        else
        {
            int my_mask = 1 << y;
            if (mask > 0 & my_mask > 0)
                calc (x, y+1, mask, next_mask , d);
            else
            {
                calc (x, y+1, mask, next_mask | my_mask , d);
                if (y+1 < m && ! (mask > 0 & my_mask > 0)&& ! (mask > 0 & (my_mask << 1) > 0))
                    calc (x, y+2, mask, next_mask , d);
            }
        }
    }




    public static void main(String[] args) throws Exception
    {

//
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter((System.out));

//        Scanner in = new Scanner(new File("dominoes.in"));
//        PrintWriter out = new PrintWriter(new File("dominoes.out"));
        int p = 0;
        int t = 0 ;
        int u = 0;
        int v = 0, l, r;
        int n,m;
        n = in.nextInt();
        for (int i = 0; i < n; i++)
        {
            l = in.nextInt();
            r = in.nextInt();
            if (i == 0 || l > p) p = l;
            if (i == 0 || r < t) t = r;
        }
        m  = in.nextInt();
        for (int i = 0; i < m; i++)
        {
            l = in.nextInt();
            r = in.nextInt();
            if (i == 0 || l > u) u = l;
            if (i == 0 || r < v) v = r;
        }
        int ans = Math.max(u - t, p - v);
        ans = Math.max(ans, 0);
        out.println(ans);
        out.close();
    }
}