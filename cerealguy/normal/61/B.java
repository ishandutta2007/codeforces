import java.io.*;
import java.util.*;

public class B {

    private void solve() throws IOException {
        String s1 = nextToken(), s2 = nextToken(), s3 = nextToken();
        s1 = s1.replaceAll("[-;_]", "").toLowerCase();
        s2 = s2.replaceAll("[-;_]", "").toLowerCase();
        s3 = s3.replaceAll("[-;_]", "").toLowerCase();
        String[] s = new String[] { s1 + s2 + s3, s1 + s3 + s2, s2 + s1 + s3,
                s2 + s3 + s1, s3 + s1 + s2, s3 + s2 + s1 };
        HashSet<String> hs = new HashSet<String>();
        for (String str : s)
            hs.add(str);
        int n = nextInt();
        for (int i = 0; i < n; i++) {
            String str = nextToken().replaceAll("[-;_]", "").toLowerCase();
            if (hs.contains(str)) {
                out.println("ACC");
            } else {
                out.println("WA");
            }
        }
    }

    public static void main(String[] args) {
        new B().run();
    }

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

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
                line = "0";
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }
}