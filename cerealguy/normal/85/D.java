import java.io.*;
import java.util.*;

public class D {

	private void solve() throws IOException {
		int n = nextInt();
		int[] operationType = new int[n];
		int[] operationValue = new int[n];
		HashSet<Integer> interesting = new HashSet<Integer>();
		for (int i = 0; i < n; i++) {
			String op = nextToken();
			if ("sum".equals(op)) {
				continue;
			}
			if ("add".equals(op)) {
				operationType[i] = 1;
				operationValue[i] = nextInt();
				interesting.add(operationValue[i]);
				continue;
			}
			if ("del".equals(op)) {
				operationType[i] = 2;
				operationValue[i] = nextInt();
				interesting.add(operationValue[i]);
				continue;
			}
			throw new AssertionError();
		}
		int[] arr = toArray(interesting);
		Arrays.sort(arr);
		value = arr;
		SegmentTree tree = new SegmentTree(arr.length);
		for (int i = 0; i < n; i++) {
			if (operationType[i] == 0) {
				out.println(tree.get());
				continue;
			}
			if (operationType[i] == 1) {
				tree.add(Arrays.binarySearch(arr, operationValue[i]));
				continue;
			}
			if (operationType[i] == 2) {
				tree.remove(Arrays.binarySearch(arr, operationValue[i]));
				continue;
			}
		}
	}

	static int[] toArray(HashSet<Integer> list) {
		int[] res = new int[list.size()];
		int cnt = 0;
		for (int i : list) {
			res[cnt++] = i;
		}
		return res;
	}

	static int[] value;

	static class SegmentTree {
		long[][] s;
		int[] size;
		int h;

		SegmentTree(int n) {
			h = 0;
			while (1 << h < n) {
				h++;
			}
			s = new long[5][1 << h + 1];
			size = new int[1 << h + 1];
		}

		void add(int n) {
			add1(1, 0, 1 << h, n);
		}

		void add1(int i, int from, int to, int n) {
			if (from == n && to == n + 1) {
				for (int j = 0; j < 5; j++) {
					s[j][i] = 0;
				}
				s[0][i] = value[n];
				size[i] = 1;
				return;
			}
			if (from > n || to <= n)
				return;
			add1(2 * i, from, (from + to) / 2, n);
			add1(2 * i + 1, (from + to) / 2, to, n);
			fix(i);
		}

		void fix(int i) {
			int shift = (5 - size[2 * i] % 5) % 5;
			size[i] = size[2 * i] + size[2 * i + 1];
			for (int j = 0; j < 5; j++) {
				s[j][i] = s[j][2 * i] + s[(j + shift) % 5][2 * i + 1];
			}
		}

		void remove(int n) {
			remove1(1, 0, 1 << h, n);
		}

		void remove1(int i, int from, int to, int n) {
			if (from == n && to == n + 1) {
				for (int j = 0; j < 5; j++) {
					s[j][i] = 0;
				}
				size[i] = 0;
				return;
			}
			if (from > n || to <= n)
				return;
			remove1(2 * i, from, (from + to) / 2, n);
			remove1(2 * i + 1, (from + to) / 2, to, n);
			fix(i);
		}

		long get() {
			return s[2][1];
		}
	}

	public static void main(String[] args) {
		new D().run();
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