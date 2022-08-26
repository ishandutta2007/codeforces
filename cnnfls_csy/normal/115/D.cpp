#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#define sqr(x) (x)*(x)
using namespace std;
string st;
long long n,m,i,j,k,mod=1e6+3,c[2005],fac[5010],inv[5010],fi[5010],y[2005],sz,sta[2005],stsz,ans,dp[2005][2005],inum,nnum,x,len;
int main()
{
	cin>>st;
	n=st.length();
	for (i=0;i<n;i++)
	{
		if (st[i]=='*'||st[i]=='/')
		{
			if ((!i)||(st[i-1]>'9')||st[i-1]<'0')
			{
				cout<<0;
				return 0;
			}
		}
	}
	if (st[n-1]>'9'||st[n-1]<'0')
	{
		cout<<0;
		return 0;
	}
	fac[0]=fac[1]=inv[0]=inv[1]=fi[0]=fi[1]=1;
    for (i=2;i<=5000;i++)  
    {  
        fac[i]=fac[i-1]*i%mod;
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
        fi[i]=fi[i-1]*inv[i]%mod;
    }
	for (i=1;i<=5000;i++)
	{
		fac[i]=(fac[i-1]*i)%mod;
		fi[i]=(fi[i-1]*inv[i])%mod;
	}
	c[1]=1;
	for (i=1;i<=2000;i++)
	{
		c[i+1]=fac[2*i]*fi[i]%mod*fi[i]%mod*inv[i+1]%mod;
	}
	sz=0;
	for (i=0;i<n;i++)
	{
		nnum=0;
		if (st[i]<='9'&&st[i]>='0')
		{
			inum=1;
		}
		else
		{
			if (inum)
			{
				inum=0;
				y[sz++]=0;
			}
			if ((!i)||(!(st[i-1]<='9'&&st[i-1]>='0')))
			{
				y[sz++]=1;
			}
			else nnum=1;
		}
	}
   	if (inum) y[sz++]=0;
	stsz=0;
	for (i=0;i<sz;i++)
	{
		if (y[i]==0) sta[stsz]++;
			else stsz++;
	}
	if (stsz==0) 
	{
		cout<<c[sz];
		return 0;
	}
	dp[stsz+1][0]=1;
	for (i=stsz;i>=0;i--)
	{
		x=sta[i];
		if (i)
		{
			len+=x;
			for (j=1;j<=len;j++)
			{
				for (k=max(x-j,0ll);k<=len-j;k++)
				{
					dp[i][k+1]+=(dp[i+1][k+j-x]*c[j])%mod;
					if(dp[i][k+1]>=mod)dp[i][k+1]-=mod;
				}
			}
		}
		else
		{
			for (j=0;j<=len;j++)
			{
				dp[i][j+x]=dp[i+1][j];
			}
			len+=x;
		}
	}
	for(i=1;i<=sz;i++) ans=(ans+dp[0][i]*c[i])%mod;
	cout<<ans;
}