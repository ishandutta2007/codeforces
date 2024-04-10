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
        static Long dp[][] = new Long[100][100];

        public void solve(int testNumber, InputReader in, PrintWriter out)
        {
            long n;
            n = in.nextInt();
            long cur = 0;
            for (int i = 0; i < n; i++)
            {
                long s, d;
                s = in.nextInt();
                d = in.nextInt();
                cur = Math.max(s, cur);
                if ((cur - s) % d != 0)  cur += d - ((cur - s) % d);
                cur++;
            }
            out.println(cur - 1);

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

        public Long nextInt() {
            return Long.parseLong(next());
        }

        public float nextFloat() {
            return Float.parseFloat(next());
        }
    }
}