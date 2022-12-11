#include<cstdio>
#include<algorithm>
using namespace std;
int n,b,a[110];
int chc[110],top;
int main()
{
	int tmp=0;
	scanf("%d%d",&n,&b);
	for (int i=1;i<=n;i++) scanf("%d",a+i);
	for (int i=1;i<n;i++)
	{
		if (a[i]&1) tmp++;
		else tmp--;
		if (!tmp) chc[++top]=(a[i]<a[i+1]?a[i+1]-a[i]:a[i]-a[i+1]);
	}
	sort(chc+1,chc+top+1);
	for (int i=1;i<=top;i++)
	{
		if (b>=chc[i]){b-=chc[i];continue;}
		printf("%d\n",i-1);
		return 0;
	}
	printf("%d\n",top);
	return 0;
}