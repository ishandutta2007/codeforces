#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define fi first
#define se second
const int M=1e9+7;
int n,K,fc[100005],dp[55],h[55];
vector<pii>gr[200005];
vector<pii>tr[55];
bool vis[200005];
vector<int>a,b,c;
int id[200005],num[55];
int f[524300],bcj[55],sz[55];
int g[55][30][2],w[30][2],nw[30][2];
int Bcj(int x){return x==bcj[x]?x:bcj[x]=Bcj(bcj[x]);}
void dfs(int x,int c){
	vis[x]=1;
	if(c==0)a.push_back(x);
	if(c==1)b.push_back(x);
	for(auto [y,e]:gr[x])if(!vis[y])dfs(y,c^1);
}
void sub0(){
	if(a.size()<b.size())swap(a,b);
	int m=0;for(auto x:b)id[x]=m++;
	memset(f,0,sizeof(f));f[0]=1;
	for(auto x:a)for(int i=(1<<m)-1;~i;i--)
		for(auto [y,e]:gr[x])if(!((i>>id[y])&1))
			(f[i|(1<<id[y])]+=(ll)f[i]*e%M)%=M;
	memset(h,0,sizeof(h));
	for(int i=0;i<(1<<m);i++)(h[__builtin_popcount(i)]+=f[i])%=M;
}
void calc(int x,int fa){
	for(auto [y,e]:tr[x])if(y!=fa)calc(y,x);
	memset(w,0,sizeof(w));
	w[0][num[x]]=1,sz[x]=1;
	for(auto [y,e]:tr[x])if(y!=fa){
		memset(nw,0,sizeof(nw));
		for(int j=0;j<=sz[x]/2;j++)
			for(int k=0;k<=sz[y]/2;k++){
				(nw[j+k][0]+=(ll)w[j][0]*(g[y][k][0]+g[y][k][1])%M)%=M;
				(nw[j+k][1]+=(ll)w[j][1]*(g[y][k][0]+g[y][k][1])%M)%=M;
				(nw[j+k+1][1]+=(ll)w[j][0]*g[y][k][0]%M*e%M)%=M;
			}
		sz[x]+=sz[y],memcpy(w,nw,sizeof(w));
	}
	memcpy(g[x],w,sizeof(w));
}
void sub1(){
	c.clear();for(auto x:a)c.push_back(x);
	for(auto x:b)c.push_back(x);int m=0;
	for(auto x:c)id[x]=m++;vector<pair<pii,int> >E,EE;
	for(int i=0;i<m;i++)tr[i].clear(),bcj[i]=i;
	for(auto x:c)for(auto [y,e]:gr[x])if(x<y)E.push_back({{id[x],id[y]},e});
	for(auto [p,e]:E){
		auto [u,v]=p;int U=Bcj(u),V=Bcj(v);if(U==V)EE.push_back({p,e});
		else tr[u].push_back({v,e}),tr[v].push_back({u,e}),bcj[U]=V;
	}int mm=EE.size();
	memset(h,0,sizeof(h));
	for(int i=0;i<(1<<mm);i++){
		memset(num,0,sizeof(num));
		int cur=1;
		for(int j=0;j<mm;j++)if((1<<j)&i){
			cur=(ll)cur*EE[j].se%M;
			auto [u,v]=EE[j].fi;
			num[u]++,num[v]++;
		}
		bool ok=1;
		for(int j=0;j<m;j++)ok&=(num[j]<2);
		if(!ok)continue;
		memset(g,0,sizeof(g)),calc(0,-1);
		for(int j=0;j<=m/2;j++){
			int x=(g[0][j][0]+g[0][j][1])%M;
			if(x)(h[j+__builtin_popcount(i)]+=(ll)x*cur%M)%=M;
		}
	}
}
int main(){
	scanf("%d%d",&n,&K);
	fc[0]=1;for(int i=1;i<=n;i++)fc[i]=(ll)fc[i-1]*i%M;
	for(int i=1;i<=K;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		if(z==1)continue;y+=n,z--;
		gr[x].push_back({y,z}),gr[y].push_back({x,z});
	}dp[0]=1;
	for(int i=1;i<=n+n;i++)if(gr[i].size()&&!vis[i]){
		a.clear(),b.clear(),dfs(i,0);
		if(a.size()+b.size()<39)sub0();else sub1();
		for(int j=K;j;j--)for(int k=1;k<=j;k++)
			(dp[j]+=(ll)dp[j-k]*h[k]%M)%=M;
	}
	int ans=0;
	for(int i=0;i<=K;i++)if(dp[i])
		(ans+=(ll)fc[n-i]*dp[i]%M)%=M;
	printf("%d",ans);
}