#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,l[100010],p[100010],len[100010];
int main()
{
	scanf("%d %d",&n,&m);
	long long sum=0;
	for(int i=1;i<=m;++i)scanf("%d",&l[i]),sum+=l[i];
	if(sum<n)return printf("-1"),0;
	for(int i=1;i<=m;++i)if(l[i]+i-1>n)return printf("-1"),0;
	int cur=0;
	for(int i=1;i<=m;++i)len[i]=1,++cur;
	for(int i=m;i;--i)
		if(cur<n)
		{
			int ad=min(n-cur,l[i]-1);
			cur+=ad,len[i]+=ad;
		}
	for(int i=1,last=1;i<=m;++i)printf("%d ",last),last+=len[i];
	return 0;
}