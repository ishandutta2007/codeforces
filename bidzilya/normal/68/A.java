import java.util.Scanner;

public class MyTask{
	
	public static void main(String args[]){
		Solver s = new Solver();
		
		System.out.println(s.solve());
	}
}

class Solver{

	private boolean u[];
	private int us[];
	private int ans[];
	private int p[];
	private int a,b;
	
	private Scanner sc;
	
	private boolean check2(int x){
		int res = x;
		for (int i=0;i<4;i++)
			res = res%p[us[i]];
		return (res==x);
	}
	
	private void check(){
		for (int i=a;i<=b;i++)
			if (check2(i))
				ans[i]++;
	}
	
	private void go(int v){
		if (v==4){
			check();
			return;
		}
		for (int i=0;i<4;i++)
			if (!u[i]){
				u[i] = true;
				us[v] = i;
				go(v+1);
				u[i] = false;
			}
	}
	
	public int solve(){
		Scanner sc = new Scanner(System.in);
		
		p = new int[4];
		for (int i=0;i<4;i++)
			p[i] = sc.nextInt();
		a = sc.nextInt();
		b = sc.nextInt();
		
		u = new boolean[4];
		us = new int[4];
		ans = new int[55555];
		go(0);
		
		int k =0;
		for (int i=a;i<=b;i++)
			if (ans[i]>=7)
				k++;
		return k;
	}
}