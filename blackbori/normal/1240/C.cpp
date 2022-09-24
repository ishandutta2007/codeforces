#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

vector <pll> T[505050];
ll n, k;

pll dfs(ll p, ll r)
{
	vector <ll> V;
	ll i, x0, x1, v0, v1;
	
	v0 = v1 = 0;
	
	for(pll &t: T[p]){
		if(t.first != r){
			tie(x0, x1) = dfs(t.first, p);
			x1 += t.second;		
			v0 += x0;
			V.emplace_back(x1 - x0);
		}
	}
	
	sort(V.rbegin(), V.rend());
	
	for(i=0; i<k-1 && i<V.size(); i++){
		if(V[i] >= 0) v0 += V[i];
	}
	
	v1 = v0;
	if(i < V.size() && V[i] >= 0) v0 += V[i];
	
	return pll(v0, v1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll q, i, u, v, w, v0, v1;
	
	cin >> q;
	
	for(; q--; ){
		cin >> n >> k;
		
		for(i=1; i<=n; i++){
			T[i].clear();
		}
		
		for(i=1; i<n; i++){
			cin >> u >> v >> w;
			T[u].emplace_back(v, w);
			T[v].emplace_back(u, w);
		}
		
		tie(v0, v1) = dfs(1, 0);
		
		cout << v0 << "\n";
	}
	
	return 0;
}