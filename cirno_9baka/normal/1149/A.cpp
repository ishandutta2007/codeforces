#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int M=998244353;
typedef long long ll;
int n,i,a[200005],f[500005],s1,s2,ans,l,b[200005],k,j;
int main(){
	scanf("%d",&n);
	f[1]=1;
	for(i=2;i*i<=500000;i++)
		if(f[i]==0)
			for(j=i*2;j<=n;j+=i)
				f[i]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1)
			s1++;
		else
			s2++;
	}
	if(s2==0)
	{
		for(i=1;i<=n;i++)
			cout<<1<<' ';
	}
	else
		if(s1==0)
			for(i=1;i<=n;i++)
				cout<<2<<' ';
	else
	{
		s2--;
		s1--;
		b[1]=2;
		b[k=2]=1;
		l=3;
		ans=1;
		for(i=4;;i++)
			if(f[i]==0)
			{
				int t=i-l;
				while(t>0)
				{
					t-=2;
					if(s2>0)
					{
						s2--;
						b[++k]=2;
					}
					else
						if(s1>1)
						{
							s1-=2;
							b[++k]=1;
							b[++k]=1;
						}
						else
						{
							if(s1==1)
								b[++k]=1;
							for(i=1;i<=k;i++)
								printf("%d ",b[i]);
							return 0;
						}
				}
			}
	}
}