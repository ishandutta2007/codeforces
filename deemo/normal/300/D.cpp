#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

typedef long long ll;

const ll MOD = 7340033;
const ll MAX = 1e9;
const ll max_k = 1e3 + 4;
const ll LOG = 30 + 5;

ll d[LOG][3 * max_k];
ll save1[max_k];

void init(){
	for (ll i = 0; i < LOG; i++)	d[i][0] = 1;

	ll x = 3;
	for (ll j = 2; x <= MAX; x = (x << 1) ^ 1, j++){
		ll y = x >> 1;

		memset(save1, 0, sizeof(save1));

		for (ll i = 0; i < max_k; i++){
			for (ll w = 0; w <= i; w++)
				save1[i] = (save1[i] + (d[j - 1][w] * d[j - 1][i - w])) % MOD;
		}

		for (ll i = 0; i < max_k; i++)
			for (ll w = 0; w < max_k; w++)
				d[j][i + w + 1] = (d[j][i + w + 1] + save1[i] * save1[w]) % MOD;
	}
}

int main(){
	init();
	ll q;	scanf("%I64d", &q);
	while (q--){
		ll x, k;	scanf("%I64d%I64d", &x, &k);
		ll y = 0;
		while (x & 1)	x >>= 1, y = (y << 1) ^ 1;
		ll cn = __builtin_popcount(y);
		if (x)	cn++;
		printf("%I64d\n", d[cn][k]);
	}
	return 0;
}