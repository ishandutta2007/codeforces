#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;	

int n, m, k;
int a, b, c;
vector <tuple<int,int,int>> v;

int cnt = 1;
int id[200005];
ll dp[805][805];
			
int main() {
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= m; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		v.pb(make_tuple(a, b, c));
	}
	sort(v.begin(), v.end(), [] (tuple<int,int,int> a, tuple<int,int,int> b) {
		return get<2>(a) < get<2> (b);
	});
	
	for(int i = 1; i <= 800; ++i)
		for(int j = 1; j <= 800; ++j) 
			if(i != j) dp[i][j] = 1e18;
	
	for(int i = 0; i < min(k, m); ++i) {
		int x = get<0> (v[i]);
		int y = get<1> (v[i]);
		int c = get<2> (v[i]);
		if(!id[x])
			id[x] = cnt++;
		if(!id[y])
			id[y] = cnt++;
		dp[id[x]][id[y]] = c;
		dp[id[y]][id[x]] = c;
	}
	
	for(int k = 1; k < cnt; ++k)
		for(int i = 1; i < cnt; ++i)
			for(int j = 1; j < cnt; ++j)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
	vector <ll> w;
	for(int i = 1; i < cnt; ++i)
		for(int j = i + 1; j < cnt; ++j)
			w.pb(dp[i][j]);
	sort(w.begin(), w.end());
	printf("%lld\n", w[k - 1]);
		
	
	
	return 0;
}