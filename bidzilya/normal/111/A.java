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
		int n = sc.nextInt();
		long x = sc.nextLong();
		int y = sc.nextInt();
		x -= n-1;
		y -= n-1;
		for (int i=1;i<=y;i++)
			if ((long)i*i>=x){
				System.out.println(i);
				for (int j=0;j<n-1;j++)
					System.out.println(1);
				return;
			}
		System.out.println(-1);
	}
}