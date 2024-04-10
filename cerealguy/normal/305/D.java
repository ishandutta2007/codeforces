import static java.lang.Math.max;
import static java.lang.Math.min;

import java.io.*;
import java.util.*;

public class D {

    static int add(int a, int b) {
        a += b;
        if (a >= MOD || a < 0) {
            a -= MOD;
        }
        return a;
    }

    static final int MOD = 1000000007;

    static void solve() throws IOException {
        int n = nextInt(), edges = nextInt(), k = nextInt();
        int[] u = new int[edges];
        int[] v = new int[edges];
        for (int i = 0; i < edges; i++) {
            u[i] = nextInt() - 1;
            v[i] = nextInt() - 1;
        }
        int ways = ways(n, edges, k, u, v);
        out.println(ways);
    }

    private static int ways(int n, int edges, int k, int[] u, int[] v) {
        ++k;
        int minK = Integer.MAX_VALUE;
        int maxK = Integer.MIN_VALUE;
        int countK = 0;

        for (int i = 0; i < edges; i++) {
            int d = v[i] - u[i];
            if (d != 1 && d != k) {
                return 0;
            }
            if (d == k) {
                ++countK;
                minK = min(minK, u[i]);
                maxK = max(maxK, u[i]);
            }
        }

        int[] twoPow = new int[n + 1];
        twoPow[0] = 1;
        for (int i = 0; i < n; i++) {
            twoPow[i + 1] = add(twoPow[i], twoPow[i]);
        }

        if (minK != Integer.MAX_VALUE) {
            if (minK + k <= maxK) {
                return 0;
            }

            int answer = 0;

            for (int first = Math.max(0, maxK - k + 1); first <= minK; first++) {
                int maxLast = Math.min(first + k - 1, n - 1 - k);
                int count = maxLast - first + 1;
                count -= countK;
                if (first != minK) {
                    --count;
                }
                answer = add(answer, twoPow[count]);
            }

            return answer;
        } else {
            if (k >= n) {
                return 1;
            }
            int answer = 1;

            for (int first = 0; first + k < n; first++) {
                int maxLast = Math.min(first + k - 1, n - 1 - k);
                int count = maxLast - first + 1;
                --count;
                answer = add(answer, twoPow[count]);
            }

            return answer;

        }
    }

    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;
        File file = new File("d.in");
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