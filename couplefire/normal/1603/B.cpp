#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll x, y; cin >> x >> y;
    if(y<x) return void(cout << x+y << '\n');
    ll a = y/x, k = (y-a*x)/2;
    cout << a*x+k << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
}