import java.io.InputStreamReader;
import java.io.IOException;
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
        id = in.nextInt();
        go1(new int[n], 0);
        for (int i = 0; i < answer.length; i++) {
            if (i > 0) {
                out.print(' ');
            }
            out.print(answer[i]);
        }
        out.println();
    }

    static int[] maxSums = {0, 1, 4, 10, 20, 35, 56, 84, 120, 0};

    static int id;
    static int[] answer;

    static void go1(int[] p, int start) {
        if (start == p.length) {
            int sum = calc(p);
            if (sum == maxSums[p.length] && --id == 0) {
                answer = p.clone();
            }
            return;
        }
        for (int val = 1; val <= p.length; val++) {
            boolean ok = true;
            for (int i = 0; i < start; i++) {
                if (p[i] == val) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                continue;
            }
            p[start] = val;
            go1(p, start + 1);
        }
    }

    private static int calc(int[] p) {
        int s = 0;
        for (int i = 0; i < p.length; i++) {
            for (int j = i; j < p.length; j++) {
                int val = Integer.MAX_VALUE;
                for (int k = i; k <= j; k++) {
                    val = Math.min(val, p[k]);
                }
                s += val;
            }
        }
        return s;
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