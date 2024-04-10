#include<bits/stdc++.h>
using namespace std;
const int MAX_N=4e5;
struct Graph{
	struct Edge{ int to,nxt,c; }edge[MAX_N*2];
	int head[MAX_N],top;
	Graph(){memset(head,-1,sizeof(head)),top=-1;}
	inline void add(int x,int y,int c){
		edge[++top]=(Edge){y,head[x],c};
		head[x]=top;
	}
}G;
namespace FLOW{
	int iter[MAX_N],lev[MAX_N];
	bool bfs(int s,int t,int n){
		static int q[MAX_N],left,right;
		memcpy(iter,G.head,sizeof(int)*(n+1));
		memset(lev,0,sizeof(int)*(n+1));
		q[left=right=1]=s; lev[s]=1;
		while(left<=right){
			int x=q[left++];
			for(int j=G.head[x];~j;j=G.edge[j].nxt){
				int y=G.edge[j].to;
				if(G.edge[j].c>0&&lev[y]==0){
					lev[y]=lev[x]+1;
					q[++right]=y;
				}
			}
		}
		return lev[t]>0;
	}
	int dfs(int x,int mi,int o){
		if(x==o) return mi;
		for(int& j=iter[x];~j;j=G.edge[j].nxt){
			int y=G.edge[j].to;
			if(G.edge[j].c>0&&lev[y]>lev[x]){
				int d=dfs(y,min(mi,G.edge[j].c),o);
				if(d>0){
					G.edge[j].c-=d;
					G.edge[j^1].c+=d;
					return d;
				}
			}
		}
		return 0;
	}
	int solve(int s,int t,int n){
		int ret=0,d;
		while(bfs(s,t,n))
			while((d=dfs(s,1e9,t))!=0) ret+=d;
		return ret;
	}
}
void add2(int x,int y,int c){
	G.add(x,y,c); G.add(y,x,0);
}
map<pair<int,int>,int> mp;
int id[205][205],top_id1=0,top_id2=0;
bool vis[205][205];
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int main(){
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		string s; cin>>s;
		for(int j=1;j<=m;++j){
			if(s[j-1]=='#')
				id[i][j]=++top_id1;
		}
	}
	int s=++top_id2,t=++top_id2;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(id[i][j]>0){
				vector<int> p(4);
				for(int asp=0;asp<4;++asp){
					int x=i+dx[asp],y=j+dy[asp];
					if(x<1||x>n||y<1||y>m||id[x][y]==0) continue;
					if(mp[make_pair(id[i][j],id[x][y])]==0){
						mp[make_pair(id[i][j],id[x][y])]
							=mp[make_pair(id[x][y],id[i][j])]=++top_id2;
					}
					p[asp]=mp[make_pair(id[i][j],id[x][y])];
				}
				for(int d=0;d<2;++d)
					if(p[d]!=0){
						for(int e=2;e<4;++e)
							if(p[e]!=0)
								add2(p[d],p[e],1);
					}
				if(p[0]!=0) add2(s,p[0],1);
				if(p[2]!=0) add2(p[2],t,1);
			}
	int ans=FLOW::solve(s,t,top_id2);
//	printf("[%d]",ans);
	ans=top_id1-(top_id2-2-ans);
	printf("%d\n",ans);
	return 0;
}