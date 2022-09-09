import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.StringTokenizer;

public class D {

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

	static void solve() throws Exception {
		int n = scanInt(), m = scanInt();
		IntList higherBad[] = new IntList[n];
		for (int i = 0; i < n; i++) {
			higherBad[i] = new IntList();
		}
		int nBad[] = new int[n];
		for (int i = 0; i < m; i++) {
			int a = scanInt() - 1, b = scanInt() - 1;
			if (a > b) {
				int t = a;
				a = b;
				b = t;
			}
			higherBad[a].push(b);
			++nBad[a];
			++nBad[b];
		}
		long ans = 0, pans[] = new long[n];
		for (int i = 0; i < n; i++) {
			ans += pans[i] = (long) (nBad[i] - higherBad[i].size()) * higherBad[i].size();
		}
		out.println(ans);
		int q = scanInt();
		for (int qq = 0; qq < q; qq++) {
			int cur = scanInt() - 1;
			ans -= pans[cur];
			pans[cur] = 0;
			for (int i = 0; i < higherBad[cur].size; i++) {
				int e = higherBad[cur].data[i];
				higherBad[e].push(cur);
				ans -= pans[e];
				ans += pans[e] = (long) (nBad[e] - higherBad[e].size()) * higherBad[e].size();
			}
			higherBad[cur].clear();
			out.println(ans);
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