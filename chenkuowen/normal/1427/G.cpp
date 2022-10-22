#include<bits/stdc++.h>
using namespace std;
const int N=50005;
typedef long long ll;
struct Graph{
	struct Edge{ int to,nxt,c; }edge[N*12];
	int head[N],top;
	Graph(){memset(head,-1,sizeof(head)),top=-1;}
	inline void add(int x,int y,int k){
		edge[++top]=(Edge){y,head[x],k};
		head[x]=top;
	}
}G;
inline void add2(int x,int y,int k){
//	printf("[%d %d %d]",x,y,k);
	G.add(x,y,k); G.add(y,x,0);
}
inline void add3(int x,int y,int k){
//	printf("<%d %d %d>",x,y,k);
	G.add(x,y,k); G.add(y,x,k);
}
namespace FLOW{
	bool vis[N];
	int dfs(int x,int o,int mi){
		if(x==o) return mi; 
		vis[x]=true;
		for(int j=G.head[x];~j;j=G.edge[j].nxt){
			int y=G.edge[j].to;
			if(G.edge[j].c>0&&!vis[y]){
				int d=dfs(y,o,min(mi,G.edge[j].c));
				if(d>0){
					G.edge[j].c-=d;
					G.edge[j^1].c+=d;
					return d;
				}	
			}
		}
		return 0;
	}
	int max_flow(int s,int t,int n,int mx=(int)1e9){
		int ret=0,d;
		while(1){
			memset(vis,0,sizeof(bool)*(n+1));
			d=dfs(s,t,mx-ret);
			if(d>0) ret+=d;
			else break;
		}
		return ret;
	}
}
int id[205][205],a[205][205],s,t,top_node,ans=0;
void change(int x){
	int key1=0;
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y==s){
			key1=G.edge[j].c;
			G.edge[j].c=G.edge[j^1].c=0;
		}
	}
	assert(key1<=4);
	int key=FLOW::max_flow(t,x,top_node,key1);
//	assert(key==key1);
	ans-=key;
	add2(x,t,(int)1e9);
	ans+=FLOW::max_flow(s,t,top_node);
}
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int main(){
	int n; scanf("%d",&n); top_node=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			scanf("%d",&a[i][j]);
			if(a[i][j]!=-1) id[i][j]=++top_node;
		}
	}
	vector<pair<int,int> > f;
	s=++top_node; t=++top_node;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			if(a[i][j]==-1) continue;
			for(int asp=0;asp<2;++asp){
				int x=i+dx[asp],y=j+dy[asp];
				if(x<1||x>n||y<1||y>n||a[x][y]==-1) 
					continue;
				add3(id[i][j],id[x][y],1);
			}
			if(a[i][j]>0){
				f.push_back(make_pair(a[i][j],id[i][j]));
				add2(s,id[i][j],(int)1e9);
			}
		}
	ans=FLOW::max_flow(s,t,top_node);
//	printf("|%d|",ans);
	sort(f.begin(),f.end());
	ll ret=0;
	for(int i=0;i+1<f.size();++i){
		int len=f[i+1].first-f[i].first;
		change(f[i].second);
//		printf("<%d %d %d %d>",f[i].first,f[i].second,len,ans);
		ret+=1ll*len*ans;
	}
	printf("%lld\n",ret);
	return 0;
}