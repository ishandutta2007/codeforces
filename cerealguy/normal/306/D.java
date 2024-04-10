import java.io.*;
import java.util.*;

public class D {

    static void solve() throws IOException {
        int n = nextInt();
        if (n <= 4) {
            out.println("No solution");
        } else {
            Point[] points = solve(n);
            for (int i = 0; i < n; i++) {
                out.println(points[i].x + " " + points[i].y);
            }
        }
    }

    static Random rng = new Random(58);

    private static Point[] solve(int n) {
        ok: for (int it = 0; it < 100; it++) {
            Point[] points = new Point[n];
            double length = 500;
            double small = 1. / 500;
            Double[] lengths = new Double[n];
            for (int i = 0; i < n; i++) {
                lengths[i] = length + small * i;
            }
            Collections.shuffle(Arrays.asList(lengths), rng);
            Point p = new Point(0, 0);
            points[0] = p;
            Point vector = new Point(1, 0);
            double angle = 2 * Math.PI / n;

            Point rotate = new Point(Math.cos(angle), Math.sin(angle));

            for (int i = 1; i < n; i++) {
                p = p.add(vector.mul(lengths[i]));
                vector = vector.rotate(rotate);
                points[i] = p;
            }

            double y = points[n - 1].y;
            double move = y / rotate.y;

            p = p.add(vector.mul(move));
            points[0] = p;

            double[] l = new double[n];
            for (int i = 0; i < n; i++) {
                l[i] = points[i].sub(points[(i + 1) % n]).abs();
            }
            Arrays.sort(l);
            for (int i = 0; i < n; i++) {
                if (i < n - 1 && l[i + 1] - l[i] <= 1e-3) {
                    continue ok;
                }
                if (l[i] < 1 || l[i] > 1000) {
                    continue ok;
                }
            }

            return points;
        }
        throw new AssertionError();
    }

    static class Point {
        final double x, y;

        Point sub(Point p) {
            return new Point(x - p.x, y - p.y);
        }

        public Point rotate(Point rotate) {
            return new Point(x * rotate.x - y * rotate.y, x * rotate.y + y
                    * rotate.x);
        }

        Point add(Point p) {
            return new Point(x + p.x, y + p.y);
        }

        Point mul(double val) {
            return new Point(x * val, y * val);
        }

        double abs() {
            return Math.sqrt(x * x + y * y);
        }

        public Point(double x, double y) {
            this.x = x;
            this.y = y;
        }

        public String toString() {
            return "Point [x=" + x + ", y=" + y + "]";
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