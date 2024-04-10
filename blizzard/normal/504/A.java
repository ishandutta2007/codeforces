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
    class Vertex implements Comparable<Vertex>{
        int xor, degree,id;

        Vertex(int degree, int xor,int id) {
            this.degree = degree;
            this.xor = xor;
            this.id = id;
        }

        @Override
        public int compareTo(Vertex o) {
            if (degree == o.degree) {
                return id-o.id;
            }
            return (degree - o.degree);
        }
    }

    private void solve() throws IOException {
        int n = nextInt();
        Vertex[] v = new Vertex[n];
        for (int i = 0; i < n; i++) {
            v[i] = new Vertex(nextInt(), nextInt(), i);
        }
        SortedSet<Vertex> set = new TreeSet<Vertex>();
        for (int i = 0; i < n; i++) {
            set.add(v[i]);
        }
        ArrayList<Integer> list = new ArrayList<Integer>();
        while (!set.isEmpty()) {
            Vertex vv = set.first();
            //System.err.println(vv.id);
            if (vv.degree == 0) {
                set.remove(vv);
                continue;
            }
            if (vv.degree != 1) {
                //System.err.println("!");
            }
            set.remove(vv);
            int u = vv.xor;
            list.add(vv.id);
            list.add(u);
            v[vv.id].degree--;
            v[vv.id].xor ^= u;
            set.remove(v[u]);
            v[u].degree--;
            v[u].xor ^= vv.id;
            set.add(v[u]);
        }
        out.println(list.size() / 2);
        for (int i = 0; i < list.size(); i+=2) {
            out.println(list.get(i) + " " + list.get(i + 1));
        }
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
        new A().run();
    }
}