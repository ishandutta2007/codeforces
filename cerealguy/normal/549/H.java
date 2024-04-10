import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.math.BigInteger;
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
		TaskH solver = new TaskH();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskH {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        long a = in.nextInt();
        long b = in.nextInt();
        long c = in.nextInt();
        long d = in.nextInt();
        double result = Double.POSITIVE_INFINITY;
        for (int signsMask = 0; signsMask < 16; signsMask++) {
            int signA = sign(signsMask, 0);
            int signB = sign(signsMask, 1);
            int signC = sign(signsMask, 2);
            int signD = sign(signsMask, 3);
            long k2 = signA * signD - signB * signC;
            long k1 = -a * signD - d * signA + b * signC + c * signB;
            long k0 = a * d - b * c;
            double[] roots = roots(k2, k1, k0);
            for (double root : roots) {
                result = Math.min(result, Math.abs(root));
            }
        }
        out.println(result);
    }

    private double[] roots(long k2, long k1, long k0) {
        if (k2 == 0) {
            if (k1 == 0) {
                return k0 == 0 ? new double[]{0} : new double[]{};
            } else {
                return new double[]{(double) k0 / k1};
            }
        }
        BigInteger d = BigInteger.valueOf(k1).multiply(BigInteger.valueOf(k1)).subtract(BigInteger.valueOf(4 * k0).multiply(BigInteger.valueOf(k2)));
        if (d.signum() < 0) {
            return new double[]{};
        }
        double sqrt = Math.sqrt(d.doubleValue());
        return new double[]{(-k1 - sqrt) / (2 * k2), (-k1 + sqrt) / (2 * k2)};
    }

    static int sign(int signsMask, int pos) {
        return (signsMask & (1 << pos)) != 0 ? -1 : 1;
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