#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

bool ok(int a) {
	set<int> d;
	while(a) {
		if(d.count(a%10)) return false;
		d.insert(a%10);
		a /= 10;
	}
	return true;
}


int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int l, r;
	cin >> l >> r;
	for(int i = l; i <= r; ++i) {
		if(ok(i)) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << "-1\n";
}