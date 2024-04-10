import java.util.*;

public class A{
	void solve(){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), sm=0;
		while (n-->0){
			String s = sc.next();
			if (s.charAt(0) == 'T') sm += 4;
			else if (s.charAt(0) == 'C') sm += 6;
			else if (s.charAt(0) == 'O') sm += 8;
			else if (s.charAt(0) == 'D') sm += 12;
			else sm += 20;
		}
		System.out.println(sm);
	}

	public static void main(String[] argc){
		A sol = new A();
		sol.solve();
	}
}