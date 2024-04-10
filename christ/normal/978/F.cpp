#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+2, BASE = 31; const ll MOD = 1000000000000037LL;
#define all(x) (x).begin(),(x).end()
vector<int> adj[MN];
int main() {
	int n,k;
	scanf ("%d %d",&n,&k);
	vector<pii> a(n); vector<int> ans(n); vector<int> og(n);
	for (int i = 0; i < n; i++) {
		scanf ("%d",&a[i].first);
		og[i] = a[i].first;
		a[i].second = i;
	}
	sort(all(a));
	while (k--) {
		int b,c;
		scanf ("%d %d",&b,&c); --b; --c;
		adj[b].push_back(c);
		adj[c].push_back(b);
	}
	map<int,int> cnt;
	for (int i = 0; i < n; i++) {
		int ret = i - cnt[a[i].first]++;
		for (int j : adj[a[i].second]) if (og[j] < a[i].first) --ret;
		ans[a[i].second] = ret;
	}
	for (int i = 0; i < n; i++) printf ("%d%c",ans[i]," \n"[i==n-1]);
    return 0;
}