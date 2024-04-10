#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
typedef long long ll;
const int Mod=1e9+7,MAXW=2e5;
int qpow(int x,int y)
{
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%Mod)
		if (y&1) res=1LL*res*x%Mod;
	return res;
}
int fac[200010],ifac[200010];
int C(int n,int m)
{
	return n<m?0:1LL*fac[n]*ifac[n-m]%Mod*ifac[m]%Mod;
}

int n,m,q;
struct Node{
	int x,y;
}node[2010];
bool operator<(const Node x,const Node y)
{
	if (x.x^y.x) return x.x<y.x;
	return x.y<y.y;
}
int dp[2010];
int main()
{
	n=read(),m=read(),q=read();
	
	fac[0]=1; for (int i=1;i<=n+m;i++) fac[i]=1LL*fac[i-1]*i%Mod;
	ifac[n+m]=qpow(fac[n+m],Mod-2); for (int i=n+m;i;i--) ifac[i-1]=1LL*ifac[i]*i%Mod;
	
	for (int i=1;i<=q;i++) node[i].x=read(),node[i].y=read();
	node[q+1]=(Node){1,1},node[q+2]=(Node){n,m}; q+=2;
	sort(node+1,node+q+1);
	dp[1]=-1;
	for (int i=2;i<=q;i++)
	{
		for (int j=1;j<i;j++)
			if (node[j].x<=node[i].x&&node[j].y<=node[i].y)
				dp[i]=(dp[i]-1LL*dp[j]*C(node[i].x-node[j].x+node[i].y-node[j].y,node[i].x-node[j].x))%Mod;
		//printf("dp %d = %d\n",i,dp[i]);
	}
	int ans=dp[q];
	printf("%d\n",(ans+Mod)%Mod);
	return 0;
}