#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1000005;
int n, m, top, g[N], d[N], mu[N], stk[N];
ll ans=1;
bool a[N], p[N];
vector<int> f[N];
int calc(int x){
	int ans=0;
}
int main() {
	scanf("%d", &n);
	for(int i=0, x; i<n; ++i) scanf("%d", &x), a[x]=1, m=max(m, x);
	fill(mu+1, mu+m+1, 1);
	for(int i=2; i<=m; ++i) if(!p[i]){
		for(int j=i; j<=m; j+=i) mu[j]*=-1, p[j]=1;
		for(ll j=(ll)i*i; j<=m; j+=(ll)i*i) mu[j]=0;
	}
	for(int i=1; i<=m; ++i) for(int j=i; j<=m; j+=i) a[i]|=a[j], ++d[j];
	for(int i=1; i<=m; ++i) f[i].resize(d[i]);
	for(int i=1; i<=m; ++i) for(int j=i; j<=m; j+=i) f[j][--d[j]]=i;
	for(int i=m; i; --i) if(a[i]){
		int x=0;
		for(int j:f[i]) x+=mu[j]*g[j];
		if(x){
			while(x){
				for(int j:f[stk[top]]) --g[j], x-=mu[j]*!(i%j);
				--top;
			}
			ans=max(ans, (ll)i*stk[++top]);
			for(int j:f[stk[top]]) ++g[j];
		}
		for(int j:f[i]) ++g[j];
		stk[++top]=i;
	}
	printf("%lld\n", ans);
	return 0;
}