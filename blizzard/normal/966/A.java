import java.util.*;
import java.io.*;

public class A {
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

    int lest(int x, int y, int o, int d)
    {
        return (Math.abs(o - x) + Math.abs(o - y) + d);
    }

    int lift(int x, int y, int o, int d, int v)
    {
        return (Math.abs(o - x) + Math.abs(o - y) + (d + (v - 1)) / v);
    }

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int cl = nextInt();
        int ce = nextInt();
        int v = nextInt();
        ArrayList<Integer> les = new ArrayList<Integer>();
        ArrayList<Integer> elev = new ArrayList<Integer>();
        for (int i = 0 ; i < cl; i++)
        {
            les.add(nextInt());
        }
        for (int i = 0 ; i < ce; i++)
        {
            elev.add(nextInt());
        }
        int q = nextInt();
        while (q-- > 0)
        {
            int ans = Integer.MAX_VALUE;
            int x1 = nextInt();
            int y1 = nextInt();
            int x2 = nextInt();
            int y2 = nextInt();
            if (x1 == x2)
            {
                out.println(Math.abs(y1 - y2));
                continue;
            }
            if (y1 > y2) {
                int y = y1;
                y1 = y2;
                y2 = y;
            }

            int r = Collections.binarySearch(les, y1);
            if (r < 0) r = - r - 1;
            if (r >=0 && r < les.size())
            {
                ans = Math.min(ans, lest(y1, y2, les.get(r), Math.abs(x1 - x2)));
            }

            r = Collections.binarySearch(les, y2);
            if (r < 0) r = -r - 2;
            if (r >= 0 && r < les.size())
            {
                ans = Math.min(ans, lest(y1, y2, les.get(r), Math.abs(x1 - x2)));
            }

            r = Collections.binarySearch(elev, y1);
            if (r < 0) r = -r - 1;
            if (r >= 0 && r < elev.size())
            {
                ans = Math.min(ans, lift(y1, y2, elev.get(r), Math.abs(x1 - x2), v));
            }

            r = Collections.binarySearch(elev, y1);
            if (r < 0) r = -r - 2;
            if (r >= 0 && r < elev.size())
            {
                ans = Math.min(ans, lift(y1, y2, elev.get(r), Math.abs(x1 - x2), v));
            }


            r = Collections.binarySearch(elev, y2);
            if (r < 0) r = -r - 1;
            if (r >= 0 && r < elev.size())
            {
                ans = Math.min(ans, lift(y1, y2, elev.get(r), Math.abs(x1 - x2), v));
            }

            r = Collections.binarySearch(elev, y2);
            if (r < 0) r = -r - 2;
            if (r >= 0 && r < elev.size())
            {
                ans = Math.min(ans, lift(y1, y2, elev.get(r), Math.abs(x1 - x2), v));
            }
            out.println(ans);
        }
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
        new A().run();
    }
}