#include <bits/stdc++.h>

using namespace std;
using pii = pair <int, int>;

vector <pii> E[505050];
vector <int> G[505050], Z;
int P[505050], D[505050], C[505050];
int P2[505050], D2[505050];
bool X[505050];
int n, m, k;
long long a;

int find(int u)
{
	if(u == P[u]) return u;
	find(P[u]); D[u] ^= D[P[u]];
	return P[u] = P[P[u]];
}

int find2(int u)
{
	if(u == P2[u]) return u;
	Z.push_back(u);
	find2(P2[u]); D2[u] ^= D2[P2[u]];
	return P2[u] = P2[P2[u]];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int i, j, l, u, v, c;

	cin >> n >> m >> k;

	iota(P, P + n + 1, 0);
	iota(P2, P2 + n + 1, 0);

	for(i = 1; i <= n; i ++){
		cin >> C[i];
	}

	for(; m --; ){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		if(C[u] == C[v]){
			if(find(u) != find(v)){
				c = 1 ^ D[u] ^ D[v];
				u = P[u]; v = P[v];
				P[u] = v; D[u] = c;
			}
			else{
				if(D[u] == D[v]) X[C[u]] = 1;
			}
		}
		else{
			E[C[u]].emplace_back(u, v);
			E[C[v]].emplace_back(v, u);
		}
	}

	for(i = 1; i <= k; i ++){
		if(!X[i]) a ++;
	}
	a = a * (a - 1);

	for(i = 1; i <= k; i ++) if(!X[i]){
		sort(E[i].begin(), E[i].end(), [&](pii &a, pii &b){
			return C[a.second] < C[b.second];
		});
		for(j = 0; j < E[i].size(); j = l){
			bool f = 0;
			for(l = j; l < E[i].size() && C[E[i][j].second] == C[E[i][l].second]; l ++){
				tie(u, v) = E[i][l]; find(u); find(v);
				c = 1 ^ D[u] ^ D[v]; u = P[u]; v = P[v];
				if(find2(u) != find2(v)){
					c ^= D2[u] ^ D2[v];
					u = P2[u]; v = P2[v];
					Z.push_back(u);
					P2[u] = v; D2[u] = c;
				}
				else{
					if((D2[u] ^ D2[v] ^ c) == 1) f = 1;
				}
			}
			if(!X[C[E[i][j].second]] && f) a --;

			for(; !Z.empty(); Z.pop_back()){
				P2[Z.back()] = Z.back();
				D2[Z.back()] = 0;
			}
		}
	}

	cout << a / 2 << "\n";

	return 0;
}