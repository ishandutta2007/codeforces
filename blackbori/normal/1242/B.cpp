#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

vector <int> G[101010];
set <pii> S;
int P[101010];
int n, m, c, ans;

int find(int p) { return p == P[p]? p : P[p] = find(P[p]); }
void unite(int p, int q) { P[find(p)] = find(q); }

int main()
{
	cin.sync_with_stdio(false);
	
	int i, j, u, v, s;
	
	cin >> n >> m;
	
	for(i = 0; i < m; i ++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		S.insert(pii(u, v));
		S.insert(pii(v, u));
	}
	
	for(i = 1, m = 1; i <= n; i ++){
		if(G[i].size() < G[m].size()) m = i;
		P[i] = i;
	}
	
	sort(G[m].begin(), G[m].end());
	
	for(i = 1, j = 0, c = 0; i <= n; i ++){
		for(; j < G[m].size() && G[m][j] < i; j ++);
		if(j >= G[m].size() || G[m][j] > i){
			c ++, unite(m, i);
		}
	}
	
	for(i = 0; i < G[m].size(); i ++){
		for(j = 0, s = 0; j < G[m].size(); j ++){
			if(S.find(pii(G[m][i], G[m][j])) == S.end()){
				unite(G[m][i], G[m][j]);
			}
			else s ++;
		}
		
		if(G[G[m][i]].size() - s != c) unite(G[m][i], m);
	}
	
	for(i = 1; i <= n; i ++){
		if(find(i) == i) ans ++;
	}
	
	cout << ans - 1 << "\n";
	
	return 0;
}