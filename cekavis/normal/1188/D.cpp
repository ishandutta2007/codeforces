#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005;
int n, cnt[2], p[N], w[N], f[60][N];
ll mx, a[N];
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%lld", a+i), mx=max(mx, a[i]);
	for(int i=1; i<=n; ++i) a[i]=mx-a[i], p[i]=i;
	memset(f, 0x3f, sizeof f), f[0][0]=0;
	for(int i=0; i<60; ++i){
		cnt[0]=cnt[1]=0;
		for(int j=1; j<=n; ++j) ++cnt[a[j]>>i&1];
		int bit=cnt[1], now=0;
		for(int j=0; j<=n; ++j){
			f[i+1][now]=min(f[i+1][now], f[i][j]+bit);
			f[i+1][now+bit]=min(f[i+1][now+bit], f[i][j]+n-bit);
			if(a[p[j+1]]>>i&1) ++now, --bit; else ++bit;
		}
		cnt[0]+=cnt[1];
		for(int j=n; j; --j) w[cnt[a[p[j]]>>i&1]--]=p[j];
		memcpy(p, w, sizeof p);
	}
	printf("%d\n", f[59][0]);
	return 0;
}