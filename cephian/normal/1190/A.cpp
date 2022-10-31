#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 1e5+5;
ll p[M];

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	ll n, k;
	int m;
	cin >> n >> m >> k;
	for(int i = 0; i < m; ++i) {
		cin >> p[i];
	}
	
	ll ctr = 0;
	int ans = 0;
	int j = 0;
	while(j < m) {
		if(p[j] <= ctr) {
			++ans;
			int rem = 0;
			while(j < m && p[j] <= ctr) {
				++j;
				++rem;
			}
			ctr += rem;
		} else {
			ctr += ((p[j]-ctr)/k) * k;
			if(ctr < p[j]) ctr += k;
		}
	}
	cout << ans << '\n';
}