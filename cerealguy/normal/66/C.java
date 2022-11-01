import java.io.*;
import java.util.*;

public class C {

	private void solve() throws IOException {
		disks = new HashMap<String, C.Tree>();
		while (true) {
			String s = nextToken();
			if (eof)
				break;
			addPath(s);
		}
		int maxFolder = 0;
		int maxFile = 0;
		for (Tree t : disks.values()) {
			t.calc();
			for (Tree t1 : t.hm.values()) {
				maxFolder = Math.max(maxFolder, t1.foldercnt);
				maxFile = Math.max(maxFile, t1.filecnt);
			}
		}
		out.println(maxFolder + " " + maxFile);
	}

	void addPath(String path) {
		StringTokenizer st = new StringTokenizer(path, "\\");
		String disk = st.nextToken();
		Tree t = disks.get(disk);
		if (t == null) {
			t = new Tree();
			disks.put(disk, t);
		}
		while (st.hasMoreTokens()) {
			String s = st.nextToken();
			if (st.hasMoreTokens()) {
				t = t.add(s);
			} else {
				t.filecnt++;
			}
		}
	}

	HashMap<String, Tree> disks;

	static class Tree {
		HashMap<String, Tree> hm;
		int filecnt;
		int foldercnt;

		public Tree() {
			hm = new HashMap<String, C.Tree>();
		}

		Tree add(String folder) {
			Tree t = hm.get(folder);
			if (t == null) {
				t = new Tree();
				hm.put(folder, t);
			}
			return t;
		}

		void calc() {
			for (Tree t : hm.values()) {
				t.calc();
				foldercnt += t.foldercnt + 1;
				filecnt += t.filecnt;
			}
		}
	}

	public static void main(String[] args) {
		new C().run();
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	boolean eof = false;

	public void run() {
		Locale.setDefault(Locale.US);
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