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
		TaskG solver = new TaskG();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskG {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt() + i;
        }
        sort(a);
        for (int i = 0; i < n; i++) {
            a[i] -= i;
        }
        boolean ok = true;
        for (int i = 0; i < n - 1; i++) {
            ok &= a[i] <= a[i+1];
        }
        if (!ok) {
            out.println(":(");
        } else {
            for (int i = 0; i < n; i++) {
                out.print(a[i]+" ");
            }
            out.println();
        }
    }

    public static void sort(int[] a) {
        sort(a, 0, a.length);
    }

    public static void sort(int[] a, int from, int to) {
        int n = to - from;
        int[] temp = new int[n];
        int[] cnt = new int[1 << 16];
        for (int i = to - 1; i >= from; --i) {
            ++cnt[low(a[i])];
        }
        for (int i = 0; i < cnt.length - 1; ++i) {
            cnt[i + 1] += cnt[i];
        }
        for (int i = to - 1; i >= from; --i) {
            temp[--cnt[low(a[i])]] = a[i];
        }

        Arrays.fill(cnt, 0);
        for (int i = n - 1; i >= 0; --i) {
            ++cnt[high(temp[i])];
        }
        cnt[0] += from;
        for (int i = 0; i < cnt.length - 1; ++i) {
            cnt[i + 1] += cnt[i];
        }
        for (int i = n - 1; i >= 0; --i) {
            a[--cnt[high(temp[i])]] = temp[i];
        }
    }

    private static int high(int a) {
        return (a ^ Integer.MIN_VALUE) >>> 16;
    }

    private static int low(int a) {
        return a & 0xFFFF;
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