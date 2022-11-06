import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.AbstractMap;
import java.util.TreeMap;
import java.io.Closeable;
import java.util.Map;
import java.io.Writer;
import java.util.Map.Entry;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 27);
        thread.start();
        thread.join();
    }

    static class TaskAdapter implements Runnable {
        @Override
        public void run() {
            InputStream inputStream = System.in;
            OutputStream outputStream = System.out;
            FastInput in = new FastInput(inputStream);
            FastOutput out = new FastOutput(outputStream);
            TaskD solver = new TaskD();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskD {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int q = in.readInt();
            GeometryUtils.Point2D[] triangles = new GeometryUtils.Point2D[3];
            double centerX = 0;
            double centerY = 0;
            for (int i = 0; i < 3; i++) {
                in.readInt();
                triangles[i] = new GeometryUtils.Point2D(in.readInt(), in.readInt());
                centerX += triangles[i].x;
                centerY += triangles[i].y;
            }

            GeometryUtils.DynamicConvexHull dch = new GeometryUtils.DynamicConvexHull(new GeometryUtils.Point2D(centerX / 3, centerY / 3));
            for (int i = 0; i < 3; i++) {
                dch.add(triangles[i]);
            }

            for (int i = 3; i < q; i++) {
                int t = in.readInt();
                GeometryUtils.Point2D pt = new GeometryUtils.Point2D(in.readInt(), in.readInt());
                if (t == 1) {
                    dch.add(pt);
                } else {
                    boolean contain = dch.contain(pt, true);
                    out.println(contain ? "YES" : "NO");
                }
            }
        }

    }

    static class FastInput {
        private final InputStream is;
        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;

        public FastInput(InputStream is) {
            this.is = is;
        }

        private int read() {
            while (bufLen == bufOffset) {
                bufOffset = 0;
                try {
                    bufLen = is.read(buf);
                } catch (IOException e) {
                    bufLen = -1;
                }
                if (bufLen == -1) {
                    return -1;
                }
            }
            return buf[bufOffset++];
        }

        public void skipBlank() {
            while (next >= 0 && next <= 32) {
                next = read();
            }
        }

        public int readInt() {
            int sign = 1;

            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+' ? 1 : -1;
                next = read();
            }

            int val = 0;
            if (sign == 1) {
                while (next >= '0' && next <= '9') {
                    val = val * 10 + next - '0';
                    next = read();
                }
            } else {
                while (next >= '0' && next <= '9') {
                    val = val * 10 - next + '0';
                    next = read();
                }
            }

            return val;
        }

    }

    static class FastOutput implements AutoCloseable, Closeable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput println(String c) {
            cache.append(c).append('\n');
            return this;
        }

        public FastOutput flush() {
            try {
                os.append(cache);
                os.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
            return this;
        }

        public void close() {
            flush();
            try {
                os.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

        public String toString() {
            return cache.toString();
        }

    }

    static class GeometryUtils {
        private static final double PREC = 1e-12;

        public static double valueOf(double x) {
            return x > -PREC && x < PREC ? 0 : x;
        }

        public static boolean near(double a, double b) {
            return valueOf(a - b) == 0;
        }

        public static double cross(double x1, double y1, double x2, double y2) {
            return valueOf(x1 * y2 - y1 * x2);
        }

        public static double theta(double y, double x) {
            double theta = Math.atan2(y, x);
            if (theta < 0) {
                theta += Math.PI * 2;
            }
            return theta;
        }

        public static class Point2D {
            public final double x;
            public final double y;

            public Point2D(double x, double y) {
                this.x = valueOf(x);
                this.y = valueOf(y);
            }

            public double distance2Between(GeometryUtils.Point2D another) {
                double dx = x - another.x;
                double dy = y - another.y;
                return valueOf(dx * dx + dy * dy);
            }

            public double cross(GeometryUtils.Point2D a, GeometryUtils.Point2D b) {
                return GeometryUtils.cross(a.x - x, a.y - y, b.x - x, b.y - y);
            }

            public String toString() {
                return String.format("(%f, %f)", x, y);
            }

            public int hashCode() {
                return (int) (Double.doubleToLongBits(x) * 31 + Double.doubleToLongBits(y));
            }

            public boolean equals(Object obj) {
                GeometryUtils.Point2D other = (GeometryUtils.Point2D) obj;
                return x == other.x && y == other.y;
            }

        }

        public static class Line2D {
            public final GeometryUtils.Point2D a;
            public final GeometryUtils.Point2D b;
            public final GeometryUtils.Point2D d;
            public final double theta;

            public Line2D(GeometryUtils.Point2D a, GeometryUtils.Point2D b) {
                this.a = a;
                this.b = b;
                d = new GeometryUtils.Point2D(b.x - a.x, b.y - a.y);
                theta = Math.atan2(d.y, d.x);
            }

            public String toString() {
                return d.toString();
            }

        }

        public static class Segment2D extends GeometryUtils.Line2D {
            public Segment2D(GeometryUtils.Point2D a, GeometryUtils.Point2D b) {
                super(a, b);
            }

            public boolean contain(GeometryUtils.Point2D p) {
                return cross(p.x - a.x, p.y - a.y, d.x, d.y) == 0
                        && valueOf(p.x - Math.min(a.x, b.x)) >= 0 && valueOf(p.x - Math.max(a.x, b.x)) <= 0
                        && valueOf(p.y - Math.min(a.y, b.y)) >= 0 && valueOf(p.y - Math.max(a.y, b.y)) <= 0;
            }

            public boolean containWithoutEndpoint(GeometryUtils.Point2D p) {
                return contain(p) && !p.equals(a) && !p.equals(b);
            }

        }

        public static class DynamicConvexHull {
            private TreeMap<Double, GeometryUtils.Point2D> pts = new TreeMap<>((a, b) ->
                    near(a, b) ? 0 : a.compareTo(b));
            private GeometryUtils.Point2D center;

            public DynamicConvexHull(GeometryUtils.Point2D center) {
                this.center = center;
            }

            private Map.Entry<Double, GeometryUtils.Point2D> clockwise(Double theta) {
                Map.Entry<Double, GeometryUtils.Point2D> floor = pts.floorEntry(theta);
                if (floor == null) {
                    floor = pts.lastEntry();
                }
                return floor;
            }

            private Map.Entry<Double, GeometryUtils.Point2D> countclockwise(Double theta) {
                Map.Entry<Double, GeometryUtils.Point2D> ceil = pts.ceilingEntry(theta);
                if (ceil == null) {
                    ceil = pts.firstEntry();
                }
                return ceil;
            }

            private boolean contain(GeometryUtils.Point2D point, Double theta, boolean close) {
                GeometryUtils.Point2D cw = clockwise(theta).getValue();
                GeometryUtils.Point2D ccw = countclockwise(theta).getValue();

                if (cw == ccw) {
                    GeometryUtils.Segment2D seg = new GeometryUtils.Segment2D(center, ccw);
                    if (close) {
                        return seg.contain(point);
                    }
                    return seg.containWithoutEndpoint(point);
                }

                if (close) {
                    return center.cross(cw, point) >= 0 &&
                            cw.cross(ccw, point) >= 0 &&
                            ccw.cross(center, point) >= 0;
                }
                return center.cross(cw, point) > 0 &&
                        cw.cross(ccw, point) > 0 &&
                        ccw.cross(center, point) > 0;
            }

            public boolean contain(GeometryUtils.Point2D point, boolean close) {
                if (pts.isEmpty()) {
                    return false;
                }
                return contain(point, theta(point.y - center.y, point.x - center.x), close);
            }

            public void add(GeometryUtils.Point2D point) {
                Double theta = theta(point.y - center.y, point.x - center.x);
                if (pts.size() < 3) {
                    GeometryUtils.Point2D exists = pts.get(theta);
                    if (exists != null && center.distance2Between(exists) >= center.distance2Between(point)) {
                        return;
                    }
                    pts.put(theta, point);
                    return;
                }

                if (contain(point, theta, true)) {
                    return;
                }

                //clockwise
                while (pts.size() >= 3) {
                    Map.Entry<Double, GeometryUtils.Point2D> cw = clockwise(theta);
                    pts.remove(cw.getKey());
                    GeometryUtils.Point2D next = clockwise(theta).getValue();
                    if (point.cross(cw.getValue(), next) < 0) {
                        pts.put(cw.getKey(), cw.getValue());
                        break;
                    }
                }
                //clockwise
                while (pts.size() >= 3) {
                    Map.Entry<Double, GeometryUtils.Point2D> ccw = countclockwise(theta);
                    pts.remove(ccw.getKey());
                    GeometryUtils.Point2D next = countclockwise(theta).getValue();
                    if (point.cross(ccw.getValue(), next) > 0) {
                        pts.put(ccw.getKey(), ccw.getValue());
                        break;
                    }
                }

                pts.put(theta, point);
            }

        }

    }
}