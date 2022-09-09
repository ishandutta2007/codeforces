import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.StringTokenizer;

public class C {

	static class IntList {

		int data[] = new int[3];
		int size = 0;

		boolean isEmpty() {
			return size == 0;
		}

		int size() {
			return size;
		}

		int get(int index) {
			if (index < 0 || index >= size) {
				throw new IndexOutOfBoundsException();
			}
			return data[index];
		}

		void clear() {
			size = 0;
		}

		void set(int index, int value) {
			if (index < 0 || index >= size) {
				throw new IndexOutOfBoundsException();
			}
			data[index] = value;
		}

		void expand() {
			if (size >= data.length) {
				data = copyOf(data, (data.length << 1) + 1);
			}
		}

		void insert(int index, int value) {
			if (index < 0 || index > size) {
				throw new IndexOutOfBoundsException();
			}
			expand();
			arraycopy(data, index, data, index + 1, size++ - index);
			data[index] = value;
		}

		int delete(int index) {
			if (index < 0 || index >= size) {
				throw new IndexOutOfBoundsException();
			}
			int value = data[index];
			arraycopy(data, index + 1, data, index, --size - index);
			return value;
		}

		void push(int value) {
			expand();
			data[size++] = value;
		}

		int pop() {
			if (size == 0) {
				throw new NoSuchElementException();
			}
			return data[--size];
		}

		void unshift(int value) {
			expand();
			arraycopy(data, 0, data, 1, size++);
			data[0] = value;
		}

		int shift() {
			if (size == 0) {
				throw new NoSuchElementException();
			}
			int value = data[0];
			arraycopy(data, 1, data, 0, --size);
			return value;
		}
	}

	static final int MOD = 1000000007;

	static int add(int a, int b) {
		int res = a + b;
		return res >= MOD ? res - MOD : res;
	}

	static int sub(int a, int b) {
		int res = a - b;
		return res < 0 ? res + MOD : res;
	}

	static int mul(int a, int b) {
		int res = (int) ((long) a * b % MOD);
		return res < 0 ? res + MOD : res;
	}

	static IntList edges[];
	static long x[];

	static void solve() throws Exception {
		int n = scanInt();
//		int n = 100000;
		x = new long[n];
		edges = new IntList[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new IntList();
		}
		for (int i = 0; i < n; i++) {
			x[i] = scanLong();
//			x[i] = 1L << min(i, 40);
		}
		for (int i = 0; i < n - 1; i++) {
			int a = scanInt() - 1, b = scanInt() - 1;
//			int a = i, b = i + 1;
			edges[a].push(b);
			edges[b].push(a);
		}
		out.print(dfs(0, -1, new long[0]));
	}

	static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	static long gcdStack[] = new long[100];
	static int gcdStackSize = 0;

	static void gcdPush(long gcd, long cnt) {
		if (gcdStackSize != 0 && gcdStack[gcdStackSize - 2] == gcd) {
			gcdStack[gcdStackSize - 1] += cnt;
		} else {
			gcdStack[gcdStackSize++] = gcd;
			gcdStack[gcdStackSize++] = cnt;
		}
	}

	static int dfs(int cur, int prev, long gcd[]) {
		long cx = x[cur];
		gcdStackSize = 0;
		gcdPush(cx, 1);
		int res = (int) (cx % MOD);
		for (int i = 0; i < gcd.length; i += 2) {
			gcdPush(cx = gcd(cx, gcd[i]), gcd[i + 1]);
			res = add(res, mul((int) (cx % MOD), (int) gcd[i + 1]));
		}
		gcd = Arrays.copyOf(gcdStack, gcdStackSize);
		IntList e = edges[cur];
		for (int i = 0; i < e.size; i++) {
			int next = e.data[i];
			if (next != prev) {
				res = add(res, dfs(next, cur, gcd));
			}
		}
		return res;
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}