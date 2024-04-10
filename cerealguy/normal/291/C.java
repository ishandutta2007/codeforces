import java.io.*;
import java.util.*;

public class Cqual {

	static void solve() throws IOException {
		int n = nextInt(), k = nextInt();
		int[] ip = new int[n];
		for (int i = 0; i < n; i++) {
			ip[i] = readIP();
		}
		sort(ip, 0, n);
		int left = 0, right = 32;
		int answerMask = 50216;
		while (right - left > 1) {
			int mid = left + right >>> 1;
			int mask = ~((1 << 32 - mid) - 1);
			int count = count(ip, mask);
			if (count < k) {
				left = mid;
			} else {
				right = mid;
				if (count == k) {
					answerMask = mask;
				}
			}
		}
		if (answerMask == 50216) {
			out.println(-1);
		} else {
			out.println(ipToString(answerMask));
		}
	}

	private static String ipToString(int answerMask) {
		return (answerMask >>> 24) + "." + ((answerMask >>> 16) & 0xFF) + "."
				+ ((answerMask >>> 8) & 0xFF) + "." + (answerMask & 0xFF);
	}

	private static int count(int[] ip, int mask) {
		if (ip.length == 0) {
			return 0;
		}
		int count = 1;
		int last = ip[0] & mask;
		for (int i = 1; i < ip.length; i++) {
			int cur = ip[i] & mask;
			if (cur != last) {
				++count;
				last = cur;
			}
		}

		return count;
	}

	private static int readIP() throws IOException {
		int ip = 0;
		for (int i = 0; i < 4; i++) {
			ip = (ip << 8) + nextInt();
		}
		return ip;
	}

	public static void sort(int[] a, int from, int to) {
		int n = to - from;
		int[] temp = new int[n];
		int[] cnt = new int[1 << 16];
		for (int i = to - 1; i >= from; --i) {
			++cnt[low(a[i])];
		}
		for (int i = 0; i < cnt.length - 1; ++i) {
			cnt[i + 1] += cnt[i];
		}
		for (int i = to - 1; i >= from; --i) {
			temp[--cnt[low(a[i])]] = a[i];
		}

		Arrays.fill(cnt, 0);
		for (int i = n - 1; i >= 0; --i) {
			++cnt[high(temp[i])];
		}
		cnt[0] += from;
		for (int i = 0; i < cnt.length - 1; ++i) {
			cnt[i + 1] += cnt[i];
		}
		for (int i = n - 1; i >= 0; --i) {
			a[--cnt[high(temp[i])]] = temp[i];
		}
	}

	private static int high(int a) {
		return (a ^ Integer.MIN_VALUE) >>> 16;
	}

	private static int low(int a) {
		return a & 0xFFFF;
	}

	static BufferedReader br;
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
	
	static int nextInt() throws IOException {
		int m = 0;
		int c = br.read();
		while (c < '0' || c > '9')
			c = br.read();
		while (c >= '0' && c <= '9') {
			m = m * 10 + c - '0';
			c = br.read();
		}
		return m;
	}
}