#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
#define fi first
#define se second
using namespace std;
const int N=2e5+5; int c[N*35],ch[N*35][2],f[N*35];
int main(){
	int n,cnt=1; scanf("%d",&n);
	rep(i,1,n){
		int x,u=1; scanf("%d",&x);
		per(j,30,0){
			int t=x>>j&1;
			if (!ch[u][t]) ch[u][t]=++cnt;
			++c[u=ch[u][t]];
		}
	}
	int ans=n-2;
	rep(u,1,cnt){
		int ls=ch[u][0],rs=ch[u][1];
		f[ls]=f[u]+max(c[rs]-1,0),f[rs]=f[u]+max(c[ls]-1,0);
		if (!ch[u][0]&&!ch[u][1]) ans=min(ans,f[u]);
	}
	cout<<ans<<endl;
    return 0;
}