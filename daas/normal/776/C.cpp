#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<map>
#define int long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,K,flag1,flag2,maxn,minn,num[101],a[100001],ans;
map<int,int> Q;
signed main()
{
	n=read(),K=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		if(a[i]>0)
			maxn+=a[i];
		else
			minn+=a[i];
	}
	if(K==1)
		num[0]=num[1]=1;
	else
		if(K==-1)
		{
			num[0]=2;
			num[1]=-1;
			num[2]=1;
		}
		else
		{
			int NOW=1;
			num[0]=num[1]=1;
			while(!flag1 || (!flag2 && K<0))
			{
				NOW*=K;
				if(NOW>maxn)
				{
					flag1=1;
					continue;
				}
				if(NOW<minn)
				{
					flag2=1;
					continue;
				}
				num[++num[0]]=NOW;
			}
		}
	Q[0]++;
	for(int i=1;i<=n;++i)
	{
		a[i]+=a[i-1];
		for(int j=1;j<=num[0];++j)
			ans+=Q[a[i]-num[j]];
		Q[a[i]]++;
	}
	printf("%lld\n",ans);
	return 0;
}