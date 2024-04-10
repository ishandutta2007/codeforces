#include <bits/stdc++.h>
using namespace std;

int n,k;
long double dp[(1<<20)+5];
long double p[25];
long double ans[25];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(); cout.tie(0);
    int q=0;
    cin>>n>>k;
    for (int i=1;i<=n;++i) {
        cin>>p[i];
        if (p[i]<=0.00001) ++q;
    }
    q=n-q;
    if (q>k) q=k;
    dp[0]=1;
    for (int i=1;i<(1<<n);++i) {
        int c=0;
        for (int j=0;j<n;++j)
            if (i&(1<<j)) ++c;
        if (c>q) continue;
        long double s=0,t=0;
        for (int j=0;j<n;++j) if (i&(1<<j)){
            s+=p[j+1];
            t+=dp[i^(1<<j)]*p[j+1];
        }
        if (1.-s>0.000001);
        dp[i]=t/(1.-s);
        if (c==q) {
            for (int j=0;j<n;++j)
                if (i&(1<<j)) ans[j]+=t;
        }
    }
    for (int i=0;i<n;++i)
        cout<<fixed<<setprecision(6)<<ans[i]<<" ";
}