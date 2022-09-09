import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.sqrt;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class F {

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

	static class LongLongCounter extends LongLongMap {

		long get(long key) {
			return get(key, 0);
		}

		void set(long key, long value) {
			if (value == 0) {
				delete(key);
			} else {
				super.set(key, value);
			}
		}

		void add(long key, long value) {
			if (key == EMPTY) {
				throw new IllegalArgumentException();
			}
			long data[] = this.data;
			for (int capacity = data.length, mask = capacity - 2, i = hash(key) & mask;; i = (i - 1) & mask) {
				long cur = data[i];
				if (cur == key) {
					data[i + 1] += value;
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
	}

	static void solve() throws Exception {
		String s = scanString();
		int n = s.length();
//		int n = 200000;
//		char ss[] = new char[n];
//		fill(ss, '1');
//		String s = new String(ss);
		LongLongCounter ctr = new LongLongCounter();
		long ans = 0;
		int cutoff = min((int) sqrt(n), 150);
		int cutoff2 = n / cutoff;
//		System.err.println("HERE1");
		for (int k = 1; k < cutoff; k++) {
			int p1 = 0, p2 = 0;
			long cur1 = 0, cur2 = 0;
			int o2 = 0;
			while (p2 < n && o2 <= cutoff2) {
				if (s.charAt(p2) == '1') {
					cur2 += k - 1;
					++o2;
				} else {
					--cur2;
				}
				++p2;
			}
			if (o2 <= cutoff2) {
				break;
			}
			ctr.add(cur1, 1);
			while (p1 < n && s.charAt(p1) == '0') {
				--cur1;
				++p1;
				ctr.add(cur1, 1);
			}
			while (true) {
				ans += ctr.get(cur2);
				if (p2 >= n) {
					break;
				}
				if (s.charAt(p2) == '1') {
					cur2 += k - 1;
					++o2;
					cur1 += k - 1;
					++p1;
					ctr.add(cur1, 1);
					while (p1 < n && s.charAt(p1) == '0') {
						--cur1;
						++p1;
						ctr.add(cur1, 1);
					}
				} else {
					--cur2;
				}
				++p2;
			}
			ctr.clear();
		}
//		System.err.println("HERE2");
		k: for (int k = 1; k <= cutoff2; k++) {
			int p1 = 0, p2, p3, p4;
			for (p2 = 0; p2 < n && s.charAt(p2) == '0'; p2++) { }
			if (p2 >= n) {
				break;
			}
			p3 = p2;
			for (int i = 1; i < k; i++) {
				for (p3++; p3 < n && s.charAt(p3) == '0'; p3++) { }
				if (p3 >= n) {
					break k;
				}
			}
			p4 = p3;
			for (p4++; p4 < n && s.charAt(p4) == '0'; p4++) { }
			while (true) {
				int l1 = p1, r1 = p2 + 1, l2 = p3 + 1, r2 = p4 + 1;
				if (r1 - l1 >= k) {
					ans += (long) (r1 - l1) / k * (r2 - l2);
					r1 = l1 + (r1 - l1) % k;
				}
				if (r2 - l2 >= k) {
					ans += (long) (r2 - l2) / k * (r1 - l1);
					r2 = l2 + (r2 - l2) % k;
				}
				int l = (l2 - (r1 - 1));
				if (l % k != 0) {
					l += k - l % k;
				}
				for (; l <= r2 - 1 - l1; l += k) {
					ans += min(r1 - 1, r2 - l - 1) - max(l1, l2 - l) + 1;
				}
				if (p4 >= n) {
					break;
				}
				p1 = p2 + 1;
				for (p2++; p2 < n && s.charAt(p2) == '0'; p2++) { }
				p3 = p4;
				for (p4++; p4 < n && s.charAt(p4) == '0'; p4++) { }
			}
		}
//		System.err.println("HERE3");
		out.print(ans);
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