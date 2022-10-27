#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn=1e6+5;
ll t,n;
int main() {
    scanf("%lld",&t);
    while(t--) {
        scanf("%lld",&n);
        if(n&1)//
            printf("%lld %lld\n",(n-1)/2,(n-1)/2+1);
        else {//*
            ll t=2*n,p=0;
            while(t%2==0)t/=2;
            p=2*n/t;
            printf("%lld %lld\n",(t-p+1)/2,(t+p-1)/2);
        }
    }
    return 0;
}