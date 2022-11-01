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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt(), initialX = in.nextInt();
        Candy[] c = new Candy[n];
        for (int i = 0; i < n; i++) {
            c[i] = new Candy(in.nextInt(), in.nextInt(), in.nextInt());
        }
        boolean[] ate = new boolean[n];
        int result = 0;
        for (int startType = 0; startType < 2; startType++) {
            Arrays.fill(ate, false);
            int x = initialX;
            int type = startType;
            int candyCount = 0;
            while (true) {
                int best = -1;
                for (int i = 0; i < n; i++) {
                    if (c[i].type != type || ate[i] || c[i].height > x) {
                        continue;
                    }
                    if (best == -1 || c[i].mass > c[best].mass) {
                        best = i;
                    }
                }
                if (best < 0) {
                    break;
                }
                x += c[best].mass;
                ate[best] = true;
                type ^= 1;
                ++candyCount;
            }
            result = Math.max(result, candyCount);
        }
        out.println(result);
    }

    static class Candy {
        int type;
        int height;
        int mass;

        Candy(int type, int height, int mass) {
            this.type = type;
            this.height = height;
            this.mass = mass;
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