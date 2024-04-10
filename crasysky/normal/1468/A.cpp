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
const int N=1e6+6; int n,st[N],a[N],c[N],f[N];
void update(int x,int y){
	for (;x<=n;x+=x&-x) c[x]=max(c[x],y);
}
int query(int x){
	int mx=0; for (;x;x-=x&-x) mx=max(mx,c[x]); return mx;
}
signed main(){
	int T; scanf("%d",&T);
	while (T--){
		int ans=0,tp=0,mx=0; scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i]),c[i]=0;
		rep(i,1,n){
			ans=max(ans,f[i]=max((int)(mx>a[i]),query(a[i]))+1);
			while (tp&&a[st[tp]]<a[i])
				update(a[st[tp]],++f[st[tp]]),--tp;
			update(a[i],f[i]),st[++tp]=i,mx=max(mx,a[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}