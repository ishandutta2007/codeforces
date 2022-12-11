#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G

int n,m;
char mp[210][210];
int gethash(int x,int y){
	return (x-1)*m+y;
}
struct Edge{
	int to,nxt,val;
}edge[1<<20];
int cnt=1,last[1<<20],S,T,_last[1<<20];
inline void addedge(int x,int y,int v){
	edge[++cnt]=(Edge){y,last[x],v},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y],0},last[y]=cnt;
}
int que[1<<20],hd,tl;
int dep[1<<20];
bool bfs(){
	hd=tl=0; memset(dep+1,-1,T<<2);
	dep[S]=1; que[++tl]=S;
	while (hd<tl){
		int u=que[++hd],v;
		for (int i=last[u];i;i=edge[i].nxt)
			if (edge[i].val&&!~dep[v=edge[i].to]){
				dep[v]=dep[u]+1;
				if (v==T) return 1;
				que[++tl]=v;
			}
	}
	return 0;
}
int dfs(int x,int flw){
	if (x==T) return flw;
	int tmp,used=0;
	for (int &i=_last[x],v;i;i=edge[i].nxt)
		if (edge[i].val&&dep[v=edge[i].to]==dep[x]+1){
			tmp=dfs(v,min(edge[i].val,flw-used));
			edge[i].val-=tmp; edge[i^1].val+=tmp;
			used+=tmp; if (used==flw) return used;
		}
	if (!used) dep[x]=-1;
	return used;
}
int dinic(){
	int res=0;
	while (bfs()){
		memcpy(_last+1,last+1,T<<2);
		res+=dfs(S,1000000000);
	}
	return res;
}
int main()
{
	n=read(),m=read(); S=n*m+1,T=S+1;
	for (int i=1;i<=n;i++) scanf("%s",mp[i]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			if (mp[i][j]=='.') continue;
			if (i==1||mp[i-1][j]=='.') addedge(S,gethash(i,j),1);
			else addedge(gethash(i-1,j),gethash(i,j),1);
			if (j==1||mp[i][j-1]=='.') addedge(gethash(i,j),T,1);
			else addedge(gethash(i,j),gethash(i,j-1),1);
		}
	printf("%d\n",dinic());
	return 0;
}