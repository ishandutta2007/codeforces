#include <bits/stdc++.h>
using namespace std;




int n;
int a[205];
int ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n+n;++i) {
        cin>>a[i];
    }
    for (int i=1;i<=n+n;i+=2) {
        if (a[i]==a[i+1]) continue;
        for (int j=n+n-1;j>i;--j)
        if (a[j+1]==a[i]) {
            ++ans;
            swap(a[j+1],a[j]);
        }
    }
    cout<<ans;
}