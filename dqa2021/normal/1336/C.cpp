#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int Mod=998244353;

char S[3010],T[3010]; int n,m;
int dp[3010][3010]; bool vis[3010][3010];
int dfs(int l,int r){
	if (vis[l][r]) return dp[l][r]; vis[l][r]=1;
	if (l==1&&r>=m) dp[l][r]=1;
	int len=r-l+1;
	if (r<n&&(r+1>m||T[r+1]==S[len+1])) dp[l][r]=(dp[l][r]+dfs(l,r+1))%Mod;
	if (l>1&&(l-1>m||T[l-1]==S[len+1])) dp[l][r]=(dp[l][r]+dfs(l-1,r))%Mod;
	return dp[l][r];
}
int main()
{
	scanf("%s%s",S+1,T+1);
	n=strlen(S+1); m=strlen(T+1);
	int ans=0;
	for(int i=0;i<=n;i++) ans=(ans+dfs(i+1,i))%Mod;
	printf("%d\n",(ans+Mod)%Mod);
	return 0;
}