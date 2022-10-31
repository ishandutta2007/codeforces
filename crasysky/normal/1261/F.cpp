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
const int N=1e6+6,P=998244353,inv2=(P+1)/2; const ll R=1LL<<60;
int add(int x,int y){ x+=y; return x>=P?x-P:x; }
int ch[N][2],nd;
void ins(int &u,ll l,ll r,ll ql,ll qr){
	if (r<ql||qr<l) return;
	if (u&&!ch[u][0]&&!ch[u][1]) return;
	if (!u) u=++nd;
	if (ql<=l&&r<=qr){ ch[u][0]=ch[u][1]=0; return; }
	ll m=l+r>>1;
	ins(ch[u][0],l,m,ql,qr),ins(ch[u][1],m+1,r,ql,qr);
}
int S(ll l,ll r){ return (l+r)%P*((r-l+1)%P)%P*inv2%P; }
int dfs(vector<pr> v,ll l,ll r){
	rep0(i,v.size()){
		int &x=v[i].fi,&y=v[i].se;
		if (!ch[x][0]&&!ch[x][1]) x=0;
		if (!ch[y][0]&&!ch[y][1]) y=0;
		if (!x||!y) return S(l,r);
	}
	vector<pr> v1,v2;
	rep0(i,v.size()){
		int x=v[i].fi,y=v[i].se;
		if ((!x||ch[x][0])&&(!y||ch[y][0])) v1.pb(mp(ch[x][0],ch[y][0]));
		if ((!x||ch[x][1])&&(!y||ch[y][1])) v1.pb(mp(ch[x][1],ch[y][1]));
		if ((!x||ch[x][0])&&(!y||ch[y][1])) v2.pb(mp(ch[x][0],ch[y][1]));
		if ((!x||ch[x][1])&&(!y||ch[y][0])) v2.pb(mp(ch[x][1],ch[y][0]));
	}
	int ans=0; ll m=l+r>>1;
	if (v1.size()) ans=add(ans,dfs(v1,l,m));
	if (v2.size()) ans=add(ans,dfs(v2,m+1,r));
	return ans;
}
int main(){
	int na,r1=0; scanf("%d",&na);
	rep(i,1,na){
		ll l,r; scanf("%lld%lld",&l,&r); ins(r1,0,R-1,l,r);
	}
	int nb,r2=0; scanf("%d",&nb);
	rep(i,1,nb){
		ll l,r; scanf("%lld%lld",&l,&r); ins(r2,0,R-1,l,r);
	}
	vector<pr> v; v.pb(mp(r1,r2));
	printf("%d\n",dfs(v,0,R-1));
	return 0;
}