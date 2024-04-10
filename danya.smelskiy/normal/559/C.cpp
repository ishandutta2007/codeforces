#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

pair<int,int> a[2005];
int h,w,n;
long long dp[2005];
long long f[200005];

inline long long p(long long x,long long y){
    long long res=1;
    while (y) {
        if (y&1) res=(res*x)%md;
        x=(x*x)%md;
        y>>=1;
    }
    return res;
}
inline long long cnk(long long x,long long y){
    if (y>x) return 0;
    long long res=f[x];
    long long q=p(f[y],md-2);
    res=(res*q)%md;
    q=p(f[x-y],md-2);
    res=(res*q)%md;
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>h>>w>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i].first>>a[i].second;
    }
    a[++n]=make_pair(1,1);
    a[++n]=make_pair(h,w);
    sort(a+1,a+n+1);
    dp[1]=1;
    f[0]=1;
    for (int i=1;i<=2*1e5;++i)
        f[i]=(f[i-1]*i)%md;
    for (int i=2;i<=n;++i){
        dp[i]=cnk(a[i].first+a[i].second-2,a[i].first-1);
        for (int j=2;j<i;++j) if (a[j].first<=a[i].first && a[j].second<=a[i].second) {
            long long z=cnk(a[i].first-a[j].first+a[i].second-a[j].second,a[i].first-a[j].first);
            dp[i]=(dp[i]-(dp[j]*z)%md+md)%md;
        }
    }
    cout<<dp[n];
}