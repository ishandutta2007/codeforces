#include<cstdio>
using namespace std;
const int N=2e5+10;
int x,y,p,n,a[N],T;
void update(int w)
{
	if(x==-1) x=w;
	y=w;
}
int calc()
{
	x=y=p=-1;
	for(int i=1;i<n;i++)
		if(a[i]==a[i+1])
		{
			p++;
			update(i);
		}
	if(p<=0) return 0;
	else return y==x+1?1:y-x-1;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		printf("%d\n",calc());
	}
}