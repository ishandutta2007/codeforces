import java.io.IOException;
import java.io.InputStreamReader;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, final PrintWriter out) {
        final int n = in.nextInt();
        int c = in.nextInt();
        final int[] maxLeft = new int[n];
        int[] minRight = new int[n];
        int[] maxRight = new int[n];
        Arrays.fill(minRight, Integer.MAX_VALUE);
        Arrays.fill(maxRight, Integer.MIN_VALUE);
        Arrays.fill(maxLeft, Integer.MIN_VALUE);
        for (int i = 0; i < c; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            boolean left = "LEFT".equals(in.nextToken());
            if (a >= b) {
                out.println("IMPOSSIBLE");
                return;
            }
            if (left) {
                maxLeft[a] = Math.max(maxLeft[a], b);
            } else {
                maxRight[a] = Math.max(maxRight[a], b);
                minRight[a] = Math.min(minRight[a], b);
            }
        }

        SegmentTreeMax maL = new SegmentTreeMax(maxLeft);
        SegmentTreeMax maR = new SegmentTreeMax(maxRight);

        for (int i = n - 1; i >= 0; --i) {
            boolean test = true;
            while (maxLeft[i] > i && test) {
                int ok1 = maL.getMax(i + 1, maxLeft[i] + 1);
                int ok2 = maR.getMax(i + 1, maxLeft[i] + 1);
                int ok = Math.max(maxLeft[i], Math.max(ok1, ok2));
                maL.set(i, ok);
                test = maxLeft[i] < ok;
                maxLeft[i] = ok;
            }
            test = true;
            while (minRight[i] <= maxRight[i] && test) {
                int ok1 = maL.getMax(minRight[i], maxRight[i] + 1);
                int ok2 = maR.getMax(minRight[i], maxRight[i] + 1);
                int ok = Math.max(maxRight[i], Math.max(ok1, ok2));
                maR.set(i, ok);
                test = maxRight[i] < ok;
                maxRight[i] = ok;
            }
        }
        for (int i = 0; i < n; i++) {
            if (maxLeft[i] >= minRight[i]) {
                out.println("IMPOSSIBLE");
                return;
            }
        }
        TaskD.out = out;
        TaskD.maxLeft = maxLeft;
        Thread t = new Thread(null, new Runnable() {

            @Override
            public void run() {
                printThem(0, n);
            }
        }, "", 1 << 28);
        t.start();
        try {
            t.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    static PrintWriter out;
    static int[] maxLeft;

    private void printThem(int from, int to) {
        if (from >= to) {
            return;
        }
        if (maxLeft[from] > from) {
            printThem(from + 1, maxLeft[from] + 1);
            out.print((from + 1) + " ");
            printThem(maxLeft[from] + 1, to);
        } else {
            out.print((from + 1) + " ");
            printThem(from + 1, to);
        }
    }

    class SegmentTreeMax {
        private int[] max;
        private int n;

        public SegmentTreeMax(int n) {
            this.n = Integer.highestOneBit(n) << 1;
            max = new int[2 * this.n];
            Arrays.fill(max, Integer.MIN_VALUE);
        }

        public SegmentTreeMax(int[] array) {
            this(array.length);
            System.arraycopy(array, 0, max, n, array.length);
            for (int x = n - 1; x >= 0; --x) {
                max[x] = Math.max(max[x << 1], max[(x << 1) | 1]);
            }
        }

        public void set(int x, int y) {
            x += n;
            max[x] = y;
            while (x > 1) {
                x >>= 1;
                max[x] = Math.max(max[x << 1], max[(x << 1) | 1]);
            }
        }

        public int getMax(int l, int r) {
            r--;
            l += n;
            r += n;
            int ret = Integer.MIN_VALUE;
            while (l <= r) {
                if ((l & 1) == 1) {
                    ret = Math.max(ret, max[l++]);
                }
                if ((r & 1) == 0) {
                    ret = Math.max(ret, max[r--]);
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