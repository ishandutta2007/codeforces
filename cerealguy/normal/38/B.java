import java.io.*;
import java.util.*;

public class b implements Runnable {
	
	int[] dx = {1, 1, -1, -1, 2, 2, -2, -2, 0};
	int[] dy = {2, -2, 2, -2, 1, -1, 1, -1, 0};
	
	static class Pair {
		int x, y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
		
	}
	
	boolean beats(Pair k, Pair p) {
		for (int i = 0; i < dx.length; i++) {
			int x = k.x + dx[i], y = k.y + dy[i];
			if (x == p.x && y == p.y) return true;
		}
		return false;
	}
	
	private void solve() throws IOException {
		Pair r = nextPair(), k = nextPair();
		int ans = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (i == r.x || j == r.y) continue;
				Pair p = new Pair(i, j);
				if (beats(p, k) || beats(p, r) || beats(k, p)) continue;
				ans++;
			}
		}
		out.println(ans);
	}
	
	Pair nextPair() {
		String s = nextToken();
		int x = s.charAt(0) - 'a';
		int y = s.charAt(1) - '1';
		return new Pair(x, y);
	}
	

	public static void main(String[] args) {
		new Thread(new b()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}
}