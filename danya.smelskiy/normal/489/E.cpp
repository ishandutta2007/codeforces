#include <bits/stdc++.h>
using namespace std;
long double dp[1005];
long double a[1005],b[1005],m;
int n;
int pred[1005];
inline bool f(long double mid){
    dp[0]=0;
    for (int i=1;i<=n;++i)
        dp[i]=1e9;
    for (int i=1;i<=n;++i) {
        for (int j=0;j<i;++j){
            long double res=dp[j]+sqrt(abs(a[i]-a[j]-m))-mid*b[i];
            if (res<dp[i]) {
                dp[i]=res;
                pred[i]=j;
            }
        }

    }
    return dp[n]<0;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>a[i]>>b[i];
    long double l=0;
    long double r=1e15;
    while (l<r-0.00000001) {
            long double mid=(l+r)/2;
            if (f(mid)) r=mid;
            else l=mid;
    }
    if (f(l)) r=l;
    vector<int> ans;
    while (n) {
        ans.push_back(n);
        n=pred[n];
    }
    for (int i=ans.size()-1;i>=0;--i)
    cout<<ans[i]<<" ";
}