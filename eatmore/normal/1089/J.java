import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;

public class J {

	static boolean startsWith(CharSequence big, String small, int pos) {
		if (small.length() + pos > big.length()) {
			return false;
		}
		for (int i = 0; i < small.length(); i++) {
			if (small.charAt(i) != big.charAt(pos + i)) {
				return false;
			}
		}
		return true;
	}

	static boolean isDigit(char c) {
		return c >= '0' && c <= '9';
	}

	static boolean isWordChar(char c) {
		return c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c == '_' || c == '$';
	}

	static int tokenLengthAt(CharSequence str, int pos) {
		int tokenLength = 0;
		for (int i = 0; i < nRes; i++) {
			if (startsWith(str, res[i], pos)) {
				tokenLength = max(tokenLength, res[i].length());
			}
		}
		if (str.length() > pos) {
			char c = str.charAt(pos);
			if (isDigit(c)) {
				int i;
				for (i = pos + 1; i < str.length() && isDigit(str.charAt(i)); i++) { }
				tokenLength = max(tokenLength, i - pos);
			} else if (isWordChar(c)) {
				int i;
				for (i = pos + 1; i < str.length() && isWordChar(str.charAt(i)); i++) { }
				tokenLength = max(tokenLength, i - pos);
			}
		}
		return tokenLength;
	}

	static String res[];
	static int nRes;

	static void solve() throws Exception {
		nRes = scanInt();
		res = new String[nRes];
		for (int i = 0; i < nRes; i++) {
			res[i] = scanString();
		}
		int nLines = scanInt();
		List<String> tokens = new ArrayList<>();
		for (int i = 0; i < nLines; i++) {
			String line = in.readLine();
			for (int j = 0; j < line.length();) {
				char c = line.charAt(j);
				if (c == ' ') {
					++j;
					continue;
				} else if (c == '#') {
					break;
				}
				int tokenLength = tokenLengthAt(line, j);
				if (tokenLength == 0) {
					throw new AssertionError();
				}
				tokens.add(line.substring(j, j + tokenLength));
				j += tokenLength;
			}
		}
		Set<String> resSet = new HashSet<>();
		Map<String, String> tokenMap = new HashMap<>();
		for (int i = 0; i < nRes; i++) {
			resSet.add(res[i]);
			tokenMap.put(res[i], res[i]);
		}
		StringBuilder cur = new StringBuilder();
		List<Integer> curPoints = new ArrayList<>();
		List<Integer> curLengths = new ArrayList<>();
		char curRepl[] = new char[0];
		for (String tok: tokens) {
			String repl;
			if (isDigit(tok.charAt(0))) {
				repl = tok;
			} else {
				repl = tokenMap.get(tok);
				if (repl == null) {
					String curReplStr;
					do {
						for (int i = curRepl.length - 1;; i--) {
							if (i < 0) {
								curRepl = new char[curRepl.length + 1];
								fill(curRepl, 'a');
								break;
							}
							if (curRepl[i] != 'z') {
								++curRepl[i];
								for (++i; i < curRepl.length; i++) {
									curRepl[i] = 'a';
								}
								break;
							}
						}
						curReplStr = new String(curRepl);
					} while (resSet.contains(curReplStr));
					tokenMap.put(tok, repl = curReplStr);
				}
			}
			int pos = cur.length();
			cur.append(repl);
			for (int i = 0, l = curPoints.size(); i < l; i++) {
				if (tokenLengthAt(cur, curPoints.get(i)) != curLengths.get(i)) {
					out.write(cur.toString(), 0, pos);
					out.write(' ');
					cur.delete(0, pos);
					curPoints.clear();
					curLengths.clear();
					pos = 0;
					break;
				}
			}
			curPoints.add(pos);
			curLengths.add(repl.length());
		}
		if (cur.length() != 0) {
			out.write(cur.toString());
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