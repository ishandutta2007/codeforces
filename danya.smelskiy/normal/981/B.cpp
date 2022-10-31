#include <bits/stdc++.h>
using namespace std;


int n;
long long ans;
int m;
pair<int,int> a[200005];

map<int,bool> used;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i].second>>a[i].first;
        a[i].first*=-1;
    }
    cin>>m;
    for (int i=1;i<=m;++i) {
        ++n;
        cin>>a[n].second>>a[n].first;
        a[n].first*=-1;
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i) {
        if (!used.count(a[i].second)) {
            used[a[i].second]=true;
            ans-=a[i].first;
        }
    }
    cout<<ans;
}