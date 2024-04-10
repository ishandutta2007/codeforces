#include <bits/stdc++.h>
using namespace std;


long long l,r,dp[100];


inline long long solve(long long x){
    if (x<=1) return 0;
    long long y=x;
    int sz=0;
    while (y) {
        ++sz;
        y>>=1;
    }
    long long res=solve((1ll<<(sz-1ll))-1ll);
    for (int i=0;i<=32;++i)
        dp[i]=0;
    for (int i=1;i<sz;++i) if (sz%i==0) {
        long long msk1=(x>>(sz-i));
        long long msk2=0;
        for (int j=1;j<=sz/i;++j){
            msk2<<=i;
            msk2|=msk1;
        }
        if (msk2<=x) ++dp[i];
        dp[i]+=msk1-(1ll<<(i-1ll));
        for (int j=1;j<i;++j)
            if (i%j==0) dp[i]-=dp[j];
        res+=dp[i];
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>l>>r;
    --l;
    cout<<solve(r)-solve(l);
}