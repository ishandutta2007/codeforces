#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=2e5+10;
ll n,q,st,d,ed,k;
ll a[(int)1e6+10],fa[MAXN],num[(int)1e6+10];
ll nxt[MAXN];
pi gnxt[MAXN];
vector<ll>group[MAXN];
vector<pair<ll,ll>>e[MAXN];
set<ll>s1;
set<ll,greater<ll>>s2;
ll maxw[MAXN];
ll getdis(int x,int y){return abs(d-abs(a[x]-a[y]));}
int Find(int x){
	if(fa[x]==x)return x;
	return fa[x]=Find(fa[x]);
}
void Merge(int x,int y){
	if(Find(x)==Find(y))return;
	fa[Find(y)]=Find(x);
	e[x].pb(mp(y,getdis(x,y)));
	e[y].pb(mp(x,getdis(x,y)));
}
int check(){
	rep(i,2,n)if(Find(1)!=Find(i))return 1;
	return 0;
}
void check(int x,int y){
	if(!nxt[x])nxt[x]=y;
	else if(getdis(x,y) < getdis(x,nxt[x]))nxt[x]=y;
}
void dfs(int u,int fa){
	for(vector<pair<ll,ll>>::iterator it=e[u].begin();it!=e[u].end();it++){
		pair<ll,ll>nxt=*it;
		if(fa==nxt.fr)continue;
		maxw[nxt.fr]=max(maxw[u],nxt.se);
		dfs(nxt.fr,u);
	}
}
int main(){
	cin>>n>>q>>st>>d;
	rep(i,1,n){
		cin>>a[i];
		num[a[i]]=i;
		fa[i]=i;
		s1.is(a[i]);
		s2.is(a[i]);
	}
	while(check()){
		rep(i,1,n){nxt[i]=0;gnxt[i]=mp(0,0);group[i].clear();}
		rep(i,1,n){group[Find(i)].pb(i);}
		rep(i,1,n){
			int sz=group[i].size();
			rep(j,0,sz-1){
				s1.erase(a[group[i][j]]);
				s2.erase(a[group[i][j]]);
			}
			rep(j,0,sz-1){
				//u<v
				if(s1.lower_bound(a[group[i][j]]+d)!=s1.end()){
					ll v=*s1.lower_bound(a[group[i][j]]+d);
					v=num[v];
					if(group[i][j]<v)check(group[i][j],v);
				}
				if(s2.lower_bound(a[group[i][j]]+d)!=s2.end()){
					ll v=*s2.lower_bound(a[group[i][j]]+d);
					v=num[v];
					if(group[i][j]<v)check(group[i][j],v);
				}
				//u>v 
				if(s1.lower_bound(a[group[i][j]]-d)!=s1.end()){
					ll v=*s1.lower_bound(a[group[i][j]]-d);
					v=num[v];
					if(group[i][j]>v)check(group[i][j],v);
				}
				if(s2.lower_bound(a[group[i][j]]-d)!=s2.end()){
					ll v=*s2.lower_bound(a[group[i][j]]-d);
					v=num[v];
					if(group[i][j]>v)check(group[i][j],v);
				}
				//
				if(gnxt[i].se==0 || getdis(gnxt[i].fr,gnxt[i].se)>getdis(group[i][j],nxt[group[i][j]]))gnxt[i]=
				mp(group[i][j],nxt[group[i][j]]); 
			}
			rep(j,0,sz-1){
				s1.is(a[group[i][j]]);
				s2.is(a[group[i][j]]);
			}
		}
		rep(i,1,n){
			if(gnxt[i].se==0)continue;
			int u=gnxt[i].fr,v=gnxt[i].se;
			Merge(u,v);
		}
	}
	dfs(st,0);
	rep(i,1,q){
		cin>>ed>>k;
		if(maxw[ed]<=k)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}