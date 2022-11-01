#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

const int N = 2005, P = 998244353;
int n, pa, pb, p, p1[N], p2[N], g[N], h[N], hh[N], f[N][N];
inline int Pow(ll x, int y=P-2){
	int ans=1;
	for(; y; y>>=1, x=x*x%P) if(y&1) ans=ans*x%P;
	return ans;
}
int main() {
	scanf("%d%d%d", &n, &pa, &pb), p=(ll)pa*Pow(pb)%P;
	p1[0]=p2[0]=1;
	for(int i=1; i<=n; ++i) p1[i]=(ll)p1[i-1]*p%P, p2[i]=p2[i-1]*(P+1ll-p)%P;
	f[0][0]=1;
	for(int i=1; i<=n; ++i) for(int j=0; j<=i; ++j){
		f[i][j]=(ll)f[i-1][j]*p1[j]%P;
		if(j) f[i][j]=(f[i][j]+(ll)f[i-1][j-1]*p2[i-j])%P;
	}
	g[1]=1, h[1]=0;
	for(int i=2; i<=n; ++i){
		g[i]=1;
		for(int j=1; j<i; ++j) g[i]=(g[i]-(ll)g[j]*f[i][j])%P;
		for(int j=1; j<i; ++j) h[i]=(h[i]+(hh[j]+(ll)h[i-j]*(1-g[i-j])+(ll)g[i-j]*hh[i-j])%P*g[j]%P*f[i][j])%P;
		hh[i]=(ll)(h[i]+i*(i-1)/2)*Pow(P+1-g[i])%P;
		h[i]=(ll)h[i]*Pow(P+1ll-g[i])%P;
	}
	return printf("%d", (hh[n]+P)%P), 0;
}