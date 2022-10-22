#include<bits/stdc++.h>
using namespace std;
const int N=3005;
typedef long long ll;
struct Graph{
	struct Edge{ int to,nxt,c,k; };
	vector<int> head;
	vector<Edge> edge;
	Graph(int n=0,int m=0){
		head=vector<int>(n+1,-1);
		edge.clear(); edge.reserve(m);
	}
	inline void add(int x,int y,int c,int k){
		edge.push_back((Edge){y,head[x],c,k});
		head[x]=edge.size()-1;
	}
}G;
inline void add2(int x,int y,int c,int k){ 
//	printf("[%d %d %d %d]",x,y,c,k);
	G.add(x,y,c,k),G.add(y,x,0,-k); 
}
namespace FLOW{
	int iter[N],lev[N];
	ll dis[N],h[N];
	bool dij(int s,int t,int n){
		priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
		for(int i=0;i<=n;++i) dis[i]=(ll)1e18,lev[i]=0,iter[i]=G.head[i];
		dis[t]=0; lev[t]=1; q.push(make_pair(dis[t],t)); 
		while(!q.empty()){
			int x=q.top().second;ll k=q.top().first; q.pop();
			if(k!=dis[x]) continue;
			for(int j=G.head[x];~j;j=G.edge[j].nxt){
				int y=G.edge[j].to,k1=G.edge[j^1].k+h[x]-h[y];
				if(G.edge[j^1].c>0&&dis[x]+k1<dis[y]){
					dis[y]=dis[x]+k1; lev[y]=lev[x]+1;
					q.push(make_pair(dis[y],y));
				}
			}
		}
		return lev[s]>0;
	}
	int dfs(int x,int o,int mx){
		if(x==o) return mx;
		int ret=0;
		for(int& j=iter[x];~j;j=G.edge[j].nxt){
			int y=G.edge[j].to;
			if(G.edge[j].c>0&&h[y]+G.edge[j].k-h[x]==0&&lev[y]==lev[x]-1){
				int d=dfs(y,o,min(mx-ret,G.edge[j].c));
				if(d>0){
					G.edge[j].c-=d;
					G.edge[j^1].c+=d;
					ret+=d; if(ret==mx) break;
				}
			}
		}
		return ret;
	}
	pair<ll,int> solve(int s,int t,int n){
		for(int i=0;i<=n;++i) h[i]=0;
		pair<ll,int> ret(0,0);
		while(dij(s,t,n)){
			for(int i=0;i<=n;++i) h[i]+=dis[i];
			if((h[s]-h[t])>=0) break;
			int k=dfs(s,t,(int)1e9);
			ret.first+=k*(h[s]-h[t]);
			ret.second+=k;
		}
		return ret;
	}
}
void split_path(int x,int t,vector<int>& g){
	if(x==t) return;
	g.push_back(x);
//	printf("<%d>",x);
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(G.edge[j^1].c>0&&(j%2==0)){
			split_path(y,t,g);
			G.edge[j].c++;
			G.edge[j^1].c--;
			return;
		}
	}
}
int find_bit(int sta){
	return sta&1?0:find_bit(sta>>1)+1;
}
bool vis[N];
int main(){
	int d,n; scanf("%d%d",&d,&n);
	int s=0,t=(1<<d+1)+1;
	G=Graph(t,t*20);
	for(int i=1;i<=n;++i){
		string s; cin>>s;
		int sta=0;
		for(int i=0;i<s.length();++i) 
			if(s[i]=='1') sta|=1<<i;
		vis[sta]=1;
	}
	for(int sta=0;sta<1<<d;++sta){
		add2(sta,1<<d|sta,(int)1e9,0);
		add2(1<<d|sta,t,(int)1e9,1);
		if(vis[sta]) add2(sta,1<<d|sta,1,-(int)1e4);
		for(int j=0;j<d;++j)
			if(~(sta>>j)&1)
				add2(1<<d|sta,1<<j|sta,(int)1e9,1);
	}
	FLOW::solve(s,t,t);
	bool flag=0;
	vector<int> ans;
	while(1){
		vector<int> g; split_path(s,t,g);
		if(g.size()<2) break;
		if(flag) ans.push_back(-1);
		flag=1;
		for(int i=1;i+2<g.size();i+=2)
			ans.push_back(find_bit((g[i]-(1<<d))^g[i+1]));
	//	exit(0);
	}
	printf("%d\n",int(ans.size()));
	for(auto x:ans) {
		if(x==-1) printf("R ");
		else printf("%d ",x);
	}
	return 0;
}