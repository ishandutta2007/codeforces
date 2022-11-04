import java.io.*;
import java.util.*;

public class B {
    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;

    public String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }
        return in.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public static void main(String[] args) throws IOException {
        new B().run();
    }

    class Man implements Comparable<Man> {
        int n;
        long w;
        long h;

        public Man(int n, long w, long h) {
            this.n = n;
            this.w = w;
            this.h = h;
        }

        @Override
        public int compareTo(Man o) {
            return Long.compare(this.h, o.h);
        }
    }

    public void solve() throws IOException {
        int n = nextInt();
        Man[] a = new Man[n];
        long sum = 0;
        for (int i = 0; i < n; i++) {
            long w = nextLong();
            long h = nextLong();
            sum += w;
            a[i] = new Man(i, w, h);
        }
        long[] b = new long[n];
        Arrays.sort(a);
        for (int i = 0; i < n; i++) {
            long w1 = sum - a[i].w;
            long h1 = a[n - 1].h;
            if (i == n - 1) {
                h1 = a[n - 2].h;
            }
            b[a[i].n] = w1 * h1;
        }
        for (int i = 0; i < n; i++) {
            out.print(b[i] + " ");
        }
    }

    public void run() {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}