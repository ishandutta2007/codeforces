import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    BufferedReader in;
    StringTokenizer stok;
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    boolean eq(int x1, int y1, int x2, int y2) {
        return (x1 == x2) && (y1 == y2);
    }

    int f(int x1, int y1, int x2, int y2) {
        return abs(abs(x2 - x1) - abs(y2 - y1));
    }

    void solve() throws IOException {
        int x1 = nextInt();
        int y1 = nextInt();
        int x2 = nextInt();
        int y2 = nextInt();
        boolean poly = true;
        while ((x1 != 0 || y1 != 0) && (x2 != 0 || y2 != 0)) {
            if (poly) {
                if (x1 > 0 && (y1 == 0 || f(x1 - 1, y1, x2, y2) <= f(x1, y1 - 1, x2, y2))) {
                    if (!eq(x1 - 1, y1, x2, y2)) {
                        x1--;
                    } else if (y1 > 0) {
                        y1--;
                    }
                } else {
                    if (!eq(x1, y1 - 1, x2, y2)) {
                        y1--;
                    } else if (x1 > 0) {
                        x1--;
                    }
                }
            } else {
                if (x2 > 0 && y2 > 0) {
                    if (!eq(x1, y1, x2 - 1, y2 - 1)) {
                        x2--;
                        y2--;
                    } else {
                        x2--;
                    }
                } else if (x2 > 0) {
                    if (!eq(x1, y1, x2 - 1, y2)) {
                        x2--;
                    }
                } else if (y2 > 0) {
                    if (!eq(x1, y1, x2, y2 - 1)) {
                        y2--;
                    }
                }
            }
            poly = !poly;
        }
        println(poly ? "Vasiliy" : "Polycarp");
    }

    void run() {
        try {
            solve();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(abs(-1));
        } finally {
            close();
        }
    }

    Main() throws IOException {
        super(System.out);
        in = new BufferedReader(new InputStreamReader(System.in));
    }

    Main(String filename) throws IOException {
        super("".equals(filename) ? "output.txt" : filename + ".out");
        in = new BufferedReader(new FileReader("".equals(filename) ? "input.txt" : filename + ".in"));
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    String next() throws IOException {
        while (stok == null || !stok.hasMoreTokens()) {
            String s = in.readLine();
            if (s == null) {
                return null;
            }
            stok = new StringTokenizer(s);
        }
        return stok.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    int[] nextIntArray(int len) throws IOException {
        int[] res = new int[len];
        for (int i = 0; i < len; i++) {
            res[i] = nextInt();
        }
        return res;
    }

    void shuffle(int[] a) {
        for (int i = 1; i < a.length; i++) {
            int x = rand.nextInt(i + 1);
            int _ = a[i];
            a[i] = a[x];
            a[x] = _;
        }
    }

    boolean nextPerm(int[] p) {
        for (int a = p.length - 2; a >= 0; --a)
            if (p[a] < p[a + 1])
                for (int b = p.length - 1; ; --b)
                    if (p[b] > p[a]) {
                        int t = p[a];
                        p[a] = p[b];
                        p[b] = t;
                        for (++a, b = p.length - 1; a < b; ++a, --b) {
                            t = p[a];
                            p[a] = p[b];
                            p[b] = t;
                        }
                        return true;
                    }
        return false;
    }

    <T> List<T>[] createAdjacencyList(int countVertex) {
        List<T>[] res = new List[countVertex];
        for (int i = 0; i < countVertex; i++) {
            res[i] = new ArrayList<T>();
        }
        return res;
    }

    class Pair<A extends Comparable<A>, B extends Comparable<B>> implements Comparable<Pair<A, B>> {
        A a;
        B b;

        public Pair(A a, B b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public int compareTo(Pair<A, B> o) {
            int aa = a.compareTo(o.a);
            return aa == 0 ? b.compareTo(o.b) : aa;
        }
    }
}