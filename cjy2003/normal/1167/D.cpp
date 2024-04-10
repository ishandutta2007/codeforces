#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,dp;
char s[200020];
bool ans[200020];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='(')dp^=1,ans[i]=dp;
		else ans[i]=dp,dp^=1;
		printf("%d",ans[i]);
	}
	return 0;
}