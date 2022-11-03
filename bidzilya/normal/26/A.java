import java.util.Scanner;

public class MyTask{
	
	public static void main(String args[]){
		Solver s = new Solver();
		s.solve();
	}
}

class Solver{
	
	private boolean kanon(int x){
		int m =0;
		for (int i=2;i<=x;i++){
			int k =0;
			while (x%i==0){
				x /= i;
				k=1;
			}
			m += k;
		}
		return (m==2);
	}
	
	public void solve(){
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt(),
			ans = 0;
		for (int i=2;i<=x;i++)
			if (kanon(i))
				ans++;
		System.out.print(ans);
	}
}