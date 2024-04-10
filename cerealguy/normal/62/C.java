import java.io.*;
import java.util.*;

public class C {

	static class Point {
		int x, y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public String toString() {
			return "(" + x + "," + y + ")";
		}
	}

	static class Segment {
		public String toString() {
			return "Segment [p1=" + p1 + ", p2=" + p2 + "]";
		}

		Point p1;
		Point p2;

		public Segment(Point p1, Point p2) {
			this.p1 = p1;
			this.p2 = p2;
		}

		double abs() {
			double xx = p1.x - p2.x;
			double yy = p1.y - p2.y;
			return Math.sqrt(xx * xx + yy * yy);
		}

		boolean intersects(Segment ss) {
			long dx = p2.x - p1.x;
			long dy = p2.y - p1.y;
			long a = ss.p2.y - ss.p1.y;
			long b = ss.p1.x - ss.p2.x;
			long c = -a * ss.p1.x - b * ss.p1.y;
			long cc = -c - a * p1.x - b * p1.y;
			long dd = a * dx + b * dy;
			if (dd == 0) {
				if (cc != 0)
					return false;
				return false;
				// throw new AssertionError();
			}
			if (cc == 0)
				return true;
			if (Long.signum(cc) != Long.signum(dd)
					|| Math.abs(cc) > Math.abs(dd))
				return false;
			return true;
		}

		double intersect(Segment ss) {
			long dx = p2.x - p1.x;
			long dy = p2.y - p1.y;
			long a = ss.p2.y - ss.p1.y;
			long b = ss.p1.x - ss.p2.x;
			long c = -a * ss.p1.x - b * ss.p1.y;
			long cc = -c - a * p1.x - b * p1.y;
			long dd = a * dx + b * dy;
			if (dd == 0) {
				if (cc != 0)
					return Double.NaN;
				return Double.NaN;
				// throw new AssertionError();
			}
			if (cc == 0)
				return 0;
			if (Long.signum(cc) != Long.signum(dd))
				return 0;
			if (Math.abs(cc) > Math.abs(dd)) {
				return 1;
			}
			return cc * 1. / dd;
		}
	}

	static int signum(double a) {
		if (Math.abs(a) < EPS)
			return 0;
		return a < 0 ? -1 : 1;
	}

	static int compare(double a, double b) {
		double d = a - b;
		if (Math.abs(d) < EPS)
			return 0;
		return d < 0 ? -1 : 1;
	}

	static class Event implements Comparable<Event> {
		double t;
		boolean open;

		public Event(double t, boolean open) {
			this.t = t;
			this.open = open;
		}

		@Override
		public int compareTo(Event o) {
			int cmp = compare(t, o.t);
			if (cmp != 0)
				return cmp;
			if (open == o.open)
				return 0;
			return open ? 1 : -1;
		}

		public String toString() {
			return String.format("%.2f: ", t) + (open ? 1 : 0);
		}
	}

	static final double EPS = 1e-7;

	double[] intersect(Segment s1, Segment s2, Segment s) {
		if (!s1.intersects(s) || !s2.intersects(s))
			return null;

		double d1 = s.intersect(s1);
		double d2 = s.intersect(s2);
		return new double[] { Math.min(d1, d2), Math.max(d1, d2) };
	}

	void addEvents(ArrayList<Event> list, double[] d) {
		list.add(new Event(d[0], true));
		list.add(new Event(d[1], false));
	}

	void work(Segment s1, Segment s2, Segment s3, int i, int j) {
		Segment q = segments[i][j];
		double[] d = intersect(s1, s2, q);
		if (d != null) {
			addEvents(events[i][j], d);
		}
		d = intersect(s2, s3, q);
		if (d != null) {
			addEvents(events[i][j], d);
		}
		d = intersect(s3, s1, q);
		if (d != null) {
			addEvents(events[i][j], d);
		}
	}

	void work(int k) {
		Segment s1 = segments[k][0];
		Segment s2 = segments[k][1];
		Segment s3 = segments[k][2];
		for (int i = 0; i < n; i++) {
			if (i == k)
				continue;
			for (int j = 0; j < 3; j++) {
				work(s1, s2, s3, i, j);
			}
		}
	}

	double calculate(int i, int j) {
		ArrayList<Event> cur = events[i][j];
		Collections.sort(cur);
		int open = 0;
		double last = 0;
		double res = 0;
		for (Event e : cur) {
			if (open > 0)
				res += e.t - last;
			last = e.t;
			if (e.open) {
				++open;
			} else {
				--open;
			}
		}
		res = 1 - res;
		return res * segments[i][j].abs();
	}

	Segment[][] segments;
	ArrayList<Event>[][] events;
	Point[][] points;
	int n;

	private void solve() throws IOException {
		n = nextInt();
		points = new Point[n][3];
		for (int i = 0; i < n; i++) {
			points[i][0] = new Point(nextInt(), nextInt());
			points[i][1] = new Point(nextInt(), nextInt());
			points[i][2] = new Point(nextInt(), nextInt());
		}
		events = new ArrayList[n][3];
		segments = new Segment[n][3];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				events[i][j] = new ArrayList<C.Event>();
				segments[i][j] = new Segment(points[i][j != 0 ? 0 : 1],
						points[i][j != 2 ? 2 : 1]);
			}
		}
		for (int i = 0; i < n; i++) {
			work(i);
		}
		double res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				res += calculate(i, j);
			}
		}
		out.printf(Locale.US, "%.8f", res);
	}

	public static void main(String[] args) {
		new C().run();
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
			st = new StringTokenizer("");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				eof = true;
				line = "0";
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
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