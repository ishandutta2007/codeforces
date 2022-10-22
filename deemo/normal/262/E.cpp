#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll LOG = 60;
const ll MAX = 60;

ll n, t;
ll c[MAX + 2][MAX + 2];

void init(){
	c[0][0] = 1;
	for (ll i = 1; i < MAX; i++){
		c[i][0] = c[i][i] = 1;
		for (ll j = 1; j < i; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]);
	}
}

ll get(ll x, ll k){
	if (k < 0)
		return	0;
	if (x == 0)	
		return	k == 0;

	ll z = 60;
	while (((x >> z) & 1) == 0)	z--;
	ll ret = c[z][k];
	return	ret + get(x ^ (ll(1) << z), k - 1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> t;
	ll z = -1;
	for (ll i = 0; i < LOG; i++)
		if ((ll(1) << ll(i)) == t){
			z = i;
			break;
		}
	if (z == -1){
		cout << 0 << endl;
		return	0;
	}
	z++;
	init();
	ll ans = get(n + 1, z);
	if (t == 1)
		ans--;
	cout << ans << endl;
	return 0;
}