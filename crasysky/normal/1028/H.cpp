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
const int N=1.2e6,V=5.2e6,INF=1e9;
int n,C[N];
void push(int i,int v){ for (;i;i-=i&-i) C[i]=min(C[i],v); }
int query(int i){ int v=INF; for (;i<=n;i+=i&-i) v=min(v,C[i]); return v; }
int pm[V],f[V],cnt[V],a[N],ans[N]; vector<pr> G[N]; vector<int> st[V];
int main(){
	int q,mx=0; scanf("%d%d",&n,&q);
	rep(i,1,n) scanf("%d",&a[i]),mx=max(mx,a[i]);
	int pc=0; static int p[V],pm[V],tg[V]; f[1]=1;
	rep(i,2,mx){
		if (!tg[i]) p[++pc]=i,pm[i]=pc,f[i]=i,cnt[i]=1;
		for (int j=1,v;j<=pm[i]&&(v=i*p[j])<=mx;++j){
			tg[v]=true,pm[v]=j,cnt[v]=cnt[i]+1;
			if (f[i]%p[j]) f[v]=f[i]*p[j]; else f[v]=f[i]/p[j];
		}
	}
	rep(i,1,n) a[i]=f[a[i]];
	rep(i,1,q){ int l,r; scanf("%d%d",&l,&r); G[r].pb(mp(l,i)); }
	rep(i,1,n) C[i]=INF;
	rep(i,1,n){
		int c=0,v[1000]; for (int x=a[i];x!=1;x/=p[pm[x]]) v[++c]=p[pm[x]];
		rep0(s,1<<c){
			int d=1; rep(i,1,c) if (s>>i-1&1) d*=v[i];
			#define back(d) (*--st[d].end())
			while (st[d].size()&&cnt[a[back(d)]]>=cnt[a[i]]){
				push(back(d),cnt[a[back(d)]]+cnt[a[i]]-2*cnt[d]),st[d].pop_back();
			}
			if (st[d].size())
				push(back(d),cnt[a[back(d)]]+cnt[a[i]]-2*cnt[d]);
			st[d].pb(i);
 		}
		rep0(j,G[i].size()) ans[G[i][j].se]=query(G[i][j].fi);
	}
	rep(i,1,q) printf("%d\n",ans[i]);
	return 0;
}