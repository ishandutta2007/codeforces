import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main
{
    static int n;
    public static void main(String[] args)
    {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task
    {

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

        static int N = 200005;
        static int ans[] = new int[N];
        static int mp[] = new int[N];
        static int not_Taken[] = new int[N];
        public void solve(int testNumber, InputReader in, PrintWriter out)
        {

            Random random = new Random(94739534513L + System.currentTimeMillis());
            int n;
            n = in.nextInt();
            for (int i = 0; i < n; i++)
            {
                ans[i] = in.nextInt();
                mp[ans[i]]++;
            }
            int cnt = 0;
            TreeSet<Integer> st = new  TreeSet<Integer>();
            for (int i = 1; i <= n; i++)
            {
                cnt += Math.max(mp[i] - 1, 0);
                if (mp[i] == 0) st.add(i);
            }
            out.println(cnt);
            for (int i = 0; !st.isEmpty() && i < n; ++i)
            {
                int p = ans[i];
                if (mp[p] == 1) continue;
                if (p > st.first())
                {
                    mp[p]--;
                    ans[i] = st.first();
                    st.remove(st.first());
                }
                else
                {
                    if (not_Taken[p] != 0)
                    {
                        --mp[p];
                        ans[i] = st.first();
                        st.remove(st.first());
                    }
                    else
                    {
                        not_Taken[p]++;
                    }
                }
            }
            for (int i = 0; i < n; ++i)
            {
                out.print(ans[i] + " ");
            }
            out.close();
            return;

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