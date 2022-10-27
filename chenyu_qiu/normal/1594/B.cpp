#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn=1e6+5;
const int mod=1e9+7;
ll t,n,k,ans;
void quicksum(int power) {
    ll result=1,base=n;
    while(power) {
        if(power&1)result=result*base%mod;
        power>>=1;
        base=base*base%mod;
    }
    ans=(ans+result)%mod;
}
int main() {
    scanf("%lld",&t);
    while(t--) {
        scanf("%lld%lld",&n,&k);
        bitset<64> bit=k;//
        for(int i=0; i<=64; i++)
            if(bit[i])//1
                quicksum(i);
        printf("%lld\n",ans);
        ans=0;
    }
    return 0;
}