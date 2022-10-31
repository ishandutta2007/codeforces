#include <bits/stdc++.h>
using namespace std;



long long n;
long long a[100005];
long long b[100005];
long long dp[100005];
pair<long long,long long> q[100005];
long long l,r;
inline double get(pair<long long,long long> a,pair<long long,long long> b){
    long double x=a.first-b.first;
    long double y=b.second-a.second;
    return (x!=0 ? y/x : (a.second>b.second ? 1e18 : -1e18));
}
inline void add(pair<long long,long long> a,long long b){
    while (r>l+1 && get(q[r-1],q[r-2])>=get(a,q[r-1])) --r;
    q[r++]=a;
    while (l+1<r && get(q[l],q[l+1])<b) ++l;
}
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (long long i=1;i<=n;++i)
        cin>>a[i];
    for (long long i=1;i<=n;++i)
        cin>>b[i];
    for (long long i=2;i<=n;++i) {
        add(make_pair(b[i-1],dp[i-1]),a[i]);
        dp[i]=q[l].first*a[i]+q[l].second;
    }
    cout<<dp[n];
}