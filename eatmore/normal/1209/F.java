import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.PriorityQueue;
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

	static class LongLongMap {

		static final long EMPTY = Long.MIN_VALUE;

		long data[] = new long[4];
		{
			data[0] = EMPTY;
			data[2] = EMPTY;
		}
		int size = 0;

		boolean isEmpty() {
			return size == 0;
		}

		int size() {
			return size;
		}

		void clear() {
			for (int i = 0; i < data.length; i += 2) {
				data[i] = EMPTY;
			}
			size = 0;
		}

		static int hash(long key) {
			long hash = key * 1000000007;
			hash ^= hash >> 16;
			hash ^= hash >> 24;
			return (int) hash;
		}

		boolean have(long key) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			for (int mask = data.length - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
				if (cur == key) {
					return true;
				} else if (cur == EMPTY) {
					return false;
				}
			}
		}

		long get(long key, long default_) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			for (int mask = data.length - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
				if (cur == key) {
					return data[i + 1];
				} else if (cur == EMPTY) {
					return default_;
				}
			}
		}

		static long[] resize(long data[], int newCapacity) {
			int oldCapacity = data.length;
			long ndata[] = new long[newCapacity];
			for (int i = 0; i < newCapacity; i += 2) {
				ndata[i] = EMPTY;
			}
			for (int mask = newCapacity - 2, i = 0; i < oldCapacity; i += 2) {
				long cur = data[i];
				if (cur == EMPTY) {
					continue;
				}
				for (int j = hash(cur) & mask;; j = (j - 1) & mask) {
					if (ndata[j] == EMPTY) {
						ndata[j] = cur;
						ndata[j + 1] = data[i + 1];
						break;
					}
				}
			}
			return ndata;
		}

		void set(long key, long value) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			long data[] = this.data;
			for (int capacity = data.length, mask = capacity - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
				if (cur == key) {
					data[i + 1] = value;
					return;
				} else if (cur == EMPTY) {
					data[i] = key;
					data[i + 1] = value;
					if (++size > capacity >> 2) {
						this.data = resize(data, capacity << 1);
					}
					return;
				}
			}
		}

		void delete(long key) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			long data[] = this.data;
			for (int capacity = data.length, mask = capacity - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
				if (cur == key) {
					for (int j = i;;) {
						cur = data[j = (j - 1) & mask];
						if (cur == EMPTY) {
							data[i] = EMPTY;
							--size;
							return;
						}
						int k = hash(cur) & mask;
						if ((k >= i) ^ (k < j) ^ (i < j)) {
							data[i] = cur;
							data[i + 1] = data[j + 1];
							i = j;
						}
					}
				} else if (cur == EMPTY) {
					return;
				}
			}
		}

		void expand(int newCapacity) {
			long data[] = this.data;
			int oldCapacity = data.length;
			if (oldCapacity >> 2 < newCapacity) {
				this.data = resize(data, Integer.highestOneBit(newCapacity - 1) << 3);
			}
		}

		void shrink() {
			long data[] = this.data;
			int oldCapacity = data.length;
			if (oldCapacity > 4 && oldCapacity >> 3 >= size) {
				this.data = resize(data, max(Integer.highestOneBit(size - 1) << 3, 4));
			}
		}

		static class Iterator {

			final long data[];
			int position = -2;

			Iterator(long data[]) {
				this.data = data;
				advance();
			}

			boolean hasNext() {
				return position < data.length;
			}

			long getKey() {
				return data[position];
			}

			long getValue() {
				return data[position + 1];
			}

			void advance() {
				do {
					position += 2;
				} while (position < data.length && data[position] == EMPTY);
			}
		}

		Iterator iterator() {
			return new Iterator(data);
		}
	}

	static int cnt = 0, vals[] = new int[200000], prevs[][] = new int[20][200000];
	static LongLongMap fwd = new LongLongMap();

	static int extend(int cur, int val) {
		long key = (cur & 0xffffffffL) | ((long) val << 32);
		long res = fwd.get(key, -1);
		if (res >= 0) {
			return (int) res;
		}
		int r = cnt++;
		vals[r] = val;
		prevs[0][r] = cur;
		for (int i = 1; i < 20; i++) {
			prevs[i][r] = cur = cur < 0 ? -1 : prevs[i - 1][cur];
		}
		fwd.set(key, r);
		return r;
	}

	static int compare(int length, int a, int b) {
		if (length == 0) {
			return 0;
		}
		for (int i = 31 - Integer.numberOfLeadingZeros(length - 1); i >= 0; i--) {
			if (prevs[i][a] != prevs[i][b]) {
				a = prevs[i][a];
				b = prevs[i][b];
			}
		}
		return Integer.compare(vals[a], vals[b]);
	}

	static class Token implements Comparable<Token> {
		final int id, len, head, tail, val;

		Token(int id, int len, int head, int tail, int val) {
			this.id = id;
			this.len = len;
			this.head = head;
			this.tail = tail;
			this.val = val;
		}

		static final int p10[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
		static final int MOD = 1000000007;

		Token append(int v, int id) {
			int l = 0, p = 1;
			for (; p <= v; p *= 10) {
				++l;
			}
			int nHead, nTail;
			if (len / 9 == (len + l) / 9) {
				nHead = head;
				nTail = tail * p + v;
			} else {
				int ll = (len + l) / 9 * 9;
				nHead = extend(head, tail * p10[ll - len] + v / p10[len + l - ll]);
				nTail = v % p10[len + l - ll];
			}
			return new Token(id, len + l, nHead, nTail, (int) (((long) val * p + v) % MOD));
		}

		public int compareTo(Token o) {
			if (len != o.len) {
				return len - o.len;
			}
			int r = compare(len / 9, head, o.head);
			if (r != 0) {
				return r;
			}
			if (tail != o.tail) {
				return Integer.compare(tail, o.tail);
			}
			return id - o.id;
		}
	}

	static void solve() throws Exception {
		int n = scanInt(), m = scanInt();
		IntList edges[] = new IntList[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new IntList();
		}
		for (int i = 0; i < m; i++) {
			int a = scanInt() - 1, b = scanInt() - 1;
			edges[a].push(b);
			edges[a].push(i + 1);
			edges[b].push(a);
			edges[b].push(i + 1);
		}
		Token toks[] = new Token[n];
		toks[0] = new Token(0, 0, -1, 0, 0);
		PriorityQueue<Token> q = new PriorityQueue<>();
		q.add(toks[0]);
		boolean processed[] = new boolean[n];
		do {
			Token tok = q.remove();
			int cur = tok.id;
			if (processed[cur]) {
				continue;
			}
			processed[cur] = true;
			IntList cEdges = edges[cur];
			for (int i = 0; i < cEdges.size; i += 2) {
				int next = cEdges.data[i], nextE = cEdges.data[i + 1];
				Token tNext = tok.append(nextE, next);
				if (toks[next] == null || tNext.compareTo(toks[next]) < 0) {
					toks[next] = tNext;
					q.add(tNext);
				}
			}
		} while (!q.isEmpty());
		for (int i = 1; i < n; i++) {
			out.println(toks[i].val);
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