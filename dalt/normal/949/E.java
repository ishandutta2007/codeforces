

import java.io.*;
import java.util.*;

/**
 * Created by dalt on 2018/4/2.
 */
public class CF949E {
    public static final long MOD = (long) (1e9 + 7);
    public static BlockReader input;
    public static PrintStream output;
    static Integer[] targetTrace = new Integer[33];

    public static void main(String[] args) throws FileNotFoundException {
        if (System.getProperty("ONLINE_JUDGE") == null) {
            input = new BlockReader(new FileInputStream("D:\\DataBase\\TESTCASE\\codeforces\\CF949E.in"));
            output = System.out;
        } else {
            input = new BlockReader(System.in);
            output = new PrintStream(new BufferedOutputStream(System.out), false);
        }

        solve();

        output.flush();
    }

    public static void solve() {
        int n = input.nextInteger();
        Set<Integer> data = new HashSet<Integer>();
        for (int i = 0; i < n; i++) {
            data.add(input.nextInteger());
        }

        output.println(find(data, new ArrayDeque<>(22), 0));
        for (int bit : targetTrace) {
            output.print(bit);
            output.print(' ');
        }
    }


    public static int find(Set<Integer> set, Deque<Integer> trace, int depth) {
        if (set.size() == 1 && (set.contains(1) || set.contains(-1))) {
            trace.push(set.iterator().next() * (1 << depth));
            int r = find(Collections.emptySet(), trace, depth + 1) + 1;
            trace.pop();
            return r;
        }
        if (set.size() == 0) {
            if (trace.size() < targetTrace.length) {
                targetTrace = trace.toArray(new Integer[0]);
            }
            return 0;
        }

        Set<Integer> next = new HashSet<>();

        boolean hasOdd = false;
        for (int v : set) {
            if ((v & 1) == 1) {
                hasOdd = true;
                next.add((v - 1) >> 1);
            } else {
                next.add(v >> 1);
            }
        }
        next.remove(0);
        if (hasOdd == false) {
            return find(next, trace, depth + 1);
        } else {
            trace.push(1 << depth);
            int min = find(next, trace, depth + 1);
            trace.pop();
            trace.push(-(1 << depth));
            next.clear();
            for (int v : set) {
                if ((v & 1) == 1) {
                    next.add((v + 1) >> 1);
                } else {
                    next.add(v >> 1);
                }
            }
            next.remove(0);
            min = Math.min(find(next, trace, depth + 1), min) + 1;
            trace.pop();
            return min;
        }

    }


    public static class BlockReader {
        static final int EOF = -1;
        InputStream is;
        byte[] dBuf;
        int dPos, dSize, next;
        StringBuilder builder = new StringBuilder();

        public BlockReader(InputStream is) {
            this(is, 4096);
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