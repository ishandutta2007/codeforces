import java.io.*;
import java.util.*;

public class B {

    static void solve() throws IOException {
        int n = nextInt(), r = nextInt(), c = nextInt() + 1;
        String[] input = new String[n];
        for (int i = 0; i < n; i++) {
            input[i] = nextToken();
        }
        int[] lengths = new int[n];
        for (int i = 0; i < n; i++) {
            lengths[i] = input[i].length();
        }

        int[] to = new int[n + 1];
        int ptr = 0;
        int totalLength = 0;
        for (int i = 0; i < n; i++) {
            if (ptr > i) {
                totalLength -= lengths[i - 1] + 1;
            } else {
                totalLength = 0;
                ptr = i;
            }
            while (ptr < n && totalLength + lengths[ptr] + 1 <= c) {
                totalLength += lengths[ptr] + 1;
                ptr++;
            }
            to[i] = ptr;
        }
        to[n] = n;
        int[][] jump = new int[22][n + 1];
        jump[0] = to;
        for (int it = 1; it < jump.length; it++) {
            int[] cur = jump[it];
            int[] prev = jump[it - 1];
            for (int j = 0; j <= n; j++) {
                cur[j] = prev[prev[j]];
            }
        }

        int bestVal = -1;
        int bestLeft = -1;
        for (int start = 0; start < n; start++) {
            int ok = start;
            for (int it = 0; it < jump.length; it++) {
                if ((r & (1 << it)) == 0) {
                    continue;
                }
                ok = jump[it][ok];
            }
            int curVal = ok - start;
            if (curVal > bestVal) {
                bestVal = curVal;
                bestLeft = start;
            }
        }

        int ok = bestLeft;
        for (int i = 0; i < r; i++) {
            for (int j = ok; j < to[ok]; j++) {
                if (j > ok) {
                    out.print(' ');
                }
                out.print(input[j]);
            }
            out.println();
            ok = to[ok];
        }
    }

    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;
        File file = new File("b.in");
        if (file.exists() && file.canRead()) {
            input = new FileInputStream(file);
        }
        br = new BufferedReader(new InputStreamReader(input));
        out = new PrintWriter(output);
        solve();
        out.close();
    }

    static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }
}