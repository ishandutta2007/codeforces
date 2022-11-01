import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
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
        String[] contacts = new String[n];
        for (int i = 0; i < n; i++) {
            contacts[i] = in.nextToken();
        }
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        int[] gotMessages = new int[n];
        boolean[] party = new boolean[n];
        all:
        while (true) {
            for (int i = 0; i < n; i++) {
                if (a[i] == gotMessages[i]) {
                    party[i] = true;
                    for (int j = 0; j < n; j++) {
                        if (contacts[i].charAt(j) == '1') {
                            ++gotMessages[j];
                        }
                    }
                    continue all;
                }
            }
            break;
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (party[i]) {
                ++count;
            }
        }
        out.println(count);
        for (int i = 0; i < n; i++) {
            if (party[i]) {
                out.print((i+1)+" ");
            }
        }
        out.println();
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