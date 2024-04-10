import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.NavigableMap;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {
    static void zap() throws IOException {
        int n = nextInt();
        NavigableMap<Integer, Integer> my = new TreeMap<Integer, Integer>();
        for(int i=0;i<n;i++)
        {
            int number = nextInt();
            if(my.containsKey(number))
                my.put(number, my.get(number) + 1);
            else
                my.put(number, 1);
        }
        for(Integer thisKey = my.firstKey(); thisKey != null; thisKey = my.higherKey(thisKey))
        {
            int occur = my.get(thisKey);
            if(occur == 1)
                continue;
            int incrNext = occur / 2;
            if(my.containsKey(thisKey+1))
                my.put(thisKey+1, my.get(thisKey+1) + incrNext);
            else
                my.put(thisKey+1, incrNext);
            if(occur % 2 == 0)
                my.remove(thisKey);
            else
                my.put(thisKey, 1);
        }
        out.println(my.lastKey() + 1 - my.size());
    }

    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        InputStream input = System.in;
        br = new BufferedReader(new InputStreamReader(input));
        out = new PrintWriter(System.out);
        zap();
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