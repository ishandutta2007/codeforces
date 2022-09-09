import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class H {

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


	static long key(int start, long trace, int traceLen) {
		return trace + (1L << traceLen) + ((long) start << 58);
	}

//	static class Value {
//		final long len;
//		final int target;
//
//		Value(long len, int target) {
//			this.len = len;
//			this.target = target;
//		}
//	}

	static LongLongMap cache, cache2;

	static int retPos;
	static long retTrace, retLen;
	static boolean cacheGet(long key) {
		long v = cache.get(key, -1);
		if (v == -1) {
			return false;
		}
		retPos = (int) (v >>> 58);
		retTrace = v & ((1L << 58) - 1);
		retLen = cache2.get(key, -1);
		return true;
	}

	static void cacheSet(long key, int pos, long trace, long len) {
		cache.set(key, ((long) pos << 58) + trace);
		cache2.set(key, len);
	}

	static final List<int[]> pool = new ArrayList<>();
	static int[] poolGet() {
		if (pool.isEmpty()) {
			return new int[64];
		} else {
			return pool.remove(pool.size() - 1);
		}
	}
	static void poolPut(int a[]) {
		pool.add(a);
	}

	static long retState;
	static boolean run(int start, long state, long mask, long limit) {
		long trace = 0, traceMask = 0;
		int traceLen = 0;
		int traceMap[] = poolGet();
		int curPos = start;
		long curState = state;
		long curLen = 0;
		while ((mask & (1L << curPos)) != 0) {
			traceMask |= 1L << curPos;
			if ((state & (1L << curPos)) != 0) {
				trace |= 1L << traceLen;
			}
			traceMap[traceLen] = curPos;
			++traceLen;
			long key = key(start, trace, traceLen);
			if (cacheGet(key)) {
				if (retLen <= limit) {
					curPos = retPos;
					for (int i = 0; i < traceLen; i++) {
						int j = traceMap[i];
						curState ^= (((curState >> j) ^ (retTrace >> i)) & 1) << j;
					}
					curLen = retLen;
					continue;
				} else if (traceLen == 1) {
					retPos = start;
					retState = limit == 0 ? state : state ^ (1L << curPos);
					retLen = limit;
					return false;
				}
			}
			if (!run(curPos, curState, traceMask, limit - curLen)) {
				retLen += curLen;
				return false;
			}
			curPos = retPos;
			curState = retState;
			curLen += retLen;
			long newTrace = 0;
			for (int i = 0; i < traceLen; i++) {
				int j = traceMap[i];
				newTrace |= ((curState >> j) & 1) << i;
			}
			cacheSet(key, curPos, newTrace, curLen);
		}
		retPos = curPos;
		retState = curState;
		retLen = curLen;
		poolPut(traceMap);
		return true;
	}

	static void solve() throws Exception {
		int n = scanInt();
		cache = new LongLongMap();
		cache2 = new LongLongMap();
		for (int i = 0; i < n - 1; i++) {
			int b = scanInt() - 1, r = scanInt() - 1;
			if (i == r) {
				cacheSet(key(i, 0, 1), b, 0, 2);
			} else {
				cacheSet(key(i, 0, 1), r, 1, 1);
			}
			if (i == b) {
				cacheSet(key(i, 1, 1), r, 1, 2);
			} else {
				cacheSet(key(i, 1, 1), b, 0, 1);
			}
		}
		if (!run(0, 0, (1L << (n - 1)) - 1, Long.MAX_VALUE)) {
			throw new AssertionError();
		}
		long fullLen = retLen;
		int q = scanInt();
		for (int qq = 0; qq < q; qq++) {
			int cur = scanInt() - 1;
			String ss = scanString();
			long state = 0;
			for (int i = 0; i < n - 1; i++) {
				if (ss.charAt(i) == 'R') {
					state |= 1L << i;
				}
			}
			if (!run(cur, state, (1L << (n - 1)) - 1, Long.MAX_VALUE)) {
				throw new AssertionError();
			}
			long thisLen = retLen;
			if (thisLen > fullLen ||
				run(0, 0, (1L << (n - 1)) - 1, fullLen - thisLen) ||
				retPos != cur || retState != state) {
				out.println(-1);
			} else {
				out.println(fullLen - thisLen);
			}
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