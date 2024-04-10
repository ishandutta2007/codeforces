import static java.lang.Math.abs;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.fill;
import static java.util.Arrays.sort;

import java.io.*;
import java.util.*;

public class Subway {

    private static void solve() throws IOException {
        int menCount = nextInt(), subwayCount = nextInt();
        int[] manX = new int[menCount], manY = new int[menCount];
        for (int i = 0; i < menCount; i++) {
            manX[i] = nextInt() * 2;
            manY[i] = nextInt() * 2;
        }
        int[] subwayX = new int[subwayCount], subwayY = new int[subwayCount];
        for (int i = 0; i < subwayCount; i++) {
            subwayX[i] = nextInt() * 2;
            subwayY[i] = nextInt() * 2;
        }
        int answer = solve(manX, manY, subwayX, subwayY);
        out.println(answer + 1 >> 1);
    }

    static int solve(int[] manX, int[] manY, int[] subwayX, int[] subwayY) {
        int menCount = manX.length, subwayCount = subwayX.length;

        Point[] manPoints = new Point[menCount];
        Point[] subways = new Point[subwayCount];
        for (int i = 0; i < menCount; i++) {
            manPoints[i] = new Point(manX[i] + manY[i], manX[i] - manY[i]);
        }
        for (int i = 0; i < subwayCount; i++) {
            subways[i] = new Point(subwayX[i] + subwayY[i], subwayX[i] - subwayY[i]);
        }
        int[] distToSubway = DistToSubwaySolver.distToSubwayForPoints(manPoints, subways);
        Man[] men = new Man[menCount];
        for (int i = 0; i < menCount; i++) {
            men[i] = new Man(manPoints[i], distToSubway[i]);
        }
        sort(men, new Comparator<Man>() {
            @Override
            public int compare(Man o1, Man o2) {
                return o2.distToSubway - o1.distToSubway;
            }
        });

        int[] minRadius = new int[menCount];
        Segment[] segments = new Segment[menCount];
        int x1 = Integer.MAX_VALUE, y1 = Integer.MAX_VALUE;
        int x2 = Integer.MIN_VALUE, y2 = Integer.MIN_VALUE;
        for (int i = 0; i < menCount; i++) {
            x1 = min(x1, men[i].where.x);
            x2 = max(x2, men[i].where.x);
            y1 = min(y1, men[i].where.y);
            y2 = max(y2, men[i].where.y);
            int d = max(x2 - x1, y2 - y1) >> 1;
            minRadius[i] = d;
            segments[i] = new Segment(min(x1 + d, x2 - d), min(y1 + d, y2 - d),
                    max(x1 + d, x2 - d), max(y1 + d, y2 - d));
        }

        int[] segmentToSubway = DistToSubwaySolver.distToSubwayForSegments(segments, subways);

        int bestAnswer = Integer.MAX_VALUE;

        for (int menWalk = 0; menWalk <= menCount; menWalk++) {
            int r;
            if (menWalk == 0) {
                r = men[0].distToSubway;
            } else {
                if (menWalk == menCount) {
                    r = minRadius[menCount - 1];
                } else {
                    int d = segmentToSubway[menWalk - 1] + minRadius[menWalk - 1]
                            + men[menWalk].distToSubway;
                    r = d / 2;
                    r = max(r, minRadius[menWalk - 1]);
                    r = max(r, men[menWalk].distToSubway);
                }
            }
            bestAnswer = min(bestAnswer, r);
        }
        return bestAnswer;
    }

    static class Segment {
        int x1, y1, x2, y2;

        private Segment(int x1, int y1, int x2, int y2) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }
    }

    static class Man {
        final Point where;
        final int distToSubway;

        private Man(Point where, int distToSubway) {
            this.where = where;
            this.distToSubway = distToSubway;
        }
    }

    static class Point {
        final int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        int dist(Point p) {
            return max(abs(x - p.x), abs(y - p.y));
        }

        @Override
        public String toString() {
            return "(" + x + ", " + y + ")";
        }
    }

    static class DistToSubwaySolver {

        static int[] distToSubwayForPoints(Point[] men, Point[] subways) {
            int menCount = men.length, subwayCount = subways.length;
            Event[] allEvents = new Event[subwayCount + menCount];
            Set<Integer> allXplusY = new HashSet<Integer>();
            for (int i = 0; i < subwayCount; i++) {
                Event event = new SubwayEvent(subways[i]);
                allEvents[i] = event;
                allXplusY.add(subways[i].x + subways[i].y);
            }
            QueryEvent[] queries = new QueryEvent[menCount];
            for (int i = 0; i < menCount; i++) {
                QueryEvent event = new QueryEvent(men[i], i);
                allEvents[i + subwayCount] = event;
                allXplusY.add(men[i].x + men[i].y);
                queries[i] = event;
            }
            int[] xplusyArray = toSortedArray(allXplusY);

            for (final int aMul : new int[] { 1, -1 }) {
                for (final int bMul : new int[] { 1, -1 }) {
                    Comparator<Event> comparator = new Comparator<Event>() {
                        @Override
                        public int compare(Event o1, Event o2) {
                            int cmp = (o1.p.x - o1.p.y) - (o2.p.x - o2.p.y);
                            if (cmp != 0) {
                                return cmp * bMul;
                            }
                            return o1.getType() - o2.getType();
                        }
                    };
                    sort(allEvents, comparator);
                    SmartStructureForPoints smart = new SmartStructureForPoints(new Fenwick(
                            xplusyArray.length), xplusyArray, aMul, bMul);
                    for (Event e : allEvents) {
                        e.processMe(smart);
                    }
                }
            }
            int[] ret = new int[menCount];
            for (int i = 0; i < menCount; i++) {
                ret[i] = queries[i].answer >> 1;
            }

            return ret;
        }

        static int[] toSortedArray(Collection<Integer> c) {
            int[] res = new int[c.size()];
            int cnt = 0;
            for (int i : c) {
                res[cnt++] = i;
            }
            sort(res);
            return res;
        }

        static abstract class Event {
            Point p;

            abstract int getType();

            abstract void processMe(SmartStructureForPoints smart);

            abstract void processMe(SmartStructureForSegments smart);
        }

        static class SubwayEvent extends Event {

            private SubwayEvent(Point p) {
                this.p = p;
            }

            @Override
            public int getType() {
                return 0;
            }

            @Override
            public void processMe(SmartStructureForPoints smart) {
                int index = binarySearch(smart.allXplusY, p.x + p.y);
                if (smart.aMul < 0) {
                    index = smart.allXplusY.length - index - 1;
                }
                int value = (p.x + p.y) * smart.aMul + (p.x - p.y) * smart.bMul;
                smart.f.relax(index, value);
            }

            @Override
            void processMe(SmartStructureForSegments smart) {
                int index = binarySearch(smart.all, p.x * (1 - smart.direction) + p.y
                        * smart.direction);
                smart.tree.set(index, (p.x * smart.direction + p.y * (1 - smart.direction))
                        * smart.order);
            }
        }

        static class QueryEvent extends Event {
            final int id;
            int answer;

            private QueryEvent(Point p, int id) {
                this.p = p;
                this.id = id;
                this.answer = Integer.MAX_VALUE;
            }

            @Override
            public int getType() {
                return 1;
            }

            @Override
            public void processMe(SmartStructureForPoints smart) {
                int index = binarySearch(smart.allXplusY, p.x + p.y);
                if (smart.aMul < 0) {
                    index = smart.allXplusY.length - index - 1;
                }
                int value = (p.x + p.y) * smart.aMul + (p.x - p.y) * smart.bMul;
                int okValue = smart.f.getMax(index);
                if (okValue != Integer.MIN_VALUE) {
                    this.answer = min(this.answer, value - okValue);
                }
            }

            @Override
            void processMe(SmartStructureForSegments smart) {
                throw new UnsupportedOperationException();
            }
        }

        static class SegmentEvent extends Event {
            final Segment segment;
            final int id;
            int answer;

            private SegmentEvent(Segment segment, Point oneEnd, int id) {
                this.p = oneEnd;
                this.segment = segment;
                this.id = id;
                this.answer = Integer.MAX_VALUE;
            }

            @Override
            int getType() {
                return 1;
            }

            @Override
            void processMe(SmartStructureForPoints smart) {
                throw new UnsupportedOperationException();
            }

            @Override
            void processMe(SmartStructureForSegments smart) {
                if (segment.x1 == segment.x2 && smart.direction == 0) {
                    return;
                }
                if (segment.y1 == segment.y2 && smart.direction == 1) {
                    return;
                }
                int left = binarySearch(smart.all, segment.x1 * (1 - smart.direction) + segment.y1
                        * smart.direction);
                int right = binarySearch(smart.all, segment.x2 * (1 - smart.direction) + segment.y2
                        * smart.direction);
                int value = (p.x * smart.direction + p.y * (1 - smart.direction)) * smart.order;
                int okValue = smart.tree.get(left, right + 1);
                if (okValue != Integer.MIN_VALUE) {
                    answer = min(answer, value - okValue);
                }
            }
        }

        static class SmartStructureForPoints {
            Fenwick f;
            int[] allXplusY;
            int aMul, bMul;

            private SmartStructureForPoints(Fenwick f, int[] allX, int aMul, int bMul) {
                this.f = f;
                this.allXplusY = allX;
                this.aMul = aMul;
                this.bMul = bMul;
            }
        }

        static class Fenwick {
            int[] a;

            Fenwick(int n) {
                a = new int[n];
                fill(a, Integer.MIN_VALUE);
            }

            void relax(int i, int val) {
                for (; i < a.length; i |= i + 1) {
                    a[i] = max(a[i], val);
                }
            }

            int getMax(int i) {
                int ans = Integer.MIN_VALUE;
                for (; i >= 0; i = (i & i + 1) - 1) {
                    ans = max(ans, a[i]);
                }
                return ans;
            }
        }

        static int[] distToSubwayForSegments(Segment[] segments, Point[] subways) {
            int segmentCount = segments.length, subwayCount = subways.length;
            Point[] ends = new Point[2 * segmentCount];
            for (int i = 0; i < segmentCount; i++) {
                ends[2 * i] = new Point(segments[i].x1, segments[i].y1);
                ends[2 * i + 1] = new Point(segments[i].x2, segments[i].y2);
            }
            int[] distForEnds = distToSubwayForPoints(ends, subways);
            int[] answer = new int[segmentCount];
            for (int i = 0; i < segmentCount; i++) {
                answer[i] = min(distForEnds[2 * i], distForEnds[2 * i + 1]);
            }
            Set<Integer> all = new HashSet<Integer>();
            for (Point p : ends) {
                all.add(p.x);
                all.add(p.y);
            }
            for (Point p : subways) {
                all.add(p.x);
                all.add(p.y);
            }
            int[] xArray = toSortedArray(all);
            Event[] allEvents = new Event[segmentCount + subwayCount];

            SegmentEvent[] segmentEvents = new SegmentEvent[segmentCount];
            for (int i = 0; i < segmentCount; i++) {
                segmentEvents[i] = new SegmentEvent(segments[i], ends[2 * i], i);
                allEvents[i] = segmentEvents[i];
            }

            for (int i = 0; i < subwayCount; i++) {
                allEvents[i + segmentCount] = new SubwayEvent(subways[i]);
            }

            for (final int direction : new int[] { 0, 1 }) {
                for (final int order : new int[] { 1, -1 }) {
                    final int xMul = direction;
                    final int yMul = 1 - direction;
                    Comparator<Event> comparator = new Comparator<Event>() {
                        @Override
                        public int compare(Event o1, Event o2) {
                            int cmp = (o1.p.x * xMul + o1.p.y * yMul)
                                    - (o2.p.x * xMul + o2.p.y * yMul);
                            if (cmp != 0) {
                                return cmp * order;
                            }
                            return o1.getType() - o2.getType();
                        }
                    };
                    sort(allEvents, comparator);
                    SmartStructureForSegments smart = new SmartStructureForSegments(
                            new SegmentTreeMax(xArray.length), xArray, direction, order);
                    for (Event e : allEvents) {
                        e.processMe(smart);
                    }
                }
            }
            for (SegmentEvent e : segmentEvents) {
                answer[e.id] = min(answer[e.id], e.answer);
            }
            return answer;
        }

        static class SmartStructureForSegments {
            SegmentTreeMax tree;
            int[] all;
            int direction, order;

            private SmartStructureForSegments(SegmentTreeMax tree, int[] all, int direction,
                    int order) {
                this.tree = tree;
                this.all = all;
                this.direction = direction;
                this.order = order;
            }
        }

        static class SegmentTreeMax {
            int[] max;
            int n;

            public SegmentTreeMax(int n) {
                this.n = Integer.highestOneBit(n) << 1;
                max = new int[this.n << 1];
                Arrays.fill(max, Integer.MIN_VALUE);
            }

            void set(int x, int y) {
                x += n;
                max[x] = y;
                while (x > 1) {
                    x >>= 1;
                    max[x] = Math.max(max[x << 1], max[(x << 1) | 1]);
                }
            }

            int get(int l, int r) {
                --r;
                int ret = Integer.MIN_VALUE;
                l += n;
                r += n;
                while (l <= r) {
                    if ((l & 1) == 1) {
                        ret = Math.max(ret, max[l++]);
                    }
                    if ((r & 1) == 0) {
                        ret = Math.max(ret, max[r--]);
                    }
                    l >>= 1;
                    r >>= 1;
                }
                return ret;
            }
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