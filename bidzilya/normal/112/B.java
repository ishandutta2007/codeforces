import java.util.Scanner;

public class MyTask{
	
	public static void main(String args[]){
		Solver s = new Solver();
		System.out.print((s.solve())?"YES":"NO");
	}
}

class Solver{
	
	private Scanner sc = new Scanner(System.in);
	
	public boolean solve(){
		int n = sc.nextInt();
		int x = sc.nextInt();
		int y = sc.nextInt();
		
		if (y!=(int)n/2 && y!=(int)n/2+1)
			return true;
		int newX = n-x+1;
		if (Math.abs(newX-x)>=3)
			return true;
		else
			return false;
	}
}