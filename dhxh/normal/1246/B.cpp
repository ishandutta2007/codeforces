#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
const long long inf = 1e9 + 5;
const int N = 1e5;

long long n, m;
long long a[maxn];
long long cnt[maxn];
long long c[maxn];
bool vis[maxn];

long long qpow(long long b, long long x){
	long long ret = 1;
	
	while(x){
		if(x & 1){
			if(ret * b / b != ret or ret * b >= inf)return inf;
			ret = ret * b;
		}
		
		x >>= 1;
		if(x and (b * b / b != b or b * b >= inf))return inf;
		b = b * b;
	}
	
	
	return ret;
}

int main(){
	int i, j;
	
	scanf("%lld%lld", &n, &m);
	
	for(i=1;i<=n;i++){
		scanf("%lld", &a[i]);
		cnt[a[i]]++;
	}
	
	for(i=1;i<=N;i++){
		if(qpow(i, m) > N)break;
		vis[qpow(i, m)] = true;
	}
	
	for(i=1;i<=N;i++){
		for(j=1;i*j<=N;j++){
			if(vis[j])c[i] += cnt[i * j];
		}
	}
	
	long long ans = 0;
	
	for(i=1;i<=N;i++){
		if(!cnt[i])continue;
		long long x = 1, y = i;
		for(j=2;j*j<=i;j++){
			int s = 0;
			while(y % j == 0){
				s++;
				y /= j;
			}
			
			if(s % m){
				s = m - s % m;
				if(x * qpow(j, s) / qpow(j, s) != x)x = inf;
				else x = x * qpow(j, s);
				if(x >= inf)x = inf;
			}
		}
		
		if(y > 1){
			int s = 1;
			if(s % m){
				s = m - s % m;
				if(x * qpow(y, s) / qpow(y, s) != x)x = inf;
				else x = x * qpow(y, s);
				if(x >= inf)x = inf;
			}
		}
		
		if(x >= N)continue;
		
		ans += cnt[i] * c[x];
		if(i % x == 0 and vis[i / x])ans -= cnt[i];
	}
	
	ans /= 2;
	
	printf("%lld\n", ans);
	
	return 0;
}