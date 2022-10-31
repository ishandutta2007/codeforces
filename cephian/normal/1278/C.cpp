#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

const int N = 1e5+5;
int a[N];
int b[N];

void solve() {
	int n;
	cin >> n;

	int diff_a = 0, diff_b = 0;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		if(a[i] == 1) --diff_a;
		else ++diff_a;
	}

	for(int i = 0; i < n; ++i) {
		cin >> b[i];
		if(b[i] == 1) --diff_b;
		else ++diff_b;
	}
	map<int,int> fst;
	fst[diff_b] = 0;
	for(int i = 0; i < n; ++i) {
		if(b[i] == 1) ++diff_b;
		else --diff_b;
		if(!fst.count(diff_b)) {
			fst[diff_b] = i+1;
		}
	}

	int ans = 2*n;
	for(int i = n; i >= 0; --i) {
		if(i != n) {
			if(a[i] == 1) ++diff_a;
			else --diff_a;
		}
		int took = n-i;
		if(!fst.count(-diff_a)) {
			continue;
		}
		took += fst[-diff_a];
		ans = min(ans,took);
	}
	cout << ans << '\n';
}


int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}