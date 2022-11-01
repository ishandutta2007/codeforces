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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int rows = in.nextInt();
        int cols = in.nextInt();
        int garbage = in.nextInt();
        String[] grid = new String[rows];
        for (int i = 0; i < rows; i++) {
            grid[i] = in.nextToken();
        }
        for (int startCol = 0; startCol < cols; startCol++) {
            int curAns = 0;
            for (int j = 1; j < rows; j++) {
                if (startCol >= j && grid[j].charAt(startCol - j) == 'R') {
                    ++curAns;
                }
                if (startCol + j < cols && grid[j].charAt(startCol + j) == 'L') {
                    ++curAns;
                }
                if (j + j < rows && grid[j + j].charAt(startCol) == 'U') {
                    ++curAns;
                }
            }
            if (startCol > 0) {
                out.print(' ');
            }
            out.print(curAns);
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