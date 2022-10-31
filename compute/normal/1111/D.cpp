#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
const int mod=1e9+7;
long long dp[maxn];
long long cur[maxn];
long long ans[55][55];
string s;
long long w[55];
long long fac[maxn];
long long base;
int change(char x)
{
	if(x>='a'&&x<='z') return x-'a';
	else return x-'A'+26;
}
void del(int x)
{
	if(!w[x]) return;
	for(int j=w[x];j<=s.length()/2;j++)
	{
		cur[j]-=cur[j-w[x]];
		cur[j]+=mod;
		cur[j]%=mod;
	}
}
long long inv(long long a)
{
	long long ret=1;
	long long b=mod-2;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
void db()
{
	fac[0]=1;
	for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
	base=fac[s.length()/2]*fac[s.length()/2]%mod;
	for(int i=0;i<s.length();i++)
		w[change(s[i])]++;
	dp[0]=1;
	for(int i=0;i<52;i++)
	{
		base=base*inv(fac[w[i]])%mod;
		if(!w[i]) continue;
		for(int j=s.length()/2;j>=w[i];j--)
		{
			dp[j]=(dp[j]+dp[j-w[i]])%mod;
		}
	}
	for(int i=0;i<52;i++)
	{
		for(int j=i;j<52;j++)
		{
			memcpy(cur,dp,sizeof(dp));
			del(i);if(i!=j) del(j);
			ans[i][j]=2LL*base%mod*cur[s.length()/2]%mod;
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>s;
	db();
	int q;
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		char xx=s[x-1],yy=s[y-1];
		x=change(xx);
		y=change(yy);
		if(x>y) swap(x,y);
		cout<<ans[x][y]<<'\n';
	}
}