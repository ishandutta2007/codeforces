#include<bits/stdc++.h>
using namespace std;
__int128 p=1e9+7;
int main()
{
    long long K,N;
    __int128 n,k;
	__int128 ans;
    scanf("%lld %lld",&K,&N);
    n=N,k=K;
    ans=n*k%p;
    __int128 l=1,r=0,t=0;
    while(l<=n) r=(t=k/l)?min(k/t,n):n,ans+=p-t*(r-l+1)%p*(l+r)%p*500000004ll%p,ans%=p,l=r+1;
    printf("%lld\n",(long long)ans);
    return 0;
}