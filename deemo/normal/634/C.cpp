#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 1e6 + 20;

ll n, k, a, b, q, vec[2][MAXN];
ll fen[2][MAXN];

ll get(ll v, ll t){
	ll ret = 0;
	for (; v; v -= v & (-v))
		ret += fen[t][v];
	return	ret;
}

void add(ll v, ll val, ll t){
	for (; v < MAXN; v += v & (-v))
		fen[t][v] += val;
}

int main(){
	scanf("%I64d %I64d %I64d %I64d %I64d", &n, &k, &a, &b, &q);
	while (q--){
		ll type;	scanf("%I64d", &type);
		if (type == 2){
			ll v;	scanf("%I64d", &v);
			printf("%I64d\n", get(v - 1, 0) + (get(MAXN - 2, 1) - get(v + k - 1, 1)));
		}
		else{
			ll v, val;	scanf("%I64d %I64d", &v, &val);
			ll dif = min(val, b - vec[0][v]);
			vec[0][v] += dif;
			add(v, dif, 0);
			dif = min(val, a - vec[1][v]);
			vec[1][v] += dif;
			add(v, dif, 1);
		}
	}
	return	0;
}