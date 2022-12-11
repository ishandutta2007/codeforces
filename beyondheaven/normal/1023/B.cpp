#include<bits/stdc++.h>
typedef long long LL;
LL n,k;
inline LL Solve()
{
	if(2*n-1<k||k<3)return 0;
	return std::min(n,k-1)-k/2;
}
int main()
{
	scanf("%lld%lld",&n,&k);
	printf("%lld\n",Solve());
	return 0;
}