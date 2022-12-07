#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n, m;
int f[2][1 << 16], g[2][1 << 16], ff[1 << 16], gg[1 << 16];
char mp[260][260], mmp[260][20 ];

inline void add(int &a, int b){
	(a += b, a >= M) && (a -= M);
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%s", mp[i]);
	if(n < m){
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				mmp[j][i] = mp[i][j];
		swap(n, m);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				mp[i][j] = mmp[i][j];
	}
	
	f[0][0] = 1;
	bool t = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j){
			if(!j){
				memcpy(ff, f[t], sizeof(f[t]));
				memcpy(gg, g[t], sizeof(g[t]));			
				for(int mask = 0; mask < 1 << m; ++mask){
					f[t][mask << 1] = ff[mask];
					add(f[t][mask << 1], ff[mask | 1 << m]);
					g[t][mask << 1] = gg[mask];
					add(g[t][mask << 1], gg[mask | 1 << m]);
					f[t][mask << 1 | 1] = g[t][mask << 1 | 1] = 0;
				}
			}
			for(int mask = 0, tmask; mask < 1 << m + 1; ++mask){
				if(mp[i][j] == 'x'){
					tmask = mask & ~(1 << j | 1 << j + 1);
					add(f[t ^ 1][tmask], f[t][mask]);
					add(g[t ^ 1][tmask], g[t][mask]);
				}else{
					tmask = mask | 1 << j | 1 << j + 1;
					add(f[t ^ 1][tmask], f[t][mask]);
					add(g[t ^ 1][tmask], g[t][mask]);
					if(mask >> j & 1 || mask >> j + 1 & 1){
						tmask = mask & ~(1 << j | 1 << j + 1);
						int x = mask >> j & 1, y = mask >> j + 1 & 1;
						tmask |= y << j | x << j + 1;
						add(f[t ^ 1][tmask], f[t][mask]);
						add(g[t ^ 1][tmask], g[t][mask]);
					}else{
						add(g[t ^ 1][mask], f[t][mask]);
					}
				}
			}
			memset(f[t], 0, sizeof(f[t]));
			memset(g[t], 0, sizeof(g[t]));
			t ^= 1;
		}
	int ans = 0;
	for(int mask = 0; mask < 1 << m + 1; ++mask){
		add(ans, f[t][mask]);
		add(ans, g[t][mask]);
	}
	printf("%d\n", ans);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}