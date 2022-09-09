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

	interface IntComparator {
		public int compare(int o1, int o2);
	}

	static void sortWith(int a[], IntComparator cmp) {
		int n = a.length;
		if (n == 0) {
			return;
		}
		for (int i = 1; i < n; i++) {
			int j = i;
			int ca = a[i];
			do {
				int nj = (j - 1) >> 1;
				int na = a[nj];
				if (cmp.compare(na, ca) >= 0) {
					break;
				}
				a[j] = na;
				j = nj;
			} while (j != 0);
			a[j] = ca;
		}
		int ca = a[0];
		for (int i = n - 1; i > 0; i--) {
			int j = 0;
			while ((j << 1) + 2 + Integer.MIN_VALUE < i + Integer.MIN_VALUE) {
				j <<= 1;
				j += (cmp.compare(a[j + 1], a[j + 2]) < 0) ? 2 : 1;
			}
			if ((j << 1) + 2 == i) {
				j = (j << 1) + 1;
			}
			int na = a[i];
			a[i] = ca;
			ca = na;
			while (j != 0 && cmp.compare(a[j], ca) < 0) {
				j = (j - 1) >> 1;
			}
			while (j != 0) {
				na = a[j];
				a[j] = ca;
				ca = na;
				j = (j - 1) >> 1;
			}
		}
		a[0] = ca;
	}

	static void solve() throws Exception {
		int n = scanInt();
		final int x[] = new int[n];
		final int y[] = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = scanInt();
			y[i] = scanInt();
		}
		int ox[] = new int[n];
		int oy[] = new int[n];
		for (int i = 0; i < n; i++) {
			ox[i] = oy[i] = i;
		}
		sortWith(ox, new IntComparator() {
			public int compare(int o1, int o2) {
				return x[o1] != x[o2] ? x[o1] - x[o2] : y[o1] - y[o2];
			}
		});
		sortWith(oy, new IntComparator() {
			public int compare(int o1, int o2) {
				return y[o1] != y[o2] ? y[o1] - y[o2] : x[o1] - x[o2];
			}
		});
		int gapsX = 0, gapsY = 0;
		for (int i = 0; i < n - 1; i++) {
			if (x[ox[i]] == x[ox[i + 1]]) {
				++gapsX;
			}
			if (y[oy[i]] == y[oy[i + 1]]) {
				++gapsY;
			}
		}
		Matcher.n = gapsX;
		Matcher.m = gapsY;
		Matcher.init();
		for (int i = 0, ii = 0; i < n - 1; i++) {
			int pi1 = ox[i], pi2 = ox[i + 1], xi;
			if ((xi = x[pi1]) != x[pi2]) {
				continue;
			}
			for (int j = 0, jj = 0; j < n - 1; j++) {
				int pj1 = oy[j], pj2 = oy[j + 1], yj;
				if ((yj = y[pj1]) != y[pj2]) {
					continue;
				}
				if (x[pj1] < xi && xi < x[pj2] && y[pi1] < yj && yj < y[pi2]) {
					Matcher.edges[ii][jj] = true;
				}
				++jj;
			}
			++ii;
		}
		Matcher.hopcroftKarp();
		int cx = -1, cy = -1;
		IntList ans = new IntList();
		for (int i = 0, ii = 0; i < n; i++) {
			int nx = x[oy[i]], ny = y[oy[i]];
			if (i == 0) {
				cx = nx;
				cy = ny;
				ans.push(cx);
				ans.push(cy);
				continue;
			}
			if (ny == cy && Matcher.hkDist[ii++] < 0) {
				cx = nx;
				cy = ny;
				continue;
			}
			ans.push(cx);
			ans.push(cy);
			cx = nx;
			cy = ny;
			ans.push(cx);
			ans.push(cy);
		}
		ans.push(cx);
		ans.push(cy);
		out.println(ans.size() / 4);
		for (int i = 0; i < ans.size(); i += 4) {
			out.println(ans.get(i) + " " + ans.get(i + 1) + " " + ans.get(i + 2) + " " + ans.get(i + 3));
		}
		ans.clear();
		for (int i = 0, ii = 0; i < n; i++) {
			int nx = x[ox[i]], ny = y[ox[i]];
			if (i == 0) {
				cx = nx;
				cy = ny;
				ans.push(cx);
				ans.push(cy);
				continue;
			}
			if (nx == cx) {
				if (Matcher.matchingL[ii] < 0 || Matcher.hkDist[Matcher.matchingL[ii]] >= 0) {
					++ii;
					cx = nx;
					cy = ny;
					continue;
				}
				++ii;
			}
			ans.push(cx);
			ans.push(cy);
			cx = nx;
			cy = ny;
			ans.push(cx);
			ans.push(cy);
		}
		ans.push(cx);
		ans.push(cy);
		out.println(ans.size() / 4);
		for (int i = 0; i < ans.size(); i += 4) {
			out.println(ans.get(i) + " " + ans.get(i + 1) + " " + ans.get(i + 2) + " " + ans.get(i + 3));
		}
	}

	static class Matcher {
		static int n, m;
		static boolean edges[][];
		static int matchingL[], matchingR[];
		static int hkDist[], hkQueue[];

		static void init() {
			edges = new boolean[n][m];
			matchingL = new int[n];
			matchingR = new int[m];
			hkDist = new int[m];
			hkQueue = new int[2 * n];
		}

		static int hopcroftKarp() {
			fill(matchingL, -1);
			fill(matchingR, -1);
			int size = 0;
			while (true) {
				fill(hkDist, -1);
				int queueHead = 0, queueTail = 0;
				for (int i = 0; i < n; i++) {
					if (matchingL[i] < 0) {
						hkQueue[queueTail++] = i;
						hkQueue[queueTail++] = 0;
					}
				}
				int resDist = -1;
				while (queueHead < queueTail) {
					int cur = hkQueue[queueHead++];
					int cdist = hkQueue[queueHead++];
					if ((cdist + Integer.MIN_VALUE) > (resDist + Integer.MIN_VALUE)) {
						break;
					}
					for (int next = 0; next < m; next++) {
						if (!edges[cur][next] || hkDist[next] >= 0) {
							continue;
						}
						hkDist[next] = cdist;
						int next2 = matchingR[next];
						if (next2 < 0) {
							resDist = cdist;
						} else {
							hkQueue[queueTail++] = next2;
							hkQueue[queueTail++] = cdist + 1;
						}
					}
				}
				if (resDist < 0) {
					return size;
				}
				for (int cur = 0; cur < n; cur++) {
					if (matchingL[cur] < 0 && hopcroftKarpDfs(cur, 0)) {
						++size;
					}
				}
			}
		}

		static boolean hopcroftKarpDfs(int cur, int cdist) {
			for (int next = 0; next < m; next++) {
				if (!edges[cur][next] || hkDist[next] != cdist) {
					continue;
				}
				hkDist[next] = -1;
				int next2 = matchingR[next];
				if (next2 < 0 || hopcroftKarpDfs(next2, cdist + 1)) {
					matchingR[next] = cur;
					matchingL[cur] = next;
					return true;
				}
			}
			return false;
		}
	}

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