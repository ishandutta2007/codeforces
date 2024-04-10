import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {
    BufferedReader br;
    PrintWriter out;
    StringTokenizer stok;

    String nextToken() throws IOException {
        while (stok == null || !stok.hasMoreTokens()) {
            String s = br.readLine();
            if (s == null) {
                return null;
            }
            stok = new StringTokenizer(s);
        }
        return stok.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    char nextChar() throws IOException {
        return (char) (br.read());
    }

    String nextLine() throws IOException {
        return br.readLine();
    }

    boolean check(int[] ans) {
        int[] a = new int[ans.length];
        int n = ans.length;
        a[0] = ans[0];
        for (int i = 1; i < n; i++) {
            a[i] = a[0];
            for (int j = 1; j <= i; j++) {
                a[i] = a[i] ^ a[j];
            }
        }

        for (int i = 1; i < n; i++) {
            if (a[i] > a[i - 1]) return false;
        }

        return true;
    }


    int[][] to = new int[2][100031 * 61];
    int[] cnt = new int[100031 * 61];
    int[] p = new int[100031 * 61];

    void solve() throws IOException {
        int n = nextInt();
        long[] b = new long[n];
        long[] ans = new long[n];
        for (int i = 0; i < n; i++) {
            b[i] = nextLong();
        }
        long xor = 0, count = 0;

        Arrays.fill(to[0], -1);
        Arrays.fill(to[1], -1);
        Arrays.fill(cnt, 0);
        Arrays.fill(p, -1);

        int m = 1;
        for (int i = 0; i < n; i++) {
            xor ^= b[i];

            int v = 0;
            for (int bit = 59; bit >= 0; bit--) {
                int k = (int) ((b[i] >> bit) & 1L);
                cnt[v]++;
                count++;
                if (to[k][v] == -1) {
                    p[m] = v;
                    to[k][v] = m++;
                }
                v = to[k][v];
            }
            cnt[v]++;
        }

        Arrays.fill(ans, -1);
        for (int i = 0; i < n; i++) {
            for (int bit = 0; bit <= 59; bit++) {
                if (((xor >> bit) & 1L) > 0) {
                    int cur = 0;
                    int pos = 60;
                    boolean flag = true;
                    while (pos > bit + 1) {
                        if (to[0][cur]== -1) {
                            flag = false;
                            break;
                        }
                        cur = to[0][cur];
                        pos--;
                    }
                    if (!flag || to[1][cur] == -1) continue;
                    cur = to[1][cur];
                    if (cnt[cur]== 0 || count == 0) continue;

                    long answ = 1L << bit;
                    for (int bit2 = bit - 1; bit2 >= 0; bit2--) {
                        int value = (int) ((xor >> bit2) & 1L);
                        if (to[value ^ 1][cur] == -1 || count == 0 || cnt[to[value ^ 1][cur]] == 0) {
                            if (count > 0 && value == 1) {
                                answ ^= 1L << bit2;
                            }
                            cur = to[value][cur];
                        } else {
                            if (value == 0) answ ^= 1L << bit2;
                            if (count == 0) {
                                cur = to[value][cur];
                            } else {
                                cur = to[value ^ 1][cur];
                            }
                        }
                    }

                    ans[i] = answ;
                    cnt[cur]--;
                    while (p[cur] != -1) {
                        cur = p[cur];
                        cnt[cur]--;
                    }
                    break;
                }
            }

            if (ans[i] == -1) {
                out.print("No");
                return;
            }

            xor ^= ans[i];
        }

        out.println("Yes");
        for (int i = n - 1; i >= 0; i--) {
            out.print(ans[i] + " ");
        }
    }

    void run() throws IOException {
//        long time = System.currentTimeMillis();
        // br = new BufferedReader(new FileReader("dragons.in"));
        //out = new PrintWriter("dragons.out");
        // br = new BufferedReader(new FileReader("input.txt"));
        // out = new PrintWriter("output.txt");
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        br.close();
        out.close();
//        System.err.println(System.currentTimeMillis() - time);
    }

    public static void main(String[] args) throws IOException {
        // Locale.setDefault(Locale.US);
        new C().run();
    }
}