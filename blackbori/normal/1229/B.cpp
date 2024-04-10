#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

const ll mod = 1e9 + 7;

vector <ll> G[101010];
ll X[101010];
ll n, ans;

ll gcd(ll a, ll b) { for(; a; swap(a, b)) b %= a; return b; }

void dfs(ll p, ll r, vector <pll> V)
{
	vector <pll> Z;
	
	V.emplace_back(X[p], 1);
	
	for(pll &t: V){
		t.first = gcd(t.first, X[p]);
		ans = (ans + t.first * t.second) % mod;
	}
	
	sort(V.begin(), V.end());
	
	for(pll &t: V){
		if(!Z.empty() && Z.back().first == t.first){
			Z.back().second += t.second;
		}
		else Z.push_back(t);
	}
	
	for(ll &t: G[p]){
		if(t != r){
			dfs(t, p, Z);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector <pll> V;
	ll i, u, v;
	
	cin >> n;
	
	for(i=1; i<=n; i++){
		cin >> X[i];
	}
	
	for(i=1; i<n; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1, 0, V);
	
	cout << ans << "\n";
	
	return 0;
}