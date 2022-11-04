import java.io.*;
import java.util.*;

public class B {
    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;

    public String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }
        return in.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public static void main(String[] args) throws IOException {
        new B().run();
    }

    public void solve() throws IOException {
        int n = nextInt();
        int[] w = new int[n];
        int[] h = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = nextInt();
            h[i] = nextInt();
        }
        int[][] dp = new int[n + 1][1001];
        for (int i = 0; i < n + 1; i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        }
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 1001; j++) {
                if (dp[i][j] != Integer.MAX_VALUE) {
                    dp[i + 1][Math.max(j, h[i])] = Math.min(dp[i + 1][Math.max(j, h[i])], dp[i][j] + w[i]);
                    dp[i + 1][Math.max(j, w[i])] = Math.min(dp[i + 1][Math.max(j, w[i])], dp[i][j] + h[i]);
                }
            }
        }
        long res = Long.MAX_VALUE;
        for (int i = 0; i < 1001; i++) {
            if (dp[n][i] != Integer.MAX_VALUE) {
                res = Math.min(res, dp[n][i] * i);
            }
        }
        out.println(res);
    }

    public void run() {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}