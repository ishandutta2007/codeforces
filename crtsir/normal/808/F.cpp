#include<bits/stdc++.h>
using namespace std;
int n,k,p[103],c[103],l[103],cnt[2],S=200,T=201,P=202,val[2][103];
bool isprime(int x){
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)return 0;
	return 1;
}
const int MAXN=205,MAXM=100000,INF=998244353;
struct maxflow{
	int len,maxFlow,tot;
	int head[MAXN],cur[MAXN],dep[MAXN],vis[MAXN];
	queue<int>q;
	struct Edge{
		int to,next,flow;
	}e[MAXM];
	void Init(){
		memset(head,-1,sizeof(head));
		len=1;
	}
	void add_edge(int u,int v,int flow){
		e[++len]=(Edge){v,head[u],flow};
		head[u]=len;
		e[++len]=(Edge){u,head[v],0};
		head[v]=len;
	}
	int bfs(){
		for(int i=0;i<MAXN;i++){
			cur[i]=head[i];
			dep[i]=-1;
		}
		dep[S]=0;
		q.push(S);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=head[u];i!=-1;i=e[i].next){
				int v=e[i].to;
				if(dep[v]==-1&&e[i].flow){
					dep[v]=dep[u]+1;
					q.push(v);
				}
			}
		}
		return dep[T]!=-1;
	}
	int dfs(int u,int flow){
		if(u==T){
			maxFlow+=flow;
			return flow;
		}
		int used=0,low;
		for(int i=cur[u];i!=-1;i=e[i].next){
			cur[u]=i;
			int v=e[i].to;
			if(dep[v]==dep[u]+1&&e[i].flow)
				if(low=dfs(v,min(flow - used,e[i].flow))){
					e[i].flow-=low;
					e[i^1].flow+=low;
					used+=low;
					if(used==flow)
						break;
				}
		}
		return used;
	}
	int Dinic(){maxFlow=0;
		while(bfs())dfs(S,INF);
		return maxFlow;
	}
}gr;
vector<int>v[103];
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		scanf("%d%d%d",p+i,c+i,l+i);
		v[l[i]].push_back(i);
	}gr.Init();
	int lst=0,ans=0;
	for(int i=0;i<103;i++){
		if(v[i].size()){
			for(int j=0;j<v[i].size();j++){
				ans+=p[v[i][j]];
				if(c[v[i][j]]==1){
					ans-=p[v[i][j]];ans-=lst;
					gr.add_edge(S,P,max(0,p[v[i][j]]-lst));
					lst=max(lst,p[v[i][j]]);
					ans+=lst; 
				}else
					if(c[v[i][j]]&1){
						val[1][cnt[1]]=c[v[i][j]];
						gr.add_edge(S,100+cnt[1],p[v[i][j]]); 
						for(int j=0;j<cnt[0];j++)
							if(isprime(val[0][j]+val[1][cnt[1]]))
								gr.add_edge(100+cnt[1],j,998244353);
						cnt[1]++;
					}else{
						if(isprime(c[v[i][j]]+1))
							gr.add_edge(P,cnt[0],998244353);
						gr.add_edge(cnt[0],T,p[v[i][j]]);
						val[0][cnt[0]]=c[v[i][j]];
						for(int j=0;j<cnt[1];j++)
							if(isprime(val[1][j]+val[0][cnt[0]]))
								gr.add_edge(100+j,cnt[0],998244353);
						cnt[0]++;
					}
			}
			ans-=gr.Dinic();
			if(ans>=k){
				cout<<i;
				return 0;
			}
		}
	}
	cout<<-1;
}