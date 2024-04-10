#include<bits/stdc++.h>
using namespace std;
const int N=5+1e5;
struct Graph{
	struct Edge{ int to,nxt,c; }edge[N*10];
	int head[N],top;
	void init(int n){memset(head,-1,sizeof(int)*(n+1)),top=-1;}
	Graph(){memset(head,-1,sizeof(head)),top=-1;}
	inline void add(int x,int y,int k){
		edge[++top]=(Edge){y,head[x],k};
		head[x]=top;
	}
}G;
inline void add2(int x,int y,int k){
//	printf("<%d %d %d>",x,y,k);
	G.add(x,y,k); G.add(y,x,0);
}
namespace FLOW{
	int iter[N],lev[N],q[N],left,right;
	bool bfs(int s,int t,int n){
		for(int i=0;i<=n;++i) lev[i]=0,iter[i]=G.head[i];
		left=right=0; q[right++]=s; lev[s]=1;
		while(left!=right){
			int x=q[left++]; 
			for(int j=G.head[x];~j;j=G.edge[j].nxt){
				int y=G.edge[j].to;
				if(G.edge[j].c>0&&lev[y]==0){
					lev[y]=lev[x]+1;
					q[right++]=y;
				}
			}
		}
		return lev[t]>0;
	}
	int dfs(int x,int o,int mi){
		if(x==o) return mi;
		for(int& j=iter[x];~j;j=G.edge[j].nxt){
			int y=G.edge[j].to;
			if(G.edge[j].c>0&&lev[y]==lev[x]+1){
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
	int max_flow(int s,int t,int n){
		int ret=0,d;
		while(bfs(s,t,n))
			while((d=dfs(s,t,(int)1e9))!=0) ret+=d;
		return ret;
	}
}
const int dx[]={0,0,1,-1},dy[]={-1,1,0,0};
const char ch[]={'L','R','D','U'};
vector<vector<int> > id,a,ans1;
vector<vector<char> > ans2;
int n,m,top_node,s,t,spp;
int check(int x,int y){
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int z=G.edge[j].to;
		if(z==y)
			return G.edge[j^1].c;
	}
	return 0;
}
int check2(int x,int y){
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int z=G.edge[j].to;
		if(z==y) return G.edge[j].c;
	}
	return 0;
}
bool check_type(int x,int y){ return (x&1)^(y&1); }
void get_ans(int x,int y){
	if(check_type(x,y)&&check(id[x][y],spp)||!check_type(x,y)&&check2(id[x][y],spp)){
		for(int asp=0;asp<4;++asp){
			int x1=x+dx[asp],y1=y+dy[asp];
			if(x1<0||x1>=n||y1<0||y1>=m) continue;
			if(a[x1][y1]<a[x][y]){
				ans1[x][y]=a[x][y]-a[x1][y1];
				ans2[x][y]=ch[asp];
				return;
			}
		}
		assert(0);
	}else if((x&1)^(y&1)){
		for(int asp=0;asp<4;++asp){
			int x1=x+dx[asp],y1=y+dy[asp];
			if(x1<0||x1>=n||y1<0||y1>=m) continue;
			if(check(id[x][y],id[x1][y1])){
				ans1[x][y]=1;
				ans1[x1][y1]=a[x][y]-1;
				ans2[x][y]=ch[asp];
				ans2[x1][y1]=ch[asp^1];
			}
		}
	}
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m); top_node=0;
		a.resize(n); id.resize(n); ans1.resize(n); ans2.resize(n);
		G.init(n*m+5);
		s=++top_node; t=++top_node; spp=++top_node;
		for(int i=0;i<n;++i){
			a[i].resize(m);
			id[i].resize(m);
			ans1[i].resize(m);
			ans2[i].resize(m);
			for(int j=0;j<m;++j){
				scanf("%d",&a[i][j]);
				id[i][j]=++top_node;
				if((i&1)^(j&1)) add2(s,id[i][j],1);
				else add2(id[i][j],t,1);
			}
		}
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j){
				if((i&1)^(j&1)){
					for(int asp=0;asp<4;++asp){
						int x=i+dx[asp],y=j+dy[asp];
						if(x<0||x>=n||y<0||y>=m) continue;
						if(a[i][j]==a[x][y]){
							add2(id[i][j],id[x][y],1);
						}else if(a[i][j]>a[x][y]){
							add2(id[i][j],spp,1);
						}else add2(spp,id[x][y],1);
					}
				}
			}
		int top=n*m;
		if(top&1){
			int x=++top_node; ++top;
			add2(s,x,1);
			add2(x,spp,1);
		}
		int key=FLOW::max_flow(s,t,top_node);
//		printf("<%d %d>\n",key,top);
		if(key!=top/2) puts("NO");
		else{
			puts("YES");
			for(int i=0;i<n;++i)
				for(int j=0;j<m;++j)
					get_ans(i,j);
			for(int i=0;i<n;++i){
				for(int j=0;j<m;++j)
					printf("%d ",ans1[i][j]);			
				puts("");
			}
			for(int i=0;i<n;++i){
				for(int j=0;j<m;++j)
					printf("%c ",ans2[i][j]);
				puts("");
			}
		}
	}
	return 0;
}