#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int N=2e5+10;
struct node{
	int v,nxt,id;
	node(int v=0,int nxt=0,int id=0):v(v),nxt(nxt),id(id){}
}e[N<<2];
int n,cnt=1,head[N<<1];
void add(int u,int v,int id){
	e[++cnt]=node(v,head[u],id);head[u]=cnt;
	e[++cnt]=node(u,head[v],id);head[v]=cnt;
}
int tot;map<pll,int>p;
int get(ll x,ll y){
	pll a=mp(x/__gcd(x,y),y/__gcd(x,y));
	if(p.find(a)!=p.end())return p[a];
	return p[a]=++tot;
}
vector<pii>ans;
int match[N<<1];bool vis[N<<1];
void dfs(int u){
	vis[u]=1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].v,Id=e[i].id;if(!Id)continue;
		e[i].id=e[i^1].id=0;
		if(!vis[v])dfs(v);
		if(match[v]){
			ans.pb(mp(Id,match[v]));
			match[v]=0;
		}else if(match[u]){
			ans.pb(mp(Id,match[u]));
			match[u]=0;
		}else match[u]=Id;
	}
}
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
		int u=get(1ll*(a+b)*d,1ll*c*b);
		int v=get(1ll*a*d,1ll*(c+d)*b);
		add(u,v,i);
	}
	for(int i=1;i<=tot;i++)if(!vis[i])dfs(i);
	printf("%d\n",ans.size());
	for(auto kk:ans)printf("%d %d\n",kk.first,kk.second);
}