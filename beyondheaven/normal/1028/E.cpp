#include<bits/stdc++.h>
#define MaxN 150123
typedef long long LL;
int n;
LL a[MaxN],b[MaxN];
#define pre(i) (((i)+n-2)%n+1)
#define nxt(i) ((i)%n+1)
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	scanf("%lld",b+i);
	int pos=0;
	for(int i=1;i<=n;++i)
	if(b[i]>b[pre(i)])pos=i;
	if(!pos)
	{
		if(std::all_of(b+1,b+n+1,[](LL x){return x==0LL;}))
		{
			puts("YES");
			for(int i=1;i<=n;++i)
			printf("%d ",1);
		}
		else puts("NO");
		return 0;
	}
	a[pos]=b[pos];
	for(int i=pre(pos);i!=pos;i=pre(i))
	{
		LL k=(b[pre(i)]-b[i])/a[nxt(i)]+1;
		a[i]=b[i]+k*a[nxt(i)];
	}
	puts("YES");
	for(int i=1;i<=n;++i)
	printf("%lld ",a[i]);
	return 0;
}