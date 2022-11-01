import java.io.*;
import java.util.*;

public class D {

	static void solve() throws IOException {
//		int[] grundy = new int[30];
//		for (int i = 1; i < 30; i++) {
//			grundy[i] = getGrundy(i);
//			System.err.println(i + ": " + grundy[i]);
//		}
//		System.err.println(Arrays.toString(grundy));

		int n = nextInt();
		boolean winning = winning(n);
		out.println(winning ? "Vasya" : "Petya");
	}

	static final int[] GRUNDY = { 0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5,
			9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12 };

	private static boolean winning(int n) {
		Set<Integer> pows = new HashSet<>();
		int grundy = 0;
		int i;
		for (i = 2; i * i <= n; i++) {
			if (pows.contains(i)) {
				continue;
			}
			long good = i;
			int cnt = 0;
			while (good <= n) {
				pows.add((int) good);
				++cnt;
				good *= i;
			}
			grundy ^= GRUNDY[cnt];
		}
		grundy ^= (n - pows.size()) & 1;
		return grundy != 0;
	}

	static int getGrundy(int count) {
		byte[] g = new byte[1 << count];
		g[0] = 0;
		int[] can = new int[count + 5];
		for (int mask = 1; mask < g.length; mask += 2) {
			can[0] = mask;
			for (int move = 2; move <= count; move++) {
				if ((mask & (1 << move - 1)) == 0) {
					continue;
				}
				int ok = (1 << move - 1);
				int mm = ok;
				for (int i = move; i <= count; i += move) {
					mm |= ok;
					ok <<= move;
				}
				int toMask = mask & ~mm;
				can[g[toMask]] = mask;
			}
			int ok = 0;
			while (can[ok] == mask) {
				++ok;
			}
			g[mask] = (byte) ok;
		}
		return g[g.length - 1];
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("d.in");
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solve();
		out.close();
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
}