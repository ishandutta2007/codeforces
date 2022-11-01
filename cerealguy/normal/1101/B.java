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
        B solver = new B();
        solver.solve(1, in, out);
        out.close();
    }

    static class B {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String s = in.nextToken();
            int start = accordeon_start(s, "[:");
            int end = s.length() - accordeon_start(new StringBuilder(s).reverse().toString(), "]:");
            if (end < start) {
                out.println(-1);
                return;
            }
            int answer = 4;
            for (int i = start; i < end; i++) {
                if (s.charAt(i) == '|') {
                    answer++;
                }
            }
            out.println(answer);
        }

        private int accordeon_start(String s, String accordeon) {
            int start = 0;
            for (int i = 0; i < accordeon.length(); i++) {
                while (start < s.length() && s.charAt(start) != accordeon.charAt(i)) {
                    ++start;
                }
                ++start;
            }
            return start;
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

    }
}