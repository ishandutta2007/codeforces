import java.io.*;
import java.util.*;

public class E {

    private void solve() throws IOException {
        int n = nextInt();
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        int[] b = a.clone();
        Arrays.sort(b);
        for (int i = 0; i < n; i++) {
            a[i] = Arrays.binarySearch(b, a[i]);
        }
        higherBefore = new int[n];
        lowerAfter = new int[n];
        temp = new int[n];
        mergeSort(0, n);
        long res = 0;
        for (int i = 0; i < n; i++) {
            res += (long) higherBefore[i] * lowerAfter[i];
        }
        out.println(res);
    }

    int[] a;
    int[] higherBefore;
    int[] lowerAfter;
    int[] temp;

    void mergeSort(int l, int r) {
        if (r - l < 2)
            return;
        int m = (l + r >> 1);
        mergeSort(l, m);
        mergeSort(m, r);
        int i = l;
        int j = m;
        int it;
        for (it = l; it < r; it++) {
            if (i < m && (j == r || a[i] < a[j])) {
                lowerAfter[a[i]] += j - m;
                temp[it] = a[i++];
            } else {
                higherBefore[a[j]] += m - i;
                temp[it] = a[j++];
            }
        }
        for (it = l; it < r; it++) {
            a[it] = temp[it];
        }
    }

    public static void main(String[] args) {
        new E().run();
    }

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;
    boolean eof = false;

    public void run() {
        Locale.setDefault(Locale.US);
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
            st = new StringTokenizer("");
            solve();
            out.close();
        } catch (Throwable e) {
            e.printStackTrace();
            System.exit(239);
        }
    }

    String nextToken() throws IOException {
        while (!st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) {
                eof = true;
                line = "0";
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }
}