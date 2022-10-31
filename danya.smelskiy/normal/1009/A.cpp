#include <bits/stdc++.h>
using namespace std;






int n,m,ans;
int a[1005];
int b[1005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=m;++i)
        cin>>b[i];
    int last=1;
    for (int i=1;i<=n;++i) {
        if (last<=m) {
            if (b[last]>=a[i]) {
                ++last;
                ++ans;
            }
        }
    }
    cout<<ans;
}