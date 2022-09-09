import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;
import static java.util.Arrays.fill;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.StringTokenizer;

public class G {

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

	static class Tree {

		final int n;
		final int add[], nZero[];

		Tree(int n) {
			this.n = n;
			add = new int[2 * n - 1];
			nZero = new int[2 * n - 1];
			fill(nZero, n - 1, 2 * n - 1, 1);
			for (int i = n - 1; i != 0; i--) {
				nZero[i - 1] = nZero[(i << 1) - 1] + nZero[i << 1];
			}
		}

		void fix(int i) {
			nZero[i - 1] = add[i - 1] != 0 ? 0 : i >= n ? 1 : nZero[(i << 1) - 1] + nZero[i << 1];
		}

		void push(int i) {
			for (int j = 31 - Integer.numberOfLeadingZeros(i); j != 0; --j) {
				int p = i >> j;
				int v = add[p - 1];
				if (v != 0) {
					add[(p << 1) - 1] += v;
					nZero[(p << 1) - 1] = 0;
					add[p << 1] += v;
					nZero[p << 1] = 0;
					add[p - 1] = 0;
				}
			}
		}

		int get1(int l, int r) {
			int vl = 0, vr = 0;
			for (l += n, r += n;; l >>>= 1, r >>>= 1) {
				if (l != 1) {
					if (add[l - 2] != 0) {
						vl = 0;
					}
				}
				if (r < 2 * n && add[r - 1] != 0) {
					vr = 0;
				}
				if (l == r && (l & 1) != 0) {
					break;
				}
				if ((l & 1) != 0) {
					vl += nZero[l++ - 1];
				}
				if ((r & 1) != 0) {
					vr += nZero[--r - 1];
				}
			}
			int v = vl + vr;
			for (l >>>= 1; l != 0; l >>>= 1) {
				if (add[l - 1] != 0) {
					v = 0;
				}
			}
			return v;
		}

		void inc(int l, int r) {
			if (l == r) {
				return;
			}
			l += n;
			r += n;
			for (int cl = l, cr = r; cl != cr; cl >>>= 1, cr >>>= 1) {
				if ((cl & 1) != 0) {
					++add[cl - 1];
					nZero[cl++ - 1] = 0;
				}
				if ((cr & 1) != 0) {
					++add[--cr - 1];
					nZero[cr - 1] = 0;
				}
			}
			for (int i = Integer.numberOfTrailingZeros(l) + 1; l >>> i != 0; ++i) {
				fix(l >>> i);
			}
			for (int i = Integer.numberOfTrailingZeros(r) + 1; r >>> i != 0; ++i) {
				fix(r >>> i);
			}
		}

		void dec(int i) {
			if (add[i] != 0) {
				--add[i];
			} else {
				dec((i << 1) + 1);
				dec((i << 1) + 2);
			}
			fix(i + 1);
		}

		void dec(int l, int r) {
			if (l == r) {
				return;
			}
			l += n;
			r += n;
			for (int cl = l, cr = r; cl != cr; cl >>>= 1, cr >>>= 1) {
				if ((cl & 1) != 0) {
					dec(cl - 1);
					fix(cl++);
				}
				if ((cr & 1) != 0) {
					dec(--cr - 1);
					fix(cr);
				}
			}
			for (int i = Integer.numberOfTrailingZeros(l) + 1; l >>> i != 0; ++i) {
				fix(l >>> i);
			}
			for (int i = Integer.numberOfTrailingZeros(r) + 1; r >>> i != 0; ++i) {
				fix(r >>> i);
			}
		}
	}

	static IntList children[];
	static int pos[], endPos[], curPos;

	static class Event implements Comparable<Event> {
		final int pos, l, r;
		final boolean end;

		Event(int pos, int l, int r, boolean end) {
			this.pos = pos;
			this.l = l;
			this.r = r;
			this.end = end;
		}

		public int compareTo(Event o) {
			return pos - o.pos;
		}
	}

	static void solve() throws Exception {
		int n = scanInt(), m = scanInt();
		String f[] = new String[n];
		for (int i = 0; i < n; i++) {
			f[i] = scanString();
		}
		int idx[] = new int[n * m];
		int n0 = 0, n1 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				idx[i * m + j] = ((i ^ j) & 1) == 0 ? n0++ : n1++;
			}
		}
		children = new IntList[n * m];
		for (int i = 0; i < n * m; i++) {
			children[i] = new IntList();
		}
		IntList roots0 = new IntList(), roots1 = new IntList();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				IntList curRoots = ((i ^ j) & 1) != 0 ? roots1 : roots0;
				switch (f[i].charAt(j)) {
				case 'L':
					(j + 2 >= m ? curRoots : children[i * m + j + 2]).push(i * m + j);
					break;
				case 'R':
					(j - 2 < 0 ? curRoots : children[i * m + j - 2]).push(i * m + j);
					break;
				case 'U':
					(i + 2 >= n ? curRoots : children[(i + 2) * m + j]).push(i * m + j);
					break;
				case 'D':
					(i - 2 < 0 ? curRoots : children[(i - 2) * m + j]).push(i * m + j);
					break;
				default:
					throw new AssertionError();
				}
			}
		}
		pos = new int[n * m];
		endPos = new int[n * m];
		curPos = 0;
		for (int i = 0; i < roots0.size; i++) {
			dfs(roots0.data[i]);
		}
		curPos = 0;
		for (int i = 0; i < roots1.size; i++) {
			dfs(roots1.data[i]);
		}
		Event evs[] = new Event[n * m];
		int nEvs = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int p1 = i * m + j, p2;
				switch (f[i].charAt(j)) {
				case 'L':
					p2 = p1 + 1;
					break;
				case 'U':
					p2 = p1 + m;
					break;
				default:
					continue;
				}
				if (((i ^ j) & 1) != 0) {
					int t = p1;
					p1 = p2;
					p2 = t;
				}
				evs[nEvs++] = new Event(pos[p1], pos[p2], endPos[p2], false);
				evs[nEvs++] = new Event(endPos[p1], pos[p2], endPos[p2], true);
			}
		}
		sort(evs);
		int time = 0;
		long ans = 0;
		Tree tree = new Tree(n1);
		for (Event e: evs) {
			if (time != e.pos) {
				ans += (long) (e.pos - time) * (n1 - tree.get1(0, n1));
				time = e.pos;
			}
			if (e.end) {
				tree.dec(e.l, e.r);
			} else {
				tree.inc(e.l, e.r);
			}
		}
		out.print(ans);
	}

	static void dfs(int cur) {
		pos[cur] = curPos++;
		IntList ch = children[cur];
		for (int i = 0; i < ch.size; i++) {
			dfs(ch.data[i]);
		}
		endPos[cur] = curPos;
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