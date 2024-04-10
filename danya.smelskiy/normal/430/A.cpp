#include <bits/stdc++.h>
using namespace std;

int n,m;
pair<int,int> a[105];
int ans[105];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i)
        if (i&1) ans[a[i].second]=1;
        else ans[a[i].second]=0;
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
}