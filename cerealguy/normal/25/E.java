import java.io.*;
import java.util.*;

public class e implements Runnable {

	private void solve() throws IOException {
		String s1 = nextToken(), s2 = nextToken(), s3 = nextToken();
		if (isPrefix(s1, s2) || isPrefix(s1, s3)) {
			out.println(Math.min(min0(s2, s3), min0(s3, s2)));
			return;
		}
		if (isPrefix(s2, s3) || isPrefix(s2, s1)) {
			out.println(Math.min(min0(s1, s3), min0(s3, s1)));
			return;
		}
		if (isPrefix(s3, s2) || isPrefix(s3, s1)) {
			out.println(Math.min(min0(s2, s1), min0(s1, s2)));
			return;
		}
		int ans = Integer.MAX_VALUE;
		ans = Math.min(ans, min2(s1, s2, s3));
		ans = Math.min(ans, min2(s1, s3, s2));
		ans = Math.min(ans, min2(s2, s1, s3));
		ans = Math.min(ans, min2(s2, s3, s1));
		ans = Math.min(ans, min2(s3, s1, s2));
		ans = Math.min(ans, min2(s3, s2, s1));
		out.println(ans);

	}

	int min0(String a, String b) {
		int[] p = prefix((b + "$" + a).toCharArray());
		int pp = p[p.length - 1];
		return a.length() + b.length() - pp;
	}

	boolean isPrefix(String s1, String s2) {
		int[] p = prefix((s1 + "$" + s2).toCharArray());
		for (int i = s1.length() + 1; i < p.length; i++) {
			if (p[i] == s1.length())
				return true;
		}
		return false;
	}

	int[] prefix(char[] c) {
		int[] p = new int[c.length + 1];
		int k = 0;
		for (int i = 1; i < c.length; i++) {
			while (k > 0 && c[i] != c[k])
				k = p[k];
			if (c[i] == c[k])
				k++;
			p[i + 1] = k;
		}
		return p;
	}

	int min1(String a, String b, String c) {
		int[] p = prefix((b + "$" + a).toCharArray());
		int pp = p[p.length - 1];
		a = a + b.substring(pp);
		p = prefix((c + "$" + a).toCharArray());
		pp = p[p.length - 1];
		return a.length() + c.length() - pp;
	}

	Random rand = new Random();

	String randomString(int max, int len) {
		String s = "";
		for (int i = 0; i < len; i++) {
			s += (char) (rand.nextInt(max) + 'a');
		}
		return s;
	}

	int min2(String a, String b, String c) {
		int[] p = prefix((c + "$" + a).toCharArray());
		int[] p1 = prefix((b + "$" + a).toCharArray());
		int[] p2 = prefix((c + "$" + b).toCharArray());

		HashSet<Integer> a1 = new HashSet<Integer>();
		for (int i = p1[p1.length - 1]; i > 0; i = p1[i]) {
			a1.add(i);
		}
		int l = b.length();

		for (int k = p[p.length - 1]; k > 0; k = p[k]) {
			if (p2[p2.length - 1] >= k && p1[p1.length - 1] >= k
					&& p2[p2.length - 1] + p1[p1.length - 1] >= l + k) {

				for (int i = p2[p2.length - 1]; i > 0
						&& i + p1[p1.length - 1] >= l + k; i = p2[i]) {
					if (a1.contains(l + k - i)) {
						// System.out.println(a + c.substring(k));
						// System.err.println(a.length() + c.length() - k);
						return a.length() + c.length() - k;
					}
				}
			}
		}
		return min1(a, b, c);
	}

	public static void main(String[] args) {
		new Thread(new e()).start();
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