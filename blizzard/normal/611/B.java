import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
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


    private void solve() throws IOException {
        long a = nextLong();
        long b = nextLong();
        ArrayList<Long> all = new ArrayList<Long>();
        long sum = 1;
        for (int i = 1; i < 63; i++) {
            long t = (1L << i);
            sum += t;
            for (int j = i - 1; j >= 0; j--) {
                long tmp = sum - (1L << j);
                all.add(tmp);
            }
        }
        Collections.sort(all);
        int i = 0;
        for (i = 0; all.get(i) < a; i++) {
        ;
        }
        int j = i;
        for (j = i; all.get(j) <= b; j++) {
            ;
        }
        out.println(j - i);
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
        new B().run();
    }
}