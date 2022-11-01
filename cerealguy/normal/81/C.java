import java.io.*;
import java.util.*;

public class C {

	static class Mark {
		int value, id;

		public Mark(int value, int id) {
			this.value = value;
			this.id = id;
		}
	}

	static int a, b;

	private void solve() throws IOException {
		int n = nextInt();
		a = nextInt();
		b = nextInt();
		Mark[] marks = new Mark[n];
		for (int i = 0; i < n; i++) {
			marks[i] = new Mark(nextInt(), i);
		}
		if (a == b) {
			for (int i = 0; i < a; i++) {
				out.print(1 + " ");
			}
			for (int i = 0; i < a; i++) {
				out.print(2 + " ");
			}
			out.println();
			return;
		}
		Arrays.sort(marks, new Comparator<Mark>() {

			public int compare(Mark o1, Mark o2) {
				if (o1.value != o2.value)
					return o1.value - o2.value;
				if (a > b) {
					return o1.id - o2.id;
				} else {
					return o2.id - o1.id;
				}
			}
		});
		int[] res = new int[n];
		if (a > b) {
			Arrays.fill(res, 2);
			for (int i = 0; i < a; i++) {
				res[marks[i].id] = 1;
			}
		} else {
			Arrays.fill(res, 1);
			for (int i = 0; i < b; i++) {
				res[marks[i].id] = 2;
			}
		}
		for (int i = 0; i < n; i++) {
			out.print(res[i] + " ");
		}
		out.println();
	}

	public static void main(String[] args) {
		new C().run();
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