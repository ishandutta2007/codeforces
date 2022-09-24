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
static int N = (int) 3e5;
ArrayList<Integer> a = new  ArrayList<Integer>();
ArrayList<Integer> b = new  ArrayList<Integer>();
public void solve(int testNumber, InputReader in, PrintWriter out)
        {
            int n = in.nextInt();
            int cnt = 0;

            a.add(0);
            a.add(1);
            b.add(1);

            while (b.size() != n)
            {
                ArrayList<Integer> c = new ArrayList<Integer>();
                c.add(0);

                for (int i = 0; i < (int)a.size(); i++)
                {
                    c.add(a.get(i));
                }

                boolean fl = true;

                for (int i = 0; i < (int)b.size(); i++)
                {
                    if (-1 <= c.get(i) + b.get(i) && c.get(i) + b.get(i) <= 1);
                    else
                    {
                        fl = false;
                        break;
                    }
                }

                if (!fl) 
                {
                    fl = true;

                    for (int i = 0; i < (int)b.size(); i++)
                    {
                        if (-1 <= c.get(i) - b.get(i) && c.get(i) - b.get(i) <= 1);
                        else
                        {
                            fl = false;
                            break;
                        }
                    }

                    if (!fl) {
                        out.println(b.size());
                        out.close();
                        return;
                    }

                    for (int i = 0; i < (int)b.size(); i++) {
                        c.set(i  , c.get(i) - b.get(i));
                    }
                }
                else 
                {
                    for (int i = 0; i < (int)b.size(); i++)
                    {
                        c.set(i  , c.get(i) + b.get(i));
                    }
                }

                b = a;
                a = c;
            }

            if (a.get(a.size() - 1) < 0)
            {
                for (int i = 0; i < (int)a.size(); i++)
                {
                    a.set(i  , -a.get(i));
                }
            }

            if (b.get(b.size() - 1) < 0) 
            {
                for (int i = 0; i < (int)b.size(); i++) 
                {
                    b.set(i  , -b.get(i));
                }
            }

            out.println(a.size() - 1);

            for (int i = 0; i < (int)a.size(); i++)
            {
                out.print(a.get(i) + " ");
            }

            out.println();
            out.println(b.size() - 1);

            for (int i = 0; i < (int)b.size(); i++)
            {
                out.print(b.get(i) + " ");
            }
            out.println();
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