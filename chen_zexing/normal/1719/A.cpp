#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        puts((n+m)%2?"Burenka":"Tonya");
    }
    return 0;
}