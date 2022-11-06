

import java.io.*;
import java.nio.charset.Charset;

public class Contest45C {
    public static void main(String[] args) throws FileNotFoundException {
        boolean local = System.getProperty("ONLINE_JUDGE") == null;
        IOUtil io;
        if (local) {
            io = new IOUtil(new FileInputStream("E:\\DATABASE\\TESTCASE\\codeforces\\Contest45C.in"), new FileOutputStream("E:\\DATABASE\\TESTCASE\\codeforces\\Contest45C.out"));
        } else {
            io = new IOUtil(System.in, System.out);
        }

        Task task = new Task(io);
        task.run();
        io.flush();
    }

    public static class Task implements Runnable {
        IOUtil io;
        int INF = (int) 1e8;

        public Task(IOUtil io) {
            this.io = io;
        }

        @Override
        public void run() {
            char[] data = new char[300000];
            int n = io.readInt();
            int[] bpos = new int[n];
            int[] epos = new int[n];

            int offset = 0;
            for (int i = 0; i < n; i++) {
                bpos[i] = offset;
                offset += io.readString(data, offset, INF);
                epos[i] = offset;
            }

            int[] leftCnt = new int[300001];
            int[] rightCnt = new int[300001];
            for (int i = 0; i < n; i++) {
                int dL = degreeL(data, bpos[i], epos[i]);
                int dR = degreeR(data, bpos[i], epos[i]);
                if (dL != -1) {
                    leftCnt[dL]++;
                }
                if (dR != -1) {
                    rightCnt[dR]++;
                }
            }

            long total = 0;
            for (int i = 0; i < 300001; i++) {
                total += (long) leftCnt[i] * rightCnt[i];
            }

            io.write(total);
        }

        public static void reverse(char[] data, int from, int to) {
            int l = from;
            int r = to - 1;
            while (l < r) {
                char tmp = data[l];
                data[l] = data[r];
                data[r] = tmp;
                l++;
                r--;
            }
        }

        public static int degreeL(char[] data, int from, int to) {
            int leftCnt = 0;
            for (int i = from; i < to; i++) {
                if (data[i] == '(') {
                    leftCnt++;
                } else {
                    if (leftCnt == 0) {
                        return -1;
                    }
                    leftCnt--;
                }
            }
            return leftCnt;
        }

        public static int degreeR(char[] data, int from, int to) {
            int rightCnt = 0;
            for (int i = to - 1; i >= from; i--) {
                if (data[i] == ')') {
                    rightCnt++;
                } else {
                    if (rightCnt == 0) {
                        return -1;
                    }
                    rightCnt--;
                }
            }
            return rightCnt;
        }
    }

    public static class IOUtil {
        private static int BUF_SIZE = 1 << 13;

        private byte[] r_buf = new byte[BUF_SIZE];
        private int r_cur;
        private int r_total;
        private int r_next;
        private final InputStream in;
        private StringBuilder temporary = new StringBuilder();

        StringBuilder w_buf = new StringBuilder();
        private final OutputStream out;

        public IOUtil(InputStream in, OutputStream out) {
            this.in = in;
            this.out = out;
        }

        private void skipBlank() {
            while (r_next <= 32) {
                r_next = read();
            }
        }

        public int readString(char[] data, int offset, int limit) {
            skipBlank();

            int originalLimit = limit;
            while (limit > 0 && r_next > 32) {
                data[offset++] = (char) r_next;
                limit--;
                r_next = read();
            }

            return originalLimit - limit;
        }

        public String readString(StringBuilder builder) {
            skipBlank();

            while (r_next > 32) {
                builder.append((char) r_next);
                r_next = read();
            }

            return builder.toString();
        }

        public String readString() {
            temporary.setLength(0);
            return readString(temporary);
        }

        public long readUnsignedLong() {
            skipBlank();

            long num = 0;
            while (r_next >= '0' && r_next <= '9') {
                num = num * 10 + r_next - '0';
                r_next = read();
            }
            return num;
        }

        public long readLong() {
            skipBlank();

            int sign = 1;
            while (r_next == '+' || r_next == '-') {
                if (r_next == '-') {
                    sign *= -1;
                }
                r_next = read();
            }

            return sign == 1 ? readUnsignedLong() : readNegativeLong();
        }

        public long readNegativeLong() {
            skipBlank();

            long num = 0;
            while (r_next >= '0' && r_next <= '9') {
                num = num * 10 - r_next + '0';
                r_next = read();
            }
            return num;
        }

        public int readUnsignedInt() {
            skipBlank();

            int num = 0;
            while (r_next >= '0' && r_next <= '9') {
                num = num * 10 + r_next - '0';
                r_next = read();
            }
            return num;
        }

        public int readNegativeInt() {
            skipBlank();

            int num = 0;
            while (r_next >= '0' && r_next <= '9') {
                num = num * 10 - r_next + '0';
                r_next = read();
            }
            return num;
        }

        public int readInt() {
            skipBlank();

            int sign = 1;
            while (r_next == '+' || r_next == '-') {
                if (r_next == '-') {
                    sign *= -1;
                }
                r_next = read();
            }

            return sign == 1 ? readUnsignedInt() : readNegativeInt();
        }

        public int read() {
            while (r_total <= r_cur) {
                try {
                    r_total = in.read(r_buf);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
                r_cur = 0;
                if (r_total == -1) {
                    return -1;
                }
            }
            return r_buf[r_cur++];
        }

        public void write(char c) {
            w_buf.append(c);
        }

        public void write(int n) {
            w_buf.append(n);
        }

        public void write(String s) {
            w_buf.append(s);
        }

        public void write(long s) {
            w_buf.append(s);
        }

        public void write(double s) {
            w_buf.append(s);
        }

        public void write(float s) {
            w_buf.append(s);
        }

        public void write(Object s) {
            w_buf.append(s);
        }

        public void write(char[] data, int offset, int cnt) {
            for (int i = offset, until = offset + cnt; i < until; i++) {
                write(data[i]);
            }
        }

        public void flush() {
            try {
                out.write(w_buf.toString().getBytes(Charset.forName("ascii")));
                w_buf.setLength(0);
                out.flush();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        public double readDouble() {
            return Double.parseDouble(readString());
        }
    }
}