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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int pos = 0;
            int max = 20000;
            for (int i = 0; i < n; i++) {
                int dist = in.nextInt();
                String dirS = in.nextToken();
                int dir;
                if ("North".equals(dirS)) {
                    dir = -1;
                } else if ("South".equals(dirS)) {
                    dir = 1;
                } else {
                    dir = 0;
                    if (pos == 0 || pos == max) {
                        out.println("NO");
                        return;
                    }
                }
                pos += dir * dist;
                if (pos < 0 || pos > max) {
                    out.println("NO");
                    return;
                }
            }
            if (pos != 0) {
                out.println("NO");
                return;
            }
            out.println("YES");
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