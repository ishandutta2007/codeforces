#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;
long long n, a[1200000], b[1200000], bit[1200000], q, l, r, ans[1200000]; vector<pair<int, int>>G[1200000];
map<int, int>M;
void add(long long x, long long r) { if (x <= 0)return; while (x <= n) { bit[x] ^= r; x += (x&-x); } }
long long sum(long long x) { long long s = 0; while (x >= 1) { s ^= bit[x]; x -= (x&-x); } return s; }
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) { scanf("%lld", &a[i]); b[i] = a[i]; }
	for (int i = 1; i <= n; i++) { b[i] ^= b[i - 1]; }
	cin >> q;
	for (int i = 1; i <= q; i++) { scanf("%lld%lld", &l, &r); G[r].push_back(make_pair(l, i)); }
	for (int i = 1; i <= n; i++) {
		if (M[a[i]] >= 1) { add(M[a[i]], a[i]); }
		add(i, a[i]); M[a[i]] = i;
		for (int j = 0; j < G[i].size(); j++) {
			ans[G[i][j].second] = (b[i] ^ b[G[i][j].first - 1]) ^ (sum(i) ^ sum(G[i][j].first - 1));
		}
	}
	for (int i = 1; i <= q; i++)printf("%lld\n", ans[i]);
	return 0;
}