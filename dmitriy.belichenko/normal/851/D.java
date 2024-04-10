import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.InputStream;

public class Main
{
    static int n;
    public static void main(String[] args)
    {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }


    static Long res = 1L << 60;
    static int N = (int)5e5 +1000;
    static int MAXK = (int)1e6 + 10;
    static long t[] = new long[4 * MAXK];
    static int cnt[] = new int[4 * MAXK];
    static long A, B, toadd, del;
    static int pt[] = new int[2 * MAXK];
    static void build(int i, int l, int r)
    {
        if (l == r)
        {
            t[i] = 1L * pt[l] * l;
            cnt[i] = pt[l];
        } else {
            build(2 * i, l, (l + r) / 2);
            build(2 * i + 1, (l + r) / 2 + 1, r);
            t[i] = t[2 * i] + t[2 * i + 1];
            cnt[i] = cnt[2 * i] + cnt[2 * i + 1];
        }
    }


    static void q(int i, int l, int r)
    {
        if (l > B || r < A)
        {
            return;
        }
        if (l >= A && r <= B)
        {
            toadd += t[i];
            del += cnt[i];
            return;
        }
        q(2 * i, l, (l + r) / 2);
        q(2 * i + 1, (l + r) / 2 + 1, r);
    }

    static class TaskD
    {

        static int a[] = new int[N];
        static int pri[] = new int[N];

        //out.println(n);
        static int prcnt = 0;
        static int se[] = new int[MAXK];


        public void solve(int testNumber, InputReader in, PrintWriter out)
        {

            Random random = new Random(94739534513L + System.currentTimeMillis());
            n = in.nextInt();
            //System.out.println(res);
            int x1 , y1;
            x1 = in.nextInt();
            y1 = in.nextInt();
            Long x = 1L * x1;
            Long y = 1L * y1;
            int p = 0;
            int to = -1;
            //Long res = 0L;
            boolean flag = false;
            for (int i = 0; i < n; ++i)
            {
                a[i] = in.nextInt();
                pt[a[i]]++;
                res += 1L*(a[i] % 2) * y;
             //   System.out.println(res);
                p = Math.max(a[i] , p);
                if(p == a[i] && !flag)
                {
                    to = p;
                }
            }


            build(1, 0, to);

            for (int i = 2; i <= to; ++i)
            {
                if (se[i] == 0)
                {
                    pri[prcnt] = i;
                    prcnt++;
                    se[i] = i;
                }
                long pt = MAXK / i  * 1L;
                if (i <= pt)
                {
                    for (int j = i * i; j <= to; j += i) se[j] = i;
                }
            }
            for (int i = 0; i < prcnt; ++i)
            {
                int vp = pri[i];
                long tot = 0;
                //res = Math.min(res,(long) tot + n  * x);
                long cnt1 = 0;
                for (int j = vp; j <= to + vp; j += vp)
                {
                    long mxn = Math.min(vp - 1L, x / y);
                    A = j - mxn;
                    B = j;
                    toadd = 0;
                    del = 0;
                    q(1, 0, to);
                    tot += (del * j - toadd) * y;
                    cnt1 += del;
                }

                res = Math.min(res,(long) tot + (n - cnt1) * x);
            }
            if(p == 1 )
            {
                res = Math.min(1L * n *  y , (n  * x * 1L));
            }
            out.println(res);
            return ;

        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}