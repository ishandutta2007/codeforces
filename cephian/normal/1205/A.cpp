#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	if(n%2 == 0) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for(int i = 0; i < 2*n; ++i) {
			if(i%2 == 0) {
				cout << 2*(i%n)+1 << '\n';
			} else {
				cout << 2*(i%n)+2 << '\n';
			}
		}
	}
}