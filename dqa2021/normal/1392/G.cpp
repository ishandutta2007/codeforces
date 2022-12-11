#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
const int INF=1e9;

int n,m,k;
int p[1000010][21];
char A[30],B[30],C[30];
int L[1000010],R[1000010];
int f[1<<20],g[1<<20];  //leftest superset of A; rightest of B
int getmsk(char *C){
	int res=0;
	for (int i=1;i<=k;i++) if (C[i]&1) res|=1<<i-1;
	return res;
}
inline void chkmin(int &x,int y){if (y<x) x=y;}
inline void chkmax(int &x,int y){if (y>x) x=y;}
int popcnt(int S){
	int res=0;
	for (int i=0;i<k;i++) res+=S>>i&1;
	return res;
}
int main()
{
	n=read(),m=read(),k=read();
	scanf("%s%s",A+1,B+1);
	for (int i=1;i<=n;i++) L[i]=read(),R[i]=read();
	for (int i=1;i<=k;i++) p[n+1][i]=i;
	for (int i=0;i<(1<<k);i++) f[i]=INF,g[i]=-INF;
	for (int i=n;i;i--){
		for (int j=1;j<=k;j++)
			if (L[i]==j) p[i][j]=p[i+1][R[i]];
			else if (R[i]==j) p[i][j]=p[i+1][L[i]];
			else p[i][j]=p[i+1][j];
		for (int j=1;j<=k;j++) C[p[i][j]]=A[j];
		chkmin(f[getmsk(C)],i);
		for (int j=1;j<=k;j++) C[p[i+1][j]]=B[j];
		chkmax(g[getmsk(C)],i);
	}
	for (int j=0;j<k;j++)
		for (int i=0;i<(1<<k);i++)
			if (i>>j&1){
				chkmin(f[i^(1<<j)],f[i]);
				chkmax(g[i^(1<<j)],g[i]);
			}
	int ans=-INF,l,r;
	for (int i=0;i<(1<<k);i++) if (g[i]-f[i]+1>=m){
		int t=popcnt(i)*2+k;
		if (t>ans) ans=t,l=f[i],r=g[i];
	}
	for (int i=1;i<=k;i++) if (A[i]&1) ans--;
	for (int i=1;i<=k;i++) if (B[i]&1) ans--;
	printf("%d\n%d %d\n",ans,l,r);
	return 0;
}