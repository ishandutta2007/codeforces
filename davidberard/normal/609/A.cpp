#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	ll n; cin >> n;
	ll m; cin >> m;
	vector<ll> ai(n);
	for(ll& ii : ai) cin >> ii;
	sort(ai.begin(), ai.end());
	ll sum = 0;
	for(int i=0;i<n;++i) {
		sum += ai[n-1-i];
		if(sum >= m) {
			cout << i+1 << endl;
			break;
		}
	}
	
	return 0;
}