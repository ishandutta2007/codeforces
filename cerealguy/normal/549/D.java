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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int r = in.nextInt();
        int c = in.nextInt();
        char[][] s = new char[r][];
        for (int i = 0; i < r; i++) {
            s[i] = in.nextToken().toCharArray();
        }
        int[][] k = new int[r][c];
        int answer = 0;
        for (int i = r - 1; i >= 0; --i) {
            for (int j = c - 1; j >= 0; --j) {
                char val = s[i][j];
                if (k[i][j] != get(val)) {
                    ++answer;
                    int diff = get(val) - k[i][j];
                    for (int i1 = 0; i1 <= i; i1++) {
                        int[] kI1 = k[i1];
                        for (int j1 = 0; j1 <= j; j1++) {
                            kI1[j1] += diff;
                        }
                    }
                }
            }
        }
        out.println(answer);
    }

    static int get(char c) {
        return c == 'B' ? -1 : 1;
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