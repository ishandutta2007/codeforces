import java.util.Map;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Set;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
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
		TaskG solver = new TaskG();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskG {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        int[] start = new int[n];
        for (int i = 0; i < n; i++) {
            start[i] = in.nextInt();
        }

        Map<Permutation, Integer> ways = new HashMap<>();
        ways.put(new Permutation(start), 1);
        Map<Permutation, Integer> next = new HashMap<>();

        for (int it = 0; it < k; it++) {
            for (Map.Entry<Permutation, Integer> entry : ways.entrySet()) {
                Permutation p = entry.getKey();
                int cnt = entry.getValue();
                for (int from = 0; from < n; from++) {
                    for (int to = from; to < n; to++) {
                        Permutation ok = p.apply(from, to);
                        Integer c = next.get(ok);
                        if (c == null) {
                            c = 0;
                        }
                        next.put(ok, cnt + c);
                    }
                }
            }
            Map<Permutation, Integer> tmp = ways;
            ways = next;
            next = tmp;
            next.clear();
        }

        long answer = 0;
        int all = 0;

        for (Map.Entry<Permutation, Integer> entry : ways.entrySet()) {
            Permutation p = entry.getKey();
            answer += (long)p.inversions() * (long) entry.getValue();
            all += entry.getValue();
        }

        out.println((double) answer / all);
    }

    static class Permutation {
        int[] p;

        Permutation(int[] p) {
            this.p = p;
        }

        Permutation apply(int from, int to) {
            int[] pp = p.clone();
            for (int i = from, j = to; i < j; ++i, --j) {
                int t = pp[i];
                pp[i] = pp[j];
                pp[j] = t;
            }
            return new Permutation(pp);
        }

        int inversions() {
            int cnt = 0;
            for (int i = 0; i < p.length; i++) {
                for (int j = i + 1; j < p.length; j++) {
                    if (p[i] > p[j]) {
                        ++cnt;
                    }
                }
            }
            return cnt;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Permutation that = (Permutation) o;

            if (!Arrays.equals(p, that.p)) return false;

            return true;
        }

        public int hashCode() {
            return Arrays.hashCode(p);
        }
    }
}

class InputReader {
    BufferedReader br;
    StringTokenizer st;

    public InputReader(InputStream stream) {
        br = new BufferedReader(new InputStreamReader(stream));
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