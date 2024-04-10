import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class A {

	static void solve() throws Exception {
		int da[][][][] = new int[4][4][201][201];
		int db[][][][] = new int[4][4][201][201];
		for (int sa = 0; sa < 3; sa++) {
			for (int sb = 0; sb < 3; sb++) {
				int cda[][] = da[sa][sb];
				int cdb[][] = db[sa][sb];
				for (int pa = 0; pa <= 200; pa++) {
					for (int pb = 0; pb <= 200; pb++) {
						int ccda = cda[pa][pb];
						int ccdb = cdb[pa][pb];
						if (sa == 0 && sb == 0 && (pa != 0 || pb != 0)) {
							continue;
						}
						if ((sa != 0 || sb != 0) && ccda == 0 && ccdb == 0) {
							continue;
						}
						int es = sa == 2 && sb == 2 ? 15 : 25;
						for (int apb = 0; pb + apb <= 200; apb++) {
							int apa = max(apb + 2, es);
							if (pa + apa <= 200) {
								da[sa + 1][sb][pa + apa][pb + apb] = apa;
								db[sa + 1][sb][pa + apa][pb + apb] = apb;
							}
						}
						for (int apa = 0; pa + apa <= 200; apa++) {
							int apb = max(apa + 2, es);
							if (pb + apb <= 200) {
								da[sa][sb + 1][pa + apa][pb + apb] = apa;
								db[sa][sb + 1][pa + apa][pb + apb] = apb;
							}
						}
					}
				}
			}
		}
		int tests = scanInt();
		List<Integer> ans = new ArrayList<>();
		test: for (int test = 0; test < tests; test++) {
			int pa = scanInt(), pb = scanInt();
			for (int sa = 3; sa >= 0; sa--) {
				for (int sb = 0; sb <= 3; sb++) {
					if (sa < 3 && sb < 3) {
						continue;
					}
					int cda = da[sa][sb][pa][pb];
					int cdb = db[sa][sb][pa][pb];
					if (cda == 0 && cdb == 0) {
						continue;
					}
					out.println(sa + ":" + sb);
					ans.clear();
					while (sa > 0 || sb > 0) {
						ans.add(cda);
						ans.add(cdb);
						pa -= cda;
						pb -= cdb;
						if (cda > cdb) {
							--sa;
						} else {
							--sb;
						}
						cda = da[sa][sb][pa][pb];
						cdb = db[sa][sb][pa][pb];
					}
					for (int i = ans.size() - 2; i >= 0; i -= 2) {
						out.print(ans.get(i) + ":" + ans.get(i + 1) + " ");
					}
					out.println();
					continue test;
				}
			}
			out.println("Impossible");
		}
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}