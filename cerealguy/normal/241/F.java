import static java.lang.Math.abs;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.fill;
import static java.util.Arrays.sort;

import java.io.*;
import java.util.*;

public class F {

	static int[] dx = { 0, 0, 1, -1 };
	static int[] dy = { 1, -1, 0, 0 };

	private static void solve() throws IOException {
		int r = nextInt(), c = nextInt();
		int time = nextInt();

		char[][] grid = new char[r][];
		for (int i = 0; i < r; i++) {
			grid[i] = nextToken().toCharArray();
		}

		// Set<Character> haveJunctions = new HashSet<Character>();
		// for (int i = 0; i < r; i++) {
		// for (int j = 0; j < c; j++) {
		// if (grid[i][j] < 'a' || grid[i][j] > 'z') {
		// continue;
		// }
		// haveJunctions.add(grid[i][j]);
		// }
		// }
		// char[] allJ = new char[haveJunctions.size()];
		// int cnt = 0;
		// for (char ch : haveJunctions) {
		// allJ[cnt++] = ch;
		// }
		// sort(allJ);
		// int cntJ = allJ.length;
		int[][][] getTo = new int[r][c][4];
		for (int[][] arr1 : getTo) {
			for (int[] arr : arr1) {
				fill(arr, -1);
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (grid[i][j] == '#') {
					continue;
				}
				// int from = binarySearch(allJ, grid[i][j]);
				for (int dir = 0; dir < dx.length; dir++) {
					int ni = i + dx[dir], nj = j + dy[dir];
					if (ni < 0 || ni >= r || nj < 0 || nj >= 'c') {
						continue;
					}
					if (grid[ni][nj] == '#') {
						continue;
					}
					while (grid[ni][nj] < 'a' || grid[ni][nj] > 'z') {
						ni += dx[dir];
						nj += dy[dir];
					}
					// int to = binarySearch(allJ, grid[ni][nj]);
					getTo[i][j][dir] = grid[ni][nj];
				}
			}
		}
		int curX = nextInt() - 1;
		int curY = nextInt() - 1;
		String input = nextToken();
		int endX = nextInt() - 1;
		int endY = nextInt() - 1;

		while (time > 0 && (input.length() > 0 || curX != endX || curY != endY)) {
			int ansDir = -1;
			if (input.length() > 0) {
				// int want = binarySearch(allJ, input.charAt(0));
				ansDir = -1;
				for (int dir = 0; dir < 4; dir++) {
					if (getTo[curX][curY][dir] == input.charAt(0)) {
						ansDir = dir;
						break;
					}
				}
			} else {
				int wantX = endX - curX;
				int wantY = endY - curY;
				wantX = Integer.signum(wantX);
				wantY = Integer.signum(wantY);
				for (int dir = 0; dir < 4; dir++) {
					if (dx[dir] == wantX && dy[dir] == wantY) {
						ansDir = dir;
						break;
					}
				}
			}
			// System.err.println(ansDir);
			// System.err.println(input+" "+curX+" "+curY+" "+Arrays.toString(getTo[curX][curY]));
			if (ansDir < 0) {
				throw new AssertionError();
			}
			if (grid[curX][curY] < 'a' || grid[curX][curY] > 'z') {
				if (time >= grid[curX][curY] - '0') {
					time -= grid[curX][curY] - '0';
				} else {
					break;
				}
			} else {
				time -= 1;
			}
			curX += dx[ansDir];
			curY += dy[ansDir];
			if (input.length() > 0 && grid[curX][curY] == input.charAt(0)) {
				input = input.substring(1);
			}
		}
		out.println(curX + 1 + " " + (curY + 1));
	}

	public static void main(String[] args) {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
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