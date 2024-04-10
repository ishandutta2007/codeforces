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
const int MAXN=2e5+10;
int T,n,m,u,v;
int fa[MAXN],dis[MAXN],sz[MAXN],vis[MAXN];
int cnt[MAXN];
int Find(int x){
	if(fa[x]==x)return x;
	int root=Find(fa[x]);dis[x]^=dis[fa[x]];
	return fa[x]=root;
}
string tmp;
void solve(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		fa[i]=i;dis[i]=0;sz[i]=1;vis[i]=0;cnt[i]=0;
	}
	int flag=1;
	rep(i,1,m){
		scanf("%d%d",&u,&v);cin>>tmp;
		int w=1;if(tmp=="crewmate")w=0;
		int p=Find(u),q=Find(v);
		if(p==q){
			if((dis[u]^dis[v])!=w){
				if(flag)printf("-1\n");
				flag=0;
			} 
		}else{
			dis[p]=w^dis[u]^dis[v];
			sz[q]+=sz[p];
			fa[p]=q;
		}
	}
	if(!flag)return;
	rep(i,1,n){
		int p=Find(i);
		if(dis[i]==0)cnt[fa[i]]++;
	} 
	int ans=0;
	rep(i,1,n){
		if(Find(i)!=i)continue;
		int num=sz[i];
		ans+=max(cnt[i],num-cnt[i]);
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--){
		solve();
	}

	return 0;
}