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
        for (int to = 0; to <= n; to++) {
            for (int from = 0; from < to; from++) {
                dp1[0][to] = Math.max(dp1[0][to], s[to] - s[from]);
                dp2[0][to] = Math.max(dp2[0][to], -(s[to] - s[from]));
            }
        }
        long[] t1 = new long[n + 1];
        long[] t2 = new long[n + 1];
        long[] t3 = new long[n + 1];
        long[] t4 = new long[n + 1];
        for (int segments = 0; segments < k - 1; segments++) {
            long[] d1 = dp1[segments + 1];
            long[] d2 = dp2[segments + 1];
            long[] prev1 = dp1[segments];
            long[] prev2 = dp2[segments];
            Arrays.fill(t1, INF);
            Arrays.fill(t2, INF);
            Arrays.fill(t3, INF);
            Arrays.fill(t4, INF);
            for (int from = 0; from <= n; from++) {
                t1[from] = prev1[from] + s[from];
                t2[from] = prev2[from] - s[from];
                t3[from] = prev1[from] + 2 * s[from];
                t4[from] = prev2[from] - 2 * s[from];
            }
            for (int from = 1; from <= n; from++) {
                t1[from] = Math.max(t1[from - 1], t1[from]);
                t2[from] = Math.max(t2[from - 1], t2[from]);
                t3[from] = Math.max(t3[from - 1], t3[from]);
                t4[from] = Math.max(t4[from - 1], t4[from]);
            }
            for (int to = 1; to <= n; to++) {
                d1[to] = Math.max(d1[to], d1[to - 1]);
                d2[to] = Math.max(d2[to], d2[to - 1]);
                long best1 = Math.max(t1[to - 1] - s[to], t2[to - 1] + s[to]);
                if (segments == k - 2) {
                    problemAnswer = Math.max(problemAnswer, best1);
                }
                long ok1 = t4[to - 1] + 2 * s[to];
                long ok2 = t3[to - 1] - 2 * s[to];
                long ok3 = prev1[to - 1];
                long ok4 = prev2[to - 1];
                d1[to] = Math.max(d1[to - 1], Math.max(ok1, ok3));
                d2[to] = Math.max(d2[to - 1], Math.max(ok2, ok4));
//                for (int from = 0; from < to; from++) {
//                    int curSum = s[to] - s[from];
//                    long best = Math.max(prev2[from] + curSum, prev1[from] - curSum);
//                    if (segments == k - 2) {
//                        problemAnswer = Math.max(problemAnswer, best);
//                    }
//                    d1[to] = Math.max(d1[to], best + curSum);
//                    d2[to] = Math.max(d2[to], best - curSum);
//                }
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