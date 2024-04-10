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
import java.util.ArrayList;
import java.util.List;
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

	static class IntIntMap {

		static final int EMPTY = Integer.MIN_VALUE;

		int data[] = new int[4];
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

		static int hash(int key) {
			int hash = key * 1000000007;
			hash ^= hash >> 16;
			hash ^= hash >> 24;
			return hash;
		}

		boolean have(int key) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			for (int mask = data.length - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				int cur = data[i];
				if (cur == key) {
					return true;
				} else if (cur == EMPTY) {
					return false;
				}
			}
		}

		int get(int key, int default_) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			for (int mask = data.length - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				int cur = data[i];
				if (cur == key) {
					return data[i + 1];
				} else if (cur == EMPTY) {
					return default_;
				}
			}
		}

		static int[] resize(int data[], int newCapacity) {
			int oldCapacity = data.length;
			int ndata[] = new int[newCapacity];
			for (int i = 0; i < newCapacity; i += 2) {
				ndata[i] = EMPTY;
			}
			for (int mask = newCapacity - 2, i = 0; i < oldCapacity; i += 2) {
				int cur = data[i];
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

		void set(int key, int value) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			int data[] = this.data;
			for (int capacity = data.length, mask = capacity - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				int cur = data[i];
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

		void delete(int key) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			int data[] = this.data;
			for (int capacity = data.length, mask = capacity - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				int cur = data[i];
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
			int data[] = this.data;
			int oldCapacity = data.length;
			if (oldCapacity >> 2 < newCapacity) {
				this.data = resize(data, Integer.highestOneBit(newCapacity - 1) << 3);
			}
		}

		void shrink() {
			int data[] = this.data;
			int oldCapacity = data.length;
			if (oldCapacity > 4 && oldCapacity >> 3 >= size) {
				this.data = resize(data, max(Integer.highestOneBit(size - 1) << 3, 4));
			}
		}

		static class Iterator {

			final int data[];
			int position = -2;

			Iterator(int data[]) {
				this.data = data;
				advance();
			}

			boolean hasNext() {
				return position < data.length;
			}

			int getKey() {
				return data[position];
			}

			int getValue() {
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

	static final List<IntList> freeLists = new ArrayList<>();

	static IntList takeList() {
		if (freeLists.isEmpty()) {
			return new IntList();
		} else {
			return freeLists.remove(freeLists.size() - 1);
		}
	}

	static void putList(IntList list) {
		list.clear();
		freeLists.add(list);
	}

	static int n, m;

	static IntList solve(int from, int to) {
		IntList res;
		if (from + 1 == to) {
			res = takeList();
			res.push(from);
			if (from + m > n) {
				res.push(n - from);
				res.push(from - n);
			}
			res.push(m);
			if (from > m) {
				res.push(n - from);
				res.push(from);
			}
			res.push(-from);
		} else {
			int mid = (from + to) >> 1;
			IntList a = solve(from, mid), b = solve(mid, to);
			res = takeList();
			int aSize = a.size, bSize = b.size;
			int aData[] = a.data, bData[] = b.data;
			for (int i = 0;; i += 2) {
				int bFrom = i == 0 ? 0 : bData[i - 1];
				int bTo = i == bSize - 1 ? n : bData[i + 1];
				int bShift = bData[i];
				int aFrom = bFrom + bShift;
				int aTo = bTo + bShift;
				int l = 0, r = aSize - 1;
				while (l < r) {
					int m = (((l + r) >> 2) << 1) + 1;
					if (aData[m] <= aFrom) {
						l = m + 1;
					} else {
						r = m - 1;
					}
				}
				int cur = l;
				while (true) {
					res.push(bShift + aData[cur]);
					++cur;
					if (cur == aSize) {
						break;
					}
					int pos = aData[cur];
					if (pos >= aTo) {
						break;
					}
					res.push(pos - bShift);
					++cur;
				}
				if (i == bSize - 1) {
					break;
				}
				res.push(bTo);
			}
			putList(a);
			putList(b);
		}
		return res;
	}

	static void solve() throws Exception {
		n = scanInt();
		m = scanInt();
		int s = scanInt() - 1;
		long t = scanLong();
		for (int ct = (int) (t % n); ct != 0; ct--) {
			if (s < m) {
				s += ct;
				if (s >= n) {
					s -= n;
				}
			} else {
				s -= ct;
				if (s < 0) {
					s += n;
				}
			}
		}
		long cycles = t / n;
		if (cycles > 0) {
			IntList cycleSolve = solve(0, n);
			int csSize = cycleSolve.size, csData[] = cycleSolve.data;
			IntList cycleList = takeList();
			IntIntMap cycleMap = new IntIntMap();
			for (int it = 0;; it++) {
				if (it == cycles) {
					break;
				}
				int prev = cycleMap.get(s, -1);
				if (prev >= 0) {
					s = cycleList.get(prev + (int) ((cycles - prev) % (it - prev)));
					break;
				}
				cycleList.push(s);
				cycleMap.set(s, it);
				int l = 0, r = csSize - 1;
				while (l < r) {
					int m = (((l + r) >> 2) << 1) + 1;
					if (csData[m] <= s) {
						l = m + 1;
					} else {
						r = m - 1;
					}
				}
				s += csData[l];
			}
		}
		out.print(s + 1);
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