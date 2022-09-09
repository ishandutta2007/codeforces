import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.StringTokenizer;

public class F {

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

	static IntList ans;

	static boolean[] solve(int n, int offset) {
		if (n == 1) {
			return new boolean[1];
		}
		for (int i = 0; i < n / 2; i++) {
			ans.push(offset + i);
			ans.push(offset + i + n / 2);
		}
		boolean subres[] = solve(n / 2, offset);
		solve(n / 2, offset + n / 2);
		boolean res[] = new boolean[n];
		arraycopy(subres, 0, res, 0, n / 2);
		arraycopy(subres, 0, res, n / 2, n / 2);
		if (n % 2 != 0) {
			int cnt = 0;
			for (int i = 0; i < n / 2; i++) {
				if (subres[i]) {
					++cnt;
				}
			}
			cnt *= 2;
			boolean consume = true;
			if (cnt > n - 1 - cnt) {
				cnt = n - 1 - cnt;
				consume = false;
			}
			int bits = 32 - Integer.numberOfLeadingZeros(cnt);
			int curSet[] = new int[1 << bits];
			curSet[0] = n - 1;
			int posTrue = 0, posFalse = 0;
			for (int i = 0; i < bits; i++) {
				boolean consumeNow = consume ^ ((cnt & (1 << i)) == 0);
				int pos = consumeNow ? posTrue : posFalse;
				for (int j = 0; j < 1 << i; j++) {
					while (true) {
						if (pos == n - 1) {
							throw new AssertionError();
						}
						if (res[pos] == consumeNow) {
							break;
						}
						++pos;
					}
					ans.push(offset + curSet[j]);
					ans.push(offset + pos);
					curSet[(1 << i) + j] = pos;
					++pos;
				}
				if (consumeNow) {
					posTrue = pos;
				} else {
					posFalse = pos;
				}
			}
			fill(res, false);
			for (int i: curSet) {
				res[i] = true;
			}
		}
		return res;
	}

	static void solve() throws Exception {
		int n = scanInt();
		ans = new IntList();
		solve(n, 0);
		out.println(ans.size / 2);
		for (int i = 0; i < ans.size; i += 2) {
			out.println((ans.data[i] + 1) + " " + (ans.data[i + 1] + 1));
		}
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