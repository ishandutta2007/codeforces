#include<bits/stdc++.h>
#define MaxN 3123
typedef long long LL;
const LL Mod=998244353;
int n,m;
char S[MaxN],T[MaxN];
LL f[MaxN][MaxN];
inline void Init()
{
	scanf("%s%s",S+1,T+1);
	n=strlen(S+1);m=strlen(T+1);
	memset(f,-1,sizeof(f));
}
inline LL dp(int i,int j)
{
	if(~f[i][j])return f[i][j];
	LL&ans=f[i][j];
	if(i==j)return ans=((S[1]==T[i]||i>m)?2:0);
	ans=0;
	if(S[j-i+1]==T[i]||i>m)ans+=dp(i+1,j);
	if(S[j-i+1]==T[j]||j>m)ans+=dp(i,j-1);
	return ans%=Mod;
}
int main()
{
	Init();
	LL sum=0;
	for(int i=m;i<=n;++i)
	sum=(sum+dp(1,i))%Mod;
	printf("%lld\n",sum);
	return 0;
}