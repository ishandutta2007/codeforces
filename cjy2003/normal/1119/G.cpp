#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,h[1000010],k[1000010],tot,s[1000010],k1[1000010],cnt[2000020],num;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&h[i]);
		tot+=h[i];
		k[i]=(k[i-1]+h[i])%n;
	}
	printf("%d\n",(tot-1)/n+1);
	k[m]=n;
	sort(k+1,k+m+1);
	for(int i=1;i<=m;++i)
		s[i]=k[i]-k[i-1],printf("%d ",s[i]);
	printf("\n");
	int last=1;
	for(int i=1;i<=m;++i)
		while(h[i]>0)h[i]-=s[last],cnt[++num]=i,last=last%m+1;
	while(num%m)cnt[++num]=m;
	for(int i=1;i<=num;++i)
	{
		printf("%d ",cnt[i]);
		if(i%m==0)printf("\n");
	}
	return 0;
}