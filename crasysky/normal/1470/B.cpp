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
		int n; scanf("%d",&n);
		rep(i,1,n){
			int x,mx=1; scanf("%d",&x);
			for (int j=1;j*j<=x;++j) if (x%(j*j)==0) mx=j;
			a[i]=x/(mx*mx);
		}
		sort(a+1,a+1+n);
		int ans0=0,c=0,c1=0;
		rep(i,1,n)
			if (a[i]==a[i-1]) ++c;
			else{
				ans0=max(ans0,c);
				if (c%2==0||a[i-1]==1) c1+=c;
				c=1;
			}
		ans0=max(ans0,c);
		if (c%2==0||a[n]==1) c1+=c;
		int q; scanf("%d",&q);
		while (q--){
			ll x; scanf("%lld",&x);
			printf("%d\n",x==0?ans0:max(ans0,c1));
		}
	}
	return 0;
}