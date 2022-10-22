import java.util.*;

public class C{
	final int MOD = (int)1e9 + 7;
	long get(int x, int y, int lim){
		if (Math.min(x,y) < 0) return 0L;
		
		long[][][][] d = new long[32][2][2][2], sm = new long[32][2][2][2];
		d[31][1][1][1] = 1;
		for (int w = 30; w >= 0; w--)
			for (int a = 0; a < 2; a++)
				for (int b = 0; b < 2; b++)
					for (int c = 0; c < 2; c++)
						for (int aa = 0; aa <= (a==0?1:x>>w&1); aa++)
							for (int bb = 0; bb <= (b==0?1:y>>w&1); bb++)
								if (c == 0 || (aa^bb) <= (lim>>w&1)){
									d[w][(a==0||aa<(x>>w&1))?0:1][(b==0||bb<(y>>w&1))?0:1][(c==0||(aa^bb)<(lim>>w&1))?0:1]
										+= d[w+1][a][b][c];

									sm[w][(a==0||aa<(x>>w&1))?0:1][(b==0||bb<(y>>w&1))?0:1][(c==0||(aa^bb)<(lim>>w&1))?0:1]
										+= sm[w+1][a][b][c] + (1L<<w)*(aa^bb)*d[w+1][a][b][c];
									sm[w][(a==0||aa<(x>>w&1))?0:1][(b==0||bb<(y>>w&1))?0:1][(c==0||(aa^bb)<(lim>>w&1))?0:1]
										%= MOD;
								}

		long ret = 0;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				for (int w = 0; w < 2; w++){
					ret += d[0][i][j][w];
					ret += sm[0][i][j][w];
					ret %= MOD;
				}
		return ret;
	}
	void solve(){
	//	System.out.println(get(4, 3, 4));
		Scanner sc = new Scanner(System.in);
		int q = sc.nextInt();
		while (q-->0){
			int x1 = sc.nextInt(), y1 = sc.nextInt();
			int x2 = sc.nextInt(), y2 = sc.nextInt();
			int k = sc.nextInt();
			x1--; x2--; y1--; y2--; k--;
			System.out.printf("%d\n", (get(x2, y2, k)-get(x2,y1-1, k)-get(x1-1, y2, k)+get(x1-1,y1-1, k)+MOD*10L)%MOD);
		}
	}
	public static void main(String[] args){
		C sol = new C();
		sol.solve();
	}
}