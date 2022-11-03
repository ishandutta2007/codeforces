import java.util.Scanner;

public class MyTask{
	
	public static void main(String args[]){
		Solver s = new Solver();
		s.solve();
	}
}

class Solver{

	private Scanner sc = new Scanner(System.in);
	
	private boolean sim(char c){
		if (c>='a' && c<='z' || c>='A' && c<='Z')
			return true;
		else
			return false;
	}
	
	private boolean glasn(char c){
		if (c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='Y' ||
			c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y')
				return true;
		else
				return false;
	}
	
	public void solve(){
		String s = sc.nextLine();
		int i = s.length()-1;
		while (!sim(s.charAt(i)))
			i--;
		char c = s.charAt(i);
		System.out.print((glasn(s.charAt(i)))?"YES":"NO");
	}
}