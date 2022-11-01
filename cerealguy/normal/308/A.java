import java.io.*;
import java.util.*;

public class A {

    static void solve() throws IOException {
        int n = nextInt(), length = nextInt(), time = nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        double answer = solve(n, a, length, time);
        out.println(answer);
    }

    private static double solve(int n, long[] a, long length, long time) {
        time *= 2;
        long fullCircles = time / length;
        long timeLeft = time % length;
        
        double pairsFullCircles = (double)n * (double)(n-1) * 0.25 * fullCircles;
        
        long[] b = Arrays.copyOf(a, 2 * n);
        for (int i = 0; i < n; i++) {
            b[i + n] = a[i] + length;
        }

        long pairs = getPairs(n, timeLeft, b);
        return pairs * 0.25 + pairsFullCircles;
    }

    private static long getPairs(int n, long time, long[] b) {
        int pointer = 0;
        long pairs = 0;
        for (int i = 0; i < n; i++) {
            if (pointer < i) {
                pointer = i;
            }
            while (pointer < i + n && b[pointer] <= b[i] + time) {
                pointer++;
            }
            int count = pointer - i;
//          System.err.println("count: "+count);
            pairs += count - 1;
        }
        return pairs;
    }

    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;
        File file = new File("a.in");
        if (file.exists() && file.canRead()) {
            input = new FileInputStream(file);
        }
        br = new BufferedReader(new InputStreamReader(input));
        out = new PrintWriter(output);
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