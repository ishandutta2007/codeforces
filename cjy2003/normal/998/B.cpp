#include<cstdio>
#include<algorithm>
using namespace std;
int jdz(int x)
{
	if(x>0)return x;
	else return -x;
}
int n,a[101],c[101],b,sum,num,ans;
int main()
{
	scanf("%d %d",&n,&b);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]&1)sum++;
		if(sum*2==i&&i<n)c[++num]=jdz(a[i+1]-a[i]);	
	}
	sort(c+1,c+1+num);
	for(int i=num+1;i<=100;i++)
		c[i]=0x7fffffff;
	while(b>0)
	{
		ans++;
		if(b<c[ans])
		{
			ans--;
			break;	
		}
		b-=c[ans];
	}
	printf("%d",ans);
	return 0;
}