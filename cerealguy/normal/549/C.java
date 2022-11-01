import java.io.InputStreamReader;
import java.io.IOException;
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
        int k = in.nextInt();
        int even = 0;
        int odd = 0;
        for (int i = 0; i < n; i++) {
            if (in.nextInt() % 2 == 0) {
                ++even;
            } else {
                ++odd;
            }
        }

        boolean oddWins = oddWins(k, even, odd);
        out.println(oddWins ? "Stannis" : "Daenerys");
    }

    private boolean oddWins(int k, int even, int odd) {
        if (even + odd == k) {
            return odd % 2 != 0;
        }
        if (Math.abs(odd - even) < k) {
            return (even + odd) % 2 != k % 2;
        }
        if (k % 2 == 1 && odd >= even + k) {
            return true;
        }
        return false;
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