#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
unsigned long long x=1e9+7,po[5005],hash1[5005],hash2[5005];
int n,m,dp[5005][5005],cnt[5005],i,j,k,ans[5005];
string st;
bool huiwen(int l,int r)
{
	return (hash1[r]-hash1[l-1]*po[r-l+1])*po[l-1]==hash2[r]-hash2[l-1];
}
int main()
{
	ios::sync_with_stdio(0);
	po[0]=1;
	cin>>st;
	st=" "+st;
	for (i=1;i<st.length();i++)
	{
		 hash1[i]=hash1[i-1]*x+st[i];
		 hash2[i]=hash2[i-1]+po[i-1]*st[i];
		 po[i]=po[i-1]*x;
	}
	for (k=1;k<st.length();k++)
	{
		for (i=1;i+k-1<st.length();i++)
		{
			j=i+k-1;
			if (huiwen(i,j)) dp[i][k]=dp[i][k/2]+1;
			cnt[dp[i][k]]++;
		}
	}
	for (i=st.length()-1;i>=1;i--)
	{
		ans[i]=ans[i+1]+cnt[i];
	}
	for (i=1;i<st.length();i++) cout<<ans[i]<<" ";
	return 0;
}