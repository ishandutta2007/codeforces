#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
const int maxn = 5e5 + 5;

int n, m, k;

int L[maxn], R[maxn], X[maxn];

int sa[maxn];

int g[maxn], h[maxn];
long long sum[maxn], f[maxn];

long long calc(long long l, long long r){
	if(l == 0) return sum[r];
	return (sum[r] - sum[l - 1] + mod) % mod;
}

int main(){
	int i, j;
	long long ans = 1;
	
	scanf("%d%d%d", &n, &k, &m);
	
	for(i=1;i<=m;i++){
		scanf("%d%d%d", &L[i], &R[i], &X[i]);
	}
	
	for(j=0;j<k;j++){
		for(i=1;i<=n+1;i++) sa[i] = sum[i] = f[i] = h[i] = 0;
		for(i=1;i<=m;i++){
			if((X[i] >> j) & 1){
				sa[L[i]]++;
				sa[R[i] + 1]--;
			}
		}
		for(i=1;i<=n;i++) sa[i] += sa[i - 1];
		
		for(i=1;i<=m;i++){
			if(!((X[i] >> j) & 1)){
				h[R[i] + 1] = max(h[R[i] + 1], L[i]);
			}
		}
		
		f[0] = 1;
		sum[0] = 1;
		int l = 0;
		
		for(i=1;i<=n;i++){
			l = max(h[i], l);
			sum[i] = sum[i - 1];
			if(sa[i]) continue;
			f[i] = calc(l, i - 1);
			sum[i] = (sum[i] + f[i]) % mod;
		}
		
		l = max(h[n + 1], l);
		ans = ans * (calc(l, n)) % mod;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}