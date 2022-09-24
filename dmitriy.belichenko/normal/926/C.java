import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.InputStream;
import java.io.*;
import java.lang.Math.*;
import java.math.*;
/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main
{
    static int n;
    public static void main(String[] args) throws Exception
    {
        // InputStream inputStream = new FileInputStream (new File("kitchen.in"));
        // OutputStream outputStream = new FileOutputStream(new File("kitchen.out"));
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task {
        static long INF = Long.MAX_VALUE;
        static int N = (int) 1e5;
        static int a[] = new int[200000];

        public void solve(int testNumber, InputReader in, PrintWriter out)
        {
            int n;
            n = in.nextInt();
            for(int i = 0; i < n; i++) a[i] = in.nextInt();
            TreeSet<Integer> ar = new TreeSet<Integer>();
            for(int i = 0; i < n; i++)
            {
                int j = 0;
                while(a[i] == a[i + 1] && i < n - 1)
                {
                    j++;
                    i++;
                }
                ar.add(j);
            }
            if(ar.size() == 1) out.println("YES");
            else out.println("NO");
            
         //   out.println(cur - 1);

            out.close();
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

        public float nextFloat() {
            return Float.parseFloat(next());
        }
    }
}