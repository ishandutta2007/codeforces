#include<bits/stdc++.h>
#define MaxN 300123
char s[MaxN];
int main()
{
	int n;scanf("%d%s",&n,s+1);
	long long ans=0;
	
	bool Avis=0,Bvis=0;
	for(int i=1,j;i<=n;++i)
	{
		bool flag=true;
		for(j=i-1;j;--j)
		{
			flag&=(s[j]==s[i]);
			if(s[j]==s[i])break;
		}
		
		if(j)
		{
			ans+=j;
			if(flag&&((s[i]=='A'&&Bvis)||(s[i]=='B'&&Avis)))
			--ans;
		}
		
		Avis|=(s[i]=='A');
		Bvis|=(s[i]=='B');
	}
	
	printf("%lld\n",ans);
	return 0;
}