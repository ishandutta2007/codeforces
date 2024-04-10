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
const int N=1e6+6,P=1e9+7; int d[N]; pr a[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i].fi),a[i].se=i,d[i]=0;
		sort(a+1,a+1+n),reverse(a+1,a+1+n);
		rep(i,1,n-1){
			int u,v; scanf("%d%d",&u,&v);
			++d[u],++d[v];
		}
		ll s=0; rep(i,1,n) s+=a[i].fi;
		int j=1;
		rep(i,1,n-1){
			printf("%lld ",s);
			while (d[a[j].se]==1) ++j;
			s+=a[j].fi,--d[a[j].se];
		}
		putchar('\n');
	}
	return 0;
}