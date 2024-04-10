#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 200005, M = 3005, P = 998244353;
int n, m, ans, is0, is1, s[2], is[M<<1], a[N], w[N], f[M][M];
inline int Pow(ll x, int y=P-2){
	int ans=1;
	for(; y; y>>=1, x=x*x%P) if(y&1) ans=ans*x%P;
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=1; i<=n; ++i) scanf("%d", w+i), s[a[i]]+=w[i];
	is0=Pow(s[0]), is1=Pow(s[1]);
	for(int i=-m; i<=m; ++i) is[i+m]=Pow(s[0]+s[1]+i);
	f[0][0]=1;
	for(int i=0; i<m; ++i) for(int j=0; j<=i; ++j) if(f[i][j]){
		f[i+1][j]=(f[i+1][j]+(ll)f[i][j]*(s[0]-(i-j))%P*is[m+j-i+j])%P;
		f[i+1][j+1]=(f[i+1][j+1]+(ll)f[i][j]*(s[1]+j)%P*is[m+j-i+j])%P;
	}
	for(int i=0; i<=m; ++i) ans=(ans+(ll)i*f[m][i])%P;
	for(int i=1; i<=n; ++i)
		if(a[i]) printf("%lld\n", (w[i]+(ll)w[i]*is1%P*ans)%P);
		else printf("%lld\n", (w[i]+(ll)(P-w[i])*is0%P*(m+P-ans))%P);
	return 0;
}