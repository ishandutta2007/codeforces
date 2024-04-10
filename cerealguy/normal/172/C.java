import static java.lang.Math.max;
import static java.lang.Math.min;

import java.io.*;
import java.util.*;

public class C {

	private static void solve() throws IOException {
		int n = nextInt(), seats = nextInt();
		Student[] men = new Student[n];
		for (int i = 0; i < n; i++) {
			men[i] = new Student(nextInt(), nextInt(), i);
		}

		List<Student> passengers = new ArrayList<Student>();
		Comparator<Student> comparator = new Comparator<Student>() {
			@Override
			public int compare(Student o1, Student o2) {
				return o1.whereWants - o2.whereWants;
			}
		};
		long curTime = 0;
		for (int curStudent = 0; curStudent < n; curStudent += seats) {
			for (int i = curStudent; i < min(n, curStudent + seats); i++) {
				passengers.add(men[i]);
				curTime = max(curTime, men[i].timeCame);
			}
			Collections.sort(passengers, comparator);
			int index = 0;
			int lastPosition = 0;
			for (; index < passengers.size(); ) {
				Student man = passengers.get(index);
				int indexTo = index + 1;
				while (indexTo < passengers.size()
						&& passengers.get(indexTo).whereWants == man.whereWants) {
					indexTo++;
				}
				curTime += man.whereWants - lastPosition;
				for (int i = index; i < indexTo; i++) {
					passengers.get(i).answer = curTime;
				}
				curTime += 1 + (indexTo - index) / 2;
				index = indexTo;
				lastPosition = man.whereWants;
			}
			curTime += lastPosition;
			passengers.clear();
		}
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				out.print(' ');
			}
			out.print(men[i].answer);
		}

	}

	static class Student {
		int timeCame;
		int whereWants;
		int id;
		long answer;

		private Student(int timeCame, int whereWants, int id) {
			this.timeCame = timeCame;
			this.whereWants = whereWants;
			this.id = id;
			this.answer = 0;
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