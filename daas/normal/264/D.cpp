#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=1e6+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int dp[MAXN][2],a[MAXN],b[MAXN],r[3][3],l[3][3],n,m;
ll ans=1;
char s[MAXN],t[MAXN];
vector<int> Q[3][3];
int main()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	for(int i=1;i<=n;++i)
		switch(s[i])
		{
			case 'R':a[i]=0;break;
			case 'G':a[i]=1;break;
			case 'B':a[i]=2;break;
		}
	for(int i=1;i<=m;++i)
		switch(t[i])
		{
			case 'R':b[i]=0;break;
			case 'G':b[i]=1;break;
			case 'B':b[i]=2;break;
		}
	for(int i=2;i<=m;++i) Q[b[i-1]][b[i]].push_back(i);
	dp[1][0]=1;
	while(ans<m && a[1]!=b[ans]) ++ans;
	dp[1][1]=ans;
	for(int i=2;i<=n;++i)
	{
		dp[i][0]=dp[i-1][0];
		dp[i][1]=dp[i-1][1];
		if(a[i-1]==b[dp[i-1][0]]) ++dp[i][0];
		if(a[i-1]==b[dp[i-1][1]] && dp[i][1]!=m) ++dp[i][1];
		while(dp[i][1]!=m && a[i]!=b[dp[i][1]]) ++dp[i][1];
		for(int j=0;j<3;++j)
			for(int k=0;k<3;++k)
			{
				while(r[j][k]<Q[j][k].size() && Q[j][k][r[j][k]]<=dp[i][1]) ++r[j][k];
				while(l[j][k]<Q[j][k].size() && Q[j][k][l[j][k]]<dp[i][0]) ++l[j][k];
			}
		ans+=max(0,dp[i][1]-dp[i][0]+1);
		if(a[i]!=a[i-1]) ans-=max(0,r[a[i]][a[i-1]]-l[a[i]][a[i-1]]);
	}
	printf("%lld\n",ans);
	return 0;
}
//ore no turn,draw!