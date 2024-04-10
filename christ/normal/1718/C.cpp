#include <bits/stdc++.h>
using namespace std;
const int MN = 4e5 + 5;
void solve() { //# factors <= 160
	int n,q; scanf ("%d %d",&n,&q);
	vector<int> fac;
	int N = n;
	for (int i = 2; i <= n; i++) if (N % i == 0) {
		while (N % i == 0) N /= i;
		fac.push_back(n/i);
	}
	int m = (int)fac.size();
	vector<int> a(n);
	for (int i = 0; i < n; i++) scanf ("%d",&a[i]);
	long long mx = 0;
	vector<multiset<long long>> st(m);
	vector<vector<long long>> sum(m);
	for (int id = 0; id < m; id++) {
		int k = fac[id];
		sum[id].resize(k);
		for (int i = 0; i < n; i++) {
			sum[id][i%k] += a[i];
		}
		for (long long v : sum[id]) {
			st[id].insert(v);
			mx = max(mx,v*k);
		}
	}
	printf ("%lld\n",mx);
	while (q--) {
		int i,v; scanf ("%d %d",&i,&v); i--;
		long long mx = 0;
		for (int id = 0; id < m; id++) {
			int k = fac[id];
			int j = i % k;
			st[id].erase(st[id].find(sum[id][j]));
			sum[id][j] += v - a[i];
			st[id].insert(sum[id][j]);
			mx = max(mx,(*st[id].rbegin())*k);
		}
		printf ("%lld\n",mx);
		a[i] = v;
	}
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}