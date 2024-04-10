import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;


public class E {
    
    static int inf = (1 << 30);
    
    public static void main(String arg[]) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskE {
    
    static int inf = (1 << 30);
    
    public void solve(int testNumber, InputReader in, PrintWriter  out) {
        int n = in.nextInt(), m = in.nextInt(), num = in.nextInt(), q = in.nextInt();
        
        int[][][] best = new int[10][2][2];
        
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 2; j++)
                for(int k = 0; k < 2; k++)
                    best[i][j][k] = -inf;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int w = in.nextInt();
                best[w][0][0] = Math.max(best[w][0][0], -i - j);
                best[w][0][1] = Math.max(best[w][0][1], -i + j);
                best[w][1][0] = Math.max(best[w][1][0], i - j);
                best[w][1][1] = Math.max(best[w][1][1], i + j);
            }
        }
        int[][] dis = new int[10][10];
        
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 10; j++) {
                dis[i][j] = -inf;
                for(int k = 0; k < 2; k++)
                    for(int l = 0; l < 2; l++) {
                        dis[i][j] = Math.max(dis[i][j], best[i][k][l] + best[j][k ^ 1][l ^ 1]);
                    }
            }
        
        int ans = -inf;
        for(int last = -1, i = 0; i < q; i++) {
            int x = in.nextInt();
            if (last != -1) {
                ans = Math.max(dis[x][last], ans);
            }
            last = x;
        }
        System.out.println(ans);
    }
};

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

}