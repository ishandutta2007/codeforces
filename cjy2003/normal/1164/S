#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,p;
char a[200];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",a+1);
		p=0;
		for(int i=1;i<=n;++i)
			if(a[i]=='8')
			{
				p=i;
				break;
			}
		if(!p||n-p<10)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}