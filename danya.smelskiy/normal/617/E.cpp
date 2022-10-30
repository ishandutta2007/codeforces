#include <bits/stdc++.h>
using namespace std;
const int sz=500;

int n,m,k;
long long cur;
vector<pair<pair<int,int>,int> > v;
int l,r;
long long ans[100005];
int a[100005];
int cnt[3000005];

inline bool cmp(pair<pair<int,int>,int> x,pair<pair<int,int>,int> y) {
    int bl1=x.first.first;
    int bl2=y.first.first;
    bl1=(bl1+sz-1)/sz;
    bl2=(bl2+sz-1)/sz;
    if (bl1!=bl2) return bl1<bl2;
    else return x.first.second<y.first.second;
}


inline void mv(int ll,int rr) {
    while (l>ll) {
        --l;
        cur+=cnt[a[l]^k];
        ++cnt[a[l]];
    }
    while (r<rr) {
        ++r;
        cur+=cnt[a[r]^k];
        ++cnt[a[r]];
    }
    while (l<ll) {
        --cnt[a[l]];
        cur-=cnt[a[l]^k];
        ++l;
    }
    while (r>rr) {
        --cnt[a[r]];
        cur-=cnt[a[r]^k];
        --r;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        a[i]^=a[i-1];
    }
    for (int i=1;i<=m;++i) {
        int x,y;
        cin>>x>>y;
        --x;
        v.push_back({{x,y},i});
    }
    sort(v.begin(),v.end(),cmp);
    l=0;
    r=0;
    ++cnt[a[0]];
    for (int i=0;i<v.size();++i) {
        int x=v[i].first.first;
        int y=v[i].first.second;
        mv(x,y);
        ans[v[i].second]=cur;
    }
    for (int i=1;i<=m;++i)
        cout<<ans[i]<<'\n';
}