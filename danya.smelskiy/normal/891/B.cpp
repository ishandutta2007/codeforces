#include <bits/stdc++.h>
using namespace std;

int n;
pair<int,int> a[1005];
int ans[1005];

int main() {
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i) {
        if (i>1) ans[a[i].second]=a[i-1].first;
        else ans[a[i].second]=a[n].first;
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
}