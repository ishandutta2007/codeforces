import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.PriorityQueue;
import java.util.Collection;
import java.util.AbstractQueue;
import java.io.IOException;
import java.util.Deque;
import java.io.UncheckedIOException;
import java.util.AbstractCollection;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.ArrayDeque;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author daltao
 */
public class Main {
    public static void main(String[] args) throws Exception {
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
            FastOutput out = new FastOutput(outputStream);
            TaskC solver = new TaskC();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class TaskC {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            long p = in.readInt();

            PriorityQueue<Event> events = new PriorityQueue<>(2 * n, (a, b) -> Long.compare(a.time, b.time));

            Seat[] seats = new Seat[n];
            for (int i = 0; i < n; i++) {
                seats[i] = new Seat();
                seats[i].id = i;
                Event e = new Event();
                e.type = 2;
                e.which = seats[i];
                e.time = in.readInt();
                events.add(e);
            }
            MinQueue<Seat> inQue = new MinQueue<>(n, (a, b) -> a.id - b.id);
            PriorityQueue<Seat> wait = new PriorityQueue<>(n, (a, b) -> a.id - b.id);

            boolean state = false;
            while (!events.isEmpty()) {
                long time = events.peek().time;
                while (!events.isEmpty() && events.peek().time == time) {
                    Event head = events.remove();
                    if (head.type == 2) {
                        wait.add(head.which);
                    } else if (head.type == 1) {
                        state = false;
                        inQue.deque();
                        head.which.ans = head.time;
                    }
                }

                while (!wait.isEmpty() && (inQue.isEmpty() || inQue.query().id > wait.peek().id)) {
                    Seat s = wait.remove();
                    inQue.enqueue(s);
                }

                if (!state && !inQue.isEmpty()) {
                    state = true;
                    Seat s = inQue.peek();
                    Event e = new Event();
                    e.which = s;
                    e.type = 1;
                    e.time = time + p;
                    events.add(e);
                }
            }

            for (Seat s : seats) {
                out.append(s.ans).append(' ');
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

    static class Event {
        int type;
        Seat which;
        long time;

    }

    static class Seat {
        int id;
        long ans;

        public String toString() {
            return "" + id;
        }

    }

    static class MinQueue<T> {
        Deque<T> data;
        Deque<T> increasing;
        Comparator<T> comparator;

        public boolean isEmpty() {
            return data.isEmpty();
        }

        public MinQueue(int cap, Comparator<T> comparator) {
            data = new ArrayDeque<>(cap);
            increasing = new ArrayDeque<>(cap);
            this.comparator = comparator;
        }

        public void enqueue(T x) {
            while (!increasing.isEmpty() && comparator.compare(x, increasing.peekLast()) < 0) {
                increasing.removeLast();
            }
            increasing.addLast(x);
            data.addLast(x);
        }

        public T deque() {
            T head = data.removeFirst();
            if (increasing.peekFirst() == head) {
                increasing.removeFirst();
            }
            return head;
        }

        public T query() {
            return increasing.peekFirst();
        }

        public T peek() {
            return data.peekFirst();
        }

    }

    static class FastOutput implements AutoCloseable, Closeable {
        private StringBuilder cache = new StringBuilder(1 << 20);
        private final Writer os;

        public FastOutput(Writer os) {
            this.os = os;
        }

        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }

        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }

        public FastOutput append(long c) {
            cache.append(c);
            return this;
        }

        public FastOutput flush() {
            try {
                os.append(cache);
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

    }
}