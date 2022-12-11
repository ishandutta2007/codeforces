#include<bits/stdc++.h>
#define MaxN 100123
typedef long long LL;
const LL Mod=1e9+7;

char s[MaxN];
LL sum[MaxN];

int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	
	for(int i=1,l=0;i<=n;++i)
	{
		LL tmp=0;
		if(s[i]=='a')tmp=1+(l?sum[l-1]:0);
		if(s[i]=='b')l=i;
		sum[i]=(sum[i-1]+tmp)%Mod;
	}
	
	printf("%lld\n",sum[n]);
	return 0;
}