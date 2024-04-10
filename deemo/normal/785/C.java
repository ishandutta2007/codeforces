import java.util.*;

public class C{
	void solve(){
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong(), m = sc.nextLong();
		m = Math.min(n, m);
		if (n == m)
			System.out.println(n);
		else{
			n -= m;
			n += n;
			long x = (long)Math.sqrt(n);
			x++;
			while ((x-1)*x>=n) x--;
			System.out.println(x+m);
		}
	}
	public static void main(String[] argc){
		C sol = new C();
		sol.solve();
	}
}