#include<bits/stdc++.h>
using namespace std;
const int N=1e6+4;
int n,q,rt,X[10];
vector<int>tr[N];
int *f[N],arr[N],*it=arr;
int len[N],son[N],p[N],ans[N];
void bfs(){
	memset(p,-1,sizeof(p));queue<int>que;
	for(int i=1;i<=n;i++)if(tr[i].size()==1)
		que.push(i),p[i]=0;
	while(!que.empty()){
		int u=que.front();que.pop();
		for(auto v:tr[u])if(p[v]<0)
			p[v]=p[u]+1,que.push(v);
	}
}
void init0(int x,int fa){
	for(auto y:tr[x])if(y!=fa){
		init0(y,x);
		if(len[y]+1>len[x])len[x]=len[y]+1,son[x]=y;
	}
}
void init1(int x,int fa){
	f[x]=it++;
	if(son[x])init1(son[x],x);
	for(auto y:tr[x])if(y!=fa&&y!=son[x])
		init1(y,x);
}
void dfs(int x,int fa){
	f[x][0]=p[x];
	if(son[x]){
		dfs(son[x],x);
		for(int t=0;t<q;t++){
			for(;;){
				int md=ans[t]+1;
				if(len[x]<md||f[x][md]+p[x]+X[t]<md)break;
				ans[t]=md;
			}
		}
		f[x][0]=max(f[x][0],f[x][1]);
	}
	for(auto y:tr[x])if(y!=fa&&y!=son[x]){
		dfs(y,x);
		for(int i=0;i<=len[y];i++){
			int p=i+1;
			for(int t=0;t<q;t++){
				for(;;){
					int md=ans[t]+1,q=max(md-p,0);
					if(len[x]<q||f[y][i]+f[x][q]+X[t]<md)break;
					ans[t]=md;
				}
			}
		}
		for(int i=0;i<=len[y];i++)
			f[x][i+1]=max(f[x][i+1],f[y][i]);
		f[x][0]=max(f[x][0],f[x][1]);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		int x;scanf("%d",&x);
		tr[x].push_back(i),tr[i].push_back(x);
	}
	bfs(),init0(1,0),init1(1,0);
	scanf("%d",&q);for(int i=0;i<q;i++)scanf("%d",&X[i]),ans[i]=1;
	dfs(1,0);for(int i=0;i<q;i++)printf("%d ",ans[i]);
}