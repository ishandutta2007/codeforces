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
		int n = sc.nextInt();
		
		int a[] = new int[n];
		
		int c0=0,c1=0;
		for (int i=0;i<n;i++){
			a[i] = sc.nextInt();
			if (a[i]%2==0)
				c0++;
			else
				c1++;
		}
		for (int i=0;i<n;i++)
			if (c1==1 && a[i]%2==1)
				System.out.print(i+1);
			else
			if (c0==1 && a[i]%2==0)
				System.out.print(i+1);
	}
}