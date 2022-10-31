#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5+5;
int a[N];

void solve() {
	int n;
	cin >> n;
	int mx = 0, mn = 1e9+5;
	int mxi = 0, mni = 0;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if(a > mx) {
			mxi = i+1;
			mx = a;
		}
		if(a < mn) {
			mn = a;
			mni = i+1;
		}
	}
	cout << mni << ' ' << mxi << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}