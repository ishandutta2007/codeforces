#include <bits/stdc++.h>

using namespace std;

struct edge{
	int v, c, i;
	edge() {}
	edge(int v, int c, int i) : v(v), c(c), i(i) {}
};

vector <edge> G[222];
vector <int> X, Y;
queue <int> Q;
int X1[55], X2[55], Y1[55], Y2[55];
int D[111][111];
int L[222], I[222];
int n, m, x, y, ans;

bool bfs()
{
	int i, p;
	
	for(i=0; i<=x+y; i++){
		L[i] = 0;
	}
	
	L[0] = 1; Q.push(0);
	
	for(; !Q.empty(); ){
		p = Q.front(); Q.pop();
		for(edge &e: G[p]){
			if(!L[e.v] && e.c){
				L[e.v] = L[p] + 1;
				Q.push(e.v);
			}
		}
	}
	
	return L[x + y] != 0;
}

int get_flow(int p, int c)
{
	if(p == x + y) return c;
	
	int v, _c, t, f;
	
	for(int &i=I[p]; i<G[p].size(); i++){
		v = G[p][i].v; _c = G[p][i].c; t = G[p][i].i;
		if(L[v] == L[p] + 1 && _c){
			f = get_flow(v, min(c, _c));
			if(f){
				G[p][i].c -= f;
				G[v][t].c += f;
				return f;
			}
		}
	}
	
	return 0;
}

int main()
{
	int i, j, t;
	
	scanf("%d%d", &n, &m);
	
	for(i=1; i<=m; i++){
		scanf("%d%d%d%d", X1 + i, Y1 + i, X2 + i, Y2 + i);
		X.push_back(X1[i]); X.push_back(++ X2[i]);
		Y.push_back(Y1[i]); Y.push_back(++ Y2[i]);
	}
	
	X.push_back(1); X.push_back(n + 1);
	Y.push_back(1); Y.push_back(n + 1);
	
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	
	sort(Y.begin(), Y.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());
	
	x = X.size(); y = Y.size();
	
	for(i=1; i<=m; i++){
		X1[i] = lower_bound(X.begin(), X.end(), X1[i]) - X.begin() + 1;
		X2[i] = lower_bound(X.begin(), X.end(), X2[i]) - X.begin() + 1;
		Y1[i] = lower_bound(Y.begin(), Y.end(), Y1[i]) - Y.begin() + 1;
		Y2[i] = lower_bound(Y.begin(), Y.end(), Y2[i]) - Y.begin() + 1;
		D[X1[i]][Y1[i]] ++; D[X2[i]][Y2[i]] ++;
		D[X1[i]][Y2[i]] --; D[X2[i]][Y1[i]] --;
	}
	
	for(i=1; i<x; i++){
		for(j=1; j<y; j++){
			D[i][j] += D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1];
			if(D[i][j]){
				G[i].emplace_back(x + j, 2e9, G[x + j].size());
				G[x + j].emplace_back(i, 0, G[i].size() - 1);
			}
		}
	}
	
	for(i=1; i<x; i++){
		G[0].emplace_back(i, X[i] - X[i - 1], G[i].size());
		G[i].emplace_back(0, 0, G[0].size() - 1);
	}
	
	for(i=1; i<y; i++){
		G[x + i].emplace_back(x + y, Y[i] - Y[i - 1], G[x + y].size());
		G[x + y].emplace_back(x + i, 0, G[x + i].size() - 1);
	}
/*	
	for(i=0; i<=x+y; i++){
		for(edge &e: G[i]){
			if(i < e.v) printf("%d -> %d %d\n", i, e.v, e.c);
		}
	}
*/	
	for(; ; ){
		if(!bfs()) break;
		
		for(i=0; i<=x+y; i++){
			I[i] = 0;
		}
		
		for(; ; ){
			t = get_flow(0, 2e9);
			if(!t) break;
			ans += t;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}