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
            GPetyaAndGraph solver = new GPetyaAndGraph();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class GPetyaAndGraph {
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            long[] weights = new long[n + m];
            for (int i = 0; i < n; i++) {
                weights[i] = -in.readInt();
            }
            int[][] edges = new int[m][2];
            for (int i = 0; i < m; i++) {
                edges[i][0] = in.readInt() - 1;
                edges[i][1] = in.readInt() - 1;
                weights[i + n] = in.readInt();
            }
            LongMinimumCloseSubGraph graph = new LongMinimumCloseSubGraph(weights);
            for (int i = 0; i < m; i++) {
                graph.addDependency(i + n, edges[i][0]);
                graph.addDependency(i + n, edges[i][1]);
            }

            long ans = graph.solve();
            out.println(ans);
        }

    }

    static class LongMinimumCloseSubGraph {
        private LongISAP isap;
        private int n;
        private long sumOfPositive;
        private boolean solved;
        private long minCut;

        public LongMinimumCloseSubGraph(long[] weight) {
            this.n = weight.length;
            isap = new LongISAP(n + 2);
            int idOfSrc = n;
            int idOfDst = n + 1;
            isap.setSource(idOfSrc);
            isap.setTarget(idOfDst);

            for (int i = 0; i < n; i++) {
                if (weight[i] > 0) {
                    isap.getChannel(idOfSrc, i).reset(weight[i], 0);
                    sumOfPositive += weight[i];
                }
                if (weight[i] < 0) {
                    isap.getChannel(i, idOfDst).reset(-weight[i], 0);
                }
            }
        }

        public void addDependency(int from, int to) {
            if (!(from >= 0 && from < n && to >= 0 && to < n)) {
                throw new IllegalArgumentException();
            }
            isap.getChannel(from, to).reset((long) 1e18, 0);
        }

        public long solve() {
            if (!solved) {
                minCut = isap.send((long) 1e18);
                solved = true;
            }
            return sumOfPositive - minCut;
        }

    }

    static class LongISAP {
        LongISAP.Node[] nodes;
        int[] distanceCnt;
        LongISAP.Node source;
        LongISAP.Node target;
        int nodeNum;
        Map<Long, LongISAP.DirectChannel> channelMap = new HashMap();
        Deque<LongISAP.Node> deque;
        long totalFlow;

        private Collection<LongISAP.DirectChannel> getChannels() {
            return channelMap.values();
        }

        private LongISAP.DirectChannel addChannel(int src, int dst) {
            LongISAP.DirectChannel channel = new LongISAP.DirectChannel(nodes[src], nodes[dst], 0, 0);
            nodes[src].channelList.add(channel);
            nodes[dst].channelList.add(channel.getInverse());
            return channel;
        }

        public LongISAP.DirectChannel getChannel(int src, int dst) {
            Long id = (((long) src) << 32) | dst;
            LongISAP.DirectChannel channel = channelMap.get(id);
            if (channel == null) {
                channel = addChannel(src, dst);
                channelMap.put(id, channel);
            }
            return channel;
        }

        public LongISAP(int nodeNum) {
            this.nodeNum = nodeNum;
            deque = new ArrayDeque(nodeNum);
            nodes = new LongISAP.Node[nodeNum];
            distanceCnt = new int[nodeNum + 2];
            for (int i = 0; i < nodeNum; i++) {
                LongISAP.Node node = new LongISAP.Node();
                node.id = i;
                nodes[i] = node;
            }
        }

        public long send(long flow) {
            long sent = 0;
            bfs();
            while (flow > sent && source.distance < nodeNum) {
                sent += send(source, flow - sent);
            }
            totalFlow += sent;
            return sent;
        }

        private long send(LongISAP.Node node, long flowRemain) {
            if (node == target) {
                return flowRemain;
            }

            long sent = 0;
            int nextDistance = node.distance - 1;
            for (LongISAP.Channel channel : node.channelList) {
                long channelRemain = channel.getCapacity() - channel.getFlow();
                LongISAP.Node dst = channel.getDst();
                if (channelRemain == 0 || dst.distance != nextDistance) {
                    continue;
                }
                long actuallySend = send(channel.getDst(), Math.min(flowRemain - sent, channelRemain));
                channel.sendFlow(actuallySend);
                sent += actuallySend;
                if (flowRemain == sent) {
                    break;
                }
            }

            if (sent == 0) {
                if (--distanceCnt[node.distance] == 0) {
                    distanceCnt[source.distance]--;
                    source.distance = nodeNum;
                    distanceCnt[source.distance]++;
                    if (node != source) {
                        distanceCnt[++node.distance]++;
                    }
                } else {
                    distanceCnt[++node.distance]++;
                }
            }

            return sent;
        }

        public void setSource(int id) {
            source = nodes[id];
        }

        public void setTarget(int id) {
            target = nodes[id];
        }

        private void bfs() {
            Arrays.fill(distanceCnt, 0);
            deque.clear();

            for (int i = 0; i < nodeNum; i++) {
                nodes[i].distance = nodeNum;
            }

            target.distance = 0;
            deque.addLast(target);

            while (!deque.isEmpty()) {
                LongISAP.Node head = deque.removeFirst();
                distanceCnt[head.distance]++;
                for (LongISAP.Channel channel : head.channelList) {
                    LongISAP.Channel inverse = channel.getInverse();
                    if (inverse.getCapacity() == inverse.getFlow()) {
                        continue;
                    }
                    LongISAP.Node dst = channel.getDst();
                    if (dst.distance != nodeNum) {
                        continue;
                    }
                    dst.distance = head.distance + 1;
                    deque.addLast(dst);
                }
            }
        }

        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (LongISAP.DirectChannel channel : getChannels()) {
                if (channel.getFlow() == 0) {
                    continue;
                }
                builder.append(channel).append('\n');
            }

            for (LongISAP.DirectChannel channel : getChannels()) {
                if (channel.getFlow() != 0) {
                    continue;
                }
                builder.append(channel).append('\n');
            }
            return builder.toString();
        }

        public static interface Channel {
            public LongISAP.Node getSrc();

            public LongISAP.Node getDst();

            public long getCapacity();

            public long getFlow();

            public void sendFlow(long volume);

            public LongISAP.Channel getInverse();

        }

        public static class DirectChannel implements LongISAP.Channel {
            final LongISAP.Node src;
            final LongISAP.Node dst;
            final int id;
            long capacity;
            long flow;
            LongISAP.Channel inverse;

            public DirectChannel(LongISAP.Node src, LongISAP.Node dst, int capacity, int id) {
                this.src = src;
                this.dst = dst;
                this.capacity = capacity;
                this.id = id;
                inverse = new LongISAP.InverseChannelWrapper(this);
            }

            public void reset(long cap, long flow) {
                this.flow = flow;
                this.capacity = cap;
            }

            public String toString() {
                return String.format("%s--%s/%s-->%s", getSrc(), getFlow(), getCapacity(), getDst());
            }

            public LongISAP.Node getSrc() {
                return src;
            }

            public LongISAP.Channel getInverse() {
                return inverse;
            }

            public LongISAP.Node getDst() {
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

        }

        public static class InverseChannelWrapper implements LongISAP.Channel {
            final LongISAP.Channel channel;

            public InverseChannelWrapper(LongISAP.Channel channel) {
                this.channel = channel;
            }

            public LongISAP.Channel getInverse() {
                return channel;
            }

            public LongISAP.Node getSrc() {
                return channel.getDst();
            }

            public LongISAP.Node getDst() {
                return channel.getSrc();
            }

            public long getCapacity() {
                return channel.getFlow();
            }

            public long getFlow() {
                return 0;
            }

            public void sendFlow(long volume) {
                channel.sendFlow(-volume);
            }

            public String toString() {
                return String.format("%s--%s/%s-->%s", getSrc(), getFlow(), getCapacity(), getDst());
            }

        }

        public static class Node {
            int id;
            int distance;
            List<LongISAP.Channel> channelList = new ArrayList(1);

            public String toString() {
                return "" + id;
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

        public FastOutput println(long c) {
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
}