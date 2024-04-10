import static java.lang.Math.abs;
import static java.lang.Math.max;

import java.io.*;
import java.util.*;

public class E {

	private void solve() throws IOException {
		int[] abc = new int[3];
		for (int i = 0; i < 3; i++) {
			abc[i] = nextInt();
			moveDistance[i] = nextInt();
			throwDistance[i] = nextInt();
		}
		Position init = new Position(abc[0], abc[1], abc[2], 511, 0);
		queue.add(init);
		visited.add(init);
		best = Integer.MIN_VALUE;
		// long time = System.currentTimeMillis();
		bfs();
		// System.err.println(visited.size());
		// System.err.println(System.currentTimeMillis() - time);
		out.println(best);
	}

	static Queue<Position> queue = new ArrayDeque<E.Position>();
	static HashSet<Position> visited = new HashSet<E.Position>();
	static Position temp = new Position(0, 0, 0, 0, 0);
	static int[] moveDistance = new int[3];
	static int[] throwDistance = new int[3];
	static int best;

	static int[] array = new int[3];

	static boolean containedInArray(int i) {
		return array[0] == i || array[1] == i || array[2] == i;
	}

	static void bfs() {
		while (!queue.isEmpty()) {
			Position p = queue.poll();
			p.copyTo(temp);
			for (int i = 0; i < 3; i++) {
				array[i] = p.getPos(i);
				best = max(best, array[i]);
			}

			for (int manMoving = 0; manMoving < 3; manMoving++) {
				int pos = temp.getPos(manMoving);
				int holding = ((temp.holding123 >> 2 * manMoving) & 3) - 1;
				if (beingHeld(temp.holding123, manMoving)) {
					continue;
				}

				if (holding == -1 && !bit(temp.movesMask, 3 * manMoving + 1)) {
					if (bit(temp.movesMask, (3 * manMoving))) {
						best = max(best, pos + moveDistance[manMoving]);
						continue;
					}
				}

				if (holding == -1 && bit(temp.movesMask, (3 * manMoving))) {
					temp.movesMask ^= 1 << 3 * manMoving;
					for (int i = max(pos - moveDistance[manMoving], 1); i <= pos
							+ moveDistance[manMoving]; i++) {
						if (containedInArray(i)) {
							continue;
						}
						temp.setPosition(manMoving, i);
						if (!visited.contains(temp)) {
							Position t = temp.copy();
							visited.add(t);
							queue.add(t);
						}
					}
					temp.setPosition(manMoving, pos);
					temp.movesMask ^= 1 << 3 * manMoving;
				}

				if (holding != -1 && bit(temp.movesMask, 3 * manMoving + 1)) {
					temp.movesMask ^= 1 << 3 * manMoving + 1;
					temp.holding123 ^= (holding + 1) << 2 * manMoving;
					int otherManHolds = ((temp.holding123 >> 2 * holding) & 3) - 1;
					for (int i = max(pos - throwDistance[manMoving], 1); i <= pos
							+ throwDistance[manMoving]; i++) {
						if (containedInArray(i)) {
							continue;
						}
						temp.setPosition(holding, i);
						if (otherManHolds != -1) {
							temp.setPosition(otherManHolds, i);
						}
						if (!visited.contains(temp)) {
							Position t = temp.copy();
							visited.add(t);
							queue.add(t);
						}
					}
					if (otherManHolds != -1) {
						temp.setPosition(otherManHolds, pos);
					}
					temp.holding123 ^= (holding + 1) << 2 * manMoving;
					temp.setPosition(holding, pos);
					temp.movesMask ^= 1 << 3 * manMoving + 1;
				}

				if (bit(temp.movesMask, 3 * manMoving + 2)) {
					temp.movesMask ^= 1 << 3 * manMoving + 2;
					for (int i = 0; i < 3; i++) {
						if (i == manMoving) {
							continue;
						}
						int oldpos = temp.getPos(i);
						if (abs(oldpos - pos) != 1) {
							continue;
						}
						if (beingHeld(temp.holding123, i)) {
							continue;
						}
						temp.holding123 ^= (i + 1) << (2 * manMoving);
						temp.setPosition(i, pos);
						if (!visited.contains(temp)) {
							Position t = temp.copy();
							visited.add(t);
							queue.add(t);
						}
						temp.holding123 ^= (i + 1) << (2 * manMoving);
						temp.setPosition(i, oldpos);
					}
					temp.movesMask ^= 1 << 3 * manMoving + 2;
				}
			}
		}
	}

	static boolean beingHeld(int holding, int man) {
		++man;
		if (man == (holding & 3))
			return true;
		if (man == ((holding >> 2) & 3))
			return true;
		if (man == ((holding >> 4) & 3))
			return true;
		return false;
	}

	static boolean bit(int mask, int bit) {
		return (mask & (1 << bit)) != 0;
	}

	static class Position {
		int a, b, c;
		int movesMask;
		int holding123;

		void setPosition(int man, int pos) {
			if (man == 0) {
				a = pos;
			} else {
				if (man == 1) {
					b = pos;
				} else {
					c = pos;
				}
			}
		}

		int getPos(int manMoving) {
			return manMoving == 0 ? a : manMoving == 1 ? b : c;
		}

		Position() {
		}

		Position copy() {
			Position res = new Position();
			copyTo(res);
			return res;
		}

		public Position(int a, int b, int c, int movesMask, int holding123) {
			this.a = a;
			this.b = b;
			this.c = c;
			this.movesMask = movesMask;
			this.holding123 = holding123;
		}

		void copyTo(Position to) {
			to.a = a;
			to.b = b;
			to.c = c;
			to.movesMask = movesMask;
			to.holding123 = holding123;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + a;
			result = prime * result + b;
			result = prime * result + c;
			result = prime * result + holding123;
			result = prime * result + movesMask;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Position other = (Position) obj;
			if (a != other.a)
				return false;
			if (b != other.b)
				return false;
			if (c != other.c)
				return false;
			if (holding123 != other.holding123)
				return false;
			if (movesMask != other.movesMask)
				return false;
			return true;
		}
	}

	public static void main(String[] args) {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			new E().solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}