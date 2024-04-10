import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        static int[] dx = {1, 1, 0, -1, -1, -1, 0, 1};
        static int[] dy = {0, 1, 1, 1, 0, -1, -1, -1};

        public void solve(int testNumber, InputReader in, PrintWriter out) {

            int n = in.nextInt();
            int[] t = new int[n];
            for (int i = 0; i < n; i++) {
                t[i] = in.nextInt();
            }
            int maxDistance = 0;
            for (int i = 0; i < n; i++) {
                maxDistance += t[i];
            }
            int size = 2 * maxDistance + 1;
            boolean[][] wasVisited = new boolean[size][size];
            int[][] isEndpoint = new int[size][size];
            isEndpoint[maxDistance - dx[0]][maxDistance - dy[0]] = 1;
            int[][] isEndpointNext = new int[size][size];

            for (int it = 0; it < n; it++) {
                for (int[] arr : isEndpointNext) {
                    Arrays.fill(arr, 0);
                }
                for (int x = 0; x < size; x++) {
                    for (int y = 0; y < size; y++) {
                        if (isEndpoint[x][y] == 0) {
                            continue;
                        }
                        for (int dir = 0; dir < dx.length; dir++) {
                            if ((isEndpoint[x][y] & (1 << dir)) == 0) {
                                continue;
                            }
                            int steps = t[it];
                            int to1 = (dir + 1) % dx.length;
                            int to2 = (dir + dx.length - 1) % dx.length;
                            int curX = x;
                            int curY = y;
                            for (int step = 0; step < steps; step++) {
                                curX += dx[dir];
                                curY += dy[dir];
                                wasVisited[curX][curY] = true;
                            }
                            isEndpointNext[curX][curY] |= 1 << to1;
                            isEndpointNext[curX][curY] |= 1 << to2;
                        }
                    }
                }
                int[][] tmp = isEndpoint;
                isEndpoint = isEndpointNext;
                isEndpointNext = tmp;
            }
            int answer = 0;
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (wasVisited[i][j]) {
                        ++answer;
                    }
                }
            }
            out.println(answer);
        }

    }

    static class InputReader {
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
}