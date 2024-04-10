#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=800,Mod=1000000007;
int D[MX],Len;
ll R[MX];

//n u a>=d
ll dp[MX][2][MX];
ll dfs(int n,int u,int a,int d)
{
	if(n==Len)return R[a];
	ll &res=dp[n][u][a];
	if(res!=-1)return res;
	int h=u?D[n+1]:9; res=0;
	Fr(i,0,h)res+=dfs(n+1,u&&i==h,a+(i>=d),d);
	res%=Mod;
	return res;
}

ll Solve(char* s)
{
	Len=strlen(s+1);
	Fr(i,1,Len)R[i]=(R[i-1]*10+1)%Mod;
	Fr(i,1,Len)D[i]=s[i]-'0';
	ll res=0;
	Fr(i,1,9)Fill(dp,-1),res+=dfs(0,1,0,i);
	return res%Mod;
}

char S[MX];
int main()
{
	scanf("%s",S+1);
	printf("%lld\n",Solve(S));
	return 0;
}