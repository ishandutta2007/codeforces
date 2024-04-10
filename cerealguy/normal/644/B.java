import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.util.ArrayDeque;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.Collection;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int queueCapacity = in.nextInt();
        Queue<Integer> queue = new ArrayDeque<>();
        long currentTime = 0;
        long[] answer = new long[n];
        int processed = 0;
        for (int i = 0; i < n; i++) {
            int time = in.nextInt();
            int duration = in.nextInt();
            while (!queue.isEmpty() && currentTime <= time) {
                currentTime += queue.poll();
                while (answer[processed] < 0) {
                    ++processed;
                }
                answer[processed++] = currentTime;
            }
            currentTime = Math.max(currentTime, time);
            if (queue.size() < queueCapacity) {
                queue.add(duration);
            } else {
                answer[i] = -1;
            }
        }
        while (!queue.isEmpty()) {
            currentTime += queue.poll();
            while (answer[processed] < 0) {
                ++processed;
            }
            answer[processed++] = currentTime;
        }
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                out.print(' ');
            }
            out.print(answer[i]);
        }
        out.println();
    }
}

class InputReader {
    public BufferedReader br;
    StringTokenizer st;

    public InputReader(InputStream stream) {
        br = new BufferedReader(new InputStreamReader(stream));
    }

    public String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            String line = null;
            try {
                line = br.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

}