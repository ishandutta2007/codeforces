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
long long n,m,i,j,z[1000005],pos[1000005],cnt[1000005],l,r,mod=1e9+7,ans;
string st;
long long qp(long long x,long long y)
{
	if (y==0) return 1;
	if (y==1) return x;
	long long z=qp(x,y/2);
	z=z*z%mod;
	if (y&1) z=z*x%mod;
	return z;
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	cin>>st;
	//st=" "+st;
	z[1]=0;
	for (i=1;i<st.length();i++)
	{
		if (i<=r)
		{
			z[i]=min(z[i-l],r-i);
		}
		while (i+z[i]<st.length()&&st[z[i]]==st[i+z[i]]) z[i]++;
		if (i+z[i]-1>r)
		{
			l=i;
			r=i+z[i]-1;
		}
	}
	/*for (i=0;i<st.length();i++) cerr<<z[i]<<' ';
	cerr<<endl;*/
	for (i=1;i<=m;i++) scanf("%I64d",&pos[i]);
	for (i=2;i<=m;i++)
	{
		if (pos[i]-pos[i-1]>=st.length()) continue;
		if (pos[i]-pos[i-1]+z[pos[i]-pos[i-1]]!=st.length())
		{
			printf("0");
			return 0;
		}
	}
	for (i=1;i<=m;i++)
	{
		cnt[pos[i]]++;
		cnt[pos[i]+st.length()]--;
	}
	for (i=1;i<=n;i++)
	{
		cnt[i]+=cnt[i-1];
		if (!cnt[i]) ans++;
	}
	printf("%I64d\n",qp(26,ans));
	return 0;
}