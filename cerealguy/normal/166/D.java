import static java.util.Arrays.sort;

import java.io.*;
import java.util.*;

public class D {

	private static void solve() throws IOException {
		int shoesCount = nextInt();
		Shoe[] shoes = new Shoe[shoesCount];
		for (int i = 0; i < shoesCount; i++) {
			int cost = nextInt(), size = nextInt();
			shoes[i] = new Shoe(size, cost, i);
		}
		sort(shoes);

		TreeMap<Integer, List<Customer>> customers = new TreeMap<Integer, List<Customer>>();
		int costomersCount = nextInt();
		for (int i = 0; i < costomersCount; i++) {
			int cost = nextInt(), size = nextInt();
			add(customers, size, new Customer(cost, i));
		}

		RestoreInfo[] info = new RestoreInfo[shoesCount + 1];
		RestoreInfo[] maxSuffix = new RestoreInfo[shoesCount + 1];
		info[shoesCount] = new RestoreInfo(0);
		maxSuffix[shoesCount] = info[shoesCount];
		int shoeIndex = shoesCount;

		for (Map.Entry<Integer, List<Customer>> entry : customers.descendingMap().entrySet()) {
			int size = entry.getKey();
			List<Customer> list = entry.getValue();
			Collections.sort(list, new Comparator<Customer>() {
				@Override
				public int compare(Customer o1, Customer o2) {
					return o1.money - o2.money;
				}
			});

			if (list.size() > 2) {
				list.subList(0, list.size() - 2).clear();
			}

			while (shoeIndex > 0 && shoes[shoeIndex - 1].size >= size) {
				--shoeIndex;
				maxSuffix[shoeIndex] = max(maxSuffix[shoeIndex + 1], info[shoeIndex]);
			}

			int shoeHave = -1;
			for (int i = 0; i < 2; i++) {
				int index = shoeIndex + i;
				if (index < 0 || index >= shoesCount) {
					continue;
				}
				if (shoes[index].size != size && shoes[index].size != size + 1) {
					continue;
				}
				Customer man = list.get(list.size() - 1);
				if (man.money < shoes[index].cost) {
					continue;
				}
				if (shoeHave == -1) {
					shoeHave = index;
				} else {
					shoeHave = -2;
				}
				RestoreInfo have = maxSuffix[index + 1];
				long profitMake = have.profitMake + shoes[index].cost;
				RestoreInfo willHave = new RestoreInfo(profitMake, shoes[index].id, man.id, have);
				info[index] = max(info[index], willHave);
				for (int j = index; j >= shoeIndex; --j) {
					maxSuffix[j] = max(maxSuffix[j], willHave);
				}
			}

			if (shoeHave == -2 && list.size() == 2) {
				Shoe one = shoes[shoeIndex], two = shoes[shoeIndex + 1];
				if (one.cost > two.cost) {
					Shoe t = one;
					one = two;
					two = t;
				}
				Customer manOne = list.get(0), manTwo = list.get(1);
				if (one.cost <= manOne.money && two.cost <= manTwo.money) {
					RestoreInfo have = maxSuffix[shoeIndex + 2];
					long profitMake = have.profitMake + one.cost + two.cost;
					RestoreInfo willHave1 = new RestoreInfo(have.profitMake + two.cost, two.id,
							manTwo.id, have);
					RestoreInfo willHave = new RestoreInfo(profitMake, one.id, manOne.id, willHave1);
					info[shoeIndex] = max(info[shoeIndex], willHave);
					maxSuffix[shoeIndex] = max(maxSuffix[shoeIndex], willHave);
				}
			}
		}
		RestoreInfo answer = maxSuffix[shoeIndex];
		List<Integer> shoesRestore = new ArrayList<Integer>();
		List<Integer> customersRestore = new ArrayList<Integer>();
		long answerMoney = answer.profitMake;
		while (answer.nextShoe != null) {
			shoesRestore.add(answer.thisShoe);
			customersRestore.add(answer.thisMan);
			answer = answer.nextShoe;
		}
		out.println(answerMoney);
		out.println(shoesRestore.size());
		for (int i = 0; i < shoesRestore.size(); i++) {
			out.print(customersRestore.get(i) + 1);
			out.print(' ');
			out.print(shoesRestore.get(i) + 1);
			out.println();
		}
	}

	static RestoreInfo max(RestoreInfo one, RestoreInfo two) {
		if (one == null) {
			return two;
		}
		if (two == null) {
			return one;
		}
		if (one.profitMake <= two.profitMake) {
			return two;
		} else {
			return one;
		}
	}

	static class RestoreInfo {
		long profitMake;
		int thisShoe;
		int thisMan;
		RestoreInfo nextShoe;

		private RestoreInfo(long profitMake, int thisShoe, int thisMan, RestoreInfo nextShoe) {
			this.profitMake = profitMake;
			this.thisShoe = thisShoe;
			this.nextShoe = nextShoe;
			this.thisMan = thisMan;
		}

		private RestoreInfo(long profitMake) {
			this.profitMake = profitMake;
			this.thisShoe = -1;
			this.thisMan = -1;
			this.nextShoe = null;
		}
	}

	static class Shoe implements Comparable<Shoe> {
		final int size, cost, id;

		private Shoe(int size, int cost, int id) {
			this.size = size;
			this.cost = cost;
			this.id = id;
		}

		@Override
		public int compareTo(Shoe o) {
			return size - o.size;
		}
	}

	static <K, T> void add(Map<K, List<T>> map, K key, T value) {
		List<T> list = map.get(key);
		if (list == null) {
			list = new ArrayList<T>();
			map.put(key, list);
		}
		list.add(value);
	}

	static class Customer {
		final int money;
		final int id;

		private Customer(int size, int id) {
			this.money = size;
			this.id = id;
		}

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