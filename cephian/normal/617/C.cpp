#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll dist(ll x1, ll y1, ll x2, ll y2) {
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int n;
ll x[2005],y[2005];
ll fx[2];
ll fy[2];

vector<ll> dx;

int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	cin >> fx[0] >> fy[0] >> fx[1] >> fy[1];
	for(int i =0 ; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	for(int i = 0; i < n; ++i) {
		dx.push_back(dist(fx[0], fy[0], x[i], y[i]));
	}
	dx.push_back(0);
	sort(dx.begin(), dx.end());
	ll ans = dx[n];
	for(int i = 0; i < n; ++i) {
		ll r1 = dx[i];
		ll r2 = 0;
		for(int j = 0; j < n; ++j) {
			if(dist(fx[0], fy[0], x[j], y[j]) <= r1) continue;
			r2 = max(r2, dist(fx[1], fy[1], x[j], y[j]));
		}
		ans = min(ans, r1+r2);
	}
	cout << ans  << "\n";
}