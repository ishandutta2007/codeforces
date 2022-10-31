#include <bits/stdc++.h>
using namespace std;


int n;
long long K,B;
long long pos[200005];
pair<long long,long long> v[200005];
pair<long long,long long> pp[200005];


inline pair<long long,long long> get_point(long long x) {
    long long y=K*x+B;
    return make_pair(x,y);
}

inline long long get_dist(pair<long long,long long> x) {
    long long res=0;
    res+=x.second;
    res-=K*x.first;
    res-=B;
    return res;
}

long long ans;
map<long long,int> cnt;

inline void solve(int l,int r) {
    cnt.clear();
    for (int i=l;i<=r;++i)
        ++cnt[pp[i].second];
    for (int i=l;i<=r;++i) {
        ans+=r-l+1-cnt[pp[i].second];
    }
}

main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>K>>B;
    for (int i=1;i<=n;++i) {
        cin>>pos[i]>>v[i].first>>v[i].second;
        pair<long long,long long> p=get_point(pos[i]);
        p.first+=v[i].first;
        p.second+=v[i].second;
        pp[i].second=v[i].first;
        pp[i].first=get_dist(p);
    }
    sort(pp+1,pp+n+1);
    int i=1;
    while (i<=n) {
        int j=i;
        while (j<=n && pp[j].first==pp[i].first) ++j;
        solve(i,j-1);
        i=j;
    }
    cout<<ans;
}