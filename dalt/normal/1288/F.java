import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.Collection;
import java.io.IOException;
import java.util.HashMap;
import java.util.Deque;
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.io.Closeable;
import java.util.Map;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
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
            FRedBlueGraph solver = new FRedBlueGraph();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class FRedBlueGraph {
        int n1;
        int n2;
        long inf = (long) 1e8;

        int idOfLeft(int i) {
            return i;
        }

        int idOfRight(int i) {
            return n1 + i;
        }

        int idOfSrc() {
            return n1 + n2;
        }

        int idOfDst() {
            return idOfSrc() + 1;
        }

        public void solve(int testNumber, FastInput in, FastOutput out) {
            n1 = in.readInt();
            n2 = in.readInt();
            int m = in.readInt();
            int r = in.readInt();
            int b = in.readInt();

            LongMinCostMaxFlow mcmf = new LongMinCostMaxFlow(idOfDst() + 1, idOfSrc(), idOfDst());
            char[] leftColors = in.readString().toCharArray();
            char[] rightColors = in.readString().toCharArray();

            int colorCnt = n1 + n2;
            for (int i = 0; i < n1; i++) {
                if (leftColors[i] == 'R') {
                    mcmf.getChannel(idOfSrc(), idOfLeft(i), -inf).modify(1, 0);
                    mcmf.getChannel(idOfSrc(), idOfLeft(i), 0).modify(inf, 0);
                } else if (leftColors[i] == 'B') {
                    mcmf.getChannel(idOfLeft(i), idOfDst(), -inf).modify(1, 0);
                    mcmf.getChannel(idOfLeft(i), idOfDst(), 0).modify(inf, 0);
                } else {
                    mcmf.getChannel(idOfSrc(), idOfLeft(i), 0).modify(inf, 0);
                    mcmf.getChannel(idOfLeft(i), idOfDst(), 0).modify(inf, 0);
                    colorCnt--;
                }
            }

            LongMinCostMaxFlow.DirectFeeChannel[] reds = new LongMinCostMaxFlow.DirectFeeChannel[m];
            LongMinCostMaxFlow.DirectFeeChannel[] blues = new LongMinCostMaxFlow.DirectFeeChannel[m];

            for (int i = 0; i < n2; i++) {
                if (rightColors[i] == 'B') {
                    mcmf.getChannel(idOfSrc(), idOfRight(i), -inf).modify(1, 0);
                    mcmf.getChannel(idOfSrc(), idOfRight(i), 0).modify(inf, 0);
                } else if (rightColors[i] == 'R') {
                    mcmf.getChannel(idOfRight(i), idOfDst(), -inf).modify(1, 0);
                    mcmf.getChannel(idOfRight(i), idOfDst(), 0).modify(inf, 0);
                } else {
                    mcmf.getChannel(idOfSrc(), idOfRight(i), 0).modify(inf, 0);
                    mcmf.getChannel(idOfRight(i), idOfDst(), 0).modify(inf, 0);
                    colorCnt--;
                }
            }

            for (int i = 0; i < m; i++) {
                int left = in.readInt() - 1;
                int right = in.readInt() - 1;
                reds[i] = mcmf.addChannel(idOfLeft(left), idOfRight(right), r).modify(1, 0);
                blues[i] = mcmf.addChannel(idOfRight(right), idOfLeft(left), b).modify(1, 0);
            }


            char[] paint = new char[m];
            Arrays.fill(paint, 'U');
            long cost = 0;
            while (true) {
                long[] state = mcmf.send(1);
                if (state[1] >= 0) {
                    break;
                }
                cost -= state[1];
                for (int i = 0; i < m; i++) {
                    if (reds[i].getFlow() == 1) {
                        paint[i] = ('R');
                    } else if (blues[i].getFlow() == 1) {
                        paint[i] = ('B');
                    } else {
                        paint[i] = ('U');
                    }
                }
            }


            if (cost <= inf * (colorCnt - 1)) {
                out.println(-1);
                return;
            }

            out.println(-(cost - colorCnt * inf));
            out.println(new String(paint));
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
            cache.append(c);
            println();
            return this;
        }

        public FastOutput println(int c) {
            cache.append(c);
            println();
            return this;
        }

        public FastOutput println(long c) {
            cache.append(c);
            println();
            return this;
        }

        public FastOutput println() {
            cache.append(System.lineSeparator());
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

    static class LongMinCostMaxFlow {
        LongMinCostMaxFlow.Node[] nodes;
        Deque<LongMinCostMaxFlow.Node> deque;
        LongMinCostMaxFlow.Node source;
        LongMinCostMaxFlow.Node target;
        int nodeNum;
        final static long INF = (long) 1e18;
        Map<LongMinCostMaxFlow.ID, LongMinCostMaxFlow.DirectFeeChannel> channelMap = new HashMap();
        LongMinCostMaxFlow.ID id = new LongMinCostMaxFlow.ID(0, 0, 0);

        public LongMinCostMaxFlow(int nodeNum, int s, int t) {
            this.nodeNum = nodeNum;
            nodes = new LongMinCostMaxFlow.Node[nodeNum];
            for (int i = 0; i < nodeNum; i++) {
                nodes[i] = new LongMinCostMaxFlow.Node(i);
            }
            deque = new ArrayDeque(nodeNum);
            setSource(s);
            setTarget(t);
        }

        private void setSource(int id) {
            source = nodes[id];
        }

        private void setTarget(int id) {
            target = nodes[id];
        }

        public LongMinCostMaxFlow.DirectFeeChannel getChannel(int src, int dst, long fee) {
            id.src = src;
            id.dst = dst;
            id.fee = fee;
            LongMinCostMaxFlow.DirectFeeChannel channel = channelMap.get(id);
            if (channel == null) {
                channel = addChannel(src, dst, fee);
                channelMap.put(new LongMinCostMaxFlow.ID(src, dst, fee), channel);
            }
            return channel;
        }

        public LongMinCostMaxFlow.DirectFeeChannel addChannel(int src, int dst, long fee) {
            LongMinCostMaxFlow.DirectFeeChannel dfc = new LongMinCostMaxFlow.DirectFeeChannel(nodes[src], nodes[dst], fee);
            nodes[src].channelList.add(dfc);
            nodes[dst].channelList.add(dfc.inverse());
            return dfc;
        }

        public long[] send(long flow) {
            long totalFee = 0;
            long totalFlow = 0;

            while (flow > 0) {
                spfa();

                if (target.distance == INF) {
                    break;
                }


                long feeSum = target.distance;
                long minFlow = flow;

                LongMinCostMaxFlow.Node trace = target;
                while (trace != source) {
                    LongMinCostMaxFlow.FeeChannel last = trace.last;
                    minFlow = Math.min(minFlow, last.getCapacity() - last.getFlow());
                    trace = last.getSrc();
                }

                flow -= minFlow;

                trace = target;
                while (trace != source) {
                    LongMinCostMaxFlow.FeeChannel last = trace.last;
                    last.sendFlow(minFlow);
                    trace = last.getSrc();
                }

                totalFee += feeSum * minFlow;
                totalFlow += minFlow;
            }

            return new long[]{totalFlow, totalFee};
        }

        private void spfa() {
            for (int i = 0; i < nodeNum; i++) {
                nodes[i].distance = INF;
                nodes[i].inque = false;
                nodes[i].last = null;
            }

            deque.addLast(source);
            source.distance = 0;
            source.inque = true;
            long sumOfDistance = 0;

            while (!deque.isEmpty()) {
                LongMinCostMaxFlow.Node head = deque.removeFirst();
                if (head.distance * (deque.size() + 1) > sumOfDistance) {
                    deque.addLast(head);
                    continue;
                }
                sumOfDistance -= head.distance;
                head.inque = false;
                for (LongMinCostMaxFlow.FeeChannel channel : head.channelList) {
                    if (channel.getFlow() == channel.getCapacity()) {
                        continue;
                    }
                    LongMinCostMaxFlow.Node dst = channel.getDst();
                    long oldDist = dst.distance;
                    long newDist = head.distance + channel.getFee();
                    if (oldDist <= newDist) {
                        continue;
                    }
                    dst.distance = newDist;
                    dst.last = channel;
                    if (dst.inque) {
                        sumOfDistance -= oldDist;
                        sumOfDistance += newDist;
                        continue;
                    }
                    if (!deque.isEmpty() && deque.peekFirst().distance < dst.distance) {
                        deque.addFirst(dst);
                    } else {
                        deque.addLast(dst);
                    }
                    dst.inque = true;
                    sumOfDistance += newDist;
                }
            }
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (LongMinCostMaxFlow.DirectFeeChannel channel : channelMap.values()) {
                if (channel.getFlow() > 0) {
                    builder.append(channel).append('\n');
                }
            }
            return builder.toString();
        }

        private static class ID {
            int src;
            int dst;
            long fee;

            ID(int src, int dst, long fee) {
                this.src = src;
                this.dst = dst;
                this.fee = fee;
            }

            public int hashCode() {
                return (int) ((src * 31L + dst) * 31 + Long.hashCode(fee));
            }

            public boolean equals(Object obj) {
                LongMinCostMaxFlow.ID other = (LongMinCostMaxFlow.ID) obj;
                return src == other.src &&
                        dst == other.dst &&
                        fee == other.fee;
            }

        }

        public static interface FeeChannel {
            public LongMinCostMaxFlow.Node getSrc();

            public LongMinCostMaxFlow.Node getDst();

            public long getCapacity();

            public long getFlow();

            public void sendFlow(long volume);

            public long getFee();

        }

        public static class DirectFeeChannel implements LongMinCostMaxFlow.FeeChannel {
            final LongMinCostMaxFlow.Node src;
            final LongMinCostMaxFlow.Node dst;
            long capacity;
            long flow;
            LongMinCostMaxFlow.FeeChannel inverse;
            final long fee;

            public long getFee() {
                return fee;
            }

            public DirectFeeChannel(LongMinCostMaxFlow.Node src, LongMinCostMaxFlow.Node dst, long fee) {
                this.src = src;
                this.dst = dst;
                this.fee = fee;
                inverse = new LongMinCostMaxFlow.InverseFeeChannelWrapper(this);
            }

            public String toString() {
                return String.format("%s--%s/%s-->%s", getSrc(), getFlow(), getCapacity(), getDst());
            }

            public LongMinCostMaxFlow.Node getSrc() {
                return src;
            }

            public LongMinCostMaxFlow.FeeChannel inverse() {
                return inverse;
            }

            public LongMinCostMaxFlow.Node getDst() {
                return dst;
            }

            public long getCapacity() {
                return capacity;
            }

            public long getFlow() {
                return flow;
            }

            public void sendFlow(long volume) {
                flow += volume;
            }

            public LongMinCostMaxFlow.DirectFeeChannel modify(long cap, long flow) {
                this.capacity += cap;
                this.flow += flow;
                return this;
            }

        }

        public static class InverseFeeChannelWrapper implements LongMinCostMaxFlow.FeeChannel {
            final LongMinCostMaxFlow.FeeChannel inner;

            public InverseFeeChannelWrapper(LongMinCostMaxFlow.FeeChannel inner) {
                this.inner = inner;
            }

            public long getFee() {
                return -inner.getFee();
            }

            public LongMinCostMaxFlow.Node getSrc() {
                return inner.getDst();
            }

            public LongMinCostMaxFlow.Node getDst() {
                return inner.getSrc();
            }

            public long getCapacity() {
                return inner.getFlow();
            }

            public long getFlow() {
                return 0;
            }

            public void sendFlow(long volume) {
                inner.sendFlow(-volume);
            }

            public String toString() {
                return String.format("%s--%s/%s-->%s", getSrc(), getFlow(), getCapacity(), getDst());
            }

        }

        public static class Node {
            final int id;
            long distance;
            boolean inque;
            LongMinCostMaxFlow.FeeChannel last;
            List<LongMinCostMaxFlow.FeeChannel> channelList = new ArrayList(1);

            public Node(int id) {
                this.id = id;
            }

            public String toString() {
                return "" + id;
            }

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
}