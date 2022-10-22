#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAX = 14;

ll m;
ll c[MAX + 2][MAX + 2], p2[MAX + 2], p8[MAX + 2];
ll ans, g[MAX], d[MAX][MAX], cn[MAX];

void init(){
	c[0][0] = 1;
	for (ll i = 1; i < MAX; i++){
		c[i][0] = c[i][i] = 1;
		for (ll j = 1; j < i; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
	}
	p2[0] = 1;
	for (ll i = 1; i < MAX; i++)
		p2[i] = (p2[i - 1] * 2) % MOD;
	p8[0] = 1;
	for (ll i = 1; i < MAX; i++)
		p8[i] = (p8[i - 1] * 8) % MOD;

	d[0][0] = 1;
	for (ll dig = 1; dig < MAX; dig++)
		for (ll k = 0; k <= dig; k++)
			d[dig][k] = c[dig][k] * p2[k] * p8[dig - k];
}

ll get(ll x, ll cnt, ll z, ll t){
	if (cnt < 0)
		return	0;
	if (t == 0)
		return	cnt == 0;

	ll dig = x/z;
	ll ret = 0;
	for (ll j = 0; j < dig; j++){
		if (j != 4 && j != 7)
			ret += d[t - 1][cnt];
		else if (cnt)
			ret += d[t - 1][cnt - 1];
	}

	if (dig != 4 && dig != 7)
		ret += get(x % z, cnt, z/10, t-1);
	else
		ret += get(x % z, cnt - 1, z/10, t-1);
	return	ret;
}

void gen(ll mx, ll ind, ll sum){
	if (sum >= mx)	return;
	if (ind == 6){
		ll ret = g[mx];
		for (ll i = 0; i < 10; i++){
			if (cn[i] > g[i])	return;
			for (ll j = g[i]; j > g[i] - cn[i]; j--)
				ret = (ret * j) % MOD;
		}
		ans = (ans + ret) % MOD;
		return;
	}

	for (ll i = 0; i < mx; i++){
		cn[i] += 1;
		gen(mx, ind + 1, sum + i);
		cn[i] -= 1;
	}
}

int main(){
	cin >> m;
	init();
	ll z = 1, cnt = 0;
	{
		while (z <= m)	z *= 10;
		z /= 10;

		ll tm = m;
		while (tm){
			cnt++;
			tm/=10;
		}
	}
	for (ll i = 0; i < 10; i++)
		g[i] = get(m, i, z, cnt);
	g[0]--;

	for (ll i = 1; i < 10; i++){
		memset(cn, 0, sizeof(cn));
		gen(i, 0, 0);
	}
	cout << ans << endl;
	return 0;
}