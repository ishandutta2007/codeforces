#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int k;
char s[6]={'a','e','i','o','u'};
int main()
{
	scanf("%d",&k);
	for(int i=5;5*i<=k;++i)
		if(k%i==0)
		{
			int n=i,m=k/i;
			for(int j=0;j<k;++j)
				printf("%c",s[(j/m+j%m)%5]);
			return 0;
		}
	printf("-1");
	return 0;
}