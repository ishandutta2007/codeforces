#include<bits/stdc++.h>
using namespace std;
#define LLLL long long
long long gcd(long long x,long long y){
    if (y==0)return x;
    return gcd(y,x%y);
}
LLLL quick(LLLL x,LLLL y,LLLL mod){
    if (y==0)return 1;
    if (y&1){
        return 1LL*x*quick(x*x%mod,y/2,mod)%mod;
    }else{
        return quick(x*x%mod,y/2,mod);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    while (n--){
        long long p,q,b;
        scanf("%lld%lld%lld",&p,&q,&b);
     //   cout<<p<<" "<<q<<" "<<b<<endl;
        if (q==1||p==0||p%q==0){
            puts("Finite");
            continue;
        }
        LLLL g = gcd(p,q);
        q/=g;
        bool succ = true;
        while (q!=1){
            LLLL g = gcd(q,b);
            if (g==1){
                succ = false;
                break;
            }
            while (q%g==0)q/=g;
        }
        if (succ)printf("Finite\n");
        else printf("Infinite\n");
    }


    return 0;
}