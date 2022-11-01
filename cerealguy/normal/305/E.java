import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;

public class E {

    static void solve() throws IOException {
        String s = nextToken();
        int winningMove = moveForFirst(s);
        if (winningMove >= 0) {
            out.println("First");
            out.println(winningMove + 1);
        } else {
            out.println("Second");
        }
    }

    private static int moveForFirst(String s) {
        int n = s.length();

        int[] grundy = new int[n + 2];

        int[] haveGrundy = new int[256];
        fill(haveGrundy, -1);

        for (int i = 0; i < grundy.length; i++) {
            for (int j = 1; j + 1 < i; j++) {
                int g1 = grundy[j];
                int g2 = grundy[i - 1 - j];
                haveGrundy[g1 ^ g2] = i;
            }
            int g = 0;
            while (haveGrundy[g] == i) {
                g++;
            }
            grundy[i] = g;
        }

        boolean[] good = new boolean[n];
        for (int i = 1; i < n - 1; i++) {
            if (s.charAt(i - 1) == s.charAt(i + 1)) {
                good[i] = true;
            }
        }

        int inputGrundy = 0;

        for (int i = 0; i < n;) {
            if (good[i]) {
                int j = i;
                while (good[j]) {
                    j++;
                }
                inputGrundy ^= grundy[j - i + 2];
                i = j;
            } else {
                i++;
            }
        }

        if (inputGrundy == 0) {
            return -1;
        }

        for (int i = 0; i < n;) {
            if (good[i]) {
                int j = i;
                while (good[j]) {
                    j++;
                }
                int g = grundy[j - i + 2];
                for (int move = 1; move < j - i + 1; move++) {
                    int gg = grundy[move] ^ grundy[j - i + 1 - move];
                    if ((inputGrundy ^ g ^ gg) == 0) {
                        return move + i - 1;
                    }
                }
                i = j;
            } else {
                i++;
            }
        }

        throw new AssertionError();
    }

    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;
        File file = new File("e.in");
        if (file.exists() && file.canRead()) {
            input = new FileInputStream(file);
        }
        br = new BufferedReader(new InputStreamReader(input));
        out = new PrintWriter(output);
        solve();
        out.close();
    }

    static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) {
                return null;
            }
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }
}