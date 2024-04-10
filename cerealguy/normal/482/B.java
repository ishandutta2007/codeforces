import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        Segment[] segments = new Segment[m];
        for (int i = 0; i < m; i++) {
            segments[i] = new Segment(in.nextInt() - 1, in.nextInt(), in.nextInt());
        }
        SegmentTreeOr tree = new SegmentTreeOr(n);
        for (Segment s : segments) {
            tree.orOnSegment(s.left, s.right, s.value);
        }
        int[] values = new int[n];
        for (int i = 0; i < n; i++) {
            values[i] = tree.get(i);
        }
        boolean ok = check(values, segments);
        if (!ok) {
            out.println("NO");
        } else {
            out.println("YES");
            for (int i = 0; i < n; i++) {
                out.print(values[i]+" ");
            }
            out.println();
        }
    }

    private boolean check(int[] values, Segment[] segments) {
        SegmentTreeAnd tree = new SegmentTreeAnd(values);
        for (Segment s: segments) {
            if (tree.getAnd(s.left, s.right) != s.value) {
                return false;
            }
        }
        return true;
    }

    static class Segment {
        final int left, right, value;

        Segment(int left, int right, int value) {
            this.left = left;
            this.right = right;
            this.value = value;
        }
    }

    static class SegmentTreeOr {
        private int[] or;
        private int n;

        public SegmentTreeOr(int n) {
            this.n = Integer.highestOneBit(n) << 1;
            or = new int[2 * this.n];
        }

        public int get(int x) {
            x += n;
            int result = or[x];
            while (x > 1) {
                x >>= 1;
                result |= or[x];
            }
            return result;
        }

        public void orOnSegment(int l, int r, int value) {
            r--;
            l += n;
            r += n;
            while (l <= r) {
                if ((l & 1) == 1) {
                    or[l++] |= value;
                }
                if ((r & 1) == 0) {
                    or[r--] |= value;
                }
                l >>= 1;
                r >>= 1;
            }
        }
    }

    class SegmentTreeAnd {
        private int[] and;
        private int n;

        public SegmentTreeAnd(int n) {
            this.n = Integer.highestOneBit(n) << 1;
            and = new int[2 * this.n];
            Arrays.fill(and, -1);
        }

        public SegmentTreeAnd(int[] array) {
            this(array.length);
            System.arraycopy(array, 0, and, n, array.length);
            for (int x = n - 1; x >= 0; --x) {
                and[x] = and[x << 1] & and[(x << 1) | 1];
            }
        }

        public int getAnd(int l, int r) {
            r--;
            l += n;
            r += n;
            int ret = -1;
            while (l <= r) {
                if ((l & 1) == 1) {
                    ret &= and[l++];
                }
                if ((r & 1) == 0) {
                    ret &= and[r--];
                }
                l >>= 1;
                r >>= 1;
            }
            return ret;
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