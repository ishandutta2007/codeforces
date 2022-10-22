#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=2e5+10;
const ll inf=2e15;
const int mod=1e9+7;
inline int MOD(int x) {return x+((x>>31)&mod);}
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,q,a[MAXN],b[MAXN],ans[MAXN];
ll pre[MAXN];
vector<int> Q[MAXN];
int root=1,pcnt=1;
struct seg_tree
{
	int l,r,v1,v2;
}tree[MAXN*55];
#define ls(x) (tree[x].l)
#define rs(x) (tree[x].r)
void change(int x,int v1,int v2)
{
	tree[x].v1=MOD(tree[x].v1+v1-mod);
	tree[x].v2=MOD(tree[x].v2+v2-mod);
}
void down(int x)
{
	if(!ls(x)) tree[x].l=++pcnt;
	if(!rs(x)) tree[x].r=++pcnt;
	change(ls(x),tree[x].v1,tree[x].v2);
	change(rs(x),tree[x].v1,tree[x].v2);
	tree[x].v1=tree[x].v2=0;
}
void xg(ll l,ll r,ll L,ll R,int v1,int v2,int x)
{
	//if(x==1 && L<=-5 && -5<=R) {cerr<<L<<" "<<R<<" "<<v1<<" "<<v2<<endl;}
	if(L<=l && r<=R) {change(x,v1,v2);return;}
	ll len=(r-l+1)/2,mid=l+len-1;
	down(x);
	if(L<=mid) xg(l,mid,L,R,v1,v2,ls(x));
	if(mid<R) xg(mid+1,r,L,R,v1,v2,rs(x));
}
pair<int,int> cx(ll l,ll r,ll zone,int x)
{
	if(!ls(x) && !rs(x)) return make_pair(tree[x].v1,tree[x].v2);
	ll len=(r-l+1)/2,mid=l+len-1;
	down(x);
	if(zone<=mid) return cx(l,mid,zone,ls(x));
	else return cx(mid+1,r,zone,rs(x));
}
int calc(ll x)
{
	pair<int,int> bck=cx(-inf,inf,x,1);
	//cout<<"??????????????????????????????????????????????? "<<x<<" "<<MOD(bck.first+(ll)bck.second*MOD(x%mod)%mod-mod)<<endl;
	return MOD(bck.first+(ll)bck.second*MOD(x%mod)%mod-mod);
}
int main()
{
	n=read(),q=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i) b[i]=read(),pre[i]=pre[i-1]+b[i];
	for(int i=1;i<=q;++i)
	{
		int l=read(),r=read();
		//if(i!=3) continue;
		Q[l-1].push_back(-i);
		Q[r].push_back(i);
	}
	ll now=0;
	for(int i=1;i<=n;++i)
	{
		ll nex=now-b[i];
		int val=(ll)abs(b[i])*a[i]%mod;
		if(b[i]>0)
		{
			xg(-inf,inf,now+1,inf,MOD(-val),0,root);
			xg(-inf,inf,-inf,nex-1,val,0,root);
			xg(-inf,inf,nex,now,(ll)MOD((2*now-b[i])%mod)*a[i]%mod,MOD((-2*a[i]%mod)),root);
		}
		else
		{
			xg(-inf,inf,nex+1,inf,val,0,root);
			xg(-inf,inf,-inf,now-1,MOD(-val),0,root);
			xg(-inf,inf,now,nex,(ll)MOD((-2*now+b[i])%mod)*a[i]%mod,2*a[i]%mod,root);
		}
		now=nex;
		for(int j=0;j<(int)Q[i].size();++j)
		{
			if(Q[i][j]<0) ans[-Q[i][j]]=MOD(ans[-Q[i][j]]-calc(-pre[i]));
			else ans[Q[i][j]]=MOD(ans[Q[i][j]]+calc(-pre[i])-mod);
		}
	}
	for(int i=1;i<=q;++i) printf("%d\n",ans[i]);
	return 0;
}
//ore no turn,draw!