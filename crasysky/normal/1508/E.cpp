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
using namespace std;
const int N=3e5+5;
int a[N],p[N],dfn[N],fa[N]; vector<int> G[N];
bool checkdfn(int u,int &c){
	++c; if (dfn[u]!=c) return true;
	rep0(i,G[u].size()) if (checkdfn(G[u][i],c)) return true;
	return false;
}
int q[N],ql,qr,op; ll ans;
void solve(int u){
	q[++qr]=dfn[u];
	rep0(i,G[u].size()){
		solve(G[u][i]); if (ans==-1) return;
	}
	if (q[ql]==a[u]&&op!=2){
		ans+=qr-ql,++ql; if (op==1) op=2;
	}
	else if (q[qr]==a[u]){
		--qr; if (op==0) op=1;
	}
	else{ ans=-1; return; }
}
bool cmp(int x,int y){ return dfn[x]<dfn[y]; }
int main(){
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]),p[a[i]]=i;
	rep(i,1,n-1){
		int u,v; scanf("%d%d",&u,&v); G[u].pb(v),fa[v]=u;
	}
	int cnt=0;
	rep(i,1,n){
		static int st[N]; int tp=0;
		for (int u=p[i];u&&!dfn[u];u=fa[u]) st[++tp]=u;	
		while (tp) dfn[st[tp--]]=++cnt;
	}
	rep(i,1,n) sort(G[i].begin(),G[i].end(),cmp);
	int nd=0;  if (checkdfn(1,nd)){ puts("NO"); return 0; }
	ql=1,qr=0,solve(1);
	if (ans==-1){ puts("NO"); return 0; }
	else{
		printf("YES\n%lld\n",ans);
		rep(i,1,n) printf("%d ",dfn[i]); putchar('\n');
	}
	return 0;
}