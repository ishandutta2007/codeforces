#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#define Pr pair <int, int>
#define fi first
#define se second
using namespace std;
const int INF = 1e8;
const int maxn = 2e5 + 5;
map <int, int> mp;
vector <int> G[maxn];
int G3[1003][1003], d[1003][1003], c[1003];
long long read(){
	long long c = 0, f = 1; char ch = getchar();
	while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c * f;
}
int main(){
	int n = read();
	for (int i = 1; i <= n; ++ i){
		long long x = read();
		for (int j = 0; x; ++ j, x >>= 1)
			if (x & 1)
				++ c[j], G[i].push_back(n + 1 + j), G[n + 1 + j].push_back(i);
	}
	for (int j = 0; j <= 100; ++ j)
		if (c[j] >= 3){
			cout << 3 << endl;
			return 0;
		}	
	int c = 0;
	for (int j = 0; j <= 100; ++ j)
		if (G[n + 1 + j].size() == 2){
			if (! mp.count(G[n + 1 + j][0]))
				mp[G[n + 1 + j][0]] = ++ c;
			if (! mp.count(G[n + 1 + j][1]))
				mp[G[n + 1 + j][1]] = ++ c;
			int u = mp[G[n + 1 + j][0]], v = mp[G[n + 1 + j][1]];
			G3[u][v] = G3[v][u] = d[u][v] = d[v][u] = 1;
		}
	for (int i = 1; i <= c; ++ i)
		for (int j = 1; j <= c; ++ j)
			if (G3[i][j] == 0)
				G3[i][j] = d[i][j] = INF;
	int ans = INF;
	for (int k = 1; k <= c; ++ k){
		for (int i = 1; i <= c; ++ i)
			for (int j = i + 1; j <= c; ++ j)
				ans = min(ans, d[k][i] + G3[i][j] + d[j][k]);
		for (int i = 1; i <= c; ++ i)
			for (int j = 1; j <= c; ++ j)
				G3[i][j] = min(G3[i][j], G3[i][k] + G3[k][j]);
	}
	cout << (ans == INF ? -1 : ans) << endl;
}