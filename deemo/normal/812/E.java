import java.util.*;

public class E{
	final int MAXN = (int)1e5 + 10;
	final int XX = (int)2e7 + 10;
	ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
	int n, s1, s2;
	int[] x = new int[MAXN], sec = new int[MAXN], gec = new int[MAXN], cnt = new int[XX];

	int dfs(int v){
		int de = 0;
		for (int u:adj.get(v))
			de = Math.max(de, dfs(u)+1);
		if ((de&1)==0)
			sec[s1++] = x[v];
		else
			gec[s2++] = x[v];
		return de;
	}

	void solve(){
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		for (int i = 0; i < n; i++){
			adj.add(new ArrayList<>());
			x[i] = sc.nextInt();
		}
		for (int i = 1; i < n; i++)
			adj.get(sc.nextInt()-1).add(i);
		dfs(0);

		int xx = 0;
		for (int i = 0; i < s1; i++) xx ^= sec[i];
	
		long ans = 0;
		if (xx==0) ans += 1L*s1*(s1-1)/2 + 1L*s2*(s2-1)/2;
		for (int i = 0; i < s2; i++) cnt[gec[i]]++;
		for (int i = 0; i < s1; i++){
			int temp = xx^sec[i];
			ans += cnt[temp];
		}
		System.out.println(ans);
	}

	public static void main(String[] args){
		E sol = new E();
		sol.solve();
	}
}