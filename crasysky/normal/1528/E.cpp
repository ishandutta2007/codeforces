#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
#define db long double
#define sit set<int>::iterator
using namespace std;
const int N=1e6+6,P=998244353; int f[N],f2[N],g[N];
int fpw(int x,int y){
	int s=1; for (;y;y>>=1,x=(ll)x*x%P) if (y&1) s=(ll)s*x%P;
	return s;
}
int main(){
	int n; scanf("%d",&n);
	g[0]=1; rep(i,1,n) g[i]=((ll)(g[i-1]+1)*(g[i-1]+1)+(g[i-1]+1))/2%P;
	f[0]=0; rep(i,1,n) f[i]=((ll)g[i-1]*g[i-1]+g[i-1])/2%P;
	int inv6=fpw(6,P-2);
	f2[0]=0; rep(i,1,n) f2[i]=((ll)g[i-1]*g[i-1]%P*g[i-1]+3LL*g[i-1]*g[i-1]%P+2LL*g[i-1])%P*inv6%P;
	per(i,n,1) g[i]=(g[i]+P-g[i-1])%P,f[i]=(f[i]+P-f[i-1])%P,f2[i]=(f2[i]+P-f2[i-1])%P;
	int ans=(2LL*f2[n]+f[n]+g[n])%P; rep(i,1,n-1) ans=(ans+(ll)f[i]*g[n-i-1])%P;
	cout<<ans<<endl;
	return 0;
}