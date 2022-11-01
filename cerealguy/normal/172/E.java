import java.io.*;
import java.util.*;

public class E {

	private static void solve() throws IOException {
		String document = br.readLine();
		List<Tag> tags = getTags(document);
		int queries = Integer.parseInt(br.readLine());
		while (queries-- > 0) {
			List<String> query = new ArrayList<String>();
			StringTokenizer tok = new StringTokenizer(br.readLine());
			while (tok.hasMoreTokens()) {
				query.add(tok.nextToken());
			}
			int answer = get(tags, query.toArray(new String[query.size()]));
			out.println(answer);
		}
	}

	private static int get(List<Tag> tags, String[] query) {
		int curHave = 0;
		int answer = 0;
		int curDepth = 0;
		List<Integer> depthsStack = new ArrayList<Integer>();
		for (Tag tag : tags) {
			if (tag.name.equals(query[curHave])) {
				if (curHave == query.length - 1) {
					if (tag.type >= 0) {
						++answer;
					}
				} else {
					if (tag.type > 0) {
						depthsStack.add(curDepth);
						++curHave;
					}
				}
			}
			if (tag.type < 0 && !depthsStack.isEmpty()
					&& depthsStack.get(depthsStack.size() - 1).intValue() == curDepth - 1) {
				depthsStack.remove(depthsStack.size() - 1);
				--curHave;
			}
			if (tag.type > 0) {
				++curDepth;
			}
			if (tag.type < 0) {
				--curDepth;
			}
		}
		return answer;
	}

	static List<Tag> getTags(String document) {
		List<Tag> list = new ArrayList<Tag>();
		while (!document.isEmpty()) {
			if (!document.startsWith("<")) {
				throw new AssertionError();
			}
			int close = document.indexOf('>');
			if (close < 0) {
				throw new AssertionError();
			}
			String s = document.substring(1, close);
			int type = 1;
			if (s.startsWith("/")) {
				type = -1;
				s = s.substring(1);
			} else {
				if (s.endsWith("/")) {
					type = 0;
					s = s.substring(0, s.length() - 1);
				}
			}
			list.add(new Tag(s, type));
			document = document.substring(close + 1);
		}
		return list;
	}

	static class Tag {
		String name;
		int type;

		private Tag(String name, int type) {
			this.name = name;
			this.type = type;
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