#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

ld expow(ld a,int b) {
    ld ans=1;
    while(b) {
        if(b%2) {
            ans*=a;
        }
        a*=a;
        b/=2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ld n,m;
    cin>>m>>n;
    ld ans=0;
    for(ld i=1;i<=m;i++){
        ans+=i*(expow(i/m,n)-expow((i-1)/m,n));
    }
    cout<<fixed<<setprecision(100)<<ans<<"\n";
    return 0;
}