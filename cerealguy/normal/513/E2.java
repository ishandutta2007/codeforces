import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        int[] s = new int[n + 1];
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] + a[i];
        }
        long[][] dp1 = new long[k][n + 1];
        long[][] dp2 = new long[k][n + 1];
        final long INF = Long.MIN_VALUE / 2;
        for (long[] d : dp1) {
            Arrays.fill(d, INF);
        }
        for (long[] d : dp2) {
            Arrays.fill(d, INF);
        }
        long problemAnswer = INF;
        int maxSum = 0, minSum = 0;
        for (int to = 1; to <= n; to++) {
            dp1[0][to] = s[to] - minSum;
            dp2[0][to] = maxSum - s[to];
            maxSum = Math.max(maxSum, s[to]);
            minSum = Math.min(minSum, s[to]);
        }
        for (int segments = 0; segments < k - 1; segments++) {
            long[] d1 = dp1[segments + 1];
            long[] d2 = dp2[segments + 1];
            long[] prev1 = dp1[segments];
            long[] prev2 = dp2[segments];
            long dd2 = d2[0];
            long dd1 = d1[0];
            long tt1 = INF;
            long tt2 = INF;
            long tt3 = INF;
            long tt4 = INF;
            for (int to = 1; to <= n; to++) {
                tt1 = Math.max(tt1, prev1[to - 1] + s[to - 1]);
                tt2 = Math.max(tt2, prev2[to - 1] - s[to - 1]);
                tt3 = Math.max(tt3, prev1[to - 1] + 2 * s[to - 1]);
                tt4 = Math.max(tt4, prev2[to - 1] - 2 * s[to - 1]);
                long best1 = Math.max(tt1 - s[to], tt2 + s[to]);
                if (segments == k - 2) {
                    problemAnswer = Math.max(problemAnswer, best1);
                }
                long ok1 = tt4 + 2 * s[to];
                long ok2 = tt3 - 2 * s[to];
                long ok3 = prev1[to - 1];
                long ok4 = prev2[to - 1];
                if (ok1 < ok3) {
                    ok1 = ok3;
                }
                if (dd1 < ok1) {
                    dd1 = ok1;
                }
                if (ok2 < ok4) {
                    ok2 = ok4;
                }
                if (dd2 < ok2) {
                    dd2 = ok2;
                }
                d1[to] = dd1;
                d2[to] = dd2;
            }
        }
        out.println(problemAnswer);
    }
}

class InputReader {
    BufferedReader br;
    StringTokenizer st;

    public InputReader(InputStream stream) {
        br = new BufferedReader(new InputStreamReader(stream));
    }

    public String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            String line = null;
            try {
                line = br.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

}