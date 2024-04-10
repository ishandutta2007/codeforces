#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
#define MN 200000
char s[MN+5];
int main()
{
	int n,a,b,c=0,i;ll ans=1e18;
	scanf("%d%d%d%s",&n,&a,&b,s+1);
	for(i=1;i<=n;++i)if(s[i]=='1')++c;
	for(i=1;i<=c;++i)ans=min(ans,1LL*a*i+b*(1LL*n%i*(n/i)*(n/i)+1LL*(i-n%i)*(n/i-1)*(n/i-1)));
	printf("%I64d",ans);
}