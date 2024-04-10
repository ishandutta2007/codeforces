import java.io.*;
import java.util.*;

public class A {

	static void solve() throws IOException {
		int a = nextInt();
		String s = nextToken();
		int n = s.length();
		int[] sum = new int[n + 1];
		for (int i = 0; i < n; i++) {
			sum[i + 1] = sum[i] + s.charAt(i) - '0';
		}
		int all = n * (n + 1) / 2;
		int[] arr = new int[all];
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				arr[cnt++] = sum[i] - sum[j];
			}
		}
		Arrays.sort(arr);
		long answer = 0;
		if (a == 0) {
			int zeros = 0;
			for (int i = 0; i < cnt; i++) {
				if (arr[i] == 0) {
					++zeros;
				}
			}
			answer = (long) zeros * (long) cnt * 2L - (long) zeros
					* (long) zeros;
		} else {
			int p = cnt - 1;
			for (int i = 0; i < cnt;) {
				int j = i + 1;
				int value1 = arr[i];
				while (j < cnt && arr[j] == value1) {
					j++;
				}
				int count1 = j - i;
				i = j;
				if (value1 == 0) {
					continue;
				}
				if (a % value1 != 0) {
					continue;
				}
				int value2 = a / value1;
				while (p >= 0 && arr[p] > value2) {
					--p;
				}
				if (p >= 0 && arr[p] == value2) {
					int count2 = 0;
					while (p >= 0 && arr[p] == value2) {
						--p;
						++count2;
					}
					answer += (long) count1 * (long) count2;
				}
			}
		}
		out.println(answer);
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("a.in");
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solve();
		out.close();
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
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
}