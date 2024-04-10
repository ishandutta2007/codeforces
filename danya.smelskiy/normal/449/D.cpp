#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
int n;
int x;
int dp[(1<<21)];
long long pp[1000005];
long long ans;
 main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>x;
        ++dp[x];
    }
    for (int i=0;i<=20;++i)
        for (int j=(1<<20);j>=0;--j)
            if ((j&(1<<i))==0) dp[j]+=dp[(j^(1<<i))];
    pp[0]=1;
    for (int i=1;i<=n;++i)
        pp[i]=(pp[i-1]*2)%md;
    for (int i=0;i<(1<<20);++i) {
        x=i;
        long long kol=0;
        while (x) {
            kol+=x%2;
            x/=2;
        }
        if (kol&1) ans=(ans-pp[dp[i]]+md)%md;
        else ans=(ans+pp[dp[i]])%md;
    }
    cout<<ans;
}