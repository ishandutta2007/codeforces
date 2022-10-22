import java.util.*;
import java.io.*; 
public class Main 
{
	public static void main(String[] args) throws IOException {
		int t = nextInt();
		for (int cse = 1; cse <= t; cse++) {
			int n = nextInt();
			int[] a = new int[n+1], psa = new int[n+1];
			String s = next();
			for (int i = 1; i <= n; i++) {
				a[i] = Integer.parseInt(s.charAt(i-1)+"");
				psa[i] = psa[i-1] + a[i];
			}
			long ans = 0;
			HashMap<Integer,Integer> mp = new HashMap<>();
			for (int i = 1; i <= n; i++) {
				int rVal = psa[i-1] - i + 1;
				mp.put(rVal,mp.getOrDefault(rVal,0)+1);
				int lVal = psa[i] - i;
				ans += mp.getOrDefault(lVal,0);
			}
			//L <= R, psa[R] - R = psa[L-1] - L + 1
			System.out.println(ans);
		}
	}
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}
	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
}