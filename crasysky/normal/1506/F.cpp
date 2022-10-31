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
using namespace std;
const int N=1e6+6; pr a[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i].fi);
		rep(i,1,n) scanf("%d",&a[i].se);
		sort(a+1,a+1+n);
		ll ans=0; int x=1,y=1;
		rep(i,1,n){
			if (a[i].fi-x==a[i].se-y){
				if (!(x+y&1)) ans+=a[i].fi-x;
			}
			else ans+=((a[i].fi-x)-(a[i].se-y)+(x+y&1))/2;
			x=a[i].fi,y=a[i].se;
		}
		printf("%lld\n",ans);
	}
	return 0;
}