#include<bits/stdc++.h>
typedef long long LL;
const LL Mod=1e9+7;
const LL ans[]={1,3,15,133,2025,37851,1030367,36362925,1606008513};
int main()
{
	int n;scanf("%d",&n);
	if(n%2==0)return puts("0"),0;
	LL res=ans[n/2];
	for(int i=1;i<=n;++i)res=res*i%Mod;
	printf("%lld\n",res);
	return 0;
}