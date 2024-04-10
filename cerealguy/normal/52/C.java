import java.io.*;
import java.util.*;

import static java.lang.Integer.parseInt;

public class C {

    private static void solve() throws IOException {
        int n = parseInt(br.readLine().trim());
        long[] a = new long[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = parseInt(st.nextToken());
        }
        SegmentTreeMin tree = new SegmentTreeMin(a);

        int q = parseInt(br.readLine().trim());
        int[] buf = new int[3];
        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int cnt = 0;
            while (st.hasMoreTokens()) {
                buf[cnt++] = parseInt(st.nextToken());
            }
            int l = buf[0], r = buf[1];
            r = (r + 1) % n;
            if (cnt == 3) {
                tree.add(l, r, buf[2]);
            } else {
                System.out.println(tree.get(l, r));
            }
        }
    }

    public static class SegmentTreeMin {
        final static long INF = 1L << 62;
        int c, n;
        long[] min;
        long[] add;

        SegmentTreeMin(int n) {
            this.n = n;
            c = Integer.highestOneBit((n << 1) - 1);
            min = new long[c << 1];
            add = new long[c << 1];
            Arrays.fill(min, INF);
            min[0] = 0;
        }

        SegmentTreeMin(long[] x) {
            this(x.length);
            System.arraycopy(x, 0, min, c, n);
            for (int i = c - 1; i > 0; i--) {
                min[i] = Math.min(min[2 * i], min[2 * i + 1]);
            }
        }

        void add(int l, int r, long val) {
            if (r <= l) {
                if (r != 0)
                    add1(0, r, 1, 0, c, val);
                add1(l, n, 1, 0, c, val);
            } else
                add1(l, r, 1, 0, c, val);
        }

        void add1(int l, int r, int i, int from, int to, long val) {
            if (from >= l && to <= r) {
                add[i] += val;
                min[i] += val;
            } else {
                int m = (from + to) / 2;
                if (l < m)
                    add1(l, Math.min(r, m), 2 * i, from, m, val);
                if (r > m)
                    add1(Math.max(l, m), r, 2 * i + 1, m, to, val);
                min[i] = Math.min(min[2 * i], min[2 * i + 1]) + add[i];
            }
        }

        long get(int l, int r) {
            long ret;
            if (r <= l) {
                long a = get1(0, r, 1, 0, c);
                long b = get1(l, n, 1, 0, c);
                ret = Math.min(a, b);
            } else
                ret = get1(l, r, 1, 0, c);
            return ret;
        }

        long get1(int l, int r, int i, int from, int to) {
            if (from >= l && to <= r) {
                return min[i];
            } else {
                int m = (from + to) / 2;
                long a = l < m ? get1(l, Math.min(r, m), 2 * i, from, m) : INF;
                long b = r > m ? get1(Math.max(l, m), r, 2 * i + 1, m, to) : INF;
                return Math.min(a, b) + add[i];
            }
        }
    }

    static BufferedReader br;

    public static void main(String[] args) {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            solve();
            System.out.close();
        } catch (Throwable e) {
            e.printStackTrace();
            System.exit(239);
        }
    }
}