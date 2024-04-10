#include<cstdio>
#include<algorithm>
#include<cctype>
#include<set>
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
struct Edge{
	int to,nxt;
}edge[200010];
int cnt,last[200010];
inline void addedge(int x,int y){
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
}
int seq[200010],seqtot;

int que[200010],hd,tl; int dep[200010]; bool vis[200010];

typedef pair<int,int> P;
set<int> st[200010];
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++) addedge(read(),read());
	seqtot=read(); for (int i=1;i<=seqtot;i++) seq[i]=read();
	
	que[++tl]=seq[seqtot],dep[seq[seqtot]]=0,vis[seq[seqtot]]=1;
	while (hd<tl){
		int u=que[++hd],v;
		for (int i=last[u];i;i=edge[i].nxt)
			if (!vis[v=edge[i].to]){
				vis[v]=1; dep[v]=dep[u]+1; que[++tl]=v;
			}
	}
	for (int i=1,v;i<=n;i++)
		for (int j=last[i];j;j=edge[j].nxt)
			if (v=edge[j].to,dep[i]+1==dep[v])
				st[v].insert(i);
	int minn=0,maxn=0;
	for (int i=1;i<seqtot;i++){
		int u=seq[i],v=seq[i+1];
		if (!st[u].count(v)){minn++,maxn++;continue;}
		if (st[u].size()>1){maxn++;}
	}
	printf("%d %d\n",minn,maxn);
	return 0;
}