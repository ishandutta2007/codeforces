#include <bits/stdc++.h>
using namespace std;


int n;
pair<pair<int,int>,int> a[300005];


inline bool cmp(pair<pair<int,int>,int> x,pair<pair<int,int>,int> y) {
    if (x.first.second!=y.first.second) return x.first.second<y.first.second;
    return x.first.first>y.first.first;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i].first.first>>a[i].first.second;
        a[i].second=i;
    }
    sort(a+1,a+n+1,cmp);
    int lastx=-1e9;
    int lastpoc=0;
    for (int i=1;i<=n;++i) {
        if (lastx>=a[i].first.first && lastpoc) {
            cout<<lastpoc<<" "<<a[i].second;
            return 0;
        }
        if (a[i].first.first>=lastx) {
            lastx=a[i].first.first;
            lastpoc=a[i].second;
        }
    }
    cout<<"-1 -1";
}