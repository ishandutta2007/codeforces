#include<bits/stdc++.h>
using namespace std;
const int N = 4005, K = 805;
int n, k, ans, f[N], cnt[N], a[N][N], g[N][N];
char buf[1<<26], *s=buf;
inline void read(int &x){
	x=0;
	while(isspace(*s)) ++s;
	x=*s++-'0';
	while(isdigit(*s)) x=x*10+*s++-'0';
}
inline int check(int x){
	memset(f, 0x3f3f3f3f, sizeof f);
	f[0]=0;
	for(int i=1; i<=n; ++i){
		int *G=g[i];
		for(int j=0; j<i; ++j) if(f[j]+G[j+1]+x<f[i]) f[i]=f[j]+G[j+1]+x, cnt[i]=cnt[j]+1;
	}
	return cnt[n];
}
int main(){
	fread(buf, 1, 1<<26, stdin);
	read(n), read(k);
	for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) read(a[i][j]), a[i][j]+=a[i][j-1];
	for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j) g[j][i]=g[j-1][i]+a[j][j-1]-a[j][i-1];
	int l=0, r=g[n][1];
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)<=k) ans=f[n]-k*mid, r=mid-1; else l=mid+1;
	}
	return printf("%d", ans), 0;
}