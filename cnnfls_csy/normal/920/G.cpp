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
int n,m,ind,i,j,t,x,l,r,mid,ans;
bool np[1000005];
vector<int> pri,in;
int check(int x)
{
	int i,t=in.size();
	int s=1,ans=0;
	for (i=1;i<(1<<t);i++)
	{
		s=1;
		for (j=0;j<t;j++)
		{
			if ((1<<j)&i) s*=in[j];
		}
		if (__builtin_popcount(i)&1)
		{
			ans+=x/s;
		}
		else
		{
			ans-=x/s;
		}
	}
	return ans;
}
int main()
{
	np[1]=1;
	for (i=2;i<=1000000;i++)
	{
		if (np[i]) continue;
		pri.push_back(i);
		for (j=2;i*j<=1000000;j++)
		{
			np[i*j]=1;
		}
	}
	//cerr<<pri.back()<<endl;
	cin>>t;
	while (t--)
	{
		scanf("%d%d%d",&n,&m,&ind);
		x=m;
		in.clear();
		for (i=0;sqr(pri[i])<=x;i++)
		{
			if (x%pri[i]==0)
			{
				in.push_back(pri[i]);
				x/=pri[i];
			}
			while (x%pri[i]==0)
			{
				x/=pri[i];
			}
		}
		if (x!=1) in.push_back(x);
		//check(11);
		/*for (i=1;i<=30;i++) cerr<<check(i)<<' ';
		cerr<<endl;*/
		/*for (i=0;i<in.size();i++) cerr<<pri[in[i]]<<' ';
		cerr<<endl;*/
		ind+=n-check(n);
		l=ind/(m-check(m))*m-1;r=1<<25;ans=l-1;
		while (l<r)
		{
			mid=(l+r)/2;
			if (mid-check(mid)<ind)
			{
				ans=mid;
				l=mid+1;
			}
			else r=mid;
		}
		printf("%d\n",ans+1); 
	}
	return 0;
}