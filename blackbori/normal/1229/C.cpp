#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

const ll sz = 300;

vector <ll> G[101010], V;
set <pll> S;
set <ll> Q;
bool chk[101010];
ll T[101010], X[101010], Y[101010];
ll n, m, q, ans;

void init()
{
	Q.clear();
	
	ll i;
	
	for(i=1; i<=n; i++){
		chk[i] = 0;
	}
}

void query(ll k, ll v)
{
	ans -= X[v] * Y[v];
	
	if(chk[v]){
		for(ll t: Q) if(T[v] < T[t]){
			if(S.find(pll(t, v)) != S.end()){
				X[v] --; Y[v] ++;
				ans -= X[t] * Y[t];
				X[t] ++; Y[t] --;
				ans += X[t] * Y[t];
			}
		}
	}
	else{
		chk[v] = 1;
		
		for(ll &t: G[v]){
			if(T[v] < T[t]){
				X[v] --; Y[v] ++;
				ans -= X[t] * Y[t];
				X[t] ++; Y[t] --;
				ans += X[t] * Y[t];
			}
		}
	}
	
	Q.insert(v);
	ans += X[v] * Y[v];
	T[v] = k;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll i, u, v;
	
	cin >> n >> m;
	
	for(i=0; i<m; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		S.insert(pll(u, v));
		S.insert(pll(v, u));
	}
	
	for(i=1; i<=n; i++){
		T[i] = i;
	}
	
	cin >> q;
	
	for(i=1; i<=n; i++){
		for(ll &t: G[i]){
			if(T[i] < T[t]) X[i] ++;
			else Y[i] ++;
		}
		
		ans += X[i] * Y[i];
	}
	
	cout << ans << "\n";
	
	for(i=1; i<=q; i++){
		if(i % sz == 0){
			init();
		}
		
		cin >> v;
		
		query(n + i + 1, v);
		
		cout << ans << "\n";
	}
	
	return 0;
}