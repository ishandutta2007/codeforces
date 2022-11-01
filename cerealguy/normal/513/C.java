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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] l = new int[n];
        int[] r = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = in.nextInt();
            r[i] = in.nextInt();
        }

        double expected = 0;

        for (int winner = 0; winner < n; winner++) {
            long[] ways1 = new long[r[winner] + 1];
            long[] ways2 = new long[r[winner] + 1];
            long all = 1;
            Arrays.fill(ways1, 1);
            Arrays.fill(ways2, 1);
            for (int man = 0; man < n; man++) {
                if (man == winner) {
                    continue;
                }
                long[] w = man < winner ? ways1 : ways2;
                all *= r[man] - l[man] + 1;
                Arrays.fill(w, 0, Math.min(w.length, l[man]), 0);
                for (int i = l[man]; i < r[man] && i < w.length; i++) {
                    w[i] *= i - l[man] + 1;
                }
                for (int i = r[man]; i < w.length; i++) {
                    w[i] *= r[man] - l[man] + 1;
                }
            }
            for (int secondVal = 1; secondVal <= r[winner]; secondVal++) {
                double pFirstGreater = (r[winner] - Math.max(secondVal, l[winner] - 1)) / (r[winner] - l[winner] + 1.0);
                {
                    long okWays = ways2[secondVal] * ways1[secondVal] - ways2[secondVal - 1] * ways1[secondVal - 1];
                    expected += pFirstGreater * okWays / all * secondVal;
                }
                double pFirstSame = (secondVal >= l[winner]) ? 1.0 / (r[winner] - l[winner] + 1.0) : 0;
                {
                    long okWays = ways2[secondVal] * ways1[secondVal - 1] - ways2[secondVal - 1] * ways1[secondVal - 1];
                    expected += pFirstSame * okWays / all * secondVal;
                }
            }
        }
        out.println(expected);
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