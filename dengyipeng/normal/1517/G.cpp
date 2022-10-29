#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#define maxn 2050
#define maxm 1000005
#define inf 1e15
#define ll long long
using namespace std;

int n,i,j,k,a[maxn][2],w[maxn],S,T;
map<pair<int,int>,int> m;

int em,e[maxm],nx[maxm],ls[maxn];
ll ec[maxm],ans;
void insert(int x,int y,ll z){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em; ec[em]=z;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em; ec[em]=0;
}

int d[maxn],dis[maxn],cur[maxn];
int bfs(){
	memset(dis,0,sizeof(int)*(T+1));
	int t=0,w=1; d[1]=S,dis[S]=1;
	while (t<w){
		int x=d[++t]; cur[x]=ls[x];
		for(int i=ls[x];i;i=nx[i]) if (ec[i]&&!dis[e[i]])
			dis[e[i]]=dis[x]+1,d[++w]=e[i];
	}
	return dis[T];
}
ll dfs(int x,ll p){
	if (x==T) return p;
	ll res=p;
	for(int &i=cur[x];i;i=nx[i]) if (ec[i]&&dis[x]+1==dis[e[i]]){
		ll tmp=dfs(e[i],min(res,ec[i]));
		res-=tmp,ec[i]-=tmp,ec[i^1]+=tmp;
		if (!res) break;
	}
	return p-res;
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d%d%d",&a[i][0],&a[i][1],&w[i]);
		m[make_pair(a[i][0],a[i][1])]=i;
	}
	S=n*2+1,T=S+1,em=1;
	for(i=1;i<=n;i++) insert(i,i+n,w[i]),ans+=w[i];
	for(i=1;i<=n;i++){
		int x=a[i][0],y=a[i][1];
		if ((x+y)%2){
			if (x%2) insert(S,i,inf);
			if (m.find(make_pair(x+1,y))!=m.end())
				insert(i+n,m[make_pair(x+1,y)],inf);
			if (m.find(make_pair(x-1,y))!=m.end())
				insert(i+n,m[make_pair(x-1,y)],inf);
		} else 
		if (y%2==0){
			if (m.find(make_pair(x,y+1))!=m.end())
				insert(i+n,m[make_pair(x,y+1)],inf);
			if (m.find(make_pair(x,y-1))!=m.end())
				insert(i+n,m[make_pair(x,y-1)],inf);
		} else insert(i+n,T,inf);
	}
	while (bfs()) ans-=dfs(S,inf);
	printf("%lld\n",ans);
}