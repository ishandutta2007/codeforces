
import java.io.*;
import java.util.*;

public class B {

    private static void solve() throws IOException {
    int n = nextInt();
int best = 0, left = nextInt(), right = nextInt();
int max = right;
for( int i = 1; i < n; i++) {
int l = nextInt(), r = nextInt();
if (l < left || l == left && r > right) {
left = l;
right = r;
best = i;
}
if (max < r) max = r;
}
out.println(max <= right? (best+1): -1);
    }
    
    public static void main(String[] args) {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
            solve();
            out.close();
        } catch (Throwable e) {
            e.printStackTrace();
            System.exit(239);
        }
    }

    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

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

    static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }
}