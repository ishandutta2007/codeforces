import static java.lang.System.currentTimeMillis;

import java.io.*;
import java.util.*;

public class D {

    static void solve() throws IOException {
        // while (true) {
        // testWithVsWithout();
        // if (false) {
        // break;
        // }
        // }
        // test();
        int n = nextInt(), m = nextInt();
//      long time = currentTimeMillis();
        long answer = solve(n, m);
//      System.err.println(currentTimeMillis() - time);
        out.println(answer);
    }

    static void test() {
        for (int n = 1; n < 100; n++) {
            for (int m = 0; 2 * m <= n; m++) {
                long got = solve(n, m);
                long stup = solveStupid(n, m);
                if (got != stup) {
                    throw new AssertionError();
                }
            }
        }
        System.err.println("pass");
    }

    static void testWithVsWithout() {
        Random rng = new Random();
        int n = rng.nextInt(32001);
        while (n < 5) {
            n = rng.nextInt(32001);
        }
        int m = rng.nextInt(n / 2);
        long got = solve(n, m);
        long stup = solveWithoutOptimizations(n, m);
        if (got != stup) {
            throw new AssertionError();
        }
        System.err.println("pass");
    }

    private static long solve(int n, int m) {
        Point[] pointsLeft = new Point[n];
        Point[] pointsRight = new Point[n];
        for (int i = 0; i < n; i++) {
            pointsLeft[i] = new Point((i + 1) * 2, (i + 1) * 2);
            pointsRight[i] = new Point(4 * (n + 1) - (i + 1) * 2, (i + 1) * 2);
            // pointsLeft[i] = new Point((i+1) * 0.5, (i+1) * ok);
            // pointsRight[i] = new Point(n + 1 - (i+1) * 0.5, (i+1) * ok);
        }

        long answer = 0;

        int lastSegmentThing = m;

        int rightStop = n - m;

        for (int leftPointId = m; leftPointId + m < n; leftPointId++) {

            int segmentLeft = -1, segmentRight = -1;

            int xx, yy, theirDx, theirDy;
            long theirAbs, yyyy3;

            {
                int rightPointId = leftPointId;
                xx = pointsLeft[leftPointId].x + pointsRight[rightPointId].x >> 1;
                yy = pointsLeft[leftPointId].y + pointsRight[rightPointId].y >> 1;
                theirDx = xx - pointsLeft[leftPointId].x;
                theirDy = yy - pointsLeft[leftPointId].y;
                theirAbs = (long) theirDx * theirDx + (long) theirDy * theirDy
                        * 3;

                yyyy3 = (long) yy * yy * 3;

                for (int low = lastSegmentThing; low + m < n; low++) {
                    long lowX = 4 * (low + 1);
                    long dx = xx - lowX;
                    long abs = dx * dx + yyyy3;
                    if (abs < theirAbs) {
                        segmentLeft = low;
                        break;
                    }
                }
            }

            // timeFirst += currentTimeMillis();
            int yyyy3i = (int) yyyy3;
            int theirAbsi = (int) theirAbs;
            if (segmentLeft < 0) {
                break;
            }
            lastSegmentThing = segmentLeft;

            segmentRight = n - 1 - segmentLeft;

            answer += segmentRight - segmentLeft + 1;

            int dx;

            int yyyy3MinusTheirAbsi = yyyy3i - theirAbsi;

            int curAddInt = 0;

            for (int rightPointId = leftPointId + 1; rightPointId < rightStop; rightPointId++) {
                --xx;
                ++yy;
                // xx = pointsLeft[leftPointId].x + pointsRight[rightPointId].x
                // >> 1;
                // yy = pointsLeft[leftPointId].y + pointsRight[rightPointId].y
                // >> 1;
                --theirDx;
                ++theirDy;
                // theirDx = xx - pointsLeft[leftPointId].x;
                // theirDy = yy - pointsLeft[leftPointId].y;
                yyyy3MinusTheirAbsi += 2 * theirDx + 1;
                yyyy3MinusTheirAbsi -= 6 * theirDy - 3;
                // theirAbs = theirDx * theirDx + theirDy * theirDy * 3;
                yyyy3MinusTheirAbsi += 6 * yy - 3;
                // if (yyyy3 > Integer.MAX_VALUE) {
                // System.err.println(yyyy3);
                // }
                // long yyyy3 = yy * yy * 3;
                // if (segmentLeft < lastLeftForThisRight[rightPointId]) {
                // segmentLeft = lastLeftForThisRight[rightPointId];
                // }
                // if(segmentRight > lastRightForThisRight[rightPointId]) {
                // segmentRight = lastRightForThisRight[rightPointId];
                // }
                int lowX = 4 * (segmentLeft + 1);
                dx = xx - lowX;
                int abs = dx * dx + yyyy3MinusTheirAbsi;
                while (segmentLeft <= segmentRight) {
                    // if (dx * dx > Integer.MAX_VALUE) {
                    // System.err.println(dx * dx);
                    // }
                    if (abs < 0) {
                        break;
                    } else {
                        ++segmentLeft;
                        abs -= 8 * dx - 16;
                        dx -= 4;
                    }
                }

                lowX = 4 * (segmentRight + 1);
                dx = (xx - lowX);
                abs = dx * dx + yyyy3MinusTheirAbsi;

                while (segmentLeft <= segmentRight) {
                    if (abs < 0) {
                        break;
                    } else {
                        --segmentRight;
                        abs += 8 * dx + 16;
                        dx += 4;
                    }
                }

                if (segmentLeft > segmentRight) {
                    rightStop = rightPointId;
                    break;
                }
                curAddInt += segmentRight - segmentLeft + 1;
            }
            answer += 2L * curAddInt;
        }

        // System.err.println("time first: "+timeFirst);
        // System.err.println("time second: "+timeSecond);
        return answer * 3L;
    }

    private static long solveWithoutOptimizations(int n, int m) {
        Point[] pointsLeft = new Point[n];
        Point[] pointsRight = new Point[n];
        for (int i = 0; i < n; i++) {
            pointsLeft[i] = new Point((i + 1) * 2, (i + 1) * 2);
            pointsRight[i] = new Point(4 * (n + 1) - (i + 1) * 2, (i + 1) * 2);
        }

        long answer = 0;

        int lastSegmentThing = m;

        for (int leftPointId = m; leftPointId + m < n; leftPointId++) {

            int segmentLeft = -1, segmentRight = -1;
            {
                int rightPointId = leftPointId;
                long xx = pointsLeft[leftPointId].x
                        + pointsRight[rightPointId].x >> 1;
                long yy = pointsLeft[leftPointId].y
                        + pointsRight[rightPointId].y >> 1;
                long theirDx = xx - pointsLeft[leftPointId].x;
                long theirDy = yy - pointsLeft[leftPointId].y;
                long theirAbs = theirDx * theirDx + (long) theirDy * theirDy
                        * 3;

                for (int low = lastSegmentThing; low + m < n; low++) {
                    long lowX = 4 * (low + 1);
                    long dx = xx - lowX;
                    long abs = dx * dx + yy * yy * 3;
                    if (abs < theirAbs) {
                        segmentLeft = low;
                        break;
                    }
                }
            }

            if (segmentLeft < 0) {
                break;
            }
            lastSegmentThing = segmentLeft;

            segmentRight = n - 1 - segmentLeft;

            answer += segmentRight - segmentLeft + 1;

            for (int rightPointId = leftPointId + 1; rightPointId < n - m; rightPointId++) {
                long xx = pointsLeft[leftPointId].x
                        + pointsRight[rightPointId].x >> 1;
                long yy = pointsLeft[leftPointId].y
                        + pointsRight[rightPointId].y >> 1;
                long theirDx = xx - pointsLeft[leftPointId].x;
                long theirDy = yy - pointsLeft[leftPointId].y;
                long theirAbs = theirDx * theirDx + theirDy * theirDy * 3;
                while (segmentLeft <= segmentRight) {
                    long lowX = 4 * (segmentLeft + 1);
                    long dx = xx - lowX;
                    long abs = dx * dx + yy * yy * 3;
                    if (abs < theirAbs) {
                        break;
                    } else {
                        ++segmentLeft;
                    }
                }

                while (segmentLeft <= segmentRight) {
                    long lowX = 4 * (segmentRight + 1);
                    long dx = xx - lowX;
                    long abs = dx * dx + yy * yy * 3;
                    if (abs < theirAbs) {
                        break;
                    } else {
                        --segmentRight;
                    }
                }

                if (segmentLeft > segmentRight) {
                    break;
                }
                answer += 2 * (segmentRight - segmentLeft + 1);
            }
        }

        return answer * 3L;
    }

    static long solveStupid(int n, int m) {
        Point[] pointsLeft = new Point[n];
        Point[] pointsRight = new Point[n];
        // double ok = Math.sqrt(3) * 0.5;
        for (int i = 0; i < n; i++) {
            pointsLeft[i] = new Point((i + 1) * 2, (i + 1) * 2);
            pointsRight[i] = new Point(4 * (n + 1) - (i + 1) * 2, (i + 1) * 2);
            // pointsLeft[i] = new Point((i+1) * 0.5, (i+1) * ok);
            // pointsRight[i] = new Point(n + 1 - (i+1) * 0.5, (i+1) * ok);
        }

        long answer = 0;

        for (int leftPointId = m; leftPointId + m < n; leftPointId++) {

            for (int rightPointId = m; rightPointId + m < n; rightPointId++) {
                long xx = pointsLeft[leftPointId].x
                        + pointsRight[rightPointId].x >> 1;
                long yy = pointsLeft[leftPointId].y
                        + pointsRight[rightPointId].y >> 1;

                long theirDx = xx - pointsLeft[leftPointId].x;
                long theirDy = yy - pointsLeft[leftPointId].y;
                long theirAbs = theirDx * theirDx + theirDy * theirDy * 3;

                for (int low = m; low + m < n; low++) {
                    long lowX = 4 * (low + 1);
                    long dx = xx - lowX;
                    long abs = dx * dx + yy * yy * 3;
                    if (abs < theirAbs) {
                        ++answer;
                    }
                }
            }
        }

        return answer * 3L;
    }

    static class Point {
        final int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;
        File file = new File("d.in");
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