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
			m = sc.nextInt(),
		    a[] = new int[n];
		for (int i=0;i<n;i++)
			a[i]=sc.nextInt();
		
		for (int i=0;i<n-1;i++)
			for (int j=i+1;j<n;j++)
				if (a[j]<a[i]){
					int buf = a[i];a[i]=a[j];a[j]=buf;
				}
		int ans =0,
			i = 0;
	    while (i<m && a[i]<0)
			ans += a[i++];
		System.out.print(Math.abs(ans));
	}
}