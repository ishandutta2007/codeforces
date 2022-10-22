//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<iomanip>
#include<stack>
#include<bitset>
#define int unsigned long long
#define INF 0x3fffffffffffffff
#define MOD 0xffffffffffffffff
#define BAS 233
using namespace std;
int sum[200005],n,m,l[200005],r[200005],ans;
int power(int a,int b)
{
	int tmp=1;
	while(b)
	{
		if(b&1)
		{
			tmp=tmp*a%MOD;
		}
		a=a*a%MOD;
		b>>=1;
	}
	return tmp;
}
struct S{
	int s,p;
	bool operator < (const S &A)const
	{
		return s==A.s?p<A.p:s<A.s;
	}
}s[200005];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>l[i]>>r[i];
		sum[l[i]]^=power(BAS,i);
		sum[r[i]+1]^=power(BAS,i);
	}
	for(int i=1;i<=m;++i)
	{
		sum[i]^=sum[i-1];
	}
	for(int i=1;i<=m;++i)
	{
		if(!sum[i])
		{
			int j=i,tmp=1;
			while(!sum[++j]&&j<=m)
			{
				tmp+=(j-i+2)*(j-i+1)>>1;
			}
			--j;
			ans-=tmp;
			i=j;
		}
	}
	for(int i=1;i<=n;++i)
	{
		sum[l[i]]^=power(BAS,i);
	}
	for(int i=1;i<=m;++i)
	{
		sum[i]^=sum[i-1];
	}
	for(int i=1;i<=m;++i)
	{
		s[i].s=sum[i];
		s[i].p=i;
	}
	sort(s+1,s+1+m);
	s[0].s=-1;
	for(int i=1;i<=m;++i)
	{
		if(s[i].s!=s[i-1].s)
		{
			int j=i,tmp=s[i].p-1;
			ans+=s[i].p*(i-i+1)-tmp;
			while(s[++j].s==s[i].s&&j<=m)
			{
				tmp+=s[j].p-1;
				ans+=s[j].p*(j-i+1)-tmp;
			}
			--j;
			i=j;
		}
	}
	cout<<ans<<endl;
	return 0;
}