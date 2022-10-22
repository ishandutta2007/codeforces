//Don't fail me now..

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<utility>
#include<numeric>
#include<vector>
using namespace std;
#define FAIL return printf("NOT MAGIC\n"), 0;
#define F first
#define S second

const int MAXN = 25e2 + 2;
int n, c[MAXN][MAXN], par[MAXN], sz;
vector<pair<int, int>>	adj[MAXN];
pair<int, int>	sec[MAXN*MAXN];

bool cmp(pair<int, int> u, pair<int, int> v){return c[u.F][u.S] < c[v.F][v.S];}
int get_par(int v){return par[v]==v?v:par[v]=get_par(par[v]);}
bool dfs(int v, int ss, int p = -1, int mn = 0){if (v^ss && c[v][ss] > mn) return	true;	for (auto u:adj[v]) if (u.F^p && dfs(u.F, ss, v, max(mn, u.S)))	return	true;	return	false;}

int main(){
	scanf("%d", &n);	for (int i = 0; i < n; i++)	for (int j = 0; j < n; j++)	scanf("%d", &c[i][j]);
	for (int i = 0; i < n; i++)	for (int j = 0; j < n; j++)	if (c[i][j] ^ c[j][i] || (i==j&&c[i][j]))	FAIL;
	for (int i = 0; i < n; i++)	for (int j = 0; j < i; j++)	if (i^j)	sec[sz++] = {i, j};
	iota(par, par + n, 0);
	sort(sec, sec + sz, cmp);
	for (int i = 0; i < sz; i++) 
		if (get_par(sec[i].S) != get_par(sec[i].F)){
			adj[sec[i].S].push_back({sec[i].F, c[sec[i].S][sec[i].F]}), adj[sec[i].F].push_back({sec[i].S, c[sec[i].F][sec[i].S]});	par[get_par(sec[i].F)] = get_par(sec[i].S);}
	for (int i = 0; i < n; i++)	if (dfs(i, i))	FAIL;
	printf("MAGIC\n");
	return	0;
}