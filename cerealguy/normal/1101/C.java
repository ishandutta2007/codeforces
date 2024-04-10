import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        C solver = new C();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class C {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            C.Segment[] segments = new C.Segment[n];
            for (int i = 0; i < n; i++) {
                segments[i] = new C.Segment(in.nextInt(), in.nextInt());
            }
            C.Segment[] sorted = segments.clone();
            Arrays.sort(sorted, new Comparator<C.Segment>() {

                public int compare(C.Segment o1, C.Segment o2) {
                    return o1.l - o2.l;
                }
            });

            int maxR = 0;
            int posSplit = 0;
            for (C.Segment s : sorted) {
                if (maxR > 0 && s.l > maxR) {
                    posSplit = s.l;
                    break;
                }
                maxR = Math.max(maxR, s.r);
            }
            if (posSplit == 0) {
                out.println(-1);
            } else {
                for (int i = 0; i < n; i++) {
                    C.Segment s = segments[i];
                    if (i > 0) {
                        out.print(' ');
                    }
                    out.print(s.l < posSplit ? '1' : '2');
                }
                out.println();
            }
        }

        static class Segment {
            int l;
            int r;

            public Segment(int l, int r) {
                this.l = l;
                this.r = r;
            }

        }

    }

    static class InputReader {
        public BufferedReader br;
        StringTokenizer st;

        public InputReader(InputStream stream) {
            br = new BufferedReader(new InputStreamReader(stream));
        }

        public String next() {
            return nextToken();
        }

        public String nextToken() {
            while (st == null || !st.hasMoreTokens()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                if (line == null) {
                    return null;
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

    }
}