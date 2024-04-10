#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
const int mod=998244353;
const int inv2=499122177;
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
int n,p[200001];
int main()
{
	n=read();
	p[1]=inv2;
	p[2]=1ll*inv2*inv2%mod;
	for(int i=3;i<=n;++i)
		p[i]=(1ll*p[i-1]*inv2%mod+1ll*p[i-2]*inv2%mod*inv2%mod)%mod;
	printf("%d\n",p[n]);
	return 0;
}