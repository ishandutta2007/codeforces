#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=200005,E=524288;
int s,f[4]={0,2,3,1},t;
long long n,i,j;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n%3==1)
		{
			n/=3;
			for(i=0;n>=(1ll<<i*2);n-=(1ll<<i*2),++i);
			printf("%lld\n",(1ll<<2*i)+n);
		}
		else
		if(n%3==2)
		{
			n/=3;
			for(i=0;n>=(1ll<<2*i);n-=(1ll<<i*2),++i);
			long long m=0,tmp=n;
			for(j=0;tmp;j+=2,tmp>>=2)
				m=m|(1ll*f[tmp&3]<<j);
			printf("%lld\n",(1ll<<2*i+1)+m);
		}
		else
		if(n%3==0)
		{
			n=n/3-1;
			for(i=0;n>=(1ll<<2*i);n-=(1ll<<i*2),++i);
			long long m=0,tmp=n;
			for(j=0;tmp;j+=2,tmp>>=2)
				m=m|(1ll*f[tmp&3]<<j);
			printf("%lld\n",((1ll<<2*i)+n)^((1ll<<2*i+1)+m));
		}
	}
}