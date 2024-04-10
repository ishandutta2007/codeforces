#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ans = 1;
    int h, w;
    cin >> h >> w;
    for (int i=0; i < h+w; i++){
        ans = (ans*2)%mod;
    }
    cout << ans;
}