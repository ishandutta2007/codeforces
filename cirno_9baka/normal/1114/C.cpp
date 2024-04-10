#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int M=998244353,P=1000000007;
long long n,b,i,a[100005],c[100005],k,ans=2000000000000000000ll,s,p;
int main(){
	cin>>n>>b;
	for(i=2;i*i<=b;i++)
		if(b%i==0)
		{
			a[++k]=i;
			while(b%i==0)
			{
				b/=i;
				c[k]++;
			}
		}
	if(b!=1)
	{
		a[++k]=b;
		c[k]=1;
	}
	for(i=1;i<=k;i++)
	{
		p=a[i];
		s=0;
		while(p<=n)
		{
			s+=n/p;
			if(p%M*a[i]%M!=p*a[i]%M||p%P*a[i]%P!=p*a[i]%P)
				break;
			p*=a[i];
		}
		ans=min(ans,s/c[i]);
	}
	cout<<ans;
}