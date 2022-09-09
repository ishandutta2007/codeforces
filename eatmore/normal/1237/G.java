import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class G {

	interface IntComparator {
		public int compare(int o1, int o2);
	}

	static void sort(int a[], int n, IntComparator cmp) {
		if (n == 0) {
			return;
		}
		for (int i = 1; i < n; i++) {
			int j = i;
			int ca = a[i];
			do {
				int nj = (j - 1) >> 1;
				int na = a[nj];
				if (cmp.compare(na, ca) >= 0) {
					break;
				}
				a[j] = na;
				j = nj;
			} while (j != 0);
			a[j] = ca;
		}
		int ca = a[0];
		for (int i = n - 1; i > 0; i--) {
			int j = 0;
			while ((j << 1) + 2 + Integer.MIN_VALUE < i + Integer.MIN_VALUE) {
				j <<= 1;
				j += (cmp.compare(a[j + 1], a[j + 2]) < 0) ? 2 : 1;
			}
			if ((j << 1) + 2 == i) {
				j = (j << 1) + 1;
			}
			int na = a[i];
			a[i] = ca;
			ca = na;
			while (j != 0 && cmp.compare(a[j], ca) < 0) {
				j = (j - 1) >> 1;
			}
			while (j != 0) {
				na = a[j];
				a[j] = ca;
				ca = na;
				j = (j - 1) >> 1;
			}
		}
		a[0] = ca;
	}

	static int n, k, a[], sum, move[], moveOffset, defer[], deferCnt, derefFirst[];

	static void doMove(int pos) {
		if (a[pos] < (move[(pos + 1) % n] - moveOffset) || a[(pos + k - 1) % n] < -(move[(pos + k - 1) % n] - moveOffset)) {
			if (deferCnt == 0) {
				derefFirst = new int[k - 1];
				for (int i = 0; i < k - 1; i++) {
					derefFirst[i] = move[(pos + i + 1) % n] - moveOffset;
					move[(pos + i + 1) % n] = moveOffset;
				}
			}
			defer[deferCnt++] = pos;
			return;
		}
		for (int i = 0; i < k - 1; i++) {
			int m = move[(pos + i + 1) % n] - moveOffset;
			a[(pos + i) % n] -= m;
			a[(pos + i + 1) % n] += m;
			move[(pos + i + 1) % n] = moveOffset;
		}
		out.print(pos);
		for (int i = 0; i < k; i++) {
			out.print(" " + a[(pos + i) % n]);
		}
		out.println();
		if (deferCnt > 0) {
			if (--deferCnt == 0) {
				pos = defer[0];
				for (int i = 0; i < k - 1; i++) {
					int m = derefFirst[i];
					a[(pos + i) % n] -= m;
					a[(pos + i + 1) % n] += m;
				}
				out.print(pos);
				for (int i = 0; i < k; i++) {
					out.print(" " + a[(pos + i) % n]);
				}
				out.println();
			} else {
				doMove(defer[deferCnt]);
			}
		}
	}

	static void solve() throws Exception {
		n = scanInt();
		k = scanInt();
		a = new int[n];
		sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i] = scanInt();
		}
		sum /= n;
		move = new int[n];
		int idx[] = new int[n];
		for (int i = 0; i < n - 1; i++) {
			move[i + 1] = move[i] + a[i] - sum;
			idx[i] = i;
		}
		idx[n - 1] = n - 1;
		sort(idx, n, new IntComparator() {
			public int compare(int o1, int o2) {
				return move[o1] != move[o2] ? move[o1] - move[o2] : o1 - o2;
			}
		});
		int ans = (n + k - 2) / (k - 1), ansStart = -1;
		int maxChain[] = new int[n], curNext[] = new int[k - 1];
		fill(curNext, -1);
		for (int i = 0, j; i < n; i = j) {
			for (j = i + 1; j < n && move[idx[j]] == move[idx[i]]; j++) { }
			for (int ii = j - 1; ii >= i; ii--) {
				int ci = idx[ii], ni = curNext[(ci + 1) % (k - 1)];
//				System.err.println(ci + " " + ni);
				maxChain[ci] = ni < 0 ? 1 : 1 + maxChain[ni];
				int cans = (n - maxChain[ci] + k - 2) / (k - 1);
				if (cans < ans) {
					ans = cans;
					ansStart = ci;
				}
				curNext[ci % (k - 1)] = ci;
			}
			for (int ii = i; ii < j; ii++) {
				curNext[idx[ii] % (k - 1)] = -1;
			}
		}
//		System.err.println(Arrays.toString(maxChain));
		out.println(ans);
		defer = new int[n];
		deferCnt = 0;
//		System.err.println(ans + " " + ansStart + " " + sum);
		if (ansStart < 0) {
			moveOffset = 0;
			for (int i = 0; i < ans; i++) {
				doMove(i * (k - 1));
			}
		} else {
			moveOffset = move[ansStart];
//			System.err.println(Arrays.toString(move) + " " + moveOffset);
			for (int i = 0, pos = ansStart; i < ans; i++) {
				while (move[(pos + 1) % n] == moveOffset) {
					pos = (pos + 1) % n;
				}
//				System.err.println(pos);
				doMove(pos);
//				System.err.println(Arrays.toString(a));
				pos = (pos + k - 1) % n;
			}
		}
		if (deferCnt != 0) {
			throw new AssertionError();
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
			tok = new StringTokenizer(in.readLine());
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