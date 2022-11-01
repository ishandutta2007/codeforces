import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class E {

	static void solve() throws IOException {
		int n = nextInt();
		int[] parentEdge = new int[n];
		int[] head = new int[n];
		fill(head, -1);
		int[] next = new int[n - 1];
		int[] to = new int[n - 1];
		String[] string = new String[n - 1];
		int edges = 0;

		parentEdge[0] = -1;
		for (int i = 1; i < n; i++) {
			int p = nextInt() - 1;
			String s = nextToken();
			parentEdge[i] = edges;
			next[edges] = head[p];
			to[edges] = i;
			string[edges] = s;
			head[p] = edges++;
		}

		String query = nextToken();
		int[] prefix = prefix(query);

		int[][] automata = new int[26][prefix.length];
		for (int i = 0; i < 26; i++) {
			automata[i][0] = 0;
		}
		automata[query.charAt(0) - 'a'][0] = 1;
		for (int c = 0; c < 26; c++) {
			int[] auto = automata[c];
			char cc = (char) (c + 'a');
			for (int match = 1; match < prefix.length; match++) {
				if (match < query.length() && query.charAt(match) == cc) {
					auto[match] = match + 1;
				} else {
					auto[match] = auto[prefix[match]];
				}
			}
		}

		ArrayList<State> stack = new ArrayList<>();
		stack.add(new State(0, 0));
		StringBuilder currentString = new StringBuilder();

		int answer = 0;
		while (!stack.isEmpty()) {
			State state = stack.remove(stack.size() - 1);
			if (state.match < 0) {
				int remove = string[parentEdge[state.u]].length();
				currentString.setLength(currentString.length() - remove);
			} else {
				int match = state.match;
				int endPos = currentString.length();
				if (state.u > 0) {
					currentString.append(string[parentEdge[state.u]]);
				}
				while (endPos < currentString.length()) {
					char add = currentString.charAt(endPos++);
					match = automata[add - 'a'][match];
					if (match == query.length()) {
						++answer;
					}
				}

				if (state.u > 0) {
					stack.add(new State(state.u, -1));
				}

				for (int edge = head[state.u]; edge >= 0; edge = next[edge]) {
					stack.add(new State(to[edge], match));
				}
			}
		}
		out.println(answer);
	}

	static class State {
		int u;
		int match;

		public State(int u, int match) {
			this.u = u;
			this.match = match;
		}
	}

	public static int[] prefix(String s) {
		int[] p = new int[s.length() + 1];
		p[0] = -1;
		for (int i = 1, k = 0; i < s.length(); i++) {
			while (k >= 0 && s.charAt(i) != s.charAt(k))
				k = p[k];
			p[i + 1] = ++k;
		}
		return p;
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("e.in");
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