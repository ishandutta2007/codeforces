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
        int rows = in.nextInt(), cols = in.nextInt();
        int levels = in.nextInt();
        int weight = in.nextInt();
        String[][] input = new String[levels][rows];
        for (int lvl = 0; lvl < levels; lvl++) {
            for (int row = 0; row < rows; row++) {
                input[lvl][row] = in.nextToken();
            }
        }
        int[][] diff = new int[levels][levels];
        for (int lvl = 0; lvl < levels; lvl++) {
            for (int other = 0; other < lvl; other++) {
                String[] a = input[lvl];
                String[] b = input[other];
                int d = 0;
                for (int row = 0; row < rows; row++) {
                    String s1 = a[row];
                    String s2 = b[row];
                    for (int col = 0; col < cols; col++) {
                        if (s1.charAt(col) != s2.charAt(col)) {
                            ++d;
                        }
                    }
                }
                diff[lvl][other] = d;
                diff[other][lvl] = d;
            }
        }
        boolean[] was = new boolean[levels];
        int[] dist = new int[levels];
        int[] parent = new int[levels];
        Arrays.fill(parent, -1);
        Arrays.fill(dist, rows * cols);
        StringBuilder output = new StringBuilder();
        int cost = 0;
        for (int it = 0; it < levels; it++) {
            int best = -1;
            for (int i = 0; i < levels; i++) {
                if (was[i]) {
                    continue;
                }
                if (best < 0 || dist[best] > dist[i]) {
                    best = i;
                }
            }
            cost += dist[best];
            was[best] = true;
            int printX = best + 1;
            int printY = parent[best] + 1;
            output.append(printX + " " + printY).append('\n');
            for (int i = 0; i < levels; i++) {
                if (was[i]) {
                    continue;
                }
                if (dist[i] > diff[best][i] * weight) {
                    dist[i] = diff[best][i] * weight;
                    parent[i] = best;
                }
            }
        }
        out.println(cost);
        out.print(output);
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