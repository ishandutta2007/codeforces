import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
	
	static int maxn = 1010;
	static int n;
	static int a[][] = new int[maxn][maxn];
	static double f[] = new double[maxn];
	static double p[] = new double[maxn];
	static double tot[] = new double[maxn];
	static double t[][] = new double[maxn][maxn];
	
    public static void main(String[] args) {
    	n = Input.nextInt();
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < n; j++) {
    			a[i][j] = Input.nextInt();
    		}
    	}
    	for (int i = 0; i < n - 1; i++) {
    		if (a[i][n - 1] > 0) f[i] = 100.0 / a[i][n - 1];
    		else f[i] = 1e9;
    	}
    	ArrayList<Integer> v = new ArrayList<Integer>();
    	ArrayList<Integer> r = new ArrayList<Integer>();
    	for (int i = 0; i < n; i++) {
    		r.add(i); p[i] = 1;
    	}
    	while (r.size() > 0) {
    		for (int i = 0; i < r.size(); i++) {
    			int u = r.get(i);
    			if (v.size() > 0) {
    				int k = v.get(v.size() - 1);
    				t[u][k] = p[u] * a[u][k] / 100.0;
    				tot[u] += t[u][k] * f[k];
    				p[u] *= 1 - a[u][k] / 100.0;
    				if (p[u] < 1) f[u] = (tot[u] + 1) / (1 - p[u]);
    			}
    		}
    		Collections.sort(r, new Comparator<Integer>() {
    			public int compare(Integer i, Integer j) {
    				if (f[j] - f[i] > 0) return 1;
    				if (f[j] - f[i] < 0) return -1;
    				return 0;
    			}
    		});
    		v.add(r.get(r.size() - 1)); r.remove(r.size() - 1);
    	}
    	System.out.printf("%.6f", f[0]);
    }
    
    private static class Input {
    	private static StringTokenizer token = null;
    	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
//    	private static BufferedReader in;
//    	static {
//    		try {
//                in = new BufferedReader(new FileReader("in.txt"));
//            } catch (IOException e) {
//            }
//    	}
        
        public static final int nextInt() {
            return Integer.parseInt(nextString());
        }

        public static final long nextLong() {
            return Long.parseLong(nextString());
        }

        public static final double nextDouble() {
            return Double.parseDouble(nextString());
        }

        public static final String nextString() {
            try {
                while (token == null || !token.hasMoreTokens()) {
                    token = new StringTokenizer(in.readLine());
                }
            } catch (IOException e) {
            }
            return token.nextToken();
        }
    }
}