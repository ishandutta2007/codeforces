#include <bits/stdc++.h>
using namespace std;
const int MN = 3e3+5;
int get (int n) {
	assert(n>0);
	int ret = 0;
	while (n>0) {
		++ret;
		n /= 10;
	}
	return ret;
}
void solve () {
	int n; scanf ("%d",&n);
	vector<int> a(n+1), b(n+1);
	map<int,int> cntA, cntB;
	multiset<pair<int,int>> have;
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]), cntA[a[i]]++, have.insert({a[i],0});
	for (int i = 1; i <= n; i++) scanf ("%d",&b[i]), cntB[b[i]]++, have.insert({b[i],1});
	int ret = 0;
	while (!have.empty()) {
		auto [v,t] = *have.rbegin();
		if (cntA[v] > 0 && cntB[v] > 0) {
			cntA[v]--; cntB[v]--;
			have.erase(have.find({v,0}));
			have.erase(have.find({v,1}));
			continue;
		}
		++ret;
		(t ? cntB[v] : cntA[v])--;
		have.erase(have.find({v,t}));
		v = get(v);
		(t ? cntB[v] : cntA[v])++;
		have.insert({v,t});
	}
	printf ("%d\n",ret);
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}
//1 2 4 = 1+2+4 = 7
//1 2 4 8 ... =
//1 2 5 = 8
//5
//want n + n-1...
//perm of [n-2] that ends with 0