import java.io.*;
import java.util.*;

public class B {

    private static void solve() throws IOException {
   int n = nextInt(), edges = nextInt();
   List<Integer> e[] = new List[n];
   for(int i = 0; i < n; i++) {
   e[i] = new ArrayList<Integer>();e[i].add(i);
  
   }
   while(edges-->0) {
   int u = nextInt()-1, v = nextInt()-1;
   e[u].add(v); e[v].add(u);
   }
    int[] bad = new int[n];
    boolean[] use = new boolean[n];
    Queue<Integer> q = new ArrayDeque<Integer>();
    
   for(int i =0; i < n ; i++) {
   bad[i]= nextInt();
   if (bad[i]==0) q.add(i);
   }
   while(!q.isEmpty()) {
   int u = q.poll();
   if(bad[u]!=0) continue;
   for (int v: e[u]) {
   if(use[v]) continue;
   use[v]= true;
   for(int w: e[v]) {if(--bad[w]==0) q.add(w);}
   break;
   }
   }
   int cnt =0;
   for (int i = 0; i < n; i++) {
   if (use[i]) cnt++;
   }
   out.println(cnt);
   
   for(int i =0; i < n; i++) if(use[i]) out.print((i+1)+" ");
   
   
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