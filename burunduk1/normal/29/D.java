import com.sun.org.apache.xerces.internal.util.XMLStringBuffer;

import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * @author Sergey Kopeliovich (burunduk1@yandex-team.ru)
 */
public class D {
    private StringBuffer buf = new StringBuffer();
    private int count = 0;

    private void addNum(int x) {
        buf.append((x + 1) + " ");
        count++;
    }

    public static void main(String[] args) {
        new D().run();
    }

    private void run() {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        Graph g = new Graph(n);
        for (int i = 0; i < n - 1; i++) {
            g.addEdge(in.nextInt() - 1, in.nextInt() - 1);
        }

        int cur = 0;
        while (in.hasNextInt()) {
            int a = in.nextInt() - 1;
            g.outPath(cur, a);
            cur = a;
        }
        g.outPath(cur, 0);
        addNum(0);
        if (count == 2 * n - 1) {
            System.out.println(buf);
        } else {
            System.out.println("-1");
        }
    }

    private class Graph {
        private final List<ArrayList<Integer>> c;
        private final int[] p;
        private final boolean[] u;

        public Graph(int n) {
            c = new ArrayList<ArrayList<Integer>>();
            for (int i = 0; i < n; i++) {
                c.add(new ArrayList<Integer>());
            }
            u = new boolean[n];
            p = new int[n];
        }

        public void addEdge( int a, int b ) {
            c.get(a).add(b);
            c.get(b).add(a);
        }

        public void outPath(int b, int a) {
            Arrays.fill(u, false);
            for (dfs(a); b != a; b = p[b]) {
                addNum(b);
            }
        }

        private void dfs(int a) {
            u[a] = true;
            for (Integer v : c.get(a)) {
                if (!u[v]) {
                    p[v] = a;
                    dfs(v);
                }
            }
        }
    }
}