import java.io.*;
import java.util.*;

public class C {

	static void solve() throws IOException {
		int n = nextInt(), read = nextInt();
		long[] h = new long[n];
		for (int i = 0; i < n; i++) {
			h[i] = nextLong();
		}
		long[] want = new long[read];
		for (int i = 0; i < read; i++) {
			want[i] = nextLong();
		}
		long left = -1;
		long right = (long) (1e12);
		while (right - left > 1) {
			long mid = left + right >>> 1;
			if (canReadInTime(h, want, mid)) {
				right = mid;
			} else {
				left = mid;
			}
		}
		out.println(right);
	}

	private static boolean canReadInTime(long[] h, long[] want, long time) {
		int n = h.length;
		int read = want.length;
		int curRead = 0;
		for (int head = 0; head < n && curRead < read; head++) {
			long pos = h[head];
			long toRead = want[curRead];
			if (toRead < pos) {
				long diff = pos - toRead;
				if (diff > time) {
					return false;
				}
			}
			while (curRead < read && want[curRead] <= pos) {
				curRead++;
			}
			while (curRead < read
					&& canDoInTime(toRead, pos, want[curRead], time)) {
				curRead++;
			}
		}
		return curRead == read;
	}

	private static boolean canDoInTime(long left, long start, long right,
			long time) {
		if (left < start) {
			long a = start - left;
			long b = right - start;
			return a + b + Math.min(a, b) <= time;
		} else {
			return right - start <= time;
		}
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("c.in");
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