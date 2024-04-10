import java.util.Scanner;

public class Task{
	
	public static void main(String args[]){
		Solver s = new Solver();
		s.solve();
	}
}

class Solver{
	
	private Scanner sc = new Scanner(System.in);
	
	public void solve(){
		int n = sc.nextInt(),
			l = sc.nextInt();
		int a[] = new int[n];
		for (int i=0;i<n;i++)
			a[i] = sc.nextInt();
		int ans =0;
		for (int i=l;i<=100;i++){
			int tans = 0;
			for (int j=0;j<n;j++)
				tans = tans + (int)a[j]/i;
			tans = tans*i;
			ans = Math.max(ans, tans);
		}
		System.out.print(ans);
	}
}