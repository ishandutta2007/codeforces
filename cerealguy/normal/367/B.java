import java.io.*;
import java.util.*;

public class B {

	static void solve() throws IOException {
		int aLen = nextInt();
		int bLen = nextInt();
		int step = nextInt();
		int[] a = new int[aLen];
		for (int i = 0; i < aLen; i++) {
			a[i] = nextInt();
		}
		int[] b = new int[bLen];
		for (int i = 0; i < bLen; i++) {
			b[i] = nextInt();
		}

		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		for (Integer value : b) {
			Integer have = map.get(value);
			if (have == null) {
				have = map.size();
				map.put(value, have);
			}
		}

		Integer k = map.size();
		int[] cntInB = new int[k];
		for (Integer value : b) {
			++cntInB[map.get(value)];
		}

		int[] cnt = new int[k + 1];

		List<Integer> goodQ = new ArrayList<>();
		for (int start = 0; start < step; start++) {
			if (start + (long) (bLen - 1) * (long) step >= aLen) {
				continue;
			}
			System.arraycopy(cntInB, 0, cnt, 0, cntInB.length);
			cnt[k] = 0;
			for (int i = 0; i < bLen; i++) {
				int value = a[start + i * step];
				Integer ok = map.get(value);
				if (ok == null) {
					ok = k;
				}
				--cnt[ok];
			}
			int nonZero = 0;
			for (int i = 0; i < cnt.length; i++) {
				if (cnt[i] != 0) {
					++nonZero;
				}
			}
			if (nonZero == 0) {
				goodQ.add(start);
			}

			for (int go = start + step; go + (long) (bLen - 1) * (long) step < aLen; go += step) {
				Integer remove = a[go - step];
				Integer add = a[go + (bLen - 1) * step];

				remove = map.get(remove);
				add = map.get(add);
				if (remove == null) {
					remove = k;
				}
				if (add == null) {
					add = k;
				}
				if (cnt[remove] != 0) {
					--nonZero;
				}
				if (cnt[add] != 0) {
					--nonZero;
				}
				++cnt[remove];
				--cnt[add];
				if (cnt[remove] != 0) {
					++nonZero;
				}
				if (cnt[add] != 0) {
					++nonZero;
				}
				if (nonZero == 0) {
					goodQ.add(go);
				}
			}
		}
		Collections.sort(goodQ);
		out.println(goodQ.size());
		for (int i = 0; i < goodQ.size(); i++) {
			if (i != 0) {
				out.print(' ');
			}
			out.print(goodQ.get(i) + 1);
		}
		out.println();
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("b.in");
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solve();
		out.close();
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

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
}