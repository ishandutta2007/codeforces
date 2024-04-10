#include<bits/stdc++.h>
#define LL long long
#define pb push_back
using namespace std;
const int N=2e5+5,P=1e9+7;
struct Edge{int to,nxt;}e[N<<1];
int n,fa[N],fst[N],tote,res;LL ans;bool vis[N],fl;
vector<int>ring;
LL qpow(LL x,LL y){LL res=1;for(;y;y>>=1,x=x*x%P)if(y&1)res=res*x%P;return res;}
void adde(int u,int v){e[++tote]=(Edge){v,fst[u]};fst[u]=tote;}
void dfs(int u,int f,int lst){
	vis[u]=true;fa[u]=f;
	for(int i=fst[u],v,lenr;i;i=e[i].nxt){
		v=e[i].to;
		if(!vis[v])dfs(v,u,i);
		else if(!fl&&lst!=(i^1)){
			lenr=1;for(int t=u;t!=v;t=fa[t])lenr++;
			ring.pb(lenr);fl=true;
		}
	}
}
int main(){
	scanf("%d",&n);tote=1;res=n;
	for(int i=1,x;i<=n;i++)scanf("%d",&x),adde(i,x),adde(x,i);
	for(int i=1;i<=n;i++)if(!vis[i])fl=false,dfs(i,0,0);
	for(auto x:ring)res-=x;ans=qpow(2,res);
	for(auto x:ring)ans=(LL)ans*(qpow(2,x)-2+P)%P;
	printf("%d\n",ans);
	return 0;
}