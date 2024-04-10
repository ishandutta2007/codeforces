#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

vector <pll> K[40404];
vector <pll> V;
vector <ll> G[22];
bool chk[22], dp[40404], poss[40404];
ll D[22], S[22];
ll A[22], B[22];
ll k, s;

void check(ll p, ll x)
{
	vector <pll> X;
	ll i, b, y;
	
	for(i = 1; i <= k; i ++){
		chk[i] = 0;
	}
	
	chk[p] = 1; b |= 1ll << p - 1;
	X.emplace_back(p, x);
	
	for(i = p, y = x; ; ){
		auto it = lower_bound(V.begin(), V.end(), pll(s - S[i] + x, -1));
		if(it == V.end() || it -> first != s - S[i] + x) return;
		x = s - S[i] + x; i = it -> second;
		if(chk[i]) break;
		X.emplace_back(i, x);
		b |= 1ll << i - 1; chk[i] = 1;
	}
	
	if(i != p || x != y) return;
	
//	printf("yeah %lld\n", b);
//	for(pll &t: X) printf("%lld %lld\n", t.first, t.second);
	
	if(K[b].empty()){
		K[b] = X;
		poss[b] = 1;
	}
}

void make(ll b)
{
	vector <pll> &X = K[b];
	ll i;
	
	for(i = 0; i < X.size(); i ++){
		A[X[i].first] = X[i].second;
		B[X[i].first] = X[(i + X.size() - 1) % (ll)X.size()].first;
	}
}

int main()
{
	cin.sync_with_stdio(false);
	
	ll i, j, v;
	
	cin >> k;
	
	for(i = 1; i <= k; i ++){
		cin >> D[i];
		for(j = 0; j < D[i]; j ++){
			cin >> v;
			s += v; S[i] += v;
			G[i].push_back(v);
			V.emplace_back(v, i);
		}
	}
	
	if(s % k){
		cout << "No\n";
		return 0;
	}
	
	s /= k;
	
	sort(V.begin(), V.end());
	
	for(i = 1; i <= k; i ++){
		for(ll &t: G[i]){
			check(i, t);
		}
	}
	
	dp[0] = 1;
	
	for(i = 1; i < (1 << k); i ++){
		for(j = i; !dp[i] && j; j = j - 1 & i){
			if(dp[i - j] && poss[j]) dp[i] = 1;
		}
	}
	
	if(!dp[(1 << k) - 1]){
		cout << "No\n";
		return 0;
	}
	
	for(i = (1 << k) - 1; i; ){
		for(j = i; j; j = j - 1 & i){
			if(dp[i - j] && poss[j]) break;
		}
		make(j); i -= j;
	}
	
	cout << "Yes\n";
	
	for(i = 1; i <= k; i ++){
		cout << A[i] << " " << B[i] << "\n";
	}
	
	return 0;
}