#include<cstdio>
#include<algorithm>
#include<cctype>
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

int n,q;
struct Edge{
	int to,nxt,val;
}edge[200010];
int cnt=1,last[100010];
inline void addedge(int x,int y,int v){
	edge[++cnt]=(Edge){y,last[x],v},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y],v},last[y]=cnt;
}
int dis[100010];
void dfs0(int x,int f,int d){
	dis[x]=d;
	for (int i=last[x],v;i;i=edge[i].nxt)
		if ((v=edge[i].to)^f)
			dfs0(v,x,d+edge[i].val);
}
int S,T;
struct Rec{
	int gnd[100010][17];
	int dis[100010],top[100010],son[100010],maxd[100010];
	int mrk[100010],pre[100010];
	void dfs1(int x,int f,int d){
		dis[x]=d; gnd[x][0]=f;
		for (int i=1;i<17&&gnd[x][i-1];i++) gnd[x][i]=gnd[gnd[x][i-1]][i-1];
		maxd[x]=d;
		for (int i=last[x],v;i;i=edge[i].nxt)
			if ((v=edge[i].to)^f){
				dfs1(v,x,d+edge[i].val);
				if (maxd[v]>maxd[x]) maxd[x]=maxd[v],son[x]=v;
			}
	}
	void dfs2(int x,int f,int t){
		top[x]=t;
		if (!son[x]) return;
		dfs2(son[x],x,t);
		for (int i=last[x],v;i;i=edge[i].nxt)
			if (((v=edge[i].to)^f)&&(v^son[x]))
				dfs2(v,x,v);
	}
	int solve(int x,int k){
		if (mrk[top[x]]<=k) return pre[k];
		int y=x;
		for (int i=16;i>=0;i--) if (gnd[y][i]&&mrk[top[gnd[y][i]]]>k) y=gnd[y][i];
		y=gnd[y][0];
		return max(pre[k-1],pre[k]-maxd[y]+dis[y])+maxd[x]-dis[y];
	}
}A,B;
bool cmp1(int x,int y){
	return A.maxd[x]-A.dis[A.gnd[x][0]]>A.maxd[y]-A.dis[A.gnd[y][0]];
}
bool cmp2(int x,int y){
	return B.maxd[x]-B.dis[B.gnd[x][0]]>B.maxd[y]-B.dis[B.gnd[y][0]];
}
int main()
{
	n=read(); q=read();
	if (n==1){
		while (q--) puts("0");
		return 0;
	}
	for (int i=1,x,y,v;i<n;i++)
		x=read(),y=read(),v=read(),
		addedge(x,y,v);
	dfs0(1,0,0);
	for (int i=1;i<=n;i++) if (!S||dis[i]>dis[S]) S=i;
	dfs0(S,0,0);
	for (int i=1;i<=n;i++) if (!T||dis[i]>dis[T]) T=i;
	A.dfs1(S,0,0); A.dfs2(S,0,S);
	B.dfs1(T,0,0); B.dfs2(T,0,T);
	static int seq[100010],top;
	for (int i=1;i<=n;i++) if (A.top[i]==i) seq[++top]=i;
	sort(seq+1,seq+top+1,cmp1);
	for (int i=1;i<=top;i++){
		int x=seq[i];
		A.mrk[x]=i;
		A.pre[i]=A.pre[i-1]+A.maxd[x]-A.dis[A.gnd[x][0]];
	}
	int Atop=top;
	top=0;
	for (int i=1;i<=n;i++) if (B.top[i]==i) seq[++top]=i;
	sort(seq+1,seq+top+1,cmp2);
	for (int i=1;i<=top;i++){
		int x=seq[i];
		B.mrk[x]=i;
		B.pre[i]=B.pre[i-1]+B.maxd[x]-B.dis[B.gnd[x][0]];
	}
	int Btop=top;
	
	int lastans=0;
	while (q--){
		int x=(read()+lastans-1)%n+1,y=(read()+lastans-1)%n+1;
//		int x=read(),y=read();
		y=y*2-1;
		printf("%d\n",lastans=max(A.solve(x,min(y,Atop)),B.solve(x,min(y,Btop))));
	}
	return 0;
}