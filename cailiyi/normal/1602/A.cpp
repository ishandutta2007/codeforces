#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n;
char s[105];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s),n=strlen(s);
		int a=0;
		for(int i=1;i<n;++i) if(s[i]<s[a]) a=i;
		printf("%c ",s[a]);
		for(int i=0;i<n;++i) if(i!=a) putchar(s[i]);
		putchar('\n'); 
	}
	return 0;
}