#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 5e5 + 20;

ll n, m, k;
set<ll>	st;
vector<ll>	vec;

ll get(ll x){
	ll ret = 0, r = min(m, x);
	for (ll i = 1; i <= n; i++){
		while (r && i * r >= x)	r--;
		ret += r;
	}
	return	ret;
}

int main(){
	cin >> n >> m >> k;
	ll b = 1, e = n * m, ret;
	while (b <= e){
		ll mid = (b + e)/ 2;
		if (get(mid) < k){
			ret = mid;
			b = mid + 1;
		}
		else	e = mid - 1;
	}
	cout << ret << "\n";
	return	0;
}