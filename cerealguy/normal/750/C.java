import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] c = new int[n];
            int[] d = new int[n];
            for (int i = 0; i < n; i++) {
                c[i] = in.nextInt();
                d[i] = in.nextInt();
            }
            int maxRating = Integer.MAX_VALUE;
            int minRating = Integer.MIN_VALUE;
            int change = 0;
            for (int i = 0; i < n; change += c[i], i++) {
                if (d[i] == 1) {
                    minRating = Math.max(minRating, 1900 - change);
                } else {
                    maxRating = Math.min(maxRating, 1899 - change);
                }
            }
            if (minRating > maxRating) {
                out.println("Impossible");
                return;
            }
            if (maxRating == Integer.MAX_VALUE) {
                out.println("Infinity");
                return;
            }
            out.println(maxRating + change);
        }

    }

    static class InputReader {
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
}