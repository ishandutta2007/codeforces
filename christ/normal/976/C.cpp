#include <bits/stdc++.h>
using namespace std;
const int MN = 5e5 + 5, M = 2e4 + 5;
int main () {
	int n; scanf ("%d",&n);
	vector<array<int,3>> v;
	for (int i = 1; i <= n; i++) {
		int l,r; scanf ("%d %d",&l,&r);
		v.push_back({l,r,i});
	}
	sort(v.begin(),v.end(),[&] (const auto &a, const auto &b) {
		return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
	});
	array<int,2> r = {-1,-1};
	for (int i = 0; i < n; i++) {
		auto [ll,rr,ii] = v[i];
		if (r[0] >= rr) {
			printf ("%d %d\n",ii,r[1]);
			return 0;
		}
		r = max(r,array<int,2>{rr,ii});
	}
	printf ("-1 -1\n");
	return 0;
}