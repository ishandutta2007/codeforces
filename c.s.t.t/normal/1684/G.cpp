/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010],tot;
namespace MaxFlow{
	const int N=1010,M=2000000;
	int head[N],cur[N],dep[N],cnt,S,T;
	int res;
	struct node{int to,next;int val;}edge[M];
	void ae(int u,int v,int w){
		edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
		edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=0,head[v]=cnt++;
	}
	queue<int>q;
	inline bool bfs(){
		memset(dep,0,sizeof(dep)),q.push(S),dep[S]=1;
		while(!q.empty()){
			register int x=q.front();q.pop();
			for(register int i=cur[x]=head[x];i!=-1;i=edge[i].next)
				if(edge[i].val&&!dep[edge[i].to])dep[edge[i].to]=dep[x]+1,q.push(edge[i].to);
		}
		return dep[T]>0;
	}
	bool reach;
	inline int dfs(int x,int flow){
		if(x==T){res+=flow,reach=true;return flow;}
		int used=0;
		for(register int &i=cur[x];i!=-1;i=edge[i].next){
			if(!edge[i].val||dep[edge[i].to]!=dep[x]+1)continue;
			register int ff=dfs(edge[i].to,min(edge[i].val,flow-used));
			if(ff){edge[i].val-=ff,edge[i^1].val+=ff,used+=ff;if(used==flow)break;}
		}
		return used;
	}
	inline void Dinic(){
		while(bfs()){reach=true;while(reach)reach=false,dfs(S,0x3f3f3f3f);}
	}
}using namespace MaxFlow;
bool used[1010];
vector<pair<int,int> >v;
int main(){
	scanf("%d%d",&n,&m),S=n+1,T=n+2,memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=n;i;i--)if(3ll*a[i]>m){
		for(int j=1;j<=n;j++)if(2ll*a[i]+a[j]<=m&&!(a[i]%a[j]))ae(i,j,1);
		ae(S,i,1),tot++;
	}else ae(i,T,1);
	Dinic();
	if(res!=tot){puts("-1");return 0;}
	for(int i=n;i;i--)if(3ll*a[i]>m){
		for(int j=head[i];j!=-1;j=edge[j].next)if(!edge[j].val&&edge[j].to>=1&&edge[j].to<=n)
			{used[edge[j].to]=true,v.emplace_back(2*a[i]+a[edge[j].to],a[i]+a[edge[j].to]);break;}
	}
	for(int i=1;i<=n;i++)if(3ll*a[i]<=m&&!used[i])v.emplace_back(3*a[i],2*a[i]);
	printf("%d\n",v.size());
	for(auto x:v)printf("%d %d\n",x.first,x.second);
	return 0;
}