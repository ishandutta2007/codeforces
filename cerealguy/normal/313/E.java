/**
 * Created with IntelliJ IDEA.
 * User: Venky
 */

import java.io.*;
import java.util.*;

public class Main {
    static void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        List<Integer> num1 = new ArrayList<Integer>(n);
        List<Integer> num2 = new ArrayList<Integer>(n);
        List<Integer> res = new ArrayList<Integer>(n);
        for(int i=0;i<n;i++)
            num1.add(nextInt());
        for(int i=0;i<n;i++)
            num2.add(nextInt());
        Collections.sort(num1);
        Collections.sort(num2);
        int i1 = num1.size() - 1;
        List<Integer> num2Unprocessed = new ArrayList<Integer>();
        List<Integer> num2Processed = new ArrayList<Integer>();
        num2Unprocessed.addAll(num2);
        Collections.reverse(num2Unprocessed);
        while(i1 >= 0)
        {
            while (!num2Unprocessed.isEmpty() && num1.get(i1) + num2Unprocessed.get(num2Unprocessed.size() - 1) <= m - 1)
                num2Processed.add(num2Unprocessed.remove(num2Unprocessed.size() - 1));
            if(!num2Processed.isEmpty())
            {
                res.add(num1.get(i1) + num2Processed.remove(num2Processed.size() - 1));
                num1.remove(i1);
            }
            i1--;
        }
        num2.clear();
        num2.addAll(num2Processed);
        Collections.reverse(num2Unprocessed);
        num2.addAll(num2Unprocessed);
        i1 = num1.size() - 1;
        int i2 = num2.size() - 1;
        while(i1 >= 0 && i2 >= 0)
        {
            res.add((num1.get(i1) + num2.get(i2)) % m);
            i1--;
            i2--;
        }
        Collections.sort(res);
        for(int i = res.size() - 1;i>=0;i--)
        {
            if(i < res.size()-1)
                out.print(" ");
            out.print(res.get(i));
        }
    }

    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        InputStream input = System.in;
        br = new BufferedReader(new InputStreamReader(input));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }
}