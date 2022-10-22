#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX_N=5+1e5,INF=2147483647;
struct Edge{
	int to; int nxt; int key;
}edge[MAX_N*2];
int top_edge=-1,head[MAX_N];
int dis[MAX_N],pre[MAX_N],n,k,max_len;
int stk[MAX_N],f[MAX_N];
bool mark[MAX_N];
void add_edge(int x,int y,int key){
	++top_edge;
	edge[top_edge].key=key;
	edge[top_edge].nxt=head[x];
	edge[top_edge].to=y;
	head[x]=top_edge;
}
int bfs(int x){
	for(int i=1;i<=n;++i) dis[i]=-1;
	dis[x]=0,pre[x]=0;
	int top_stk=1; stk[1]=x;
	while(top_stk>0){
		int x=stk[top_stk]; --top_stk;
		for(int j=head[x];j!=-1;j=edge[j].nxt){
			int y=edge[j].to;
			if(dis[y]==-1){
				dis[y]=dis[x]+edge[j].key;
				pre[y]=x,stk[++top_stk]=y;
			}
		}
	}
	int p=1;
	for(int i=2;i<=n;++i)
		if(dis[i]>dis[p]) p=i;
	return p;
}
vector<int> a;
void dfs(int x,int pre){
	f[x]=0;
	for(int j=head[x];j!=-1;j=edge[j].nxt){
		int y=edge[j].to;
		if(!mark[y]&&y!=pre){
			dfs(y,x);
			f[x]=max(f[x],f[y]+edge[j].key);
		}
	}
}
int judge(int standard){
	if(max_len<=standard) return 0;
	int l,r;
	for(int i=0;i<(int)a.size();++i)
		if(dis[a.front()]-dis[a[i]]>standard){
			l=i-1; break;
		}
	for(int i=a.size()-1;i>=0;--i){
		if(dis[a[i]]-dis[a.back()]>standard){
			r=i+1; break;
		}
	}
	if(l>=r) return 1;
	for(int i=l+1;i<=r-1;++i)
		if(f[a[i]]>standard) return INF;
	return r-l+1;  
}
void initialize(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i) head[i]=-1;
	for(int i=1;i<n;++i){
		int u,v,key; scanf("%d%d%d",&u,&v,&key);
		add_edge(u,v,key),add_edge(v,u,key);
	}
	int x=bfs(bfs(1));
	max_len=dis[x];
	a.clear(),memset(mark,0,sizeof(mark));
	while(x!=0) a.push_back(x),mark[x]=true,x=pre[x];
	for(int i=0;i<(int)a.size();++i) dfs(a[i],0);
}
int main(){
	initialize();
	int left=0,right=1e9;
	while(left<right){
		int mid=(left+right)>>1;
		if(judge(mid)<=k) right=mid;
		else left=mid+1;
	}
	printf("%d\n",right);
	return 0;
}