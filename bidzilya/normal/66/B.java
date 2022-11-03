import java.util.Scanner;

public class MyTask{
	
	public static void main(String args[]){
		Solver s = new Solver();
		s.solve();
	}
}

class Solver{
	
	private final Scanner sc = new Scanner(System.in);
	private int a[];
	private int n;
	
	private int gol(int v,int p){
		if (v<0 || a[v]>p)
			return 0;
		else
			return gol(v-1,a[v])+1;
	}
	
	private int gor(int v,int p){
		if (v>=n || a[v]>p)
			return 0;
		else
			return gor(v+1,a[v])+1;
	}
	
	private int go(int v){
		return gol(v-1,a[v])+gor(v+1,a[v])+1;
	}
	
	public void solve(){
		n = sc.nextInt();
		a = new int[n];
		
		for (int i=0;i<n;i++)
			a[i]=sc.nextInt();
		int ans = 1;
		for (int i=0;i<n;i++)
			ans = Math.max(ans,go(i));
		
		System.out.print(ans);
	}
}