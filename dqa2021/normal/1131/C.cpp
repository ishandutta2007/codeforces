#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n,w[110];
bool mrk[110];
bool chck(int x)
{
	for (int i=2;i<=n;i++)
		if (w[i]-w[i-1]>x) return false;
	memset(mrk,false,sizeof mrk);
	int lst=1;
	for (int i=2;i<=n;i++)
		if (i==n||w[i+1]-w[lst]>x) lst=i,mrk[i]=true;
	lst=n;
	for (int i=n;i;i--)
		if (!mrk[i])
		{
			if (w[lst]-w[i]>x) return false;
			lst=i;
		}
	return true;
}
void print(int x)
{
	memset(mrk,false,sizeof mrk);
	int lst=1;
	printf("%d",w[1]);
	for (int i=2;i<=n;i++)
		if (i==n||w[i+1]-w[lst]>x) lst=i,mrk[i]=true,printf(" %d",w[i]);
	for (int i=n;i>1;i--) if (!mrk[i]) printf(" %d",w[i]); putchar('\n');
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",w+i);
	sort(w+1,w+n+1);
	int l=0,r=w[n]-w[1],mid;
	while (l<r)
	{
		mid=l+r>>1;
		if (chck(mid)) r=mid;
		else l=mid+1;
	}
	print(l);
	return 0;
}