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
const int mod=998244353;

int n,w[1510][1510];
struct Rec{
	int u,v;
}rec[1510*1510]; int m;
int fat[1510],tot[1510],siz[1510];
int find(int x){return fat[x]?fat[x]=find(fat[x]):x;}
int dp[1510][1510];
void merge(int x,int y){
	fat[y]=x; tot[x]+=tot[y];
	static int c[1510];
	int u=siz[x],v=siz[y];
	for (int i=1;i<=u+v;i++) c[i]=0;
	for (int i=1;i<=u;i++)
		for (int j=1;j<=v;j++)
			c[i+j]=(c[i+j]+1LL*dp[x][i]*dp[y][j])%mod;
	siz[x]+=siz[y];
	for (int i=1;i<=u+v;i++) dp[x][i]=c[i];
}
int main()
{
	n=read(); m=n*(n-1)/2;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			w[i][j]=read();
			if (i<j) rec[w[i][j]]=(Rec){i,j};
		}
	for (int i=1;i<=n;i++) dp[i][1]=1,siz[i]=1;
	for (int i=1;i<=m;i++){
		int u=rec[i].u,v=rec[i].v;
		int x=find(u),y=find(v);
		if (x!=y) merge(x,y);
		tot[x]++;
		if (tot[x]==siz[x]*(siz[x]-1)/2) dp[x][1]=1;
	}
	for (int i=1;i<=n;i++) printf("%d ",dp[find(1)][i]);
	puts("");
	return 0;
}