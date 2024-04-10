// Problem: C. Anna, Svyatoslav and Maps
// Contest: Codeforces - Codeforces Round #581 (Div. 2)
// URL: https://codeforces.com/contest/1204/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
char s[103][103];
int d[103][103],a[1000003];
int lst[1000003];
int dp[1000003];
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1); 
	memset(d,0x3f,sizeof(d));
	for(int i=1; i<=n; ++i)
	for(int j=1; j<=n; ++j) if(s[i][j]=='1') d[i][j]=1;
	for(int i=1; i<=n; ++i) d[i][i]=0;
	for(int i=1; i<=n; ++i)
	for(int j=1; j<=n; ++j)
	for(int k=1; k<=n; ++k) 
	d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
	int m=read();
	for(int i=1; i<=m; ++i) a[i]=read();
	for(int i=1; i<=m; ++i)
	{
		dp[i]=i,lst[i]=i-1;
	for(int j=1; j<=n&&i-j>0; ++j)
	{
		if(d[a[i-j]][a[i]]==j&&dp[i-j]+1<dp[i])
		{
			dp[i]=dp[i-j]+1;
			lst[i]=i-j;
		}
	}
	// printf("%lld %lld\n",dp[i],lst[i]);
	}
	// return 0;
	int cur=m;
	stack<int> ans;
	while(1)
	{
		ans.push(a[cur]);
		if(cur==1) break;
		cur=lst[cur];
	}
	printf("%lld\n",dp[m]);
	assert(ans.size()==dp[m]);
	while(!ans.empty())
	{
		printf("%lld ",ans.top());
		ans.pop();
	}
	return 0;
}