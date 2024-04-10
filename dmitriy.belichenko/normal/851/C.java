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

    static double x[][] = new double[1005][5];
    static boolean bad[] = new boolean[1005];

   static boolean check(int a, int b, int c) {
        int p=0;
        for (int i=0; i<5; i++) {
            p+=(x[b][i]-x[a][i])*(x[c][i]-x[a][i]);
        }
        if (p>0) return true;
        else return false;
    }

    static class TaskD
    {



        public void solve(int testNumber, InputReader in, PrintWriter out)
        {
            // zzzzz
            Random random = new Random(94739534513L + System.currentTimeMillis());
             n = in.nextInt();

          
            for (int i=0; i<n; i++) {
                for (int j=0; j<5; j++)
                    x[i][j] = in.nextInt();
            }
            for (int a = 0; a<n; a++)
            {
                if (!bad[a]) 
                {
                    for (int b = a + 1; b < n; b++) 
                    {
                        for (int c = b + 1; c < n; c++) 
                        {
                            if (bad[a] || check(a,b,c)) bad[a] = true;
                            if (bad[b] || check(b,a,c)) bad[b] = true;
                            if (bad[c] || check(c,a,b)) bad[c] = true;
                        }
                    }
                }
            }
            int good = 0;
            for (int i=0; i<n; i++)
                if (!bad[i]) good++;
            out.println(good);
            for (int i=0; i<n; i++)
                if (!bad[i]) out.println(i + 1);
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