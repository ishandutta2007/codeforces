#include<cstdio>
#include<cstring>
using namespace std;
int T,len,ans;
char s[100010];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%s",s);
		len=strlen(s);
		for(int i=0;i<len;i++)
			ans+=(s[i]=='N');
		if(ans==1) puts("NO");
		else puts("YES");
	}
}