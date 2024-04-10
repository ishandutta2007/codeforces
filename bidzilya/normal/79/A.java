import java.util.Scanner;

public class MyTask{
	
	public static void main(String args[]){
		Solver s = new Solver();
		s.solve();
	}
}

class Solver{
	
	private int x,y;
	
	private boolean hod1(){
		if (x>=2 && y>=2){
			x -= 2;
			y -= 2;
			return true;
		}
		else
		if (x>=1 && y>=12){
			x--;
			y -= 12;
			return true;
		}
		else
		if (y>=22){
			y -=22;
			return true;
		}
		else
			return false;
	}
	
	private boolean hod2(){
		if (y>=22){
			y -=22;
			return true;
		}
		else
		if (y>=12 && x>=1){
			y -= 12;
			x--;
			return true;
		}
		else
		if (y>=2 && x>=2){
			x -= 2;
			y -= 2;
			return true;
		}
		else 
			return false;
	}
	
	public void solve(){
		Scanner sc = new Scanner(System.in);
		x = sc.nextInt();
		y = sc.nextInt();
		
		int h = 0;
		while (true){
			if (h==0 && !hod1())
				break;
			else
			if (h==1 && !hod2())
				break;
			h = (h+1)%2;
		}
		h = (h+1)%2;
		System.out.print((h==0)?"Ciel":"Hanako");
	}
}