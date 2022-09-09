import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class G1 {

	static int dsuGet(int dsu[], int i) {
		return dsu[i] == i ? i : (dsu[i] = dsuGet(dsu, dsu[i]));
	}

	static boolean dsuMerge(int dsu[], int i, int j) {
		i = dsuGet(dsu, i);
		j = dsuGet(dsu, j);
		if (i == j) {
			return false;
		}
		dsu[j] = i;
		return true;
	}

	static void solve() throws Exception {
		int n = scanInt();
		scanInt();
		int blockPos[] = new int[n + 1];
		int blockVal[] = new int[n];
		int nBlocks = 0;
		int cPos[] = new int[200001], cParent[] = new int[200001], cnt[] = new int[200001];
		fill(cPos, -1);
		fill(cParent, -1);
		for (int i = 0; i < n; i++) {
			int cur = scanInt();
			++cnt[cur];
			if (cPos[cur] < 0) {
				cPos[cur] = i;
				cParent[cur] = ~nBlocks;
				blockVal[nBlocks] = cur;
				++nBlocks;
			} else {
				int p = cPos[cur];
				while (blockPos[nBlocks - 1] > p) {
					--nBlocks;
					cParent[blockVal[nBlocks]] = blockVal[nBlocks - 1];
				}
			}
			blockPos[nBlocks] = i + 1;
		}
		int dsu[] = new int[cPos.length];
		for (int i = 0; i < dsu.length; i++) {
			dsu[i] = i;
		}
		for (int i = 0; i < cPos.length; i++) {
			if (cParent[i] >= 0) {
				dsuMerge(dsu, i, cParent[i]);
			}
		}
		int dsuMax[] = new int[cPos.length];
		for (int i = 0; i < cPos.length; i++) {
			int j = dsuGet(dsu, i);
			dsuMax[j] = max(dsuMax[j], cnt[i]);
		}
		int ans = n;
		for (int i = 0; i < nBlocks; i++) {
			ans -= dsuMax[dsuGet(dsu, blockVal[i])];
		}
		out.print(ans);
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