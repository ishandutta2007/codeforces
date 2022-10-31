#include <bits/stdc++.h>
using namespace std;




int n,m;
int x,y;
int l,r=1e9;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if (!m) {
        cout<<n-1;
        return 0;
    }
    while (m--) {
        cin>>x>>y;
        if (x>y) swap(x,y);
        l=max(l,x);
        r=min(r,y);
    }
    if (l<=r) cout<<r-l;
    else cout<<0;
}