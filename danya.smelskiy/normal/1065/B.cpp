#include <bits/stdc++.h>
using namespace std;



long long n,m;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    cout<<max(0ll,n-m*2ll)<<" ";
    for (int i=0;i<=n;++i) {
        long long x=i;
        x*=i-1ll;
        x/=2ll;
        if (x>=m) {
            cout<<n-i;
            return 0;
        }
    }
}