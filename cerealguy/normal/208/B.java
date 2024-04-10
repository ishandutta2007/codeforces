import static java.lang.Math.min;
import static java.lang.System.arraycopy;
import static java.util.Arrays.copyOfRange;

import java.io.*;
import java.util.*;

public class B {

	static String TYPES = "SDHC";
	static String VALUES = "23456789TJQKA";

	static class State {
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + Arrays.hashCode(cardsOnTop);
			result = prime * result + numberOfCards;
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
			State other = (State) obj;
			if (!Arrays.equals(cardsOnTop, other.cardsOnTop))
				return false;
			if (numberOfCards != other.numberOfCards)
				return false;
			return true;
		}

		int numberOfCards;
		int[] cardsOnTop;

		private State(int numberOfCards, int[] cardsOnTop) {
			this.numberOfCards = numberOfCards;
			this.cardsOnTop = cardsOnTop;
		}

		boolean success() {
			return numberOfCards == 1;
		}

		State go1(int[] inputCards) {
			if (numberOfCards <= 1) {
				return null;
			}
			int topCard = cardsOnTop[0];
			int otherCard = cardsOnTop[1];
			if (!good(topCard, otherCard)) {
				return null;
			}
			if (cardsOnTop.length == numberOfCards) {
				int[] newTop = copyOfRange(cardsOnTop, 1, cardsOnTop.length);
				newTop[0] = topCard;
				return new State(numberOfCards - 1, newTop);
			} else {
				int[] newTop = new int[cardsOnTop.length];
				arraycopy(cardsOnTop, 1, newTop, 0, cardsOnTop.length - 1);
				newTop[cardsOnTop.length - 1] = inputCards[numberOfCards - cardsOnTop.length - 1];
				newTop[0] = topCard;
				return new State(numberOfCards - 1, newTop);
			}
		}

		State go2(int[] inputCards) {
			if (numberOfCards <= 3) {
				return null;
			}
			int topCard = cardsOnTop[0];
			int otherCard = inputCards[numberOfCards - 4];
			if (!good(topCard, otherCard)) {
				return null;
			}
			if (cardsOnTop.length == numberOfCards) {
				throw new AssertionError();
			} else {
				int[] newTop = new int[cardsOnTop.length];
				arraycopy(cardsOnTop, 1, newTop, 0, cardsOnTop.length - 1);
				newTop[cardsOnTop.length - 1] = topCard;
				return new State(numberOfCards - 1, newTop);
			}
		}
	}

	static boolean good(int card1, int card2) {
		int xor = card1 ^ card2;
		return (xor & 3) == 0 || xor < 4;
	}

	private static void solve() throws IOException {
		int n = nextInt();
		int[] inputCards = new int[n];
		for (int i = 0; i < n; i++) {
			inputCards[i] = nextCard();
		}
		out.println(yes(inputCards) ? "YES" : "NO");
	}

	static boolean yes(int[] inputCards) {
		int n = inputCards.length;
		int cnt = min(n, 3);
		int[] initialCardsOnTop = new int[cnt];
		for (int i = 0; i < cnt; i++) {
			initialCardsOnTop[i] = inputCards[n - 1 - i];
		}
//		System.err.println(Arrays.toString(inputCards));
		State initialState = new State(n, initialCardsOnTop);
		Queue<State> q = new ArrayDeque<State>();
		Set<State> visited = new HashSet<State>();
		q.add(initialState);
		visited.add(initialState);
		while (!q.isEmpty()) {
			State s = q.poll();
			if (s.success()) {
				return true;
			}
			for (State to: new State[]{s.go1(inputCards), s.go2(inputCards)}) {
				if (to == null) {
					continue;
				}
				if (!visited.contains(to)) {
					visited.add(to);
					q.add(to);
				}
			}
		}
		return false;
	}

	static int nextCard() throws IOException {
		String s = nextToken();
		int type = TYPES.indexOf(s.charAt(1));
		int value = VALUES.indexOf(s.charAt(0));
		return value * 4 + type;
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