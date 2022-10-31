#include <bits/stdc++.h>
using namespace std;


int n,m,k;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    long long q=1+((n-1)*(n-2))/2;
    if (!(m<=q && m>=n-1)) {
        cout<<"-1";
        return 0;
    }
    if (k!=1) {
    cout<<1<<" "<<k<<'\n';
    --m;
    for (int i=2;i<=n;++i) {
        if (!m) break;
        for (int j=i+1;j<=n;++j) {
            --m;
            cout<<i<<" "<<j<<'\n';
            if (!m) break;
        }
    }
    } else {
    cout<<n<<" "<<k<<'\n';
    --m;
    for (int i=n-1;i>1;--i) {
        if (!m) break;
        for (int j=i-1;j>=1;--j) {
            --m;
            cout<<i<<" "<<j<<'\n';
            if (!m) break;
        }
    }
    }
}