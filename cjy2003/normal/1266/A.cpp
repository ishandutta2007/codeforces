#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
char s[110];
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",s+1);
		int len=strlen(s+1);
		bool f0=0;
		int sum=0,cnte=0;
		for(int i=1;i<=len;++i)
		{
			sum+=s[i]-'0';
			if(s[i]=='0')f0=1;
			cnte+=s[i]%2==0;
		}
		if(sum%3==0&&cnte>=2&&f0)printf("red\n");
		else printf("cyan\n");
	}
	return 0;
}