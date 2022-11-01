#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1005, P = 998244353;
int n, k, ans, a[N], f[N][N];
int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	sort(a+1, a+n+1);
	for(int x=1; x*(k-1)<=100000; ++x){
		int j=0;
		for(int i=1; i<=n; ++i){
			while(a[i]-a[j+1]>=x) ++j;
			for(int t=1; t<=k; ++t) f[i][t]=(f[i-1][t]+f[j][t-1])%P;
			++f[i][1];
		}
		(ans+=f[n][k])%=P;
	}
	return printf("%d", ans), 0;
}