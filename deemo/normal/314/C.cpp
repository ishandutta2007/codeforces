#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAX = 1e6 + 30;

ll n;
ll fen[MAX], ans;
ll last[MAX], a[MAX];

ll get(ll v){
	ll ret = 0;
	for (; v; v -= v & (-v))
		ret = (ret + fen[v]) % MOD;
	return	ret;
}	

void add(ll v, ll val){
	for (v++; v < MAX; v += v & (-v))
		fen[v] = (fen[v] + val) % MOD;
}

int main(){
	scanf("%I64d", &n);
	for (ll i = 0; i < n; i++){
		scanf("%I64d", &a[i]);
		last[a[i]] = i;
	}

	add(0, 1);
	for (ll i = 0; i < n; i++){
		ll temp = (get(a[i] + 1) - get(a[i]) + MOD)  % MOD;
		ll sec = (get(a[i] + 1) * a[i]) % MOD;

		if (last[a[i]] == i)
			ans = (ans + sec) % MOD;
		add(a[i], (sec - temp + MOD*2) % MOD);
	}
	printf("%I64d\n", (ll)ans);
	return 0;	
}