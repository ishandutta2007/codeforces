#include <bits/stdc++.h>
using namespace std;


int t;
long long a,b,c,x,z;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    while (t--) {
        cin>>a>>b>>c;
        if (!a) {
            cout<<"Finite"<<'\n';
            continue;
        }
        x=__gcd(a,b);
        a/=x;
        b/=x;
        while (b>1) {
            c=__gcd(b,c);
            if (c==1) break;
            b/=c;
        }
        if (b==1) cout<<"Finite"<<'\n';
        else cout<<"Infinite"<<'\n';
    }
}