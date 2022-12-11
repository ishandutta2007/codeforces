#include<cstdio>
#include<algorithm>
#include<cctype>
#include<iostream>
using namespace std;
typedef long long ll;
#define G getchar()
ll read()
{
	ll x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G
const int Mod=998244353,inv2=Mod+1>>1,MAXW=(1<<18)-1;
int upd(int x){return x+(x>>31&Mod);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%Mod)
		if (y&1) res=1LL*res*x%Mod;
	return res;
}

int n,m; ll w[200010],lb[60],Atot;
ll bin[60]; int bintop; int p[60],q[60],ans[60];
int ins(ll x){
	for (int i=m-1;i>=0;i--)
		if (x>>i&1){
			if (lb[i]){x^=lb[i]; continue;}
			lb[i]=x;
			for (int j=i-1;j>=0;j--) if (lb[i]>>j&1) lb[i]^=lb[j];
			for (int j=i+1;j<m;j++) if (lb[j]>>i&1) lb[j]^=lb[i];
			return 1;
		}
	return 0;
}
void dfs(int *p){
	for (int i=0;i<bintop;i++) bin[i]=bin[i+1];
	ll msk=0; p[0]++;
	for (int i=1;i<(1<<bintop);i++){
		msk^=bin[__builtin_ctz(i)];
		p[__builtin_popcountll(msk)]++;
	}
}
int dp[60][60]; int C[60][60];
int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) Atot+=ins(w[i]=read());
	if (Atot<=m-Atot){
		for (int i=0;i<m;i++) if (lb[i]) bin[++bintop]=lb[i];
		dfs(p);
		int t=qpow(2,n-Atot);
		for (int i=0;i<=m;i++) printf("%d%c",ans[i]=1LL*p[i]*t%Mod," \n"[i==m]);
		return 0;
	}
	for (int i=0;i<m;i++) if (!lb[i]){
		ll x=1LL<<i;
		for (int j=i+1;j<m;j++)
			if (lb[j]>>i&1)
				x|=1LL<<j;
		bin[++bintop]=x;
	}
	dfs(q);
	for (int i=0;i<=m;i++){
		C[i][0]=1;
		for (int j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
	}
	for (int i=0;i<=m;i++)
		for (int j=0;j<=m;j++){
			for (int k=0,t=1;k<=i&&k<=j;k++,t=Mod-t){
				dp[i][j]=(dp[i][j]+1LL*t*C[j][k]%Mod*C[m-j][i-k])%Mod;
			}
		}
	for (int c=0;c<=m;c++)
		for (int i=0;i<=m;i++)
			p[c]=(p[c]+1LL*q[i]*dp[c][i])%Mod;
	int t=qpow(inv2,m-Atot);
	for (int i=0;i<=m;i++) p[i]=1LL*p[i]*t%Mod;
	t=qpow(2,n-Atot);
	for (int i=0;i<=m;i++) printf("%d%c",ans[i]=1LL*p[i]*t%Mod," \n"[i==m]);
	return 0;
}