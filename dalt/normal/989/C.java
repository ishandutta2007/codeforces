

import java.io.*;
import java.nio.charset.Charset;
import java.util.Arrays;
import java.util.Comparator;

public class Contest487C {
    public static void main(String[] args) throws FileNotFoundException {
        boolean local = System.getProperty("ONLINE_JUDGE") == null;
        IOUtil io;
        if (local) {
            io = new IOUtil(new FileInputStream("E:\\DATABASE\\TESTCASE\\codeforces\\Contest487C.in"), new FileOutputStream("E:\\DATABASE\\TESTCASE\\codeforces\\Contest487C.out"));
        } else {
            io = new IOUtil(System.in, System.out);
        }

        Task task = new Task(io);
        task.run();
        io.flush();
    }

    public static class Task implements Runnable {
        IOUtil io;

        public Task(IOUtil io) {
            this.io = io;
        }

        @Override
        public void run() {
            int[][] colors = new int[4][2];
            int[][] colors2 = new int[4][2];
            for (int i = 0; i < 4; i++) {
                colors[i][0] = 'A' + i;
                colors[i][1] = io.readInt();

                colors2[i] = colors[i].clone();
            }

            Arrays.sort(colors, new Comparator<int[]>() {
                @Override
                public int compare(int[] o1, int[] o2) {
                    return o1[1] - o2[1];
                }
            });


            char[][] map = new char[50][50];
            for (int i = 0; i < 50; i++) {
                Arrays.fill(map[i], (char) colors[0][0]);
            }
            colors[0][1]--;

            int r, c;
            for (r = 2; colors[0][1] > 0; r += 4) {
                for (c = 0; colors[0][1] > 0 && c < 48; c += 2) {
                    map[r + 1][c] = (char) pickUp(colors);
                    map[r][c + 1] = (char) pickUp(colors);
                    map[r - 1][c] = (char) pickUp(colors);
                    colors[0][1]--;
                }
            }

            r += 2;
            c = 0;
            int next;
            while ((next = pickUp(colors)) != -1) {
                map[r][c] = (char) next;
                c += 2;
                if (c == 50) {
                    c = 0;
                    r += 2;
                }
            }

            io.write(50);
            io.write(' ');
            io.write(50);
            io.write('\n');
            for (int i = 0; i < 50; i++) {
                io.write(String.valueOf(map[i]));
                io.write('\n');
            }
           // io.flush();

            boolean local = System.getProperty("ONLINE_JUDGE") == null;
            if (local) {
                int[][] components = new int[50][50];
                int[] total = new int[4];
                for (int i = 0; i < 50; i++) {
                    for (int j = 0; j < 50; j++) {
                        total[map[i][j] - 'A'] += dfs(components, map, i, j, map[i][j]);
                    }
                }

                for (int i = 0; i < 4; i++) {
                    if (colors2[i][1] != total[i]) {
                        throw new RuntimeException();
                    }
                }
            }



        }

        public static int dfs(int[][] comp, char[][] map, int i, int j, int color) {
            if (i < 0 || j < 0 || i >= 50 || j >= 50) {
                return 0;
            }

            if (comp[i][j] != 0 || map[i][j] != color) {
                return 0;
            }

            comp[i][j] = 1;
            dfs(comp, map, i + 1, j, color);
            dfs(comp, map, i - 1, j, color);
            dfs(comp, map, i, j + 1, color);
            dfs(comp, map, i, j - 1, color);

            return 1;
        }

        public static int pickUp(int[][] color) {
            for (int i = 1; i < 4; i++) {
                if (color[i][1] > 0) {
                    color[i][1]--;
                    return color[i][0];
                }
            }
            return -1;
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