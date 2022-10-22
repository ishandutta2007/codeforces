import java.util.*;

public class Div2B{
	void solve(){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), k = sc.nextInt();
		long ans = 0;
		int[] sec = new int[n];
		for (int i = 0; i < n; i++){
			int a = sc.nextInt(), b = sc.nextInt();
			int mn = Math.min(a, b);
			ans += mn;
			b -= mn;
			sec[i] = Math.min(a, b);
		}
		Arrays.sort(sec);
		for (int i = n-1; i >= n-k; i--)
			ans += sec[i];
		System.out.println(ans);
	}
	public static void main(String[] args){
		Div2B sol = new Div2B();
		sol.solve();
	}
}