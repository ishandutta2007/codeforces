import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.StringTokenizer;

public class E {

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

	static int perm[] = new int[5];
	static int muls[] = {1, 1, 2, 6, 24};

	static int packPerm() {
		int res = 0;
		for (int i = 1; i < 5; i++) {
			for (int j = 0; j < i; j++) {
				if (perm[i] > perm[j]) {
					res += muls[i];
				}
			}
		}
		return res;
	}

	static void unpackPerm(int v) {
		for (int i = 0; i < 5; i++) {
			perm[i] = i;
		}
		for (int i = 4; i > 0; i--) {
			int c = v / muls[i];
			v %= muls[i];
			while (c < i) {
				int t = perm[c];
				perm[c] = perm[++c];
				perm[c] = t;
			}
		}
	}

	static int permMul[] = new int[120 * 120];
	static {
		Arrays.fill(permMul, -1);
	}
	static int perm2[] = new int[5], perm3[] = new int[5];
	static int permMul(int a, int b) {
		int id = 120 * a + b;
		int res = permMul[id];
		if (res < 0) {
			unpackPerm(a);
			int t[] = perm;
			perm = perm2;
			perm2 = t;
			unpackPerm(b);
			t = perm;
			perm = perm3;
			perm3 = t;
			for (int i = 0; i < 5; i++) {
				perm[i] = perm2[perm3[i]];
			}
			permMul[id] = res = packPerm();
		}
		return res;
	}
	static final int IDENTITY = 119;

	static class Key {
		final long a, b;

		Key(long a, long b) {
			this.a = a;
			this.b = b;
		}

		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + (int) (a ^ (a >>> 32));
			result = prime * result + (int) (b ^ (b >>> 32));
			return result;
		}

		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Key other = (Key) obj;
			if (a != other.a)
				return false;
			if (b != other.b)
				return false;
			return true;
		}
	}

	static List<Key> sg = new ArrayList<>();
	static Map<Key, Integer> sgMap = new HashMap<>();

	static int k2i(long a, long b) {
		Key k = new Key(a, b);
		Integer res = sgMap.get(k);
		if (res == null) {
			sgMap.put(k, res = sg.size());
			sg.add(k);
		}
		return res;
	}

	static int groupOfPerm[] = new int[120];
	static {
		Arrays.fill(groupOfPerm, -1);
	}
	static int groupOfPerm(int p) {
		int res = groupOfPerm[p];
		if (res < 0) {
			long g[] = new long[2];
			int cp = IDENTITY;
			while (true) {
				if ((g[cp >> 6] & (1L << cp)) != 0) {
					break;
				}
				g[cp >> 6] |= 1L << cp;
				cp = permMul(cp, p);
			}
			groupOfPerm[p] = res = k2i(g[0], g[1]);
		}
		return res;
	}

	static IntList groupSize = new IntList();
	static int groupSize(int group) {
		if (groupSize.size() > group) {
			int res = groupSize.get(group);
			if (res >= 0) {
				return res;
			}
		}
		Key k = sg.get(group);
		int res = Long.bitCount(k.a) + Long.bitCount(k.b);
		while (groupSize.size() <= group) {
			groupSize.push(-1);
		}
		groupSize.set(group, res);
		return res;
	}

	static IntList mergeGroups = new IntList();
	static int stack[] = new int[120];
	static int mergeGroups(int a, int b) {
		if (a == b) {
			return a;
		}
		if (a > b) {
			int t = a;
			a = b;
			b = t;
		}
		int id = b * (b - 1) / 2 + a;
		if (mergeGroups.size() > id) {
			int res = mergeGroups.get(id);
			if (res >= 0) {
				return res;
			}
		}
		Key k1 = sg.get(a), k2 = sg.get(b);
		long r[] = {0, 0};
		r[IDENTITY >> 6] |= 1L << IDENTITY;
		stack[0] = IDENTITY;
		int stackSize = 1;
		long aa = k1.a | k2.a, bb = k1.b | k2.b;
		do {
			int cur = stack[--stackSize];
			for (int i = 0; i < 64; i++) {
				if ((aa & (1L << i)) != 0) {
					int next = permMul(cur, i);
					if ((r[next >> 6] & (1L << next)) == 0) {
						r[next >> 6] |= 1L << next;
						stack[stackSize++] = next;
					}
				}
			}
			for (int i = 64; i < 120; i++) {
				if ((bb & (1L << i)) != 0) {
					int next = permMul(cur, i);
					if ((r[next >> 6] & (1L << next)) == 0) {
						r[next >> 6] |= 1L << next;
						stack[stackSize++] = next;
					}
				}
			}
		} while (stackSize != 0);
		int res = k2i(r[0], r[1]);
		while (mergeGroups.size() <= id) {
			mergeGroups.push(-1);
		}
		mergeGroups.set(id, res);
		return res;
	}

	static int gr[];

	static void solve() throws Exception {
		int n = scanInt();
		int k = scanInt();
		gr = new int[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++) {
				perm[j] = scanInt() - 1;
			}
			for (int j = k; j < 5; j++) {
				perm[j] = j;
			}
			gr[i] = groupOfPerm(packPerm());
		}
		out.print(go(0, n));
	}

	static int stackA[] = new int[20], stackB[] = new int[20];
	static long go(int l, int r) {
		if (r == l) {
			return 0;
		}
		if (r == l + 1) {
			return groupSize(gr[l]);
		}
		int mid = (l + r) / 2;
		int curGroup = gr[mid];
		stackA[0] = curGroup;
		stackA[1] = 1;
		int stackSizeA = 2;
		for (int i = mid - 1; i >= l; i--) {
			curGroup = mergeGroups(curGroup, gr[i]);
			if (stackA[stackSizeA - 2] == curGroup) {
				++stackA[stackSizeA - 1];
			} else {
				stackA[stackSizeA++] = curGroup;
				stackA[stackSizeA++] = 1;
			}
		}
		curGroup = gr[mid];
		stackB[0] = curGroup;
		stackB[1] = 1;
		int stackSizeB = 2;
		for (int i = mid + 1; i < r; i++) {
			curGroup = mergeGroups(curGroup, gr[i]);
			if (stackB[stackSizeB - 2] == curGroup) {
				++stackB[stackSizeB - 1];
			} else {
				stackB[stackSizeB++] = curGroup;
				stackB[stackSizeB++] = 1;
			}
		}
		long res = 0;
		for (int i = 0; i < stackSizeA; i += 2) {
			for (int j = 0; j < stackSizeB; j += 2) {
				res += (long) groupSize(mergeGroups(stackA[i], stackB[j])) * stackA[i + 1] * stackB[j + 1];
			}
		}
		return res + go(l, mid) + go(mid + 1, r);
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