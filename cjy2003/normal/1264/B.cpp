#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
void no()
{
	printf("NO");
	exit(0);
}
int a,b,c,d,ans[100010];
int main()
{
	scanf("%d %d %d %d",&a,&b,&c,&d);
	if(abs(a+c-b-d)>1)no();
	if(a+c>=b+d)
	{
		for(int i=1;i<=a;++i)ans[i*2-1]=0;
		for(int i=a+1;i<=a+c;++i)ans[i*2-1]=2;
		for(int i=1;i<=b;++i)ans[i*2]=1;
		for(int i=b+1;i<=b+d;++i)ans[i*2]=3;
	}
	else
	{
		for(int i=1;i<=b;++i)ans[i*2-1]=1;
		for(int i=b+1;i<=b+d;++i)ans[i*2-1]=3;
		for(int i=1;i<=a;++i)ans[i*2]=0;
		for(int i=a+1;i<=a+c;++i)ans[i*2]=2;
	}
	for(int i=1;i<a+b+c+d;++i)if(ans[i+1]>ans[i]+1||ans[i+1]<ans[i]-1)no();
	printf("YES\n");
	for(int i=1;i<=a+b+c+d;++i)printf("%d ",ans[i]);
	return 0;
}