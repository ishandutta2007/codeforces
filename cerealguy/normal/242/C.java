
import java.io.*;
import java.util.*;

public class B {

static long toLong(int a, int b) {
return ((long)a<<32)+b;
}

    private static void solve() throws IOException {
   Set<Long> can = new HashSet<Long>();
int x0=nextInt(),y0 = nextInt(), x1 = nextInt(), y1 = nextInt();
int n = nextInt();
for (int ii = 0; ii < n; ii++) {
int row = nextInt();
int a = nextInt(), b = nextInt();
for(int i = a; i <= b; i++) {
can.add(toLong(row, i));
}
}
Queue<Integer> qx = new ArrayDeque<Integer>(), qy = new ArrayDeque<Integer>(), qd = new ArrayDeque<Integer>();
qx.add(x0);
qy.add(y0);
qd.add(0);
can.remove(toLong(x0,y0));
while (!qx.isEmpty()) {
int x = qx.poll(), y = qy.poll();
int d = qd.poll();
if(x ==x1 && y == y1) {
out.println(d);
return;
}
for(int dx=-1; dx<=1; dx++)
for(int dy=-1; dy<=1;dy++) {
int nx = x + dx, ny= y+dy;
long xy = toLong(nx,ny);
if(can.remove(xy)) {
qx.add(nx);
qy.add(ny);
qd.add(d+1);
}
}
}
out.println(-1);

    }
    
    public static void main(String[] args) {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
            solve();
            out.close();
        } catch (Throwable e) {
            e.printStackTrace();
            System.exit(239);
        }
    }

    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

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

    static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }
}