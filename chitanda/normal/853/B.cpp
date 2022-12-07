#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const int INF = 1e9;
const int maxn = 100100;
const int maxm = 1000100;
int n, m, k;
vector<pair<int, int> > pre[maxm], suf[maxm];
ll Pre[maxm];
int ppre[maxn], ssuf[maxn];

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; ++i){
		static int d, f, t, c;
		scanf("%d%d%d%d", &d, &f, &t, &c);
		if(t == 0) pre[d].pb(mkp(f, c));
		else suf[d].pb(mkp(t, c));
	}
	ll cost = 0;
	for(int i = 1; i <= n; ++i)
		ppre[i] = INF, cost += INF;
	
	int cnt = 0;
	for(int i = 1; i <= 1000000 - k - 1; ++i){
		for(auto v : pre[i]){
			if(ppre[v.fi] == INF) ++cnt;
			cost -= ppre[v.fi];
			ppre[v.fi] = min(ppre[v.fi], v.se);
			cost += ppre[v.fi];
		}
		if(cnt == n) Pre[i] = cost;
		else Pre[i] = -1;
	}
	
	cost = 0;
	for(int i = 1; i <= n; ++i)
		ssuf[i] = INF, cost += INF;

	cnt = 0;

	ll ans = 1LL << 60;
	for(int i = 1000000; i >= k + 2; --i){
		for(auto v : suf[i]){
			if(ssuf[v.fi] == INF) ++cnt;
			cost -= ssuf[v.fi];
			ssuf[v.fi] = min(ssuf[v.fi], v.se);
			cost += ssuf[v.fi];
		}
		if(Pre[i - k - 1] == -1) break;
		if(cnt == n){
			ans = min(ans, Pre[i - k - 1] + cost);
		}
	}
	
	if(ans != (1LL << 60))
		printf("%lld\n", ans);
	else
		printf("-1\n");
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}