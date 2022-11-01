import java.io.*;
import java.util.*;

public class A {

    static void solve() throws IOException {
        int n = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        Arrays.sort(a);
        List<Integer> answer = new ArrayList<>();
        if (a[0] == 0) {
            answer.add(0);
        }
        if (a[n-1] == 100) {
            answer.add(100);
        }
        boolean ok = false;
        all: for (int i = 0; i < n; i++) {
            if (a[i] == 0 || a[i] == 100) {
                continue;
            }
            for (int j = 0; j < i; j++) {
                if (a[j] == 0 || a[j] == 100) {
                    continue;
                }
                if (canAdd(a[i], a[j])) {
                    answer.add(a[i]);
                    answer.add(a[j]);
                    ok = true;
                    break all;
                }
            }
        }
        if (!ok) {
            for (int i = 0; i < n; i++) {
                if (a[i] != 0 && a[i] != 100) {
                    answer.add(a[i]);
                    break;
                }
            }
        }
        out.println(answer.size());
        for (int i = 0; i < answer.size(); i++) {
            if (i > 0) {
                out.print(' ');
            }
            out.print(answer.get(i));
        }
    }
    
    

    private static boolean canAdd(int i, int j) {
        if (i <= 0 || i >= 100) {
            return false;
        }
        if (j <= 0 || j >= 100) {
            return false;
        }
        if (i % 10 == 0 && j < 10) {
            return true;
        }
        if (j % 10 == 0 && i < 10) {
            return true;
        }
        return false;
    }



    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;
        File file = new File("a.in");
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