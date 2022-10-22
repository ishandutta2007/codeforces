#include<bits/stdc++.h>
using namespace std;
int T,n;
vector<int>edg[65540];
int p[65540],q[65540],sz[65540],col[65540];
vector<int>ver[20];
bool vis[65540];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int N=(1<<n),M=(N>>1)*n;
		for(int i=0;i<=n;i++)ver[i].clear();
		for(int i=0;i<N;i++)edg[i].clear(),vis[i]=0;
		for(int i=0;i<M;i++){
			int u,v;scanf("%d%d",&u,&v);
			edg[u].push_back(v),edg[v].push_back(u);
		}
		ver[0].push_back(0),vis[0]=1,q[0]=0;
		for(int i=1;i<=n;i++){
			for(auto x:ver[i-1])for(auto y:edg[x])if(!vis[y])ver[i].push_back(y),vis[y]=1;
			if(i==1){
				int c=0;
				for(auto x:ver[i])q[x]=(1<<c),++c;
 			}else for(auto x:ver[i]){
				q[x]=0;
				for(auto y:edg[x])if(vis[y])q[x]|=q[y];
			}
		}
		for(int i=0;i<N;i++)p[q[i]]=i;
		for(int i=0;i<N;i++)printf("%d ",p[i]);puts("");
		if(n!=(n&-n))puts("-1");
		else{
			for(int i=0;i<N;i++){
				col[p[i]]=0;
				for(int j=0;j<n;j++)if((1<<j)&i)col[p[i]]^=j;
			}
			for(int i=0;i<N;i++)printf("%d ",col[i]);puts("");
		}
	}
}