import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {
    BufferedReader br;
    PrintWriter out;
    StringTokenizer stok;

    String nextToken() throws IOException {
        while (stok == null || !stok.hasMoreTokens()) {
            String s = br.readLine();
            if (s == null) {
                return null;
            }
            stok = new StringTokenizer(s);
        }
        return stok.nextToken();
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

    char nextChar() throws IOException {
        return (char) (br.read());
    }

    String nextLine() throws IOException {
        return br.readLine();
    }

    long c;
    long h1;
    long h2;
    long w1;
    long w2;

    /* double f(double x) {
         double y = (c - w1 * x) / w2;
         return h1 * x + h2 * y;
     }*/
    class Point {
        long x, y;

        Point(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }

    public long gcd(long a, long b) {
        if (b == 0) return a;
        long x = a % b;
        return gcd(b, x);
    }

    private void solve() throws IOException {
        final long  MAXC = 3000000;
        long c = nextLong();
        long h1 = nextLong();
        long h2 = nextLong();
        long w1 = nextLong();
        long w2 = nextLong();
        if (h1 * 1. / w1 > h2 * 1. / w2) {
            long x = h1;
            long y = w1;
            h1 = h2;
            w1 = w2;
            h2 = x;
            w2 = y;
        }
        long y = (long) (c + .0) / (w2);
        long max = -1;
        for (long j = y - MAXC; j < y + MAXC; j++) {
            long i = (long) Math.floor((c - j * w2) * 1. / w1);
            if (j < 0 || i < 0) {
                continue;
            }
            max = Math.max(i * h1 + j * h2, max);
        }
        for (long j = 0 ; j < Math.min(y, MAXC); j++) {
            long i = (long) Math.floor((c - j * w2) * 1. / w1);
            if (j < 0 || i < 0) {
                continue;
            }
            max = Math.max(i * h1 + j * h2, max);
        }
        out.println(max);
    }


    void run() throws IOException {
        //br = new BufferedReader(new FileReader("input.txt"));
        //out = new PrintWriter("output.txt");
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        br.close();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        // Locale.setDefault(Locale.US);
        new C().run();
    }
}