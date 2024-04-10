import java.util.*;

public class A {
    Scanner in;

    class Solver {
        ArrayList[] g;
        Integer[] f;
        int n;
        boolean bad = false;

        Solver() {
            n = in.nextInt();
            g = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                g[i] = new ArrayList<Integer>();
                for (int k = in.nextInt(); k > 0; k--)
                    g[i].add(in.nextInt() - 1);
            }
        }

        void calc(int v) {
            f[v] = -2;
            var ma = 1;
            for (var _x : g[v]) {
                int x = (Integer) _x;
                if (f[x] == -2) bad = true;
                if (f[x] == -1) calc(x);
                ma = Math.max(ma, f[x] + (x > v ? 1 : 0));
            }
            f[v] = ma;
        }

        int solve() {
            f = new Integer[n];
            Arrays.fill(f, -1);
            for (int i = 0; i < n; i++)
                if (f[i] == -1)
                    calc(i);
            return bad ? -1 : Collections.max(Arrays.asList(f));
        }
    }

    public void run() {
        in = new Scanner(System.in);
        for (int tn = in.nextInt(); tn > 0; tn--)
            System.out.println(new Solver().solve());
    }

    public static void main(String[] args) {
        new A().run();
    }
}