#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=3e5+50;
int n,cnt,f[N][18],d[N],fa[N],id[N],s[N];
vector<int>v1[N],v2[N];
void dfs1(int x,int ff){
	for(int i=0;i<17;i++)f[x][i+1]=f[f[x][i]][i];
	for(int i=0,y;i<v1[x].size();i++)if((y=v1[x][i])!=ff)
		f[y=v1[x][i]][0]=x,d[y]=d[x]+1,dfs1(y,x); 
}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x,int y){
	x=find(x);y=find(y);
	if(s[x]>s[y])swap(x,y);
	fa[x]=y;s[y]+=s[x];id[y]=d[id[y]]<d[id[x]]?id[y]:id[x];
}
void dfs2(int x,int ff){
	for(int i=0,y;i<v2[x].size();i++)
		if((y=v2[x][i])!=ff)dfs2(y,x);
	if(!ff)return;
	int fx=id[find(x)],p=ff;
	for(int i=17;~i;i--)
		if(d[id[find(f[p][i])]]>d[fx])p=f[p][i];
	if(id[find(f[p][0])]!=fx)p=fx;
	merge(p,f[p][0]);
	printf("%d %d %d %d\n",p,f[p][0],x,ff);
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)
		scanf("%d%d",&x,&y),
		v1[x].pb(y),v1[y].pb(x);
	for(int i=1,x,y;i<n;i++)
		scanf("%d%d",&x,&y),
		v2[x].pb(y),v2[y].pb(x);
	printf("%d\n",n-1);
	for(int i=1;i<=n;i++)id[i]=fa[i]=i,s[i]=1;
	dfs1(d[1]=1,0);dfs2(1,0);
	return 0;
}