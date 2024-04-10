#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const int MAX = 1e6 + 200;
const int max_n = 1e5 + 200;
const int MOD = 1e9 + 7;

int n;
int a[max_n];
ll fen[MAX];

ll get(int v){
	ll ret = 0;
	for (; v; v -= v & (-v))
		ret = (ret + fen[v]) % MOD;
	return	ret;
}

void add(int v, ll val){
	for (v++; v < MAX; v += v & (-v))
		fen[v] = (fen[v] + val) % MOD;
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	ll ans = 0;
	add(0, 1);
	for (int i = 0; i < n; i++){
		ll x = get(a[i] + 1);
		x = (x * a[i]) % MOD;
		add(a[i], -(get(a[i] + 1) - get(a[i])));
		add(a[i], x);
	}
	printf("%d\n", ((int)get(MAX - 2) + MOD - 1) % MOD);
	return 0;
}