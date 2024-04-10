#include<cstdio>
#include<algorithm>
using namespace std;

int n;
char s[300010],t[300010];
int ltot,rtot,top;
int main()
{
	scanf("%d%s",&n,s+1);
	if (n&1) return puts(":("),0;
	for (int i=1;i<=n;i++)
		if (s[i]=='(') ltot++;
		else if (s[i]==')') rtot++;
	if (ltot*2>n||rtot*2>n) return puts(":("),0;
	ltot=n/2-ltot,rtot=n/2-rtot;
	for (int i=1;i<=n;i++)
		if (s[i]=='('||s[i]==')') t[i]=s[i];
		else if (ltot) ltot--,t[i]='(';
		else t[i]=')';
//	puts(t+1);
	for (int i=1;i<=n;i++)
	{
		if (t[i]=='(') top++;
		else
		{
			if (!top) return puts(":("),0;
			top--;
		}
		if (i!=n&&!top) return puts(":("),0;
	}
	puts(t+1);
	return 0;
}