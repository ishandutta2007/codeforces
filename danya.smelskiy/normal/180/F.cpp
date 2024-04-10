#include <bits/stdc++.h>
using namespace std;



int n;
int a[100005];
int b[100005];
int ans[100005];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    for (int i=1;i<=n;++i) {
        cin>>b[i];
        ans[a[i]]=b[i];
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
}