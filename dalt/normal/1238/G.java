import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.AbstractQueue;
import java.io.IOException;
import java.util.AbstractCollection;
import java.io.InputStream;

/**
 * Built using CHelper plug-in Actual solution is at the top
 * 
 * @author daltao
 */
public class Main {
    public static void main(String[] args) throws InterruptedException {
        Thread thread = new Thread(null, new TaskAdapter(), "daltao", 1 << 27);
        thread.start();
        thread.join();
    }

    static class TaskAdapter implements Runnable {
        @Override
        public void run() {
            InputStream inputStream = System.in;
            OutputStream outputStream = System.out;
            FastInput in = new FastInput(inputStream);
            PrintWriter out = new PrintWriter(outputStream);
            TaskG solver = new TaskG();
            int testCount = Integer.parseInt(in.next());
            for (int i = 1; i <= testCount; i++)
                solver.solve(i, in, out);
            out.close();
        }
    }
    static class TaskG {
        public void solve(int testNumber, FastInput in, PrintWriter out) {
            int n = in.readInt();
            int m = in.readInt();
            int c = in.readInt();
            int c0 = in.readInt();

            Event[] events = new Event[n + 1];
            events[0] = new Event(c0, 0, 0);

            for (int i = 1; i <= n; i++) {
                int t = in.readInt();
                int a = in.readInt();
                int b = in.readInt();
                events[i] = new Event(a, b, t);
            }

            Arrays.sort(events, (a, b) -> a.time - b.time);
            PriorityQueue<Event> queue = new PriorityQueue<>(n + 1, (a, b) -> a.unitCost - b.unitCost);
            Segment segment = new Segment(0, n);

            for (int i = 0; i < n; i++) {
                events[i].carry = events[i + 1].time - events[i].time;
            }
            events[n].carry = m - events[n].time;

            for (int i = 0; i <= n; i++) {
                events[i].index = i;
            }

            long cost = 0;
            for (Event e : events) {
                queue.add(e);
                while (e.carry > 0 && !queue.isEmpty()) {
                    Event top = queue.remove();
                    int canUse = c - segment.query(top.index, e.index, 0, n);
                    canUse = Math.min(canUse, top.in);
                    canUse = Math.min(canUse, e.carry);
                    if (canUse == 0) {
                        continue;
                    }
                    cost += (long) canUse * top.unitCost;
                    top.in -= canUse;
                    e.carry -= canUse;
                    segment.update(top.index, e.index, 0, n, canUse);
                    if (top.in > 0) {
                        queue.add(top);
                    }
                }
                if (e.carry > 0) {
                    out.println(-1);
                    return;
                }
            }
            out.println(cost);
        }

    }
    static class Event {
        int in;
        int unitCost;
        int time;
        int carry;
        int index;

        public Event(int in, int unitCost, int time) {
            this.in = in;
            this.unitCost = unitCost;
            this.time = time;
        }

    }
    static class FastInput {
        private final InputStream is;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 13);
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
                    throw new RuntimeException(e);
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

        public String next() {
            return readString();
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

        public String readString(StringBuilder builder) {
            skipBlank();

            while (next > 32) {
                builder.append((char) next);
                next = read();
            }

            return builder.toString();
        }

        public String readString() {
            defaultStringBuf.setLength(0);
            return readString(defaultStringBuf);
        }

    }
    static class Segment implements Cloneable {
        private Segment left;
        private Segment right;
        private int val;
        private int plus;

        public void setPlus(int p) {
            this.plus += p;
            this.val += p;
        }

        public void pushUp() {
            val = Math.max(left.val, right.val);
        }

        public void pushDown() {
            if (plus != 0) {
                left.setPlus(plus);
                right.setPlus(plus);
                plus = 0;
            }
        }

        public Segment(int l, int r) {
            if (l < r) {
                int m = (l + r) >> 1;
                left = new Segment(l, m);
                right = new Segment(m + 1, r);
                pushUp();
            } else {

            }
        }

        private boolean covered(int ll, int rr, int l, int r) {
            return ll <= l && rr >= r;
        }

        private boolean noIntersection(int ll, int rr, int l, int r) {
            return ll > r || rr < l;
        }

        public void update(int ll, int rr, int l, int r, int p) {
            if (noIntersection(ll, rr, l, r)) {
                return;
            }
            if (covered(ll, rr, l, r)) {
                setPlus(p);
                return;
            }
            pushDown();
            int m = (l + r) >> 1;
            left.update(ll, rr, l, m, p);
            right.update(ll, rr, m + 1, r, p);
            pushUp();
        }

        public int query(int ll, int rr, int l, int r) {
            if (noIntersection(ll, rr, l, r)) {
                return 0;
            }
            if (covered(ll, rr, l, r)) {
                return val;
            }
            pushDown();
            int m = (l + r) >> 1;
            return Math.max(left.query(ll, rr, l, m), right.query(ll, rr, m + 1, r));
        }

    }
}