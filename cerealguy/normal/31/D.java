import java.io.*;
import java.util.*;

public class D implements Runnable {

	private void solve() throws IOException {
		int xx = nextInt(), yy = nextInt(), n = nextInt();
		LinkedList<Piece> pieces = new LinkedList<Piece>();
		pieces.add(new Piece(0, 0, xx, yy));
		List<Cut> cuts = new LinkedList<Cut>();
		for (int CutNumber = 0; CutNumber < n; CutNumber++) {
			cuts.add(new Cut(nextInt(), nextInt(), nextInt(), nextInt()));
		}

		ArrayList<Integer> sizes = new ArrayList<Integer>(n + 1);

		pp: while (!pieces.isEmpty()) {
			Piece p = pieces.poll();
			for (Iterator<Cut> it = cuts.iterator(); it.hasNext();) {
				Cut c = it.next();
				if (p.getsCut(c)) {
					pieces.addAll(p.cut(c));
					it.remove();
					continue pp;
				}
			}
			sizes.add(p.size());
		}
		
		assert cuts.isEmpty();

		Collections.sort(sizes);
		for (int i : sizes) {
			out.print(i + " ");
		}
	}
	
	static class Piece {
		int x1, y1;
		int x2, y2;

		public Piece(int x0, int y0, int x1, int y1) {
			this.x1 = x0;
			this.y1 = y0;
			this.x2 = x1;
			this.y2 = y1;
		}
		
		int size() {
			return (x2 - x1) * (y2 - y1);
		}

		boolean getsCut(Cut c) {
			if (c.x1 == c.x2) {
				return c.x1 > x1 && c.x1 < x2 && c.y1 == y1 && c.y2 == y2;
			} else {
				return c.x1 == x1 && c.x2 == x2 && c.y1 > y1 && c.y1 < y2;
			}
		}

		List<Piece> cut(Cut c) {
			if (!getsCut(c))
				return null;
			List<Piece> res = new ArrayList<Piece>(2);
			if (c.x1 == c.x2) {
				res.add(new Piece(x1, y1, c.x1, y2));
				res.add(new Piece(c.x1, y1, x2, y2));
			} else {
				res.add(new Piece(x1, y1, x2, c.y1));
				res.add(new Piece(x1, c.y1, x2, y2));
			}
			return res;
		}
	}

	static class Cut {
		int x1, y1;
		int x2, y2;

		public Cut(int x1, int y1, int x2, int y2) {
			this.x1 = x1;
			this.y1 = y1;
			this.x2 = x2;
			this.y2 = y2;
			if (x1 > x2) {
				int t = x1;
				x1 = x2;
				x2 = t;
			}
			if (y1 > y2) {
				int t = y1;
				y1 = y2;
				y2 = t;
			}
		}
	}

	public static void main(String[] args) {
		new Thread(new D()).start();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

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
				return "0";
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}
}