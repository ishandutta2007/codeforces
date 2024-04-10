#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define ll long long
using namespace std;
const ll lim=1e18;
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
int n,p[11]={0,2,3,5,7,11,13,17,19,23,29};
ll ans=0x3f3f3f3f3f3f3f3f,v=1;
void fun(int rest,int k,int last)
{
	if(v>=ans)
		return;
	if(rest==1)
	{
		ans=v;
		return;
	}
	if(k==11)
		return;
	ll fb=v;
    for(int i=2;i<=last && i<=rest;++i)
	{
		if(lim/v<1ll*p[k])
			break;
		v*=p[k];
		if(rest%i==0)
			fun(rest/i,k+1,i);
	}
    v=fb;
}
int main()
{
	n=read();
	fun(n,1,1000);
	printf("%lld\n",ans);
	return 0;
}