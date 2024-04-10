import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.PrintStream;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        long id = in.nextLong() - 1;
        int[] answer = get(n, id);
        for (int i = 0; i < answer.length; i++) {
            if (i > 0) {
                out.print(' ');
            }
            out.print(answer[i]);
        }
        out.println();
    }

    static int[] get(int n, long id) {
        int[] answer = new int[]{1};
        for (int it = n - 2; it >= 0; --it) {
            int pos = -1;
            for (int p = 0; p < answer.length; p++) {
                if (answer[p] == answer.length) {
                    pos = p;
                    break;
                }
            }
            int[] to = new int[answer.length + 1];
            if ((id & (1L << it)) == 0) {
                System.arraycopy(answer, 0, to, 0, pos + 1);
                to[pos + 1] = to.length;
                System.arraycopy(answer, pos + 1, to, pos + 2, answer.length - (pos + 1));
            } else {
                System.arraycopy(answer, 0, to, 0, pos);
                to[pos] = to.length;
                System.arraycopy(answer, pos, to, pos + 1, answer.length - pos);
            }
            answer = to;
        }
        return answer;
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

    public long nextLong() {
        return Long.parseLong(nextToken());
    }

}