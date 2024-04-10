#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define MN 77777
#define MX 900000
#define N 1048576
int t[N*2+5],sg[MX+5];
long long z[MN+5];
void change(int k,int x){for(t[k+=N]=x;k>>=1;)t[k]=min(t[k<<1],t[k<<1|1]);}
int query(int x)
{
	int k=1;
	while(k<N)if(t[k<<=1]>=x)++k;
	return k-N;
}
int main()
{
	int n,i,a,b,ans=0;
	for(i=2,a=b=1;i<=MX;++i)
	{
		for(;b*b<=i;++b)change(sg[b],b);
		while(a*a*a*a<i)++a;
		sg[i]=query(a);
	}
	for(scanf("%d",&n),i=1;i<=n;++i)scanf("%I64d",&z[i]);
	sort(z+1,z+n+1);memset(t,0,sizeof(t));
	for(a=b=i=1;i<=n;++i)
	{
		if(z[i]<=MX){ans^=sg[z[i]];continue;}
		for(;1LL*b*b<=z[i];++b)change(sg[b],b);
		while(1LL*a*a*a*a<z[i])++a;
		ans^=query(a);
	}
	puts(ans?"Furlo":"Rublo");
}