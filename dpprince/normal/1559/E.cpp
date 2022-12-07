// By: Little09
// Problem: E. Mocha and Stars
// Contest: Codeforces - Codeforces Round #738 (Div. 2)
// URL: https://codeforces.com/contest/1559/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")

const ll inf=1000000000000000000; 
const ll mod=998244353;
//const ll mod=1000000007;

const int N=55,M=100005;
int n,m,T; 
int a[N],b[N];
ll dp[N][M],s[M],ans[M];
int work(int k)
{
	int u=m/k;
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=u;j++)
		{
			dp[i][j]=0;
		}
	}
	dp[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=u;j++) s[j]=0;
		s[0]=dp[i-1][0];
		for (int j=1;j<=u;j++) s[j]=(dp[i-1][j]+s[j-1])%mod;
		//cout << endl;
		//for (int j=1;j<=u;j++) cout << s[j] << " ";
		//cout << endl;
		for (int j=0;j<=u;j++)
		{
			int l=(a[i]+k-1)/k,r=b[i]/k;
			if (l>r) return 0;
			int L=j-r-1,R=j-l;
			if (R<0) dp[i][j]=0;
			else if (L<0) dp[i][j]=s[R];
			else dp[i][j]=(s[R]-s[L]+mod)%mod;
			//cout << i << " " << j << " " << dp[i][j] << " " << L << " " << R << endl;
		}
	}
	ll res=0;
	for (int i=1;i<=u;i++) res=(res+dp[n][i])%mod;
	return res;
}
inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read(),b[i]=read();
	for (int i=1;i<=m;i++) ans[i]=work(i);
	for (int i=m;i>=1;i--)
	{
		//cout << ans[i] << " ";
		for (int j=2;i*j<=m;j++)
		{
			ans[i]=(ans[i]-ans[i*j]+mod)%mod;
		}
	}
	cout << ans[1] << endl;
	return 0;
}