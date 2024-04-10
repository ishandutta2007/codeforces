#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register ll
ll ans,n,m,A,B,bj;
ll dabiao[26]={0,0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,
1,349525,299593,1398101,178481,5592405,1082401};
int main()
{
	scanf("%lld",&n);
	re a;
	for(re j=1;j<=n;j++)
	{
		scanf("%lld",&a);
		re la=0,b=0;
		while(b<=a) la++,b=(1<<la);
		printf("%lld\n",(b-a)!=1?(1ll<<la)-1ll:dabiao[la]);
	}
	return 0;
}