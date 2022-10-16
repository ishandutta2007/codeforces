#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,m,k,u[1000005],v[1000005],first[1000005],nxt[1000005];
int fa[1000005],depth[1000005];
int d[1000005],tot;
vector<int> e[500005];
void dfs(int now,int f,int dep){
	fa[now]=f,depth[now]=dep;
	int cnt=0;
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==f)continue;
		if (depth[v[i]]!=0)e[now].push_back(v[i]);
		else cnt++,dfs(v[i],now,dep+1);
	}
	if (cnt==0)d[++tot]=now;
	return;
}
void out(int now){
	int x=e[now][0],y=e[now][1];
	if ((depth[now]-depth[x])%3!=2){
		printf("%d\n",depth[now]-depth[x]+1);
		printf("%d ",now);
		while(now!=x)now=fa[now],printf("%d ",now);
		puts("");
	}
	else if ((depth[now]-depth[y])%3!=2){
		printf("%d\n",depth[now]-depth[y]+1);
		printf("%d ",now);
		while(now!=y)now=fa[now],printf("%d ",now);
		puts("");
	}
	else{
		if (depth[x]<depth[y])swap(x,y);
		printf("%d\n",1+(depth[x]-depth[y]+1));
		printf("%d ",now);
		while(x!=y)printf("%d ",x),x=fa[x];
		printf("%d\n",y);
	}
	return;
}
int main(){
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		u[i]=read(),v[i]=read();
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+m]=v[i],v[i+m]=u[i];
		nxt[i+m]=first[u[i+m]],first[u[i+m]]=i+m;
	}
	dfs(1,0,1);
	int id=-1,mx=0;
	for (int i=1;i<=n;i++)
		if (depth[i]>mx)id=i,mx=depth[i];
	if (1ll*mx*k>=n){
		puts("PATH");
		cout<<mx<<endl;
		while(id!=1)printf("%d ",id),id=fa[id];
		puts("1");
	}
	else{
		puts("CYCLES");
		for (int i=1;i<=k;i++)out(d[i]);
	}
	return 0;
}