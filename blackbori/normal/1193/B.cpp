#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;
typedef map <ll, ll> mll;

vector <ll> V[101010];
pll D[101010];
ll n, m, k, ans;

void merge(mll &X, mll &Y)
{
	if(X.size() < Y.size()) swap(X, Y);
	for(pll t: Y) X[t.first] += t.second;
}

void dfs(ll p, mll &X)
{
	ll s, t, x, y;
	
	for(ll &t: V[p]){
		mll Y;
		dfs(t, Y); merge(X, Y);
	}
	
	if(D[p].second){
		tie(x, y) = D[p]; X[x] += y;
		
		auto it = next(X.find(x));
		for(s=0; it!=X.end(); ){
			s += it -> second;
			t = it -> first;
			X.erase(it);
			if(s > y){
				X[t] = s - y;
				break;
			}
			it = next(X.find(x));
		}
	}
}

int main()
{
	ll i, p, d, w;
	
	scanf("%lld%lld%lld", &n, &m, &k);
	
	for(i=2; i<=n; i++){
		scanf("%lld", &p);
		V[p].push_back(i);
	}
	
	for(i=1; i<=m; i++){
		scanf("%lld%lld%lld", &p, &d, &w);
		D[p] = pll(d, w);
	}
	
	mll X;
	dfs(1, X);
	
	for(pll t: X){
		ans += t.second;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}