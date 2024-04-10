#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <random>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int n,m;
vvi g, cc, rsort, csort;

int sz = 0;
vvi G,V;

int R,C;

bool cmp_row(int i, int j) {return g[R][i] < g[R][j];}
bool cmp_col(int i, int j) {return g[i][C] < g[j][C];}

const int N = 1000005;
int uf[N];

int id(int v) { return (uf[v]==v)?v:uf[v] = id(uf[v]);}

void merge(int v, int u) {uf[id(v)] = id(u);}

int E(int i, int j) {return id(i*m+j);}

bool seen[1000005]={0};
vector<int> L;

void dfs1(int v) {
	if(seen[v]) return;
	seen[v] = 1;
	for(auto u : G[v])
		dfs1(u);
	L.push_back(v);
}

int val[N];

int main() {
	scanf("%d%d",&n,&m);
	g = vvi(n,vi(m,0));
	cc = vvi(n,vi(m,-1));
	rsort = vvi(n,vi(m,0));
	csort = vvi(m,vi(n,0));
	G = vvi(n*m,vi());
	V = vvi(n*m,vi());
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			scanf("%d",&g[i][j]);
	for(R = 0; R < n; ++R) {
		for(int j = 0; j < m; ++j) rsort[R][j] = j;
		sort(rsort[R].begin(),rsort[R].end(),cmp_row);
	}
	for(C = 0; C < m; ++C) {
		for(int i = 0; i < n; ++i) csort[C][i] = i;
		sort(csort[C].begin(),csort[C].end(),cmp_col);
	}
	for(int i = 0; i < n*m; ++i) uf[i] = i;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(j > 0) {
				int cur = g[i][rsort[i][j]], prv = g[i][rsort[i][j-1]];
				int u = E(i,rsort[i][j]), v = E(i,rsort[i][j-1]);
				if(cur == prv) merge(u,v);
			}
			if(i > 0) {
				int cur = g[csort[j][i]][j], prv = g[csort[j][i-1]][j];
				int u = E(csort[j][i],j), v = E(csort[j][i-1],j);
				if(cur == prv) merge(u,v);
			}
		}
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(j > 0) {
				int cur = g[i][rsort[i][j]], prv = g[i][rsort[i][j-1]];
				int u = E(i,rsort[i][j]), v = E(i,rsort[i][j-1]);
				if(cur != prv) {
					G[v].push_back(u);
					V[u].push_back(v);
				}
			}
			if(i > 0) {
				int cur = g[csort[j][i]][j], prv = g[csort[j][i-1]][j];
				int u = E(csort[j][i],j), v = E(csort[j][i-1],j);
				if(cur != prv) {
					G[v].push_back(u);
					V[u].push_back(v);
				}
			}
		}
	}
	for(int i = 0; i < n*m; ++i) {
		if(id(i) == i)
			dfs1(i);
	}
	for(int i = L.size()-1; i >= 0; --i) {
		val[L[i]] = 1;
		for(int u : V[L[i]])
			val[L[i]] = max(val[L[i]],val[u]+1);
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			printf("%d ",val[id(E(i,j))]);
		}
		printf("\n");
	}



	return 0;
}