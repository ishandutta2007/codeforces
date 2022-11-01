import java.io.*;
import java.util.*;

public class C {

	static void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[2 * n];
		int[] b = new int[2 * n];
		for (int i = 0; i < 2 * n; i++) {
			a[i] = nextInt() - 1;
			b[i] = nextInt() - 1;
		}
		int[] answer = solve(a, b, n);
		if (answer == null) {
			out.println(-1);
		} else {
			for (int i = 0; i < n; i++) {
				if (i > 0) {
					out.print(' ');
				}
				out.print(answer[i] + 1);
			}
			out.println();
		}
	}

	private static int[] solve(int[] a, int[] b, int n) {
		int[] size = new int[n];
		int[][] lists = new int[n][4];
		for (int i = 0; i < 2 * n; i++) {
			if (size[a[i]] == 4 || size[b[i]] == 4) {
				return null;
			}
			lists[a[i]][size[a[i]]++] = b[i];
			lists[b[i]][size[b[i]]++] = a[i];
		}
		for (int secondNumber : lists[0]) {
			for (int thirdNumber : lists[0]) {
				if (thirdNumber == secondNumber) {
					continue;
				}
				boolean[] used = new boolean[n];
				int[] restored = new int[n];
				restored[0] = 0;
				restored[1] = secondNumber;
				restored[2] = thirdNumber;
				used[0] = used[secondNumber] = used[thirdNumber] = true;
				for (int i = 3; i < n; i++) {
					boolean good = false;
					for (int value : lists[restored[i - 1]]) {
						if (used[value]) {
							continue;
						}
						if (!has(lists[restored[i - 2]], value)) {
							continue;
						}
						good = true;
						used[value] = true;
						restored[i] = value;
						break;
					}
					if (!good) {
						restored = null;
						break;
					}
				}
				if (restored != null && check(lists, restored)) {
					return restored;
				}
			}
		}
		return null;
	}

	private static boolean check(int[][] lists, int[] restored) {
		int n = restored.length;
		for (int i = 0; i < n; i++) {
			for (int dx = 0; dx < 2; dx++) {
				int j = (i + dx + 1) % n;
				if (!has(lists[restored[i]], restored[j])) {
					return false;
				}
			}
		}
		return true;
	}

	static boolean has(int[] list, int number) {
		for (int i : list) {
			if (i == number) {
				return true;
			}
		}
		return false;
	}

	static BufferedReader br;
	static PrintWriter out;
	static StringTokenizer st;

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

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