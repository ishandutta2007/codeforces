#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

vector <ll> V[505050];
ll S[505050];
ll n, ans = -1e18;

void sz_dfs(ll p, ll r)
{
	S[p] = 1;
	
	for(ll &t: V[p]){
		if(t != r){
			sz_dfs(t, p);
			S[p] += S[t];
		}
	}
}

ll get_max(vector <pll> &L, ll a)
{
	if(L.empty()) return -1e18;
	
	ll s, e, m, v;
	
	for(s=0, e=L.size()-1; s<=e; ){
		m = s + e >> 1; v = L[m].first * a + L[m].second;
		if(m && v < L[m - 1].first * a + L[m - 1].second) e = m - 1;
		else if(m + 1 < L.size() && v < L[m + 1].first * a + L[m + 1].second) s = m + 1;
		else return v;
	}
}

void addline(vector <pll> &L, ll a, ll b)
{	
	for(; !L.empty(); ){
		if(L.back().first == a){
			if(L.back().second <= b){
				L.pop_back(); continue;
			}
		}
		
		if(L.size() > 1){
			ll a1, b1, a2, b2;
			tie(a1, b1) = L.back(); tie(a2, b2) = L[L.size() - 2];
			if((b2 - b1) * (a - a2) >= (b2 - b) * (a1 - a2)){
				L.pop_back(); continue;
			}
		}
		
		break;
	}
	
	L.emplace_back(a, b);
}

ll dfs(ll p, ll r)
{
	vector <pll> K, L;
	ll ret = 0, k;
	
	for(ll &t: V[p]){
		if(t != r){
			k = dfs(t, p);
			ans = max(ans, k + S[t] * (n - S[t]));
			ret = max(ret, k + S[t] * (S[p] - S[t]));
			K.emplace_back(S[t], k - S[t] * S[t]);
		}
	}
	
	sort(K.begin(), K.end(), [&](pll &pa, pll &pb){
		if(pa.first != pb.first) return pa.first > pb.first;
		else return n * pa.first + pa.second < n * pb.first + pb.second;
	});
	
	for(pll &t: K){
		ans = max(ans, get_max(L, t.first) + t.second);
		addline(L, n - t.first, n * t.first + t.second);
	}
	
	return ret;
}

int main()
{
	ll i, u, v;
	
	scanf("%lld", &n);
	
	for(i=1; i<n; i++){
		scanf("%lld%lld", &u, &v);
		V[u].push_back(v);
		V[v].push_back(u);
	}
	
	sz_dfs(1, 0);
	dfs(1, 0);
	
	printf("%lld\n", ans + n * (n - 1) / 2);
	
	return 0;
}