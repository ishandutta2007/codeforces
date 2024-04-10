#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    cout<<"YES"<<'\n';
    int x,y,xx,yy;
    for (int i=1;i<=n;++i) {
        cin>>x>>y>>xx>>yy;
        x=abs(x);
        y=abs(y);
        if ((x&1) && (y&1)) cout<<1<<'\n';
        else if ((x&1)) cout<<2<<'\n';
        else if ((y&1)) cout<<3<<'\n';
        else cout<<4<<'\n';
    }
}