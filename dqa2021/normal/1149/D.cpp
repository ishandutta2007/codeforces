#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#include<queue>
#include<assert.h>
#define pb push_back
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
const int INF=1e9;

int n,m,A,B;
struct R{
	int u,v,c;
}r[210];

int fat[80],siz[80];
int find(int x){return fat[x]?fat[x]=find(fat[x]):x;}

int f[20][80][80],g[80][80],h[80][80];
int id[80],idtot;
int dp[80][1<<17];  //40mb
bool vis[80][1<<17];

inline void checkmin(int &x,int y,bool &z){
	if (!z) z=1,x=INF;
	if (y<x) x=y;
}
inline void checkmin(int &x,int y){if (y<x) x=y;}

int ans[80];

int main()
{
	n=read(),m=read(),A=read(),B=read();
	for (int i=1;i<=n;i++) siz[i]=1;
	for (int i=1;i<=m;i++) r[i].u=read(),r[i].v=read(),r[i].c=read();
	for (int i=1;i<=m;i++) if (r[i].c==A){
		int x=find(r[i].u),y=find(r[i].v);
		if (x^y) fat[y]=x,siz[x]+=siz[y];
	}
	for (int i=1;i<=n;i++) if (find(i)==i&&siz[i]>=4) id[i]=++idtot;
	for (int i=1;i<=n;i++) id[i]=id[find(i)];
	assert(idtot<=17);
	for (int k=0;k<=idtot;k++)
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				f[k][i][j]=f[k][j][i]=INF;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			/*f[i][j]=f[j][i]=*/g[i][j]=g[j][i]=h[i][j]=h[j][i]=INF;
	for (int i=1;i<=m;i++){
		int u=r[i].u,v=r[i].v,c=r[i].c;
		int x=find(u),y=find(v);
		if (x==y&&c==B) continue;
		if (x==y&&siz[x]>=4){
			g[u][v]=min(g[u][v],c);
			g[v][u]=min(g[v][u],c);
		}
		else{
			if (c==A){
				for (int k=0;k<=idtot;k++){
					f[k][u][v]=min(f[k][u][v],c);
					f[k][v][u]=min(f[k][v][u],c);
				}
			}
			else{
				for (int k=0;k<=idtot;k++){
					if (!k&&!id[u]||k&&(id[u]==k||id[u]==0)&&id[v]!=k){
						f[k][u][v]=min(f[k][u][v],c);
					}
					if (!k&&!id[v]||k&&(id[v]==k||id[v]==0)&&id[u]!=k){
						f[k][v][u]=min(f[k][v][u],c);
					}
				}
			}
		}
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	for (int e=0;e<=idtot;e++){
		for (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					f[e][i][j]=min(f[e][i][j],f[e][i][k]+f[e][k][j]);
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			h[i][j]=INF;
			for (int k=1;k<=n;k++){
				h[i][j]=min(h[i][j],f[id[i]][i][k]+g[k][j]);
			}
		}
	
	if (id[1]){
		int msk=1<<id[1]-1;
		for (int i=1;i<=n;i++)
			if (id[i]==id[1])
				vis[i][msk]=1,dp[i][msk]=g[1][i];
	}
	else{
		for (int i=1;i<=n;i++){
			if (!id[i]) continue;
			if (h[1][i]==INF) continue;
			int msk=1<<id[i]-1;
			vis[i][msk]=1,dp[i][msk]=h[1][i];
		}
	}
	
	for (int msk=1,U=1<<idtot;msk<U;msk++)
		for (int i=1;i<=n;i++)
			if (vis[i][msk]&&dp[i][msk]^INF){
				for (int j=1;j<=n;j++)
					if (id[j]){
						int nxt=msk|(1<<id[j]-1);
						if (msk==nxt) continue;
						checkmin(dp[j][nxt],dp[i][msk]+h[i][j],vis[j][nxt]);
					}
			}
	
	if (id[1]){
		for (int i=1;i<=n;i++) ans[i]=INF;
		for (int msk=1,U=1<<idtot;msk<U;msk++)
			for (int i=1;i<=n;i++)
				if (vis[i][msk]){
					checkmin(ans[i],dp[i][msk]);
					for (int j=1;j<=n;j++) if (!id[j])
						checkmin(ans[j],dp[i][msk]+f[id[i]][i][j]);
				}
	}
	else{
		for (int i=1;i<=n;i++) ans[i]=INF;
		for (int msk=1,U=1<<idtot;msk<U;msk++)
			for (int i=1;i<=n;i++)
				if (vis[i][msk]){
					checkmin(ans[i],dp[i][msk]);
					for (int j=1;j<=n;j++) if (!id[j])
						checkmin(ans[j],dp[i][msk]+f[id[i]][i][j]);
				}
		for (int i=1;i<=n;i++) if (!id[i]) checkmin(ans[i],h[1][i]);
	}
	
	for (int i=1;i<=n;i++){
		assert(ans[i]^INF);
		printf("%d%c",ans[i]," \n"[i==n]);
	}
	
	return 0;
}