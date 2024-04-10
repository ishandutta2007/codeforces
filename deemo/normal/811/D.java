import java.util.*;

public class D{
	static int n, m;
	static boolean fit(int x, int y){return 0 <= x && x < n && 0 <= y && y < m;}

	static class Pair{
		int f;
		int s;
		Pair(int a, int b){
			f = a;
			s = b;
		}
	}

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		String[] s = new String[n];
		for (int i = 0; i < n; i++) s[i] = sc.next();
		int tx=0, ty=0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (s[i].charAt(j) == 'F'){
					tx = i;
					ty = j;
				}

		char L = 'L', R = 'R', D = 'D', U = 'U';
		int[] dx = {0, 1, 0, -1};
		int[] dy = {1, 0, -1, 0};

		int x = 0, y = 0;
		if (m > 1 && s[x].charAt(y+1) != '*'){
			System.out.println(R);
			System.out.flush();
			x = sc.nextInt(); x--;
			y = sc.nextInt(); y--;
			if (x == tx && y == ty) return;
			if (y == 0){
				char temp = L;
				L = R;
				R = temp;
			}
			else{
				System.out.println(L);
				System.out.flush();
				x = sc.nextInt(); x--;
				y = sc.nextInt(); y--;
			}

			while (true){
				if (n > 1 && s[x+1].charAt(y) != '*'){
					System.out.println(D);
					System.out.flush();

					x = sc.nextInt(); x--;
					y = sc.nextInt(); y--;
					if (x == tx && y == ty) return;
					if (x == 0){
						char tt = U;
						U = D;
						D = tt;
					}
					break;
				}

				System.out.println(R);
				System.out.flush();
				x = sc.nextInt(); x--;
				y = sc.nextInt(); y--;
				if (x == tx && y == ty) return;
			}
		}
		else if (n > 1 && s[x+1].charAt(y) != '*'){
			System.out.println(D);
			System.out.flush();
			x = sc.nextInt(); x--;
			y = sc.nextInt(); y--;
			if (x == tx && y == ty) return;
			if (x == 0){
				char temp = U;
				U = D;
				D = temp;
			}
			else{
				System.out.println(U);
				System.out.flush();
				x = sc.nextInt(); x--;
				y = sc.nextInt(); y--;
			}

			while (true){
				if (m > 1 && s[x].charAt(y+1) != '*'){
					System.out.println(R);
					System.out.flush();

					x = sc.nextInt(); x--;
					y = sc.nextInt(); y--;
					if (x == tx && y == ty) return;
					if (y == 0){
						char tt = L;
						L = R;
						R = tt;
					}
					break;
				}

				System.out.println(D);
				System.out.flush();
				x = sc.nextInt(); x--;
				y = sc.nextInt(); y--;
				if (x == tx && y == ty) return;
			}
		}

		Pair[] q = new Pair[(n+1)*(m+1)];
		Pair[][] par = new Pair[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				par[i][j] = new Pair(-1, -1);
		int h = 0, t = 0;
		q[t++] = new Pair(x, y);
		while (t-h>0){
			Pair v = q[h++];
			for (int w = 0; w < 4; w++)
				if (fit(v.f+dx[w], v.s+dy[w]) && s[v.f+dx[w]].charAt(v.s+dy[w])!='*' && par[v.f+dx[w]][v.s+dy[w]].f == -1){
					q[t++] = new Pair(v.f+dx[w], v.s+dy[w]);
					par[v.f+dx[w]][v.s+dy[w]] = v;
				}
		}

		t = 0;
		char[] ans = new char[n*m];
		while (tx != x || ty != y){
			Pair v = par[tx][ty];
			if (v.f < tx) ans[t++] = D;
			else if (v.f > tx) ans[t++] = U;
			else if (v.s < ty) ans[t++] = R;
			else ans[t++] = L;
			tx = v.f;
			ty = v.s;
		}
		while (t-->0){
			System.out.println(ans[t]);
			System.out.flush();
			x = sc.nextInt(); x--;
			y = sc.nextInt(); y--;
		}
	}
}