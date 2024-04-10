#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long

const int maxn = 400;
int n, m, t, mp[maxn][maxn], gor[maxn][maxn], gou[maxn][maxn];
int gol[maxn][maxn], god[maxn][maxn];
int ans, an[6], tp, tu, td;

int check(int h1, int h2){
	return h1 == h2 ? tp : h1 < h2 ? tu : td;
}

int main(){
	//freopen("D.in", "r", stdin);
	//freopen("D.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &t);
	scanf("%d%d%d", &tp, &tu, &td);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &mp[i][j]);
	
	for(int i = 1; i <= n; i++)
		for(int j = 2; j <= m; j++)
			gor[i][j] = gor[i][j-1] + check(mp[i][j-1], mp[i][j]);
	
	for(int i = 1; i <= n; i++)
		for(int j = m - 1; j; j--)
			gol[i][j] = gol[i][j+1] + check(mp[i][j+1], mp[i][j]);

	for(int j = 1; j <= m; j++)
		for(int i = n - 1; i; i--)
			gou[i][j] = gou[i+1][j] + check(mp[i+1][j], mp[i][j]);

	for(int j = 1; j <= m; j++)
		for(int i = 2; i <= n; i++)
			god[i][j] = god[i-1][j] + check(mp[i-1][j], mp[i][j]);

	int ans = (int)1e9;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			for(int k = i + 2; k <= n; k++)
				for(int l = j + 2; l <= m; l++){
					int ret = 0;
					ret += gor[i][l] - gor[i][j];
					ret += gol[k][j] - gol[k][l];
					ret += gou[i][j] - gou[k][j];
					ret += god[k][l] - god[i][l];
					if (abs(ret - t) < ans){
						ans = abs(ret - t);
						an[1] = i, an[2] = j, an[3] = k, an[4] = l;
					}
					//if (i == 4 && j == 4 && k == 6 && l == 7) printf("%d\n", ret);
				}
		}
	for(int i = 1; i <= 4; i++) printf("%d ", an[i]);
	return 0;
}