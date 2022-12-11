#include<cstdio>
#include<algorithm>
using namespace std;

int n,w[200010],len;
bool chk(int x)
{
	for (int i=1;i<=x;i++)
		if (w[n-x+i]-w[i]<len)
			return false;
	return true;
}
int main()
{
	scanf("%d%d",&n,&len);
	for (int i=1;i<=n;i++) scanf("%d",w+i);
	sort(w+1,w+n+1);
	int l=0,r=n/2,mid;   //0 not 1!!
	while (l<r)
	{
		mid=l+r+1>>1;
		if (chk(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}