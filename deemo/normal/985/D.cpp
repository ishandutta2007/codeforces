#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const ll INF = 2e18;

ll n, h;
bool ok(ll w){
	ll lo = 0, hi = w;
	while (hi-lo>1){
		ll mid = hi+lo>>1;
		if ((w - 1 - mid) >= mid+1 - h)
			lo = mid;
		else
			hi = mid;
	}

	if ((1+(lo+1)) >= INF/ (lo+1)) return true;

	ll tot = (lo+1) * (1 + (lo + 1))/ 2;

	if (w-1-lo > 0){
		if (w-1-lo > lo+1 - h)
			tot += lo+1, w--;
		if (w-1-lo && (lo + (lo + 1 - (w-1-lo))) >= INF/ (w-1-lo)) return true;

		tot += 1ll*(w-1-lo)*(lo + (lo + 1 - (w-1-lo)))/ 2;
	}
	return tot >= n;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> h;
	h = min(n, h);
	ll lo = 0, hi = n;
	while (hi-lo>1){
		ll mid = hi+lo>>1;
		if (ok(mid))
			hi = mid;
		else
			lo = mid;
	}
	cout << hi << endl;
	return 0;
}