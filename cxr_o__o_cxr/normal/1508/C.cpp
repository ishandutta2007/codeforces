//starusc
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1,c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int M=2e5+4;
int n,m,sum,ans=1e18;
namespace solve1{
	const int N=704;
	int vis[N],dis[N],e[N][N],uu[N],vv[N];
	inline int solve(){
		int ret=0;
		memset(vis,0,sizeof(vis));
		vis[1]=1;
		for(int i=1;i<=n;i++)dis[i]=e[1][i];
		for(int t=1,x;t<n;t++){
			x=0;
			for(int i=1;i<=n;i++)if(!vis[i]&&(!x||dis[i]<dis[x]))x=i;
			ret+=dis[x];
			vis[x]=1;
			for(int i=1;i<=n;i++)dis[i]=min(dis[i],e[i][x]); 
		}
		return ret;
	}
	inline void main(){
		for(int i=1,u,v,w;i<=m;i++){
			u=read();v=read();w=read();sum^=w;
			e[u][v]=e[v][u]=w;
		}
		m=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)if(!e[i][j]){
				uu[++m]=i;vv[m]=j;
			}
		for(int i=1;i<=m;i++){
			e[uu[i]][vv[i]]=e[vv[i]][uu[i]]=sum;
			ans=min(ans,solve());
			e[uu[i]][vv[i]]=e[vv[i]][uu[i]]=0;
		}
		cout<<ans<<"\n";
	}
}
namespace solve2{
	struct edge{
		int u,v,w;
	}e[M];
	inline bool comp(const edge &a,const edge &b){
		return a.w<b.w;
	}
	int c[M],fa[M],siz[M];
	vector<int>vec[M];
	map<pair<int,int>,bool>mp;
	set<int>s;
	int find(int x){
		return x==fa[x]?x:fa[x]=find(fa[x]);
	}
	inline void main(){
//		cerr<<"sdfsd\n";
		for(int i=1;i<=m;i++){
			e[i].u=read();e[i].v=read();e[i].w=read();
			if(e[i].u>e[i].v)swap(e[i].u,e[i].v);
			mp[make_pair(e[i].u,e[i].v)]=1;
		}
		sort(e+1,e+m+1,comp);
//		cerr<<"sdfsd\n";
		for(int i=1;i<=n;i++){
			fa[i]=i;
			siz[i]=1;
			s.insert(i);
			vec[i].push_back(i);
		}
//		cerr<<"sdfsd\n";
		for(int i=2,fl;i<=n;i++){
//			cerr<<i<<" i\n";
			c[0]=0;
			for(auto u:s){
				if(u>=i)break;
				c[++c[0]]=u;
//				cerr<<c[0]<<" "<<u<<"\n";
			}
			for(int tt=1,u;tt<=c[0];tt++){
				u=c[tt];
//				cerr<<i<<" "<<u<<"\n";
				fl=0;
				for(auto v:vec[u])if(!mp.count(make_pair(v,i))){
					fl=1;break;
				}
				if(!fl)continue;
//				cerr<<u<<" "<<i<<" merge\n";
				fa[u]=i;
				s.erase(u);
				if(siz[u]>siz[i])swap(vec[u],vec[i]);
				siz[i]+=siz[u];
				for(auto v:vec[u])vec[i].push_back(v);
//				cerr<<"merge_end\n";
			}
//			cerr<<"dsfds\n";
		}
//		cerr<<"sdfsd\n";
		ans=0;
		for(int i=1,u,v;i<=m;i++){
			u=find(e[i].u);v=find(e[i].v);
			if(u!=v){
				fa[u]=v;
				ans+=e[i].w;
			}
		}
		cout<<ans<<"\n";
	}
}
signed main(){
//	freopen("1.in","r",stdin);
	n=read();m=read();
	if(n*(n-1)/2-m<=n-1)solve1::main();
	else solve2::main();
	return (0-0);
}