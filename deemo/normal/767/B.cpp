#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n;
ll tl, tr, t, st[MAXN];
pair<ll, ll> ans(1e18, 1e18);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tl >> tr >> t;
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> st[i];

	ans = {tl, 0};
	if (n){
		if (st[0] <= tl)
			ans = min(ans, {tl-st[0]+1, st[0]-1});
	}
	ll cur = tl;
	for (int i = 0; i < n && cur + t <= tr; i++){
		if (cur < st[i]){
			cout << cur << "\n";
			return 0;
		}

		if (i){
			ans = min(ans, {cur - (st[i] - 1), st[i] - 1});
		}
		cur += t;
		
	}
	if (cur + t <= tr){
		cout << cur << "\n";
		return 0;
	}

	cout << ans.S << "\n";
	return 0;
}