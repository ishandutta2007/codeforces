import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
	
	static int maxn = 100010;
	static int n;
	static int a[] = new int[maxn];
	
    public static void main(String[] args) {
    	n = Input.nextInt();
    	for (int i = 0; i < n; i++) {
    		a[i] = Input.nextInt();
    	}
    	for (int i = 1; 2 * i < n; i++) {
    		if (n % i == 0) {
    			int f[] = new int[i];
    			for (int j = 0; j < n; j++) {
    				f[j % i] += a[j];
    			}
    			for (int j = 0; j < i; j++) {
    				if (f[j] == n / i) {
    					System.out.print("YES");
    					return;
    				}
    			}
    		}
    	}
    	System.out.print("NO");
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