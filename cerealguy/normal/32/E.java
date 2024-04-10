import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class E implements Runnable {

	Point intersect(Line l1, Line l2) {
		Frac det = l1.a.multiply(l2.b).sub(l2.a.multiply(l1.b));
		Frac x = l1.c.multiply(l2.b).negate().add(l2.c.multiply(l1.b));
		Frac y = l1.a.multiply(l2.c).negate().add(l2.a.multiply(l1.c));
		return new Point(x.divide(det), y.divide(det));
	}

	boolean intersect(Point v, Point p, Point t1, Point t2) {
		Line l1 = new Line(v, p);
		Line l2 = new Line(t1, t2);
		Frac det = l1.a.multiply(l2.b).sub(l2.a.multiply(l1.b));
		if (det.signum() != 0)
			return l1.side(t1) * l1.side(t2) <= 0
					&& l2.side(v) * l2.side(p) <= 0;
		else {
			if (l1.side(t1) != 0) {
				return false;
			} else {
				return pointBetween(v, p, t1) || pointBetween(v, p, t2);
			}
		}
	}

	boolean mirrorIsBad(Point v, Point p, Point t1, Point t2) {
		Line l1 = new Line(v, p);
		Line l2 = new Line(t1, t2);
		Frac det = l1.a.multiply(l2.b).sub(l2.a.multiply(l1.b));
		if (det.signum() != 0)
			return l1.side(t1) * l1.side(t2) <= 0
					&& l2.side(v) * l2.side(p) <= 0;
		else {
			return false;
		}
	}

	boolean pointBetween(Point a, Point b, Point t) {
		boolean b1 = a.x.compareTo(t.x) == a.x.compareTo(b.x)
				&& b.x.compareTo(t.x) == b.x.compareTo(a.x);
		boolean b2 = a.y.compareTo(t.y) == a.y.compareTo(b.y)
				&& b.y.compareTo(t.y) == b.y.compareTo(a.y);
		return b1 && b2;
	}

	boolean mirrorIsNotUseful(Point v, Point p, Point m1, Point m2) {
		Line mirror = new Line(m1, m2);
		return mirror.side(v) * mirror.side(p) <= 0;
	}

	boolean solve1() {
		Point v = nextPoint();
		Point p = nextPoint();
		Point w1 = nextPoint(), w2 = nextPoint();
		Point m1 = nextPoint(), m2 = nextPoint();
		if (mirrorIsNotUseful(v, p, m1, m2)) {
			return !intersect(v, p, w1, w2) && !mirrorIsBad(v, p, m1, m2);
		}
		if (!intersect(v, p, w1, w2) && !intersect(v, p, m1, m2)) {
			return true;
		}
		Line mirror = new Line(m1, m2);
		Point virtualP = mirror.reflect(p);

		if (!intersect(v, virtualP, m1, m2))
			return false;

		Point m = intersect(new Line(v, virtualP), new Line(m1, m2));
		return !intersect(v, m, w1, w2) && !intersect(m, p, w1, w2);
	}

	private void solve() throws IOException {
		if (solve1()) {
			out.println("YES");
		} else {
			out.println("NO");
		}
	}

	Point nextPoint() {
		return new Point(nextInt(), nextInt());
	}

	class Line {
		Frac a, b, c;

		Line(Point p1, Point p2) {
			b = p1.x.sub(p2.x);
			a = p2.y.sub(p1.y);
			c = p1.x.multiply(a).add(p1.y.multiply(b)).negate();
		}

		int side(Point p) {
			Frac val = a.multiply(p.x).add(b.multiply(p.y)).add(c);
			return val.signum();
		}

		Point reflect(Point p) {
			Frac val = a.multiply(p.x).add(b.multiply(p.y)).add(c);
			Frac warp = a.multiply(a).add(b.multiply(b));
			val = val.divide(warp);
			Frac xx = p.x.sub(a.multiply(val).multiply(new Frac(2)));
			Frac yy = p.y.sub(b.multiply(val).multiply(new Frac(2)));
			return new Point(xx, yy);
		}

		@Override
		public String toString() {
			return "Line [a=" + a + ", b=" + b + ", c=" + c + "]";
		}
	}

	class Point {
		Frac x, y;

		public Point(int x, int y) {
			this.x = new Frac(x);
			this.y = new Frac(y);
		}

		public Point(Frac x, Frac y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public String toString() {
			return "Point [x=" + x + ", y=" + y + "]";
		}
	}

	class Frac implements Comparable<Frac> {
		BigInteger n, d;

		Frac(long n) {
			this.n = BigInteger.valueOf(n);
			d = BigInteger.ONE;
		}

		Frac(long n, long d) {
			if (d == 0)
				throw new ArithmeticException();
			if (d < 0) {
				d = -d;
				n = -n;
			}
			this.n = BigInteger.valueOf(n);
			this.d = BigInteger.valueOf(d);
			normalize();
		}

		Frac(BigInteger n, BigInteger d) {
			if (d.signum() == 0)
				throw new ArithmeticException();
			if (d.signum() < 0) {
				d = d.negate();
				n = n.negate();
			}
			this.n = n;
			this.d = d;
			normalize();
		}

		void normalize() {
			BigInteger gcd = n.gcd(d);
			n = n.divide(gcd);
			d = d.divide(gcd);
		}

		Frac negate() {
			return new Frac(n.negate(), d);
		}

		Frac multiply(Frac f) {
			return new Frac(n.multiply(f.n), d.multiply(f.d));
		}

		Frac divide(Frac f) {
			return new Frac(n.multiply(f.d), d.multiply(f.n));
		}

		Frac add(Frac f) {
			return new Frac(n.multiply(f.d).add(d.multiply(f.n)),
					d.multiply(f.d));
		}

		Frac sub(Frac f) {
			return this.add(f.negate());
		}

		int signum() {
			return n.signum();
		}

		@Override
		public String toString() {
			return String.format("%.2f", n.doubleValue() / d.doubleValue());
		}

		@Override
		public int compareTo(Frac o) {
			return this.n.multiply(o.d).compareTo(this.d.multiply(o.n));
		}
	}

	public static void main(String[] args) {
		new Thread(new E()).start();
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