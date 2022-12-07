#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int f[60][60], g[60][60];
int inv[60];
int ff[60][60];
int n, m;

inline void add(int &a, int b){
	(a += b, a >= M) && (a -= M);
}

int main(){
	scanf("%d%d", &n, &m);
	f[0][1] = 1;

	inv[0] = inv[1] = 1;
	for(int i = 2; i <= n; ++i)
		inv[i] = (ll)(M - M / i) * inv[M % i] % M;

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= i + 1; ++j){
			for(int x = 0; x < i; ++x){
				int y = i - 1 - x;
				for(int k = j; k <= x + 1; ++k)
					add(g[i][j], (ll)f[x][k] * f[y][j] % M);
				for(int k = j + 1; k <= y + 1; ++k)
					add(g[i][j], (ll)f[x][j] * f[y][k] % M);
			}			
			
			memset(ff, 0, sizeof(ff));
			for(int p = 0; p <= n; ++p)
				for(int q = 1; q <= p + 1; ++q){
					int now = g[i][j], s = 1;
					for(int t = 1; p + i * t <= n; ++t){
						s = (ll)s * (now + t - 1) % M * inv[t] % M;
						add(ff[p + i * t][q + j * t], (ll)f[p][q] * s % M);
					}
				}
			
			for(int p = 0; p <= n; ++p)
				for(int q = 1; q <= p + 1; ++q)
					add(f[p][q], ff[p][q]);
		}
	
	printf("%d\n", f[n][m]);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}