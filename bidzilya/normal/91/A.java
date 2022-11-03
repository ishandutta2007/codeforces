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
		String s1 = sc.nextLine();
		String s2 = sc.nextLine();
		
		boolean f[] = new boolean[26];
		for (int i=0;i<s1.length();i++)
			f[s1.charAt(i)-'a']=true;
		boolean g[] = new boolean[26];
		for (int i=0;i<s2.length();i++)
			g[s2.charAt(i)-'a']=true;
		for (int i=0;i<26;i++)
			if (g[i] && !f[i]){
				System.out.print(-1);
				return;
			}
		
		int next[][] = new int[s1.length()+1][26];
		
		for (int i=0;i<26;i++)
			next[s1.length()][i]=-1;
		
		for (int i=s1.length()-1;i>=0;i--){
			for (int j=0;j<26;j++)
				next[i][j]=next[i+1][j];
			next[i][s1.charAt(i)-'a']=i;
		}
		
		int ans = 1,tek=0;
		for (int i=0;i<s2.length();i++){
			int c = s2.charAt(i)-'a';
			if (next[tek][c]==-1){
				tek =0;
				ans++;
			}
			tek = next[tek][c]+1;
		}
		System.out.print(ans);
	}
}