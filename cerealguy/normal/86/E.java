import java.io.*;
import java.util.*;

public class E {

	boolean[] get(int k) {
		ArrayList<Integer> divisors = divisors(k);
		// System.err.println(((1<<k) - 1)+" "+divisors);
		for (int i = 0; i < 1000; i++) {
			boolean[] res = random(k);
			if (check(res, divisors))
				return res;
		}
		return null;
	}

	final static Random rand = new Random();

	boolean[] random(int k) {
		boolean[] res = new boolean[k];
		for (int i = 0; i < k; i++) {
			res[i] = rand.nextBoolean();
		}
		return res;
	}

	void print(boolean[] m) {
		if (m == null) {
			System.err.println();
			return;
		}
		int k = m.length;
		for (int j = 0; j < k; j++) {
			System.err.print(m[j] ? 1 : 0);
		}
	}

	void print(boolean[][] m) {
		int k = m.length;
		for (int i = 0; i < k; i++) {
			print(m[i]);
			System.err.println();
		}
	}

	boolean check(boolean[] c, ArrayList<Integer> divisors) {
		int k = c.length;
		boolean[][] m = new boolean[k][k];
		for (int i = 0; i < k - 1; i++) {
			m[i][i + 1] = true;
		}
		m[k - 1] = c.clone();
		// print(m);
		// System.err.println("----");
		// print(pow(m, 2));
		long number = (1L << k) - 1;
		if (!isOne(pow(m, number))) {
			return false;
		}
		for (int d : divisors) {
			if (isOne(pow(m, number / d)))
				return false;
		}
		return true;
	}

	boolean isZero(boolean[][] m) {
		int k = m.length;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				if (m[i][j])
					return false;
			}
		}
		return true;
	}

	boolean isOne(boolean[][] m) {
		int k = m.length;
		for (int i = 0; i < k; i++) {
			if (!m[i][i])
				return false;
			for (int j = 0; j < k; j++) {
				if (j != i && m[i][j])
					return false;
			}
		}
		return true;
	}

	ArrayList<Integer> divisors(int k) {
		long number = (1L << k) - 1;
		long ok = number;
		ArrayList<Integer> res = new ArrayList<Integer>();
		for (long i = 3; i * i <= number; i += 2) {
			if (number % i == 0) {
				res.add((int) i);
				while (number % i == 0)
					number /= i;
			}
		}
		if (number < ok) {
			res.add((int) number);
		}
		return res;
	}

	boolean[][] pow(boolean[][] a, long pow) {
		int k = a.length;
		boolean[][] a1 = new boolean[k][];
		for (int i = 0; i < k; i++) {
			a1[i] = a[i].clone();
		}
		a = a1;
		boolean[][] tmp = new boolean[k][k];
		boolean[][] res = new boolean[k][k];
		for (int i = 0; i < k; i++) {
			res[i][i] = true;
		}
		while (pow > 0) {
			if (pow % 2 == 1) {
				mul(res, a, tmp);
				boolean[][] t = tmp;
				tmp = res;
				res = t;
			}
			pow >>= 1;
			mul(a, a, tmp);
			boolean[][] t = tmp;
			tmp = a;
			a = t;
		}
		return res;
	}

	void mul(boolean[][] a, boolean[][] b, boolean[][] res) {
		int k = a.length;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				res[i][j] = false;
				for (int j2 = 0; j2 < k; j2++) {
					res[i][j] ^= a[i][j2] & b[j2][j];
				}
			}
		}
	}

	String[] res = { "", "1", "11", "110", "1001", "11101", "110110",
			"1100101", "11100001", "100110111", "1101000100", "10001110000",
			"111100111001", "1110000001110", "11011011010001",
			"101011101110011", "1111110111111000", "11011111100100001",
			"100101101100101101", "1011001110010100011",
			"10011000110001000000", "101100011010010110010",
			"1001000110100000011100", "11111101100101010101001",
			"111100111100110000101110", "1000010110100010110000101",
			"11011000110010000101010101", "100110011010000111000110010",
			"1111010100011011111110000111", "11011100011110101100000001111",
			"111100011101111111111100101110",
			"1101001000001110010000010001110",
			"10100010110111110011110100100110",
			"100110101111111100111000101011010",
			"1001111010010001101001110111101110",
			"11010111010000101101010110100110010",
			"100101000101110100010010000011011110",
			"1001010101001001110011110100111011010",
			"11111001100110100110001110011110000010",
			"110001010100011010011010110101111111010",
			"1010001001111011001111101111011011110101",
			"11010010100110011011010111000101111111100",
			"111001010001110011111001001001010111000110",
			"1111001001110011111111101111110101100010001",
			"11010001011100100111001100010111110011100011",
			"101011001101111100000101100010011101111011110",
			"1111001111110001001110110011100100101001101001",
			"11111101001100011001010010001001011011110000101",
			"110100110001000100000010101101110100010010101010",
			"1100100010110000110110011001100111001011001010000",
			"11011110110010010001110001001111001110101101100101", };

	private void solve() throws IOException {
		int k = nextInt();
		String s = res[k];
		s = new StringBuilder(s).reverse().toString();
		for (int i = 0; i < k; i++) {
			if (i > 0) {
				out.print(" ");
			}
			out.print(s.charAt(i));
		}
		out.println();
		out.print(1);
		for (int i = 0; i < k - 1; i++) {
			out.print(" 0");
		}
		out.println();
		// for (int k = 2; k <= 50; k++) {
		// boolean[] res = get(k);
		// System.err.print("\"");
		// print(res);
		// System.err.println("\",");
		//
		// }
	}

	public static void main(String[] args) {
		new E().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	public void run() {
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