import java.util.Scanner;

public class MyTask{
	
	public static void main(String args[]){
		Solver s = new Solver();
		System.out.print((s.solve())?"YES":"NO");
	}
}

class Solver{
	
	private Scanner sc = new Scanner(System.in);
	
	private int deleteNull(int x){
		int c[] = new int[10];
		int m = 0;
		while (x>0){
			int a = x%10;
			x = (int)x/10;
			if (a!=0)
				c[m++]=a;
		}
		int res=0;
		for (int i=m-1;i>=0;i--)
			res = res*10+c[i];
		return res;
	}
	
	public boolean solve(){
		int a = sc.nextInt(),
			b = sc.nextInt(),
			A = deleteNull(a),
			B = deleteNull(b),
			C = deleteNull(a+b);
		
		return (A+B==C);
	}
}