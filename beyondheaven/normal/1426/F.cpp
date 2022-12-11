#include<bits/stdc++.h>
#define MaxN 200123
typedef long long LL;
const LL Mod=1e9+7;

char s[MaxN];
int pre1[MaxN],pre2[MaxN];//pre1: a pre2: ?
int suf1[MaxN],suf2[MaxN];

LL pow3[MaxN];
int main()
{
	int n;
	scanf("%d%s",&n,s+1);
	
	for(int i=pow3[0]=1;i<=n;++i)
	pow3[i]=pow3[i-1]*3%Mod;
	
	for(int i=1;i<=n;++i)
	{
		pre1[i]=pre1[i-1]+(s[i]=='a'?1:0);
		pre2[i]=pre2[i-1]+(s[i]=='?'?1:0);
	}
	
	for(int i=n;i;--i)
	{
		suf1[i]=suf1[i+1]+(s[i]=='c'?1:0);
		suf2[i]=suf2[i+1]+(s[i]=='?'?1:0);
	}
	
	int cnt=pre2[n];
	LL ans=0;
	
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='b')
		ans=(ans+pow3[cnt]*pre1[i-1]%Mod*suf1[i+1])%Mod;
		if(s[i]=='?')
		ans=(ans+pow3[cnt-1]*pre1[i-1]%Mod*suf1[i+1])%Mod;
	}
	
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='b'&&cnt>=1)
		{
			ans=(ans+pow3[cnt-1]*pre2[i-1]%Mod*suf1[i+1])%Mod;
			ans=(ans+pow3[cnt-1]*pre1[i-1]%Mod*suf2[i+1])%Mod;
		}
		if(s[i]=='?'&&cnt>=2)
		{
			ans=(ans+pow3[cnt-2]*pre2[i-1]%Mod*suf1[i+1])%Mod;
			ans=(ans+pow3[cnt-2]*pre1[i-1]%Mod*suf2[i+1])%Mod;
		}
	}
	
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='b'&&cnt>=2)
		ans=(ans+pow3[cnt-2]*pre2[i-1]%Mod*suf2[i+1])%Mod;
		if(s[i]=='?'&&cnt>=3)
		ans=(ans+pow3[cnt-3]*pre2[i-1]%Mod*suf2[i+1])%Mod;
	}
	
	printf("%lld\n",ans);
	return 0;
}