#include <bits/stdc++.h>
using namespace std;

int n;
int aa,bb;
pair<long long,long long> a[200005];
long long ans,ans2;
int p[200005];
long long val[200005];

inline bool cmp(int x,int y) {
    return val[x]>val[y];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>aa>>bb;
    bb=min(bb,n);
    for (int i=1;i<=n;++i) {
        cin>>a[i].first>>a[i].second;
        if (a[i].second>a[i].first) val[i]=0;
        else val[i]=a[i].first-a[i].second;
        p[i]=i;
    }
    sort(p+1,p+n+1,cmp);
    for (int i=1;i<=n;++i)
        val[i]=max(a[i].first,a[i].second);
    for (int i=1;i<=n;++i) {
        if (i<bb) ans+=val[p[i]];
        else ans+=a[p[i]].second;
    }
    if (!bb) {
        cout<<ans;
        return 0;
    }
    ans2=ans;
    long long zz=1;
    for (int i=1;i<=aa;++i)
        zz*=2ll;
    long long cur,z;
    for (int i=1;i<=n;++i) {
        cur=ans;
        if (i<bb) {
            cur-=val[p[i]];
            cur-=a[p[bb]].second;
            cur+=val[p[bb]];
        } else cur-=a[p[i]].second;
        z=a[p[i]].first*zz;
        z=max(z,a[p[i]].second);
        cur+=z;
        if (cur>ans2) ans2=cur;
    }
    cout<<ans2;
}