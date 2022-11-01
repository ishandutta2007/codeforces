import java.io.*;
import java.util.*;

public class D implements Runnable {

	class Cube {
		long x1, y1, x2, y2;

		public Cube(long x1, long y1, long x2, long y2) {
			this.x1 = Math.min(x1, x2);
			this.y1 = Math.min(y1, y2);
			this.x2 = Math.max(x1, x2);
			this.y2 = Math.max(y1, y2);
		}

		long side() {
			return x2 - x1;
		}

		long mass() {
			long a = side();
			return a * a * a;
		}

		Point center() {
			return new Point((x1 + x2) * .5, (y1 + y2) * .5);
		}

		boolean ok(long x, long y) {
			return x >= x1 && x <= x2 && y >= y1 && y <= y2;
		}
	}

	class Point {
		double x, y;

		public Point(double x, double y) {
			this.x = x;
			this.y = y;
		}
	}

	private void solve() throws IOException {
		int n = nextInt();
		Cube[] c = new Cube[n];
		for (int i = 0; i < n; i++) {
			c[i] = new Cube(nextInt(), nextInt(), nextInt(), nextInt());
		}

		int ans = 0;
		oo: for (int k = 1; k <= n; k++) {
			for (int i = 0; i < k; i++) {
				long x = 0, y = 0, mass = 0;
				for (int j = i + 1; j < k; j++) {
					long m = c[j].mass();
					x += (c[j].x1 + c[j].x2) * m;
					y += (c[j].y1 + c[j].y2) * m;
					mass += m;
				}
				mass *= 2;
				Cube t = new Cube(c[i].x1 * mass, c[i].y1 * mass, c[i].x2
						* mass, c[i].y2 * mass);
				if (!t.ok(x, y)) {
					break oo;
				}
			}
			ans = k;
		}
		out.println(ans);
	}

	public static void main(String[] args) {
		new Thread(new D()).start();
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