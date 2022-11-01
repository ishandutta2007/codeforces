import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class C {

	private static void solve() throws IOException {
		int n = nextInt();
		int length = nextInt();
		int v1 = nextInt(), v2 = nextInt();
		int[] candy = new int[n];
		for (int i = 0; i < n; i++) {
			candy[i] = nextInt();
		}

		Rational anton = new Rational((long) length * v2, v1 + v2);
		double antonDouble = anton.doubleValue();

		int weEat = 0;
		List<Event> events = new ArrayList<Event>();
		for (int i = 0; i < n; i++) {
			for (int it = 0; it < 2; it++) {
				double lose = candy[i] + it * 2L * length;
//				Rational lose = new Rational(candy[i] + it * 2L * length);
				Event loseEvent = new Event(lose, false);
				events.add(loseEvent);
				double gain = lose - (antonDouble);
				if (gain < 0) {
					++weEat;
				} else {
					Event gainEvent = new Event(gain, true);
					events.add(gainEvent);
				}
			}
		}
		double lastEvent = 0;
		Collections.sort(events);

		Rational thisEnds = new Rational(2 * length, 1);
		double thisEndsDouble = thisEnds.doubleValue();
		double[] answer = new double[n + 1];

		for (Event e : events) {
			double segment;
			boolean breakAfter = false;
			if (e.time  < thisEndsDouble) {
				segment = e.time - lastEvent;
			} else {
				segment = 2 * length - lastEvent;
				breakAfter = true;
			}
			if (weEat >= 0 && weEat <= n) {
			answer[weEat] += segment;
			}
			if (e.add) {
				++weEat;
			} else {
				--weEat;
			}

			if (breakAfter) {
				break;
			}
			lastEvent = e.time;
		}
		
		for (int i = 0; i <= n; i++) {
			out.println(answer[i] / (2 * length));
		}
		

	}

	static class Event implements Comparable<Event> {
		double time;
		boolean add;

		private Event(double time, boolean add) {
			this.time = time;
			this.add = add;
		}

		@Override
		public int compareTo(Event o) {
			int cmp = Double.compare(time, o.time);
			if (cmp != 0) {
				return cmp;
			}
			if (add != o.add) {
				return !add ? -1 : 1;
			}
			return 0;
		}
	}

	public static class Rational implements Comparable<Rational> {
		BigInteger num;
		BigInteger den;

		public static final Rational ZERO = new Rational(0);
		public static final Rational ONE = new Rational(1);
		public static final Rational TWO = new Rational(2);
		public static final Rational POSITIVE_INFINITY = new Rational(1, 0);
		public static final Rational NEGATIVE_INFINITY = new Rational(-1, 0);

		public Rational(long num) {
			this.num = BigInteger.valueOf(num);
			this.den = BigInteger.ONE;
		}

		public Rational(long num, long den) {
			this.num = BigInteger.valueOf(num);
			this.den = BigInteger.valueOf(den);
			// reduce();
		}

		public Rational(BigInteger num, BigInteger den) {
			this.num = num;
			this.den = den;
			// reduce();
		}

		void reduce() {
			BigInteger gcd = num.gcd(den);
			if (gcd.signum() != 0) {
				num = num.divide(gcd);
				den = den.divide(gcd);
			}
			if (den.signum() < 0) {
				num = num.negate();
				den = den.negate();
			}
		}

		public Rational add(Rational r) {
			return new Rational(num.multiply(r.den).add(r.num.multiply(den)), den.multiply(r.den));
		}

		public Rational sub(Rational r) {
			return new Rational(num.multiply(r.den).subtract(r.num.multiply(den)),
					den.multiply(r.den));
		}

		public Rational mul(Rational r) {
			return new Rational(num.multiply(r.num), den.multiply(r.den));
		}

		public Rational div(Rational r) {
			return new Rational(num.multiply(r.den), den.multiply(r.num));
		}

		public Rational negate() {
			return new Rational(num.negate(), den);
		}

		public Rational inverse() {
			return new Rational(den, num);
		}

		public Rational abs() {
			return new Rational(num.abs(), den);
		}

		public int signum() {
			return num.signum();
		}

		public double doubleValue() {
			return num.doubleValue() / den.doubleValue();
		}

		public int compareTo(Rational other) {
			return (num.multiply(other.den).compareTo(other.num.multiply(den)));
		}

		public boolean equals(Object obj) {
			return obj instanceof Rational && num.equals(((Rational) obj).num)
					&& den.equals(((Rational) obj).den);
		}

		public int hashCode() {
			return num.hashCode() * 31 + den.hashCode();
		}

		public String toString() {
			return num + "/" + den;
		}
	}

	public static void main(String[] args) {
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

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}