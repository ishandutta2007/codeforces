#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const ll B1 = 701;
const ll B2 = 721;

int n, m;
vector<int>	vec[MAXN];
vector<pair<int, int>>	sec[MAXN];
ll ss[MAXN], t1[MAXN], t2[MAXN];
map<pair<ll, ll>, int>	mp;

int main(){
	ss[0] = 1;
	for (int i = 1; i < MAXN; i++)
		ss[i] = ss[i - 1] * i % MOD;

	t1[0] = 1;
	for (int i = 1; i < MAXN; i++)	t1[i] = t1[i - 1] * B1;

	t2[0] = 1;
	for (int i = 1; i < MAXN; i++)	t2[i] = t2[i - 1] * B2 % MOD;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++){
		int t;	scanf("%d", &t);
		vec[i].resize(t);
		for (int j = 0; j < t; j++)
			scanf("%d", &vec[i][j]), vec[i][j]--;
		sort(vec[i].begin(), vec[i].end());
		for (int l = 0; l < (int)vec[i].size();){
			int r = l;
			while (r < (int)vec[i].size() && vec[i][l] == vec[i][r])	r++;
			sec[vec[i][l]].push_back({i, r-l});
			l = r;
		}
	}

	for (int i = 0; i < m; i++){
		ll hs1 = 0, hs2 = 0;
		int l = 0;
		for (auto &x:sec[i]){
			hs1 = hs1*t1[x.F - l] + x.S;
			hs2 = (hs2*t2[x.F-l] + x.S) % MOD;
			l = x.F;
		}
		hs1 = hs1*t1[n - l];
		hs2 = hs2*t2[n-l] % MOD;
		mp[{hs1, hs2}]++;
	}

	ll ans = 1;
	for (auto &x:mp)
		ans = ans * ss[x.S] % MOD;
	printf("%lld\n", ans);
	return 0;
}