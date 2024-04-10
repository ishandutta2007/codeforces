import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Random;
import java.util.StringTokenizer;

public class G {

	static void solve() throws Exception {
		int my[] = new int[20];
		boolean win[] = new boolean[20];
		Random rng = new Random(42);
		for (int i = 0; i < 10; i++) {
			my[i] = rng.nextInt(3);
			out.println("RPS".charAt(my[i]));
			out.flush();
			String s = scanString();
			if (s == null) {
				return;
			}
			switch (s) {
			case "player":
				win[i] = true;
				break;
			case "ai":
				win[i] = false;
				break;
			default:
				return;
			}
		}
		int period[] = null, shift = -1;
		p: for (int p = 1; p <= 4; p++) {
			int cPeriod[] = new int[p];
			for (int i = 0; i < p; i++) {
				boolean can[] = new boolean[3];
				fill(can, true);
				for (int j = i; j < 10; j += p) {
					int t = (my[j] + 2) % 3;
					int t2 = (t + 1) % 3, t3 = (t + 2) % 3;
					if (win[j]) {
						can[t2] = can[t3] = false;
					} else {
						can[t] = false;
					}
				}
				if (!can[0] && !can[1] && !can[2]) {
					continue p;
				}
				cPeriod[i] = can[0] ? 0 : can[1] ? 1 : 2;
			}
			period = cPeriod;
			break;
		}
		if (period == null) {
			i: for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 9; j++) {
					int shifted = (my[j] + i) % 3;
					if ((shifted == (my[j + 1] + 2) % 3) != win[j + 1]) {
						continue i;
					}
				}
				shift = i;
				break;
			}
		}
//		System.err.println(Arrays.toString(period) + " " + shift);
		for (int i = 10; i < 20; i++) {
			if (period != null) {
				my[i] = (period[i % period.length] + 1) % 3;
			} else if (shift >= 0) {
				my[i] = (my[i - 1] + shift + 1) % 3;
			} else {
				my[i] = rng.nextInt(3);
			}
			out.println("RPS".charAt(my[i]));
			out.flush();
			String s = scanString();
			if (s == null) {
				return;
			}
			switch (s) {
			case "player":
				win[i] = true;
				break;
			case "ai":
				win[i] = false;
				break;
			default:
				return;
			}
		}
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			String l = in.readLine();
			if (l == null) {
				return null;
			}
			tok = new StringTokenizer(l);
		}
		return tok.nextToken();
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}