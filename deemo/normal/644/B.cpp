#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAX = 1e16 + 10;

ll n, k;
map<ll, ll>	fen;

ll get(ll v){
	ll ret = 0;
	for (; v; v -= v & (-v))
		ret += fen[v];
	return	ret;
}

void add(ll l, ll r){
	for (; l < MAX; l += l & (-l))
		fen[l]++;
	for (; r < MAX; r += r & (-r))
		fen[r]--;
}

int main(){
	scanf("%I64d %I64d", &n, &k);
	ll mx = 0;
	while (n--){
		ll t, v;	scanf("%I64d %I64d", &t, &v);
		if (get(t) >= k)
			printf("-1 ");
		else{
			printf("%I64d ", max(mx, t) + v);
			add(t, max(mx, t));
			mx = max(mx, t) + v;
		}
	}
	printf("\n");
	return	0;
}