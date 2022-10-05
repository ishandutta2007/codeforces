/*
sm
s
nn
s
m<=100000
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 100009;
const int MOD = 1000000007;
int n, len, t, m, cnt, fac[maxn], rev[maxn], Pow[maxn];
int f[450][maxn], MAP[maxn];
char s[maxn];

int power(int x, int p){
	int res = 1;
	while (p){
		if (p&1) res = 1LL * res * x % MOD;
		x = 1LL * x * x % MOD; p >>= 1;
	}
	return res;
}

void init(){
	fac[0] = rev[0] = Pow[0] = 1;
	for (int i=1; i<maxn; i++){
		fac[i] = 1LL * fac[i-1] * i % MOD;
		rev[i] = power(fac[i], MOD - 2);
		Pow[i] = 1LL * Pow[i-1] * 25 % MOD;
	}
}

int C(int n, int m){
	return 1LL * fac[n] * rev[n-m] % MOD * rev[m] % MOD;
}

void solve(int len){
	MAP[len] = ++cnt;
	for (int i=len; i<=100000; i++)
		f[cnt][i] = (26LL*f[cnt][i-1]
					+ 1LL*C(i-1, len-1)*Pow[i-len]) % MOD;
}

int main(){
	scanf("%d", &n); init();
	scanf("%s", &s); len = strlen(s); solve(len);
	for (int i=1; i<=n; i++){
		scanf("%d%*c", &t);
		if (t == 1){
			gets(s); len = strlen(s);
			if (!MAP[len]) solve(len);
		}
		else{
			scanf("%d", &m);
			printf("%d\n", f[MAP[len]][m]);
		}
	}
	return 0;
}