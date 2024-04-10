#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

int n, m, t;

long long b[maxn];
long long sum[maxn];
long long f[maxn];

unordered_map <long long, long long> s;

int main(){
	int i, j;
	
	scanf("%d", &t);
	
	while(t--){
		s.clear();
		scanf("%d", &n);
		
		for(i=1;i<=n;i++){
			scanf("%lld", &b[i]);
			sum[i] = sum[i - 1] + b[i];
		}
		
		f[1] = 1;
		s[sum[0]] = (s[sum[0]] + f[1]) % mod;
		
		long long ans = 1;
		long long ss = 1;
		
		for(i=2;i<=n;i++){
			f[i] = (ss - s[sum[i - 1]] + mod) % mod;
			ans = (ans + f[i]) % mod;
			ss = (ss + f[i]) % mod;
			s[sum[i - 1]] = (s[sum[i - 1]] + f[i]) % mod;
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}