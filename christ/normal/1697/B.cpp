#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 5, MOD = 1e9 + 123;
int main () {
	int n,q; scanf ("%d %d",&n,&q);
	vector<long long> v(n);
	for (long long &i : v) scanf ("%lld",&i);
	sort(v.rbegin(),v.rend());
	for (int i = 1; i < n; i++) v[i] += v[i-1];
	auto get = [&] (int l, int r) {
		if (l == 0) return v[r];
		return v[r] - v[l-1];
	};
	while (q--) {
		int x,y; scanf ("%d %d",&x,&y);
		printf ("%lld\n",get(x-y,x-1));
	}
	return 0;
}
//x=3, y=2