#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
#define llx(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
long long n,m,i,j,num[100005],ans,x,y;
int main()
{
	scanf("%I64d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%I64d",&num[i]);
		num[i]=max(num[i],num[i-1]);
	}
	scanf("%I64d",&m);
	for (i=1;i<=m;i++)
	{
		scanf("%I64d%I64d",&x,&y);
		ans=max(ans,num[x]);
		printf("%I64d\n",ans);
		ans+=y;
	}
	return 0;
}