#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int l;
		cin >> l;
		bool done = false;
		for(int i = 2; i <= n; ++i) {
			int a;
			cin >> a;
			if(!done) {
				if(abs(a-l) > 1) {
					done = true;
					cout << "YES\n" << i-1 << ' ' << i << '\n';
				}
				l = a;
			}
		}
		if(!done)
			cout << "NO\n";
	}
}