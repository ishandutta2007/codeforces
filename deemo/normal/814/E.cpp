#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 50 + 2;
const int MOD = 1e9 + 7;

int n, deg[MAXN], ch[MAXN][MAXN], d[MAXN][MAXN][MAXN];
int tt[MAXN][MAXN], t[MAXN][MAXN][MAXN][MAXN];
int p2[MAXN], p3[MAXN];

void add(int &x, int y){
	x += y;
	while (x >= MOD) x -= MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> deg[i];
		p2[i+1] = p2[i] + int(deg[i] == 2);
		p3[i+1] = p3[i] + int(deg[i] == 3);
	}
	if (deg[0] > n-1){
		cout << "0\n";
		return 0;
	}

	ch[0][0] = 1;
	for (int i = 1; i < MAXN; i++){
		ch[i][0] = ch[i][i] = 1;
		for (int j = 1; j < i; j++)
			ch[i][j] = (ch[i-1][j] + ch[i-1][j-1]) % MOD;
	}

	tt[0][0] = 1;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			if (i+j*2 <= n && i+j){
				int temp = i+j*2;
				if (i)
					tt[i][j] = 1ll*temp*tt[i-1][j]%MOD;
				else
					tt[i][j] = 1ll*ch[temp][2]*tt[i][j-1]%MOD;
			}
	
	t[0][0][0][0] = 1;
	for (int sm = 1; sm <= n; sm++)
		for (int c2 = 0; c2 <= sm; c2++){
			int c1 = sm-c2;
			for (int x1 = 0; x1 <= n; x1++)
				for (int x2 = 0; x1+x2 <= n; x2++)
					if (c1){
						if (x1)
							add(t[c1][c2][x1][x2], t[c1-1][c2][x1-1][x2]);
						if (c1>1)
							add(t[c1][c2][x1][x2], 1ll*(c1-1)*t[c1-2][c2][x1][x2]%MOD);
						if (c2>0)
							add(t[c1][c2][x1][x2], 1ll*c2*t[c1][c2-1][x1][x2]%MOD);
					}
					else{
						if (x2>0)
							add(t[c1][c2][x1][x2], t[c1][c2-1][x1][x2-1]);
						if (x1>0 && c2>1)
							add(t[c1][c2][x1][x2], 1ll*(c2-1)*t[c1+1][c2-2][x1-1][x2]%MOD);
						if (c2 > 2)
							add(t[c1][c2][x1][x2], 1ll*ch[c2-1][2]*t[c1+2][c2-3][x1][x2]%MOD);
					}
		}
	{//base
		int c1 = 0, c2 = 0;
		for (int w = 1; w < 1 + deg[0]; w++)
			c1 += int(deg[w] == 2), c2 += int(deg[w] == 3);

		for (int a = 0; a <= deg[0]; a++)
			for (int b = 0; a+b <= deg[0]; b++)
				add(d[deg[0]+1][a][b], t[c1][c2][a][b]);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			for (int w = 0; w + j <= i; w++)
				if (d[i][j][w] && j+w*2+i <= n){
					int temp = j+w*2;
					int c1 = p2[i+temp] - p2[i];
					int c2 = p3[i+temp] - p3[i];
					for (int a = 0; a <= temp; a++)
						for (int b = 0; b+a <= temp; b++)
							add(d[i+temp][a][b], 1ll*d[i][j][w]*t[c1][c2][a][b]%MOD*tt[j][w]%MOD);
				}

	cout << d[n][0][0] << "\n";
	return 0;
}