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
        int k = in.nextInt();
        int[] p = new int[n];
        for (int i = 0; i < k; i++) {
            if (i % 2 == 0) {
                p[i] = i / 2;
            } else {
                p[i] = n - 1 - i / 2;
            }
        }
        if (k % 2 != 0) {
            for (int i = k; i < n; i++) {
                p[i] = p[i - 1] + 1;
            }
        } else {
            for (int i = k; i < n; i++) {
                p[i] = p[i - 1] - 1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (i > 0) {
                out.print(' ');
            }
            out.print(p[i] + 1);
        }
        out.println();
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