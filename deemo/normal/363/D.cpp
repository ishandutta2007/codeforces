#include<iostream>
#include<algorithm>
#include<functional>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 10;

ll n, m, sm, nd, vec[MAXN], sec[MAXN];
ll ans;

bool ok(ll mid){
	nd = 0;
	ll tt = 0;
	for (ll i = 0; i < mid; i++){
		nd += max(0LL, sec[mid - i - 1] - vec[i]);
		tt += sec[i];
		if (nd > sm)	return	false;
	}

	ans = max(0LL, tt - sm);
	return	true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> sm;
	for (ll i = 0; i < n; i++)	cin >> vec[i];
	sort(vec, vec + n, greater<ll>());
	for (ll i = 0; i < m; i++)	cin >> sec[i];
	sort(sec, sec + m);

	ll b = 0, e = min(n, m), ret = 0;
	while (b <= e){
		ll mid = (b + e)/ 2;
		if (ok(mid))
			ret = mid, b = mid + 1;
		else
			e = mid - 1;
	}
	ok(ret);
	cout << ret << " " << ans << "\n";
	return	0;	
}