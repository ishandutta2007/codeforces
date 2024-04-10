#include <bits/stdc++.h>
using namespace std;

long long n,m,ans;
long long a[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i) {
        if (a[i]<=m) continue;
        if (m>=(a[i]+1)/2) {
            m=a[i];
            continue;
        }
        while (m<(a[i]+1)/2) {
            m*=2;
            ++ans;
        }
        m=max(m,a[i]);
    }
    cout<<ans;
}