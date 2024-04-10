import java.util.Scanner;

public class MyTask{
	
	public static void main(String args[]){
		Solver s = new Solver();
		s.solve();
	}
}

class Solver{
	
	private final int mod = 1000003;
	
	public void solve(){
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		
		int ans =1;
		for (int i=2;i<=x;i++)
			ans = (ans*3)%mod;
		System.out.print(ans);
	}
}