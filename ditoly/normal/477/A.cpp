#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main()
{
	int a,b,i,ans=0;
	scanf("%d%d",&a,&b);
	for(i=1;i<=a;++i)ans=(ans+1LL*b*(b-1)/2%MOD*(1LL*i*b%MOD+1))%MOD;
	printf("%d",ans);
}