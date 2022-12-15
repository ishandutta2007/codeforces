#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        long long n,k,b,s;
        scanf("%lld%lld%lld%lld",&n,&k,&b,&s);
        if((k-1)*n+k*b<s||b*k>s) puts("-1");
        else{
            long long r=s-b*k;
            for(int i=1;i<=n;i++){
                long long base=i==1?k*b:0,add=min(k-1,r);
                r-=add;
                printf("%lld ",base+add);
            }
            puts("");
        }
    }
    return 0;
}