import java.util.*;
import java.util.Map.Entry;
import java.io.*;

public class Solution {
	BufferedReader br;
	PrintWriter out;
	StringTokenizer stok;

	String nextToken() throws IOException {
		while (stok == null || !stok.hasMoreTokens()) {
			String s = br.readLine();
			if (s == null) {
				return null;
			}
			stok = new StringTokenizer(s);
		}
		return stok.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	char nextChar() throws IOException {
		return (char) (br.read());
	}

	String nextLine() throws IOException {
		return br.readLine();
	}

	int[] color;int m;
	int[][] e;
	void dfs(int i) {
		color[i] = 1;
		for (int j = 0; j < m; j++) {
			if (e[i][j] == 1 && color[j] == 0) {
				dfs(j);
			}
		}
	}
	void solve() throws IOException {
		int n = nextInt();
		m = nextInt();
		color = new int[m];
		e = new int[m][m];
		int[] qq = new int[m];
		int[] no = new int[n];
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int k = nextInt();
			if (k == 0) {
				ans++;
				no[i] = 1;
			}
			int[] a = new int[k];
			for (int j = 0; j < k; j++) {
				a[j] = nextInt();
				qq[a[j] - 1] = 1;
			}
			for (int j = 0; j < k; j++) {
				for (int q = j + 1; q < k; q++) {
					e[a[j]-1][a[q]-1] = 1;
					e[a[q]-1][a[j]-1] = 1;
				}
			}
		}
		int qans = 0;
		for (int i = 0; i < m; i++) {
			if (color[i] == 0 && qq[i] > 0) {
				dfs(i);
				qans++;
			}
		}/*
		for (int i = 0; i < m; i++) {
			if (qq[i] == 0) {
				ans--;
			}
		}*/
		out.println(ans + Math.max(0, qans - 1));
	}

	void run() throws IOException {
		//br = new BufferedReader(new FileReader("input.txt"));
		//out = new PrintWriter("output.txt");
		 br = new BufferedReader(new InputStreamReader(System.in));
		 out = new PrintWriter(System.out);
		solve();
		br.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		// Localea.setDefault(Locale.US);
		new Solution().run();
	}
}