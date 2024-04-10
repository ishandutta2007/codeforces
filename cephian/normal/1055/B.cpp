#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int N = 1e5+5;
ll a[N];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n, m, l;
	cin >> n >> m >> l;
	for(ll i = 1; i <= n; ++i)
		cin >> a[i];
	a[0] = 0;
	a[n+1] = 0;
	int segs = 0;
	for(int i = 1; i < n+1; ++i) {
		segs += a[i] > l && a[i-1] <= l;
	}

	for(ll i = 0; i < m; ++i) {
		ll t, p, d;
		cin >> t;
		if(t == 0) {
			cout << segs << "\n";
		} else { 
			cin >> p >> d;
			if(a[p] <= l && a[p]+d > l) {
				if(a[p-1] <= l && a[p+1] <= l)
					++segs;
				else if(a[p-1] > l && a[p+1] > l)
					--segs;
			}
			a[p] += d;
		}
	}

}