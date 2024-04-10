#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
char s[2020];
int n,ans,C[2020][2020],suf[2020][2020];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int cntr=0,cntn=0;
	for(int i=1;i<=n;++i)cntr+=s[i]==')',cntn+=s[i]=='?';
	for(int i=0;i<=n;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)(C[i][j]=C[i-1][j-1]+C[i-1][j])>=mod?C[i][j]-=mod:0;
		for(int j=i;~j;--j)(suf[i][j]=suf[i][j+1]+C[i][j])>=mod?suf[i][j]-=mod:0;
	}
	for(int i=1;i<=n;++i)
	{
		int cnt1=0,cnt2=0,cnt3=cntr,cnt4=cntn;
		for(int j=1;j<=n;++j)
		{
			if(s[j]=='?')--cnt4;
			if(s[j]==')')--cnt3;
			if(s[j]=='(')
			{
				++cnt1;
				if(i-cnt1>=0)ans=(ans+1ll*C[cnt2][i-cnt1]*suf[cnt4][max(0,i-cnt3)])%mod;
			}
			else if(s[j]=='?')
			{
				++cnt2;
				if(i-1-cnt1>=0)ans=(ans+1ll*C[cnt2-1][i-1-cnt1]*suf[cnt4][max(0,i-cnt3)])%mod;
			}			
		}
	}
	printf("%d",ans);	

	return 0;
}