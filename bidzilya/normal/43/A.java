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
		sc.nextLine();
		
		int cnt[] = new int[n];
		String name[] = new String[n];
		int m=0;
		
		for (int i=0;i<n;i++){
			String temp = sc.nextLine();
			
			int ind = -1;
			for (int j=0;j<m;j++)
				if (temp.equals(name[j]))
					ind = j;
			if (ind==-1){
				cnt[m] = 1;
				name[m++] = temp;
			}else 
				cnt[ind]++;
		}
		
		int ind = 0;
		for (int i=1;i<m;i++)
			if (cnt[i]>cnt[ind])
					ind = i;
		System.out.println(name[ind]);
	}
}