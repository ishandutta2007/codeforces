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
        static int N = 100005;


        public void solve(int testNumber, InputReader in, PrintWriter out)
        {

            Random random = new Random(94739534513L + System.currentTimeMillis());
            int a, b, f, k , now , d  , res = 0;
            a = in.nextInt();
            b = in.nextInt();
            now = b;
            f = in.nextInt();
            d = f;
            k = in.nextInt();
            for (int i = 0; i < k; i++, d = a + (-d))
            {
                if (i + 1 == k)
                {
                    if (now >= a)
                    {
                        out.println(res);
                        out.close();
                        return;
                    } 
                    else 
                    {
                        if (now >= d && (b + d) >= a)
                        {
                            out.println(res+ 1);
                        } 
                        else
                        {
                            out.println(-1);
                            out.close();
                            return ;
                        }
                    }
                }
                if (now + d >= 2 * a)
                {
                    now -= a;
                    if (now < 0)
                    {
                        out.println(-1);
                        out.close();
                        return ;
                    }
                }
                else 
                    {
                    now -= d;
                    if (now < 0)
                    {
                        out.println(-1);
                        out.close();
                        return ;
                    }
                    now = b + d - a;
                    if (now < 0)
                    {
                        out.println(-1);
                        out.close();
                        return ;
                    }
                    res+= 1;
                }
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