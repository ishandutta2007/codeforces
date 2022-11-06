#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int pre[1000010],nex[1000010],xl[200010],hv[1000010];
int main()
{
	int n,n1,t1,t2;
	cin>>n;
	for(n1=1;n1<=n;n1++)
	{
		scanf("%d%d",&t1,&t2);
		pre[t2]=t1;
		nex[t1]=t2;
		hv[t1]=hv[t2]=1;
	}
	for(int i=nex[0],j=2;i!=0;i=nex[i],j+=2)
		xl[j]=i;
	if(n%2==0)
	{
		for(int i=pre[0],j=n-1;i!=0;i=pre[i],j-=2)
			xl[j]=i;
		for(int i=1;i<=n;i++)
			printf("%d\n",xl[i]);
		return 0;
	}
	else
	{
		for(int i=1;i<=1000000;i++)
			if(pre[i]==0&&nex[0]!=i&&hv[i])
			{
				for(int k=i,j=1;k!=0;k=nex[k],j+=2)
					xl[j]=k;
				for(int i=1;i<=n;i++)
					printf("%d\n",xl[i]);
				return 0;
			}
	}
}