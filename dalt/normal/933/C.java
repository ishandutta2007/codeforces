

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.util.Set;
import java.util.TreeSet;

/**
 * Created by dalt on 2018/3/25.
 */
public class CF933C {
    public static final double PREC = 1e-10;
    static final boolean IS_OJ = System.getProperty("ONLINE_JUDGE") != null;
    public static BlockReader input;

    public static void main(String[] args) throws FileNotFoundException {
        if (!IS_OJ) {
            System.setIn(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF933C.in"));
        }
        input = new BlockReader(System.in);

        solve();
    }

    public static void solve() {
        int n = input.nextInteger();
        Circle[] circles = new Circle[n];

        for (int i = 0; i < n; i++) {
            circles[i] = new Circle(input.nextInteger(), input.nextInteger(), input.nextInteger());
        }

        if (n == 3 && !Circle.isIntersect(circles[0], circles[1])) {
            int sum = 4;
            if (Circle.isIntersect2(circles[0], circles[2])) {
                sum++;
            }
            if (Circle.isIntersect2(circles[1], circles[2])) {
                sum++;
            }
            System.out.println(sum);
            return;
        }

        int total = 1;
        TreeSet<Point> set = new TreeSet<>();
        for (int i = 0; i < n; i++) {
            set.clear();
            total++;
            for (int j = 0; j < i; j++) {
                Circle.intersectAt(circles[i], circles[j], set);
            }
            if (set.size() >= 2) {
                total += set.size() - 1;
            }
        }

        System.out.println(total);
    }

    public static double distance(Point a, Point b) {
        return Math.sqrt(distance2(a, b));
    }

    public static double distance2(Point a, Point b) {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        return dx * dx + dy * dy;
    }

    public static class Circle {
        Point center;
        int r;

        public Circle(int x, int y, int r) {
            this.center = new Point(x, y);
            this.r = r;
        }

        public static boolean isIntersect(Circle a, Circle b) {
            double d = distance(a.center, b.center);
            return d <= a.r + b.r + PREC && d + PREC >= Math.abs(a.r - b.r);
        }

        public static boolean isIntersect2(Circle a, Circle b) {
            double d = distance(a.center, b.center);
            return d < a.r + b.r && d > Math.abs(a.r - b.r);
        }

        public static void intersectAt(Circle a, Circle b, Set<Point> set) {
            if (!isIntersect(a, b)) {
                return;
            }

            Line line = new Line(a.center, b.center);
            double d = distance(a.center, b.center);
            double middleDistance = (d * d - b.r * b.r + a.r * a.r) / (2 * d);
            Point middle = a.center.moveAlongLine(line, middleDistance);
            Point alpha = line.asVector().getAlpha();
            double height = Math.sqrt(a.r * a.r - middleDistance * middleDistance);
            Point first = middle.moveAlongVector(alpha, height);
            Point second = middle.moveAlongVector(alpha, -height);

            set.add(first);
            if (!second.equals(first)) {
                set.add(second);
            }
        }
    }

    public static class Point implements Comparable<Point> {
        double x, y;

        public Point(double x, double y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return "(" + x + "," + y + ")";
        }

        public Point sub(Point other) {
            return new Point(x - other.x, y - other.y);
        }

        public Point moveAlongLine(Line line, double length) {
            return moveAlongVector(line.asVector(), length);
        }

        public Point moveAlongVector(Point vec, double length) {
            return add(vec.normalize().mul(length));
        }

        public Point add(Point other) {
            return new Point(x + other.x, y + other.y);
        }

        public Point mul(double f) {
            return new Point(x * f, y * f);
        }

        public Point normalize() {
            double len = Math.sqrt(x * x + y * y);
            return div(len);
        }

        public Point div(double f) {
            return new Point(x / f, y / f);
        }

        public Point getAlpha() {
            return new Point(-y, x);
        }

        @Override
        public boolean equals(Object obj) {
            Point other = (Point) obj;
            return Math.abs(x - other.x) < PREC && Math.abs(y - other.y) < PREC;
        }

        @Override
        public int compareTo(Point o) {
            if (equals(o)) {
                return 0;
            }
            if (Math.abs(x - o.x) < PREC) {
                return Double.compare(y, o.y);
            }
            return Double.compare(x, o.x);
        }
    }

    public static class Line {
        Point from;
        Point to;

        public Line(Point from, Point to) {
            this.from = from;
            this.to = to;
        }

        public Point asVector() {
            return to.sub(from);
        }

        public double length() {
            return distance(from, to);
        }
    }

    public static class BlockReader {
        static final int EOF = -1;
        InputStream is;
        byte[] dBuf;
        int dPos, dSize, next;
        StringBuilder builder = new StringBuilder();

        public BlockReader(InputStream is) {
            this(is, 4096);
        }

        public BlockReader(InputStream is, int bufSize) {
            this.is = is;
            dBuf = new byte[bufSize];
            next = nextByte();
        }

        public int nextByte() {
            while (dPos >= dSize) {
                if (dSize == -1) {
                    return EOF;
                }
                dPos = 0;
                try {
                    dSize = is.read(dBuf);
                } catch (Exception e) {
                }
            }
            return dBuf[dPos++];
        }

        public String nextBlock() {
            builder.setLength(0);
            skipBlank();
            while (next != EOF && !Character.isWhitespace(next)) {
                builder.append((char) next);
                next = nextByte();
            }
            return builder.toString();
        }

        public void skipBlank() {
            while (Character.isWhitespace(next)) {
                next = nextByte();
            }
        }

        public int nextInteger() {
            skipBlank();
            int ret = 0;
            boolean rev = false;
            if (next == '+' || next == '-') {
                rev = next == '-';
                next = nextByte();
            }
            while (next >= '0' && next <= '9') {
                ret = (ret << 3) + (ret << 1) + next - '0';
                next = nextByte();
            }
            return rev ? -ret : ret;
        }

        public int nextBlock(char[] data, int offset) {
            skipBlank();
            int index = offset;
            int bound = data.length;
            while (next != EOF && index < bound && !Character.isWhitespace(next)) {
                data[index++] = (char) next;
                next = nextByte();
            }
            return index - offset;
        }

        public boolean hasMore() {
            skipBlank();
            return next != EOF;
        }
    }
}