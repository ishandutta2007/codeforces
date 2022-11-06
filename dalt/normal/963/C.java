
import java.io.*;
import java.util.*;

public class CF963C {
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
            input = new BlockReader(new FileInputStream("E:\\DATABASE\\TESTCASE\\codeforces\\CF963C.in"));
            output = System.out;
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }

        debug = new Debug();
        debug.enter("main");
    }

    public static void solve() {
        Map<Long, List<Rect>> rectListMap = new HashMap();

        int n = input.nextInteger();
        for (int i = 0; i < n; i++) {
            Rect rect = new Rect();
            rect.w = input.nextLong();
            rect.h = input.nextLong();
            rect.cnt = input.nextLong();

            List<Rect> list = rectListMap.get(rect.h);
            if (list == null) {
                list = new ArrayList<>(1);
                rectListMap.put(rect.h, list);
            }
            list.add(rect);
        }

        List<Rect>[] rectLists = rectListMap.values().toArray(new List[0]);
        Comparator<Rect> comparator = new Comparator<Rect>() {
            @Override
            public int compare(Rect o1, Rect o2) {
                return Long.compare(o1.w, o2.w);
            }
        };

        //Check whether we can build a valid rect with these fragments

        long cntg = rectLists[0].get(0).cnt;
        long[] ratio = null;
        long[] w = null;
        for (List<Rect> rectList : rectLists) {
            Collections.sort(rectList, comparator);

            long g = rectList.get(0).cnt;
            if (ratio == null) {
                ratio = new long[rectList.size()];
                w = new long[rectList.size()];
                for (Rect rect : rectList) {
                    g = gcd(g, rect.cnt);
                }
                for (int i = 0, until = ratio.length; i < until; i++) {
                    Rect rect = rectList.get(i);
                    ratio[i] = rect.cnt / g;
                    w[i] = rect.w;
                }
            } else {
                for (Rect rect : rectList) {
                    g = gcd(g, rect.cnt);
                }
                for (int i = 0, until = ratio.length; i < until; i++) {
                    Rect rect = rectList.get(i);
                    if (w[i] != rect.w || ratio[i] != rect.cnt / g) {
                        output.println("0");
                        return;
                    }
                }
            }

            cntg = gcd(cntg, g);
        }

        //Find the number of factors of hg which is the gcd of all heights of rects
        int cnt = 0;
        for (long i = 1; i * i <= cntg; i++) {
            if (cntg % i != 0) {
                continue;
            }
            cnt++;
            if (cntg != i * i) {
                cnt++;
            }
        }

        output.println(cnt);
    }

    public static void destroy() {
        output.flush();
        debug.exit();
        debug.statistic();
    }

    public static long gcd(long a, long b) {
        return a >= b ? gcd0(a, b) : gcd0(b, a);
    }

    public static long gcd0(long a, long b) {
        return b == 0 ? a : gcd0(b, a % b);
    }

    public static class Rect {
        long w;
        long h;
        long cnt;
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

        public long nextLong() {
            skipBlank();
            long ret = 0;
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