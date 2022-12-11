#include<cstdio> 
#include<cstring>
#define MN 1000000
#define MOD 1000000007
char s[MN+5];
int main()
{
	int n,i,x=0,ans=0;
	scanf("%s",s+1);n=strlen(s+1);
	for(i=1;i<=n;++i)
		if(s[i]=='a')x=(x*2+1)%MOD;
		else ans=(ans+x)%MOD;
	printf("%d",ans);
}