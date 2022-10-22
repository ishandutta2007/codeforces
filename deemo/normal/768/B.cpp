#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

ll get(ll n, ll ind, ll cc){
	if (n < 2) return n;
	ll cur = (1ll<<cc-1) -1;
	if (ind <= cur)
		return get(n>>1, ind,cc-1);
	if (ind == cur + 1)
		return n&1;
	return get(n>>1, ind-cur-1,cc-1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, l, r;
	cin >> n >> l >> r;

	ll temp = n, cc = 1;
	temp >>= 1;
	while (temp){
		cc++;
		temp >>= 1;
	}
	int cnt = 0;
	for (ll i = l; i <= r; i++)
		if (get(n, i, cc)){
			cnt++;
		}
	cout << cnt << "\n";
	return 0;
}