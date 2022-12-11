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
typedef long long ll;

int n;
struct Edge{
	int to,nxt,val;
}edge[200010];
int cnt=1,last[100010];
inline void addedge(int x,int y,int v){
	edge[++cnt]=(Edge){y,last[x],v},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y],v},last[y]=cnt;
}
ll dis[100010]; int fat[100010];
void dfs0(int x,int f,ll d){
	fat[x]=f; dis[x]=d;
	for (int i=last[x],v;i;i=edge[i].nxt)
		if ((v=edge[i].to)^f)
			dfs0(v,x,d+edge[i].val);
}
ll disS[100010],disT[100010];
void dfs1(int x,int f,ll d,ll *dis){
	fat[x]=f; dis[x]=d;
	for (int i=last[x],v;i;i=edge[i].nxt)
		if ((v=edge[i].to)^f)
			dfs1(v,x,d+edge[i].val,dis);
}
ll f[100010]; int seq[100010];
bool cmp(int x,int y){return f[x]>f[y];}
int p[100010],m;
int S=1,T=1,P,Q;
int g[100010],siz[100010];
int mrk[100010],tim;
int find(int x){return g[x]?g[x]=find(g[x]):x;}
void ins(int x,int &res){
	mrk[x]=tim; siz[x]=1;
	for (int i=last[x],v;i;i=edge[i].nxt)
		if ((v=edge[i].to)^fat[x]){
			if (mrk[v]==tim){
				g[v]=x; siz[x]+=siz[v];
			}
		}
	if (mrk[P]==tim&&mrk[Q]==tim) res=max(res,siz[P]+siz[Q]);
	res=max(res,siz[x]);
}
void del(int x,int &res){
	mrk[x]=tim-1; siz[find(x)]--;
}
int solve(ll d){  //init
	int res=0; ++tim;
	for (int i=1;i<=n;i++) g[i]=0,siz[i]=0;
	for (int i=1,j=0;i<=n;i++){
		while (j<i&&f[seq[j+1]]-f[seq[i]]>d) del(seq[++j],res);
		ins(seq[i],res);
	}
	return res;
}
int main()
{
	n=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read(),v=read();
		addedge(x,y,v);
	}
	dfs0(1,0,0);
	for (int i=2;i<=n;i++) if (dis[i]>dis[S]) S=i;
	dfs0(S,0,0);
	for (int i=2;i<=n;i++) if (dis[i]>dis[T]) T=i;
	for (int i=T;i;i=fat[i]) p[++m]=i; reverse(p+1,p+m+1);
	dfs1(S,0,0,disS); dfs1(T,0,0,disT);
	int pos=1;
	while (pos<m&&disS[p[pos+1]]<disT[p[pos+1]]) pos++;
	P=p[pos],Q=p[pos+1];
	dfs0(P,Q,0); dfs0(Q,P,0);
	for (int i=1;i<=n;i++) f[i]=max(disS[i],disT[i]),seq[i]=i;
	sort(seq+1,seq+n+1,cmp);
	int q=read();
	while (q--){
		ll x; scanf("%lld",&x);
		printf("%d\n",solve(x));
	}
	return 0;
}