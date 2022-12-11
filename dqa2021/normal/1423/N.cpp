#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#define pb push_back
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

int n,k;
struct Edge{
	int u,v,nxt;
}edge[1000010];
int cnt,last[12510];
inline void addedge(int x,int y){
	edge[++cnt]=(Edge){x,y,last[x]},last[x]=cnt;
}
int V[12510];
int E[1000010];
int w[12510];
int vrn[1000010],tim;
int main()
{
	n=read(),k=read();
	for (int i=1;i<=k;i++){
		int u=read(),v=read();
		w[u]++,w[v]++;
		if (u<v) swap(u,v);
		addedge(u,v);
	}
	for (int i=2;i<=n;i++){
		++tim;
		for (int j=last[i],v;j;j=edge[j].nxt){
			v=edge[j].v;
			if (!V[v]) V[v]=1,E[j]=0,w[i]--;
			else E[j]=1;
			vrn[w[v]]=tim;
		}
		if (vrn[w[i]]^tim) continue;
		for (int j=last[i],v;j;j=edge[j].nxt){
			v=edge[j].v;
			V[v]--,E[j]++,w[i]++;
			if (vrn[w[i]]^tim) break;
		}
	}
	int tot=0;
	for (int i=1;i<=n;i++) if (V[i]) tot++;
	printf("%d\n",tot);
	for (int i=1;i<=n;i++) if (V[i]) printf("%d ",i);
	if (tot) puts("");
	for (int i=1;i<=k;i++) printf("%d %d %d\n",edge[i].u,edge[i].v,E[i]);
	return 0;
}