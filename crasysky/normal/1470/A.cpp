#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6; int c[N],a[N],q[N],q2[N]; 
signed main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,m; scanf("%d%d",&n,&m);
		rep(i,1,m) c[i]=0;
		rep(i,1,n){
			int k; scanf("%d",&k),++c[k];
		}
		rep(i,1,m) scanf("%d",&a[i]);
		int l=1,r=0,l2=1,r2=0; ll ans=0;
		rep(i,1,m){
			rep(j,1,c[i])
				if (l<=r&&(l2>r2||a[q[l]]<q2[l2])) ans+=a[q[l++]],q2[++r2]=a[i];
				else if (l2<=r2&&(l>r||a[q[l]]>=q2[l2])) ans+=q2[l2++],q2[++r2]=a[i];
				else ans+=a[i];
			q[++r]=i;
		}
		printf("%lld\n",ans);
	}
	return 0;
}