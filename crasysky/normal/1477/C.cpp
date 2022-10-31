#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=1e6+6;
int x[N],y[N]; bool vis[N];
ll d(int i,int j){
	return (ll)(x[i]-x[j])*(x[i]-x[j])+(ll)(y[i]-y[j])*(y[i]-y[j]);
}
int main(){
	int n; scanf("%d",&n); rep(i,1,n) scanf("%d%d",&x[i],&y[i]);
	printf("%d ",1),vis[1]=true;
	for (int p=1,i=2;i<=n;++i){
		ll s=0; int u;
		rep(j,1,n)
			if (!vis[j]&&d(p,j)>s) u=j,s=d(p,j);
		printf("%d ",u),vis[p=u]=true;
	}
	return 0;
}