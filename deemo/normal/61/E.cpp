#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 1e6 + 20;

ll ans;
ll n, a[MAXN], b[MAXN];
ll fen[2][MAXN];
map<ll, ll>	mp;

ll get(ll v, ll t){
	ll ret = 0;
	for (; v; v -= v & (-v))
		ret += fen[t][v];
	return	ret;
}

void add(ll v, ll val, ll t){
	for (v++; v < MAXN; v += v & (-v))
		fen[t][v] += val;
}

int main(){
	scanf("%I64d", &n);
	for (ll i = 0; i < n; i++)	scanf("%I64d", &a[i]);
	copy(a, a + n, b);
	sort(b, b + n);
	for (ll i = 0; i < n; i++)	mp[b[i]] = i;
	for (ll i = 0; i < n; i++)	a[i] = mp[a[i]];

	for (ll i = 0; i < n; i++){
		ans += get(MAXN - 1, 0) - get(a[i], 0);
		add(a[i], i - get(a[i], 1), 0);
		add(a[i], 1, 1);
	}
	printf("%I64d\n", ans);
	return 0;
}