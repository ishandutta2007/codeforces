import java.io.*;
import java.util.*;

public class E {

	static void solve() throws IOException {
		int n = nextInt(), queries = nextInt();
		TreeSet<ParkingSegment> byPos = new TreeSet<>(
				new Comparator<ParkingSegment>() {
					@Override
					public int compare(ParkingSegment o1, ParkingSegment o2) {
						int cmp = o1.pos - o2.pos;
						return cmp;
					}
				});
		TreeSet<ParkingSegment> bySize = new TreeSet<>(
				new Comparator<ParkingSegment>() {
					@Override
					public int compare(ParkingSegment o1, ParkingSegment o2) {
						int cmp = (o2.size - 1) / 2 - (o1.size - 1) / 2;
						if (cmp != 0) {
							return cmp;
						}
						return o1.pos - o2.pos;
					}
				});
		ParkingSegment initial = new ParkingSegment(0, n);
		byPos.add(initial);
		bySize.add(initial);
		Map<Integer, Integer> whereIsMan = new HashMap<Integer, Integer>();
		for (int query = 0; query < queries; query++) {
			// debug(byPos);
			int type = nextInt(), man = nextInt();
			if (type == 1) {
				int manArrives = manArrives(n, byPos, bySize, whereIsMan, man);
				out.println(manArrives + 1);
			} else {
				manLeaves(n, byPos, bySize, whereIsMan, man);
			}
		}
	}

	// private static void debug(TreeSet<ParkingSegment> ts) {
	// for (ParkingSegment s : ts) {
	// System.err
	// .print("[" + s.pos + ", " + (s.pos + s.size) + ")" + "; ");
	// }
	// System.err.println();
	// }

	private static void manLeaves(int n, TreeSet<ParkingSegment> byPos,
			TreeSet<ParkingSegment> bySize, Map<Integer, Integer> whereIsMan,
			int man) {
		int manPos = whereIsMan.remove(man);
		ParkingSegment tmp = new ParkingSegment(manPos, 0);
		ParkingSegment left = byPos.lower(tmp);
		ParkingSegment right = byPos.higher(tmp);
		if (right != null && right.pos > manPos + 1) {
			right = null;
		}
		if (left != null && left.pos + left.size < manPos) {
			left = null;
		}
		if (left != null) {
			bySize.remove(left);
			byPos.remove(left);
		}
		if (right != null) {
			bySize.remove(right);
			byPos.remove(right);
		}
		if (left != null && right != null) {
			ParkingSegment to = new ParkingSegment(left.pos, left.size
					+ right.size + 1);
			bySize.add(to);
			byPos.add(to);
			return;
		}
		if (left == null && right != null) {
			ParkingSegment to = new ParkingSegment(right.pos - 1,
					right.size + 1);
			bySize.add(to);
			byPos.add(to);
			return;
		}
		if (left != null && right == null) {
			ParkingSegment to = new ParkingSegment(left.pos, left.size + 1);
			bySize.add(to);
			byPos.add(to);
			return;
		}
		ParkingSegment to = new ParkingSegment(manPos, 1);
		bySize.add(to);
		byPos.add(to);
	}

	private static int manArrives(int n, TreeSet<ParkingSegment> byPos,
			TreeSet<ParkingSegment> bySize, Map<Integer, Integer> whereIsMan,
			int man) {
		ParkingSegment segment = getParkingSegment(n, byPos, bySize,
				whereIsMan, man);
		int manPos;
		if (segment.pos == 0) {
			manPos = 0;
		} else {
			if (segment.pos + segment.size == n) {
				manPos = n - 1;
			} else {
				manPos = segment.pos + (segment.size - 1) / 2;
			}
		}
		whereIsMan.put(man, manPos);
		ParkingSegment s1 = new ParkingSegment(segment.pos, manPos
				- segment.pos);
		ParkingSegment s2 = new ParkingSegment(manPos + 1, segment.pos
				+ segment.size - manPos - 1);
		byPos.remove(segment);
		bySize.remove(segment);
		for (ParkingSegment s : new ParkingSegment[] { s1, s2 }) {
			if (s.size > 0) {
				byPos.add(s);
				bySize.add(s);
			}
		}
		return manPos;
	}

	private static ParkingSegment getParkingSegment(int n,
			TreeSet<ParkingSegment> byPos, TreeSet<ParkingSegment> bySize,
			Map<Integer, Integer> whereIsMan, int man) {
		ParkingSegment best = null;
		int bestDist = Integer.MIN_VALUE;
		case1: {
			ParkingSegment p = byPos.first();
			if (p.pos != 0) {
				break case1;
			}
			int dist = p.size - 1;
			if (bestDist < dist) {
				bestDist = dist;
				best = p;
			}
		}
		case2: {
			ParkingSegment p = bySize.first();
			if (p.pos == 0 || p.pos + p.size == n) {
				break case2;
			}
			int dist = (p.size - 1) / 2;
			if (bestDist < dist) {
				bestDist = dist;
				best = p;
			}
		}
		case3: {
			ParkingSegment p = byPos.last();
			if (p.pos + p.size != n) {
				break case3;
			}
			int dist = p.size - 1;
			if (bestDist < dist) {
				bestDist = dist;
				best = p;
			}
		}
		return best;
	}

	static class ParkingSegment {
		final int pos, size;

		public ParkingSegment(int pos, int size) {
			this.pos = pos;
			this.size = size;
		}
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static String nextToken() throws IOException {
		return hasNextToken() ? st.nextToken() : null;
	}

	static boolean hasNextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return false;
			}
			st = new StringTokenizer(line);
		}
		return true;
	}

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		File inputFile = new File("fn.in");
		if (inputFile.canRead()) {
			input = new FileInputStream(inputFile);
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(System.out);
		solve();
		br.close();
		out.close();
	}
}