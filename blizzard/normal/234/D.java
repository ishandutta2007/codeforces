import java.util.*;
import java.io.*;

public class solve {
	BufferedReader br;
	PrintWriter out;
	StringTokenizer stok;

	String nextToken() throws IOException {
		while (stok == null || !stok.hasMoreTokens()) {
			String s = br.readLine();
			if (s == null) {
				return null;
			}
			stok = new StringTokenizer(s);
		}
		return stok.nextToken();
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

	char nextChar() throws IOException {
		return (char) (br.read());
	}

	String nextLine() throws IOException {
		return br.readLine();
	}
	
	void solve() throws IOException {
		int m = nextInt();
		int k = nextInt();
		int[] q = new int[k];
		for (int i = 0; i < k; i++) {
			q[i] = nextInt();
		}
		int n = nextInt();
		ArrayList<Integer>[] a = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			nextLine();
			int x = nextInt();
			a[i] = new ArrayList<Integer>();
			for (int j = 0; j < x; j++) {
				a[i].add(nextInt());
			}
		}
		
		int[] min = new int[n];
		int[] max = new int[n];
		for (int i = 0; i < n; i++) {
			min[i] = 0;
			max[i] = 0;
			for (int j = 0; j < a[i].size(); j++) {
				if (a[i].get(j) == 0) {
					max[i]++;
					continue;
				} 
				for (int qq = 0; qq < k; qq++) {
					if (q[qq] == a[i].get(j)) {
						max[i]++;
						min[i]++;
						break;
					}
				}
			}
			if (a[i].size() > (m - (k - min[i]))) {
				min[i] += a[i].size() - (m - (k - min[i]));
			}
			if (max[i] > k) max[i] = k;
		}
		
		int maximum = 0;
		for (int i = 0; i < n; i++) {
			maximum = Math.max(maximum, max[i]);
		}
		int maxim = 0;
		for (int i = 0; i < n; i++) {
			maxim = Math.max(maxim, min[i]);
		}
		/*if (n == 1) {
			out.println("0");
			return;
		}*/
		for (int i = 0; i < n; i++) {
			boolean fg = false;
			for (int j = 0; j < n; j++) {
				if (j == i) continue;
				if (max[j] > min[i]) fg = true;
			}
			
			if (fg == false || min[i] >= maximum) {
				out.println("0");
			} else {
				if (max[i] < maxim) {
					out.println("1");
				} else {
					out.println("2");
				}
			} 
		}
	}

	void run() throws IOException {
		//br = new BufferedReader(new FileReader("huffman.in"));
		//out = new PrintWriter("huffman.out");
		 br = new BufferedReader(new FileReader("input.txt"));
		 out = new PrintWriter("output.txt");
		// br = new BufferedReader(new InputStreamReader(System.in));
		// out = new PrintWriter(System.out);
		solve();
		br.close();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		// Localea.setDefault(Locale.US);
		new solve().run();
	}
}