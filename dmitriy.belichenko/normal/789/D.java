import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	int[] p;
	int[] rank;
	
	int get(int v) {
		return p[v] == v ? v : (p[v] = get(p[v]));
	}
	
	void unite(int a, int b) {
		a = get(a);
		b = get(b);
		if (a == b) {
			return;
		}
		if (rank[a] < rank[b]) {
			int tmp = a;
			a = b;
			b = tmp;
		}
		
		p[b] = a;
		if (rank[a] == rank[b]) {
			rank[a]++;
		}
	}

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();

		p = new int[n];
		rank = new int[n];
		
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}
		
		int loops = 0;
		
		int[] deg = new int[n];
		boolean[] hasLoop = new boolean[n];
		
		for (int i = 0; i < m; i++) {
			int v = nextInt() - 1;
			int u = nextInt() - 1;
			
			if (v == u) {
				loops++;
				hasLoop[v] = true;
			} else {
				deg[v]++;
				deg[u]++;
				
				unite(v, u);
			}
		}
		
		int edgesComp = -1;
		for (int i = 0; i < n; i++) {
			int v = get(i);
			if (!hasLoop[v] && deg[v] == 0) {
				continue;
			}
			if (edgesComp == -1) {
				edgesComp = v;
			} else if (edgesComp != v) {
				out.println(0);
				return;
			}
		}
		
		long ret = c2(m) - c2(m - loops); // loop + anything
		
		for (int i = 0; i < n; i++) {
			ret += c2(deg[i]);
		}
		
		out.println(ret);
		
	}
	
	long c2(long x) {
		return x * (x - 1) / 2;
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
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
}