#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int cal(long long x){
    int ans=0;
    while(x%(1LL<<ans)==0) ans++;
    return ans-1;
}
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        long long a,b,d;
        scanf("%lld%lld%lld",&a,&b,&d);
        if(cal(a)<cal(d)||cal(b)<cal(d)){
            puts("-1");
            continue;
        }
        long long ans=d;
        int st=cal(d),cnt=0;
        while(1){
            if((ans|a)==ans&&(ans|b)==ans) break;
            int j;
            for(j=st;((1LL<<j)&ans);j++);
            ans+=(1LL<<(j-st))*d;
        }
        printf("%lld\n",ans);
    }
    return 0;
}