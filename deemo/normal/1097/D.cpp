#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define F first
#define S second

const ll MOD = 1e9 + 7;
const ll XX = 50 + 2;
const ll MAXK = 1e4 + 10;

ll n;
ll k, ans = 1, pr[MAXK][XX][XX], pt[XX][XX], sv[XX];

ll add(ll x, ll y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}

ll pw(ll a, ll b){
	ll ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}

ll pp[XX];
ll get(ll p, ll c){
	ll temp = p%MOD;
	pp[0] = 1;
	for (ll i = 1; i < XX; i++)
		pp[i] = 1ll*pp[i-1]*temp%MOD;

	ll ret = 0;
	for (ll b = 0; b <= c; b++){
		ret = add(ret, 1ll*pr[k][c][b]*pp[b]%MOD);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (ll i = 0; i < XX; i++)
		sv[i] = pw(i+1, MOD-2);

	for (ll j = 0; j < MAXK; j++){
		if (j == 0)
			for (ll i = 0; i < XX; i++)
				pr[0][i][i] = 1;
		else{
			for (ll i = 0; i < XX; i++){
				pt[i][i] = pr[j-1][i][i];
				for (ll k = i+1; k < XX; k++)
					pt[i][k] = add(pt[i][k-1], pr[j-1][k][i]);
			}

			for (ll st = 0; st < XX; st++)
				for (ll en = 0; en <= st; en++)
					pr[j][st][en] = 1ll*sv[st]*pt[en][st]%MOD;
		}
	}

	cin >> n >> k;
	for (ll i = 2; i * i <= n; i++)
		if (n%i == 0){
			ll c = 0;
			while (n%i == 0)
				n /= i, c++;
			
			ans = 1ll*ans*get(i, c)%MOD;
		}
	if (n > 1)
		ans = 1ll*ans*get(n, 1)%MOD;
	cout << ans << "\n";
	return 0;
}