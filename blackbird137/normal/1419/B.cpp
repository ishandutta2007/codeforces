#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=1e6+5;
int t,n,m,a[N];

signed main()
{
	for(int i=1,j=1;i<=30;++i,j*=2)
		a[i]=a[i-1]*2+j*j;
	for(int i=1;i<=30;++i)
		a[i]+=a[i-1];
	t=read();
	while(t--)
	{
		n=read();
		m=upper_bound(a+1,a+1+30,n)-a-1;
		printf("%lld\n",m);
	}
	return 0;
}