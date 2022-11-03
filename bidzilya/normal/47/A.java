import java.util.Scanner;

public class MyTask{
	
	public static void main(String args[]){
		Solver s = new Solver();
		s.solve();
	}
}

class Solver{
	
	public void solve(){
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		
		boolean tr[] = new boolean[501];
		int n=1;
		while (true){
			int k = n*(n+1)/2;
			if (k>500)
				break;
			tr[k]=true;
			n++;
		}
		
		System.out.print((tr[x])?"YES":"NO");
	}
}