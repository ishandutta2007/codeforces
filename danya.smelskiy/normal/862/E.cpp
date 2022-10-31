#include <bits/stdc++.h>
using namespace std;

long long n,m,q;
long long a[100005],dp[100005];
long long b[100005];
vector<long long> qq;
long long fl;
inline long long get_for_b(long long l,long long r){
    long long res=dp[r]-dp[l-1];
    if ((l&1)) res*=-1;
    return res;
}
inline void update(long long l,long long r,long long x){
    int ll=l;
    int rr=r;
    if (l&1) ++ll;
    if (r&1) --rr;
    if (ll<=rr) {
        ll-=2;
        fl+=(long long)(rr/2-ll/2)*(-x);
    }
    ll=l;
    rr=r;
    if ((l&1)==0) ++ll;
    if ((r&1)==0) --rr;
    if (ll<=rr) {
        ++ll; ++rr;
        ll-=2;
        fl+=(long long)(rr/2-ll/2)*x;
    }
}
inline long long p(long long pos){
    long long res=fl+qq[pos];
    if(res<0) res*=-1;
    return res;
}
inline long long solve(){
    long long res=4*1e18;
    res=p(0);
    res=min(res,p(qq.size()-1));
    int l=0;
    int r=qq.size()-1;
    while (l<r-1) {
        int mid=(l+r)>>1;
        if (fl+qq[mid]<0) l=mid;
        else r=mid;
    }
    for (int i=max(0,l);i<min((int)qq.size(),l+5);++i)
        res=min(res,p(i));
    return res;
}
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>q;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        if (i&1) fl+=a[i];
        else fl-=a[i];
    }
    for (int i=1;i<=m;++i) {
        cin>>b[i];
        dp[i]=dp[i-1];
        if (i&1) dp[i]+=b[i];
        else dp[i]-=b[i];
    }
    for (int i=1;i<=m-n+1;++i) {
        qq.push_back(get_for_b(i,i+n-1));
    }
    sort(qq.begin(),qq.end());
    cout<<solve()<<'\n';
    for (int i=1;i<=q;++i) {
        int l,r,x;
        cin>>l>>r>>x;
        update(l,r,x);
        cout<<solve()<<'\n';
    }
}