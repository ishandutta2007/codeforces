

import java.io.*;
import java.util.*;

/**
 * Created by dalt on 2018/5/25.
 */
public class CF976F {
    static final int INF = (int) 1e8;
    static final int MOD = (int) 1e9 + 7;
    public static BlockReader input;
    public static PrintStream output;
    public static Debug debug;

    public static void main(String[] args) throws FileNotFoundException {

        init();

        solve();

        destroy();
    }

    public static void init() throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("E:\\DATABASE\\TESTCASE\\codeforces\\CF976F.in"));
            output = System.out;
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }

        debug = new Debug();
        debug.enter("main");
    }

    public static void solve() {
        int n1 = input.nextInteger();
        int n2 = input.nextInteger();
        int m = input.nextInteger();

        int sourceId = n1 + n2 + 1;
        int targetId = n1 + n2 + 2;
        ISAP isap = new ISAP(n1 + n2 + 2);


        ISAP.DirectChannel[] source2 = new ISAP.DirectChannel[n1 + 1];
        ISAP.DirectChannel[] toTarget = new ISAP.DirectChannel[n2 + 1];
        int[] degrees = new int[1 + n1 + n2];

        for (int i = 1; i <= n1; i++) {
            source2[i] = isap.buildChannel(sourceId, i, 0, 0);
        }
        for (int i = 1; i <= n2; i++) {
            toTarget[i] = isap.buildChannel(n1 + i, targetId, 0, 0);
        }
        ISAP.DirectChannel[] middle = new ISAP.DirectChannel[m + 1];
        for (int i = 1; i <= m; i++) {
            int a = input.nextInteger();
            int b = input.nextInteger() + n1;
            middle[i] = isap.buildChannel(a, b, 1, i);
            degrees[a]++;
            degrees[b]++;
        }

        isap.setSource(sourceId);
        isap.setTarget(targetId);


        int minDegree = INF;
        for (int i = 1, until = degrees.length; i < until; i++) {
            minDegree = Math.min(minDegree, degrees[i]);
        }

        output.println(0);
        for (int i = 1; i <= minDegree; i++) {
            for (int j = 1; j <= n1; j++) {
                source2[j].setCapacity(i);
            }
            for (int j = 1; j <= n2; j++) {
                toTarget[j].setCapacity(i);
            }

            isap.source.distance = 3;
            isap.target.distance = 0;
            for (int j = 1; j <= n1; j++) {
                isap.nodes[j].distance = 2;
            }
            for (int j = n1 + 1, until = n1 + n2; j <= until; j++) {
                isap.nodes[j].distance = 1;
            }
            Arrays.fill(isap.distanceCnt, 0);
            isap.distanceCnt[0] = 1;
            isap.distanceCnt[1] = n2;
            isap.distanceCnt[2] = n1;
            isap.distanceCnt[3] = 1;

            int flow = isap.sendFlow(INF);
            Arrays.fill(degrees, 0);
            int edges = 0;
            for (int j = 1; j <= m; j++) {
                ISAP.DirectChannel channel = middle[j];
                if (channel.getFlow() == 0) {
                    continue;
                }
                edges++;
                degrees[channel.getSrc().id]++;
                degrees[channel.getDst().id]++;
            }
            output.print(i * (n1 + n2) - edges);
            output.print(' ');
            for (int j = 1; j <= m; j++) {
                ISAP.DirectChannel channel = middle[j];
                if (channel.getFlow() == 0) {
                    int src = channel.getSrc().id;
                    int dst = channel.getDst().id;
                    if (degrees[src] < i || degrees[dst] < i) {
                        degrees[src]++;
                        degrees[dst]++;
                        output.print(j);
                        output.print(' ');
                    }
                } else {
                    output.print(j);
                    output.print(' ');
                }
            }

            output.println();
        }
    }

    public static void destroy() {
        output.flush();
        debug.exit();
        debug.statistic();
    }

    public static class ISAP {
        int inf;
        Node[] nodes;
        int[] distanceCnt;
        Node source;
        Node target;
        int nodeNum;

        public ISAP(int nodeNum) {
            this.nodeNum = nodeNum;
            nodes = new Node[nodeNum + 1];
            distanceCnt = new int[nodeNum + 2];
            inf = nodeNum;
            for (int i = 1; i <= nodeNum; i++) {
                Node node = new Node();
                node.id = i;
                nodes[i] = node;
            }
        }

        public int sendFlow(int flow) {
            int flowSnapshot = flow;
            while (flow > 0 && source.distance < inf) {
                flow -= send(source, flow);
            }
            return flowSnapshot - flow;
        }

        public int send(Node node, int flowRemain) {
            if (node == target) {
                return flowRemain;
            }

            int flowSnapshot = flowRemain;
            int nextDistance = node.distance - 1;
            for (Channel channel : node.channelList) {
                int channelRemain = channel.getCapacity() - channel.getFlow();
                Node dst = channel.getDst();
                if (channelRemain == 0 || dst.distance != nextDistance) {
                    continue;
                }
                int actuallySend = send(channel.getDst(), Math.min(flowRemain, channelRemain));
                channel.sendFlow(actuallySend);
                flowRemain -= actuallySend;
                if (flowRemain == 0) {
                    break;
                }
            }

            if (flowSnapshot == flowRemain) {
                if (--distanceCnt[node.distance] == 0) {
                    distanceCnt[source.distance]--;
                    source.distance = inf;
                    distanceCnt[source.distance]++;
                    if (node != source) {
                        distanceCnt[++node.distance]++;
                    }
                } else {
                    distanceCnt[++node.distance]++;
                }
            }

            return flowSnapshot - flowRemain;
        }

        public void setSource(int id) {
            source = nodes[id];
        }

        public void setTarget(int id) {
            target = nodes[id];
        }

        public DirectChannel buildChannel(int a, int b, int flow, int id) {
            return Node.buildChannel(nodes[a], nodes[b], flow, id);
        }

        public void bfs(Deque<Node> queue) {
            Arrays.fill(distanceCnt, 0);
            queue.clear();

            for (int i = 1; i <= nodeNum; i++) {
                nodes[i].distance = inf;
            }

            target.distance = 0;
            queue.addLast(target);

            while (!queue.isEmpty()) {
                Node head = queue.removeFirst();
                distanceCnt[head.distance]++;
                for (Channel channel : head.channelList) {
                    Channel inverse = channel.getInverse();
                    if (inverse.getCapacity() == inverse.getFlow()) {
                        continue;
                    }
                    Node dst = channel.getDst();
                    if (dst.distance != inf) {
                        continue;
                    }
                    dst.distance = head.distance + 1;
                    queue.addLast(dst);
                }
            }
        }

        public static interface Channel {
            public Node getSrc();

            public Node getDst();

            public int getCapacity();

            public int getFlow();

            public void sendFlow(int volume);

            public Channel getInverse();
        }

        public static class DirectChannel implements Channel {
            final Node src;
            final Node dst;
            final int id;
            int capacity;
            int flow;
            Channel inverse;

            public DirectChannel(Node src, Node dst, int capacity, int id) {
                this.src = src;
                this.dst = dst;
                this.capacity = capacity;
                this.id = id;
                inverse = new InverseChannelWrapper(this);
            }

            @Override
            public String toString() {
                return String.format("%s--%s/%s-->%s", getSrc(), getFlow(), getCapacity(), getDst());
            }

            @Override
            public Node getSrc() {
                return src;
            }

            @Override
            public Channel getInverse() {
                return inverse;
            }


            public void setCapacity(int expand) {
                capacity = expand;
            }

            @Override
            public Node getDst() {
                return dst;
            }

            @Override
            public int getCapacity() {
                return capacity;
            }

            @Override
            public int getFlow() {
                return flow;
            }

            @Override
            public void sendFlow(int volume) {
                flow += volume;
            }


        }

        public static class InverseChannelWrapper implements Channel {
            final Channel channel;

            public InverseChannelWrapper(Channel channel) {
                this.channel = channel;
            }

            @Override
            public Channel getInverse() {
                return channel;
            }


            @Override
            public Node getSrc() {
                return channel.getDst();
            }

            @Override
            public Node getDst() {
                return channel.getSrc();
            }

            @Override
            public int getCapacity() {
                return channel.getFlow();
            }

            @Override
            public int getFlow() {
                return 0;
            }

            @Override
            public void sendFlow(int volume) {
                channel.sendFlow(-volume);
            }


            @Override
            public String toString() {
                return String.format("%s--%s/%s-->%s", getSrc(), getFlow(), getCapacity(), getDst());
            }
        }

        public static class Node {
            int id;
            int distance;
            List<Channel> channelList = new ArrayList<>(1);

            public static DirectChannel buildChannel(Node src, Node dst, int capacity, int id) {
                DirectChannel channel = new DirectChannel(src, dst, capacity, id);
                src.channelList.add(channel);
                dst.channelList.add(channel.getInverse());
                return channel;
            }

            @Override
            public String toString() {
                return "" + id;
            }
        }
    }

    public static class Debug {
        boolean debug = System.getProperty("ONLINE_JUDGE") == null;
        Deque<ModuleRecorder> stack = new ArrayDeque<>();
        Map<String, Module> fragmentMap = new HashMap<>();

        public void enter(String module) {
            if (debug) {
                stack.push(new ModuleRecorder(getModule(module)));
            }
        }

        public Module getModule(String moduleName) {
            Module module = fragmentMap.get(moduleName);
            if (module == null) {
                module = new Module(moduleName);
                fragmentMap.put(moduleName, module);
            }
            return module;
        }

        public void exit() {
            if (debug) {
                ModuleRecorder fragment = stack.pop();
                fragment.exit();
            }
        }

        public void statistic() {
            if (!debug) {
                return;
            }

            if (stack.size() > 0) {
                throw new RuntimeException("Exist unexited tag");
            }
            System.out.println("\n------------------------------------------");

            System.out.println("memory used " + ((Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()) >> 20) + "M");

            System.out.println("\n------------------------------------------");
            for (Module module : fragmentMap.values()) {
                System.out.println(String.format("Module %s : enter %d : cost %d", module.moduleName, module.enterTime, module.totaltime));
            }

            System.out.println("------------------------------------------");
        }

        public static class ModuleRecorder {
            Module fragment;
            long time;

            public ModuleRecorder(Module fragment) {
                this.fragment = fragment;
                time = System.currentTimeMillis();
            }

            public void exit() {
                fragment.totaltime += System.currentTimeMillis() - time;
                fragment.enterTime++;
            }
        }

        public static class Module {
            String moduleName;
            long totaltime;
            long enterTime;

            public Module(String moduleName) {
                this.moduleName = moduleName;
            }
        }
    }

    public static class BlockReader {
        static final int EOF = -1;
        InputStream is;
        byte[] dBuf;
        int dPos, dSize, next;
        StringBuilder builder = new StringBuilder();

        public BlockReader(InputStream is) {
            this(is, 8192);
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