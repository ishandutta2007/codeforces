import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int a = in.nextInt();
        int b = in.nextInt();
        int[][] dude = new int[a][b];
        if (a * b < n) {
            out.println(-1);
        } else {
            for (int even = 0; even < 2; even++) {
                int cur = even + 1;
                for (int i = 0; i < a && cur <= n; i++) {
                    for (int j = (i ^ even) & 1; j < b; j += 2) {
                        dude[i][j] = cur++;
                    }
                }
            }
            int[] what = new int[]{1, 2};
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b; j++) {
                    int who = what[(i ^ j) & 1];
                    what[(i ^ j) & 1] += 2;
                    if (who > n) who = 0;
                    if (j > 0) {
                        out.print(' ');
                    }
                    out.print(who);
                }
                out.println();
            }
        }
    }
}

class InputReader {
    public BufferedReader br;
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