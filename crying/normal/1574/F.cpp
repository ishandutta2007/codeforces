#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
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
const int MAXN=3e5+10,mod=998244353;
int n,m,k,c[MAXN];
int outd[MAXN],ind[MAXN];
int sz[MAXN],valid[MAXN],fa[MAXN];
int vis[MAXN],cnt[MAXN];
ll f[MAXN];
set<int>len;
vector<int>a[MAXN],e[MAXN];
map<pi,int>occ;
int Find(int x){
	if(fa[x]==x)return x;
	return fa[x]=Find(fa[x]); 
}
void Merge(int a,int b){
	if(Find(a)==Find(b)){valid[Find(a)]=0;return;}
	sz[Find(a)]+=sz[Find(b)];
	valid[Find(a)]&=valid[Find(b)];
	fa[Find(b)]=Find(a);
}
void addedge(int u,int v){
	if(occ[mp(u,v)])return;
	occ[mp(u,v)]=1;e[u].pb(v);outd[u]++;ind[v]++;
}
void dp(){
	f[0]=1;
	rep(i,1,m){
		for(auto sz:len){
			ll num=cnt[sz];
			if(sz>i)break;
			f[i]=(f[i]+num*f[i-sz]%mod)%mod;
		}
	}	
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,k)valid[i]=1,fa[i]=i,sz[i]=1;
	rep(i,1,n){
		scanf("%d",&c[i]); 
		rep(j,1,c[i]){
			int tmp;scanf("%d",&tmp);
			a[i].pb(tmp);
		}
		rep(j,1,c[i]-1){
			addedge(a[i][j],a[i][j-1]);
		}
	}
	rep(i,1,k){
		if(ind[i]>=2 || outd[i]>=2 || occ[mp(i,i)]!=0){
			valid[i]=0;
		}
	}
	rep(u,1,k){
		for(auto v:e[u]){
			Merge(u,v);
		}
	}
	rep(i,1,k){
		if(vis[Find(i)])continue;
		vis[Find(i)]=1;
		if(valid[Find(i)]==0)continue;
		cnt[sz[Find(i)]]++;
		len.is(sz[Find(i)]);
	}
	dp();
	printf("%lld",f[m]);
	return 0;
}