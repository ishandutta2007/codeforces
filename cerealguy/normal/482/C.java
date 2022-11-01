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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        n = in.nextInt();
        int[] inInput = new int[256];
        input = new char[n][];
        for (int i = 0; i < n; i++) {
            char[] c = in.nextToken().toCharArray();
            c = Arrays.copyOf(c, c.length + 1);
            c[c.length - 1] = (char) i;
            input[i] = c;
            for (int j = 0; j < c.length - 1; j++) {
                inInput[c[j]] = 1;
            }
        }
        for (int i = 1; i < inInput.length; i++) {
            inInput[i] += inInput[i - 1];
        }
        for (int i = 0; i < n; i++) {
            char[] c = input[i];
            for (int j = 0; j < c.length - 1; j++) {
                c[j] = (char) (inInput[c[j]] - 1);
            }
        }
        MAX = inInput[inInput.length - 1];
        cnt = new int[MAX];
        bits = input[0].length - 1;
        inputPerLevel = new char[bits + 1][n][];
        System.arraycopy(input, 0, inputPerLevel[0], 0, n);
        factorial = new double[bits + 1];
        factorial[0] = 1;
        for (int i = 1; i <= bits; i++) {
            factorial[i] = factorial[i - 1] * i;
        }
        equivalenceClassPerLevel = new int[bits + 1][n];
        whatWeAreCalculatingPerInput = new double[n];
        goAll(0, 0);
        double worst = 0;
        for (double d : whatWeAreCalculatingPerInput) {
            worst += d;
        }
        double answer = worst / factorial[bits] / n + (n==1?0:1);
        out.println(answer);
    }

    static int bits;
    static int n;
    static char[][] input;
    static char[][][] inputPerLevel;

    static double[] whatWeAreCalculatingPerInput;
    static double[] factorial;

    static int[][] equivalenceClassPerLevel;
    static int MAX;

    static void goAll(int curBit, int mask) {
        if (curBit == bits) {
            return;
        }
        int k = Integer.bitCount(mask) + 1;
        double add = factorial[k] * factorial[bits - k];
        for (int takeBit = curBit; takeBit < bits; takeBit++) {
            goodSort(inputPerLevel[curBit], equivalenceClassPerLevel[curBit], inputPerLevel[takeBit + 1], equivalenceClassPerLevel[takeBit + 1], takeBit, add);
            goAll(takeBit + 1, mask | (1 << takeBit));
        }
    }

    static int[] cnt;

    private static void goodSort(char[][] in, int[] equivIn, char[][] out, int[] equivOut, int sortBy, double add) {
        Arrays.fill(cnt, 0);
        for (int i = 0; i < n; i++) {
            ++cnt[in[i][sortBy]];
        }
        for (int i = 1; i < cnt.length; i++) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = n - 1; i >= 0; --i) {
            int what = in[i][sortBy];
            out[--cnt[what]] = in[i];
        }
        int lastEquiv = -1;
        int lastVal = -1;
        int equivId = -1;
        int last = -1;
        for (int i = 0; i < n; i++) {
            int who = out[i][bits];
            int curEquiv = equivIn[who];
            int curVal = out[i][sortBy];
            if (curVal != lastVal || curEquiv != lastEquiv) {
                ++equivId;
                lastVal = curVal;
                lastEquiv = curEquiv;
                if (i - last > 1) {
                    for (int j = last; j < i; j++) {
                        int guy = out[j][bits];
                        whatWeAreCalculatingPerInput[guy] += add;
                    }
                }
                last = i;
            }
            equivOut[who] = equivId;
        }
        if (n - last > 1) {
            for (int j = last; j < n; j++) {
                int guy = out[j][bits];
                whatWeAreCalculatingPerInput[guy] += add;
            }
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