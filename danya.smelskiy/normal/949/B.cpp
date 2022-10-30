#include <bits/stdc++.h>
using namespace std;


long long n,m;


inline long long get_pos(long long x) {
    if (x%2ll==1) {
        return (x+1ll)/2ll;
    }
    long long y,rght;
    while (true) {
        y=((x)/2ll);
        rght=n-y-1ll;
        if (n+n-x-1ll==rght+rght) return (x+1ll)/2ll;
        x+=rght+1ll;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>m;
    long long x;
    for (int i=1;i<=m;++i) {
        cin>>x;
        cout<<get_pos(x)<<'\n';
    }
}