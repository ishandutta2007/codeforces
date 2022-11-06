import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PushbackInputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

/**
 * Created by dalt on 2017/7/29.
 */
public class FourMelodies {
    public static void main(String[] args) throws IOException {
        AcmInputReader reader = new AcmInputReader(System.in);

        int n = reader.nextInteger();
        ResidualNet net = new ResidualNet(2 + n * 4);

        {
            List<Integer>[] m7registries = new List[7];
            for (int i = 0; i < 7; i++) {
                m7registries[i] = new LinkedList<Integer>();
                m7registries[i].add(0);
            }
            Map<Integer, List<Integer>> equalRegistries = new TreeMap<>();
            int inf = 100000000;
            for (int i = 0; i < n; i++) {
                int input = reader.nextInteger();

                int m7 = i * 4 + 2;
                int equal = m7 + 1;
                int occupy_in = m7 + 2;
                int occupy_out = m7 + 3;

                //Clear the registry
                int m7Value = input % 7;
                for (int src : m7registries[m7Value]) {
                    net.buildEdge(src, m7, inf, 0);
                }
                m7registries[m7Value].clear();

                List<Integer> registry = equalRegistries.get(input);
                if (registry == null) {
                    registry = new LinkedList<>();
                    equalRegistries.put(input, registry);
                }
                for (Integer src : registry) {
                    net.buildEdge(src, equal, inf, 0);
                }
                registry.clear();
                //Build inner edge
                net.buildEdge(m7, occupy_in, 1, 0);
                net.buildEdge(equal, occupy_in, 1, 0);
                net.buildEdge(occupy_in, occupy_out, 1, -1);

                //Register for some slots
                m7registries[m7Value].add(m7);
                m7registries[m7Value].add(occupy_out);
                registry.add(equal);
                registry = equalRegistries.get(input - 1);
                if (registry == null) {
                    registry = new LinkedList<>();
                    equalRegistries.put(input - 1, registry);
                }
                registry.add(occupy_out);
                registry = equalRegistries.get(input + 1);
                if (registry == null) {
                    registry = new LinkedList<>();
                    equalRegistries.put(input + 1, registry);
                }
                registry.add(occupy_out);
            }

            //Redirect all remain registries into sink point
            for (int i = 0; i < 7; i++) {
                for (int src : m7registries[i]) {
                    if (src != 0) {
                        net.buildEdge(src, 1, inf, 0);
                    }
                }
            }
            for (List<Integer> list : equalRegistries.values()) {
                for (int src : list) {
                    net.buildEdge(src, 1, inf, 0);
                }
            }
        }

        //Now we have build the net graph successfully
        //Then we should do preparation for append flow
        prepare(net);
        for (int i = 0; i < 4; i++) {
            //validate(net);
            sendMinCostOneUnitFlow(net);
        }

        int totalPrice = net.totalPrice();
        System.out.println(-totalPrice);
    }

    public static void validate(ResidualNet net) {
        for (ResidualNet.INetNode node : net.getAllNodes()) {
            for (ResidualNet.INetEdge edge : node.getEdges()) {
                if (edge.valid() && edge.weightedPrice() < 0) {
                    throw new AssertionError();
                }
            }
        }
    }

    public static void prepare(ResidualNet net) {
        ResidualNet.INetNode[] nodes = net.getAllNodes();
        nodes[0].setWeight(0);
        for (ResidualNet.INetNode src : nodes) {
            int srcWeight = src.getWeight();
            for (ResidualNet.INetEdge edge : src.getEdges()) {
                if (!edge.valid()) {
                    continue;
                }
                ResidualNet.INetNode target = edge.targetNode();
                int targetWeight = edge.targetNode().getWeight();
                int newWeight = srcWeight + edge.unitPrice();
                if (newWeight < targetWeight) {
                    target.setWeight(newWeight);
                }
            }
        }
    }

    public static void sendMinCostOneUnitFlow(ResidualNet net) {
        //First step, build a min heap
        ResidualNet.INetNode[] nodes = net.getAllNodes();
        KeyHeap.Key[] keyOutput = new KeyHeap.Key[nodes.length];
        Pair<Integer, ResidualNet.INetNode>[] shortestDistanceFromSrc = new Pair[nodes.length];
        int inf = 100000000;
        Integer infPack = Integer.valueOf(inf);
        shortestDistanceFromSrc[0] = new Pair<>(Integer.valueOf(0), nodes[0]);
        ResidualNet.INetEdge[] parentEdges = new ResidualNet.INetEdge[nodes.length];
        for (int i = 1, bound = nodes.length; i < bound; i++) {
            shortestDistanceFromSrc[i] = new Pair<>(infPack, nodes[i]);
        }
        KeyHeap heap = new KeyHeap(shortestDistanceFromSrc, keyOutput, new Comparator<Object>() {
            @Override
            public int compare(Object o1, Object o2) {
                return ((Pair<Integer, ResidualNet.INetNode>) o1).key.compareTo(((Pair<Integer, ResidualNet.INetNode>) o2).key);
            }
        });

        //Then pop all nodes from shortestDistanceFromSrc
        while (!heap.isEmpty()) {
            Pair<Integer, ResidualNet.INetNode> pair = (Pair<Integer, ResidualNet.INetNode>) heap.pop();
            if (pair.key.intValue() < inf) {
                shortestDistanceFromSrc[pair.value.getId()] = pair;
                //Reduce the shortest distance to all node follow edges whose source is pair.value
                for (ResidualNet.INetEdge edge : pair.value.getEdges()) {
                    if (!edge.valid()) {
                        continue;
                    }
                    int newDistance = edge.weightedPrice() + pair.key;
                    ResidualNet.INetNode targetNode = edge.targetNode();
                    KeyHeap.Key targetKey = keyOutput[targetNode.getId()];
                    if (((Pair<Integer, ResidualNet.INetNode>) targetKey.getValue()).key > newDistance) {
                        targetKey.update(new Pair<Integer, ResidualNet.INetNode>(newDistance, edge.targetNode()));
                        parentEdges[targetNode.getId()] = edge;
                    }
                }
            } else {
                break;
            }
        }

        //Now we have find all the shortest distance to each node, we should expand the flow in the shortest distance road from src to sink
        ResidualNet.INetEdge edge = parentEdges[1];
        while (edge != null) {
            edge.appendFlow(1);
            edge = parentEdges[edge.sourceNode().getId()];
        }

        //Then recalculate all weight
        for (int i = 0, bound = nodes.length; i < bound; i++) {
            int newWeight = nodes[i].getWeight() + shortestDistanceFromSrc[i].key;
            nodes[i].setWeight(Math.min(newWeight, inf));
        }
    }

    public static class Pair<K, V> {
        public final K key;
        public final V value;

        public Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }
    }

    /**
     * Created by dalt on 2017/7/29.
     */
    public static class KeyHeap {
        private Comparator<Object> comparator;
        private Key[] keys;
        private int remain;

        public KeyHeap(Object[] data, Key[] keyOutput, Comparator<Object> comparator) {
            remain = data.length;
            this.comparator = comparator;

            if (data == null) {
                throw new IllegalArgumentException();
            }
            if (comparator == null) {
                throw new IllegalArgumentException();
            }
            keys = new Key[data.length];
            for (int i = 0, bound = data.length; i < bound; i++) {
                keys[i] = new Key(data[i], i);
            }
            if (keyOutput != null) {
                System.arraycopy(keys, 0, keyOutput, 0, Math.min(keys.length, keyOutput.length));
            }
            Arrays.sort(keys, new Comparator<Key>() {
                @Override
                public int compare(Key o1, Key o2) {
                    return comparator.compare(o1.getValue(), o2.getValue());
                }
            });
        }

        public KeyHeap(int capacity, Comparator<Object> comparator) {
            if (capacity < 0) {
                throw new IllegalArgumentException();
            }
            if (comparator == null) {
                throw new IllegalArgumentException();
            }
            keys = new Key[capacity];
            this.comparator = comparator;
        }

        public Object peek() {
            if (remain <= 0) {
                throw new IllegalStateException();
            }
            return keys[0].value;
        }

        public int size() {
            return remain;
        }

        public Object pop() {
            if (remain <= 0) {
                throw new IllegalStateException();
            }
            Key result = keys[0];
            remain--;
            inject(keys[remain], 0);
            keys[remain] = null;
            downward(0);
            return result.value;
        }

        public Key push(Object value) {
            if (remain == keys.length) {
                throw new IllegalStateException();
            }
            Key newKey = new Key(value, remain);
            keys[remain] = newKey;
            remain++;
            upward(newKey.index);
            return newKey;
        }


        public void clear() {
            for (int i = 0; i < remain; i++) {
                keys[i].removed = true;
                keys[i] = null;
            }
            remain = 0;
        }

        private void downward(int target) {
            if(target < 0 || target >= remain)
            {
                return;
            }
            Key targetKey = keys[target];
            while (true) {
                int lindex = target << 1;
                int rindex = (target << 1) | 1;
                if (lindex >= remain) {
                    break;
                }
                if (rindex >= remain) {
                    rindex = lindex;
                }
                Key left = keys[lindex];
                Key right = keys[rindex];
                if (comparator.compare(left.value, right.value) < 0) {
                    if (comparator.compare(left.value, targetKey.value) < 0) {
                        inject(left, target);
                        target = lindex;
                    } else {
                        break;
                    }
                } else {
                    if (comparator.compare(right.value, targetKey.value) < 0) {
                        inject(right, target);
                        target = rindex;
                    } else {
                        break;
                    }
                }
            }
            inject(targetKey, target);
        }

        private void inject(Key key, int i) {
            keys[i] = key;
            key.index = i;
        }

        private void upward(int target) {
            if(target < 0 || target >= remain)
            {
                return;
            }

            Key targetKey = keys[target];
            while (target > 0) {
                int pindex = target >> 1;
                Key parent = keys[pindex];
                if (comparator.compare(targetKey.value, parent.value) < 0) {
                    inject(parent, target);
                    target = pindex;
                } else {
                    break;
                }
            }
            inject(targetKey, target);
        }

        public boolean isEmpty() {
            return remain == 0;
        }

        private void remove(int index) {
            keys[index].removed = true;
            keys[index] = keys[--remain];
            keys[remain] = null;
            downward(index);
        }

        public class Key {
            boolean removed = false;
            private int index;
            private Object value;

            public Key(Object value, int index) {
                this.value = value;
                this.index = index;
            }

            public Object getValue() {
                return value;
            }

            public void remove() {
                if (removed) {
                    throw new IllegalStateException();
                }
                KeyHeap.this.remove(index);
            }

            public void update(Object value) {
                if (removed) {
                    throw new IllegalStateException();
                }
                int cmp = comparator.compare(value, this.value);
                this.value = value;
                if (cmp < 0) {
                    upward(index);
                } else if (cmp > 0) {
                    downward(index);
                }
            }
        }
    }

    /**
     * @author dalt
     * @see java.lang.AutoCloseable
     * @since java1.7
     */
    private static class AcmInputReader implements AutoCloseable {
        private PushbackInputStream in;

        /**
         * 
         *
         * @param input 
         */
        public AcmInputReader(InputStream input) {
            in = new PushbackInputStream(new BufferedInputStream(input));
        }

        @Override
        public void close() throws IOException {
            in.close();
        }

        private int nextByte() throws IOException {
            return in.read() & 0xff;
        }

        /**
         * b
         *
         * @param b 
         * @throws IOException if 
         */
        public void skipByte(int b) throws IOException {
            int c;
            if ((c = nextByte()) != b) {
                in.unread(c);
            }
        }

        /**
         * kbk{@literal k<times}
         *
         * @param b     
         * @param times -1
         * @throws IOException if 
         */
        public void skipByte(int b, int times) throws IOException {
            int c;
            while ((c = nextByte()) == b && times > 0) {
                times--;
            }
            if (c != b) {
                in.unread(c);
            }
        }

        /**
         * {@link #skipByte(int, int)}, 
         *
         * @param b     
         * @param times -1
         * @throws IOException if 
         */
        public void skipBlankAndByte(int b, int times) throws IOException {
            int c;
            skipBlank();
            while ((c = nextByte()) == b && times > 0) {
                times--;
                skipBlank();
            }
            if (c != b) {
                in.unread(c);
            }
        }

        /**
         * 
         *
         * @return 
         * @throws IOException if 
         */
        public String nextBlock() throws IOException {
            skipBlank();
            StringBuilder sb = new StringBuilder();
            int c = nextByte();
            while (AsciiMarksLazyHolder.asciiMarks[c = nextByte()] != AsciiMarksLazyHolder.BLANK_MARK) {
                sb.append((char) c);
            }
            in.unread(c);
            return sb.toString();
        }

        /**
         * 
         *
         * @throws IOException if 
         */
        private void skipBlank() throws IOException {
            int c;
            while ((c = nextByte()) <= 32) ;
            in.unread(c);
        }

        /**
         * 
         *
         * @return 
         * @throws IOException if 
         */
        public int nextInteger() throws IOException {
            skipBlank();
            int value = 0;
            boolean positive = true;
            int c = nextByte();
            if (AsciiMarksLazyHolder.asciiMarks[c] == AsciiMarksLazyHolder.SIGN_MARK) {
                positive = c == '+';
            } else {
                value = '0' - c;
            }
            c = nextByte();
            while (AsciiMarksLazyHolder.asciiMarks[c] == AsciiMarksLazyHolder.NUMERAL_MARK) {
                value = (value << 3) + (value << 1) + '0' - c;
                c = nextByte();
            }

            in.unread(c);
            return positive ? -value : value;
        }

        /**
         * 
         *
         * @return truefalse
         * @throws IOException if 
         */
        public boolean isMeetEOF() throws IOException {
            int c = nextByte();
            if (AsciiMarksLazyHolder.asciiMarks[c] == AsciiMarksLazyHolder.EOF) {
                return true;
            }
            in.unread(c);
            return false;
        }

        /**
         * 
         *
         * @return truefalse
         * @throws IOException if 
         */
        public boolean isMeetBlankAndEOF() throws IOException {
            skipBlank();
            int c = nextByte();
            if (AsciiMarksLazyHolder.asciiMarks[c] == AsciiMarksLazyHolder.EOF) {
                return true;
            }
            in.unread(c);
            return false;
        }

        /**
         * 
         *
         * @return 
         */
        public String nextWord() throws IOException {
            StringBuilder sb = new StringBuilder(16);
            skipBlank();
            int c;
            while ((AsciiMarksLazyHolder.asciiMarks[(c = nextByte())] & AsciiMarksLazyHolder.LETTER_MARK) != 0) {
                sb.append((char) c);
            }
            in.unread(c);
            return sb.toString();
        }

        /**
         * 
         *
         * @return 
         * @throws IOException if 
         */
        public long nextLong() throws IOException {
            skipBlank();
            long value = 0;
            boolean positive = true;
            int c = nextByte();
            if (AsciiMarksLazyHolder.asciiMarks[c] == AsciiMarksLazyHolder.SIGN_MARK) {
                positive = c == '+';
            } else {
                value = '0' - c;
            }
            c = nextByte();
            while (AsciiMarksLazyHolder.asciiMarks[c] == AsciiMarksLazyHolder.NUMERAL_MARK) {
                value = (value << 3) + (value << 1) + '0' - c;
                c = nextByte();
            }
            in.unread(c);
            return positive ? -value : value;
        }

        /**
         * 
         *
         * @return 
         * @throws IOException if 
         */
        public float nextFloat() throws IOException {
            return (float) nextDouble();
        }

        /**
         * 
         *
         * @return 
         * @throws IOException if 
         */
        public double nextDouble() throws IOException {
            skipBlank();
            double value = 0;
            boolean positive = true;
            int c = nextByte();
            if (AsciiMarksLazyHolder.asciiMarks[c] == AsciiMarksLazyHolder.SIGN_MARK) {
                positive = c == '+';
            } else {
                value = c - '0';
            }
            c = nextByte();
            while (AsciiMarksLazyHolder.asciiMarks[c] == AsciiMarksLazyHolder.NUMERAL_MARK) {
                value = value * 10.0 + c - '0';
                c = nextByte();
            }

            if (c == '.') {
                double littlePart = 0;
                double base = 1;
                c = nextByte();
                while (AsciiMarksLazyHolder.asciiMarks[c] == AsciiMarksLazyHolder.NUMERAL_MARK) {
                    littlePart = littlePart * 10.0 + c - '0';
                    base *= 10.0;
                    c = nextByte();
                }
                value += littlePart / base;
            }
            in.unread(c);
            return positive ? value : -value;
        }

        /**
         * 
         *
         * @return 
         * @throws IOException if 
         */
        public BigDecimal nextDecimal() throws IOException {
            skipBlank();
            StringBuilder sb = new StringBuilder();
            sb.append((char) nextByte());
            int c = nextByte();
            while (AsciiMarksLazyHolder.asciiMarks[c] == AsciiMarksLazyHolder.NUMERAL_MARK) {
                sb.append((char) c);
                c = nextByte();
            }
            if (c == '.') {
                sb.append('.');
                c = nextByte();
                while (AsciiMarksLazyHolder.asciiMarks[c] == AsciiMarksLazyHolder.NUMERAL_MARK) {
                    sb.append((char) c);
                    c = nextByte();
                }
            }
            in.unread(c);
            return new BigDecimal(sb.toString());
        }

        /**
         * 
         *
         * @return 
         * @throws IOException if 
         */
        public BigInteger nextBigInteger() throws IOException {
            skipBlank();
            StringBuilder sb = new StringBuilder();
            sb.append((char) nextByte());
            int c = nextByte();
            while (AsciiMarksLazyHolder.asciiMarks[c] == AsciiMarksLazyHolder.NUMERAL_MARK) {
                sb.append((char) c);
                c = nextByte();
            }
            in.unread(c);
            return new BigInteger(sb.toString());
        }

        private static class AsciiMarksLazyHolder {
            public static final byte BLANK_MARK = 1;
            public static final byte SIGN_MARK = 1 << 1;
            public static final byte NUMERAL_MARK = 1 << 2;
            public static final byte UPPERCASE_LETTER_MARK = 1 << 3;
            public static final byte LOWERCASE_LETTER_MARK = 1 << 4;
            public static final byte LETTER_MARK = UPPERCASE_LETTER_MARK | LOWERCASE_LETTER_MARK;
            public static final byte EOF = 1 << 5;
            public static byte[] asciiMarks = new byte[256];

            static {
                for (int i = 0; i <= 32; i++) {
                    asciiMarks[i] = BLANK_MARK;
                }
                asciiMarks['+'] = SIGN_MARK;
                asciiMarks['-'] = SIGN_MARK;
                for (int i = '0'; i <= '9'; i++) {
                    asciiMarks[i] = NUMERAL_MARK;
                }
                for (int i = 'a'; i <= 'z'; i++) {
                    asciiMarks[i] = LOWERCASE_LETTER_MARK;
                }
                for (int i = 'A'; i <= 'Z'; i++) {
                    asciiMarks[i] = UPPERCASE_LETTER_MARK;
                }
                asciiMarks[0xff] = EOF;
            }
        }
    }

    private static class ResidualNet {

        private WeightedNetNode[] nodes;

        /**
         * Build a residual net with nodeNum nodes. The source node will be allocated id 0, and the target node will be allocated id 1.
         * Other nodes follow the sequence.
         *
         * @param nodeNum the total node num of this residual net work.
         */
        public ResidualNet(int nodeNum) {
            nodes = new WeightedNetNode[nodeNum];
            for (int i = 0; i < nodeNum; i++) {
                nodes[i] = new WeightedNetNode(i);
            }
        }

        public INetNode[] getAllNodes() {
            return nodes;
        }

        public void buildEdge(int from, int to, int capcity, int unitPrice) {
            if (from == 1 || to == 0) {
                throw new IllegalArgumentException("Illegal source node for " + from + " with target node for " + to + " to build a edge");
            }
            if (from == to) {
                throw new IllegalArgumentException("You can't build an edge between same node");
            }
            INetEdge edge = new ObeyNetEdge(nodes[from], nodes[to], unitPrice, capcity);
            nodes[from].addEdge(edge);
            nodes[to].addEdge(edge.reverseEdge());
        }

        public int totalPrice() {
            int totalPrice = 0;
            for (WeightedNetNode node : nodes) {
                for (INetEdge edge : node.getEdges()) {
                    totalPrice += edge.totalPrice();
                }
            }
            return totalPrice;
        }

        public static interface INetEdge {
            public INetNode sourceNode();

            public INetNode targetNode();

            public int unitPrice();

            public int totalPrice();

            public int weightedPrice();

            public INetEdge reverseEdge();

            public int capacity();

            public int flow();

            public void appendFlow(int inc);

            public int remain();

            public boolean valid();
        }

        public static interface INetNode {
            public int getId();

            public Iterable<INetEdge> getEdges();

            public int getWeight();

            public void setWeight(int weight);
        }

        public static abstract class AbstractNetEdge implements INetEdge {
            public int weightedPrice() {
                return unitPrice() + sourceNode().getWeight() - targetNode().getWeight();
            }

            @Override
            public boolean valid() {
                return remain() > 0;
            }

            public int flow() {
                return capacity() - remain();
            }

            @Override
            public int totalPrice() {
                return unitPrice() * flow();
            }

            @Override
            public String toString() {
                return String.format("to %d, price %d, flow %d, remain %d", targetNode().getId(), weightedPrice(), flow(), remain());
            }
        }

        public static class ObeyNetEdge extends AbstractNetEdge {
            private INetNode source;
            private INetNode target;
            private int price;
            private int capacity;
            private int remain;
            private RevoltedNetEdge revoltedGEdge = new RevoltedNetEdge(this);

            public ObeyNetEdge(INetNode source, INetNode target, int price, int capacity) {
                this.source = source;
                this.target = target;
                this.price = price;
                this.capacity = capacity;
                this.remain = capacity;
            }

            @Override
            public void appendFlow(int inc) {
                this.remain -= inc;
            }

            @Override
            public INetNode sourceNode() {
                return source;
            }

            @Override
            public INetNode targetNode() {
                return target;
            }

            @Override
            public int unitPrice() {
                return price;
            }

            @Override
            public INetEdge reverseEdge() {
                return revoltedGEdge;
            }

            @Override
            public int capacity() {
                return capacity;
            }

            @Override
            public int remain() {
                return remain;
            }
        }

        public static class RevoltedNetEdge extends AbstractNetEdge {
            private ObeyNetEdge edge;

            public RevoltedNetEdge(ObeyNetEdge edge) {
                this.edge = edge;
            }

            @Override
            public INetNode sourceNode() {
                return edge.targetNode();
            }

            @Override
            public void appendFlow(int inc) {
                edge.appendFlow(-inc);
            }

            @Override
            public INetNode targetNode() {
                return edge.sourceNode();
            }

            @Override
            public int unitPrice() {
                return -edge.unitPrice();
            }

            @Override
            public INetEdge reverseEdge() {
                return edge;
            }

            @Override
            public int capacity() {
                return edge.capacity();
            }

            @Override
            public int remain() {
                return edge.flow();
            }

            @Override
            public int flow() {
                return 0;
            }
        }

        public static class WeightedNetNode implements INetNode {
            private LinkedList<INetEdge> edges;
            private int id;
            private int weight;

            public WeightedNetNode(int id) {
                this.id = id;
                edges = new LinkedList<INetEdge>();
            }

            public void addEdge(INetEdge edge) {
                edges.add(edge);
            }

            @Override
            public Iterable<INetEdge> getEdges() {
                return edges;
            }

            @Override
            public int getId() {
                return id;
            }

            @Override
            public int getWeight() {
                return weight;
            }

            @Override
            public void setWeight(int weight) {
                this.weight = weight;
            }

            @Override
            public String toString() {
                return Integer.toString(id);
            }
        }
    }
}