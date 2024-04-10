#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

struct query{
	ll p, x, y;
	query() {}
	query(ll p, ll x, ll y) : p(p), x(x), y(y) {}
};

multiset <ll> S1[303030], S2[303030];
vector <pll> T[303030], V;
set <pll> K;
ll P[303030], C[303030], X[303030], N[303030];
vector <query> R;
ll n, ans, cnt;

void dfs(ll p, ll r)
{
	P[p] = r;
	
	for(pll &t: T[p]){
		if(t.first != r){
			dfs(t.first, p);
			C[t.first] = t.second;
			S2[p].insert(t.second);
		}
	}
	
	N[p] = ++cnt;
	V.emplace_back(T[p].size(), p);
	K.insert(pll(cnt, p));
}

void change(ll p, ll x, ll y)
{
	if(!p) return;
	
	auto it = S1[p].lower_bound(x);
	if(it != S1[p].end() && *it == x){
		S1[p].erase(it); X[p] -= x;
	}
	else{
		it = S2[p].lower_bound(x);
		S2[p].erase(it);
	}
	
	S2[p].insert(y);
}

ll getsum(ll p, ll k)
{
	for(; !S2[p].empty() && (S1[p].size() < k || *S2[p].begin() < 0 ||
		(!S1[p].empty() && *S2[p].begin() < *prev(S1[p].end()))); ){
		X[p] += *S2[p].begin();
		S1[p].insert(*S2[p].begin());
		S2[p].erase(S2[p].begin());
	}
	
	for(; S1[p].size() > k && *prev(S1[p].end()) >= 0; ){
		X[p] -= *prev(S1[p].end());
		S2[p].insert(*prev(S1[p].end()));
		S1[p].erase(prev(S1[p].end()));
	}
	
	return X[p];
}

ll calc(ll p, ll k)
{
	ll v1 = getsum(p, T[p].size() - k);
	ll v2 = getsum(p, T[p].size() - k - 1) + C[p];
	
	change(P[p], C[p], v2 - v1);
	R.emplace_back(P[p], v2 - v1, C[p]);
	
	if(T[P[p]].size() > k || p == 1) return v1;
	else return min(v1, v2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll i, k, u, v, c;
	
	cin >> n;
	
	for(i=1; i<n; i++){
		cin >> u >> v >> c;
		ans += c;
		T[u].emplace_back(v, c);
		T[v].emplace_back(u, c);
	}
	
	dfs(1, 0);
	
	sort(V.begin(), V.end());
	
	for(k=0, i=0; k<n; k++){
		for(; i<V.size() && V[i].first <= k; i++){
			K.erase(pll(N[V[i].second], V[i].second));
		}
		
		ans = 0; R.clear();
		
		for(pll t: K){
			ans += calc(t.second, k);
		}
		
		for(query &q: R){
			change(q.p, q.x, q.y);
		}
		
		cout << ans << " ";
	}
	
	cout << "\n";
	
	return 0;
}