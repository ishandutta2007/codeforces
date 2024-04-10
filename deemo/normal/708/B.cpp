#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAXN = 1e6 + 10;

ll a[5];
string ans;
ll ss[MAXN];

bool ok(ll aa, ll bb){
	if (1ll * aa * (aa - 1)/2 != a[0])	return false;
	if (1ll * bb * (bb - 1)/2 != a[3])	return false;
	if (1ll * aa * bb != a[1] + a[2])	return false;
	ans = "";
	for (ll i = 0; i < aa; i++)	ans += '0';
	for (ll i = 0; i < bb; i++)	ans += '1';
	ll rem = aa * bb - a[1], cur = aa, ptr = 0;
	for (ll i = aa; rem && i < aa + bb; i++){
		ll g = min(rem, aa);
		rem -= g;
		swap(ans[i], ans[i - g]);
	}
	return ans.size() > 0;
}

int main(){
	for (ll i = 2; i < MAXN; i++)
		ss[i] = 1ll * i * (i - 1)/ 2;
	for (ll i = 0; i < 4; i++)	cin >> a[i];

	ll aa = 0, bb = 0;
	bool fail = 1;
	for (ll i = 0; i < MAXN; i++)
		if (ss[i] == a[0]){
			aa = i;
			fail = 0;
			break;
		}

	if (fail){
		cout << "Impossible\n";
		return 0;
	}

	fail = 1;
	for (ll i = 0; i < MAXN; i++)
		if (ss[i] == a[3]){
			bb = i;
			fail = 0;
			break;
		}

	if (fail){
		cout << "Impossible\n";
		return 0;
	}

	for (ll i = aa; i <= aa + 1; i++)
		for (ll j = bb; j <= bb + 1; j++)
			if (ok(i, j)){
				cout << ans << "\n";
				return 0;
			}

	cout << "Impossible\n";
	return 0;
}