//I'm nothing!
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<map>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int max_n = 3e5;

int n, m, g;
ll save[max_n];

void init(){
	save[0] = save[1] = 1;
	for (int i = 2; i < max_n; i++)
		save[i] = (save[i - 1] * i) % MOD;
}

int pw(ll a, ll b){
	ll ret = 1;
	while (b){
		if (b & 1)	
			ret = (ret * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return	ret;
}

int get(int a, int b){
	if (a < b)	return	0;
	ll ret = save[a];
	ll x = (save[b] * save[a - b]) % MOD;
	x = pw(x, MOD - 2);
	return	(x * ret) % MOD;
}

int main(){
	scanf("%d%d%d", &n, &m, &g);
	init();
	long long ans = 0;
	for (int i = 0; i <= n; i++){
		if (g == 0){
			if (i % 2 == 0){
				if (m > 1 || i != n)
					ans = (ans + get(n + m - i - 1, n - i)) % MOD;
			}
			else if (m <= 1 && i == n)	ans = (ans + 1) % MOD;
		}
		else{
			if (i % 2 == 0){
				if (i == n && m <= 1)	ans = (ans + 1) % MOD;
			}
			else if (i != n || m > 1)	ans = (ans + get(n + m - i - 1, n - i)) % MOD;
		}
	}	
	printf("%d\n", (int)ans);
	return 0;
}