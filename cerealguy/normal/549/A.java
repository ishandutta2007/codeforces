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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int r = in.nextInt();
        int c = in.nextInt();
        String[] s = new String[r];
        for (int i = 0; i < r; i++) {
            s[i] = in.nextToken();
        }
        int answer = 0;
        for (int i = 0; i < r - 1; i++) {
            for (int j = 0; j < c - 1; j++) {
                char[] t = new char[4];
                int cnt = 0;
                for (int i1 = 0; i1 < 2; i1++) {
                    for (int j1 = 0; j1 < 2; j1++) {
                        t[cnt++] = s[i+i1].charAt(j+j1);
                    }
                }
                Arrays.sort(t);
                if ("acef".equals(new String(t))) {
                    ++answer;
                }
            }
        }
        out.println(answer);
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