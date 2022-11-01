#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

const int maxn = 1000 + 5;
const int mod = 2520;

int n, m, t, q;

vector <int> e[maxn];
int a[maxn];

int f[maxn][mod + 5];
pair <int, int> nxt[maxn][mod + 5];
bool vis[maxn][mod + 5];
bool v[maxn][mod + 5];
int cnt[maxn];
bool inc[maxn][mod + 5];
int ans[maxn][mod + 5];
int ansn = 0;
vector <pair <int, int> > edge[maxn][mod + 5];

pair <int, int> cir;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int dfsb(int x, int y){
	if(inc[x][y]){
		return 0;
	}
	inc[x][y] = true;
	cnt[x]++;
	if(cnt[x] == 1)ansn++;
	dfsb(nxt[x][y].first, nxt[x][y].second);
	ans[x][y] = ansn;
	cnt[x]--;
	
	return 0;
}

int dfs(int x, int y){
	if(v[x][y]){
		cir = make_pair(x, y);
		return 0;
	}
	
	if(vis[x][y])return 0;
	
	vis[x][y] = true;
	v[x][y] = true;
	
	dfs(nxt[x][y].first, nxt[x][y].second);
	v[x][y] = false;
	
	return 0;
}

int dfsc(int x, int y){
	if(vis[x][y]){
		return 0;
	}
	
	vis[x][y] = true;
	ans[x][y] = ansn;
	for(pair <int, int> tmp : edge[x][y]){
		if(inc[tmp.first][tmp.second])continue;
		dfsc(tmp.first, tmp.second);
	}
	
	return 0;
}

int main(){
	int i, j;
	int x, y;
	
	n = read();
	
	for(i=1;i<=n;i++){
		a[i] = (read() % mod + mod) % mod;
	}
	
	for(i=1;i<=n;i++){
		m = read();
		for(j=1;j<=m;j++){
			e[i].push_back(read());
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=0;j<mod;j++){
			nxt[i][j] = make_pair(e[i][j % (int)e[i].size()], ((a[e[i][j % (int)e[i].size()]] + j) % mod + mod) % mod);
			edge[e[i][j % (int)e[i].size()]][((a[e[i][j % (int)e[i].size()]] + j) % mod + mod) % mod].push_back(make_pair(i, j));
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=0;j<mod;j++){
			if(!vis[i][j]){
				dfs(i, j);
			}
			if(cir != make_pair(0, 0))dfsb(cir.first, cir.second);
			cir = make_pair(0, 0);
			ansn = 0;
		}
	}
	
	memset(vis, 0, sizeof(vis));
	for(i=1;i<=n;i++){
		for(j=0;j<mod;j++){
			if(inc[i][j]){
				ansn = ans[i][j];
				dfsc(i, j);
			}
		}
	}
	
	q = read();
	
	for(i=1;i<=q;i++){
		x = read();
		y = read();
		y = ((y + a[x]) % mod + mod) % mod;
		printf("%d\n", ans[x][y]);
	}
	
	return 0;
}