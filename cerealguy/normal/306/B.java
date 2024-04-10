import java.io.*;
import java.util.*;

public class B {
    static void sort1(Query[] array) {
        Arrays.sort(array);
    }
    static void sort2(Query[] array) {
        int n = array.length;
        Object[] objects = new Object[n];
        for (int i = 0; i < n; i++) {
            objects[i] = array[i];
        }
        Arrays.sort(objects);
        for (int i = 0; i < n; i++) {
            array[i] = (Query) objects[i];
        }
    }

    static void solve() throws IOException {

        nextToken();
        int queriesCount = nextInt();

        Query[] queries = new Query[queriesCount];

        for (int i = 0; i < queriesCount; i++) {
            int pos = nextInt() - 1;
            int len = nextInt();
            Query q = new Query(pos, len, i);
            queries[i] = q;
        }

        sort2(queries);

        int haveRight = -1;
        Query best = null;
        boolean[] take = new boolean[queriesCount];

        for (Query q : queries) {
            if (q.left > haveRight) {
                if (best != null) {
                    if (q.left <= best.right) {
                        take[best.id] = true;
                        haveRight = best.right;
                    } else {
                        take[best.id] = true;
                        take[q.id] = true;
                        haveRight = q.right;
                        best = null;
                    }
                } else {
                    take[q.id] = true;
                    haveRight = q.right;
                }
            }
            if (q.right > haveRight && (best == null || best.right < q.right)) {
                best = q;
            }
        }
        if (best != null) {
            take[best.id] = true;
        }

        int dontTakeCount = 0;
        for (int i = 0; i < queriesCount; i++) {
            if (!take[i]) {
                ++dontTakeCount;
            }
        }
        out.println(dontTakeCount);
        boolean first = true;
        for (int i = 0; i < queriesCount; i++) {
            if (!take[i]) {
                if (!first) {
                    out.print(' ');
                } else {
                    first = false;
                }
                out.print(i + 1);
            }
        }
    }

    static class Query implements Comparable<Query>{
        int left;
        int right;
        int id;

        public Query(int pos, int len, int id) {
            this.left = pos;
            this.right = len + pos;
            this.id = id;
        }

        @Override
        public int compareTo(Query o) {
            int cmp = left - o.left;
            if (cmp != 0) {
                return cmp;
            }
            return o.right - right;
        }
    }

    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;
        File file = new File("b.in");
        if (file.exists() && file.canRead()) {
            input = new FileInputStream(file);
        }
        br = new BufferedReader(new InputStreamReader(input));
        out = new PrintWriter(output);
        solve();
        out.close();
    }

    static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }
}