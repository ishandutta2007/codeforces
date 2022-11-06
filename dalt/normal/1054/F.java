import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.util.Iterator;
import java.io.IOException;
import java.util.stream.Collectors;
import java.io.UncheckedIOException;
import java.util.List;
import java.util.stream.Stream;
import java.io.Closeable;
import java.util.Map.Entry;
import java.io.Writer;
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
            FElectricScheme solver = new FElectricScheme();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FElectricScheme {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            Point[] pts = new Point[n];
            for (int i = 0; i < n; i++) {
                int x = in.readInt();
                int y = in.readInt();
                pts[i] = new Point(x, y);
            }

            Map<Integer, List<Point>> ptsGroupByX = Arrays.stream(pts).collect(Collectors.groupingBy(x -> x.x));
            Map<Integer, List<Point>> ptsGroupByY = Arrays.stream(pts).collect(Collectors.groupingBy(x -> x.y));

            List<XLine> xLines = new ArrayList<>(n);
            List<YLine> yLines = new ArrayList<>(n);
            for (Map.Entry<Integer, List<Point>> entry : ptsGroupByY.entrySet()) {
                int y = entry.getKey();
                List<Point> list = entry.getValue();
                list.sort((a, b) -> a.x - b.x);
                for (int i = 1; i < list.size(); i++) {
                    Point last = list.get(i - 1);
                    Point next = list.get(i);
                    if (last.x + 1 < next.x) {
                        XLine line = new XLine(last.x + 1, next.x - 1, y);
                        xLines.add(line);
                    }
                }
            }

            for (Map.Entry<Integer, List<Point>> entry : ptsGroupByX.entrySet()) {
                int x = entry.getKey();
                List<Point> list = entry.getValue();
                list.sort((a, b) -> a.y - b.y);
                for (int i = 1; i < list.size(); i++) {
                    Point last = list.get(i - 1);
                    Point next = list.get(i);
                    if (last.y + 1 < next.y) {
                        YLine line = new YLine(last.y + 1, next.y - 1, x);
                        yLines.add(line);
                    }
                }
            }


            int xCnt = xLines.size();
            int yCnt = yLines.size();
            List<int[]> edges = new ArrayList<>(xCnt * yCnt);
            for (int i = 0; i < xCnt; i++) {
                for (int j = 0; j < yCnt; j++) {
                    XLine xLine = xLines.get(i);
                    YLine yLine = yLines.get(j);
                    if (between(xLine.y, yLine.b, yLine.t) &&
                            between(yLine.x, xLine.l, xLine.r)) {
                        edges.add(new int[]{i, j});
                    }
                }
            }

            BipartiteMatching match = new BipartiteMatching(xLines.size(), yLines.size(), edges.size());
            for (int[] e : edges) {
                match.addEdge(e[0], e[1]);
            }

            boolean[][] minVertexCover = match.minVertexCover();
            List<XLine> ansXLines = new ArrayList<>(n);
            List<YLine> ansYLines = new ArrayList<>(n);

            int cnt = 0;
            for (Map.Entry<Integer, List<Point>> entry : ptsGroupByY.entrySet()) {
                int y = entry.getKey();
                List<Point> list = entry.getValue();
                list.sort((a, b) -> a.x - b.x);
                int l, r;
                l = r = list.get(0).x;
                for (int i = 1; i < list.size(); i++) {
                    Point last = list.get(i - 1);
                    Point next = list.get(i);
                    if (last.x + 1 < next.x) {
                        if (minVertexCover[0][cnt]) {
                            ansXLines.add(new XLine(l, r, y));
                            l = r = next.x;
                        } else {
                            r = next.x;
                        }
                        cnt++;
                    } else {
                        r = next.x;
                    }
                }
                ansXLines.add(new XLine(l, r, y));
            }

            cnt = 0;
            for (Map.Entry<Integer, List<Point>> entry : ptsGroupByX.entrySet()) {
                int x = entry.getKey();
                List<Point> list = entry.getValue();
                list.sort((a, b) -> a.y - b.y);
                int b, t;
                b = t = list.get(0).y;
                for (int i = 1; i < list.size(); i++) {
                    Point last = list.get(i - 1);
                    Point next = list.get(i);
                    if (last.y + 1 < next.y) {
                        if (minVertexCover[1][cnt]) {
                            ansYLines.add(new YLine(b, t, x));
                            b = t = next.y;
                        } else {
                            t = next.y;
                        }
                        cnt++;
                    } else {
                        t = next.y;
                    }
                }
                ansYLines.add(new YLine(b, t, x));
            }

            out.println(ansXLines.size());
            for (XLine line : ansXLines) {
                out.append(line.l).append(' ').append(line.y).append(' ').append(line.r).append(' ').append(line.y).println();
            }
            out.println(ansYLines.size());
            for (YLine line : ansYLines) {
                out.append(line.x).append(' ').append(line.b).append(' ').append(line.x).append(' ').append(line.t).println();
            }
        }

        public boolean between(int a, int l, int r) {
            return l <= a && a <= r;
        }

    }

    static interface SimplifiedStack<T> extends Iterable<T> {
    }

    static interface IntegerStack {
    }

    static class BipartiteMatching {
        LongDinicBeta dinic;
        int l;
        int r;
        List<LongDinicBeta.ChannelImpl> channels;
        boolean[][] minVertexCover;
        boolean[] leftVisited;
        boolean[] rightVisited;
        int[] match;
        int flow = -1;

        private int left(int i) {
            return i;
        }

        private int right(int i) {
            return l + i;
        }

        private int src() {
            return l + r;
        }

        private int sink() {
            return src() + 1;
        }

        public BipartiteMatching(int l, int r, int edgeNum) {
            this.l = l;
            this.r = r;
            dinic = new LongDinicBeta(sink() + 1, edgeNum + l + r, src(), sink());
            for (int i = 0; i < l; i++) {
                dinic.addChannel(src(), left(i)).expand(1);
            }
            for (int i = 0; i < r; i++) {
                dinic.addChannel(right(i), sink()).expand(1);
            }
            channels = new ArrayList<>(edgeNum);
        }

        public void addEdge(int lId, int rId) {
            LongDinicBeta.ChannelImpl channel = dinic.addChannel(left(lId), right(rId));
            channels.add(channel);
            channel.expand(1);
        }

        private void solve() {
            flow = (int) dinic.send(Math.min(l, r));
        }

        public int maxMatch() {
            if (flow == -1) {
                solve();
            }
            return flow;
        }

        public boolean[][] minVertexCover() {
            if (minVertexCover == null) {
                minVertexCover = new boolean[][]{new boolean[l], new boolean[r]};
                leftVisited = new boolean[l];
                rightVisited = new boolean[r];
                boolean[] matched = new boolean[r];
                for (int x : match()) {
                    if (x == -1) {
                        continue;
                    }
                    matched[x] = true;
                }
                for (int i = 0; i < r; i++) {
                    if (!matched[i]) {
                        dfsRight(i);
                    }
                }

                for (int i = 0; i < l; i++) {
                    minVertexCover[0][i] = leftVisited[i];
                }
                for (int i = 0; i < r; i++) {
                    minVertexCover[1][i] = !rightVisited[i];
                }
            }
            return minVertexCover;
        }

        private void dfsRight(int node) {
            if (rightVisited[node]) {
                return;
            }
            rightVisited[node] = true;
            for (LongDinicBeta.Channel left : dinic.getChannelFrom(right(node))) {
                if (left.getDst() < l) {
                    dfsLeft(left.getDst());
                }
            }
        }

        private void dfsLeft(int node) {
            if (match[node] == -1 || leftVisited[node]) {
                return;
            }
            leftVisited[node] = true;
            dfsRight(match[node]);
        }

        public int[] match() {
            if (match == null) {
                maxMatch();
                match = new int[l];
                Arrays.fill(match, -1);
                for (LongDinicBeta.ChannelImpl channel : channels) {
                    if (channel.getFlow() == 1) {
                        match[channel.getSrc()] = channel.getDst() - l;
                    }
                }
            }
            return match;
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

    static interface LongObjectEntryIterator<V> {
        boolean hasNext();

        void next();

        long getEntryKey();

        V getEntryValue();

    }

    static interface IntegerDeque extends IntegerStack {
    }

    static class LongObjectHashMap<V> {
        private int[] slot;
        private int[] next;
        private long[] keys;
        private Object[] values;
        private int alloc;
        private boolean[] removed;
        private int mask;
        private boolean rehash;

        public LongObjectHashMap(int cap, boolean rehash) {
            this.mask = (1 << (32 - Integer.numberOfLeadingZeros(cap - 1))) - 1;
            slot = new int[mask + 1];
            next = new int[cap + 1];
            keys = new long[cap + 1];
            values = new Object[cap + 1];
            removed = new boolean[cap + 1];
            this.rehash = rehash;
        }

        public LongObjectEntryIterator<V> iterator() {
            return new LongObjectEntryIterator() {
                int index = 1;
                int readIndex = -1;


                public boolean hasNext() {
                    while (index <= alloc && removed[index]) {
                        index++;
                    }
                    return index <= alloc;
                }


                public long getEntryKey() {
                    return keys[readIndex];
                }


                public Object getEntryValue() {
                    return values[readIndex];
                }


                public void next() {
                    if (!hasNext()) {
                        throw new IllegalStateException();
                    }
                    readIndex = index;
                    index++;
                }
            };
        }

        public String toString() {
            LongObjectEntryIterator<V> iterator = iterator();
            StringBuilder builder = new StringBuilder("{");
            while (iterator.hasNext()) {
                iterator.next();
                builder.append(iterator.getEntryKey()).append("->").append(iterator.getEntryValue()).append(',');
            }
            if (builder.charAt(builder.length() - 1) == ',') {
                builder.setLength(builder.length() - 1);
            }
            builder.append('}');
            return builder.toString();
        }

    }

    static class YLine {
        int t;
        int b;
        int x;

        public YLine(int b, int t, int x) {
            this.t = t;
            this.b = b;
            this.x = x;
        }

    }

    static class LongDinicBeta {
        private MultiWayStack<LongDinicBeta.Channel> edges;
        private RevokeIterator<LongDinicBeta.Channel>[] iterators;
        private LongObjectHashMap<LongDinicBeta.ChannelImpl> map;
        private IntegerDequeImpl deque;
        private int[] dists;
        private int vertexNumber;
        private long totalFlow;
        private int sink;
        private int source;

        public LongDinicBeta(int vertexNumber, int expectedChannelNumber,
                             int source, int sink) {
            edges = new MultiWayStack<>(vertexNumber, expectedChannelNumber * 2);
            iterators = new RevokeIterator[vertexNumber];
            map = new LongObjectHashMap<>(expectedChannelNumber, true);
            this.sink = sink;
            this.source = source;
            deque = new IntegerDequeImpl(vertexNumber);
            dists = new int[vertexNumber];
            this.vertexNumber = vertexNumber;
        }

        public SimplifiedStack<LongDinicBeta.Channel> getChannelFrom(int id) {
            return edges.getStack(id);
        }

        public long send(long flow) {
            long totalSent = 0;
            while (flow > totalSent) {
                bfs();
                if (dists[source] == Integer.MAX_VALUE) {
                    break;
                }
                for (int i = 0; i < iterators.length; i++) {
                    iterators[i] = edges.iterator(i);
                }
                totalSent += send(source, flow - totalSent);
            }
            totalFlow += totalSent;
            return totalSent;
        }

        private void bfs() {
            Arrays.fill(dists, Integer.MAX_VALUE);
            dists[sink] = 0;
            deque.clear();
            deque.addLast(sink);
            while (!deque.isEmpty()) {
                int head = deque.removeFirst();
                for (Iterator<LongDinicBeta.Channel> iterator = edges.iterator(head);
                     iterator.hasNext(); ) {
                    LongDinicBeta.Channel channel = iterator.next().inverse();
                    if (channel.getCap() == channel.getFlow()) {
                        continue;
                    }
                    int src = channel.getSrc();
                    if (dists[src] <= dists[head] + 1) {
                        continue;
                    }
                    dists[src] = dists[head] + 1;
                    deque.addLast(src);
                }
            }
        }

        private long send(int root, long flow) {
            if (root == sink) {
                return flow;
            }
            long totalSent = 0;
            for (; iterators[root].hasNext(); ) {
                LongDinicBeta.Channel channel = iterators[root].next();
                int dst = channel.getDst();
                if (channel.getCap() == channel.getFlow() ||
                        dists[dst] + 1 != dists[root]) {
                    continue;
                }
                long sent = send(dst, Math.min(flow - totalSent, channel.getCap() - channel.getFlow()));
                totalSent += sent;
                channel.send(sent);
                if (totalSent == flow) {
                    if (channel.getCap() > channel.getFlow()) {
                        iterators[root].revoke();
                    }
                    break;
                }
            }

            return totalSent;
        }

        public LongDinicBeta.ChannelImpl addChannel(int a, int b) {
            LongDinicBeta.ChannelImpl channel = new LongDinicBeta.ChannelImpl(a, b);
            edges.addLast(a, channel);
            edges.addLast(b, channel.inverse());
            return channel;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < vertexNumber; i++) {
                for (Iterator<LongDinicBeta.Channel> iterator = edges.iterator(i); iterator.hasNext(); ) {
                    LongDinicBeta.Channel channel = iterator.next();
                    builder.append(channel).append('\n');
                }
            }
            return builder.toString();
        }

        public static interface Channel {
            LongDinicBeta.Channel inverse();

            long getFlow();

            long getCap();

            void send(long f);

            int getSrc();

            int getDst();

        }

        public static class ChannelImpl implements LongDinicBeta.Channel {
            private long flow;
            private long cap;
            private LongDinicBeta.InverseChannelWrapper inverse = new LongDinicBeta.InverseChannelWrapper(this);
            private int src;
            private int dst;

            private ChannelImpl(int src, int dst) {
                this.src = src;
                this.dst = dst;
            }

            public long getFlow() {
                return flow;
            }

            public long getCap() {
                return cap;
            }

            public LongDinicBeta.Channel inverse() {
                return inverse;
            }

            public void send(long f) {
                flow += f;
            }

            public void expand(long c) {
                cap += c;
            }

            public int getSrc() {
                return src;
            }

            public int getDst() {
                return dst;
            }

            public String toString() {
                return String.format("%d-%d/%d->%d", getSrc(), getFlow(), getCap(), getDst());
            }

        }

        private static class InverseChannelWrapper implements LongDinicBeta.Channel {
            private LongDinicBeta.Channel channel;

            private InverseChannelWrapper(LongDinicBeta.Channel channel) {
                this.channel = channel;
            }

            public LongDinicBeta.Channel inverse() {
                return channel;
            }

            public long getFlow() {
                return 0;
            }

            public long getCap() {
                return channel.getFlow();
            }

            public void send(long f) {
                channel.send(-f);
            }

            public int getSrc() {
                return channel.getDst();
            }

            public int getDst() {
                return channel.getSrc();
            }

            public String toString() {
                return String.format("%d-%d/%d->%d", getSrc(), getFlow(), getCap(), getDst());
            }

        }

    }

    static class MultiWayStack<T> {
        private Object[] values;
        private int[] next;
        private int[] heads;
        private int alloc;
        private int stackNum;

        public RevokeIterator<T> iterator(final int queue) {
            return new RevokeIterator<T>() {
                int ele = heads[queue];
                int pre = 0;


                public boolean hasNext() {
                    return ele != 0;
                }


                public T next() {
                    T ans = (T) values[ele];
                    pre = ele;
                    ele = next[ele];
                    return ans;
                }


                public void revoke() {
                    ele = pre;
                    pre = 0;
                }
            };
        }

        public SimplifiedStack<T> getStack(int qId) {
            return new SimplifiedStack<T>() {

                public boolean isEmpty() {
                    return MultiWayStack.this.isEmpty(qId);
                }


                public T peekLast() {
                    return MultiWayStack.this.peekLast(qId);
                }


                public void addLast(T x) {
                    MultiWayStack.this.addLast(qId, x);
                }


                public T removeLast() {
                    return MultiWayStack.this.removeLast(qId);
                }


                public Iterator<T> iterator() {
                    return MultiWayStack.this.iterator(qId);
                }
            };
        }

        private void doubleCapacity() {
            int newSize = Math.max(next.length + 10, next.length * 2);
            next = Arrays.copyOf(next, newSize);
            values = Arrays.copyOf(values, newSize);
        }

        public void alloc() {
            alloc++;
            if (alloc >= next.length) {
                doubleCapacity();
            }
            next[alloc] = 0;
        }

        public boolean isEmpty(int qId) {
            return heads[qId] == 0;
        }

        public MultiWayStack(int qNum, int totalCapacity) {
            values = new Object[totalCapacity + 1];
            next = new int[totalCapacity + 1];
            heads = new int[qNum];
            stackNum = qNum;
        }

        public void addLast(int qId, T x) {
            alloc();
            values[alloc] = x;
            next[alloc] = heads[qId];
            heads[qId] = alloc;
        }

        public T peekLast(int qId) {
            return (T) values[heads[qId]];
        }

        public T removeLast(int qId) {
            T ans = (T) values[heads[qId]];
            heads[qId] = next[heads[qId]];
            return ans;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < stackNum; i++) {
                builder.append(i).append(": ");
                for (Iterator iterator = iterator(i); iterator.hasNext(); ) {
                    builder.append(iterator.next()).append(",");
                }
                if (builder.charAt(builder.length() - 1) == ',') {
                    builder.setLength(builder.length() - 1);
                }
                builder.append('\n');
            }
            return builder.toString();
        }

    }

    static class Point {
        int x;
        int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
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

        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }

        public FastOutput append(int c) {
            cache.append(c);
            return this;
        }

        public FastOutput println(int c) {
            cache.append(c).append('\n');
            return this;
        }

        public FastOutput println() {
            cache.append('\n');
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

    static interface IntegerIterator {
        boolean hasNext();

        int next();

    }

    static class XLine {
        int l;
        int r;
        int y;

        public XLine(int l, int r, int y) {
            this.l = l;
            this.r = r;
            this.y = y;
        }

    }

    static class IntegerDequeImpl implements IntegerDeque {
        private int[] data;
        private int bpos;
        private int epos;
        private static final int[] EMPTY = new int[0];
        private int n;

        public IntegerDequeImpl(int cap) {
            if (cap == 0) {
                data = EMPTY;
            } else {
                data = new int[cap];
            }
            bpos = 0;
            epos = 0;
            n = cap;
        }

        private void expandSpace(int len) {
            while (n < len) {
                n = Math.max(n + 10, n * 2);
            }
            int[] newData = new int[n];
            if (bpos <= epos) {
                if (bpos < epos) {
                    System.arraycopy(data, bpos, newData, 0, epos - bpos);
                }
            } else {
                System.arraycopy(data, bpos, newData, 0, data.length - bpos);
                System.arraycopy(data, 0, newData, data.length - bpos, epos);
            }
            epos = size();
            bpos = 0;
            data = newData;
        }

        public IntegerIterator iterator() {
            return new IntegerIterator() {
                int index = bpos;


                public boolean hasNext() {
                    return index != epos;
                }


                public int next() {
                    int ans = data[index];
                    index = IntegerDequeImpl.this.next(index);
                    return ans;
                }
            };
        }

        public int removeFirst() {
            int ans = data[bpos];
            bpos = next(bpos);
            return ans;
        }

        public void addLast(int x) {
            ensureMore();
            data[epos] = x;
            epos = next(epos);
        }

        public void clear() {
            bpos = epos = 0;
        }

        private int next(int x) {
            return x + 1 >= n ? 0 : x + 1;
        }

        private void ensureMore() {
            if (next(epos) == bpos) {
                expandSpace(n + 1);
            }
        }

        public int size() {
            int ans = epos - bpos;
            if (ans < 0) {
                ans += data.length;
            }
            return ans;
        }

        public boolean isEmpty() {
            return bpos == epos;
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (IntegerIterator iterator = iterator(); iterator.hasNext(); ) {
                builder.append(iterator.next()).append(' ');
            }
            return builder.toString();
        }

    }

    static interface RevokeIterator<E> extends Iterator<E> {
        void revoke();

    }
}