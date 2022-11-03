import java.util.Scanner;

public class MyTask{
	
	public static void main(String args[]){
		Solver s = new Solver();
		
		s.solve();
	}
}

class Solver{
	
	private Scanner sc = new Scanner(System.in);
	
	public void solve(){
		int n = sc.nextInt();
		sc.nextLine();
		
		String a[] = new String[n];
		
		for (int i=0;i<n;i++)
			a[i] = sc.nextLine();
		
		int ans=0;
		boolean ok = true;
		while (ans<a[0].length() && ok){
			char c = a[0].charAt(ans);
			for (int i=1;i<n;i++)
				if (a[i].charAt(ans)!=c){
					ok = false;
					break;
				}
			if (ok)
				ans++;
		}
		System.out.print(ans);
	}
}