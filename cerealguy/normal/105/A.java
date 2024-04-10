import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class A {

	private void solve() throws IOException {
		int n = nextInt(), m = nextInt();
		int k = (int) (nextDouble() * 100 + .1);
		Map<String, Integer> skills = new TreeMap<String, Integer>();
		for (int i = 0; i < n; i++) {
			String name = nextToken();
			int score = nextInt();
			score = (score * k) / 100;
			if (score >= 100) {
				skills.put(name, score);
			}
		}
		for (int i = 0; i < m; i++) {
			String name = nextToken();
			if (!skills.containsKey(name)) {
				skills.put(name, 0);
			}
		}
		
		out.println(skills.size());
		for (Entry<String, Integer> ent: skills.entrySet()) {
			out.println(ent.getKey()+" "+ent.getValue());
		}
	}

	public static void main(String[] args) {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			new A().solve();
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