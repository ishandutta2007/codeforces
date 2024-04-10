#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6,P=1e9+7; int p[100],c[100],v[100][100];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; scanf("%d",&n);
		rep(j,0,59) c[j]=0;
		rep(j,0,59) rep(k,0,59) v[j][k]=0;
		rep(i,1,n){
			ll x,m=0; scanf("%lld",&x);
			rep(j,0,59) if (x>>j&1) p[++m]=j,++c[j];
			rep(j,1,m) rep(k,1,m) ++v[p[j]][p[k]];
		}
		int ans=0;
		rep(j,0,59)
			rep(k,0,59){
				int t=((ll)v[j][k]*n+(ll)(c[j]-v[j][k])*c[k])%P*c[j]%P;
				ans=(ans+(1LL<<j)%P*((1LL<<k)%P)%P*t)%P;
			}
		printf("%d\n",ans);
	}
	return 0;
}