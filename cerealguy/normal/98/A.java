import java.io.*;
import java.util.*;

public class A {

	private void solve() throws IOException {
		char[] c = nextToken().toCharArray();
		int[] a = new int[6];
		for (int i = 0; i < 6; i++) {
			a[i] = c[i];
		}
		int res = generateCubes(a);
		out.println(res);
	}

	static boolean nextPermutation(int[] p) {
		for (int i = p.length - 2; i >= 0; --i) {
			if (p[i] >= p[i + 1]) {
				continue;
			}
			int j = i + 1;
			while (j + 1 < p.length && p[j + 1] > p[i]) {
				j++;
			}
			int t = p[i];
			p[i] = p[j];
			p[j] = t;
			Arrays.sort(p, i + 1, p.length);
			return true;
		}
		return false;
	}

	static int generateCubes(int[] alphabet) {
		Cube[] allcubes = generateCubes();
		Arrays.sort(alphabet);

		HashSet<Cube> visited = new HashSet<A.Cube>();
		int res = 0;
		int[] a1 = new int[6];
		do {
			boolean ok = true;
			for (Cube c : allcubes) {
				for (int i = 0; i < 6; i++) {
					a1[c.a[i]] = alphabet[i];
				}
				Cube c1 = new Cube(a1);
				if (visited.contains(c1)) {
					ok = false;
					break;
				}
			}
			if (ok) {
				res++;
				visited.add(new Cube(alphabet.clone()));
			}
		} while (nextPermutation(alphabet));
		return res;
	}

	static Cube[] generateCubes() {
		Cube start = new Cube(new int[] { 0, 1, 2, 3, 4, 5 });
		Queue<Cube> q = new ArrayDeque<A.Cube>();
		HashSet<Cube> visited = new HashSet<A.Cube>();
		q.add(start);
		visited.add(start);
		while (!q.isEmpty()) {
			Cube u = q.poll();
			for (Cube v : new Cube[] { u.rotate1(), u.rotate2(), u.rotate3() }) {
				if (!visited.contains(v)) {
					visited.add(v);
					q.add(v);
				}
			}
		}
		return (Cube[]) visited.toArray(new Cube[visited.size()]);
	}

	static class Cube {
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + Arrays.hashCode(a);
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Cube other = (Cube) obj;
			if (!Arrays.equals(a, other.a))
				return false;
			return true;
		}

		int[] a;

		public Cube(int[] a) {
			this.a = a;
		}

		Cube rotate1() {
			int[] a1 = a.clone();
			a1[0] = a[5];
			a1[5] = a[1];
			a1[1] = a[4];
			a1[4] = a[0];
			return new Cube(a1);
		}

		Cube rotate2() {
			int[] a1 = a.clone();
			a1[0] = a[3];
			a1[3] = a[1];
			a1[1] = a[2];
			a1[2] = a[0];
			return new Cube(a1);
		}

		Cube rotate3() {
			int[] a1 = a.clone();
			a1[4] = a[3];
			a1[3] = a[5];
			a1[5] = a[2];
			a1[2] = a[4];
			return new Cube(a1);
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