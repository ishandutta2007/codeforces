#include <bits/stdc++.h>
using namespace std;





long long n,m,xx,res;
long long x,y;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    while (m--) {
        cin>>x>>y;
        if ((x+y)%2ll==0) {
            xx=(x-1)*n+y;
            res=(xx+1ll)/2ll;
            cout<<res<<'\n';
        } else {
            xx=(x-1)*n+y;
            res=(xx+1ll)/2ll;
            res+=(n*n+1ll)/2ll;
            cout<<res<<'\n';
        }
    }
}