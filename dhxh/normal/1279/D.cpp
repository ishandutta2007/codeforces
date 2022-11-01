#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;
const int mod = 998244353; 

long long cnt[maxn];
vector <int> vec[maxn];
long long fac[maxn];
long long inv[maxn];

int n, m;

long long qpow(long long b, long long x){
	long long ret = 1;
	while(x){
		if(x & 1){
			ret = ret * b % mod;
		}
		b = b * b % mod;
		x >>= 1;
	}
	return ret;
}

int main(){
	int i, j;
	int x, y;
	
	fac[0] = inv[0] = 1;
	
	for(i=1;i<=1e6;i++){
		fac[i] = fac[i - 1] * i % mod;
	}
	inv[(int)1e6] = qpow(fac[(int)1e6], mod - 2);
	
	for(i=1e6;i>0;i--){
		inv[i - 1] = inv[i] * i % mod;
		inv[i] = inv[i] * fac[i - 1] % mod;
	}
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		scanf("%d", &m);
		for(j=1;j<=m;j++){
			scanf("%d", &x);
			vec[i].push_back(x);
			cnt[x]++;
		}
	}
	
	long long ans = 0;
	
	for(i=1;i<=n;i++){
		for(auto j : vec[i]){
			ans = (ans + inv[n] * inv[vec[i].size()] % mod * inv[n] % mod * cnt[j]) % mod;
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}