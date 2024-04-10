import java.io.*;
import java.util.*;

public class D {

	int n;
	int[] qMan, qLeft, qRight;
	int[] x;
	int queries;

	int getIndex(int i) {
		int l = 0, r = x.length;
		while (r - l > 1) {
			int m = (r + l) / 2;
			if (x[m] > i) {
				r = m;
			} else {
				l = m;
			}
		}
		return l;
	}

	private void solve() throws IOException {
		n = nextInt();
		queries = nextInt();
		qMan = new int[queries];
		qLeft = new int[queries];
		qRight = new int[queries];
		HashSet<Integer> interesting = new HashSet<Integer>();
		interesting.add(0);
		interesting.add(n);
		for (int i = 0; i < queries; i++) {
			qMan[i] = nextInt();
			if (qMan[i] == 0) {
				qLeft[i] = nextInt() - 1;
				qRight[i] = nextInt();
				interesting.add(qLeft[i]);
				interesting.add(qRight[i]);
			}
		}
		x = new int[interesting.size()];
		int cnt = 0;
		for (int i : interesting) {
			x[cnt++] = i;
		}
		Arrays.sort(x);
		Fenwick f = new Fenwick(x.length);
		TreeSet<Segment> segments = new TreeSet<D.Segment>();
		TreeSet<Segment> segmentsByX = new TreeSet<D.Segment>(new ByStart());
		Segment s = new Segment(0, n);
		segments.add(s);
		segmentsByX.add(s);
		HashMap<Integer, Integer> taken = new HashMap<Integer, Integer>();
		for (int i = 0; i < queries; i++) {
			// System.err.println(segmentsByX);
			if (qMan[i] == 0) {
				// System.err.println("QUERY " + qLeft[i] + " " + qRight[i]);
				int l = getIndex(qLeft[i]);
				int r = getIndex(qRight[i]);
				out.println(f.getSum(l, r));
			} else {
				Integer pos = taken.get(qMan[i]);
				if (pos == null) {
					Segment t = segments.pollLast();
					segmentsByX.remove(t);
					pos = t.start + t.len / 2;
					// System.err.println("PUTTING " + qMan[i] + " TO " + pos);
					taken.put(qMan[i], pos);
					int ind = getIndex(pos);
					f.add(ind, 1);
					if (t.len % 2 == 1) {
						if (t.len > 1) {
							Segment s1 = new Segment(t.start, t.len / 2);
							Segment s2 = new Segment(pos + 1, t.len / 2);
							segments.add(s1);
							segments.add(s2);
							segmentsByX.add(s1);
							segmentsByX.add(s2);
						}
					} else {
						Segment s1 = new Segment(t.start, t.len / 2);
						segments.add(s1);
						segmentsByX.add(s1);
						if (t.len > 2) {
							Segment s2 = new Segment(pos + 1, t.len / 2 - 1);
							segments.add(s2);
							segmentsByX.add(s2);
						}
					}
				} else {
					// System.err.println("FREEING " + pos);
					int ind = getIndex(pos);
					taken.remove(qMan[i]);
					f.add(ind, -1);
					Segment ok = new Segment(pos, -1);
					Segment left = segmentsByX.lower(ok);
					if (left != null && left.start + left.len != pos) {
						left = null;
					}
					Segment right = segmentsByX.higher(ok);
					if (right != null && right.start != pos + 1) {
						right = null;
					}
					if (left != null) {
						segments.remove(left);
						segmentsByX.remove(left);
					}
					if (right != null) {
						segments.remove(right);
						segmentsByX.remove(right);
					}
					int newStart = left == null ? pos : left.start;
					int newLen = 1 + (left == null ? 0 : left.len)
							+ (right == null ? 0 : right.len);
					Segment add = new Segment(newStart, newLen);
					segments.add(add);
					segmentsByX.add(add);
				}
			}
		}
	}

	static class ByStart implements Comparator<Segment> {

		@Override
		public int compare(Segment o1, Segment o2) {
			return o1.start - o2.start;
		}
	}

	static class Segment implements Comparable<Segment> {
		@Override
		public String toString() {
			return "Segment [start=" + start + ", len=" + len + "]";
		}

		int start, len;

		public Segment(int start, int len) {
			this.start = start;
			this.len = len;
		}

		@Override
		public int compareTo(Segment o) {
			if (len != o.len)
				return len - o.len;
			return start - o.start;
		}
	}

	static class Fenwick {
		private final int[] s;

		public Fenwick(int n) {
			s = new int[n];
		}

		public int getSum(int i) {
			int res = 0;
			for (; i >= 0; i = (i & i + 1) - 1) {
				res += s[i];
			}
			return res;
		}

		public void add(int i, int val) {
			for (; i < s.length; i |= i + 1) {
				s[i] += val;
			}
		}

		public int getSum(int l, int r) {
			int res = 0;
			for (--r; r >= l; r = (r & r + 1) - 1) {
				res += s[r];
			}
			for (--l; l != r; l = (l & l + 1) - 1) {
				res -= s[l];
			}
			return res;
		}
	}

	public static void main(String[] args) {
		new D().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			st = new StringTokenizer("");
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	String nextToken() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				eof = true;
				line = "0";
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}