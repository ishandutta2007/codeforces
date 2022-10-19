#include<bits/stdc++.h>
using namespace std;
int T;long long n;
void solve(){
    scanf("%lld",&n);
    if(n==2) puts("-1");
    else if(n&1) puts("2");
    else{
        long long n2=n,t2=2;
        while(n2%2==0) n2/=2,t2=t2*2;
        if(t2<=2e9&&n>=t2*(t2+1)/2) printf("%lld\n",t2);
        else{
            if(n2==1) puts("-1");
            else printf("%lld\n",n2);
        }
    }
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}
//(k+1)k/2+tk
//2n=k*(2t+k+1)