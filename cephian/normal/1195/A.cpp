#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n, k;
	cin >> n >> k;
	set<int> S;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if(S.count(a))
			S.erase(a);
		else
			S.insert(a);
	}
	cout << n-S.size()/2 << '\n';
}