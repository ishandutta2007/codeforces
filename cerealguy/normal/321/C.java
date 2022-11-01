import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Random;

public class C {

	static int n;

	static int[] to;
	static int[] next;
	static int[] prev;
	static int[] head;

	static int[] subtreeSize;

	static char[] color;

	static int findCenter(int u) {
		calcSubtreeSizes(u, -1);
		int all = subtreeSize[u];
		int p = -1;
		// System.err.println(Arrays.toString(subtreeSize));
		ok: while (true) {
			for (int e = head[u]; e >= 0; e = next[e]) {
				int v = to[e];
				if (v == p) {
					continue;
				}
				if (subtreeSize[v] * 2 >= all) {
					p = u;
					u = v;
					continue ok;
				}
			}
			break;
		}
		return u;
	}

	private static void calcSubtreeSizes(int u, int p) {
		subtreeSize[u] = 1;
		for (int e = head[u]; e >= 0; e = next[e]) {
			int v = to[e];
			if (v == p) {
				continue;
			}
			calcSubtreeSizes(v, u);
			subtreeSize[u] += subtreeSize[v];
		}
	}

	static void solveTheProblem(int u, int curColor) {
//		System.err.println("solving for "+u);
		u = findCenter(u);
		// System.err.println("center: "+u);
		color[u] = (char) ('A' + curColor);
		for (int e = head[u]; e >= 0; e = next[e]) {
			int v = to[e];
			int revE = e ^ 1;
			removeEdge(v, revE);
			solveTheProblem(v, curColor + 1);
		}
	}

	private static void removeEdge(int v, int edgeId) {
		int ne = next[edgeId];
		int pr = prev[edgeId];
		if (ne >= 0) {
			prev[ne] = pr;
		}
		if (pr >= 0) {
			next[pr] = ne;
		}
		if (edgeId == head[v]) {
			head[v] = ne;
		}
	}

	static Random rng = new Random(58);
	static void solve() throws IOException {
		n = nextInt();
//		n = 100000;
		to = new int[2 * (n - 1)];
		next = new int[2 * (n - 1)];
		prev = new int[2 * (n - 1)];
		head = new int[n];
		fill(head, -1);
		fill(prev, -1);
		for (int i = 0; i < n - 1; i++) {
//			int u = i + 1;
//			int v = rng.nextInt(u);
//			System.err.println((u+1)+" "+(v+1));
			int u = nextInt() - 1;
			int v = nextInt() - 1;
			{
				to[2 * i] = v;
				next[2 * i] = head[u];
				if (head[u] >= 0) {
					prev[head[u]] = 2 * i;
				}
				head[u] = 2 * i;
			}
			{
				to[2 * i + 1] = u;
				next[2 * i + 1] = head[v];
				if (head[v] >= 0) {
					prev[head[v]] = 2 * i + 1;
				}
				head[v] = 2 * i + 1;
			}
		}
		color = new char[n];
		subtreeSize = new int[n];
		solveTheProblem(0, 0);
		char[] output = new char[2 * n - 1];
		fill(output, ' ');
		for (int i = 0; i < n; i++) {
			output[2 * i] = color[i];
		}
		out.println(output);
	}

	static BufferedReader br;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("c.in");
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solve();
		out.close();
	}

	public static int nextInt() throws IOException {
		int c = br.read();
		while ((c < '0' || c > '9') && c != '-')
			c = br.read();
		boolean negative = false;
		if (c == '-') {
			negative = true;
			c = br.read();
		}
		int m = 0;
		while (c >= '0' && c <= '9') {
			m = m * 10 + c - '0';
			c = br.read();
		}
		return negative ? -m : m;
	}

}