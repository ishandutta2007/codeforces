#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define ll long long
using namespace std;
const int mod=998244353;
inline int MOD(int x){return x+((x>>31)&mod);}
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,ans,sum2[300010],all,dp[300010];
string s[300010],t[300010];
void solve()
{
	//for(int i=1;i<=n;++i) cout<<s[i]<<endl;
	//cout<<endl;
	for(int i=1;i<=n;++i)
	{
		for(int l=1,r;l<=m;l=r+1)
		{
			r=l;
			if(s[i][l]=='*') continue;
			while(r+1<=m && s[i][r+1]==s[i][l]) ++r;
			for(int j=l;j<=r;++j) ans=MOD(ans+dp[j-l+1]-mod);
		}
	}
}
int main()
{
	n=read(),m=read();
	sum2[0]=1;
	for(int i=1;i<=n*m;++i) sum2[i]=(ll)sum2[i-1]*2%mod;
	for(int i=1;i<=n;++i)
	{
		cin>>s[i];
		s[i]="0"+s[i];
		for(int j=1;j<=m;++j) if(s[i][j]=='o') ++all;
	}
	if(all>=2) dp[2]=sum2[all-2];
	if(all>=3) dp[3]=sum2[all-3];
	for(int i=4;i<=all;++i)
	{
		if(i%2) dp[i]=MOD(dp[i-2]+sum2[all-i]-mod);
		else dp[i]=MOD(dp[i-1]+sum2[all-i]-mod);
	}

	solve();
	for(int i=1;i<=m;++i)
	{
		t[i]="0";
		for(int j=1;j<=n;++j) t[i]+=s[j][i];
	}
	swap(n,m);
	for(int i=1;i<=n;++i)
	{
		s[i]="0";
		for(int j=1;j<=m;++j) s[i]+=t[i][j];
	}
	solve();
	printf("%d\n",ans);
	return 0;
}