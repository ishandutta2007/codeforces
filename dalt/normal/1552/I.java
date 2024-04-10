import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.lang.reflect.Field;
import java.nio.charset.StandardCharsets;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 29);
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
            IOrganizingAMusicFestival solver = new IOrganizingAMusicFestival();
            solver.solve(1, in, out);
            out.close();
        }
    }

    static class IOrganizingAMusicFestival {
        int mod = 998244353;

        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.ri();
            int m = in.ri();
            PQTree pqt = new PQTree(n);
            boolean[] set = new boolean[n];
            for (int i = 0; i < m; i++) {
                Arrays.fill(set, false);
                int q = in.ri();
                for (int j = 0; j < q; j++) {
                    set[in.ri() - 1] = true;
                }
                pqt.update(set);
            }
            if (!pqt.possible()) {
                out.println(0);
                return;
            }
            int[] res = pqt.getCounts();
            Factorial fact = new Factorial(n, mod);
            long ans = 1;
            for (int i = 0; i < res.length; i++) {
                for (int j = 0; j < res[i]; j++) {
                    ans = ans * fact.fact(i) % mod;
                }
            }
            out.println(ans);
        }

    }

    static class PQTree {
        PQTree.PQNode root;
        int n;

        public boolean possible() {
            return root != null;
        }

        public PQTree(int n) {
            this.n = n;
            PQTree.PQNode[] arr = new PQTree.PQNode[n];
            for (int i = 0; i < n; i++) {
                arr[i] = new PQTree.PQNode(i, null);
            }
            root = makeNode(arr, PQTree.PQNode.P_NODE);
        }

        public void update(boolean[] b) {
            if (root == null) {
                return;
            }
            int cnt = 0;
            for (boolean flag : b) {
                cnt += flag ? 1 : 0;
            }
            if (cnt <= 1 || cnt == b.length) {
                return;
            }
            root = root.dfs(b, cnt);
        }

        public String toString() {
            if (root == null) {
                return "null";
            }
            StringBuilder sb = new StringBuilder();
            root.genRepr(sb);
            return sb.toString();
        }

        public int[] getCounts() {
            assert possible();
            int[] ret = new int[n + 1];
            root.getCounts(ret);
            return ret;
        }

        static PQTree.PQNode[] collect(PQTree.PQNode[] arr, int whatStatus) {
            int sz = 0;
            for (PQTree.PQNode v : arr) {
                if (v.status == whatStatus) {
                    sz++;
                }
            }

            PQTree.PQNode[] ret = new PQTree.PQNode[sz];
            int ptr = 0;
            for (PQTree.PQNode v : arr) {
                if (v.status == whatStatus) {
                    ret[ptr++] = v;
                }
            }

            return ret;
        }

        static PQTree.PQNode makeNode(PQTree.PQNode[] arr, int whatType) {
            if (arr.length == 0) {
                return null;
            }
            if (arr.length == 1) {
                return arr[0];
            }
            if (arr.length == 2) {
                whatType = PQTree.PQNode.Q_NODE;
            }
            return new PQTree.PQNode(whatType, arr);
        }

        static <T> void fullCopy(T[] src, T[] dest, int destPos) {
            System.arraycopy(src, 0, dest, destPos, src.length);
        }

        static PQTree.PQNode[] appendFirst(PQTree.PQNode v, PQTree.PQNode[] arr) {
            if (v == null) {
                return arr;
            }
            PQTree.PQNode[] ret = new PQTree.PQNode[arr.length + 1];
            ret[0] = v;
            fullCopy(arr, ret, 1);
            return ret;
        }

        static PQTree.PQNode[] appendLast(PQTree.PQNode v, PQTree.PQNode[] arr) {
            if (v == null) {
                return arr;
            }
            PQTree.PQNode[] ret = new PQTree.PQNode[arr.length + 1];
            fullCopy(arr, ret, 0);
            ret[arr.length] = v;
            return ret;
        }

        static PQTree.PQNode[] concat(PQTree.PQNode[] arr1, PQTree.PQNode[] arr2) {
            PQTree.PQNode[] ret = new PQTree.PQNode[arr1.length + arr2.length];
            fullCopy(arr1, ret, 0);
            fullCopy(arr2, ret, arr1.length);
            return ret;
        }

        static <T> void reverse(T[] a) {
            for (int i = 0, j = a.length - 1; i < j; i++, j--) {
                T tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }

        static class PQNode {
            static final int P_NODE = -1;
            static final int Q_NODE = -2;
            int type;
            PQTree.PQNode[] child;
            static final int EMPTY = 0;
            static final int FULL = 1;
            static final int PARTIAL = 2;
            static final int CONTAINS_ALL = 3;
            int status;
            int count;

            public PQNode(int type, PQTree.PQNode[] child) {
                this.type = type;
                this.child = child;
            }

            PQTree.PQNode dfs(boolean[] b, int allQry) {

                if (type >= 0) {
                    status = b[type] ? FULL : EMPTY;
                    count = b[type] ? 1 : 0;
                    return this;
                }

                count = 0;

                boolean allFull = true;
                boolean allEmpty = true;
                int cntPartial = 0;
                int[] idxPartial = new int[2];

                for (int i = 0; i < child.length; i++) {
                    child[i] = child[i].dfs(b, allQry);
                    if (child[i] == null) {
                        return null;
                    }
                }

                for (int i = 0; i < child.length; i++) {
                    PQTree.PQNode v = child[i];

                    if (v.status == CONTAINS_ALL) {
                        status = CONTAINS_ALL;
                        return this;
                    }
                    allFull &= v.status == FULL;
                    allEmpty &= v.status == EMPTY;
                    if (v.status == PARTIAL) {
                        if (cntPartial == 2) {
                            return null;
                        }
                        idxPartial[cntPartial++] = i;
                    }
                    count += v.count;
                }

                boolean doesContainAll = count == allQry;

                if (allFull) {
                    status = FULL;
                    return this;
                }

                if (allEmpty) {
                    status = EMPTY;
                    return this;
                }

                if (cntPartial <= 1 && type == P_NODE && doesContainAll) {
                    PQTree.PQNode[] fulls = collect(child, FULL);
                    PQTree.PQNode[] emptys = collect(child, EMPTY);

                    PQTree.PQNode fullNode = makeNode(fulls, P_NODE);

                    PQTree.PQNode fullAndPartial;
                    if (cntPartial == 0) {
                        fullAndPartial = fullNode;
                    } else {
                        PQTree.PQNode[] arr = appendFirst(fullNode,
                                child[idxPartial[0]].child);
                        fullAndPartial = makeNode(arr, Q_NODE);
                    }

                    PQTree.PQNode[] arr = appendFirst(fullAndPartial, emptys);
                    PQTree.PQNode ret = makeNode(arr, P_NODE);
                    ret.status = CONTAINS_ALL;
                    return ret;
                }

                if (cntPartial <= 1 && type == P_NODE && !doesContainAll) {
                    PQTree.PQNode[] fulls = collect(child, FULL);
                    PQTree.PQNode[] emptys = collect(child, EMPTY);

                    PQTree.PQNode full = makeNode(fulls, P_NODE);
                    if (full != null) {
                        full.status = FULL;
                    }
                    PQTree.PQNode empty = makeNode(emptys, P_NODE);
                    if (empty != null) {
                        empty.status = EMPTY;
                    }

                    PQTree.PQNode ret;
                    if (cntPartial == 1) {
                        PQTree.PQNode[] arr = appendFirst(full,
                                appendLast(empty, child[idxPartial[0]].child));
                        ret = makeNode(arr, Q_NODE);
                    } else {
                        ret = makeNode(new PQTree.PQNode[]{full, empty}, Q_NODE);
                    }
                    ret.count = count;
                    ret.status = PARTIAL;
                    return ret;
                }

                if (cntPartial == 2 && type == P_NODE && doesContainAll) {
                    PQTree.PQNode[] fulls = collect(child, FULL);
                    PQTree.PQNode[] emptys = collect(child, EMPTY);

                    PQTree.PQNode fullNode = makeNode(fulls, P_NODE);

                    reverse(child[idxPartial[0]].child);

                    PQTree.PQNode[] tmp = appendLast(fullNode, child[idxPartial[0]].child);
                    PQTree.PQNode fullAndPartial = makeNode(
                            concat(tmp, child[idxPartial[1]].child), Q_NODE);

                    PQTree.PQNode[] arr = appendFirst(fullAndPartial, emptys);
                    PQTree.PQNode ret = makeNode(arr, P_NODE);
                    ret.status = CONTAINS_ALL;
                    return ret;
                }

                if (type == Q_NODE) {
                    int size = child.length;
                    for (int i = 0; i < cntPartial; i++) {
                        size += child[idxPartial[i]].child.length - 1;
                    }

                    PQTree.PQNode[] arr = new PQTree.PQNode[size];
                    int ptr = 0;

                    boolean firstPartial = true;
                    for (int i = 0; i < child.length; i++) {
                        PQTree.PQNode v = child[i];
                        if (v.status == PARTIAL) {

                            boolean shouldRev;
                            if (cntPartial == 1) {
                                if (i == 0) {
                                    shouldRev = child[i + 1].status == FULL;
                                } else {
                                    shouldRev = child[i - 1].status == EMPTY;
                                }
                            } else {
                                shouldRev = firstPartial;
                                firstPartial = !firstPartial;
                            }

                            if (shouldRev) {
                                reverse(v.child);
                            }

                            for (PQTree.PQNode u : v.child) {
                                arr[ptr++] = u;
                            }
                        } else {
                            arr[ptr++] = v;
                        }
                    }

                    if (arr[arr.length - 1].status == FULL) {
                        reverse(arr);
                    }

                    ptr = arr.length - 1;
                    while (ptr >= 0 && arr[ptr].status == EMPTY) {
                        ptr--;
                    }
                    while (ptr >= 0 && arr[ptr].status == FULL) {
                        ptr--;
                    }

                    if (ptr == -1) {
                        PQTree.PQNode ret = makeNode(arr, Q_NODE);
                        ret.count = count;
                        ret.status = doesContainAll ? CONTAINS_ALL : PARTIAL;
                        return ret;
                    }

                    while (ptr >= 0 && arr[ptr].status == EMPTY) {
                        ptr--;
                    }

                    if (ptr == -1 && doesContainAll) {
                        PQTree.PQNode ret = makeNode(arr, Q_NODE);
                        ret.status = CONTAINS_ALL;
                        return ret;
                    }
                }

                return null;
            }

            void genRepr(StringBuilder sb) {
                if (type >= 0) {
                    sb.append(type + " ");
                    return;
                }
                sb.append(type == P_NODE ? "[" : "(");
                for (PQTree.PQNode v : child) {
                    v.genRepr(sb);
                }
                sb.append(type == P_NODE ? "]" : ")");
            }

            void getCounts(int[] a) {
                if (type >= 0) {
                    return;
                }
                if (type == P_NODE) {
                    a[child.length]++;
                } else {
                    a[2]++;
                }
                for (PQTree.PQNode v : child) {
                    v.getCounts(a);
                }
            }

        }

    }

    static class FastOutput implements AutoCloseable, Closeable, Appendable {
        private static final int THRESHOLD = 32 << 10;
        private OutputStream writer;
        private StringBuilder cache = new StringBuilder(THRESHOLD * 2);
        private static Field stringBuilderValueField;
        private char[] charBuf = new char[THRESHOLD * 2];
        private byte[] byteBuf = new byte[THRESHOLD * 2];

        static {
            try {
                stringBuilderValueField = StringBuilder.class.getSuperclass().getDeclaredField("value");
                stringBuilderValueField.setAccessible(true);
            } catch (Exception e) {
                stringBuilderValueField = null;
            }
            stringBuilderValueField = null;
        }

        public FastOutput append(CharSequence csq) {
            cache.append(csq);
            return this;
        }

        public FastOutput append(CharSequence csq, int start, int end) {
            cache.append(csq, start, end);
            return this;
        }

        private void afterWrite() {
            if (cache.length() < THRESHOLD) {
                return;
            }
            flush();
        }

        public FastOutput(OutputStream writer) {
            this.writer = writer;
        }

        public FastOutput append(char c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(int c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput append(long c) {
            cache.append(c);
            afterWrite();
            return this;
        }

        public FastOutput println(int c) {
            return append(c).println();
        }

        public FastOutput println(long c) {
            return append(c).println();
        }

        public FastOutput println() {
            return append('\n');
        }

        public FastOutput flush() {
            try {
                if (stringBuilderValueField != null) {
                    try {
                        byte[] value = (byte[]) stringBuilderValueField.get(cache);
                        writer.write(value, 0, cache.length());
                    } catch (Exception e) {
                        stringBuilderValueField = null;
                    }
                }
                if (stringBuilderValueField == null) {
                    int n = cache.length();
                    if (n > byteBuf.length) {
                        //slow
                        writer.write(cache.toString().getBytes(StandardCharsets.UTF_8));
//                writer.append(cache);
                    } else {
                        cache.getChars(0, n, charBuf, 0);
                        for (int i = 0; i < n; i++) {
                            byteBuf[i] = (byte) charBuf[i];
                        }
                        writer.write(byteBuf, 0, n);
                    }
                }
                writer.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
            return this;
        }

        public void close() {
            flush();
            try {
                writer.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

        public String toString() {
            return cache.toString();
        }

    }

    static class Factorial {
        int[] fact;
        int[] inv;
        int mod;

        public Factorial(int[] fact, int[] inv, int mod) {
            this.mod = mod;
            this.fact = fact;
            this.inv = inv;
            fact[0] = inv[0] = 1;
            int n = Math.min(fact.length, mod);
            for (int i = 1; i < n; i++) {
                fact[i] = i;
                fact[i] = (int) ((long) fact[i] * fact[i - 1] % mod);
            }
            if (n - 1 >= 0) {
                inv[n - 1] = BigInteger.valueOf(fact[n - 1]).modInverse(BigInteger.valueOf(mod)).intValue();
            }
            for (int i = n - 2; i >= 1; i--) {
                inv[i] = (int) ((long) inv[i + 1] * (i + 1) % mod);
            }
        }

        public Factorial(int limit, int mod) {
            this(new int[Math.min(limit + 1, mod)], new int[Math.min(limit + 1, mod)], mod);
        }

        public int fact(int n) {
            if (n >= mod) {
                return 0;
            }
            return fact[n];
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

        public int ri() {
            return readInt();
        }

        public int readInt() {
            boolean rev = false;

            skipBlank();
            if (next == '+' || next == '-') {
                rev = next == '-';
                next = read();
            }

            int val = 0;
            while (next >= '0' && next <= '9') {
                val = val * 10 - next + '0';
                next = read();
            }

            return rev ? val : -val;
        }

    }
}