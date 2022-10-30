#include<bits/stdc++.h>
using namespace std;
int T,n;
char s[15];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		int ans=0;
		n=strlen(s+1);
		for(int i=1;i<=n;i++)ans=max(ans,s[i]-'0');
		printf("%d\n",ans);
	}
	return 0;
}