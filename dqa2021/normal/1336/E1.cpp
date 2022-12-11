#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
using namespace std;
typedef long long ll;
#define G getchar()
ll read()
{
	ll x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
const int Mod=998244353;

int n,m; int ans[40];
ll lb[40];
int ins(ll x){
	for (int i=m-1;i>=0;i--)
		if (x>>i&1){
			if (lb[i]){x^=lb[i]; continue;}
			lb[i]=x;
			for (int j=i-1;j>=0;j--)
				if (lb[i]>>j&1) lb[i]^=lb[j];
			for (int j=i+1;j<m;j++)
				if (lb[j]>>i&1) lb[j]^=lb[i];
			return 1;
		}
	return 2;
}
int popcount(ll x){
	int res=0;
	for (int i=0;i<m;i++) res+=x>>i&1;
	return res;
}
void add(int &x,ll y){x=(x+y)%Mod;}
int A[40],Atot,B[40],Btot;
int dp[2][40][1<<17]; bool dpcur;
int main()
{
	n=read(),m=read();
	int k=1;
	for (int i=1;i<=n;i++) k=k*ins(read())%Mod;
	for (int i=0;i<m;i++) if (lb[i]) A[++Atot]=i; else B[++Btot]=i;
//	printf("Atot %d Btot %d\n",Atot,Btot);
//	printf("k %d\n",k);
	if (Atot<=17){
		for (int i=0;i<(1<<Atot);i++){
			ll x=0;
			for (int j=1;j<=Atot;j++)
				if (i>>j-1&1)
					x^=lb[A[j]];
			add(ans[popcount(x)],k);
		}
		for (int i=0;i<=m;i++) printf("%d ",(ans[i]+Mod)%Mod); puts("");
		return 0;
	}
	dp[dpcur][0][0]=1;
	for (int i=1;i<=Atot;i++){
		int msk=0;
		for (int j=1;j<=Btot;j++)
			if (lb[A[i]]>>B[j]&1) msk|=(1<<j-1);
		dpcur^=1; memset(dp[dpcur],0,sizeof dp[dpcur]);
		for (int j=0;j<i;j++)
			for (int u=0;u<(1<<Btot);u++)
				add(dp[dpcur][j][u],dp[dpcur^1][j][u]),
				add(dp[dpcur][j+1][u^msk],dp[dpcur^1][j][u]);
	}
	for (int i=0;i<=Atot;i++)
		for (int j=0;j<(1<<Btot);j++)
			add(ans[i+popcount(j)],1LL*dp[dpcur][i][j]*k);
	for (int i=0;i<=m;i++) printf("%d ",(ans[i]+Mod)%Mod); puts("");
	return 0;
}