import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {
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

    class Pair implements Comparable<Pair>
    {
        long x, y;

        public Pair(long x, long y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Pair o) {
            if (x == o.x)
            {
                return (int)( o.y - y);
            } else {
                return (int)(o.x - x);
            }
        }
    }

    void solve() throws IOException {
        int n = nextInt();
        int x1 = nextInt();
        int x2 = nextInt();
        Pair[] c = new Pair[n];
        for (int i = 0; i < n; i++)
        {
            c[i] = new Pair(nextInt(), i);
        }

        Arrays.sort(c);
        if (tryAns(x1, x2, n, c, true)) return;
        if (tryAns(x2, x1, n, c, false)) return;
        out.println("No");
    }

    void run() throws IOException {
        // br = new BufferedReader(new FileReader("dragons.in"));
        //out = new PrintWriter("dragons.out");
        // br = new BufferedReader(new FileReader("input.txt"));
        // out = new PrintWriter("output.txt");
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        br.close();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        // Locale.setDefault(Locale.US);
        new B().run();
    }

    void print(Pair[] c, int l, int r)
    {
        for (int i = l; i <= r; i++)
        {
            out.print(c[i].y + 1);
            if (i == r) {
                out.print("\n");
            } else {
                out.print(" ");
            }
        }
    }

    boolean tryAns(int s1, int s2, int n, Pair[] c, boolean rev){
        int a = -1;
        for (int i = 0; i < n; i++){
            if (c[i].x * (i + 1) >= s1){
                a = i;
                break;
            }
        }
        if (a == -1) return false;
        int b = -1;
        for (int i = a + 1; i < n; i++){
            if (c[i].x * (i - a) >= s2){
                b = i;
                break;
            }
        }
        if (b == -1) return false;
        if (rev){
            out.println("Yes");
            out.println((a + 1) + " " + (b - a));
            print(c, 0, a);print(c, a+1, b);
        } else {
            out.println("Yes");
            out.println((b - a) + " " + (a + 1));
            print(c, a+1, b);print(c, 0, a);
        }

        return true;
    }
}