#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll n,k;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    vector<ll>v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    ll x=0;
    while(x*(x+1)/2<k) {
        x++;
    }
    k-=x*(x-1)/2;k--;
    cout<<v[k]<<"\n";
    return 0;
}
/**

**/