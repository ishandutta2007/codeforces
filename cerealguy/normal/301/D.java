import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class D {

    static void solve() throws IOException {
        int n = nextInt();
        int queriesCount = nextInt();
        int[] p = new int[n];
        int[] where = new int[n + 1];
        for (int i = 0; i < n; i++) {
            p[i] = nextInt();
            where[p[i]] = i;
        }

        int[] divHead = new int[n + 1];
        int[] divNext = new int[n * 20];
        int[] divValue = new int[n * 20];
        fill(divHead, -1);
        int count = 0;

        for (int val = 1; val <= n; val++) {
            for (int i = 2 * val; i <= n; i += val) {
                if (count == divNext.length) {
                    divNext = Arrays.copyOf(divNext, 2 * count);
                    divValue = Arrays.copyOf(divValue, 2 * count);
                }
                divValue[count] = val;
                divNext[count] = divHead[i];
                divHead[i] = count++;
            }
        }

        Query[] queriesList = new Query[queriesCount];
        for (int i = 0; i < queriesCount; i++) {
            queriesList[i] = new Query(nextInt() - 1, nextInt(), i);
        }

        Fenwick fenwick = new Fenwick(n + 1);
        
        for (int it = 0; it < n; it++) {
            int val = p[it];
            int ok = 0;
            for (int i = 2 * val; i <= n; i += val) {
                int pos = where[i];
                if (pos < it) {
                    ++ok;
                }
            }
            for (int i = divHead[val]; i >= 0; i = divNext[i]) {
                int pos = where[divValue[i]];
                if (pos < it) {
                    ++ok;
                }
            }
            fenwick.add(it, ok);
        }

        int[] queryAnswer = new int[queriesCount];
        Arrays.sort(queriesList);

        int queryPointer = 0;
        for (int left = 0; left < n; left++) {
            while (queryPointer < queriesCount && queriesList[queryPointer].left == left) {
                Query query = queriesList[queryPointer];
                queryAnswer[query.id] = fenwick.getSum(query.right - 1)
                        + query.right - query.left;
                ++queryPointer;
            }
            int val = p[left];
            for (int i = 2 * val; i <= n; i += val) {
                int pos = where[i];
                if (pos > left) {
                    fenwick.add(pos, -1);
                }
            }
            for (int i = divHead[val]; i >= 0; i = divNext[i]) {
                int pos = where[divValue[i]];
                if (pos > left) {
                    fenwick.add(pos, -1);
                }
            }
        }

        for (int i = 0; i < queriesCount; i++) {
            out.println(queryAnswer[i]);
        }
    }

    static class Query implements Comparable<Query> {
        int left, right;
        int id;

        public Query(int left, int right, int id) {
            this.left = left;
            this.right = right;
            this.id = id;
        }

        @Override
        public int compareTo(Query o) {
            return left - o.left;
        }
    }

    static class Fenwick {
        private final int[] s;

        public Fenwick(int n) {
            s = new int[n];
        }

        public int getSum(int i) {
            int res = 0;
            for (; i >= 0; i = (i & i + 1) - 1) {
                res += s[i];
            }
            return res;
        }

        public void add(int i, int val) {
            for (; i < s.length; i |= i + 1) {
                s[i] += val;
            }
        }

        public int getValue(int i) {
            int stop = (i & i + 1) - 1;
            int res = s[i];
            for (--i; i != stop; i = (i & i + 1) - 1) {
                res -= s[i];
            }
            return res;
        }

        public int getSum(int l, int r) {
            int res = 0;
            for (--r; r >= l; r = (r & r + 1) - 1) {
                res += s[r];
            }
            for (--l; l != r; l = (l & l + 1) - 1) {
                res -= s[l];
            }
            return res;
        }
    }

    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;
        File file = new File("d.in");
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