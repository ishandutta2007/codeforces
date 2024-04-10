import static java.lang.Math.min;

import java.io.*;
import java.util.*;

public class C {

	static String[] types = { "weapon", "armor", "orb" };
	static String[] bonusTypes = { "gladiator", "sentry", "physician" };

	private void solve() throws IOException {
		int n = nextInt();
		Map<String, Item> hm = new HashMap<String, Item>();
		ArrayList<Item> items[] = new ArrayList[3];
		ArrayList<Bonus> bonuses[] = new ArrayList[3];
		for (int i = 0; i < 3; i++) {
			items[i] = new ArrayList<Item>();
			bonuses[i] = new ArrayList<Bonus>();
		}
		int capacity = 0;
		for (int i = 0; i < n; i++) {
			String name = nextToken();
			String type = nextToken();
			int typeId = -1;
			for (int j = 0; j < 3; j++) {
				if (types[j].equals(type)) {
					typeId = j;
				}
			}
			int score = -1;
			for (int j = 0; j < 3; j++) {
				int a = nextInt();
				if (typeId == j) {
					score = a;
				}
			}
			int size = nextInt();
			Item item = new Item(name, score, size);
			items[typeId].add(item);
			capacity += size;
			hm.put(name, item);
		}

		int k = nextInt();
		for (int i = 0; i < k; i++) {
			String name = nextToken();
			String type = nextToken();
			int typeId = -1;
			for (int j = 0; j < 3; j++) {
				if (bonusTypes[j].equals(type)) {
					typeId = j;
				}
			}
			int score = nextInt();
			String home = nextToken();
			Item item = hm.get(home);
			Bonus bonus = new Bonus(name, score, typeId);
			bonuses[typeId].add(bonus);
			item.residents.add(bonus);
		}
		if (capacity == k) {
			Item[] best = new Item[3];
			for (int i = 0; i < 3; i++) {
				Item ok = null;
				int okScore = Integer.MIN_VALUE;
				for (Item it : items[i]) {
					int score = it.calcScore(i);
					if (score > okScore) {
						ok = it;
						okScore = score;
					}
				}
				best[i] = ok;
			}
			outputResult(best);
			return;
		}

		for (int i = 0; i < 3; i++) {
			Collections.sort(bonuses[i]);
		}

		for (List<Item> list : items) {
			for (Item it : list) {
				it.residents.clear();
			}
		}
		Item[] best = new Item[3];
		for (int i = 0; i < 3; i++) {
			best[i] = bestItem(items[i], bonuses[i]);
		}
		for (Item it : best) {
			ok: while (it.hasSpace()) {
				for (ArrayList<Bonus> list : bonuses) {
					if (!list.isEmpty()) {
						it.residents.add(list.remove(list.size() - 1));
						continue ok;
					}
				}
				break;
			}
		}
		outputResult(best);
	}

	static Item bestItem(List<Item> items, ArrayList<Bonus> bonuses) {
		Item best = null;
		int bestScore = Integer.MIN_VALUE;
		int[] s = new int[bonuses.size() + 1];
		int cnt = 0;
		for (Bonus b : bonuses) {
			s[cnt + 1] = s[cnt] + b.score;
			++cnt;
		}
		for (Item it : items) {
			int put = min(bonuses.size(), it.size);
			int profit = s[put] + it.score;
			if (profit > bestScore) {
				bestScore = profit;
				best = it;
			}
		}

		int put = min(bonuses.size(), best.size);
		best.residents.clear();
		for (int i = 0; i < put; i++) {
			best.residents.add(bonuses.get(i));
		}
		List<Bonus> newbonuses = new ArrayList<Bonus>(bonuses.subList(put, bonuses.size()));
		bonuses.clear();
		bonuses.addAll(newbonuses);
		return best;
	}

	static void outputResult(Item[] items) {
		for (int i = 0; i < 3; i++) {
			String name = items[i].name;
			out.print(name + " " + items[i].residents.size());
			for (Bonus b : items[i].residents) {
				out.print(" " + b.name);
			}
			out.println();
		}
	}

	static class Item {
		String name;
		int score, size;
		ArrayList<Bonus> residents = new ArrayList<C.Bonus>();

		public Item(String name, int score, int size) {
			this.name = name;
			this.score = score;
			this.size = size;
			residents = new ArrayList<C.Bonus>();
		}

		int calcScore(int type) {
			int res = score;
			for (Bonus b : residents) {
				if (b.type == type) {
					res += b.score;
				}
			}
			return res;
		}

		boolean hasSpace() {
			return residents.size() < size;
		}
	}

	static class Bonus implements Comparable<Bonus> {
		String name;
		int score, type;

		public Bonus(String name, int score, int type) {
			this.name = name;
			this.score = score;
			this.type = type;
		}

		@Override
		public int compareTo(Bonus o) {
			return o.score - score;
		}
	}

	public static void main(String[] args) {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			new C().solve();
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