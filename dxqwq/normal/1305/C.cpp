#include<bits/stdc++.h>
const int N=2e5+5;
int n,mo,a[N],i,j,ans=1;
using namespace std;
int main()
{
	scanf("%d%d",&n,&mo);
	for(i=1;i<=n;++i )scanf("%d",a+i);
	sort(a+1,a+n+1);
	if(n>mo){puts("0");return 0;}
	for(i=1;i<n;++i) for(j=i+1;j<=n;++j) ans=1ll*ans*(a[j]-a[i])%mo;
	printf("%d\n",ans);
}