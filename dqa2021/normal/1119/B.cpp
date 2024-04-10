#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n,h,w[1010];
int ww[1010];
bool chk(int x)
{
	memcpy(ww,w,sizeof w);
	sort(ww+1,ww+x+1);
	if (x&1)
	{
		long long hh=0;
		for (int i=1;i<=x;i+=2) hh+=ww[i];
		return hh<=h;
	}
	long long hh=0;
	for (int i=2;i<=x;i+=2) hh+=ww[i];
	return hh<=h;
}
int main()
{
	scanf("%d%d",&n,&h);
	for (int i=1;i<=n;i++) scanf("%d",w+i);
	int l=1,r=n,mid;
	while (l<r)
	{
		mid=l+r+1>>1;
		if (chk(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}