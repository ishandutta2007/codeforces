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
int t,n,m,u[2000005],v[2000005],first[500005],nxt[2000005],depth[500005],fa[500005],id;
int ansx[500005],ansy[500005],tot;
vector<int> c[500005];
void dfs(int now,int f,int d){
	fa[now]=f,depth[now]=d;
	c[depth[now]].push_back(now);
	if (depth[now]*2>=n)id=now;
	for (int i=first[now];i;i=nxt[i])
		if (depth[v[i]]==0)dfs(v[i],now,d+1);
	return;
}
int main(){
	cin>>t;
	while(t--){
		n=read(),m=read();
		for (int i=1;i<=m;i++){
			u[i]=read(),v[i]=read();
			nxt[i]=first[u[i]],first[u[i]]=i;
			u[i+m]=v[i],v[i+m]=u[i];
			nxt[i+m]=first[u[i+m]],first[u[i+m]]=i+m;
		}
		dfs(1,0,1);
		if (id!=0){
			puts("PATH");
			while(id)ansx[++tot]=id,id=fa[id];
			printf("%d\n",tot);
			for (int i=1;i<=tot;i++)printf("%d ",ansx[i]);puts("");
		}
		else{
			puts("PAIRING");
			for (int i=1;i<=n;i++)
				for (int j=0,len=c[i].size();j+1<len;j+=2){
					++tot;
					ansx[tot]=c[i][j],ansy[tot]=c[i][j+1];
				}
			printf("%d\n",tot);
			for (int i=1;i<=tot;i++)printf("%d %d\n",ansx[i],ansy[i]);
		}
		for (int i=1;i<=2*m;i++)u[i]=v[i]=nxt[i]=0;
		for (int i=1;i<=n;i++)first[i]=depth[i]=fa[i]=0,c[i].clear();
		id=tot=0;
	}
	return 0;
}