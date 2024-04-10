#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5;
int main () {
	int n,m,l; scanf ("%d %d %d",&n,&m,&l);
	vector<long long> a(n); int ans = 0;
	auto get = [&] (int i) {
		if (i >= n) return false;
		return (a[i] > l) && (i == 0 || a[i-1] <= l);
	};
	for (int i = 0; i < n; i++) {
		scanf ("%lld",&a[i]);
		ans += get(i);
	}
	while (m--) {
		int t; scanf ("%d",&t);
		if (t == 0) {
			printf ("%d\n",ans); 
		} else {
			int i,v; scanf ("%d %d",&i,&v); --i;
			ans -= get(i); ans -= get(i+1);
			a[i] += v;
			ans += get(i); ans += get(i+1);
		}
	}
	return 0;
}