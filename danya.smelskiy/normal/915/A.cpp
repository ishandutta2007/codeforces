#include <bits/stdc++.h>
using namespace std;

int n,m,ans=1e9;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        int x;
        cin>>x;
        if (m%x==0) ans=min(ans,m/x);
    }
    cout<<ans;
}