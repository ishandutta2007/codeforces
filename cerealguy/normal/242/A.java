
import java.io.*;
import java.util.*;

public class B {

    private static void solve() throws IOException {
    int x = nextInt(), y = nextInt(), a =nextInt(), b = nextInt();
int cnt = 0;
for (int i = a; i <= x ; i++) { for (int j = b; j <= y && j < i; j++) {
cnt++;
}
}
out.println(cnt);
for (int i = a; i <= x ; i++) { for (int j = b; j <= y && j < i; j++) {
out.println(i+" "+j);
}
}
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