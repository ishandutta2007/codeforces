#include <bits/stdc++.h>
using namespace std;
const int sz=1000;

int n;
pair<pair<int,int>,int> a[1000005];


inline bool cmp(pair<pair<int,int>,int> x,pair<pair<int,int>,int> y) {
    int bl1=(x.first.first+sz-1)/sz;
    int bl2=(y.first.first+sz-1)/sz;
    if (bl1!=bl2) return bl1<bl2;
    else return x.first.second<y.first.second;
}

main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i].first.first>>a[i].first.second;
        a[i].second=i;
    }
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;++i)
        cout<<a[i].second<<" ";
}