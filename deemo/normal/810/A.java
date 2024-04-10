import java.util.*;

public class Div2A{
	void solve(){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), k = sc.nextInt(), sm = 0;
		for (int i = 0; i < n; i++)
			sm += sc.nextInt();
		int ans = 0;
		while (sm/(double)n < k-0.5){
			n++;
			ans++;
			sm += k;
		}
		System.out.println(ans);
	}
	public static void main(String[] args){
		Div2A sol = new Div2A();
		sol.solve();
	}
}