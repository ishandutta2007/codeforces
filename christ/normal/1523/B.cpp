#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
const int MN = 5e5 + 5;
void solve () {
	int n; scanf ("%d",&n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) scanf ("%d",&a[i]);
	vector<array<int,3>> ret;
	for (int i = 1; i <= n; i += 2) {
		for (int j =0;j<3;j++) ret.push_back({2,i,i+1}), ret.push_back({1,i,i+1});
	}
	printf ("%d\n",(int)ret.size());
	for (auto [x,y,z] : ret) printf ("%d %d %d\n",x,y,z);
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}