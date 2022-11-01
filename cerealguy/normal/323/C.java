import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class C {

	static void solve() throws IOException {
		int n = nextInt();
		int[] p = new int[n];
		int[] inQ = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = nextInt() - 1;
		}
		for (int i = 0; i < n; i++) {
			inQ[nextInt() - 1] = i;
		}
		int x = 0;
		int queries = nextInt();
		Tree tree = new Tree(p, inQ);
		while (queries-- > 0) {
			int a = nextInt(), b = nextInt(), c = nextInt(), d = nextInt();
			int fa  = (a - 1 + x)%n+1; 
			int fb  = (b - 1 + x)%n+1; 
			int fc  = (c - 1 + x)%n+1; 
			int fd  = (d - 1 + x)%n+1; 
			if (fa > fb) {
				int t = fa;
				fa = fb;
				fb = t;
			}
			if (fc > fd) {
				int t = fc;
				fc = fd;
				fd = t;
			}
//			System.err.println(fa+" "+fb+", "+fc+" "+fd);
			x = tree.query(fa, fb, fc, fd);
			out.println(x);
			++x;
		}
	}

	static class Tree {
		int[][] list;

		Tree(int[] p, int[] inQ) {
			int n = p.length;
			int size = Integer.highestOneBit(2 * n - 1);
			list = new int[2 * size][];
			fill(list, new int[0]);
			for (int i = size; i < size + n; i++) {
				list[i] = new int[] { inQ[p[i - size]] };
			}
			for (int i = size - 1; i > 0; --i) {
				int[] l1 = list[2 * i];
				int[] l2 = list[2 * i + 1];
				int[] l = Arrays.copyOf(l1, l1.length + l2.length);
				System.arraycopy(l2, 0, l, l1.length, l2.length);
				Arrays.sort(l);
				list[i] = l;
			}
//			for (int i = 1; i < list.length; i++) {
//				System.err.println(Arrays.toString(list[i]));
//			}
		}

		int left1, right1;
		int left2, right2;

		int queryAnswer;

		int query(int l1, int r1, int l2, int r2) {
			left1 = l1 - 1;
			left2 = l2 - 1;
			right1 = r1;
			right2 = r2;
			queryAnswer = 0;
			go(1, 0, list.length / 2);
			return queryAnswer;
		}

		private void go(int i, int from, int to) {
			if (to <= left1 || from >= right1) {
				return;
			}
			if (from >= left1 && to <= right1) {
				queryAnswer += count(list[i], left2, right2);
				return;
			}
			int mid = from + to >> 1;
			go(2 * i, from, mid);
			go(2 * i + 1, mid, to);
		}

		private static int count(int[] array, int from, int to) {
			return binarySearch(array, to) - binarySearch(array, from);
		}

		private static int binarySearch(int[] array, int value) {
			int left = -1, right = array.length;
			while (right - left > 1) {
				int mid = left + right >>> 1;
				if (array[mid] < value) {
					left = mid;
				} else {
					right = mid;
				}
			}
			return right;
		}
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

	public static int nextInt() throws IOException {
		int c = br.read();
		while ((c < '0' || c > '9') && c != '-')
			c = br.read();
		boolean negative = false;
		if (c == '-') {
			negative = true;
			c = br.read();
		}
		int m = 0;
		while (c >= '0' && c <= '9') {
			m = m * 10 + c - '0';
			c = br.read();
		}
		return negative ? -m : m;
	}
}