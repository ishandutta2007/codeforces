
import java.io.*;
import java.util.*;

public class CF966E {
    static final int INF = (int) 1e8;
    static final int MOD = (int) 1e9 + 7;
    public static BlockReader input;
    public static PrintStream output;
    public static Debug debug;
    static final Integer ZERO = 0;

/*    public static Integer getInteger(int v) {
        return INTEGER_MAP[v + 100001];
    }*/

    public static void main(String[] args) throws FileNotFoundException {
        init();

        solve();

        destroy();
    }

    public static void init() throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("E:\\DATABASE\\TESTCASE\\codeforces\\CF966E.in"));
            output = System.out;
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }

        debug = new Debug();
        debug.enter("main");
    }

    public static void solve() {
        int n = input.nextInteger();
        int m = input.nextInteger();

        ReuseHashMap.init(n * 2);

        Node[] nodes = new Node[n + 1];
        for (int i = 1; i <= n; i++) {
            Node node = new Node();
            node.id = i;
            nodes[i] = node;
        }

        for (int i = 2; i <= n; i++) {
            nodes[i].father = nodes[input.nextInteger()];
            nodes[i].father.children.add(nodes[i]);
        }

        for (int i = 1; i <= n; i++) {
            nodes[i].happy = input.nextInteger();
        }


        SimpleList<Node> trace = new SimpleList<>(new Node[2 * n]);
        Deque<Node> deque = new ArrayDeque<>(n);
        dfs(nodes[1], trace, 1);
        St<Node> st = new St(trace.data, trace.size(), NODE_COMPARATOR);


        trace.clear();
        Request[] req = new Request[m + 1];
        int offset = 0;
        int threshold = (int) Math.sqrt(n) + 1;
        for (int i = 1; i <= m; i++) {
            Request request = new Request();
            int event = input.nextInteger();
            request.leave = event > 0;
            request.node = nodes[Math.abs(event)];
            req[i] = request;
            if (i - offset == threshold || i == m) {
                deque.clear();
                trace.clear();
                ReuseHashMap.reset();
                handleRequest(req, offset + 1, i + 1, i, st, trace, deque, nodes[1]);

                offset = i;
            }
        }

        int last = 0;
        for (int i = 1; i <= m; i++) {
            last += req[i].ans;
            output.print(last);
            output.print(' ');
        }
    }

    public static void handleRequest(Request[] req, int reqBegin, int reqEnd, int version, St<Node> st,
                                     SimpleList<Node> list, Deque<Node> queue, Node root) {
        for (int i = reqBegin; i < reqEnd; i++) {
            Node node = req[i].node;
            if (node.version != version) {
                node.setVersion(version);
                list.add(node);
            }
        }


        list.sort(NODE_COMPARATOR);
        for (int i = 1, until = list.size(); i < until; i++) {
            Node lca = st.query(list.get(i - 1).order, list.get(i).order);
            if (lca.version != version) {
                lca.setVersion(version);
                list.add(lca);
            }
        }

        if (root.version != version) {
            root.setVersion(version);
            list.add(root);
        }

        list.sort(NODE_COMPARATOR);
        queue.addLast(list.get(0));
        for (int i = 1, until = list.size(); i < until; i++) {
            Node node = list.get(i);
            while (st.query(queue.peekLast().order, node.order) != queue.peekLast()) {
                queue.removeLast();
            }
            node.virtualFather = queue.peekLast();
            queue.add(node);
        }

        for (Node node : list) {
            Node virtualFather = node.virtualFather == null ? node.father : node.virtualFather;
            ReuseHashMap<Integer> cntMap = new ReuseHashMap(node.height - (virtualFather == null ? 0 : virtualFather.height));
            Node trace = node;
            while (trace != virtualFather) {
                if (!trace.onVacation) {
                    Integer key = trace.happy;
                    cntMap.update(key, 1);
                }
                trace = trace.father;
            }
            node.countMap = cntMap;
        }

        for (int i = reqBegin; i < reqEnd; i++) {
            Request request = req[i];
            Node start = request.node;
            int change = 0;
            if (request.leave) {
                start.onVacation = true;
                if (start.happy + start.happyChange < 0) {
                    change--;
                }
                start.countMap.update(start.happy, -1);
                int direction = -1;
                Node trace = start;
                while (trace != null) {
                    Map<Integer, Integer> map = trace.countMap;
                    trace.happyChange += direction;
                    int boundary = -1 - trace.happyChange;
                    change += trace.countMap.getOrDefault(boundary, ZERO);
                    trace = trace.virtualFather;
                }

            } else {
                start.onVacation = false;
                if (start.happy + start.happyChange < 0) {
                    change++;
                }
                start.countMap.update(start.happy, 1);
                int direction = 1;
                Node trace = start;
                while (trace != null) {
                    Map<Integer, Integer> map = trace.countMap;
                    trace.happyChange += direction;
                    int boundary = 0 - trace.happyChange;
                    change -= trace.countMap.getOrDefault(boundary, ZERO);
                    trace = trace.virtualFather;
                }
            }
            request.ans = change;
        }

        for (Node node : list) {
            Node virtualFather = node.virtualFather == null ? node.father : node.virtualFather;
            Node trace = node;
            int change = node.happyChange;
            while (trace != virtualFather) {
                trace.happy += change;
                trace = trace.father;
            }
        }
    }

    static final Comparator<Node> NODE_COMPARATOR = new Comparator<Node>() {
        @Override
        public int compare(Node o1, Node o2) {
            return o1.order - o2.order;
        }
    };

    public static void destroy() {
        output.flush();
        debug.exit();
        debug.statistic();
    }

    public static void dfs(Node node, List<Node> trace, int height) {
        node.order = trace.size();
        node.height = height;
        trace.add(node);
        for (Node child : node.children) {
            dfs(child, trace, height + 1);
            trace.add(node);
        }
    }

    public static class Request {
        Node node;
        boolean leave;
        int ans;
    }

    public static class Node {
        List<Node> children = new ArrayList<>(1);
        Node father;
        int id;
        int order;
        int happy;
        int version;
        int happyChange;
        int height;
        Node virtualFather;
        boolean onVacation;
        ReuseHashMap<Integer> countMap;

        public void setVersion(int version) {
            this.version = version;
            happyChange = 0;
            countMap = null;
        }

        @Override
        public String toString() {
            return "" + id;
        }
    }

    public static class St<T> {
        //st[i][j] means the min value between [i, i + 2^j),
        //so st[i][j] equals to min(st[i][j - 1], st[i + 2^(j - 1)][j - 1])
        Object[][] st;
        Comparator<T> comparator;


        public St(Object[] data, int length, Comparator<T> comparator) {
            int m = floorLog2(length);
            st = new Object[length][m + 1];
            this.comparator = comparator;
            for (int i = 0; i < length; i++) {
                st[i][0] = data[i];
            }
            for (int i = 0; i < m; i++) {
                int interval = 1 << i;
                for (int j = 0; j < length; j++) {
                    if (j + interval < length) {
                        st[j][i + 1] = min((T) st[j][i], (T) st[j + interval][i]);
                    } else {
                        st[j][i + 1] = st[j][i];
                    }
                }
            }
        }

        public static int floorLog2(int x) {
            return 31 - Integer.numberOfLeadingZeros(x);
        }

        private T min(T a, T b) {
            return comparator.compare(a, b) <= 0 ? a : b;
        }

        public static int ceilLog2(int x) {
            return 32 - Integer.numberOfLeadingZeros(x - 1);
        }

        /**
         * query the min value in [left,right]
         */
        public T query(int left, int right) {
            int queryLen = right - left + 1;
            int bit = floorLog2(queryLen);
            //x + 2^bit == right + 1
            //So x should be right + 1 - 2^bit - left=queryLen - 2^bit
            return min((T) st[left][bit], (T) st[right + 1 - (1 << bit)][bit]);
        }
    }

    public static class ReuseHashMap<K> extends AbstractMap<K, Integer> {
        private static class ReuseEntry<K, V> implements Entry<K, V> {
            int hash;
            K key;
            V val;
            ReuseEntry former;
            ReuseEntry next;

            @Override
            public K getKey() {
                return key;
            }

            @Override
            public V getValue() {
                return val;
            }

            @Override
            public V setValue(V value) {
                V origin = val;
                val = value;
                return origin;
            }
        }

        static ReuseEntry[] entriesQueue;
        static SimpleList<ReuseEntry> cellList;
        static int entriesQueueHead;
        static int cellListHead;

        int mask;
        List<ReuseEntry> list;
        int size;

        @Override
        public Integer getOrDefault(Object key, Integer defaultValue) {
            int hash = hash(key);
            int index = getCellIndex(hash);
            ReuseEntry<K, Integer> reuseEntry = findEntry(key, hash, index);
            return reuseEntry == null ? defaultValue : reuseEntry.val;
        }

        public void update(K key, int val) {
            int hash = hash(key);
            int index = getCellIndex(hash);
            ReuseEntry<K, Integer> reuseEntry = findEntry(key, hash, index);
            if (reuseEntry != null) {
                reuseEntry.val = reuseEntry.val + val;
            } else {
                ReuseEntry<K, Integer> entry = (ReuseEntry<K, Integer>) allocate();
                entry.hash = hash;
                entry.key = key;
                entry.val = val;
                ReuseEntry<K, Integer> cellHead = list.get(index);
                if (cellHead != null) {
                    cellHead.former = entry;
                }
                entry.next = cellHead;
                list.set(index, entry);
            }
        }

        @Override
        public Set<Entry<K, Integer>> entrySet() {
            return new AbstractSet<Entry<K, Integer>>() {
                @Override
                public Iterator<Entry<K, Integer>> iterator() {
                    return new Iterator<Entry<K, Integer>>() {
                        int index = 0;
                        ReuseEntry entry = list.get(0);

                        @Override
                        public boolean hasNext() {
                            if (entry == null) {
                                findNext();
                            }
                            return entry != null;
                        }

                        public ReuseEntry<K, Integer> findNext() {
                            if (entry != null) {
                                entry = entry.next;
                            }
                            while (entry == null && index <= mask) {
                                entry = list.get(index++);
                            }
                            return entry;
                        }

                        @Override
                        public Entry<K, Integer> next() {
                            Entry res = entry;
                            findNext();
                            return res;
                        }
                    };
                }

                @Override
                public int size() {
                    return size;
                }
            };
        }

        public static void init(int cacheSize) {
            entriesQueue = new ReuseEntry[cacheSize];
            for (int i = 0; i < cacheSize; i++) {
                entriesQueue[i] = new ReuseEntry();
            }
            cellList = new SimpleList<>(new ReuseEntry[cacheSize * 2]);
        }

        public static void reset() {
            entriesQueueHead = 0;
            cellListHead = 0;
        }

        public ReuseHashMap(int cap) {
            int properSize = 1 << (32 - Integer.numberOfLeadingZeros(cap));
            cellList.fill(cellListHead, properSize + cellListHead, null);
            this.list = cellList.subList(cellListHead, properSize + cellListHead);
            cellListHead += properSize;
            mask = properSize - 1;

        }

        @Override
        public int size() {
            return size;
        }

        @Override
        public boolean isEmpty() {
            return size == 0;
        }

        @Override
        public boolean containsKey(Object key) {
            int hash = hash(key);
            int index = getCellIndex(hash);
            ReuseEntry<K, Integer> reuseEntry = findEntry(key, hash, index);
            return reuseEntry != null;
        }

        @Override
        public Integer get(Object key) {
            int hash = hash(key);
            int index = getCellIndex(hash);
            ReuseEntry<K, Integer> reuseEntry = findEntry(key, hash, index);
            return reuseEntry == null ? null : reuseEntry.val;
        }

        @Override
        public Integer put(K key, Integer value) {
            int hash = hash(key);
            int index = getCellIndex(hash);
            ReuseEntry<K, Integer> reuseEntry = findEntry(key, hash, index);
            if (reuseEntry != null) {
                return reuseEntry.setValue(value);
            } else {
                ReuseEntry<K, Integer> entry = (ReuseEntry<K, Integer>) allocate();
                entry.hash = hash;
                entry.key = key;
                entry.val = value;
                ReuseEntry<K, Integer> cellHead = list.get(index);
                if (cellHead != null) {
                    cellHead.former = entry;
                }
                entry.next = cellHead;
                list.set(index, entry);
                return null;
            }
        }

        public static ReuseEntry allocate() {
            ReuseEntry entry = entriesQueue[entriesQueueHead++];
            entry.former = entry.next = null;
            return entry;
        }

        @Override
        public Integer remove(Object key) {
            int hash = hash(key);
            int index = getCellIndex(hash);
            ReuseEntry<K, Integer> reuseEntry = findEntry(key, hash, index);
            if (reuseEntry == null) {
                return null;
            }
            if (reuseEntry.former != null) {
                reuseEntry.former.next = reuseEntry.next;
            } else {
                list.set(index, reuseEntry.next);
            }
            if (reuseEntry.next != null) {
                reuseEntry.next.former = reuseEntry.former;
            }
            return reuseEntry.val;
        }

        public ReuseEntry<K, Integer> findEntry(Object key, int hash, int index) {
            ReuseEntry<K, Integer> trace = list.get(index);
            while (trace != null) {
                if (trace.hash == hash && Objects.equals(key, trace.key)) {
                    return trace;
                }
                trace = trace.next;
            }
            return null;
        }

        public int getCellIndex(int hash) {
            return hash & mask;
        }

        static final int hash(Object key) {
            int h;
            return (key == null) ? 0 : key.hashCode();
        }
    }

    public static class SimpleList<T> extends AbstractList<T> {
        T[] data;
        int size;

        public SimpleList(T[] data) {
            this.data = data;
        }

        public void fill(int from, int to, T v) {
            Arrays.fill(data, from, to, v);
        }

        @Override
        public boolean add(T t) {
            data[size++] = t;
            return true;
        }

        @Override
        public void sort(Comparator<? super T> c) {
            Arrays.sort(data,  0, size, c);
        }

        @Override
        public T get(int index) {
            return data[index];
        }

        @Override
        public int size() {
            return size;
        }

        public static class ArrayIterator<T> implements Iterator<T> {
            T[] data;
            int index;
            int end;

            public ArrayIterator(T[] data, int begin, int end) {
                this.data = data;
                this.index = begin;
                this.end = end;
            }

            @Override
            public boolean hasNext() {
                return index < end;
            }

            @Override
            public T next() {
                return data[index++];
            }
        }

        public static class SubList<T> extends AbstractList<T> {
            final T[] data;
            final int from;
            final int to;

            public SubList(T[] data, int from, int to) {
                this.data = data;
                this.from = from;
                this.to = to;
            }

            @Override
            public T set(int index, T element) {
                return data[from + index] = element;
            }

            @Override
            public Iterator<T> iterator() {
                return new ArrayIterator<>(data, from, to);
            }

            @Override
            public List<T> subList(int fromIndex, int toIndex) {
                return new SubList(data, from + fromIndex, from + toIndex);
            }

            @Override
            public boolean isEmpty() {
                return to == from;
            }

            @Override
            public T get(int index) {
                return data[from + index];
            }

            @Override
            public int size() {
                return to - from;
            }
        }

        @Override
        public T set(int index, T element) {
            data[index] = element;
            return null;
        }

        @Override
        public void clear() {
            size = 0;
        }


        @Override
        public Iterator<T> iterator() {
            return new ArrayIterator<>(data, 0, size);
        }

        @Override
        public List<T> subList(int fromIndex, int toIndex) {
            return new SubList(data, fromIndex, toIndex);
        }
    }

    public static class Sortable {
        private static final int THRESHOLD = 4;

        public static <T> void randomizedQuickSort(T[] data, Comparator<T> cmp, int f, int t) {
            Random random = new Random();
            int len = t - f;
            for (int i = len - 1; i >= 0; i--) {
                int rand = random.nextInt(i + 1);
                swap(data, f + rand, f + i);
            }
            quickSort(data, cmp, f, t);
        }

        public static <T> void quickSort(T[] data, Comparator<T> cmp, int f, int t) {
            if (t - f < 2) {
                //insertSort(data, cmp, f, t);
                return;
            }
            T rule = data[f];
            int l = f;
            int r = t;
            for (int i = f + 1; i < r; ) {
                int cmpRes = cmp.compare(data[i], rule);
                if (cmpRes < 0) {
                    swap(data, l++, i);
                } else if (cmpRes > 0) {
                    swap(data, --r, i);
                } else {
                    i++;
                }
            }
            quickSort(data, cmp, f, l);
            quickSort(data, cmp, r, t);
        }

        public static <T> void mergeSort(T[] data, Comparator<T> cmp, int f, int t, T[] buf) {
            if (t - f < THRESHOLD) {
                insertSort(data, cmp, f, t);
                return;
            }

            int m = (f + t) >> 1;
            mergeSort(data, cmp, f, m, buf);
            mergeSort(data, cmp, m, t, buf);

            int lIndex = f;
            int rIndex = m;
            int bIndex = 0;
            while (lIndex < m && rIndex < t) {
                int cmpRes = cmp.compare(data[lIndex], data[rIndex]);
                if (cmpRes <= 0) {
                    buf[bIndex++] = data[lIndex++];
                } else {
                    buf[bIndex++] = data[rIndex++];
                }
            }
            while (lIndex < m) {
                buf[bIndex++] = data[lIndex++];
            }
            while (rIndex < m) {
                buf[bIndex++] = data[rIndex++];
            }

            System.arraycopy(buf, 0, data, f, bIndex);
        }

        public static <T> void selectSort(T[] data, Comparator<T> cmp, int f, int t) {
            for (int i = f; i < t; i++) {
                int minIndex = i;
                for (int j = i + 1; j < t; j++) {
                    if (cmp.compare(data[minIndex], data[j]) > 0) {
                        minIndex = j;
                    }
                }
                swap(data, minIndex, i);
            }
        }

        public static <T> void swap(T[] data, int i, int j) {
            T tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }

        public static <T> void insertSort(T[] data, Comparator<T> cmp, int f, int t) {
            for (int i = f + 1; i < t; i++) {
                T v = data[i];
                int j = i - 1;
                while (j >= f && cmp.compare(v, data[j]) < 0) {
                    data[j + 1] = data[j];
                    j--;
                }
                data[j + 1] = v;
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