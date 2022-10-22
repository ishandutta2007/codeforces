#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 4e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
void solve() {
	int n;
	scanf ("%d",&n);
	vector<int> a(n);
	for (auto &au : a) scanf ("%d",&au);
	vector<pii> cmp; vector<int> psa;
	for (int i = 0; i < n; i++) {
		if (i == 0 || a[i] != a[i-1]) cmp.emplace_back(a[i],1), psa.emplace_back((i?psa.back():0)+1);
		else cmp.back().second++, psa.back()++;
	}
	int ret = 0, aa = 0, bb = 0, cc = 0;
	for (int gold = 0; gold < cmp.size(); gold++) {
		if (psa[gold] * 3 > n) break;
		auto it = upper_bound(all(psa),psa[gold]*2);
		if (it == psa.end()) break;
		int send = it-psa.begin();
		it = upper_bound(all(psa),psa[send]+psa[gold]);
		if (it == psa.end()) break;
		int bend = it-psa.begin();
		//printf ("bend %d\n",bend);
		if (psa[bend] * 2 > n) break;
		it = upper_bound(all(psa),n/2);
		bend = max(bend,it-psa.begin()-1);
		if (psa[bend] > ret) {
			//printf ("gold %d send %d bend %d\n",gold,send,bend);
			ret = psa[bend];
			aa = psa[gold];
			bb = psa[send]-psa[gold];
			cc = psa[bend]-psa[send];
		}
	}
	printf ("%d %d %d\n",aa,bb,cc);
}
int main() {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
    return 0;
}